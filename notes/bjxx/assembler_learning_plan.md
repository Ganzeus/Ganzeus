# Assembler & 935 芯片硬件架构 —— 知识文档 + 一周学习计划

> 📅 创建日期：2026-04-16
> 🎯 目标：一周内做到"能画出 935 芯片架构图 + 能对着图讲清楚数据怎么流、指令怎么跑"
> 📎 配套：[gaoz132_learning_plan.md](gaoz132_learning_plan.md) / [study_resources_and_schedule.md](study_resources_and_schedule.md)
> ⚠ 背景：领导新任务——assembler 项目重点关注，大模型（Qwen/Llama）落地。自动化任务暂缓。

---

# Part 1 · 前置知识（你需要先搞懂的基础概念）

> 每个概念我直接在这里解释。如果你觉得解释够了就跳过"深入阅读"链接；想挖深就点进去看。

---

## 1.1 什么是 NPU / DSA

**NPU** = Neural Processing Unit（神经网络处理单元），是一种 **DSA**（Domain-Specific Architecture，领域专用架构）。

**用大白话说**：GPU 是"什么都能算，但不是什么都算得最高效"；NPU 是"只能算神经网络，但算神经网络特别快、特别省电"。

**为什么不直接用 GPU**：
- GPU 的 CUDA core 是通用的，能跑任何计算，但要消耗能量在"通用调度"上
- NPU 把计算单元做成**专用硬件流水线**（比如脉动阵列），省掉了调度开销
- 智驾场景对功耗极其敏感（装在车上，不能装个服务器级水冷），所以用 NPU

**你们公司的 NPU** 叫 **Qiming-935**（或 940，同系列），内部代号 **Zeus**。下面所有讲的硬件都是指这颗芯片。

**类比**：如果 GPU 是瑞士军刀，NPU 就是手术刀——功能更窄，但在自己的领域里精度和效率碾压。

> 深入阅读：[知乎：AI 编译器及 TVM 概述](https://zhuanlan.zhihu.com/p/672462650) 里有 DSA vs GPU 的对比

---

## 1.2 脉动阵列（Systolic Array）—— PE Array 的工作原理

你们芯片里的 **PE Array**（8×8 = 64 个 Processing Element）就是一个**脉动阵列**。

### 什么是脉动阵列

> ⚠ 以下是**简化教科书模型**，帮你快速建立直觉。实际硬件中每个 PE 不是只处理"一个数"，而是一个 **8 元素向量**——详见本节末尾"实际硬件"小节。

想象一个 8×8 的格子，每个格子里有一个小计算器（PE）。在简化模型里，这个计算器做一件事：**把两个数相乘，然后加到自己的累加器上**（MAC = Multiply-Accumulate）。

```
        权重 W 从上方逐列流入
        ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓
      ┌──┬──┬──┬──┬──┬──┬──┬──┐
 A →  │PE│PE│PE│PE│PE│PE│PE│PE│  → 部分和向右传递
 从 → │PE│PE│PE│PE│PE│PE│PE│PE│
 左 → │PE│PE│PE│PE│PE│PE│PE│PE│
 侧 → │PE│PE│PE│PE│PE│PE│PE│PE│
 逐 → │PE│PE│PE│PE│PE│PE│PE│PE│
 行 → │PE│PE│PE│PE│PE│PE│PE│PE│
 流 → │PE│PE│PE│PE│PE│PE│PE│PE│
 入 → │PE│PE│PE│PE│PE│PE│PE│PE│
      └──┴──┴──┴──┴──┴──┴──┴──┘
```

**工作流程**：
1. **权重**从上方逐列加载到每个 PE 里（预先加载好，不动了）
2. **激活值（输入数据）**从左侧逐行流入
3. 每个 PE 在每个时钟周期做一次 **MAC 运算**：`累加器 += 输入 × 权重`（简化描述；实际每 PE 每周期做 **8 次** MAC，见下方"实际硬件"小节）
4. 计算完一行后，**部分和（partial sum）**往下传给下一行 PE 继续累加（注：这是简化数据流模型，实际 PE Array 的数据流动方式取决于 dataflow 设计——weight-stationary / output-stationary 等，不同设计下数据流向不同）
5. 最终从底部流出完整的输出

**关键优势**：数据在 PE 之间"流动"而不是每次都从内存读取，大幅减少了访存次数。这就是为什么脉动阵列比 GPU 省电的核心原因。

### 实际硬件：每个 PE 是 8-wide 向量 MAC 单元

> 上面的简化模型里，一个 PE 每周期做 1 次 `标量 × 标量` 的 MAC。**实际上，你们芯片的每个 PE 包含 8 个并行乘法器，每周期做 8 次 MAC——即一次 8 维向量点积。**

**一个 PE 在一个时钟周期内做的运算**：

```
acc(FP32) += a0×w0 + a1×w1 + a2×w2 + a3×w3 + a4×w4 + a5×w5 + a6×w6 + a7×w7
             \___________________ 8 个 INT8×INT8 乘法 ___________________/
```

#### PE 的输入/输出位宽

| 数据 | 精度 | 个数/周期 | 总位宽/周期 | 来源 → 去向 |
|---|---|---|---|---|
| 激活值 | INT8 (8 bit) | 8 | 64 bit | AL1 → PE |
| 权重 | INT8 (8 bit) | 8 | 64 bit | WL1 → PE |
| 累加结果 | FP32 (32 bit) | 1 | 32 bit | PE 内部累加寄存器 → OL1（仅在 k 维累加完毕后写出） |

> WL1 和 AL1 的带宽都是 64 bit/cycle，恰好每周期喂一个 PE 所需的 8 个 INT8 元素。

#### PE 内部电路：底层是怎么算的

PE 内部不是"一个电路既算整数又算浮点"，而是**四段不同的硬件电路串联在一起**：

```
  ① 输入: 8 个 INT8 激活 + 8 个 INT8 权重（共 128 bit/周期）
     ┌──┬──┬──┬──┬──┬──┬──┬──┐   ┌──┬──┬──┬──┬──┬──┬──┬──┐
     │a0│a1│a2│a3│a4│a5│a6│a7│   │w0│w1│w2│w3│w4│w5│w6│w7│
     └┬─┴┬─┴┬─┴┬─┴┬─┴┬─┴┬─┴┬┘   └┬─┴┬─┴┬─┴┬─┴┬─┴┬─┴┬─┴┬┘
      │  │  │  │  │  │  │  │      │  │  │  │  │  │  │  │
      ▼  ▼  ▼  ▼  ▼  ▼  ▼  ▼      ▼  ▼  ▼  ▼  ▼  ▼  ▼  ▼

  ② 8 个并行 INT8×INT8 乘法器 → 每个输出 INT16（16 bit）
     ┌──────┐┌──────┐┌──────┐┌──────┐┌──────┐┌──────┐┌──────┐┌──────┐
     │a0×w0 ││a1×w1 ││a2×w2 ││a3×w3 ││a4×w4 ││a5×w5 ││a6×w6 ││a7×w7 │
     │INT16 ││INT16 ││INT16 ││INT16 ││INT16 ││INT16 ││INT16 ││INT16 │
     └──┬───┘└──┬───┘└──┬───┘└──┬───┘└──┬───┘└──┬───┘└──┬───┘└──┬───┘
        └──┬────┘       └──┬────┘       └──┬────┘       └──┬────┘

  ③ 加法树（Adder Tree）: 3 级流水线把 8 个乘积求和
        第1级:  [+] INT17    [+] INT17    [+] INT17    [+] INT17
                 └────┬──────┘             └────┬──────┘
        第2级:        [+] INT18                 [+] INT18
                       └──────────┬─────────────┘
        第3级:                    [+] INT19  ← 8 个乘积之和（最多 19 bit）

        位宽逐级增长原因: 两个 N-bit 整数相加，结果最多需要 N+1 bit
                         8=2³ 个 INT16 求和 → 最多 16+3 = 19 bit

  ④ 整数→浮点转换
        INT19 ──► [INT→FP32 转换电路] ──► FP32 值

  ⑤ FP32 累加
        ┌────────────────────────────┐
        │ acc(FP32) += 转换后的FP32值  │  ← FP32 加法器
        │ acc 是 PE 内部 32-bit 寄存器 │
        └────────────────────────────┘
```

#### 为什么用 INT8 乘法 + FP32 累加（混合精度设计）

| 部件 | 电路类型 | 面积（逻辑门数） | 为什么选这个精度 |
|---|---|---|---|
| 乘法器 ×8 | INT8 整数乘法 | ~64 门/个（**极小**） | 乘法占面积大头，INT8 比 FP32 乘法器小约 30 倍 |
| 加法树 | 整数加法 | 很小 | 8 个 INT16 求和，纯整数 |
| INT→FP 转换 | 格式转换 | 较小 | 每周期只做一次，开销可忽略 |
| 累加器 | FP32 浮点加法 | ~数百门（中等） | 防溢出——100 次 MAC 后最大值可达 1,612,900，INT8 只能表示到 127 |

**设计哲学**：在最高频运算（乘法，8 次/周期/PE）上用最省的精度（INT8），在需要保精度的运算（累加）上用高精度（FP32）。这和 PyTorch 的 AMP（自动混合精度训练）是完全相同的思路。

#### 对矩阵乘法的影响

文档前面说 "PE(i,j) 计算 C(i,j) = Σ\_k A(i,k)×B(k,j)"，这个 k 维的累加不是逐个做的，而是 **每次消化 8 个 k 值**：

```
C(i,j) = A(i, 0:8) · B(0:8, j)      ← 第 1 个周期，PE 做 8 次 MAC
       + A(i, 8:16) · B(8:16, j)     ← 第 2 个周期
       + A(i, 16:24) · B(16:24, j)   ← 第 3 个周期
       + ...                          ← 直到 k 维耗尽
```

**两层并行度**（两个 "8" 是不同维度的并行）：

| 并行维度 | 数量 | 作用 |
|---|---|---|
| PE 个数 | 8×8 = 64 | 同时计算 64 个不同的 C(i,j) 输出元素 |
| 每 PE 的 vector width | 8 | 每个 C(i,j) 的 k 维累加每周期消化 8 个元素 |

**峰值算力**：64 PE × 8 MAC/PE/周期 × 1 GHz = **512 GOPS (INT8)**

#### PE Array ≠ 芯片的全部计算能力

PE Array（脉动阵列）只负责**矩阵类运算**（卷积、矩阵乘法、全连接）。芯片上还有另一个独立的计算单元 **VP（Vector Processor，向量处理器）**，负责所有**逐元素运算**：

| 运算类型 | 硬件单元 | 举例 |
|---|---|---|
| 矩阵乘法 / 卷积 | **PE Array**（脉动阵列） | Conv2d, Linear, Bmm, FC |
| 逐元素运算 / 激活函数 / 归一化 | **VP**（向量处理器） | ReLU, Softmax, LayerNorm, GELU, Add, MaxPool |
| 数据搬运 / 格式转换 | **DT** | NCHW→NHWC 转换，L2 内部搬运 |

> 在 Transformer/LLM 里，VP 的工作量不可忽视——Softmax、LayerNorm、GELU、残差 Add 全在 VP 上跑。PE 和 VP 是芯片上的 **两大计算引擎**，缺一不可。

### 用矩阵乘法理解

矩阵乘法 `C = A × B`：
- A 的第 i 行从左侧流入
- B 的第 j 列从上方预加载
- PE(i,j) 计算 C(i,j) = Σ A(i,k) × B(k,j)

**对应你们芯片**：
- A = 激活值（feature map）→ 从 AL1 读
- B = 权重（weight）→ 从 WL1 读
- C = 输出 → 写到 OL1

### 你们芯片的 PE 参数

| 参数 | 值 | 含义 |
|---|---|---|
| Array 大小 | 8×8 = 64 PE | 同时做 64 个 MAC |
| Vector Width | 8 | 每个 PE 每周期可处理 8 个元素 |
| 乘法精度 | INT8 | 8-bit 整数乘法 |
| 加法精度 | FP32 | 32-bit 浮点累加（防止精度损失） |
| 频率 | 1 GHz | 每秒 10 亿个时钟周期 |
| 峰值算力 | 64×8 = 512 ops/cycle | @1GHz = **512 GOPS**（INT8） |

> 深入阅读：
> - [知乎：脉动阵列 - 计算机体系结构](https://zhuanlan.zhihu.com/p/650209037) — 最好的中文科普，有动图
> - [知乎：脉动阵列 Systolic Architectures](https://zhuanlan.zhihu.com/p/605590757)
> - [博客园：Systolic Array 加速矩阵乘运算](https://www.cnblogs.com/kongchung/p/13227256.html)

---

## 1.3 Memory Hierarchy（存储层级）—— 为什么有这么多层 Memory

### 核心矛盾

计算单元（PE Array）算得极快（512 GOPS），但数据从**外部 DRAM 搬进来**的速度跟不上。如果 PE 每做一次乘法都要去 DRAM 读数据，PE 大部分时间在**等数据**（idle），效率极低。

### 解法：多级缓存

就像你家里的存储层级：
- **口袋**（WL1, 18.5KB）：伸手就能拿到，但只能放几样东西
- **桌面**（L2, 1MB）：走两步就能拿到，能放更多东西
- **仓库**（DRAM, 数百 MB~数 GB）：要开车去拿，但什么都能存

**策略**：把接下来要用的数据提前从仓库（DRAM）搬到桌面（L2），再从桌面搬到口袋（WL1/AL1），PE 直接从口袋取。用完就扔回桌面或仓库，腾出口袋空间放下一批数据。

### Tiling（分块计算）

问题：WL1 只有 18.5KB，但一个 Llama-7B 的权重有 7GB。怎么塞进去？

答案：**不塞全部，只塞一小块**。

把大矩阵切成很多小 tile（类比你写 Triton 时的 `BLOCK_SIZE`）。每次只把一个 tile 的权重搬进 WL1，算完这个 tile，再搬下一个 tile 的权重进来。

### Double Buffering（双缓冲）

问题：搬数据需要时间，PE 在等搬运的时候是空闲的，浪费了。

答案：把 WL1 分成两半——**一半在被 PE 使用，另一半同时在搬下一批数据**。等 PE 用完当前这半，切换过去用另一半（那边已经搬好了），然后刚才用完的那半开始搬再下一批。PE 永远不用等。

```
时间 →
WL1-A:  [搬 tile1] [PE 用 tile1] [搬 tile3] [PE 用 tile3] ...
WL1-B:  [idle    ] [搬 tile2   ] [PE 用 tile2] [搬 tile4   ] ...
PE:     [idle    ] [算 tile1   ] [算 tile2   ] [算 tile3   ] ...
```

这就是为什么代码里 WL1 有 `BATON_WL1_DOUBLE_BUFFER` 选项，大小从 16KB 变成 18.5KB。

> 深入阅读：[MLSys Book: Hardware Acceleration](https://mlsysbook.ai/contents/core/hw_acceleration/hw_acceleration.html)

---

## 1.4 指令集（ISA）—— 芯片能听懂的"命令"

### 类比

CPU 的指令集是 x86 / ARM：`ADD R1, R2, R3`（把 R2 和 R3 相加，结果放 R1）。

NPU 的指令集类似，但命令是**专门给神经网络设计的**：
- `CONV`：让 PE Array 做一次卷积运算
- `LDA_MOV`：把数据从 DRAM 搬到 L2
- `VP_SELF`：让 VP 做一次元素级运算（比如 ReLU、Softmax）

### 你们芯片的指令格式

每条指令 **16 字节（128 bit）**。前 8 bit 是 **opcode**（操作码，告诉硬件"做什么"），后面的 bit 是**参数**（告诉硬件"对什么数据做、参数是多少"）。

```
┌────────┬──────────────────────────────────────────────────┐
│ opcode │ 参数字段（source shape, dest shape, padding, ...）  │
│  8bit  │                    120bit                         │
└────────┴──────────────────────────────────────────────────┘
```

**assembler 做的事就是**：把人类可读的"用 3×3 卷积处理 224×224 图像"翻译成一连串这样的 16 字节指令，写进 `inst_file.bin`。

---

# Part 2 · 935/940 芯片架构详解

> 以下所有数据都是从你们的代码里直接挖出来的，不是通用知识。

---

## 2.1 单核架构图

```
                        ┌─────────────────────────────────────┐
                        │           Zeus NPU  单核             │
                        │                                     │
  DRAM ◄────────────────┤  ┌─────────┐   ┌──────────────────┐ │
  (数百MB~数GB)          │  │ LD/LW   │   │   PE Array 8×8   │ │
    │                   │  │ 从DRAM  │   │  ┌──┬──┬──┬──┐   │ │
    │  LD: 搬激活       │  │ 搬数据  ├──►│  │PE│PE│..│PE│   │ │
    │  LW: 搬权重       │  │ 到L2    │   │  ├──┼──┼──┼──┤   │ │
    │                   │  └─────────┘   │  │PE│PE│..│PE│   │ │
    │                   │                │  └──┴──┴──┴──┘   │ │
    │  ┌────────────────┼───────┐        │  WL1:18.5KB(权重) │ │
    │  │    L2 Cache    │       │        │  AL1:2KB(激活)    │ │
    │  │    1 MB        │       │        │  OL1:36B(输出)    │ │
    │  │  (核内共享)     │       │        └──────┬───────────┘ │
    │  │                │       │               │             │
    │  │                │  ┌────▼────┐   ┌──────▼───────────┐ │
    │  │                │  │  DT     │   │   VP             │ │
    │  │                │  │ 片上搬运│   │ 激活/池化/逐元素   │ │
    │  │                │  │ +格式转 │   │ ReLU/Softmax/Add │ │
    │  │                │  └─────────┘   └──────────────────┘ │
    │  └────────────────┼───────┘                             │
    │                   │  ┌─────────┐   ┌──────────────────┐ │
    │  ST: 写回结果      │  │  ST     │   │   CT  控制流      │ │
    ◄───────────────────┤  │ L2→DRAM │   │ 程序开始/结束/跳转│ │
                        │  └─────────┘   └──────────────────┘ │
                        │                                     │
                        │  ┌─────────┐   ┌──────────────────┐ │
                        │  │  SI     │   │   SO             │ │
                        │  │ 同步输入│   │ 同步输出          │ │
                        │  │(从别核) │   │(给别核)           │ │
                        │  └─────────┘   └──────────────────┘ │
                        └─────────────────────────────────────┘
```

---

## 2.2 各硬件单元详解

### PE（Processing Element）—— 主计算单元

| 属性 | 值 |
|---|---|
| 功能 | 卷积（Conv2d）、矩阵乘法（Dense/FC/Bmm）、反卷积 |
| 结构 | 8×8 脉动阵列，每 PE 含 8-wide 向量单元 |
| 精度 | INT8 乘法 + FP32 累加 |
| 私有存储 | WL1 (18.5KB, 存权重), AL1 (2KB, 存激活), OL1 (36B, 存部分和) |

**对应指令**：

| 指令名 | opcode | 做什么 |
|---|---|---|
| PE_CFG_FM | 128 | 配置输入/输出 feature map 的 shape 和格式 |
| PE_CFG_DQ | 129 | 配置反量化参数（scale, bias） |
| PE_CFG_PM | 130 | 配置激活函数、stride、量化参数 |
| PE_CFG_DE | 131 | 配置 tile 切分细节（tile height/width） |
| PE_CFG_TP | 132 | 配置 transpose 参数 |
| CONV | 144 | 执行标准卷积 |
| DICV | 145 | 执行 depthwise 卷积 |
| DECV | 146 | 执行反卷积 |
| GPCV | 147 | 执行 grouped pointwise 卷积 |
| FC | 148 | 执行全连接 / 矩阵乘法 |

**理解方式**：PE 做一次计算前，需要先发若干条 `PE_CFG_*` 指令告诉它"输入多大、权重多大、用什么激活函数"，然后发一条 `CONV` 或 `FC` 开始计算。类比你写 Triton 时先设置 `BLOCK_SIZE`、`stride` 这些参数，再调 `tl.dot()`。

> **PE 内部电路详解**见 [1.2 节"实际硬件"小节](#实际硬件每个-pe-是-8-wide-向量-mac-单元)，包括 INT8 乘法器 → 加法树 → INT→FP32 转换 → FP32 累加器的完整底层流程。

### VP（Vector Processor）—— 芯片的第二大计算引擎

> VP 不是 PE 的"后处理附属"，而是一个**独立的、完整的计算单元**。在 Transformer 模型里，VP 的工作量与 PE 不相上下。

| 属性 | 值 |
|---|---|
| 功能 | 逐元素运算（Add/Mul/Div）、激活函数（ReLU/Sigmoid/GELU/SiLU/Softmax）、池化（AvgPool/MaxPool）、归一化（LayerNorm/BatchNorm/RMSNorm） |
| 定位 | 与 PE Array 并列的**第二大计算引擎**——PE 做矩阵运算，VP 做一切非矩阵运算 |
| 数据来源 | 从 L2 读数据，或直接接收 PE 的输出 |

**PE vs VP 的分工**：

| 如果运算是… | 则用… | 原因 |
|---|---|---|
| 两个矩阵相乘、卷积 | PE Array | 脉动阵列为矩阵乘法专门设计 |
| 对每个元素独立做运算（如 max(0,x)、exp(x)） | VP | 不涉及元素间的"乘加缩减"，脉动阵列帮不上忙 |
| 需要跨元素统计再逐元素处理（如 Softmax、LayerNorm） | VP | 先求 max/mean/var，再逐元素计算——VP 有专门的 reduce + broadcast 能力 |

**对应指令**：VP_CFG_FM (192), VP_CFG_GCS (193), VP_SELF (200), VP_UPSM (201), VP_POOL (202) 等。

**大模型里 VP 的工作**：Transformer 里的 Softmax、LayerNorm、GELU/SiLU、残差 Add、RoPE 位置编码全在 VP 上跑。一个 Transformer block 里大约一半的算子是 VP 负责的（虽然计算量主要集中在 PE 的矩阵乘法上）。

### DT（Data Transfer）—— 片上搬运

| 属性 | 值 |
|---|---|
| 功能 | L2 内部的数据搬运 + 数据格式转换（如 NCHW → NHWC） |
| 对应指令 | DT_CFG (160), DT_CAL (168) |

### LD / LW（Load Data / Load Weight）—— DRAM → L2 搬运

| 指令 | opcode | 做什么 |
|---|---|---|
| LDA_CFG | 32 | 配置激活值加载参数（DRAM 地址、大小） |
| LDA_MOV | 40 | 执行激活值搬运：DRAM → L2 |
| LDW_CFG | 33 | 配置权重加载参数 |
| LDW_MOV | 41 | 执行权重搬运：DRAM → L2 |
| LW_CFG | 65 | 配置 L2→WL1 的权重搬运 |
| LW_MOV | 73 | 执行 L2→WL1 搬运 |

### ST（Store）—— L2 → DRAM 写回

| 指令 | opcode | 做什么 |
|---|---|---|
| STA_CFG | 96 | 配置激活值写回参数 |
| STA_MOV | 104 | 执行写回：L2 → DRAM |

### SI / SO（Sync In / Sync Out）—— 核间同步

多核跑一个模型时，核与核之间需要交换数据或等待。SI 接收别的核发来的数据/信号，SO 发送给别的核。

| 指令 | 做什么 |
|---|---|
| SI_SYN_CFG (52) | 配置同步等待条件 |
| SO_SYN_CFG (116) | 配置同步发送信号 |
| SIAA_MOV (56) | 从其他核接收激活值 |
| SOPW_MOV (121) | 向其他核发送权重 |

### CT（Control）—— 控制流

| 指令 | opcode | 做什么 |
|---|---|---|
| CT_ST | 0 | 程序开始 |
| CT_ED | 255 | 程序结束 |
| CT_BC | 16 | 循环/条件跳转 |

---

## 2.3 三级存储详解

| 层级 | 名称 | 大小 | 存什么 | 带宽 | 谁用 |
|---|---|---|---|---|---|
| L0 | WL1 | 18.5 KB/core | 权重（每次搬一个 tile） | 64 bit/cycle | PE |
| L0 | AL1 | 2 KB/core | 激活值（输入 feature map 的一块） | 64 bit/cycle | PE |
| L0 | OL1 | 36 B/core | 输出暂存（PE 累加完毕后写出的结果） | — | PE |

> **OL1 ≠ PE 内部累加器**：每个 PE 内部有自己的 FP32 累加寄存器（32 bit，属于 PE 电路本身），在 k 维累加过程中一直在 PE 内部更新，不占 OL1 空间。OL1 是一个小的**输出暂存区**，只在累加完毕、结果需要写出到 L2 时才用到。
| L1 | L2 | 1 MB/core | 权重+激活+中间结果的"中转站" | 32 GB/s | 所有单元共享 |
| L2 | DRAM | 数百 MB~数 GB | 全部数据：模型权重、输入、输出、KV-cache | 可配置 | LD/LW/ST 搬运 |

**数据流路径**：

```
权重路径:   DRAM ──LDW──► L2 ──LW──► WL1 ──► PE (计算)
激活路径:   DRAM ──LDA──► L2 ──────► AL1 ──► PE (计算)
输出路径:   PE ──► OL1 ──► L2 ──STA──► DRAM
```

---

## 2.4 多核架构

你们芯片支持 **1~4 核**（甚至更多）。多核时：
- 每个核有自己的 PE/VP/DT + WL1/AL1/L2
- DRAM 是所有核**共享**的
- 核间通过 **SI/SO 指令**同步：一个核算完 layer1，通过 SO 告诉另一个核"你可以开始算 layer2 了"
- stschedule 负责决定"哪些层放在哪个核上算"

---

# Part 3 · Assembler 项目分析

---

## 3.1 宏观：吃什么、吐什么

```
输入（三样东西）                    输出
┌──────────────┐               ┌──────────────────┐
│ .fsir.json   │ 前端 IR:       │ inst_file.bin    │ 16B/条机器指令
│              │ 网络结构+算子   │ weight_data.bin  │ 重排后权重
│ *_stschedule │ 调度 IR:       │ fixed_data.bin   │ 量化/BN 参数
│  .json       │ 多核分配+tiling│ net_config_*.json│ SDK 接口文件
│ fusion_info  │ 层融合信息     │ rela.json        │ 重定位信息
│  .json       │               │ asm_debug/       │ 调试中间文件
│ parameters/  │ .npy 权重文件  │ dag/             │ 指令DAG可视化
│  *.npy       │               └──────────────────┘
└──────────────┘
```

**用一句话说**：assembler 把"人类能读懂的网络描述 + 调度方案"翻译成"芯片能直接执行的二进制指令"。

---

## 3.2 微观：5 层 IR Lowering

Assembler 不是一步到位把 FSIR 变成二进制，而是分 **5 层**逐步降低抽象级别。

> **Lowering（降级）**：每一层只做一点点变换，把"更像人话"的描述变成"更像机器话"的描述。好处是每层逻辑简单、好调试、好扩展。

### 第 1 层：FSIR（前端 IR）

**是什么**：一个 JSON 文件，描述网络里每一层的算子类型和参数。

```json
{
  "Conv_1": {
    "operation": "conv2d",
    "input_shape": [[1,8,16,16], [16,8,3,3]],
    "output_shape": [[1,16,14,14]],
    "kernel_size": [3,3],
    "stride": [1,1],
    "activation_type": "relu"
  }
}
```

**类比**：菜谱——"用 3×3 的锅炒 16×16 的菜"

### 第 2 层：NNLayer / NNGraph

**是什么**：把 JSON 字典变成 Python 对象，构建有向图（每层是一个节点，层与层之间的连接是边）。

**做了什么变换**：
- 删除冗余的 Shape/Reshape 算子
- 同步调度信息（STSIR 里说的"这层在第几个核上跑"）
- BN 融合（BatchNorm 合并到前面的 Conv 里，减少一层计算）

**代码位置**：`assembler/transforms/fsir2nnlayer.py`

**类比**：把菜谱整理成标准流程图——"先切菜 → 再炒菜 → 最后装盘"

### 第 3 层：ZeusLayer / ZeusGraph

**是什么**：把抽象的"Conv2d 层"绑定到具体的硬件单元——这个 Conv 要在 **PE** 上算，数据要从 **DRAM** 搬。

**做了什么变换**：
- 每个 NNLayer 变成一个 ZeusLayer，标注了 `unit="PE"` 或 `unit="VP"` 或 `unit="DT"`
- 数据变成 ZeusFMP（Feature Map Partition），带上了 DRAM 地址和 L2 地址
- 做 ZeusLayer 级别的图优化（合并可以合并的计算）

**代码位置**：`assembler/transforms/nnlayer2zeuslayer.py`

**类比**：流程图上标注"这步用炒锅、那步用蒸锅、食材放在哪个架子上"

### 第 4 层：ABSNode（抽象指令节点）

**是什么**：把一个 ZeusLayer 拆成一系列"操作步骤"：先 Load 数据到 L2 → 再从 L2 搬到 WL1 → 再计算 → 再 Store 回 DRAM。这些步骤形成一个**指令 DAG（有向无环图）**。

**DAG 的意义**：有些指令可以并行（比如搬权重和搬激活可以同时做），DAG 表示了哪些指令必须等前一个做完、哪些可以并行。

**代码位置**：`assembler/target/zeus/core.py` 里的 `parse_ir()` 方法

**类比**：把"炒菜"拆成"取油→热锅→下料→翻炒→起锅"，并标注哪些步骤可以同时做

### 第 5 层：MachineInstr（机器指令）

**是什么**：把 ABSNode 翻译成具体的 16 字节二进制指令，带上具体的 opcode 和字段值。

**代码位置**：`assembler/dialect/zeus_inst/op.py`（指令类定义）+ `assembler/target/zeus/core.py` 里的 `lowering()` 方法

**最终输出**：`inst_file.bin` —— 芯片直接读取执行的二进制文件

**类比**：把"取油"翻译成机器人能执行的指令——"左手伸到架子第 3 格 (地址 0x3000)，拿起 500ml 瓶子 (大小 500B)，放到灶台左侧 (L2 地址 0x100)"

---

## 3.3 编译 Pipeline（代码执行顺序）

```python
# 文件：assembler/api/build.py — Network 类的构造函数
# 以下是 assembler 的编译流水线，按顺序执行：

CFGOptimizePass()          # 1. 配置优化
FSIROptimizePass()         # 2. 前端 IR 预处理（删冗余算子、同步调度信息、BN 融合）
FSIR2NNGraphPass()         # 3. FSIR → NNLayer 图（JSON → Python 对象图）
NNGraph2ZeusGraphPass()    # 4. NNLayer → ZeusLayer（绑定硬件单元）
ZeusGraphDealMemOpPass()   # 5. ZeusLayer 图优化（内存操作处理）
ZeusData2DRAMTensor()      # 6. 数据 → DRAM Tensor（分配 DRAM 地址）
CreateTaskPass()           # 7. 创建 Task（按核分配工作）
# → DDR 内存分配
# → ZeusCore 指令生成（parse_ir + lowering）
# → 指令编码（MachineInstr → 16字节二进制）
# → 输出生成（inst_file.bin + weight_data.bin + net_config.json）
```

**关键设计模式**：

- **Pass + ContextManager**：每个 Pass 是一个独立的编译步骤，从 ContextManager（一个全局字典）里读数据、处理、写回。Pass 之间解耦。
- **Registry 装饰器**：`@PassRegistry.register_module()` 自动注册 Pass，支持按名字查找。

---

## 3.4 关键文件地图

| 文件/目录 | 干什么 | 什么时候看 |
|---|---|---|
| `docs/assembler_v2_learning_guide.md` | 898 行学习指南，全项目最重要的文档 | **D1 第一个看** |
| `api/build.py` | 编译入口，Network 类 | D5 追 pipeline |
| `cfg/default.py` | 硬件配置（core_type=935） | D1 |
| `dialect/zeus_inst/dicts/opcodes_dict.py` | 所有 opcode 定义 | D2 |
| `dialect/zeus_inst/dicts/insts_dict.py` | 所有指令字段定义 | D2 |
| `dialect/zeus_inst/op.py` | MachineInstr 类层次 | D2 |
| `dialect/zeus_layer/op.py` | ZeusLayer 类层次（Conv2d/Bmm/VPSelf...） | D5 |
| `transforms/fsir2nnlayer.py` | FSIR → NNLayer | D5 |
| `transforms/nnlayer2zeuslayer.py` | NNLayer → ZeusLayer | D5 |
| `target/zeus/core.py` | ZeusCore：指令生成 + WL1/L2 管理（3000+ 行，核心文件） | D3-D5 |
| `memory/ddr.py` | DRAM 分配策略 | D4 |
| `memory/l2.py` | L2 ring buffer 管理 | D4 |
| `tools/run.py` | CLI 入口 | 需要跑时看 |
| `tools/decoder.py` / `tools/encoder.py` | 指令反汇编/汇编工具 | D3 看产物时 |

---

# Part 4 · Transformer / LLM 在这颗芯片上怎么跑

> 你的新任务是大模型落地（Qwen/Llama），所以你需要知道 Transformer 的每个算子在这颗芯片上对应什么。

---

## 4.1 Transformer Block 算子 → 硬件映射

一个标准的 Transformer block（Llama/Qwen 都是这个结构）：

```
Input
  │
  ├─► LayerNorm ──────────────────────────► VP (VP_SELF)
  │
  ├─► Q = Linear(x)  ─────────────────────► PE (FC 指令)
  ├─► K = Linear(x)  ─────────────────────► PE (FC 指令)
  ├─► V = Linear(x)  ─────────────────────► PE (FC 指令)
  │
  ├─► Attention Score = Q × K^T ───────────► PE (Bmm 指令)
  ├─► Softmax(Score) ──────────────────────► VP (VP_SELF)
  ├─► Attention Out = Score × V ───────────► PE (Bmm 指令)
  │
  ├─► Output Projection = Linear(AttnOut) ─► PE (FC 指令)
  ├─► Residual Add ────────────────────────► VP (VP_SELF, element-wise)
  │
  ├─► LayerNorm ──────────────────────────► VP (VP_SELF)
  │
  ├─► FFN Up = Linear(x) ─────────────────► PE (FC 指令)
  ├─► GELU / SiLU 激活 ───────────────────► VP (VP_SELF)
  ├─► FFN Down = Linear(x) ───────────────► PE (FC 指令)
  ├─► Residual Add ────────────────────────► VP (VP_SELF)
  │
  Output
```

**总结**：
- **MatMul / Linear / Attention**（计算密集）→ **PE** 单元
- **Softmax / LayerNorm / GELU / Add**（元素级）→ **VP** 单元
- **数据搬运**（权重/KV-cache 来回搬）→ **LD/LW/ST** 单元
- **核间同步**（多核推理时）→ **SI/SO** 单元

## 4.2 大模型推理的瓶颈在哪

LLM 推理分两个阶段：

### Prefill 阶段（处理 prompt）
- 一次性处理所有 input token
- **计算密集**（大矩阵 × 大矩阵）
- 瓶颈在 **PE 算力**（512 GOPS 能不能撑住）

### Decode 阶段（逐 token 生成）
- 每次只生成 1 个 token
- **访存密集**（每个 token 都要读全部 KV-cache + 全部权重，但只做 1 行 × 矩阵的小计算）
- 瓶颈在 **DRAM 带宽**（权重 7GB，每生成一个 token 都要读一遍）

**在你们芯片上**：
- Prefill：PE Array 是主角，L2 带宽 32 GB/s 可能够用
- Decode：LD/LW 搬运是瓶颈，WL1 只有 18.5KB 要反复搬权重，DRAM 带宽可能是整个系统的天花板

**KV-cache 存哪里**：
- 太大了放不进 L2（1MB），只能放 DRAM
- 每次 Attention 计算要从 DRAM 搬 KV-cache 到 L2，再搬进 AL1
- 这就是为什么 KV-cache 管理（压缩/量化/裁剪）对你们芯片至关重要

> 深入阅读：
> - [arXiv 2410.04466: LLM Inference Acceleration — Hardware Perspective](https://arxiv.org/abs/2410.04466)
> - [arXiv 2412.19442: KV Cache Management Survey](https://arxiv.org/abs/2412.19442)
> - [知乎：大语言模型推理优化技术综述](https://zhuanlan.zhihu.com/p/1911021800206365462)

---

# Part 5 · 一周学习计划

> 以下是具体的每日任务。Part 1-4 本身就是你的核心学习资料，每天的任务是"精读 + 验证 + 画图"。

| 天 | 主题 | 具体任务 | 产出 |
|---|---|---|---|
| **D1** | 硬件大图 | 精读本文档 Part 1 + Part 2；精读 `assembler_v2_learning_guide.md` 前 300 行；在纸上画 2.1 的单核架构图 | 手画架构图 v1 |
| **D2** | 指令集 | 精读本文档 Part 2.2 指令表；打开 `opcodes_dict.py` + `insts_dict.py` 对照看；在架构图上标注每个单元的指令 | 架构图 v2（带指令标注） |
| **D3** | 跑 + 看产物 | 跑一次 pipeline_demo；用 `xxd inst_file.bin \| head -50` 看二进制；找 `tools/decoder.py` 反汇编；挑 3 条指令讲出"在哪个单元上、做什么" | 3 条指令的逐字段解读 |
| **D4** | 内存深挖 | 精读本文档 Part 1.3 + Part 2.3；读 `memory/ddr.py` + `memory/l2.py` + `core.py` 里 WL1 相关代码；画数据搬运时序图 | 数据搬运时序图 |
| **D5** | 5 层 IR | 精读本文档 Part 3；选 Conv_1 追一遍 5 层 lowering（用 pipeline_demo 的 fsir.json 作为输入）；精读 `assembler_v2_learning_guide.md` 剩余部分 | 5 层 lowering 追踪笔记 |
| **D6** | LLM 映射 | 精读本文档 Part 4；列出 Llama 的全部算子并映射到硬件单元；思考 KV-cache 瓶颈 | Transformer→硬件映射表 |
| **D7** | 整合输出 | 画终版架构图（draw.io 或纸笔）；写 1 页小结回答 4 个核心问题（见下）；列"我还不理解的问题"清单 | 终版架构图 + 问题清单 |

### D7 要回答的 4 个核心问题

1. 一条 CONV 指令从编译到执行经过了哪些步骤？（5 层 IR → 16 字节二进制 → PE 执行）
2. WL1 只有 18.5KB，大模型 7GB 权重怎么跑？（tiling + double buffering）
3. Attention 的 Q×K^T 在 PE Array 上怎么 tile？（切成小矩阵块，逐块 Bmm）
4. 多核跑一个模型时 SI/SO 在做什么？（核 A 算完 layer1 通知核 B 可以开始 layer2）

---

# Part 6 · 补充资料索引

> 只有你想深入某个点时才看。本文档已经覆盖了所有必要知识。

| 主题 | 资料 | 链接 |
|---|---|---|
| 脉动阵列原理 | 知乎：脉动阵列 - 计算机体系结构 | [知乎](https://zhuanlan.zhihu.com/p/650209037) |
| 脉动阵列原理 | 知乎：Systolic Architectures | [知乎](https://zhuanlan.zhihu.com/p/605590757) |
| 脉动阵列原理 | 博客园：Systolic Array 加速矩阵乘 | [博客园](https://www.cnblogs.com/kongchung/p/13227256.html) |
| NPU 架构总览 | MLSys Book: Hardware Acceleration | [mlsysbook.ai](https://mlsysbook.ai/contents/core/hw_acceleration/hw_acceleration.html) |
| LLM 硬件加速 | LLM Inference Acceleration (2024 Survey) | [arXiv 2410.04466](https://arxiv.org/abs/2410.04466) |
| LLM 硬件加速 | Hardware Accelerators for LLMs (2024) | [arXiv 2401.09890](https://arxiv.org/abs/2401.09890) |
| KV-Cache 优化 | KV Cache Management Survey (2024) | [arXiv 2412.19442](https://arxiv.org/abs/2412.19442) |
| LLM 推理优化 | 知乎：大语言模型推理优化技术综述 | [知乎](https://zhuanlan.zhihu.com/p/1911021800206365462) |
| LLM 推理优化 | 知乎：万字长文 LLM 推理优化总结 | [知乎](https://zhuanlan.zhihu.com/p/1919407528363668517) |
| 高效 AI 计算 | MIT 6.5940 (Song Han, Fall 2024) | [hanlab.mit.edu](https://hanlab.mit.edu/courses/2024-fall-65940) |
| Roofline 模型 | 知乎：Roofline Model 与 DL 性能分析 | [知乎](https://zhuanlan.zhihu.com/p/34204282) |
| Assembler 内部 | assembler_v2_learning_guide.md | [项目内文件](assembler/docs/assembler_v2_learning_guide.md) |
| Transformer 推理 | Apple: Deploying Transformers on NPU | [apple.com](https://machinelearning.apple.com/research/neural-engine-transformers) |
