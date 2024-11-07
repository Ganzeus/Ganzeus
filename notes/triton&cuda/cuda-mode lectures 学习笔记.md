## Lecture1 Profiling and Integrating CUDA kernels in PyTorch

### 三种Profile方法

> 为什么不能用time模块测量执行时间？
> 答：在 CUDA 中，GPU 的计算和CPU的计算可以同时进行，因此它们是异步的。而使用 time 模块来测量 CUDA 函数的执行时间并不准确，因为它无法考虑到 GPU 计算的异步性。

#### cuda.Event测量执行时间

```python
def time_pytorch_function(func, input):
    # CUDA IS ASYNC so can't use python time module
    start = torch.cuda.Event(enable_timing=True)
    end = torch.cuda.Event(enable_timing=True)

    # Warmup
    for _ in range(5):	# 5次预热迭代，以确保GPU处于稳定状态。
        func(input)

    start.record()
    func(input)
    end.record()
    torch.cuda.synchronize()    # 同步（即等待）GPU上的所有CUDA操作完成
    return start.elapsed_time(end)
```



#### autograd.profiler

```python
with torch.autograd.profiler.profile(use_cuda=True) as prof:
    torch.square(b)

print(prof.key_averages().table(sort_by="cuda_time_total", row_limit=10))
```



#### PyTorch profiler

> visual profiler

##### 默认版

```python
# Default way to use profiler
with profile(activities=[ProfilerActivity.CPU, ProfilerActivity.CUDA]) as prof:
    for _ in range(10):
        a = torch.square(torch.randn(10000, 10000).cuda())
prof.export_chrome_trace("trace.json")
```



##### 详细版

```python
def trace_handler(prof):
    print(prof.key_averages().table(
        sort_by="self_cuda_time_total", row_limit=-1))
    prof.export_chrome_trace("/tmp/test_trace_" + str(prof.step_num) + ".json")

with torch.profiler.profile(
    activities=[
        torch.profiler.ProfilerActivity.CPU,
        torch.profiler.ProfilerActivity.CUDA,
    ],

    # In this example with wait=1, warmup=1, active=2, repeat=1,
    # profiler will skip the first step/iteration,
    # start warming up on the second, record
    # the third and the forth iterations,
    # after which the trace will become available
    # and on_trace_ready (when set) is called;
    # the cycle repeats starting with the next step

    schedule=torch.profiler.schedule(
        wait=1,
        warmup=1,
        active=2,
        repeat=1),
    # on_trace_ready=trace_handler
    on_trace_ready=torch.profiler.tensorboard_trace_handler('./log')
    # used when outputting for tensorboard
    ) as p:
        for iter in range(10):
            torch.square(torch.randn(10000, 10000).cuda())
            # send a signal to the profiler that the next iteration has started
            p.step()
```

​	`torch.profiler.profile`中的参数：

+ `activities` 参数指定了要分析的活动，包括 CPU 和 CUDA 操作
+ `schedule` 参数定义了分析器的执行计划，包括等待时间、预热次数、活动次数和重复次数
+ `on_trace_ready` 参数指定了当分析器准备好输出跟踪数据时要执行的操作。在这里，你将跟踪数据输出到 TensorBoard 日志文件

![image-20240513171316277](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240513171316277.png)





### 在PyTorch中运行cuda等其他语言代码

#### load_inline

+ `from torch.utils.cpp_extension import load_inline`
+ 可以将其他语言的源码在PyTorch中运行

```python
# Define the CUDA kernel and C++ wrapper
cuda_source = '''
__global__ void square_matrix_kernel(const float* matrix, float* result, int width, int height) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < height && col < width) {
        int idx = row * width + col;
        result[idx] = matrix[idx] * matrix[idx];
    }
}

torch::Tensor square_matrix(torch::Tensor matrix) {
    const auto height = matrix.size(0);
    const auto width = matrix.size(1);

    auto result = torch::empty_like(matrix);

    dim3 threads_per_block(16, 16);
    dim3 number_of_blocks((width + threads_per_block.x - 1) / threads_per_block.x,
                          (height + threads_per_block.y - 1) / threads_per_block.y);

    square_matrix_kernel<<<number_of_blocks, threads_per_block>>>(
        matrix.data_ptr<float>(), result.data_ptr<float>(), width, height);

    return result;
    }
'''

cpp_source = "torch::Tensor square_matrix(torch::Tensor matrix);"

# Load the CUDA kernel as a PyTorch extension
square_matrix_extension = load_inline(
    name='square_matrix_extension',
    cpp_sources=cpp_source,
    cuda_sources=cuda_source,
    functions=['square_matrix'],
    with_cuda=True,
    extra_cuda_cflags=["-O2"],
    build_directory='./load_inline_cuda',
    # extra_cuda_cflags=['--expt-relaxed-constexpr']
)

a = torch.tensor([[1., 2., 3.], [4., 5., 6.]], device='cuda')
print(square_matrix_extension.square_matrix(a))
```







## Lecture 3+5 Getting started with CUDA + Going Further with CUDA

1. 为什么cuda不直接细分成threads，而是要先分成block再分threads?
   答：A thread block is a group of threads that can cooperate among themselves through ==shared memory==and synchronization. ==All threads in a block are executed on the same SM==. This means they can share resources such as shared memory and can synchronize their execution with each other.
2. ==cuda代码就是c/c++==





## Lecture 14 Practitioners Guide to Triton

> 详见jupypter notebook

##### 并行编程要点

并行编程只需要考虑两部分：

1. 如何划分块
2. 每一块进行的操作都是一模一样的，只需要编写每一块执行的操作即可。
   块内操作可以看成是顺序编程，唯一区别就是块内去要利用mask进行边界处理。



##### Tiled matmul 与共享内存

+ tile就是将block进一步划分，分成更小的块（Block=一整面墙，tile=一块瓷砖）
+ 出发点：通过共享内存进行计算实现加速，但共享内存很小，不能存放整个thread甚至block，因此要进一步分成更小的块
+ ==GPU中的共享内存相当于CPU中的cache==

## Lecture 11 Sparsity

### Lottery Ticket Hypothesis

+ 网络在训练之前prune掉90%~95%的节点，训练后精度依然能接近全节点网络，甚至精度更高。

步骤：

1. 随机初始化全网络
2. 简单训练几轮
3. prune掉一部分不重要的节点
4. 将剩下的节点之间的权重回到初始化的值
5. 返回第二步进行下一轮剪枝，直到仅剩下10%左右的节点



### Difference between inference and training

#### Training 

+ Only compute benefit, slight memory penalty(9/8)
  + 在训练过程中，主要的好处在于计算方面，这意味着操作被优化得更快。
  + 内存使用略有增加，大约是9/8。这可能是因为需要存储额外的信息或中间结果。
+ Sparsification happens at runtime
  + 将矩阵变为稀疏矩阵（减少非零元素的数量）的过程是在运行时进行的。
+ need both W and W^T
  + 训练过程中需要同时使用权重矩阵 \( W \) 及其转置 \( W^T \)。
+ Needs contiguous output for distributed collective
  + 输出需要是连续的，以便进行分布式集合操作（例如在多设备或多节点上进行计算时）。

#### Inference

+ Compute + memory speedup
  + 在推理过程中，计算和内存的使用都会得到提升，即计算速度更快，内存使用更少。
+ Sparsification happens offline
  + 稀疏化过程是在离线完成的，即在推理之前完成，而不是在运行时进行。
+ Just W is sufficient
  + 推理阶段只需要权重矩阵 \( W \)，不需要 \( W^T \)。
+ Can return a view and torch.compile away subsequent transposition
  + 可以返回一个矩阵的视图，并使用 `torch.compile` 优化后续可能需要的转置操作，从而进一步提升性能。

