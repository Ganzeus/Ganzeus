cuda-mode lectures 学习笔记

----

# Lecture1 Profiling and Integrating CUDA kernels in PyTorch

## 三种Profile方法

#### cuda.Event测量执行时间

```python
def time_pytorch_function(func, input):
    # CUDA IS ASYNC so can't use python time module
    # 在 CUDA 中，GPU 的计算和CPU的计算可以同时进行，因此它们是异步的
    # 而使用 time 模块来测量 CUDA 函数的执行时间并不准确，因为它无法考虑到 GPU 计算的异步性
    start = torch.cuda.Event(enable_timing=True)
    end = torch.cuda.Event(enable_timing=True)

    # Warmup
    for _ in range(5):	# 5次预热迭代，以确保GPU处于稳定状态。
2        func(input)

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
## Default way to use profiler
with profile(activities=[ProfilerActivity.CPU, ProfilerActivity.CUDA]) as prof:
    for _ in range(10):z`
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



## How to run cuda kernels in PyTorch

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



## Triton debugger

`@triton.hit(interpret=True)`

