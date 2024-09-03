# 封面

![image-20240514174423028](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240514174423028.png)

# 章节结构

![image-20240514174332817](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240514174332817.png)





# PART I Fundamental Concepts

### CUDA API

##### `cudaMalloc()`

+ 在GPU显存上分配对象（数组）
+ 两个参数
  + **Address of a pointer** to the allocated object（指针变量的地址）
  + **Size** of allocated object in terms of bytes （字节数）
+ ==这个函数执行完后，指针变量才会指向分配好的数组（即指针变量的内容是数组首地址）==



##### `cudaFree()`

+ 释放显存空间
+ 一个参数——**Pointer** to freed object（指针变量的值）



##### `cudaMemcpy()`

+ 用于数据传输（复制）
+ 可用于CPU<->CPU、GPU<->GPU、CPU<->GPU之间
+ 四个参数
  + 目的指针
  + 源指针
  + 总字节数
  + 方向：`cudaMemcpyHostToDevice`、`cuaMemcpyDeviceToHost`等（cuda预定义符号常量）



##### `cudaGetDeviceCount()`

+ 查询系统有多少cuda设备(GPU)

+ ```c
  int devCount;
  cudaGetDeviceCount(&devCount);
  ```



##### `cudaGetDeviceProperties()`

+ 查询某一GPU的设备属性

+ ```c
  cudaDeviceProp devProp;		// cuda内置变量（struct类型）
  cudaGetDeviceProperties(&devProp, i);	// i指定GPU下标
  ```

+ `cudaDeviceProp`所包含字段举例：

  + `maxThreadsPerBlock`
  + `multiProcessorCount`: SM数量
  + `clockRate`：时钟频率
  + `maxThreadsDim[0/1/2]`：block某一维度允许的最大线程数
  + `maxGridSize[0/1/2] `：grid某一维度允许的最大block数
  + `regsPerBlock`：每个SM可用的寄存器数量
  + `warpSize`：一个warp包含的thread数（**warp大小由硬件决定**）

### CUDA C keywords

#### 函数声明

![image-20240524172656090](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240524172656090.png)

+ `__host__`：就是普通的C函数，在CPU上运行，只能被CPU调用。
  ==没有关键字的函数默认为host function==
+ `__device__`:在GPU上运行，只能由GPU调用
+ `__global__`:表示这个函数是cuda 内核函数（kernel function)，在GPU上运行，可以被CPU或GPU调用。
+ 一个函数可以同时用`__host__`和`__device__`两个关键字，这样的函数会自动生成CPU和GPU两个版本。



#### 变量声明

![image-20240706223539028](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240706223539028.png)



### CUDA 内置变量

##### 配置参数

+ 类型：`dim3`（`vector<int>(x, y, z)`)s
+ 三个成员：x、y、z

##### `gridDim`

+ 在内核中根据配置参数的值进行初始化
+ 用于查看grid各维度有多少block
+ `gridDim.x`范围：$0\sim 2^{31}-1$
+ `gridDim.y`, `gridDim.z`范围：$0\sim 2^{16}-1(65535)$

##### `blockDim`

+ 在内核中根据配置参数的值进行初始化
+ 用于查看block各维度有多少threads
+ `blockDim.x`, `blockDim.y`, `blockDim.z`
+ 范围：一个block最多有1024threads，即`blockDim.x * blockDim.y * blockDim.z <= 1024`

##### `blockIdx`

+ 用于查看当前block是grid中的某一维度的第几个block
+ 由同一block中所有thread共享
+ `blockIdx.x`, `blockIdx.y`, `blockIdx.z`范围：$0\sim gridDim.x/y/z$
  （`gridDim.x/y/z`表示当前维度一共有多少block）

##### `threadIdx`

+ 用于查看当前thread是所在block中的某一维度的第几个thread
+ `threadIdx.x`, `threadIdx.y`, `threadIdx.z`范围：$0\sim blockDim.x/y/z$
  （`blockDim.x/y/z`表示当前维度一共有多少thread）





### Grid, Block and Thread

> When a program’s host code calls a kernel, the CUDA runtime system launches a grid of threads that are organized into a two-level hierarchy. Each grid is organized as an array of thread blocks, which we will refer to as blocks for brevity. All blocks of a grid are of the same size; each block can contain up to 1024 threads on current systems.

+ grid就是一个block数组
+ 一个block最多有1024线程



> For a given grid of threads, the number of threads in a block is available in a built-in variable named `blockDim`.The `blockDim` variable is a struct with three unsigned integer fields (x, y, and z) that help the programmer to organize the threads into a one-, two-, or three-dimensional array. 
>
> For a one-dimensional organization, only the x field is used. For a two-dimensional organization, the x and y fields are used. For a three-dimensional structure, all three x, y, and z fields are used.

+ cuda内置变量`blockDim`有x、y、z三个字段，分别表示各个维度有多少线程
+ block是一维时，只有x字段有用，`blockDim.x`就表示一个block有多少threads
+ 可见block最多分三维



![image-20240524163114267](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240524163114267.png)



> The NVCC (NVIDIA C compiler)processes a CUDA C program, using the CUDA keywords to separate the host code and device code. The host code is straight ANSI C code, which is compiled with the host’s standard C/C++ compilers and is run as a traditional CPU process. The device code, which is marked with CUDA keywords that designate CUDA kernels and their associated helper functions and data structures, is compiled by NVCC into virtual binary files called PTX files. These PTX files are further compiled by a runtime component of NVCC into the real object files and executed on a CUDA-capable GPU device.

+ cuda代码被NVCC编译成ptx文件，接着被编译成object文件在cudaGPU上运行



> When calling a kernel, the program needs to specify the size of the grid and the blocks in each dimension. These are specified by using the execution configuration parameters (within<<<...>>>) of the kernel call statement. The first execution configuration parameter specifies the dimensions of the grid in number of blocks. The second specifies the dimensions of each block in number of threads. Each such parameter has the type dim3, which is an integer vector type of three elements x, y, and z. These three elements specify the sizes of the three dimensions. The programmer can use fewer than three dimensions by setting the size of the unused dimensions to 1.

+ <<<...>>>之间的参数称为配置参数（configuration parameters），传入两个参数：

  + 需要多少block

  + 每个block有多少threads

+ 每个参数的类型都是`dim3`, 有三个整型成员x, y, z, 指定每个维度有多少block/threads。

  + 1表示当前维度未使用
  + 使用一维配置参数时，也可以直接用整数替代，不需要用dim3类型的参数（==因为y、z默认初始化为1==）
  + `vecAddKernel<<<32, 128>>>(...)`

例子：

```c++
dim3 dimGrid(32, 1, 1);
dim3 dimBlock(128, 1, 1);
vecAddKernel<<<dimGrid, dimBlock>>>(...)
```

+ 每个向量划分成32个一维block，每个block有128 threads



### GPU架构

#### SM（流多处理器Streaming Multiprocessor)

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240617135653619.png" alt="image-20240617135653619" style="zoom:50%;" />

+ 一个SM（Streaming Multiprocessor）可以分配多个Block



#### Warps

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240618155256357.png" alt="image-20240618155256357" style="zoom:50%;" /> 

+ 1 warp = 32 threads
+ 如果thread是二/三维排列，那么flatten成一维后，每32个thread属于一个warp
+ **一个warp中的所有线程同时执行某一条指令**，称为'single instruction, multiple-thread'
  即warp是取指执行的最小单位

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240618182321060.png" alt="image-20240618182321060" style="zoom:50%;" /> 

+ ==对于Pascal架构GPU：==一个warp中的线程不能同时执行多种指令。例如在if语句中，同一时刻只能执行一个分支
+ 从Volta架构开始，一个warp中的线程可以同时执行多个分支





#### CUDA 内存结构

##### Overview

![image-20240706020046379](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240706020046379.png)

##### CPU vs GPU 寄存器架构

> ​	When CPUs context switch between different threads, they save the registers of the outgoing thread to memory and restore the registers of the incoming thread from memory. In contrast, GPUs achieve zero-overhead scheduling by keeping the registers of all the threads that are scheduled on the processing block in the processing block’s register file. This way, switching between warps of threads is instantaneous because the registers of the incoming threads are already in the register file. Consequently, GPU register files need to be substantially larger than CPU register files.
>
> ​	当 CPU 在不同线程之间进行上下文切换时，它们会将退出线程的寄存器保存到内存中，并从内存中恢复进入线程的寄存器。与此相反，GPU 将当前块上调度的所有线程的寄存器保存在块的寄存器文件中，实现零开销调度。通过这种方式，线程之间的切换是瞬时的，因为进入线程的寄存器已经在寄存器文件中。因此，GPU 寄存器文件需要比 CPU 寄存器文件大得多。
>
> ​	GPUs support dynamic resource partitioning where an SM may provision few registers per thread and execute a large number of threads, or it my provision more registers per thread and execute fewer threads. For this reason, GPU register files need to be designed to support such dynamic partitioning of registers. In contrast, the CPU register architecture dedicates a fixed set of registers per thread regardless of the thread’s actual demand for registers.
>
> ​	GPU 支持动态资源分区，SM 可以为每个线程提供很少的寄存器并执行大量的线程，也可以为每个线程提供较多的寄存器并执行较少的线程。因此，GPU 寄存器文件的设计需要支持这种寄存器动态分区。相比之下，CPU 的寄存器架构会为每个线程分配一组固定的寄存器，而不管线程对寄存器的实际需求如何。



+ GPU切换线程为零开销，CPU开销很大（内存调度）
+ GPU线程上下文保存在寄存器文件中，CPU线程上下文保存在内存中，因此GPU寄存器比CPU大得多
+ GPU支持为线程动态分配寄存器，CPU只能固定分配



##### 共享内存vs寄存器

![image-20240706195446602](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240706195446602.png)

+ 共享寄存器可以被所有线程访问，旨在不同线程之间的高效数据共享
+ 寄存器是线程私有的



### Performance Considerations

![image-20240814150650489](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240814150650489.png)



### Kernel Example

#### Vector Addition

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240524174617453.png" alt="image-20240524174617453" style="zoom: 50%;" /> 



#### Image Blur

![image-20240606180613907](C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20240606180613907.png)



#### Tiled Matmul

##### Tile

> The term tile draws on the analogy that a large wall(i. e., the global memory data) can be covered by small tiles(i. e., subsets that can each fit into the shared memory).

+ tile就是将block进一步划分，分成更小的块（Block=一整面墙，tile=一块瓷砖）
+ 出发点：通过 ==共享内存==进行计算实现加速，但共享内存很小，不能存放整个thread甚至block，因此要进一步分成更小的块



# PART II Parallel Patterns









# PART III Advanced Parallel Patterns & Applications









# PART IV Advanced Practices

