# 用大白话讲解 Assembler V2 学习指南

---

## 第一章：为什么需要这个项目？

### 1.1 从一个问题开始

你训练好了一个神经网络模型（比如 YOLOv5，一种常见的目标检测模型，可以识别图片里的猫、狗、汽车等物体），现在你想让它跑在一颗**专用 AI 芯片（NPU，Neural Processing Unit，就是专门为跑神经网络而设计的芯片，相比通用 CPU 更省电、更快）**上。这时候问题就来了：

- 你用 PyTorch（一种流行的 AI 训练框架，用 Python 写代码）描述的模型，本质上是一堆"先做什么运算、再做什么运算"的高层指令，机器能看懂，但那颗 NPU 芯片不认识。
- NPU 芯片内部只认识自己专用的**二进制指令**（就是一串 0 和 1 组成的机器码，硬件直接执行的最底层命令）。

**谁来做这个翻译工作呢？** 答案就是本项目：**Assembler V2**（汇编器第二版，汇编器就是把人类能理解的指令翻译成机器能执行的二进制的工具）。

打个比方，这个翻译关系就像：

```
你写的中文文章  →  翻译官  →  英文文章
PyTorch 模型   →  本项目   →  NPU 二进制指令
```

### 1.2 和传统编译器的类比

如果你学过 C 语言，你知道 `gcc`（GNU 编译器集合，最常见的 C 语言编译工具）帮你做了这些事：

```
C 源代码  →  预处理  →  编译  →  汇编  →  链接  →  可执行文件
```

本项目做的事情非常类似，只是处理的对象不同：

```
神经网络 IR  →  预处理  →  图变换  →  指令生成  →  内存分配  →  二进制文件
```

下面这张表把两者一一对照起来：

| 传统编译器 gcc 里的概念                                     | 本项目里对应的概念                                           |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| C 源代码（你写的代码文本）                                  | 神经网络前端 IR（FSIR，一种描述网络结构的 JSON 格式文件）    |
| 语法树（AST，编译器把源代码解析成树状结构，方便分析）       | 网络计算图（NNGraph，把神经网络每一层及其连接关系组织成图）  |
| 中间表示（LLVM IR，一种介于高级语言和机器码之间的通用格式） | Zeus 硬件层（ZeusLayer，已经和具体芯片硬件绑定的中间表示）   |
| 汇编指令（比 C 更底层、但还没有变成二进制的指令）           | 抽象指令（ABSNode，Abstract Node，接近硬件但还没编码成二进制的指令描述） |
| 机器码（最终可以被 CPU 直接执行的二进制）                   | 机器指令（MachineInstr，最终可以被 NPU 直接执行的指令）      |
| 可执行文件（.exe，直接双击就能跑的文件）                    | 二进制指令文件 + net_config.json（NPU 运行时需要的所有文件） |

---

## 第二章：核心概念入门

在深入代码之前，先把几个关键概念讲清楚。

### 2.1 什么是 IR（中间表示）？

**IR = Intermediate Representation，中间表示**，可以理解成"编译器内部用来传递信息的一种格式"。

想象你要把中文翻译成日文，但你不会日文。你可以这样绕一下：

```
中文  →  英文（中间语言）  →  日文
```

英文就充当了"中间表示"的角色。IR 的好处是：

- 把一个复杂的大问题拆成多个简单的小步骤；
- 每个步骤只负责一件事，做完交给下一步。

本项目一共有 **5 层 IR**，每一层都比上一层更接近硬件，更具体：

**第 1 层：FSIR（Frontend Schedule IR，前端调度中间表示）**
这是最高层，描述的是"做什么"，比如"用 Conv2d（二维卷积，一种常见的图像处理运算，让滤波器在图像上滑动做乘加）对一张 224×224 的图像做 3×3 的卷积"。这一层完全不关心硬件。

**第 2 层：NNLayer / NNGraph（神经网络层 / 神经网络图）**
把 FSIR 变成结构化的"层"对象，每一层知道自己的输入 Tensor 形状是什么（比如 [1,3,224,224] 表示 1 张图、3 个颜色通道、高 224、宽 224）、权重形状是什么、输出形状是什么。

**第 3 层：ZeusLayer / ZeusGraph（Zeus 层 / Zeus 图，Zeus 是本项目目标芯片的架构代号）**
这一层已经和具体硬件相关了。它知道这个运算要用芯片上的哪个计算单元（比如 PE 单元）来执行，数据要从 DRAM（大内存）的哪个地址加载进来。

**第 4 层：ABSNode（Abstract Node，抽象指令节点）**
已经接近具体指令了，比如"先把数据 Load（加载）到 L2 缓存，再执行卷积计算，再把结果 Store（存回）DRAM"，但还没有生成具体的二进制编码。

**第 5 层：MachineInstr（Machine Instruction，机器指令）**
最底层，每条指令都有具体的操作码（opcode，指令的编号，告诉硬件"这是哪种操作"）和操作数（operand，指令的参数，比如地址、大小）。这一层可以直接编码成二进制。

**为什么不一步到位，直接从模型变成二进制呢？** 因为每一层可以独立做优化。就像工厂流水线，每个工位只负责自己那道工序，互不干扰，也更容易排查问题。

### 2.2 什么是 Pass（编译遍）？

**Pass（编译遍）= 对 IR 进行一次变换或分析的操作**。"遍"就是"走一遍"的意思，每个 Pass 都对整个 IR 从头到尾处理一次。

把编译器想象成一条工厂流水线：

```
原材料  →  [切割工位]  →  [打磨工位]  →  [喷漆工位]  →  [质检工位]  →  成品
  IR     →  [优化Pass]  →  [转换Pass]  →  [分配Pass]  →  [验证Pass]  →  输出
```

每个 Pass 的特点：
- **输入**：某种 IR 数据；
- **输出**：修改后的 IR，或者转换成新格式的 IR；
- **职责单一**：每个 Pass 只干一件事，干完就交给下一个 Pass。

本项目里有这些 Pass（举几个例子）：

- `FSIROptimizePass`：删除 FSIR 里不需要的 shape（形状变换）操作，比如多余的 Reshape（重塑张量形状但不改变数据的操作）；
- `FSIR2NNGraphPass`：把 FSIR 字典（JSON 格式的数据）转换成 NNGraph（网络图对象）；
- `NNGraph2ZeusGraphPass`：把 NNGraph 转换成跟硬件绑定的 ZeusGraph；
- `ZeusData2DRAMTensor`：给每个 Tensor（张量，也就是多维数组，存放数据的基本单元）分配一个 DRAM 内存地址。

### 2.3 什么是 NPU 以及它为什么特殊？

**NPU = Neural Processing Unit，神经网络处理单元**，是专门为神经网络计算设计的芯片。

跟我们熟悉的 CPU（通用处理器，电脑的"大脑"）和 GPU（图形处理器，原本用来渲染游戏画面，现在也大量用于 AI）相比，NPU 的特点如下：

- **CPU**：啥都能干，但同时处理的任务数量有限（通常几个到几十个核心）；
- **GPU**：有几千个小核心，特别擅长同时处理大量相同类型的计算，但需要 CUDA 或 OpenCL 这类专用编程接口来控制；
- **NPU**：专门为矩阵乘法（matrix multiplication）和卷积（convolution）这类神经网络运算定制，效率极高，但必须用专用编译器（也就是本项目）来控制。

本项目针对的硬件叫做 **Zeus 架构**（Zeus 是希腊神话里的主神，这里是芯片架构的代号）。它内部的关键组件如下：

芯片里有多个 **Core（核心，独立的计算单元，类似 CPU 的多核）**，每个 Core 里面包含：

- **PE（Processing Element，处理单元）**：专门执行卷积、矩阵乘法这类核心计算；
- **VP（Vector Processor，向量处理器）**：执行激活函数（activation function，比如 ReLU 把负数变成 0 的操作）、池化（pooling，对特征图做降采样的操作）等逐元素操作；
- **DT（Data Transfer，数据搬移单元）**：负责在片上不同内存之间搬运数据、做格式转换；
- **CT（Control，控制单元）**：负责控制流，配置计算上下文（context，就是计算时的各种参数和状态）；
- **LD（Load，加载）**：从 DRAM（外部大内存）把数据加载到 L2 缓存；
- **LW（Load Weight，加载权重）**：从 DRAM 把模型权重（weight，神经网络里经过训练得到的参数）加载到 L2；
- **ST（Store，存储）**：把计算结果从 L2 写回 DRAM；
- **SI（Sync In，同步接收）**：核间同步用的，表示"等待其他核发来信号"；
- **SO（Sync Out，同步发出）**：核间同步用的，表示"向其他核发出信号"。

### 2.4 三级存储层级

NPU 的内存分三层，速度越快、容量越小：

**WL1（Working Level 1，一级工作存储）**：只有 18.5KB，极快但极小，就像你把东西握在手里，随时能用，但手只能拿这么多。

**L2（Level 2 Cache，二级缓存）**：大约 1MB，速度快、容量适中，就像你桌子上的东西，要用的时候直接拿。

**DRAM（Dynamic Random Access Memory，动态随机存取内存，也就是外部大内存）**：几百 MB 到几 GB，容量很大但速度相对慢，就像仓库，东西多但取的时候要跑一趟。

**编译器最重要的职责之一**，就是合理安排数据在这三层之间的搬运，让计算单元不会因为"等数据还没到"而白白空转浪费时间。

---

## 第三章：整体编译流程

### 3.1 全景图

从输入到输出，整个编译过程分为 **8 个阶段**，我们一个个来看：

**输入文件有三类：**
- `FSIR.json`（网络结构文件，用 JSON 格式描述神经网络每一层的运算）；
- `STSIR.json`（Spatial-Temporal Schedule IR，时空调度中间表示，描述多核之间怎么分工的信息）；
- 权重文件（`.npy` 格式，NumPy 数组格式，存放模型训练好的参数）。

**阶段 1：输入解析**
把上面三类文件读进来，创建对应的 Python 对象，注册到 ContextManager（上下文管理器，类似一个公告板，所有 Pass 都从它这里存取数据，后面会详细解释）。

**阶段 2：前端 IR 预处理**
做三件事：
- 删掉 FSIR 里多余的形状变换算子（比如 Reshape、Split、Concat，这些在某些情况下可以省略）；
- 把调度信息（哪些层分给哪个核）同步进 FSIR；
- 提取 BN（Batch Normalization，批归一化，一种让训练更稳定的技术，把数据的分布规范化）的参数，融合到相邻的卷积层里（这样推理时少做一步运算）。

**阶段 3：构建 NNGraph**
把 FSIR 的字典结构，转换成真正的图（graph）数据结构——NNGraph。图里每个节点（node）是一个网络层，边（edge）表示数据从哪一层流向哪一层。

**阶段 4：Lowering 到 ZeusGraph**
"Lowering"（下沉）意思就是把高层表示转换成更低层、更贴近硬件的表示。这一步把每个 NNLayer 绑定到具体的硬件单元：
- Conv2d 层 → 分配给 PE 单元计算；
- ReLU（整流线性单元，一种激活函数，输出 max(0,x)）层 → 分配给 VP 单元计算。

**阶段 5：DRAM 内存分配**
给每个 Tensor 分配一个 DRAM 地址（就像给每个快递包裹分配一个仓库货位）。同时分析每个 Tensor 的"生命周期"（从什么时候开始需要，到什么时候不再需要），对已经用完的 Tensor 所占的内存进行复用（类似垃圾回收）。

**阶段 6：指令生成**
对每个 Task（任务，一次推理过程中的一个调度单元）的每个 Core，把调度 IR 转换成抽象指令（ABSNode）的 DAG（有向无环图，Directed Acyclic Graph，一种表示依赖关系的图，后面会详细解释），再把抽象指令变成机器指令（MachineInstr）的 DAG，加上核间同步指令（SI/SO），最后做拓扑排序（topological sort，把 DAG 里有依赖关系的节点排成先后顺序）变成线性序列。

**阶段 7：指令编码**
把机器指令编码成二进制。每条指令固定 16 字节，生成 `.bin` 文件。

**阶段 8：输出生成**
生成最终的几个文件：
- `inst_file.bin`（指令二进制文件）；
- `weight_data.bin`（权重二进制文件）；
- `fixed_data.bin`（固定数据文件，比如量化参数）；
- `net_config.json`（网络配置文件，描述整体运行配置）；
- `rela.json`（重定位信息，relocation，用于运行时修正地址）。

### 3.2 一个具体例子

假设有一个极简的网络：`输入 → Conv2d（卷积层） → ReLU（激活层） → 输出`

**阶段 1 的 FSIR 长这样**（简化版 JSON）：
```json
{
  "conv1": {
    "operation": "Conv2d",
    "input_shape": [[1, 3, 224, 224]],
    "output_shape": [[1, 64, 112, 112]],
    "previous_layer": ["input"],
    "next_layer": ["relu1"]
  },
  "relu1": {
    "operation": "Relu",
    "input_shape": [[1, 64, 112, 112]],
    "output_shape": [[1, 64, 112, 112]],
    "previous_layer": ["conv1"],
    "next_layer": ["output"]
  }
}
```
就是一个 JSON 字典，说明了两个层的运算类型、形状、前后关系。

**阶段 3 变成 NNGraph 之后**，就是这样一张图：
```
[输入节点] → [Conv2d 层，知道自己的输入/权重/输出形状，步长等参数] → [ReLU 层] → [输出节点]
```

**阶段 4 变成 ZeusGraph 之后**，跟硬件绑定了：
```
[输入节点] → [PE 单元执行 Conv2d] → [VP 单元执行 ReLU] → [输出节点]
```

**阶段 6 生成的指令序列**（简化）：
```
CT_START        ← 任务开始（控制指令）
LD  addr=0x0000 ← 从 DRAM 地址 0x0000 加载输入数据到 L2
LW  addr=0x8000 ← 从 DRAM 地址 0x8000 加载卷积权重到 L2
PE  mode=conv   ← PE 单元执行卷积
VP  mode=relu   ← VP 单元执行 ReLU 激活
ST  addr=0x4000 ← 把结果存回 DRAM 地址 0x4000
CT_END          ← 任务结束
```

---

## 第四章：代码结构详解

### 4.1 目录结构总览

整个项目的代码放在 `assembler_v2/assembler/` 目录下，分成以下几个文件夹：

**`api/`（Application Programming Interface，对外接口）**：这是整个编译器的入口，`build.py` 里的 `Network` 类就是"总指挥"，你调用它就启动了整个编译流程。

**`dialect/`（方言，这里指"各种 IR 和数据结构的定义"）**：存放各种数据结构的定义，按层次分成多个子目录：
- `input_ir/`：输入 IR 的定义（FSIR、STSIR）；
- `nn_layer/`：神经网络层抽象（NNLayer、Tensor）；
- `zeus_layer/`：硬件层抽象（ZeusLayer）；
- `abs_inst/`：抽象指令（ABSNode）；
- `zeus_inst/`：机器指令 + 二进制编码器；
- `multi_kernel/`：多核场景下的 Tensor 抽象；
- `nn_mem/`：神经网络层的内存抽象；
- `zeus_mem/`：Zeus 层的内存抽象；
- `qiming_base/`（启明，可能是项目内部代号）：VP 模块的基础定义。

**`transforms/`（变换）**：存放所有的 Pass，也就是 IR 转换的具体逻辑。

**`target/`（目标硬件）**：针对具体硬件（Zeus 架构）的指令生成逻辑，`zeus/core.py` 里的 `ZeusCore` 类负责把抽象指令变成机器指令。

**`memory/`（内存）**：内存管理逻辑，`ddr.py` 管 DRAM，`l2.py` 管 L2 缓存。

**`printer/`（打印器，这里是"输出生成器"）**：生成最终输出文件的逻辑，`asm_printer.py` 生成二进制和配置文件，`dag_printer.py` 可以把计算图可视化输出。

**`support/`（支撑框架）**：编译器的基础设施：
- `passes/`：Pass 的基类（base class，所有 Pass 都要继承它）；
- `registry/`：Pass 注册表（用来通过名字查找和创建 Pass）；
- `context/`：ContextManager，数据传递系统。

**`utils/`（工具）**：各种工具函数，比如数据格式转换、日志记录、文件读写等。

### 4.2 核心模块关系图

简单来说就是：`api/build.py` 是总指挥，它调用 `transforms/`（各种变换 Pass）、`target/`（指令生成）和 `printer/`（输出）三个模块。这三个模块都在读写 `dialect/` 里定义的数据结构。而它们都依赖 `support/`（框架）、`memory/`（内存管理）和 `utils/`（工具函数）提供的基础能力。

---

## 第五章：关键设计模式

### 5.1 Pass + ContextManager 模式

这是整个项目最核心的设计思路，理解了它就理解了这个项目的骨架。

**问题**：编译过程有几十个步骤，每个步骤需要读取前一步的结果，并产出新的结果。如果直接把所有数据用全局变量（global variable，整个程序都能访问的变量）传来传去，代码会一团乱麻。

**解决方案是**：用一个 `ContextManager`（上下文管理器）充当"公告板"。每个 Pass 把自己的处理结果贴到公告板上，下一个 Pass 从公告板上取它需要的数据。大家通过公告板交流，互相之间不直接调用，就解耦（decoupling，让模块之间减少直接依赖，更独立）了。

```python
# 1. ContextManager 就是一个"公告板"
ctx_man = ContextManager()
ctx_man.graph_ir = Context(fsir_data)  # 把 FSIR 数据贴上去

# 2. 每个 Pass 是一个独立的"工位"
class FSIR2NNGraphPass(FunctionPass):
    def run_pass(self, ctx_man):
        # 从公告板读取 FSIR
        fsir = ctx_man.graph_ir.get(self)
        # 做转换
        nn_graph = self.convert(fsir)
        # 把结果贴回公告板
        ctx_man.nn_graph = Context(nn_graph, gen_by=self)
        return ctx_man
```

这样设计的好处：
- **解耦**：每个 Pass 只关心"我需要什么"和"我产出什么"，不关心其他 Pass 怎么写；
- **可追溯**：Context（上下文对象）记录了每份数据是哪个 Pass 生成的、被哪个 Pass 用过；
- **易扩展**：加一个新 Pass 不需要改其他任何 Pass 的代码。

### 5.2 注册表模式（Registry Pattern）

**问题**：神经网络有几十种算子（operator，就是 Conv2d、ReLU、Pool 这类运算），处理每种算子的逻辑都不一样。如果用一大堆 `if op == "Conv2d": ... elif op == "ReLU": ...` 来写，代码会越来越长、越来越难维护。

**解决方案**：用装饰器（decorator，Python 里一种给函数/类附加额外功能的语法糖，用 `@` 符号标记）自动注册。每个 Pass 在定义的时候自动把自己登记到一个"注册表"里，需要用的时候通过名字查找：

```python
# 定义时自动注册
@PassRegistry.register_module(must_success=True)
class MyNewPass(FunctionPass):
    def run_pass(self, ctx_man):
        ...

# 使用时通过名字查找并创建
pass_instance = PassRegistry.build({"type": "MyNewPass"})
```

这样增加新 Pass 只需要加一个新类，不需要修改任何已有代码。

### 5.3 多层抽象模式（Lowering）

**"Lowering"（下沉/降低）** 就是把高层的、抽象的表示，一步步转换成低层的、具体的表示：

```
"做卷积"  →  "PE单元做卷积"  →  "LD+LW+PE+ST指令序列"  →  二进制 0101...
 （最抽象）      （硬件相关）        （指令级别）           （最具体）
```

每层只做一步降低，每步都简单可控。就像搬家：你不会一口气从第十层扛到楼下，而是先搬到楼道，再搬到电梯，再搬出门。

### 5.4 DAG（有向无环图）模式

指令之间有依赖关系。比如：必须先把数据 Load（加载）进来，才能做计算；必须先计算完，才能 Store（存储）结果。

用 DAG（Directed Acyclic Graph，有向无环图，每条边有方向，并且从任何节点出发都不会回到自身的图）来表示这些依赖关系：

```
       LD（加载输入）     LW（加载权重）
            \               /
             \             /
           PE（执行卷积）
                  |
           VP（执行 ReLU）
                  |
           ST（存储结果）
```

DAG 的好处：
- **自动确定执行顺序**：对 DAG 做拓扑排序，就能得到一个合法的指令执行序列；
- **发现并行机会**：如果两条指令之间没有依赖关系（比如上图中 LD 和 LW 互相独立），硬件可以同时执行它们；
- **正确性保证**：DAG 里不会出现"先用结果，后做计算"这种错误。

代码里用的是 NetworkX（一个 Python 图计算库）的 `nx.DiGraph`（有向图）来实现 DAG。

---

## 第六章：关键数据结构

### 6.1 Tensor（张量）

**Tensor（张量）** 就是多维数组，是神经网络里存放数据的基本单元。一张彩色图片可以用 [高, 宽, 3] 的张量表示（3 表示 RGB 三个颜色通道）。

同一份数据，在不同编译阶段有不同的"身份描述"：

- 在 **NNLayer 阶段**：叫 `Tensor`，记录名字、形状（shape）、数据类型（dtype，比如 int8 或 float32）、来自哪个文件；
- 在 **ZeusLayer 阶段**：叫 `ZeusFmp`（Feature Map，特征图，卷积层的输出），记录编号、形状、数据类型；
- 在 **DRAM 分配阶段**：叫 `DRAMTensor`，记录内存地址（addr）、占多少字节（size）、内存步长（stride，相邻数据之间的字节间距）、生命周期（lifetime，这份数据从第几步开始需要、到第几步结束）；
- 在 **L2 分配阶段**：叫 `L2IFMapTensor`（IFMap = Input Feature Map，输入特征图），记录 L2 内的地址、边界、偏移量；
- 在 **多核阶段**：叫 `NetworkTensor`，记录 DDR 编号、所属的核组名、偏移量。

用包裹物流来类比：同一个商品，在仓库里叫"库存单元"（有货位号），在快递途中叫"快递件"（有运单号），到了你手里叫"商品"（有商品名）。不同阶段叫法不同，但本质是同一个东西。

### 6.2 Layer（层）

Layer 同样分阶段演化：

**NNLayer 阶段**：描述"做什么计算"，比如 Conv2d 知道自己的输入形状、权重形状、输出形状、卷积核大小、步长（stride，卷积核每次滑动的像素数）等。

**ZeusLayer 阶段**：描述"怎么在硬件上做"，比如 Conv2d 知道自己用 PE 单元计算，输入特征图对应哪个 ZeusFmp，数据搬运的映射关系（Place_Triple，描述数据从哪搬到哪的三元组）是什么。

对应的代码：
- `assembler/dialect/nn_layer/op.py`（约 1000 行，定义了 50 多种算子）；
- `assembler/dialect/zeus_layer/op.py`（约 1800 行，硬件层的算子定义）。

### 6.3 MachineInstr（机器指令）

最底层的指令，每条都有：
- `unit`：执行单元（比如 "PE"）；
- `src`：源操作数（source operand，指令的输入，比如数据从哪来）；
- `dst`：目标操作数（destination operand，指令的输出，比如结果写到哪）；
- `instrs`：编码字段（具体要写入的二进制字段列表，比如 PE_FM 描述特征图配置，PE_PM 描述参数配置）。

指令按照执行单元分成几大类：
- **LD / LW**：加载指令（从 DRAM 读数据到 L2）；
- **ST**：存储指令（从 L2 写数据回 DRAM）；
- **PEInstr**：PE 计算指令，细分为 PEConv（普通卷积）、PEDicv（深度可分离卷积，Depthwise Convolution，一种轻量化卷积方式）、PEFc（全连接，Fully Connected，每个输入都和每个输出连接的层）；
- **VPInstr**：VP 向量指令，细分为 VPPool（池化）、VPSelf（逐元素运算，如 ReLU）；
- **CTInstr**：控制指令，表示任务开始/结束；
- **SIInstr / SOInstr**：核间同步指令；
- **DTCopy**：片上数据搬移指令。

---

## 第七章：内存管理

内存管理是编译器里最复杂的部分之一，因为内存有限，必须精打细算。

### 7.1 DDR 内存分区

DDR（DRAM，外部大内存）被分成三个区域，各司其职：

**Fixed 区（固定数据区）**：放量化参数（quantization parameters，比如 scale 和 zero_point，把浮点数映射到整数的参数）、BN 参数等在推理过程中永远不变的数据。地址最低，一旦放进去就不动了。

**Weight 区（权重区）**：放模型的卷积核权重、全连接权重等参数。这些在推理时也不变，一次加载好，之后每次推理都复用。

**Feature Map 区（特征图区）**：放中间计算结果（每一层的输出）。这些数据是临时的，用完了就可以腾地方。地址最高，是动态分配的。

**为什么要分区？** 因为权重和固定数据的生命周期是整个推理过程，而特征图的生命周期只有几层，分区之后可以对特征图区单独做内存复用优化，节省大量内存。

### 7.2 Feature Map 内存复用

这是一个节省内存的重要优化技巧：

```
时间轴 →

Layer 1 在使用：  [████████ Tensor A]
Layer 2 在使用：        [████████ Tensor B]
Layer 3 在使用：              [████████ Tensor C]
                                ↑
                        此时 Tensor A 已经不再需要了！
                        所以 Tensor C 可以占用 A 的那块内存
```

如果 Tensor A 在 Layer 2 结束后就不再需要，那 Layer 3 新产生的 Tensor C 就可以直接复用 A 占用的那块内存，不需要额外申请。这就是"生命周期分析"（lifetime analysis）的价值。

### 7.3 符号表（Symbol Table）

DDR 类维护了一个符号表（symbol table，就像一个字典，把名字映射到内存信息），类似于操作系统里文件系统的目录：

```python
symtab = {
    "@DDR.input_0":    DRAMInputNode(...),   # 网络输入数据的地址
    "@DDR.conv1_out":  DRAMFMapTensor(...),  # conv1 层输出的特征图
    "@DDR.conv1_wgt":  DRAMWeightTensor(...),# conv1 的卷积权重
    "@DDR.output_0":   DRAMOutputNode(...),  # 网络最终输出的地址
}
```

每个符号条目里包含地址、大小、数据类型、生命周期等完整信息，指令生成时就从这里查到具体地址。

---

## 第八章：多核编译

### 8.1 为什么需要多核？

单个核心的计算能力有限，把一个大网络拆分到多个核上并行执行，可以提升整体吞吐量（throughput，单位时间内能处理的数据量）。

有两种主要的并行方式：

**按层拆分**：Core 0 跑前几层，Core 1 等 Core 0 算完再跑后几层。这样像流水线，但 Core 1 有一段等待时间。

**按数据拆分**：把同一层的输入特征图切成两半，Core 0 处理上半，Core 1 处理下半，两个核同时工作。这种效率更高，但需要在边界处做额外处理（因为卷积会跨越边界）。

### 8.2 核间同步

当 Core 0 的计算结果需要传递给 Core 1 时，必须做同步，确保 Core 1 不会在数据还没准备好的时候就开始用：

```
Core 0 算完一层后：  执行 SO 指令（Sync Out，发出同步信号）→ "我算完了！"
Core 1 等待时：      执行 SI 指令（Sync In，等待同步信号） → "收到，开始！"
```

这两条指令配对使用，是多核协作的基础机制。

### 8.3 多核编译流程

多核编译的关键中间表示叫 **MKIR（Multi-Kernel IR，多核中间表示）**，它描述了整个网络要怎么拆分到各个核上。

然后每个 Core 对应一个 **Kernel（核函数，分配给单个核的计算任务）**，各自独立编译（生成各自的指令序列）。

最后把所有 Core 的结果合并：统一分配 DDR 内存，生成一份总的 `net_config.json`（网络配置文件，运行时加载用的）。

对应代码在 `assembler/transforms/multi_kernel.py`，是整个项目里最大的一个文件，约 119K 字节。

---

## 第九章：支撑框架

### 9.1 Pass 框架

所有 Pass 都继承自 `BasePass`（基类，定义了所有子类必须实现的接口）：

```python
class BasePass(metaclass=ABCMeta):  # ABCMeta 是 Python 里定义抽象类（不能直接实例化、必须被继承的类）的方式
    @abstractmethod  # 抽象方法，子类必须重写
    def run_pass(self, ctx_man):
        """具体的变换逻辑，子类必须实现"""
        pass
```

`FunctionPass`（函数级 Pass，对整个模块/函数做变换的 Pass 类型）继承 `BasePass`，我们写的大多数 Pass 都继承 `FunctionPass`。

### 9.2 Network 类（总指挥）

`api/build.py` 里的 `Network` 类是整个编译器的对外接口和调度中枢。它在 `__init__`（初始化方法，Python 里创建对象时自动调用的方法）里：

1. 创建 `ContextManager`（公告板）；
2. 解析输入的 FSIR 和 STSIR，挂到公告板上；
3. 按顺序调用所有的 Pass，每个 Pass 从公告板取数据、处理、再把结果贴回公告板。

在 `run()` 方法里：
1. 对每个 Task、每个 Core，调用 `ZeusCore`（Zeus 核编译器）生成指令；
2. 对指令 DAG 做拓扑排序，然后编码成二进制；
3. 调用 `printer`（输出器）生成所有输出文件。

---

## 第十章：如何阅读代码（建议路线）

### 入门路线（从简单到复杂）

**第 1 步：先理解数据结构**
从 `assembler/dialect/nn_layer/data_abstraction.py`（约 100 行，定义了 Tensor 是什么）和 `assembler/dialect/nn_layer/op.py` 的前 100 行（Layer 基类的定义）入手。目标是搞清楚 Tensor 和 Layer 是什么样的 Python 对象。

**第 2 步：理解一个简单的 Pass**
读 `assembler/transforms/fsir2nnlayer.py`（约 200 行，是所有 Pass 里比较简单的一个）和 `assembler/support/passes/base_pass.py`（约 80 行，Pass 基类）。目标是理解一个 Pass 是怎么从 ContextManager 读数据、处理、写回去的。

**第 3 步：理解整体编译主流程**
读 `assembler/api/build.py`，重点看 `Network.__init__` 和 `Network.run`，搞清楚各个 Pass 的执行顺序。

**第 4 步：理解 IR 下沉（Lowering）**
读 `assembler/transforms/nnlayer2zeuslayer.py` 的前 300 行，以及 `assembler/dialect/zeus_layer/op.py` 的前 300 行。目标是理解 NNLayer 是怎么一步步变成 ZeusLayer 的。

**第 5 步：理解指令生成**
读 `assembler/target/zeus/core.py`（重点是 `parse_ir` 和 `lowering` 两个方法）和 `assembler/dialect/zeus_inst/op.py`（各种指令类型的定义）。目标是理解抽象指令怎么变成机器指令。

**第 6 步：理解内存管理**
读 `assembler/memory/ddr.py` 和 `assembler/memory/l2.py`。目标是理解数据怎么在 DRAM、L2、WL1 三层之间调度。

**第 7 步：理解输出生成**
读 `assembler/printer/asm_printer.py`。目标是理解最终输出了哪些文件、格式是什么。

### 调试技巧

1. **看日志**：项目用 `get_logger` 和 `print_log`（日志打印函数）记录了每个 Pass 的执行情况，调整日志级别（log level，控制打印哪些详细程度的日志）可以看到每个 Pass 的输入输出。
2. **看 DAG 可视化**：`dag_printer.py` 可以把计算图导出为可视化格式（比如 Graphviz 的 dot 格式，一种常用的图可视化工具），帮助理解数据流。
3. **看中间文件**：编译过程中会保存 `opt_fsir.json`（优化后的前端 IR）、`net_config.json` 等中间结果文件，可以直接打开来检查某个阶段的输出是否正确。
4. **断点调试**：在 `Network.__init__` 里某个 Pass 之后设置断点（breakpoint，让程序暂停执行的调试工具），然后检查 `ctx_man`（公告板）上当前挂着哪些数据、数据内容是否符合预期。

---

## 附录 A：术语表（通俗解释版）

**汇编器（Assembler）**：把人类能看懂的符号指令翻译成机器能执行的二进制指令的工具。本项目就是一个针对 NPU 的汇编器。

**IR（Intermediate Representation，中间表示）**：编译器内部用来存储和传递程序信息的数据格式，介于高级语言和机器码之间。

**Pass（编译遍）**：编译过程中的一个独立步骤，对 IR 做一次完整的读取、变换、写回操作。

**Lowering（下沉）**：把高层抽象的 IR 转换成更接近硬件、更具体的 IR 的过程。

**DAG（Directed Acyclic Graph，有向无环图）**：一种图结构，每条边有方向，且不存在环（从任何节点出发按边走都回不到自身）。用于表示指令之间的依赖关系。

**Tiling（分块）**：把一个大张量切成多个小块来适应片上内存（因为片上内存很小，大张量放不下，必须切块处理）。

**FSIR（Frontend Schedule IR，前端调度中间表示）**：本项目的最高层 IR，通常以 JSON 格式存储，描述神经网络的层结构和调度信息。

**STSIR（Spatial-Temporal Schedule IR，时空调度中间表示）**：描述多核之间空间（哪层给哪个核）和时间（各核的执行顺序）调度关系的 IR。

**DRAM（Dynamic Random Access Memory，动态随机存取内存）**：容量大但速度相对较慢的外部内存，所有数据最终都存在这里。

**L2（Level 2 Cache，二级缓存）**：速度较快、容量适中的片上缓存，计算时需要的数据先从 DRAM 搬到这里。

**WL1（Working Level 1，一级工作存储）**：速度极快但容量极小（18.5KB）的存储，正在被计算单元处理的数据放在这里。

**PE（Processing Element，处理单元）**：执行卷积、矩阵乘法等核心运算的硬件模块。

**VP（Vector Processor，向量处理器）**：执行激活函数、池化等逐元素操作的硬件模块。

**DT（Data Transfer，数据搬移单元）**：负责在片上不同存储区域之间搬运数据的硬件模块。

**Feature Map（特征图）**：卷积层对输入做运算后输出的多维数组，是神经网络里层与层之间传递的中间结果。

**Workload（工作负载）**：分配给单个核的一次分块计算任务。

**算子融合（Operator Fusion）**：把连续的多个算子（比如 Conv + BN + ReLU）合并成一个，减少中间结果的内存读写次数，提升效率。

**量化（Quantization）**：把模型里的浮点数（如 float32）转换成低精度整数（如 int8），让芯片计算更快、内存占用更小，但精度略有损失。

**拓扑排序（Topological Sort）**：对有向无环图（DAG）中的所有节点排出一个合法的线性顺序，使得每个节点都排在其所有前驱节点之后。

---

## 附录 B：支持的算子列表（通俗版）

**卷积类**：Conv2d（二维卷积，最常用的图像处理运算）、Conv1d（一维卷积，常用于序列数据）、Deconv2d（反卷积，用于上采样）、Deconv1d、Dicv（深度可分离卷积，把普通卷积拆成逐通道卷积和点卷积，参数量更少）、Decv、Gpcv（分组点卷积）、DGpcv（深度分组卷积）。

**线性类**：Dense（全连接层，MLP 的基本单元）、Bmm（Batch Matrix Multiply，批量矩阵乘，同时对多组矩阵做乘法）、MatMul（矩阵乘法，Transformer 的核心运算）。

**激活类**：ReLU、ReLU6（ReLU 的变种，输出截断在 6 以内，适合量化）、Sigmoid（输出 0~1 之间，常用于分类输出）、Tanh（输出 -1~1 之间）、Gelu（常用于 Transformer）、Swish、LeakyReLU（ReLU 的变种，负数部分不归零而是乘以一个小系数）、Abs（取绝对值）、Ceil（向上取整）、Floor（向下取整）、Log（取对数）、Softmax（把一组数转成概率分布，所有输出加起来等于 1）。

**归一化类**：BatchNorm（批归一化，稳定训练过程）、LayerNorm（层归一化，Transformer 常用）。

**池化类**：AvgPool（平均池化，对区域内取平均值）、MaxPool（最大池化，对区域内取最大值）、GlobalAvgPool（全局平均池化，对整个特征图取平均，常用于分类网络最后一层）。

**形状变换类**：Concat（拼接多个张量）、Split（把一个张量拆分成多个）、Reshape（改变张量形状但不改变数据）、Transpose（转置，交换张量的维度顺序）、Gather（按索引取数据）、Scatter（按索引写数据）、Slice（切片，取张量的一部分）、Pad（填充，给张量边缘补零）。

**逐元素类**：Add（加法）、Subtract（减法）、Multiply（乘法）、Divide（除法）、Minimum（取较小值）、Maximum（取较大值）、Power（幂运算）、Sqrt（开平方）、Reciprocal（取倒数）。

**其他**：Upsample（上采样，放大特征图，比如双线性插值）、Resize（缩放，改变特征图的尺寸）。