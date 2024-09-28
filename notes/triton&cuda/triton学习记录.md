## 笔记

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

#### 什么是grid

+ 一个tensor
+ 用来指定block(program)的分块维度，每个维度分成多少块



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

![image-20240909210350419](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909210350419.png)



### Autotune

#### 用lambda函数创建grid

```python
grid = lambda meta: (triton.cdiv(m, meta['bm']),  triton.cdiv(n, meta['bn']))
```

+ meta是一个字典，用于规定bm和bn的大小
+ lambda函数的参数为meta字典，返回值为grid元组

#### @triton.autotune装饰器

![image-20240924161652367](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240924161652367.png)

+ configs列表定义了多个配置组合，meta字典会自动从这些配置中生成

+ key参数表明，每当m、n、k变化时，triton就会重新进行autotune，来确定当前数据规模的最佳配置

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





## Kernel

### Vector Add

#### 图解

![image-20240909205254884](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909205254884.png)

#### 代码

![image-20240909205944554](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909205944554.png)

### Matrix Add

#### 图解

![image-20240909205314939](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909205314939.png)

#### 代码

![image-20240909210039363](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240909210039363.png)

### Matmul

#### 图解

![image-20240923234331822](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240923234331822.png)


#### 代码

![image-20240923234608376](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240923234608376.png)

![image-20240923234640128](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240923234640128.png)







