# Assembler V2

Zeus NPU 神经网络汇编器 —— 将前端模型 IR 和后端调度 IR 编译为 NPU 可执行的二进制指令文件。

```
神经网络 IR  →  预处理  →  图变换  →  指令生成  →  内存分配  →  二进制文件
```

## 项目简介

本项目是 Zeus NPU 编译工具链的后端汇编器，负责：
- 解析前端模型参数（FSIR）和后端核间调度 IR（STSIR）
- 经过多层 IR 变换，逐步降低抽象层级
- 为 Tensor 分配 DRAM 内存，管理三级存储（WL1/L2/DRAM）
- 生成指令二进制文件和重排后的权重数据
- 输出面向 SDK 的 net_config.json 配置文件

## 环境要求

- Python 3.8 / 3.9 / 3.10 / 3.11
- 当前版本：`2.0.1dev1`

## 安装说明

```bash
# 1. 安装依赖
pip install -r requirements.txt

# 2. 以开发模式安装
pip install -e .
```

主要依赖：networkx, numpy, Cython, graphviz, Jinja2, tqdm 等（详见 `requirements.txt`）。

## 使用说明

### 输入输出

**输入**：前端 IR、核间调度 IR 和网络固定参数

**输出**：指令和固定参数的 bin 文件、面向 SDK 的接口文件 net_config、汇编调试文件（输出目录下的 `assem_debug/`）

### 输入目录结构

```
input/
├── {case_name}/
│   ├── activations/                              # 激活数据
│   ├── parameters/                               # 网络权重参数(.npy)
│   ├── {case_name}.json                          # 前端 IR (FSIR)
│   ├── {case_name}_c{core_num}_stschedule.json   # 核间调度 IR (STSIR)
│   └── ...
```

### 输出文件

```
output/
├── inst_file_core{N}.bin     # 各核指令二进制文件（每条指令 16 字节）
├── weight_data.bin           # 模型权重二进制
├── fixed_data.bin            # 固定数据（量化参数、BN参数等）
├── net_config_{name}.json    # SDK 接口配置文件
├── rela.json                 # 重定位信息
└── assem_debug/              # 调试文件
```

### 命令行工具

**单核/多核编译**（`tools/run.py`）：

```bash
python3 tools/run.py \
  -f cfg/default.py \
  -i <input_dir> \
  -o <output_dir> \
  -c <core_num> \
  -l <assemble_instance>
```

```
参数说明：
  -f CFG        配置文件路径，默认 cfg/default.py
  -i INPUT_DIR  输入模型后端路径
  -l INSTANCE   汇编实例名称
  -c CORE_NUM   目标核数
  -o OUTPUT_DIR 输出路径，默认 output/$case_name/
  -a KEY VALUE  附加键值参数
  -v            显示版本号
```

**多核编译**（`tools/run_multi_kernel.py`）：用于多 Kernel 场景的编译。

**端到端多核编译**（`tools/run_multi_kernel_e2e.py`）：端到端多 Kernel 编译流程。

### API 调用

接口文件：`assembler/api/build.py`

**单核编译**：

```python
from assembler.api.build import assemble_build

net_config, status = assemble_build(
    fsir_path="path/to/fsir.json",          # 前端 IR
    sts_ir_path="path/to/stschedule.json",  # 核间调度 IR
    fusion_ir_path="path/to/fusion.json",   # 融合 IR
    params_dir_path="path/to/parameters/",  # 网络参数目录
    out_path="path/to/output/",             # 输出目录
    asm_cfg={},                             # 汇编配置字典
)
```

**多核编译**：

```python
from assembler.api.build import multi_kernel_assemble_build

net_config, status = multi_kernel_assemble_build(
    mk_ir_path="path/to/mk_ir.json",        # 多核 IR
    fsir_sts_dir_path="path/to/kernels/",    # 各 Kernel 的 FSIR/STSIR 目录
    instance_regex="*",                       # 实例匹配规则
    out_path="path/to/output/",              # 输出目录
    asm_cfg={},                              # 汇编配置字典
    build_process_num=-1,                    # 并行编译进程数（-1 为自动）
)
```

## 架构概览

### 编译流程

```
━━ 输入 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  FSIR.json (网络结构)
  STSIR.json (调度信息)
  权重文件 .npy (模型参数)

━━ 阶段 1：输入解析 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  解析 JSON → 创建 FSIR/STSIR 对象 → 注册到 ContextManager

━━ 阶段 2：前端 IR 预处理 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  删除冗余 Shape 算子 / 同步调度信息 / BN 融合

━━ 阶段 3：构建 NNGraph ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  FSIR 字典 → NNLayer 对象 → NNGraph（有向图）

━━ 阶段 4：Lowering 到 ZeusGraph ━━━━━━━━━━━━━━━━━━━━━━━
  NNLayer → ZeusLayer（绑定到 PE/VP/DT 等硬件单元）

━━ 阶段 5：DRAM 内存分配 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Tensor 地址分配 / 权重布局 / 生命周期分析与内存复用

━━ 阶段 6：指令生成 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  调度 IR → 抽象指令 DAG → 机器指令 DAG → 拓扑排序

━━ 阶段 7：指令编码 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  机器指令 → 二进制编码（16 字节/条）

━━ 阶段 8：输出生成 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  inst_file.bin / weight_data.bin / fixed_data.bin
  net_config.json / rela.json
```

### IR 层级

本项目采用 5 层 IR 逐步降低抽象层级，每层可独立做优化：

| 层级 | 表示 | 说明 |
|---|---|---|
| 1 | **FSIR** | 前端 IR，描述网络结构和算子参数 |
| 2 | **NNLayer / NNGraph** | 结构化的层对象和计算图 |
| 3 | **ZeusLayer / ZeusGraph** | 硬件相关层，绑定到具体计算单元 |
| 4 | **ABSNode** | 抽象指令 DAG，描述 Load/Compute/Store 序列 |
| 5 | **MachineInstr** | 机器指令，可直接编码为二进制 |

### 目录结构

```
assembler_v2/
├── assembler/
│   ├── api/                  # 编译入口（Network 类、assemble_build）
│   ├── dialect/              # 各层 IR 的数据结构定义
│   │   ├── input_ir/         #   FSIR、STSIR
│   │   ├── nn_layer/         #   神经网络层抽象
│   │   ├── zeus_layer/       #   硬件层抽象
│   │   ├── abs_inst/         #   抽象指令
│   │   ├── zeus_inst/        #   机器指令 + 编码器
│   │   ├── multi_kernel/     #   多核 Tensor 抽象
│   │   └── qiming_base/      #   VP 模块基础定义
│   ├── transforms/           # 编译 Pass（IR 变换逻辑）
│   │   ├── input_ir_preproc.py   # 前端 IR 预处理
│   │   ├── fsir2nnlayer.py       # FSIR → NNLayer
│   │   ├── nnlayer2zeuslayer.py  # NNLayer → ZeusLayer
│   │   ├── zeusdata2dramtensor.py# 数据 → DRAM Tensor
│   │   ├── zeuslayer_optimize.py # ZeusLayer 图优化
│   │   ├── multi_kernel.py       # 多核编译 Pass
│   │   └── cfg_opt.py            # 配置优化
│   ├── target/zeus/          # 硬件目标（ZeusCore 指令生成）
│   ├── memory/               # 内存管理（DDR、L2）
│   ├── printer/              # 输出生成（二进制、net_config）
│   ├── support/              # 基础框架（Pass、Registry、Context）
│   └── utils/                # 工具函数
├── cfg/                      # 配置文件
├── tools/                    # 命令行工具
├── tests/                    # 测试
└── docs/                     # 文档
```

### 核心设计模式

**Pass + ContextManager**：每个编译步骤是一个独立的 Pass，通过 ContextManager 传递中间数据，Pass 之间解耦。

```
ContextManager（公告板）
    │
    ├── Pass A 从中读取 FSIR，产出 NNGraph，贴回公告板
    ├── Pass B 从中读取 NNGraph，产出 ZeusGraph，贴回公告板
    └── ...
```

**Registry 注册表**：Pass 通过装饰器 `@PassRegistry.register_module()` 自动注册，支持按名称动态查找和实例化。

**Lowering（逐层降低）**：高层 IR → 低层 IR 的转换分多步完成，每步只做一层降低。

**DAG 依赖图**：指令间用有向无环图表示依赖关系，通过拓扑排序确定合法执行顺序，发现并行机会。

### 目标硬件

Zeus NPU 每个 Core 包含以下计算/存储单元：

| 单元 | 职责 | 对应指令 |
|---|---|---|
| **PE** (Processing Element) | 卷积、矩阵乘法等核心计算 | PE |
| **VP** (Vector Processor) | 激活函数、池化等逐元素运算 | VP |
| **DT** (Data Transfer) | 片上数据搬移和格式转换 | DT |
| **CT** (Control) | 控制流、配置计算上下文 | CT |
| **LD/LW** (Load/Load Weight) | DRAM → L2 数据/权重加载 | LD, LW |
| **ST** (Store) | L2 → DRAM 结果写回 | ST |
| **SI/SO** (Sync In/Out) | 核间同步信号收发 | SI, SO |

三级存储层级：

```
WL1 (18.5KB, 极快)  ←→  L2 (~1MB, 快)  ←→  DRAM (大容量, 慢)
```

### 支持的算子

**卷积**：Conv2d, Conv1d, Deconv2d, Deconv1d, Dicv, Decv, Gpcv, DGpcv

**线性**：Dense, Bmm, MatMul

**激活**：ReLU, ReLU6, Sigmoid, Tanh, Gelu, Swish, LeakyReLU, Softmax

**归一化**：BatchNorm, LayerNorm

**池化**：AvgPool, MaxPool, GlobalAvgPool

**形状变换**：Concat, Split, Reshape, Transpose, Gather, Scatter, Slice, Pad

**逐元素**：Add, Sub, Mul, Div, Min, Max, Pow, Sqrt, Reciprocal

**其他**：Upsample, Resize

## 配置文件

配置文件位于 `cfg/` 目录：

| 文件 | 用途 |
|---|---|
| `default.py` | 默认单核编译配置 |
| `mk_default.py` | 多核编译配置 |
| `mk_e2e_default.py` | 多核端到端编译配置 |
| `product_default.py` | 生产环境配置 |
| `ddr_test_default.py` | DDR 测试配置 |

## 辅助工具

`tools/` 目录下的辅助工具：

| 工具 | 用途 |
|---|---|
| `run.py` | 主编译入口 |
| `run_multi_kernel.py` | 多核编译入口 |
| `run_multi_kernel_e2e.py` | 多核端到端编译 |
| `encoder.py` / `decoder.py` | 指令编码/解码工具 |
| `net_config_tools.py` | net_config 处理工具 |
| `relocate_inst_addr.py` | 指令地址重定位 |
| `siso_verify.py` | SISO 同步验证 |
| `ddr_test.py` | DDR 测试 |

## 文档

详细的架构设计和代码阅读指南请参考 [docs/assembler_v2_learning_guide.md](docs/assembler_v2_learning_guide.md)。
