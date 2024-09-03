## 笔记

### triton vs cuda

#### 特性

+ triton不需要考虑shared memory，而cuda需要手动实现

#### 什么是program

> Note on jargon: In triton lingo, each kernel (which processes a block) is called a "program". I.e., our example above runs 2 programs. Therefore, "block_id" is often called "pid" (short for "program id"), but it's the same.

+ triton中的program就是cuda中的block
+ cuda把计算分成block和thread，而triton只分为block。
  triton在block中可以直接进行vector运算，因此比cuda好写得多

#### triton kernel中的操作

> **All** operations in triton kernels are vectorized: Loading data, operating on data, storing data, and creating masks.

+ triton kernel中一共只有四种操作：存/取数据、计算、越界检测

#### 什么是grid

+ 一个tensor
+ 用来指定block(program)的分块维度，每个维度分成多少块





## Kernel

