## 笔记

[A practitioner's guide to Triton](https://github.com/Ganzeus/Ganzeus/blob/master/notes/triton%26cuda/A guide to Triton.ipynb)

### 并行编程思想

并行编程只需要考虑两部分：

1. 如何划分块
2. 每一块进行的操作都是一模一样的，只需要编写每一块执行的操作即可。
   块内操作可以看成是顺序编程，唯一区别就是块内去要利用mask进行边界处理。



### triton vs cuda

#### 特性

+ triton不需要考虑shared memory，而cuda需要手动实现

#### program == block

> Note on jargon: In triton lingo, each kernel (which processes a block) is called a "program". Therefore, "block_id" is often called "pid" (short for "program id"), but it's the same.

+ triton中的program就是cuda中的block
+ cuda把计算分成block和thread，而triton只分为block。
  triton在block中可以直接进行vector运算，因此比cuda好写得多

#### triton kernel中的操作

> **All** operations in triton kernels are vectorized: Loading data, operating on data, storing data, and creating masks.

+ triton kernel中一共只有四种操作：存/取数据、计算、越界检测

#### grid & block

+ grid就是一个tensor
+ 用来指定block(program)的分块维度，**每个维度分成多少块**

**grid和block本质**

+ **每个block包含哪些元素都是在kernel中人为规定(load)的**，并不是理所当然的某些元素在block1中、某些元素在block2中...
+ 指定grid后，程序是不知道有block这个东西的，只会按你给的grid形状分配若干program_id，每个kernel运行时都会通过`tl.program_id()`得到自己的program_id。因此**程序也不知道每个block应该包含多少元素**。
+ program_id只是一个用于区分block的数字罢了，不存在空间信息，所以不可能知道自己会运算哪些元素，
  **更不知道自己会读取多少元素**，一切都是用load函数人为规定的





### 写kernel步骤

#### helper function

1. 初始化输出（返回值）
2. 计算各种shape和size：num_blocks、矩阵mnk
3. 定义grid
4. 调用kernel（传入各种参数）
5. return



#### kernel function

1. pid
2. offset
3. mask
4. 根据offset和mask来load数据
5. 计算
6. tl.store



### Utility Function

> 用于调试

```python
import os
import triton
import triton.language as tl

def test_pid_conds(conds, pid_0=[0], pid_1=[0], pid_2=[0]):
    '''Test if condition on pids are fulfilled
    E.g.:
        '=0'  checks that pid_0 == 0
        ',>1' checks that pid_1 > 1
        '>1,=0' checks that pid_0 > 1 and pid_1 == 0
    '''
    pids = pid_0[0], pid_1[0], pid_2[0]
    conds = conds.replace(' ','').split(',')
    for i, (cond, pid) in enumerate(zip(conds, pids)):
        if cond=='': continue
        op, threshold = cond[0], int(cond[1:])
        if op not in ['<','>','>=','<=','=', '!=']: 
            raise ValueError(f"Rules may only use these ops: '<','>','>=','<=','=', '!='. \
                             Invalid rule: '{cond}'.")
        op = '==' if op == '=' else op
        if not eval(f'{pid} {op} {threshold}'): return False
    return True

assert test_pid_conds('')
assert test_pid_conds('>0', [1], [1])
assert not test_pid_conds('>0', [0], [1])
assert test_pid_conds('=0,=1', [0], [1], [0])

def breakpoint_if(conds, pid_0=[0], pid_1=[0], pid_2=[0]):
    '''Stop kernel, if any condition of pids is fulfilled'''
    from IPython.core.debugger import set_trace
    
    if test_pid_conds(conds, pid_0, pid_1, pid_2): set_trace()

def print_if(txt, conds, pid_0=[0], pid_1=[0], pid_2=[0]):
    '''Print txt, if any condition of pids is fulfilled'''
    if test_pid_conds(conds, pid_0, pid_1, pid_2): print(txt)

def check_tensors_gpu_ready(*tensors):
    for t in tensors:
        assert t.is_contiguous(), "A tensor is not contiguous"
        if not os.environ.get('TRITON_INTERPRET') == '1': assert t.is_cuda, "A tensor is not on cuda"

```



### Autotune

#### 用lambda函数创建grid

```python
grid = lambda meta: (triton.cdiv(m, meta['bm']),  triton.cdiv(n, meta['bn']))
```

+ meta是一个字典，用于规定bm和bn的大小
+ lambda函数的参数为meta字典，返回值为grid元组
+ meta字典中的keys需要在内核函数中指明为`tl.constexpr`类型

  ```python
  def matmul_kernel(
      a_ptr, b_ptr, c_ptr,
      m, n, k,
      stride_am, stride_ak, 
      stride_bk, stride_bn,
      stride_cm, stride_cn,
      bm: tl.constexpr, bn: tl.constexpr, bk: tl.constexpr, group_sz: tl.constexpr
  ):
  ```

#### @triton.autotune装饰器

```python
@triton.autotune(
    # Choices of configs to auto-tune over
    configs=[
        triton.Config({'bm': 128, 'bn': 256, 'bk': 64, 'group_sz': 8}, num_stages=3, num_warps=8),
        triton.Config({'bm': 64, 'bn': 256, 'bk': 32, 'group_sz': 8}, num_stages=4, num_warps=4),
        triton.Config({'bm': 128, 'bn': 128, 'bk': 32, 'group_sz': 8}, num_stages=4, num_warps=4),
        triton.Config({'bm': 128, 'bn': 64, 'bk': 32, 'group_sz': 8}, num_stages=4, num_warps=4),
        triton.Config({'bm': 64, 'bn': 128, 'bk': 32, 'group_sz': 8}, num_stages=4, num_warps=4),
        triton.Config({'bm': 128, 'bn': 32, 'bk': 32, 'group_sz': 8}, num_stages=4, num_warps=4),
        triton.Config({'bm': 64, 'bn': 32, 'bk': 32, 'group_sz': 8}, num_stages=5, num_warps=2),
        triton.Config({'bm': 32, 'bn': 64, 'bk': 32, 'group_sz': 8}, num_stages=5, num_warps=2),
    ],
    # Definition of problem size. If it changes, a new auto-tune is run for the new problem size.
    key=['m', 'n', 'k'],
)
```

+ configs列表定义了多个配置组合，meta字典会自动从这些配置中生成
+ key参数(`['m', 'n', 'k']`)表明，每当m、n、k变化时，triton就会重新进行autotune，来确定当前数据规模的最佳配置



## Kernel

### Vector Add

#### 图解

![image-20240909205254884](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909205254884.png)

#### 代码

```python
# helper function
def add(a, b, block_size):      # a, b都是torch.tensor, 长度相等，返回a+b
    # 1. init output
    c = torch.zeros_like(a)
    check_tensors_gpu_ready(a, b, c)

    # 2. shape & size
    n = a.numel()
    num_blocks = triton.cdiv(n, block_size)

    # 3. grid def
    grid = (num_blocks, )

    # 4. call kernel
    add_kernel[grid](a, b, c, n, block_size)

    # 5. return
    return c

@triton.jit
def add_kernel(a_ptr, b_ptr, c_ptr, n, BLOCK_SIZE: tl.constexpr):
    # 1. pid
    pid = tl.program_id(0)
    # 2. offset
    offset = pid * BLOCK_SIZE + tl.arange(0, BLOCK_SIZE)
    # 3. mask
    mask = offset < n   # 越界检测
    # 4. load
    a = tl.load(a_ptr + offset, mask)
    b = tl.load(b_ptr + offset, mask)
    # 5. compute
    c = a + b
    # 6. store
    tl.store(c_ptr + offset, c, mask)
```



### Matrix Add

#### 图解

![image-20240909205314939](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909205314939.png)

#### 代码

```python
# helper function
def matrix_add(a, b, block_size):   # block_size为长2的元组
    # 1. init output
    c = torch.zeros_like(a)
    # 2. shape & size
    m, n = a.shape
    bs0, bs1 = block_size
    # 3. grid def
    grid = (triton.cdiv(m, bs0), triton.cdiv(n, bs1))
    # 4. call kernel
    matrix_add_kernel[grid](a, b, c, m, n, bs0, bs1)
    # 5. return
    return c


@triton.jit
def matrix_add_kernel(a_ptr, b_ptr, c_ptr, m, n, bs0: tl.constexpr, bs1: tl.constexpr):
    # 1. pid
    pid_x = tl.program_id(0)
    pid_y = tl.program_id(1)

    # 2. offset
    off_x = pid_x * bs0 + tl.arange(0, bs0)
    off_y = pid_y * bs1 + tl.arange(0, bs1)

    offset = off_x[:, None] * n + off_y[None, :]    # 二维offset公式

    # 3. mask
    mask_x = off_x < m      # 行 mask
    mask_y = off_y < n      # 列 mask
    
    mask = mask_x[:, None] & mask_y[None, :]    # 二维mask，注意是'&'不是'+'

    # 4. load
    a = tl.load(a_ptr + offset, mask)
    b = tl.load(b_ptr + offset, mask)

    # 5. compute
    c = a + b

    # 6. store
    tl.store(c_ptr + offset, c, mask)
```



### Matmul

#### 图解

![image-20240923234331822](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240923234331822.png)


#### 代码

```python
# helper function
def matmul_triton(A, B, bs=16):
    assert A.shape[1] == B.shape[0], "matrix dims not compatible for matmul"
    check_tensors_gpu_ready(A, B)
    # 1. shape & size
    (m, k), (_, n) = A.shape, B.shape       # m,n,k赋值

    # 2. init output
    C = torch.empty((m, n), device=device, dtype=torch.float16)

    # 3. grid def
    grid = lambda meta: (triton.cdiv(m, meta['bm']),  triton.cdiv(n, meta['bn']))
    
    # 4. call kernel
    matmul_kernel[grid](
        A, B, C,
        m, n, k,
        A.stride(0), A.stride(1),       # stride是PyTorch内置函数，返回指定维度上移动一个元素所跨过的元素数量
        B.stride(0), B.stride(1),       # 在行维度上，元素是连续的，因此移动一个元素只需要跨越一个元素，及stride(0)=1
        C.stride(0), C.stride(1),       # 在列维度上，移动一个元素需要跨越一整行元素，即stride(1) = 每行元素个数
        bm=bs, bn=bs, bk=bs,
    )
    
    # return
    return C

@triton.jit
def matmul_kernel(
    a_ptr, b_ptr, c_ptr,
    m, n, k,
    stride_am, stride_ak, 
    stride_bk, stride_bn,
    stride_cm, stride_cn,
    bm: tl.constexpr, bn: tl.constexpr, bk: tl.constexpr
):
    # 1. pid
    pid_m, pid_n = tl.program_id(0), tl.program_id(1)
    
    # 2. offset & mask
    off_m = pid_m * bm + tl.arange(0, bm)
    off_n = pid_n * bn + tl.arange(0, bn)

    # initialize accumulator (累加器，存放矩阵乘积)
    acc = tl.zeros((bm, bn), dtype=tl.float32)
    for i in range(0, k, bk):       # 每层循环计算一个phase
        off_k = i + tl.arange(0, bk)
    
        # offs_A, offs_B都是下标矩阵， 表示当前线程内相乘的两个矩阵在原矩阵对应的下标
        off_A = off_k[None, :] * stride_ak + off_m[:, None] * stride_am
        mask_A = (off_k[None, :] < k) & (off_m[:, None] < m)

        off_B = off_n[None, :] * stride_bn + off_k[:, None] * stride_bk
        mask_B = (off_n[None, :] < n) & (off_k[:, None] < k)
        
        # 3. load & 计算
        A = tl.load(a_ptr + off_A, mask_A, other=0.0)
        B = tl.load(b_ptr + off_B, mask_B, other=0.0)
        acc += tl.dot(A, B, allow_tf32=False)
        
    # 此时的acc就是一个小矩阵（最终结果的一部分），因此可以直接fuse激活函数
    # acc = relu(acc)
    
    # 4. store
    off_C = off_n[None, :] * stride_cn + off_m[:, None] * stride_cm
    mask_C = (off_n[None, :] < m) & (off_m[:, None] < n)
    tl.store(c_ptr + off_C, acc, mask=mask_C)

```



#### 优化：Grouped ordering

![image-20241105192034176](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20241105192034176.png)

+ **图中的每个格子都是一个block，而不是矩阵中的一个元素**
+ 默认的block读取顺序为第一行，即行优先依次读取
+ 将block读取顺序修改为第二行的样子，就可以增加L2 cache的命中率

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20241105191834445.png" alt="image-20241105191834445" style="zoom:80%;" />

+ 核心：修改block下标，从而改变读取block的顺序（==**不是修改矩阵元素的下标！！！**==）

+ 例如：调用内核时以为要读取下标(0,1)的block，结果读取了(1,0)的block

##### 二维grid：swizzle2d

```python
@jit
def swizzle2d(i, j, size_i, size_j, size_g):
    """
    修改矩阵下标的顺序，变为以边长size_g的小正方形为单位,小正方形内部采用列优先的顺序
    并行函数，即不同下标的block同时调用
    (i,j)为当前block所在原grid矩阵下标, 返回在新矩阵中的下标(new_i, new_j)
    size_i,size_j为grid矩阵行列长度(即行列各有多少block)，size_g表示几行作为一个group
    eg. size_i = size_j = 4 and size_g = 2, 转换前后矩阵如下（每个序号表示一个block而不是矩阵元素）
    [[0 , 1 , 2 , 3 ],
     [4 , 5 , 6 , 7 ],
     [8 , 9 , 10, 11],
     [12, 13, 14, 15]]
    ->	# 两行为一个group, 每个group有8个block，包含一行2个小正方形
    [[0, 2,  4 , 6 ],
     [1, 3,  5 , 7 ],
     [8, 10, 12, 14],
     [9, 11, 13, 15]]
    """
    ij = i * size_j + j				# 当前block在原矩阵中对应的序号
    
    size_gj = size_g * size_j		# 即一个group中包含多少block
    
    group_id = ij // size_gj		# 当前block在第几个group
    # row-index of the first element of this group
    off_i = group_id * size_g		# 当前group的第一个block所在行号
    # last group may have fewer rows
    size_g = core.minimum(size_i - off_i, size_g)	# 还剩多少有效行
    # new row and column indices
    new_i = off_i + (ij % size_g)		# 新行号=当前block应是小正方形的第几行+小正方形的起始行(off_i)
    new_j = (ij % size_gj) // size_g	# 新列号=当前group的第几个元素 // 剩余行数
    return new_i, new_j
```



##### 一维grid

> triton document官方方法

```python
pid = tl.program_id(axis=0)			# block序号（通过pid直接获得，不需要通过下标计算）

num_pid_m = tl.cdiv(M, BLOCK_SIZE_M)	# grid矩阵行数
num_pid_n = tl.cdiv(N, BLOCK_SIZE_N)	# grid矩阵列数

num_pid_in_group = GROUP_SIZE_M * num_pid_n		# 一个group中包含多少block

group_id = pid // num_pid_in_group				# 当前block在第几个group

first_pid_m = group_id * GROUP_SIZE_M			# 当前group的第一个block所在行号

group_size_m = min(num_pid_m - first_pid_m, GROUP_SIZE_M)	# 还剩多少有效行

pid_idx_in_group = pid % num_pid_in_group		# 当前block是所在group的第几个元素
# 计算当前block所在新矩阵下标(pid_m, pid_n)
pid_m = first_pid_m + (pid_idx_in_group % group_size_m)	
						# 新行号=当前block应是小正方形的第几行+小正方形的起始行(first_pid_m)
pid_n = pid_idx_in_group // group_size_m	# 新列号=当前group的第几个元素 // 剩余行数
```



##### 优化后代码

```python
@triton.jit
def grouped_matmul_kernel(
    a_ptr, b_ptr, c_ptr,
    m, n, k,
    stride_am, stride_ak, 
    stride_bk, stride_bn,
    stride_cm, stride_cn,
    bm: tl.constexpr, bn: tl.constexpr, bk: tl.constexpr
):
    # 1. pid
    pid_m, pid_n = tl.program_id(0), tl.program_id(1)
    
    # 仅须修改下面两行
    num_pid_m, num_pid_n = tl.num_programs(0), tl.num_programs(1)   # 获取行列各分成多少block
    pid_m, pid_n = tl.swizzle2d(pid_m, pid_n, num_pid_m, num_pid_n, group_sz)
    """
    假设triton给当前block分配的program_id为(0, 2), 但此函数人为改为(2, 0).
    这样就可以用原来的算法来计算offset,从而读取另一块内存, 不需要修改下面的代码
    """
    
    
    # 2. offset & mask
    off_m = pid_m * bm + tl.arange(0, bm)
    off_n = pid_n * bn + tl.arange(0, bn)

    # initialize accumulator (累加器，存放矩阵乘积)
    acc = tl.zeros((bm, bn), dtype=tl.float32)
    for i in range(0, k, bk):       # 每层循环计算一个phase
        off_k = i + tl.arange(0, bk)
    
        # offs_A, offs_B都是下标矩阵， 表示当前线程内相乘的两个矩阵在原矩阵对应的下标
        off_A = off_k[None, :] * stride_ak + off_m[:, None] * stride_am
        mask_A = (off_k[None, :] < k) & (off_m[:, None] < m)

        off_B = off_n[None, :] * stride_bn + off_k[:, None] * stride_bk
        mask_B = (off_n[None, :] < n) & (off_k[:, None] < k)
        
        # 3. load & 计算
        A = tl.load(a_ptr + off_A, mask_A, other=0.0)
        B = tl.load(b_ptr + off_B, mask_B, other=0.0)
        acc += tl.dot(A, B, allow_tf32=False)
        
    # 此时的acc就是一个小矩阵（最终结果的一部分），因此可以直接fuse激活函数
    # acc = relu(acc)
    
    # 4. store
    off_C = off_n[None, :] * stride_cn + off_m[:, None] * stride_cm
    mask_C = (off_n[None, :] < m) & (off_m[:, None] < n)
    tl.store(c_ptr + off_C, acc, mask=mask_C)
```



### Transpose2D

#### 图解

![image-20241022192339960](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20241022192339960.png)

#### 代码

```python
def transpose2d_triton(x):
    check_tensors_gpu_ready(x)
    M, N = x.shape
    y = torch.empty((N, M), device=device, dtype=torch.float16)

    grid = lambda META: (triton.cdiv(M, META['bm']), triton.cdiv(N, META['bn']))
    
    transpose_kernel[grid](x, y, M, N, x.stride(0), x.stride(1), y.stride(0), y.stride(1))

    return y

@triton.jit
def transpose_kernel(
    x_ptr,
    y_ptr,
    M,
    N,
    stride_xm,
    stride_xn,
    stride_yn,
    stride_ym,
    bm: tl.constexpr = 16, bn: tl.constexpr = 16
):
    pid_m, pid_n = tl.program_id(0), tl.program_id(1)

    off_m = pid_m * bm + tl.arange(0, bm)
    off_n = pid_n * bn + tl.arange(0, bn)

    off_X = off_n[None, :] * stride_xn + off_m[:, None] * stride_xm
    off_Y = off_n[:, None] * stride_yn + off_m[None, :] * stride_ym

    mask_X = (off_m[:, None] < M) & (off_n[None, :] < N)
    mask_Y = (off_m[None, :] < M) & (off_n[:, None] < N)

    x = tl.load(x_ptr + off_X, mask=mask_X)
    x_t = tl.trans(x)
    tl.store(y_ptr + off_Y, x_t, mask=mask_Y)
```





### Conv2d

