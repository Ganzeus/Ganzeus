# 学习资料库 & 按周精读计划

> 📅 创建日期：2026-04-16
> 📎 配套文件：[gaoz132_learning_plan.md](gaoz132_learning_plan.md)（8 周任务规划 + 三年职业规划）
> 🕐 本文覆盖窗口：16 周（约 4 个月）—— 前 8 周对齐任务交付，后 8 周深化知识储备
> 📂 维护约定：同 learning_plan，只在用户明确说"更新"时才改

---

# Part 1 · 学习资料总览

> 每份资料都标注了：类型 / 语言 / 难度 / 知识点 / 学完能获得什么 / 预计耗时 / 配套视频或笔记。
> **短期资料**（4 个月内用到）排前面，**长期资料**（碎片时间慢啃）排后面。

---

## 短期资料（前 16 周按需取用）

---

### R01 · Eyeriss NeurIPS 2019 Tutorial（仅 pp.1-25）

| 字段 | 内容 |
|---|---|
| **类型** | Tutorial slides (PDF, 只读前 25 页) |
| **链接** | [eyeriss.mit.edu/2019_neurips_tutorial.pdf](https://eyeriss.mit.edu/2019_neurips_tutorial.pdf) |
| **语言** | 英文 |
| **难度** | ⭐⭐ |
| **涉及知识点** | DNN 基础回顾、PE array / systolic array 概念、算力/访存指标（FLOPS / bandwidth / arithmetic intensity） |
| **学完能获得什么** | 理解 PE array 和 memory hierarchy 的基础概念。**pp.26-80 讲的 CNN dataflow (WS/OS/RS) 与大模型关联不大，跳过** |
| **预计耗时** | 1-2h（只读 pp.1-25） |
| **跳过理由** | 公司做智驾芯片跑大模型，Transformer/Attention 的瓶颈是 KV-cache / memory-bound decode，不是 CNN 的 weight reuse / row stationary。硬件基础概念用 pp.1-25 + MIT 6.5940 覆盖更好 |

**配套**：
- [Eyeriss 官方 Tutorial 页面](https://eyeriss.mit.edu/tutorial.html) — 含视频，但同样偏 CNN

---

### R01b · MIT 6.5940: TinyML and Efficient Deep Learning Computing（Eyeriss 升级替代）

| 字段 | 内容 |
|---|---|
| **类型** | 大学课程（视频 + slides + 作业，~15 讲） |
| **链接** | [hanlab.mit.edu/courses/2024-fall-65940](https://hanlab.mit.edu/courses/2024-fall-65940) |
| **语言** | 英文（YouTube 视频） |
| **难度** | ⭐⭐ |
| **涉及知识点** | pruning、quantization (PTQ/QAT)、neural architecture search、knowledge distillation、distributed training、**LLM 推理加速**（KV-cache / speculative decoding / Llama2 部署）、diffusion model 加速 |
| **学完能获得什么** | 建立"高效 AI 计算"的完整知识体系，既涵盖硬件基础也覆盖大模型。比 Eyeriss 更贴合当前业务 |
| **预计耗时** | 全套 ~25h（15 讲 × ~1.5h）；短期只看 LLM 相关讲次 ~6h |
| **章节拆分建议** | Lec 1-2: Intro + Pruning (3h); Lec 3-4: Quantization (3h); Lec 5-6: NAS + Distillation (3h); Lec 7-9: Distributed + LLM acceleration (5h) ⭐重点; Lec 10+: TinyML + Diffusion (6h) |

**配套视频/笔记**：
- [YouTube 视频（MIT HAN Lab 频道）](https://www.youtube.com/@MITHANLab) — Fall 2024 全套录影
- [csdiy.wiki 课程导航](https://csdiy.wiki/en/%E6%9C%BA%E5%99%A8%E5%AD%A6%E4%B9%A0%E7%B3%BB%E7%BB%9F/EML/) — 中文课程评价和学习建议
- [GitHub: yifanlu0227/MIT-6.5940](https://github.com/yifanlu0227/MIT-6.5940) — 作业参考

---

### R02 · Eyeriss ISCA 2016 论文（选读）

| 字段 | 内容 |
|---|---|
| **类型** | 会议论文 (15 页) |
| **链接** | [eems.mit.edu (PDF)](https://eems.mit.edu/wp-content/uploads/2016/04/eyeriss_isca_2016.pdf) |
| **语言** | 英文 |
| **难度** | ⭐⭐⭐ |
| **涉及知识点** | Row Stationary dataflow、168-PE spatial architecture、energy breakdown |
| **学完能获得什么** | 理解 PE array cost model 的基础思想。偏 CNN，但 stschedule 的 cost function 部分借鉴了这类思路 |
| **预计耗时** | 2h（只看 Sec 1-3，跳过 CNN-specific 的 eval） |
| **定位** | **选读**——如果 W5 读 stschedule 代码时发现 cost function 有 energy 项，再回来看这篇 |

---

### R02b · LLM Inference Acceleration: A Comprehensive Hardware Perspective（2024 新综述）

| 字段 | 内容 |
|---|---|
| **类型** | Survey 论文 |
| **链接** | [arXiv 2410.04466](https://arxiv.org/abs/2410.04466) |
| **语言** | 英文 |
| **难度** | ⭐⭐⭐ |
| **涉及知识点** | LLM 推理的 prefill vs decode 两阶段、Attention 的 memory-bound 本质、GPU/FPGA/ASIC 各路加速方案、KV-cache 硬件优化、speculative decoding 硬件支持 |
| **学完能获得什么** | 从硬件视角理解"为什么大模型推理和 CNN 推理完全不一样"，能跟公司硬件团队对上话 |
| **预计耗时** | 4-5h |

---

### R02c · A Survey on Hardware Accelerators for LLMs（2024）

| 字段 | 内容 |
|---|---|
| **类型** | Survey 论文 |
| **链接** | [arXiv 2401.09890](https://arxiv.org/abs/2401.09890) |
| **语言** | 英文 |
| **难度** | ⭐⭐⭐ |
| **涉及知识点** | GPU (A100/H100) / FPGA / ASIC (d-Matrix, Etched) / PIM 各路 LLM 加速架构横评 |
| **学完能获得什么** | 知道你们公司的 NPU 在整个 LLM 加速生态里的位置，面试能聊竞品 |
| **预计耗时** | 3-4h |

---

### R02d · KV Cache Management Survey（2024）

| 字段 | 内容 |
|---|---|
| **类型** | Survey 论文 |
| **链接** | [arXiv 2412.19442](https://arxiv.org/abs/2412.19442) |
| **语言** | 英文 |
| **难度** | ⭐⭐⭐ |
| **涉及知识点** | KV-cache 的 token-level / model-level / system-level 三层优化策略、cache selection / merging / quantization / low-rank |
| **学完能获得什么** | KV-cache 是大模型推理在 NPU 上的核心瓶颈，理解它的优化空间 = 理解公司芯片要解决的核心问题 |
| **预计耗时** | 3-4h |

---

### R03 · 陈天奇《机器学习编译》MLC 中文课

| 字段 | 内容 |
|---|---|
| **类型** | 大学课程（视频 + Jupyter Notebook，共 ~12 讲） |
| **链接** | [mlc.ai/summer22-zh/](https://mlc.ai/summer22-zh/)（课程主页）; [课程 Schedule](https://mlc.ai/summer22/schedule) |
| **语言** | 中文（B 站有中文录影）/ 英文（YouTube 有英文录影） |
| **难度** | ⭐⭐ |
| **涉及知识点** | MLC 概述、TensorIR 抽象、自动程序优化 (AutoTuning)、计算图优化 (Graph-level)、端到端集成、GPU 加速、模型部署、量化 |
| **学完能获得什么** | 理解整条 "模型 → IR → 优化 → 硬件代码" 的编译链设计；能做一个简单的 TVM schedule |
| **预计耗时** | 20-25h（12 讲 × ~1.5h 视频 + notebook 练习） |
| **章节拆分建议** | Lec 1: 概述 (1.5h); Lec 2-3: TensorIR (3h); Lec 4: 自动优化 (2h); Lec 5: 计算图 (2h); Lec 6: 端到端 (2h); Lec 7: GPU (2h); Lec 8+: 部署/量化 (6h) |

**配套视频/笔记**：
- **B站**：搜索「陈天奇 MLC」或「机器学习编译」可找到中文课程录影（课程官方发布）
- [MLC 课程笔记（飞书）](https://deep-learning.feishu.cn/wiki/Fyj5wwxAKiEBHNkh6pEcKYNDnDh) — 社区整理的逐讲笔记
- [GitHub: doongz/mlc-ai](https://github.com/doongz/mlc-ai) — 课程笔记 + 代码整理
- [MLC 中文论坛](https://github.com/mlc-ai/mlc-zh/discussions) — 答疑讨论区

---

### R04 · 《机器学习系统：设计和实现》AI 编译器章节

| 字段 | 内容 |
|---|---|
| **类型** | 开源教材（在线阅读） |
| **链接** | [openmlsys.github.io](https://openmlsys.github.io/) |
| **语言** | 中文 |
| **难度** | ⭐⭐ |
| **涉及知识点** | AI 编译器设计原理（AOT vs JIT）、前端 IR、图优化 Pass、算子生成、后端代码生成、运行时 |
| **学完能获得什么** | 在 30-60 分钟内建立 "编译器前端/后端/运行时" 三段式概念框架 |
| **预计耗时** | 短期只读 AI 编译器章节 ~2h；通读全书 ~20h |
| **章节拆分建议** | Ch 4 AI 编译器前端 (1h); Ch 5 AI 编译器后端 (1h); Ch 3 AI 加速器（选读，与 Eyeriss 互补） |

**配套视频/笔记**：
- [GitHub: openmlsys](https://github.com/openmlsys/openmlsys) — 源码 + issue 讨论
- 书中引用了大量 TVM / XLA / MLIR 的实例，可对照官方文档

---

### R05 · Dive into Deep Learning Compiler (tvm.d2l.ai)

| 字段 | 内容 |
|---|---|
| **类型** | 互动教程（Jupyter book，~15 章） |
| **链接** | [tvm.d2l.ai](https://tvm.d2l.ai/) |
| **语言** | 英文 |
| **难度** | ⭐⭐⭐ |
| **涉及知识点** | TVM 安装、表达式 / 算子 / 计算图编译、shape / broadcast 推断、调度原语、CPU/GPU 优化、conv 优化、depthwise conv、batch norm、pooling、内存分配 |
| **学完能获得什么** | TVM 实操能力，能写一个简单 schedule 并理解 lowering 到硬件的过程 |
| **预计耗时** | 全部 ~30h；W7 只需读 ch9 (内存管理) + ch5-6 (IR 变换) ~6h |
| **章节拆分建议** | Ch1-3 基础 (3h); Ch4-6 算子编译 (5h); Ch7-8 GPU优化 (5h); Ch9 内存管理 (3h) ⭐; Ch10+ 高级 (8h) |

**配套视频/笔记**：
- [知乎：深度学习编译器 TVM 代码串讲](https://zhuanlan.zhihu.com/p/446976730)
- [知乎：从零开始学深度学习编译器（万字系列）](https://aijishu.com/a/1060000000222107)
- [Apache TVM 中文站](https://tvm.hyper.ai/) — 官方文档的中文翻译

---

### R06 · 模拟退火算法（Simulated Annealing）

| 字段 | 内容 |
|---|---|
| **类型** | Wikipedia + 知乎/博客合集 |
| **链接** | [Wikipedia (EN)](https://en.wikipedia.org/wiki/Simulated_annealing); [Wikipedia (中文)](https://zh.wikipedia.org/wiki/%E6%A8%A1%E6%8B%9F%E9%80%80%E7%81%AB) |
| **语言** | 中英均有 |
| **难度** | ⭐ |
| **涉及知识点** | 温度 T、降温曲线 (cooling schedule)、Metropolis 准则（接受劣解概率）、邻域动作、收敛条件 |
| **学完能获得什么** | 理解 stschedule 两阶段 SA 的搜索框架：为什么有随机性、为什么同一输入跑两次结果不同 |
| **预计耗时** | 1-2h |

**配套视频/笔记**：
- [知乎：一文搞懂什么是模拟退火算法](https://zhuanlan.zhihu.com/p/404204692) — 最易懂的中文科普
- [OI Wiki: 模拟退火](https://oi-wiki.org/misc/simulated-annealing/) — 含代码模板，竞赛风格但简洁
- [知乎：用 SA 解旅行商问题](https://zhuanlan.zhihu.com/p/46292992) — 手把手代码实战
- [CSDN：深入理解模拟退火算法](https://blog.csdn.net/xianlingmao/article/details/7798647)

---

### R07 · Roofline Model

| 字段 | 内容 |
|---|---|
| **类型** | 博客 + 论文 |
| **链接** | [Berkeley Roofline 入门](https://crd.lbl.gov/divisions/amcr/computer-science-amcr/par/research/roofline/) |
| **语言** | 英文（博客），中文（知乎/CSDN 配套） |
| **难度** | ⭐⭐ |
| **涉及知识点** | 算术强度 (Operational Intensity)、理论峰值算力、内存带宽上限、compute-bound vs memory-bound 判断 |
| **学完能获得什么** | 能画 Roofline 图，能判断"这层 Conv 在我们 NPU 上是 compute-bound 还是 memory-bound" |
| **预计耗时** | 1-2h |

**配套视频/笔记**：
- [知乎：Roofline Model 与深度学习模型的性能分析](https://zhuanlan.zhihu.com/p/34204282) — 中文入门首选
- [CSDN：Roofline 模型概念、基本公式、图像分析](https://blog.csdn.net/sinat_35360418/article/details/128672715) — 含公式推导
- [知乎：roofline 模型](https://zhuanlan.zhihu.com/p/643018703)

---

### R08 · assembler_v2_learning_guide.md（内部文档）

| 字段 | 内容 |
|---|---|
| **类型** | 项目内部学习指南 |
| **链接** | [assembler/docs/assembler_v2_learning_guide.md](assembler/docs/assembler_v2_learning_guide.md) |
| **语言** | 中文 |
| **难度** | ⭐⭐ |
| **涉及知识点** | assembler 5 层 IR lowering、Pass + ContextManager 架构、代码阅读路径 |
| **学完能获得什么** | 能沿着文档指引把 assembler 核心代码追一遍 |
| **预计耗时** | 3-5h（配合源码阅读） |

---

### R09 · compilerfrontend 内部文档

| 字段 | 内容 |
|---|---|
| **类型** | 项目内部文档（多份） |
| **链接** | [compilerfrontend/doc/onnx_converter_doc.md](compilerfrontend/doc/onnx_converter_doc.md) ⭐; [compilerfrontend/doc/frontend_test_doc.md](compilerfrontend/doc/frontend_test_doc.md); `compilerfrontend/doc/{pe,vp,dt}_ops_doc.md` |
| **语言** | 中文 |
| **难度** | ⭐⭐ |
| **涉及知识点** | ONNX 算子 → qm.* 内部算子的转换规则、算子测试框架、PE/VP/DT 硬件算子说明 |
| **学完能获得什么** | 能讲清 "一个 Conv 从 ONNX 到 FSIR 经过了什么" |
| **预计耗时** | 2-3h |

---

### R10 · GitLab CI/CD 文档

| 字段 | 内容 |
|---|---|
| **类型** | 官方文档 + 中文教程 |
| **链接** | [GitLab CI 官方](https://docs.gitlab.com/ee/ci/); [极狐 GitLab 中文入门](https://docs.gitlab.cn/jh/ci/quick_start/) |
| **语言** | 英文 / 中文 |
| **难度** | ⭐⭐ |
| **涉及知识点** | `.gitlab-ci.yml` 语法、stages / jobs / artifacts / rules / cache、Runner 配置 |
| **学完能获得什么** | 能写出一个可跑的 CI pipeline |
| **预计耗时** | 3-4h |

**配套视频/笔记**：
- [CSDN：GitLab CI/CD 视频教程 + 文字教程，从入门到精通](https://blog.csdn.net/github_35631540/article/details/117172382)
- [极狐 GitLab：创建并运行你的第一个 CI/CD 流水线](https://gitlab.cn/docs/jh/ci/quick_start/_index/)
- [简书：Gitlab-CI 使用及 .gitlab-ci.yml 配置入门](https://www.jianshu.com/p/4cc441b1c8a3)

---

## 长期资料（碎片时间慢啃，按优先级排列）

---

### R11 · TVM OSDI 2018 论文【优先级 P0】

| 字段 | 内容 |
|---|---|
| **链接** | [arXiv 1802.04799](https://arxiv.org/abs/1802.04799) |
| **预计耗时** | 3-4h |
| **为什么学** | TVM 设计理念，面试必考。你们的专有工具链和 TVM 思路高度重合 |
| **学完能获得什么** | 能在面试中讲清 TVM 的 graph-level / operator-level 优化 + learning-based cost model |

---

### R12 · 知乎扫盲四篇【优先级 P0】

| 文章 | 链接 | 耗时 |
|---|---|---|
| 深度学习编译技术的现状和未来 | [知乎](https://zhuanlan.zhihu.com/p/65452090) | 30 min |
| 传统编译器和 AI/ML 编译器总结 | [知乎](https://zhuanlan.zhihu.com/p/673452222) | 30 min |
| 深度学习编译器综述 | [知乎](https://zhuanlan.zhihu.com/p/436952766) | 40 min |
| 深度学习编译器整理 | [知乎](https://zhuanlan.zhihu.com/p/382015459) | 30 min |

---

### R13 · TVM 官方文档 + 中文站【优先级 P1】

| 资料 | 链接 |
|---|---|
| Apache TVM 官方文档 | [tvm.apache.org](https://tvm.apache.org/) |
| TVM 中文站 | [tvm.hyper.ai](https://tvm.hyper.ai/) |
| TVM 快速入门（中文） | [tvm.hyper.ai/docs/tutorial/quick_start](https://tvm.hyper.ai/docs/tutorial/quick_start/) |

**配套笔记**：
- [知乎：AI 编译器及 TVM 概述](https://zhuanlan.zhihu.com/p/672462650)
- [知乎：TVM 及深度学习编译技术入门分享](https://zhuanlan.zhihu.com/p/648566805)
- [GitHub: BBuf/tvm_mlir_learn](https://github.com/BBuf/tvm_mlir_learn) — compiler learning resources 合集

---

### R14 · MLIR Toy Tutorial + Jeremy Kun【优先级 P2】

| 资料 | 链接 | 耗时 |
|---|---|---|
| MLIR 官网 Toy Tutorial (7 章) | [mlir.llvm.org/docs/Tutorials/Toy](https://mlir.llvm.org/docs/Tutorials/Toy/) | 15-20h |
| MLIR for Beginners (Jeremy Kun) | [github.com/j2kun/mlir-tutorial](https://github.com/j2kun/mlir-tutorial) | 10h |
| MLIR beginner-friendly tutorial | [github.com/AlexandreSinger/mlir-beginner-friendly-tutorial](https://github.com/AlexandreSinger/mlir-beginner-friendly-tutorial) | 5h |

**配套视频/笔记**：
- [MLIR 官方 Talks 页面](https://mlir.llvm.org/talks/) — 含 EuroLLVM 2019 Mehdi Amini 的入门 talk 视频
- [Stephen Diehl: Introduction to MLIR](https://www.stephendiehl.com/posts/mlir_introduction/) — 清晰的第三方概述
- [LambdaClass MLIR Workshop](https://lambdaclass.github.io/mlir-workshop/) — 完整动手 workshop

---

### R15 · Learn LLVM 17（书）【优先级 P3】

| 字段 | 内容 |
|---|---|
| **链接** | [Amazon](https://www.amazon.com/Learn-LLVM-12-beginners-libraries/dp/1839213507) / [GitHub 代码](https://github.com/PacktPublishing/Learn-LLVM-17) |
| **预计耗时** | 40-60h（全书 416 页，可按需查阅） |
| **为什么学** | LLVM 是 MLIR 的底座，也是通用编译器后端标准 |

**配套**：
- [How to learn compilers: LLVM Edition](https://lowlevelbits.org/how-to-learn-compilers-llvm-edition/) — 免费博客路线图
- *Engineering a Compiler* (Cooper & Torczon) — [Amazon](https://www.amazon.com/Engineering-Compiler-Keith-Cooper/dp/012088478X) — 编译器理论参考书，不用通读，当字典

---

### R16 · Flash Attention 论文【优先级 P2】

| 字段 | 内容 |
|---|---|
| **链接** | [arXiv 2205.14135](https://arxiv.org/abs/2205.14135) |
| **预计耗时** | 4-6h（精读） |
| **为什么学** | LLM 推理里最核心的 kernel 优化思想，Triton 背景的人读这个会很自然 |

**配套视频/笔记**：
- [知乎：Flash Attention 原理详解（含代码讲解）](https://zhuanlan.zhihu.com/p/676655352) ⭐ 中文最佳
- [知乎：Flash Attention 讲解](https://zhuanlan.zhihu.com/p/640223710)
- [知乎：图解 Flash Attention V2，从原理到并行计算](https://zhuanlan.zhihu.com/p/691067658)
- [知乎：手撕 Flash Attention！原理解析及代码实现](https://zhuanlan.zhihu.com/p/696850636)
- [知乎：FlashAttention2 详解](https://zhuanlan.zhihu.com/p/645376942) — V2 改进
- [知乎：Flash Attention 3 深度解析](https://zhuanlan.zhihu.com/p/17533058076) — V3 最新

---

### R17 · vLLM / TensorRT-LLM / Quantization Survey【优先级 P3】

| 资料 | 链接 | 类型 |
|---|---|---|
| vLLM | [github.com/vllm-project/vllm](https://github.com/vllm-project/vllm) | 开源项目 |
| TensorRT-LLM | [github.com/NVIDIA/TensorRT-LLM](https://github.com/NVIDIA/TensorRT-LLM) | 开源项目 |
| Quantization 综述 | [arXiv 2103.13630](https://arxiv.org/abs/2103.13630) | 论文 |

---

# Part 2 · 按周精读计划（16 周）

> **阅读单位是章节/页码/讲次，不是"每天 X 小时"**，因为你每天效率不一样。
> 每个条目后标了预计耗时，按自己速度安排。
> **优先级标注**：🔴 必做 / 🟡 推荐 / 🟢 选做
>
> **W1-W8 = 任务驱动**（边做边学，学的内容直接用在当周任务上）
> **W9-W16 = 知识深化**（CI 任务已交付，系统补课 TVM / 编译器 / 硬件）
> **长期资料不进周计划**，放在 Part 3 · 碎片时间清单里。

---

## W1（demo 巩固 + 三项目大图）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | pipeline_demo/README.md | 全文精读 + 每步产物手动打开看 | 2h |
| 🔴 | R01 Eyeriss Tutorial PDF | **只看 pp.1-25**: DNN basics + 算力/访存指标 + PE array 概念 | 1.5h |
| 🔴 | R01b MIT 6.5940 Lec 1 | Introduction to Efficient AI Computing | 1.5h |
| 🟡 | R01b MIT 6.5940 Lec 2 | Pruning (剪枝基础) | 1.5h |
| 🟡 | compilerfrontend/README.md | 全文扫读 | 0.5h |
| 🟡 | stschedule/README.md | 全文扫读 | 0.5h |
| 🟡 | assembler/README.md | 全文扫读，重点看"架构概览"和"IR 层级"两节 | 1h |

**本周阅读总量**：~8.5h

---

## W2（前端专周）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R09 onnx_converter_doc.md | 全文精读 | 1.5h |
| 🔴 | R03 MLC 课 Lec 1 | 概述：什么是 MLC、为什么需要编译 | 1.5h |
| 🔴 | R03 MLC 课 Lec 2 | TensorIR 基础：IR 抽象 + 变换原语 | 2h |
| 🔴 | R04 《机器学习系统》 | Ch 4: AI 编译器前端（IR 设计、图优化 Pass） | 1h |
| 🟡 | R09 frontend_test_doc.md | 全文扫读，了解前端测试框架 | 0.5h |
| 🟡 | R09 pe/vp/dt_ops_doc.md | 各扫前 2 页，了解硬件算子种类 | 1h |
| 🟡 | R04 《机器学习系统》 | Ch 5: AI 编译器后端（选读，为 W7 做铺垫） | 1h |

**本周阅读总量**：~8.5h

---

## W3（批量黑盒跑）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | Python subprocess 官方文档 | [subprocess](https://docs.python.org/3/library/subprocess.html) — Popen / run / check_output | 1h |
| 🔴 | Python concurrent.futures 官方文档 | [concurrent.futures](https://docs.python.org/3/library/concurrent.futures.html) — ProcessPoolExecutor | 1h |
| 🟡 | R03 MLC 课 Lec 3 | TensorIR 自动程序优化 (AutoTuning) | 2h |
| 🟢 | pytest Getting Started | [docs.pytest.org](https://docs.pytest.org/en/stable/getting-started.html) — fixture / parametrize | 1h |

**本周阅读总量**：~5h（本周重在写代码）

---

## W4（指标提取 + diff 框架）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | pipeline_demo 产物 log.txt | 逐行读一遍，标记所有不理解的字段 | 1h |
| 🟡 | R03 MLC 课 Lec 4 | 计算图优化 (Graph-level optimization) | 2h |
| 🟡 | R03 MLC 课 Lec 5 | 端到端集成 | 2h |
| 🟢 | R07 Roofline Model | 知乎入门文 + Berkeley blog | 1.5h |

**本周阅读总量**：~6.5h

---

## W5（stschedule 深挖上：硬件模型 + Stage1 SA）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R02b LLM Hardware Survey (2410.04466) | 全文精读，重点 prefill vs decode + 硬件加速架构 | 4h |
| 🔴 | R06 模拟退火 | Wikipedia + [知乎一文搞懂](https://zhuanlan.zhihu.com/p/404204692) | 1.5h |
| 🟡 | R02c HW Accelerators for LLMs (2401.09890) | 扫读，了解 GPU/FPGA/ASIC 各路方案 | 2h |
| 🟡 | R02 Eyeriss ISCA 2016 | 选读 Sec 1-3（如果 stschedule cost function 有 energy 项再看） | 1.5h |
| 🟡 | R03 MLC 课 Lec 6 | GPU 加速（理解 schedule 原语在硬件上怎么映射） | 2h |

**本周阅读总量**：~10h

---

## W6（stschedule 深挖下：Stage2 + log.txt）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | stschedule source | Stage2 SA 相关文件（精读，边读边注释） | 4h |
| 🔴 | pipeline_demo log.txt | 逐字段注释，写进 learning_plan 附录 B | 2h |
| 🟡 | R03 MLC 课 Lec 7-8 | 部署 + 量化（与 stschedule 的 hardware-aware 优化做对照） | 3h |
| 🟢 | R06 SA 实战 | [知乎：用 SA 解 TSP](https://zhuanlan.zhihu.com/p/46292992) — 写 50 行 Python SA 加深理解 | 1.5h |

**本周阅读总量**：~10.5h

---

## W7（assembler 指标相关）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R08 assembler_v2_learning_guide.md | 全文精读，跟着指引追代码 | 3h |
| 🔴 | R05 tvm.d2l.ai Ch9 | 内存管理（对应 assembler 的 DRAM 分配） | 2h |
| 🟡 | R05 tvm.d2l.ai Ch5-6 | IR 变换（对应 assembler 的 5 层 lowering） | 3h |
| 🟡 | assembler/README.md | 重读"编译流程"和"IR 层级"节，对照代码 | 1h |

**本周阅读总量**：~9h

---

## W8（CI 正式化）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R10 极狐 GitLab 中文入门 | [创建第一个 CI/CD 流水线](https://gitlab.cn/docs/jh/ci/quick_start/_index/) | 1.5h |
| 🔴 | R10 GitLab CI 官方 | [.gitlab-ci.yml 关键词参考](https://docs.gitlab.com/ee/ci/yaml/) — stages / artifacts / rules / cache | 2h |
| 🟡 | [CSDN: GitLab CI/CD 教程](https://blog.csdn.net/github_35631540/article/details/117172382) | 视频 + 文字教程，从入门到精通 | 2h |
| 🟢 | 组内现有 .gitlab-ci.yml | 三个项目里找有没有现成的 CI 配置参考 | 0.5h |

**本周阅读总量**：~6h

---

## W9-W10（MLC 课收尾 + TVM 实操）

> CI 任务已交付，进入深化阶段。

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R03 MLC 课 Lec 9-12 | 剩余讲次（如有）+ 所有 Notebook 动手做 | 8h |
| 🔴 | R05 tvm.d2l.ai Ch1-4 | 基础 + 表达式/算子编译（完整过一遍） | 6h |
| 🟡 | R11 TVM OSDI 2018 论文 | 全文精读，重点 Sec 3-4 (Schedule + AutoTVM) | 3h |
| 🟡 | R05 tvm.d2l.ai Ch7-8 | GPU 优化（conv/gemm 的 schedule） | 4h |

**两周阅读总量**：~21h

---

## W11-W12（TVM 进阶 + Eyeriss Survey）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R05 tvm.d2l.ai Ch10-15 | 高级主题：batch norm / depthwise / quantize | 8h |
| 🟡 | R01 配套：arXiv 1703.09039 | Efficient Processing of DNNs Survey，全文 | 6h |
| 🟡 | TVM 中文站 tutorial | [快速入门](https://tvm.hyper.ai/docs/tutorial/quick_start/) + 2-3 个 how-to guide | 4h |
| 🟢 | R04 《机器学习系统》 | Ch 3: AI 加速器 + Ch 5: 后端（通读） | 4h |

**两周阅读总量**：~22h

---

## W13-W14（MLIR 入门）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R14 MLIR Toy Tutorial | Ch 1-4: 定义语言 → 生成 MLIR → 高层变换 → 低层变换 | 10h |
| 🟡 | R14 MLIR Toy Tutorial | Ch 5-7: Lowering → LLVM → JIT | 8h |
| 🟡 | [Stephen Diehl: Intro to MLIR](https://www.stephendiehl.com/posts/mlir_introduction/) | 全文，建立宏观认知 | 1h |
| 🟢 | R14 Jeremy Kun tutorial | 前 3 章 | 4h |

**两周阅读总量**：~23h

---

## W15-W16（Flash Attention + 编译器理论选读）

| 优先级 | 资料 | 读什么 | 预计耗时 |
|---|---|---|---|
| 🔴 | R16 Flash Attention 论文 | 全文精读 | 4h |
| 🔴 | [知乎 Flash Attention 原理详解](https://zhuanlan.zhihu.com/p/676655352) | 配合论文看，含代码 | 2h |
| 🟡 | [知乎 Flash Attention V2](https://zhuanlan.zhihu.com/p/691067658) | 图解 V2 改进 | 1.5h |
| 🟡 | R15 Learn LLVM 17 | Ch 1-3: 安装 + LLVM 架构 + 第一个 pass | 6h |
| 🟢 | R14 Jeremy Kun tutorial | Ch 4-6 | 4h |
| 🟢 | [知乎 Flash Attention 3 深度解析](https://zhuanlan.zhihu.com/p/17533058076) | V3 最新进展 | 1h |

**两周阅读总量**：~18.5h

---

# Part 3 · 碎片时间阅读清单（不进周计划）

> 按优先级排列。利用通勤、午休、等编译的时间读。
> 每篇标了单次阅读时间，适合碎片消化。

### P0（最先读，每篇 ≤30min）

| # | 资料 | 链接 | 单次耗时 |
|---|---|---|---|
| 1 | 深度学习编译技术的现状和未来 | [知乎](https://zhuanlan.zhihu.com/p/65452090) | 25 min |
| 2 | 传统编译器和 AI/ML 编译器总结 | [知乎](https://zhuanlan.zhihu.com/p/673452222) | 25 min |
| 3 | How to learn compilers: LLVM Edition | [lowlevelbits.org](https://lowlevelbits.org/how-to-learn-compilers-llvm-edition/) | 20 min |
| 4 | TVM 及深度学习编译技术入门分享 | [知乎](https://zhuanlan.zhihu.com/p/648566805) | 25 min |
| 4b | 脉动阵列 - 计算机体系结构 | [知乎](https://zhuanlan.zhihu.com/p/650209037) | 25 min |
| 4c | 脉动阵列 Systolic Architectures | [知乎](https://zhuanlan.zhihu.com/p/605590757) | 25 min |

### P1（前两个月内读完）

| # | 资料 | 链接 | 单次耗时 |
|---|---|---|---|
| 5 | 深度学习编译器综述 | [知乎](https://zhuanlan.zhihu.com/p/436952766) | 30 min |
| 6 | 深度学习编译器整理 | [知乎](https://zhuanlan.zhihu.com/p/382015459) | 25 min |
| 7 | AI 编译器及 TVM 概述 | [知乎](https://zhuanlan.zhihu.com/p/672462650) | 25 min |
| 8 | TVM 深度学习编译器代码串讲 | [知乎](https://zhuanlan.zhihu.com/p/446976730) | 40 min |
| 8b | 大语言模型推理优化技术综述 | [知乎](https://zhuanlan.zhihu.com/p/1911021800206365462) | 40 min |
| 8c | 万字长文！LLM 推理优化技术总结 | [知乎](https://zhuanlan.zhihu.com/p/1919407528363668517) | 40 min |

### P2（四个月内读完）

| # | 资料 | 链接 | 单次耗时 |
|---|---|---|---|
| 9 | Flash Attention 讲解（基础版） | [知乎](https://zhuanlan.zhihu.com/p/640223710) | 30 min |
| 10 | 手撕 Flash Attention | [知乎](https://zhuanlan.zhihu.com/p/696850636) | 40 min |
| 11 | 从零开始学深度学习编译器（万字系列入口） | [极术社区](https://aijishu.com/a/1060000000222107) | 每篇 30-40 min |
| 12 | Stephen Diehl: Introduction to MLIR | [stephendiehl.com](https://www.stephendiehl.com/posts/mlir_introduction/) | 30 min |

### P3（长线，Year 2 以后）

| # | 资料 | 链接 | 说明 |
|---|---|---|---|
| 13 | vLLM 源码阅读 | [github.com/vllm-project/vllm](https://github.com/vllm-project/vllm) | 理解 PagedAttention |
| 14 | TensorRT-LLM 架构 | [github.com/NVIDIA/TensorRT-LLM](https://github.com/NVIDIA/TensorRT-LLM) | 工业级参考 |
| 15 | Quantization 综述论文 | [arXiv 2103.13630](https://arxiv.org/abs/2103.13630) | PTQ/QAT/AWQ/GPTQ |
| 16 | BBuf/tvm_mlir_learn | [github.com/BBuf/tvm_mlir_learn](https://github.com/BBuf/tvm_mlir_learn) | compiler 学习资源合集 |
| 17 | LambdaClass MLIR Workshop | [lambdaclass.github.io](https://lambdaclass.github.io/mlir-workshop/) | 完整动手 workshop |

---

# Part 4 · 完成打卡表

> 每完成一份资料在「完成」列打 `[x]`。不含项目内部文档，只含论文、书、视频课、博客等独立资料。

| 完成 | 类型 | 资料名 | 链接 |
|---|---|---|---|
| [ ] | Tutorial | Eyeriss NeurIPS 2019 Tutorial (**仅 pp.1-25**) | [PDF](https://eyeriss.mit.edu/2019_neurips_tutorial.pdf) |
| [ ] | 视频课 | MIT 6.5940 TinyML & Efficient DL (Song Han, Fall 2024) | [hanlab.mit.edu](https://hanlab.mit.edu/courses/2024-fall-65940) |
| [ ] | 论文 | Eyeriss ISCA 2016（选读） | [PDF](https://eems.mit.edu/wp-content/uploads/2016/04/eyeriss_isca_2016.pdf) |
| [ ] | 论文 | LLM Inference Acceleration: Hardware Perspective (2024) | [arXiv 2410.04466](https://arxiv.org/abs/2410.04466) |
| [ ] | 论文 | A Survey on Hardware Accelerators for LLMs (2024) | [arXiv 2401.09890](https://arxiv.org/abs/2401.09890) |
| [ ] | 论文 | KV Cache Management Survey (2024) | [arXiv 2412.19442](https://arxiv.org/abs/2412.19442) |
| [ ] | 视频课 | 陈天奇 MLC 中文课（全 12 讲） | [mlc.ai](https://mlc.ai/summer22-zh/) |
| [ ] | 书 | 《机器学习系统：设计和实现》 | [openmlsys.github.io](https://openmlsys.github.io/) |
| [ ] | 教程 | Dive into Deep Learning Compiler (tvm.d2l.ai) | [tvm.d2l.ai](https://tvm.d2l.ai/) |
| [ ] | 论文 | TVM OSDI 2018 | [arXiv](https://arxiv.org/abs/1802.04799) |
| [ ] | 教程 | MLIR Toy Tutorial (7 章) | [mlir.llvm.org](https://mlir.llvm.org/docs/Tutorials/Toy/) |
| [ ] | 教程 | MLIR for Beginners (Jeremy Kun) | [GitHub](https://github.com/j2kun/mlir-tutorial) |
| [ ] | 教程 | MLIR beginner-friendly (AlexandreSinger) | [GitHub](https://github.com/AlexandreSinger/mlir-beginner-friendly-tutorial) |
| [ ] | 书 | Learn LLVM 17 | [GitHub](https://github.com/PacktPublishing/Learn-LLVM-17) |
| [ ] | 书 | Engineering a Compiler (Cooper & Torczon) | [Amazon](https://www.amazon.com/Engineering-Compiler-Keith-Cooper/dp/012088478X) |
| [ ] | 论文 | Flash Attention (arXiv 2205.14135) | [arXiv](https://arxiv.org/abs/2205.14135) |
| [ ] | 论文 | Quantization 综述 (arXiv 2103.13630) | [arXiv](https://arxiv.org/abs/2103.13630) |
| [ ] | 教程 | LambdaClass MLIR Workshop | [lambdaclass.github.io](https://lambdaclass.github.io/mlir-workshop/) |
| [ ] | 博客 | How to learn compilers: LLVM Edition | [lowlevelbits.org](https://lowlevelbits.org/how-to-learn-compilers-llvm-edition/) |
| [ ] | 博客 | Stephen Diehl: Introduction to MLIR | [stephendiehl.com](https://www.stephendiehl.com/posts/mlir_introduction/) |
| [ ] | 博客 | 深度学习编译技术的现状和未来 | [知乎](https://zhuanlan.zhihu.com/p/65452090) |
| [ ] | 博客 | 传统编译器和 AI/ML 编译器总结 | [知乎](https://zhuanlan.zhihu.com/p/673452222) |
| [ ] | 博客 | 深度学习编译器综述 | [知乎](https://zhuanlan.zhihu.com/p/436952766) |
| [ ] | 博客 | 深度学习编译器整理 | [知乎](https://zhuanlan.zhihu.com/p/382015459) |
| [ ] | 博客 | AI 编译器及 TVM 概述 | [知乎](https://zhuanlan.zhihu.com/p/672462650) |
| [ ] | 博客 | TVM 及深度学习编译技术入门分享 | [知乎](https://zhuanlan.zhihu.com/p/648566805) |
| [ ] | 博客 | TVM 深度学习编译器代码串讲 | [知乎](https://zhuanlan.zhihu.com/p/446976730) |
| [ ] | 博客 | 从零开始学深度学习编译器（万字系列） | [极术社区](https://aijishu.com/a/1060000000222107) |
| [ ] | 博客 | Roofline Model 与深度学习模型性能分析 | [知乎](https://zhuanlan.zhihu.com/p/34204282) |
| [ ] | 博客 | 一文搞懂模拟退火算法 | [知乎](https://zhuanlan.zhihu.com/p/404204692) |
| [ ] | 博客 | 用 SA 解旅行商问题 | [知乎](https://zhuanlan.zhihu.com/p/46292992) |
| [ ] | 博客 | Flash Attention 原理详解（含代码） | [知乎](https://zhuanlan.zhihu.com/p/676655352) |
| [ ] | 博客 | Flash Attention 讲解 | [知乎](https://zhuanlan.zhihu.com/p/640223710) |
| [ ] | 博客 | 图解 Flash Attention V2 | [知乎](https://zhuanlan.zhihu.com/p/691067658) |
| [ ] | 博客 | 手撕 Flash Attention | [知乎](https://zhuanlan.zhihu.com/p/696850636) |
| [ ] | 博客 | FlashAttention2 详解 | [知乎](https://zhuanlan.zhihu.com/p/645376942) |
| [ ] | 博客 | Flash Attention 3 深度解析 | [知乎](https://zhuanlan.zhihu.com/p/17533058076) |
| [ ] | 博客 | 大语言模型推理优化技术综述 | [知乎](https://zhuanlan.zhihu.com/p/1911021800206365462) |
| [ ] | 博客 | 万字长文！LLM 推理优化技术总结 | [知乎](https://zhuanlan.zhihu.com/p/1919407528363668517) |
| [ ] | 博客 | 脉动阵列 - 计算机体系结构 | [知乎](https://zhuanlan.zhihu.com/p/650209037) |
| [ ] | 博客 | 脉动阵列 Systolic Architectures | [知乎](https://zhuanlan.zhihu.com/p/605590757) |
| [ ] | 博客 | Systolic Array 加速矩阵乘运算 | [博客园](https://www.cnblogs.com/kongchung/p/13227256.html) |
| [ ] | 博客 | Apple: Deploying Transformers on NPU | [apple.com](https://machinelearning.apple.com/research/neural-engine-transformers) |
| [ ] | 教程 | MLSys Book: Hardware Acceleration | [mlsysbook.ai](https://mlsysbook.ai/contents/core/hw_acceleration/hw_acceleration.html) |
