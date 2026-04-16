# 学习与职业成长规划（2026–2029）

> 📅 创建日期：2026-04-15
> 👤 主角：gaoz132（新入职，硕士毕业，Triton 背景，无硬件架构基础）
> 🎯 近期窗口：2026-04-15 → 2026-06-15（8 周 CI 自动化任务）
> 🗺 长期窗口：2026 → 2029（三年职业规划）
> 📂 维护约定：只在我（用户）明确说"加到 md 里"时才更新，不自动追加

---

## 📌 原始 Prompt

> 用 superpowers brainstorming 功能帮我写一个系统性学习规划与代办清单。背景：我是一个硕士刚毕业的新入职员工，主要技术栈为会写一些 triton kernel，包括性能测试等，硬件架构层面我只知道基本的 gpu 内存层级等基础知识。我的第一个任务（这两个月）是做 assembler、compilerfrontend 和 stschedule 这三个项目的自动化。在此之前我得先深入看懂这三个项目的关系、作用以及代码细节等等。我已经用 claude code 创建了一个 pipeline 项目（test/pipeline_demo），但我现在还没有深入看，也没有跑过，当然这三个项目我也完全不了解。请你首先从 pipeline_demo 这个项目起步，接着深入分析这三个项目，保证你能彻头彻尾理解这三个项目，好让我之后问你问题能够得到准确的解答。最后帮我写一个完整大纲，包括学习规划、每一步该学什么、需要补充什么知识、看什么资料、预计能学到什么等等。不仅要在对话框输出，还要单独写一个 md 文件，记录我的 prompt 和这个大纲，我之后跟你对话过程中可能会让你在这个 md 中添加信息（不是每次对话都自动添加！）这个 md 的文件名你帮我起，位置就放在当前目录中，不要放在任何一个项目里。

### 澄清后的几项关键决定

| 维度 | 决定 |
|---|---|
| 自动化范围 | **批量回归 + CI 守门**（不是 orchestration 平台，不是深度调参） |
| 三项目深度分配 | stschedule 深挖（白盒），frontend / assembler 灰盒级别 |
| 挖坑节奏 | 现在快速扫描，按计划渐进式深挖 |
| 规划风格 | 方案 B：任务驱动 / 早出价值 |
| 前端例外 | W2 单独留一周做前端灰盒深入（用户额外要求） |

---

## § 1 · 北极星目标

### 近期（8 周）

给 `compilerfrontend / stschedule / assembler` 三项目工具链搭一套 **CI 守门机器人**，具体四件事：

1. **批量编译**：给定一组黄金模型，一键跑完 `frontend → stschedule → assembler`
2. **指标提取**：从 log 和产物里抓 cycle 数、bin size、峰值内存、（可选）精度
3. **回归检测**：和 baseline 对比，劣化超阈值则报警
4. **接入 GitLab CI**：MR / push 触发，绿叉红勾反馈给提交者

**起点**：[test/pipeline_demo/](test/pipeline_demo/) 已跑通，它就是 CI 最里面那个"单模型跑一次"的内核。

### 长期（三年）

> 详见 § 6.5 三年职业规划

- **Year 1**：在专有工具链上做出实质贡献（不只是 CI tooling）
- **Year 2**：建立"通用价值"——掌握 TVM / MLIR 开源体系，涉足 Transformer/LLM 推理优化
- **Year 3**：完成一次跳槽，目标大模型推理团队或通用 NPU 编译器团队

### 什么是 CI（留给以后复习用）

CI = Continuous Integration（持续集成），本质是"每次有人推代码，自动跑一批检查"的机器人。对于编译器项目，CI 守门具体是：
- 有人改了 stschedule 的 SA 代价函数 → 机器人自动跑黄金模型，cycle 数涨了 20% 就挡住 MR
- 有人改了 assembler 内存分配 → 机器人跑批量编译，任何一个挂了都挡住
- 有人改了前端量化 → 机器人跑精度比对，掉点超阈值挡住

类比：Triton 里手动跑 benchmark 对比 baseline vs new 的 TFLOPS —— CI 就是把这个动作**自动化** + **强制** + **人人都跑**。

---

## § 2 · 8 周周表总览

| 周 | 主题 | 一句话目标 |
|---|---|---|
| **W1** | demo 巩固 + 三项目 1000 英尺图 | 能画出整条数据流图，能指着图说"出错大概在哪" |
| **W2** | 前端专周（灰盒） | 能讲清一个 Conv 从 ONNX 到 FSIR 经过哪些 pass |
| **W3** | 批量黑盒跑（多模型） | `batch_run.py` 能自动跑 5-10 个模型，产物目录清晰 |
| **W4** | 指标提取 + diff 框架 | `collect_metrics.py` + `diff_report.py`，两次运行能输出变化报告 |
| **W5** | stschedule 深挖上半：硬件模型 + Stage1 SA | 能讲 PE array / memory hierarchy / LG 划分 / tile 切分 |
| **W6** | stschedule 深挖下半：Stage2 SA + log.txt 每字段 | 能从 log.txt 反推"SA 为什么选了这个 mapping" |
| **W7** | assembler 指标相关模块 | 能讲 5 层 IR lowering，能定位"bin size 变大"来自哪层 |
| **W8** | CI 正式化：`.gitlab-ci.yml` + MR 守门 + 报告美化 | 提一个故意劣化的 PR，能被机器人挡住 |

### 里程碑

- **M1（W2 末）**：能独立跟新同事讲 pipeline
- **M2（W4 末）**：内部工具已上线，组里别人能直接用 `batch_run.py`
- **M3（W6 末）**：stschedule 专家级（在新人里）
- **M4（W8 末）**：CI 上线

---

## § 3 · 周详细（8 周）

### W1 · demo 巩固 + 三项目大图

**任务**：
1. 从头再跑一次 `pipeline_demo/run_all.sh`，但这次每一步**手动拆着跑**，打开所有产物文件翻一遍
2. 把 `pipeline_demo/README.md` 里第 2 节的数据流图**手画一遍**（贴在工位/md 里）
3. 把三个项目的 `README.md` + `ls` 目录结构扫一遍，每个项目写 50 字小结

**补知识**（都用 Triton 类比切入）：
- **为什么需要 NPU（不是直接用 GPU）**：DSA 专用 / 能效比 / 固定流水线
- **PE array 是什么**：类比 Triton 的 `tl.dot`，只不过硬件固定在 8×8 脉动阵列
- **Memory hierarchy 的多级约束**：L1（AL1/WL1/OL1）/ L2 / DRAM，类比 GPU 的 shared mem / L2 / global mem，但每级容量更小、数据流动更需要显式调度

**资料**：
- [test/pipeline_demo/README.md](test/pipeline_demo/README.md)（自己写的 demo 文档）
- 三项目 `README.md`
- [Eyeriss NeurIPS 2019 Tutorial PDF](https://eyeriss.mit.edu/2019_neurips_tutorial.pdf) — **只看 pp.1-25**（PE array / memory hierarchy 基础概念），后面 CNN dataflow 部分跳过，跟大模型无关
- ⭐ [MIT 6.5940: TinyML and Efficient Deep Learning Computing (Song Han, Fall 2024)](https://hanlab.mit.edu/courses/2024-fall-65940) — **Eyeriss 的升级替代**，覆盖 pruning / quantization / LLM 推理加速 / Llama2 部署，YouTube 有全套视频。本周开始并行看前 2 讲

**产出**：
- 手画一张三项目数据流图（贴到本 md）
- 三行项目小结
- 列 ≥5 个 W1 想问导师的"看不懂的地方"

---

### W2 · 前端专周（灰盒）

**任务**：
1. 扫 `compilerfrontend/compilerfrontend/` 源码目录，画一级模块图（哪些目录，各负责什么）
2. 找到 **pass pipeline 的定义**（README 提到 `pass_config_path` / `frontend_compile_info.json` 里有 pass 列表，从它倒推入口）
3. 挑一个具体算子（建议 **Conv2d**）：沿 `onnx → 内部算子（qm.conv2d）→ fsir.json` 的转换路径，手动 trace 一遍
4. 看懂 `frontend_compile_info.json` 里的 `pass pipeline` 字段，知道每个 pass 大致干什么
5. 看一下 `parameters/` 和 `activations/` 目录里的 .npy 长什么样（用 numpy 打开看 shape / dtype）

**补知识**：
- **编译器 pass 是什么**：类比"一系列 code formatter / linter / transformer"，每个 pass 读一个 IR、改一改、吐下一个 IR
- **量化基础**：fp32 → int8 / fp16 的量化点（scale / zero_point），为什么要量化（精度换算力）
- **ONNX 基础**：op_type / attribute / initializer，类比 PyTorch 的 state_dict + graph

**资料**：
- [compilerfrontend/README.md](compilerfrontend/README.md)
- [compilerfrontend/doc/onnx_converter_doc.md](compilerfrontend/doc/onnx_converter_doc.md) ⭐ 重点：ONNX → 内部算子的转换规则
- [compilerfrontend/doc/frontend_test_doc.md](compilerfrontend/doc/frontend_test_doc.md)
- `compilerfrontend/doc/{pe,vp,dt}_ops_doc.md`（PE/VP/DT 硬件单元算子文档，前端 fsir 字段与之对应）
- ⭐ [陈天奇《机器学习编译》MLC 中文课](https://mlc.ai/summer22-zh/) — 本周起并行开始看（每天 1 小时），配合前端学习理解"pass 是什么、IR 是什么"
- [《机器学习系统：设计和实现》AI 编译器章节](https://openmlsys.github.io/chapter_frontend_and_ir/ai_compiler_design_principle.html) — 中文，免费，30 分钟扫一遍建立概念

**产出**：
- 一张前端内部模块图
- 一段"Conv2d 从 ONNX 到 FSIR 的 pass 轨迹"文字笔记（5-10 行）
- 列 ≥3 个你想新加但暂时不加的 pass / 算子候选

---

### W3 · 批量黑盒跑

**任务**：
1. 在 `test/` 下新建 `batch_runner/` 目录，写 `batch_run.py`：
   - 输入：一个 YAML/JSON 模型清单（model path / dtype / batch / core_num / dram_bw）
   - 对每个模型：跑 frontend → stschedule → assembler，收集所有产物到 `runs/<timestamp>/<model_name>/`
   - 并行跑（Python multiprocessing 或 subprocess 池）
   - Fail-fast 开关：一个挂了是否继续后面的
2. 准备一个"黄金模型清单"（5-10 个）—— 和组里借（问导师要历史上用来测试的模型）
3. 跑一次完整批量，把每个模型跑通一次

**补知识**：
- `subprocess` 模块的正确用法（`check=True`, 捕获 stderr, timeout）
- Python 的 `concurrent.futures.ProcessPoolExecutor`
- `pytest` 基础（为 W4 铺路）

**资料**：
- Python stdlib [subprocess](https://docs.python.org/3/library/subprocess.html)、[concurrent.futures](https://docs.python.org/3/library/concurrent.futures.html) 官方文档
- pipeline_demo 的 3 个 shell 脚本当函数化参考
- （继续推进）[陈天奇 MLC 课](https://mlc.ai/summer22-zh/)

**产出**：
- `batch_runner/` 目录，能一命令跑完 5-10 个模型
- 一份失败模型清单（正常情况有，不要紧张）

---

### W4 · 指标提取 + diff 框架

**任务**：
1. 写 `collect_metrics.py`：从一次 batch 的产物里提取每个模型的指标 → 一个 `metrics.json`
   - **stschedule**：从 `log.txt` 解析 Real Time / Ideal Time / Energy / Avg Buffer Usage
   - **assembler**：`inst_file.bin` 大小 / `weight_data.bin` 大小 / `lowered_layer.json` 里的指令数 / `net_config_*.json` 里的 DDR 用量
   - **frontend**：模型编译耗时、pass 数量、warnings
2. 跑一次基线，把 `metrics.json` 存为 `baseline.json`
3. 写 `diff_report.py`：对比两次 `metrics.json`，输出 Markdown 表格，按劣化百分比排序
4. 故意动一下 stschedule 的某个参数（比如 dram_bw 改一下），看 diff 报告是不是能显出变化

**补知识**：
- 回归阈值怎么定（类比 Triton benchmark 里 `rtol=0.02`）：cycle 数允许多少浮动？bin size 允许多少？
- 数值稳定性：SA 有随机性，同一个输入多次跑结果可能有波动 —— 先跑 3 次看 noise floor，阈值要大于 noise

**资料**：
- log.txt 实物（pipeline_demo 跑出来的）
- Python `json`, `re` 解析
- 可选：[rich](https://github.com/Textualize/rich) / [tabulate](https://pypi.org/project/tabulate/) 美化报告

**产出**：
- `collect_metrics.py` + `diff_report.py`
- `baseline.json`
- 一份"SA 波动实测报告"（同一输入跑 5 次，看每个指标的 std）

---

### W5 · stschedule 深挖（上）：硬件模型 + Stage1

**任务**：
1. 读 `stschedule/src/main.cpp`，从入口到 `schedule_ir_gen` 到 `inter_layer_schedule`，搞清调用链
2. 找到**硬件配置是在哪读入的**（大概在 `include/` 下一个 config 头文件 / JSON），把 PE array size / AL1 / WL1 / OL1 / UL3 / L2 / DRAM 的容量和带宽记下来
3. 读 Stage1 SA 的核心文件：搞清楚
   - 搜索空间是什么（layer order、LG partition、SLG 划分、tile number、K-cut）
   - 邻域动作是怎么定义的（一次 mutation 改什么）
   - cost function 是什么（cycles？energy？带宽冲突？）
4. 做个小实验：故意改 cost function 里某一项的权重，重跑 `pipeline_demo`，看 `log.txt` 选出的 mapping 有没有变

**补知识**：
- **模拟退火算法**：T 是什么、降温曲线、接受劣解概率；类比"爬山但允许偶尔下山"
- **tile / LG / SLG 概念**：tile 类比 Triton 的 `BLOCK_SIZE`，LG 是把几层融合一起跑（省掉中间写 DRAM），SLG 是 LG 内再细分
- **mapping vs scheduling**：mapping = "在哪个硬件单元上、用多大的 tile 算"；scheduling = "先后顺序 + 存哪里"
- **Roofline 模型**：compute-bound vs memory-bound，类比 Triton 里算 flops vs bandwidth 取小

**资料**：
- [stschedule/README.md](stschedule/README.md)
- [Eyeriss ISCA 2016 论文 PDF](https://eems.mit.edu/wp-content/uploads/2016/04/eyeriss_isca_2016.pdf) — 选读 Sec 3-4，理解 PE array dataflow 如何影响 cost（CNN 视角，但基础概念通用）
- ⭐ [LLM Inference Acceleration: A Comprehensive Hardware Perspective (arXiv 2410.04466)](https://arxiv.org/abs/2410.04466) — 2024 年新综述，从硬件视角讲 LLM 推理加速，**直接对标你们公司在做的事**
- ⭐ [A Survey on Hardware Accelerators for LLMs (arXiv 2401.09890)](https://arxiv.org/abs/2401.09890) — GPU/FPGA/ASIC 各路 LLM 加速方案横评
- [模拟退火 Wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing) — 建立 SA 基本概念，30 分钟足够
- Roofline model：搜 "Roofline model Williams 2009" 或看 [Berkeley 入门 blog](https://crd.lbl.gov/divisions/amcr/computer-science-amcr/par/research/roofline/)

**产出**：
- 一张"stschedule 硬件模型图"（PE array + 三级 memory + bandwidth）
- Stage1 SA 伪代码（50 行以内）
- 一份"调 cost weight 实验日志"

---

### W6 · stschedule 深挖（下）：Stage2 + log.txt 字段

**任务**：
1. 读 Stage2 SA：搜 tensor order / tensor time / weight 存放位置（L2 vs WL1），cost 是什么
2. 把 `log.txt` 每个字段都搞懂并在 md 里注释出来（Layer order / LG / Tile Num / K_part / Real Time / Ideal Time / Energy / Avg Buffer Usage / ...）
3. 看 `encoding.json` 格式，搞清 SA 结果是怎么编码的（为了复现）
4. 把 W4 做的"SA 波动实测报告"用 W5-6 的知识解释：每个指标的 noise 来源是什么

**补知识**：
- **L1 / L2 / DRAM trade-off**：为什么 weight 有时放 WL1（常驻）有时放 L2（流式）
- **带宽冲突**：多个硬件单元同时读 L2 → 排队 → 浪费 cycle
- **Ideal Time vs Real Time**：理想 = 只看计算量 / 峰值算力；Real = 含搬运和冲突

**资料**：
- stschedule source（重点：Stage2 SA 相关文件）
- pipeline_demo 跑出来的真实 log.txt
- （可选）[陈天奇 MLC 课](https://mlc.ai/summer22-zh/) 中 Schedule / Memory Reuse 相关章节

**产出**：
- `log.txt` 字段全注释版（放本 md 附录 B）
- Stage2 伪代码
- 能回答"为什么同一个模型两次跑 cycle 数差 3%"这类问题

---

### W7 · assembler 指标相关

**任务**：
1. 对着 assembler README 的"5 层 IR lowering"节，在代码里**各找一个文件对应**：
   - FSIR → NNLayer：`transforms/fsir2nnlayer.py`
   - NNLayer → ZeusLayer：`transforms/nnlayer2zeuslayer.py`
   - ZeusLayer → ABS：`target/zeus/` 下
   - ABS → Machine：`dialect/zeus_inst/` 下
2. 搞清**指令条数是在哪确定的**（哪层 lowering 出来后数目就定了？）
3. 搞清 **DRAM 分配是在哪做的**（`memory/` 目录），看它输出到 `rela.json` 的是啥
4. 把 W4 `collect_metrics.py` 里 assembler 的部分写得更狠 —— 提取每个 core 的指令分类（PE / VP / DT / LD / ST 各多少条）

**补知识**：
- **Pass + ContextManager 模式**：类比全局 context 字典，pass 之间用它传数据
- **Registry 装饰器模式**：`@PassRegistry.register_module()` 的机制
- **Lowering 思想**：高层 IR → 低层 IR，每层只掉一点抽象

**资料**：
- [assembler/README.md](assembler/README.md)（已经很详细）
- ⭐ [assembler/docs/assembler_v2_learning_guide.md](assembler/docs/assembler_v2_learning_guide.md)（W7 重点读）
- [Dive into Deep Learning Compiler (tvm.d2l.ai)](https://tvm.d2l.ai/) — 读"IR 变换"和"内存分配"两章，帮助理解 assembler 的设计思想

**产出**：
- 一份"哪个指标在哪层 IR 就定了"对照表
- `collect_metrics.py` 升级版

---

### W8 · CI 正式化

**任务**：
1. 写 `.gitlab-ci.yml`，包含：
   - **install stage**：装依赖、编译 stschedule
   - **test stage**：跑 `batch_run.py`（选 smoke 子集，不是全量）
   - **diff stage**：和存在 artifact 里的 baseline 比，生成报告
   - **阈值超标** → exit 非零 → MR 挡住
2. 把报告输出成 MR comment 格式（markdown 表格）
3. 写 `update_baseline.sh`：受控情况下一键更新 baseline
4. 跑一次故意劣化的 MR（在 stschedule 里改个 cost 参数）验证守门生效
5. 写用户文档（给组里其他人）："如何新增黄金模型""如何更新 baseline""CI 报错怎么读"

**资料**：
- [GitLab CI 官方文档](https://docs.gitlab.com/ee/ci/)（重点：stages / artifacts / rules / cache）
- 组内现有的 `.gitlab-ci.yml` 参考（三个项目可能已各自有一份）

**产出**：
- 生效的 `.gitlab-ci.yml`
- MR 守门实操（截图当工作汇报）
- 用户文档

---

## § 4 · 学习资料库

> 分为**短期**（这两个月直接用得上）和**长期**（三年职业成长慢慢啃）。
> 每个资料标注了：难度 / 语言 / 为什么学 / 怎么用。

---

### 🟥 短期资料（W1-W8 期间按需取用）

| # | 资料 | 难度 | 语言 | 用在哪周 | 为什么 |
|---|---|---|---|---|---|
| S1 | [Eyeriss NeurIPS 2019 Tutorial PDF](https://eyeriss.mit.edu/2019_neurips_tutorial.pdf) | ⭐⭐ | 英文 | W1 | **只看 pp.1-25**（PE array / memory hierarchy 基础），后面 CNN dataflow 跳过 |
| S1b | ⭐ [MIT 6.5940 (Song Han, Fall 2024)](https://hanlab.mit.edu/courses/2024-fall-65940) | ⭐⭐ | 英文 | W1 起并行 | Eyeriss 升级替代，覆盖 quantization / pruning / **LLM 推理加速** / Llama2 部署，YouTube 全套视频 |
| S2 | [Eyeriss ISCA 2016 论文 PDF](https://eems.mit.edu/wp-content/uploads/2016/04/eyeriss_isca_2016.pdf) | ⭐⭐⭐ | 英文 | W5 | 选读，PE array cost model 基础概念仍通用 |
| S2b | ⭐ [LLM Inference Acceleration: Hardware Perspective (arXiv 2410.04466)](https://arxiv.org/abs/2410.04466) | ⭐⭐⭐ | 英文 | W5 | 2024 年新综述，从硬件视角讲 LLM 推理加速，直接对标公司业务 |
| S2c | [A Survey on Hardware Accelerators for LLMs (arXiv 2401.09890)](https://arxiv.org/abs/2401.09890) | ⭐⭐⭐ | 英文 | W5 | GPU/FPGA/ASIC 各路 LLM 加速方案横评 |
| S3 | [陈天奇《机器学习编译》MLC 中文课](https://mlc.ai/summer22-zh/) | ⭐⭐ | 中文 | W2 起并行 | TVM 作者亲授，讲清"为什么要 IR / pass / 硬件无关优化"，配合看三项目代码感觉大不同 |
| S4 | [《机器学习系统：设计和实现》AI 编译器章节](https://openmlsys.github.io/chapter_frontend_and_ir/ai_compiler_design_principle.html) | ⭐⭐ | 中文 | W2 | 免费开源书，30 分钟建立 AOT/JIT/IR/Pass 概念 |
| S5 | [Dive into Deep Learning Compiler (tvm.d2l.ai)](https://tvm.d2l.ai/) | ⭐⭐⭐ | 英文 | W7 | 深入 TVM 的 IR 变换和内存分配，帮助理解 assembler 设计 |
| S6 | [模拟退火 Wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing) | ⭐ | 中英均有 | W5 | 30 分钟建立 SA 基本概念（温度/降温/接受劣解） |
| S7 | [assembler/docs/assembler_v2_learning_guide.md](assembler/docs/assembler_v2_learning_guide.md) | ⭐⭐ | 中文 | W7 | 项目自带学习指南，W7 主力资料 |
| S8 | [GitLab CI 官方文档](https://docs.gitlab.com/ee/ci/) | ⭐⭐ | 英文 | W8 | stages/artifacts/rules/cache 四个概念够用 |
| S9 | [compilerfrontend/doc/onnx_converter_doc.md](compilerfrontend/doc/onnx_converter_doc.md) | ⭐⭐ | 中文 | W2 | 项目内部文档，ONNX → 内部算子转换规则 |

---

### 🟦 长期资料（三年内慢慢啃，标了建议开始时间）

#### L1 · TVM 深度（建议：W6 以后，约 Year 1）

| 资料 | 链接 | 说明 |
|---|---|---|
| Apache TVM 官方文档 | [tvm.apache.org](https://tvm.apache.org/) | 学 Relay IR / TIR / Schedule 的权威来源 |
| TVM OSDI 2018 论文 | [arXiv 1802.04799](https://arxiv.org/abs/1802.04799) | TVM 设计理念，面试常考 |
| Apache TVM 中文站 | [tvm.hyper.ai](https://tvm.hyper.ai/) | 志愿者维护的中文翻译，适合入门 |

**为什么学**：TVM 是目前业界最广泛的开源 ML 编译器框架，你们的专有工具链和 TVM 设计思路高度重合。学完 TVM 之后，你的技能从"只能用于内部工具"变成"能对外跳槽"。

---

#### L2 · MLIR（建议：W8 以后，约 Year 1.5）

| 资料 | 链接 | 说明 |
|---|---|---|
| MLIR 官网 Toy Tutorial | [mlir.llvm.org/docs/Tutorials/Toy](https://mlir.llvm.org/docs/Tutorials/Toy/) | 必做！从零带你走完一个小语言的 MLIR 编译流程 |
| MLIR for Beginners (Jeremy Kun) | [github.com/j2kun/mlir-tutorial](https://github.com/j2kun/mlir-tutorial) | 公认最易懂的第三方教程，比官方文档友好 |
| MLIR 官网 Getting Started | [mlir.llvm.org/getting_started](https://mlir.llvm.org/getting_started/) | 建立环境 |

**为什么学**：Google XLA 新版、PyTorch Inductor、tenstorrent 的 tt-mlir、华为 MindSpore 都在迁移到 MLIR。这是未来 5 年 ML 编译器的通用基础设施。掌握它 = 打开所有通用编译器岗位的门。

---

#### L3 · LLVM（建议：Year 1.5，按需学）

| 资料 | 链接 | 说明 |
|---|---|---|
| Learn LLVM 17（书，Packt 2024） | [Amazon](https://www.amazon.com/Learn-LLVM-12-beginners-libraries/dp/1839213507) / [GitHub 代码](https://github.com/PacktPublishing/Learn-LLVM-17) | 2024 年最新版，从入门到写 backend |
| How to learn compilers: LLVM Edition | [lowlevelbits.org](https://lowlevelbits.org/how-to-learn-compilers-llvm-edition/) | 免费博客，先看这个再决定要不要买书 |

**为什么学**：LLVM 是 MLIR 的底层基础，也是所有通用编译器后端的标准。做 NPU backend 开发的时候经常需要写 LLVM IR 相关代码。先学 MLIR 再回来看 LLVM 会顺很多。

**注意**：不需要读龙书（《编译原理》Aho et al.），龙书是学术经典但实践价值有限。如果需要补编译器理论，用 [*Engineering a Compiler*（Cooper & Torczon）](https://www.amazon.com/Engineering-Compiler-Keith-Cooper/dp/012088478X)更实用。

---

#### L4 · LLM 推理优化（建议：Year 1 就开始，公司本身就在做大模型芯片）

| 资料 | 链接 | 说明 |
|---|---|---|
| Flash Attention 论文 | [arXiv 2205.14135](https://arxiv.org/abs/2205.14135) | LLM 推理里最核心的 kernel 优化思想 |
| KV Cache Management Survey | [arXiv 2412.19442](https://arxiv.org/abs/2412.19442) | 2024 年 KV-cache 专题综述（token/model/system 三级优化） |
| vLLM 项目 | [github.com/vllm-project/vllm](https://github.com/vllm-project/vllm) | 阅读源码理解 PagedAttention / continuous batching |
| TensorRT-LLM | [github.com/NVIDIA/TensorRT-LLM](https://github.com/NVIDIA/TensorRT-LLM) | 工业级 LLM 推理引擎，了解架构即可 |
| Quantization 综述 | [arXiv 2103.13630](https://arxiv.org/abs/2103.13630) | PTQ/QAT/AWQ/GPTQ 量化方法综述 |

**为什么学**：你们公司做智驾芯片跑大模型，这些不是"未来方向"而是**当前业务**。越早补上 LLM 推理的知识，越能在内部讨论中有话语权。

---

#### L5 · 中文优质知乎/博客（随时碎片阅读）

| 文章 | 链接 | 价值 |
|---|---|---|
| 深度学习编译技术的现状和未来 | [知乎](https://zhuanlan.zhihu.com/p/65452090) | 该领域最好的中文概述，有历史感 |
| 传统编译器和 AI/ML 编译器总结 | [知乎](https://zhuanlan.zhihu.com/p/673452222) | 两类编译器有哪里不一样的直觉 |
| 深度学习编译器综述 | [知乎](https://zhuanlan.zhihu.com/p/436952766) | 国内工程师写的 survey，好过直接读英文 |
| 深度学习编译器整理 | [知乎](https://zhuanlan.zhihu.com/p/382015459) | TVM/XLA/MLIR 横向对比 |
| 大语言模型推理优化技术综述 | [知乎](https://zhuanlan.zhihu.com/p/1911021800206365462) | LLM 推理五大核心技术（KV cache / 推测解码等） |
| 万字长文！LLM 推理优化技术总结 | [知乎](https://zhuanlan.zhihu.com/p/1919407528363668517) | prefill vs decode、各层优化方法全景 |

---

## § 5 · 每周固定动作（防失联）

- **周五下班前**：在 § 8 进度跟踪里填本周产出 / 下周 TODO / 卡住的地方
- **每周挑 1 个问题去问导师**（不要憋）
- **每两周一次 recap**：回看记忆里的项目文件，确认没过时
- **每月一次方向校准**：看一眼 § 6.5 三年规划，想想现在的工作和目标的距离

---

## § 6 · 8 周预期总产出

- ✅ **代码**：`batch_run.py` + `collect_metrics.py` + `diff_report.py` + `.gitlab-ci.yml` + `update_baseline.sh`
- ✅ **数据**：一套黄金模型 + `baseline.json`
- ✅ **文档**：用户手册（给组里别人用 CI 的）+ 本 md（给自己的学习档案）
- ✅ **知识**：
  - 三项目 I/O 关系闭眼能画
  - stschedule 两阶段 SA 闭眼能讲
  - frontend / assembler 能讲主要模块职责
  - 具备基础 NPU 架构认知（PE array / memory hierarchy / systolic / LG fusion）
  - 会写 GitLab CI、会用 pytest、会做数值回归检测

---

## § 6.5 · 三年职业规划（2026–2029）

### 整体路线图

```
2026 (Year 1)          2027 (Year 2)          2028-2029 (Year 3)
──────────────         ──────────────         ──────────────────
专有工具链 CI          深化 + 开源贡献         跳槽 / 转型
  ↓                      ↓                      ↓
打牢硬件 + 编译器      TVM/MLIR 通用化        大模型推理 or
基础（你现在）         支持 Transformer        通用 NPU 编译器
```

---

### Year 1（2026）：打基础，交付 CI，建立内部信任

**目标**：
- 完成 8 周 CI 任务，在组里建立"靠谱"的形象
- 通过 stschedule 深挖，成为组内第一个能解释 SA 输出的人
- 开始并推进 [陈天奇 MLC 课](https://mlc.ai/summer22-zh/)，搞清 TVM 架构

**关键动作**：
- 8 周结束后，**主动提一个 stschedule 或 assembler 的优化提案**（基于读代码发现的改进点）；不要停在 tooling 层
- 业余：每周 2 小时看 TVM 文档或 MLC 课
- 摸底市场：在 Boss 直聘 / 牛客上搜"ML Compiler 工程师"，了解 JD 要求什么技术栈（校准，不是真跳）

**Year 1 末可以说的话**：
> "我搭了一套三项目的 CI 守门系统，理解了整条 ONNX→FSIR→STSIR→.bin 的编译链，对 stschedule 的两阶段 SA 调度有代码级理解。"

---

### Year 2（2027）：通用化，建立开源存在感

**目标**：
- 掌握 TVM 的 Relay IR + TIR + Schedule 体系（能做一个简单的 custom pass）
- 开始学 MLIR（Toy Tutorial 做完，能用 MLIR 定义一个自定义 dialect）
- 如果公司开始支持 Transformer 模型，**主动请缨承担 Attention 算子的调度优化**
- 在 GitHub 上出现：给 TVM 或 vLLM 提 1-2 个有意义的 PR（fix bug 或小 feature）

**关键动作**：
- LLM 推理方向：读懂 Flash Attention 论文，尝试用 Triton 复现，理解 memory-bound 的 KV-cache 问题
- 编译器方向：完成 MLIR Toy Tutorial，读一遍 [Jeremy Kun 的 MLIR 教程](https://github.com/j2kun/mlir-tutorial)
- 脉脉 / LinkedIn 建立人脉：关注目标公司工程师，不是为了立刻跳，是为了了解他们在做什么

**Year 2 末可以说的话**：
> "我有 TVM/MLIR 实操经验，做过 NPU 编译链的 IR lowering，写过 Triton kernel，GitHub 上有开源贡献。"

---

### Year 3（2028–2029）：跳槽，进入更大舞台

**时机判断**：
- 简历上有 1 个拿得出手的技术成果（不只是"搭了个 CI"）
- TVM 或 MLIR 有实际开发经验
- 在当前岗位上已经做不出更多新东西

---

### 目标岗位与公司

#### 方向 A：大模型推理优化工程师（薪资溢价最高）

| 目标公司 | 团队/产品 | 技术栈要求 |
|---|---|---|
| 字节跳动 | 推理平台 / Seed 团队 | CUDA, Triton, TensorRT-LLM, vLLM, PyTorch |
| 阿里云 | PAI / 通义推理 | TVM, ONNX Runtime, 量化 (AWQ/GPTQ), CUDA |
| 百度 | 飞桨推理 / 文心 | PaddlePaddle, TVM, 自研推理引擎 |
| 商汤 | InternEvo / 大装置推理 | vLLM, Flash Attention, CUDA kernel |
| 月之暗面 / MiniMax 等 | 推理基础设施 | CUDA, Triton, 系统工程 |

**JD 关键词搜索**：ML compiler、LLM inference、inference optimization、kernel optimization、TensorRT、vLLM、CUDA optimization

#### 方向 B：NPU / DSA 编译器工程师（专业深度最强）

| 目标公司 | 产品 | 技术栈要求 |
|---|---|---|
| 华为 | CANN / AscendC | MLIR, C++, 硬件架构, 自研 IR |
| 地平线 | BPU 编译器 | TVM 或类 TVM 框架, C++, ONNX |
| 寒武纪 | MLU 编译器 | MLIR, LLVM, C++ |
| 燧原科技 | GCU 编译器 | MLIR, 图优化 |
| 摩尔线程 / 壁仞 | GPU 编译器 | CUDA/ROCm 生态, LLVM |

**JD 关键词搜索**：NPU compiler、DSA compiler、IR lowering、code generation、backend compiler、MLIR、TVM

---

### 如何找工作

**平台**：
- **Boss 直聘**：搜上面的关键词，直接联系 HR / 技术负责人
- **牛客网 offer 区 + 求职版**：看同背景的人拿到什么 offer，了解市场价
- **领英 LinkedIn**：搜目标公司 + 岗位，看 JD 细节；也方便被猎头找到
- **脉脉**：国内版 LinkedIn，关注目标公司员工，了解公司内部情况（文化/稳定性）
- **GitHub**：在 TVM/MLIR/vLLM 等开源项目有贡献 → 直接被 recruiter 联系

**内推**：
- 校友网络（导师 / 同学进了目标公司的）是最高效的通道
- 技术交流社区（知乎、掘金、CSDN 上认识的人）

**面试准备**：
- 系统设计：能讲"如何设计一个 ML 编译器的 IR 变换框架"
- 算法：编译器相关（数据流分析、图优化、寄存器分配）
- 实战：能 live coding 写一个简单的 MLIR pass 或 TVM custom schedule

---

### 薪资预期（仅供参考，请在 Boss直聘 实时校准）

| 年限 | 岗位 | 一线城市月薪（税前，社招） |
|---|---|---|
| 0-1 年（现在） | junior compiler/inference engineer | 15-25k |
| 2-3 年（跳槽前） | mid-level | 30-50k |
| 3-5 年（跳槽后） | senior，有 TVM/MLIR + LLM 推理经验 | 50-80k |
| 5 年+ | staff / tech lead | 80k+ |

### 防 35 岁危机的操作清单

- [ ] 不把技能锁死在公司专有工具链里，每年至少学一个通用开源框架
- [ ] GitHub 保持活跃（哪怕是 issue 讨论），对外可见的技术存在感
- [ ] 每年至少摸底一次市场（更新简历 + 看 JD），不要等到被裁才开始
- [ ] 关注 Attention 机制 / LLM 架构演进（因为你在做的硬件最终要跑这些）
- [ ] 2-3 年内完成一次主动跳槽（不是被动等）

---

## § 7 · 8 周进度跟踪（我自己填）

### W1（2026-04-15 → 2026-04-21）
- [ ] 任务 1：
- [ ] 任务 2：
- [ ] 任务 3：
- **卡住的地方**：
- **本周问导师的问题**：
- **下周 TODO**：

### W2（2026-04-22 → 2026-04-28）
- 待填

### W3（2026-04-29 → 2026-05-05）
- 待填

### W4（2026-05-06 → 2026-05-12）
- 待填

### W5（2026-05-13 → 2026-05-19）
- 待填

### W6（2026-05-20 → 2026-05-26）
- 待填

### W7（2026-05-27 → 2026-06-02）
- 待填

### W8（2026-06-03 → 2026-06-09）
- 待填

---

## § 8 · 长期问题清单（随时攒）

> 积攒那些"一时找不到答案、但想某天去查清楚"的问题，避免忘掉。

- [ ] `fusion_info.json` 的实际来源和语义（已知由 stschedule 产出，但内容含义还没跟导师确认）
- [ ] STSIR 文件名带 `_bw{BW}.000000` 是约定还是 bug
- [ ] `stschedule/stschedule.sh` 是坏的（用位置参数），组里要不要修
- [ ] `stschedule/src/main.cpp:1125` 的硬编码路径是测试残留吗
- [ ] （随时补）

---

## § 9 · 修订记录

| 日期 | 改动 | 发起人 |
|---|---|---|
| 2026-04-15 | 初稿创建（8 周 CI 规划） | gaoz132 + Claude（brainstorming） |
| 2026-04-15 | 新增 § 4 完整资料库（短期/长期，含链接）；新增 § 6.5 三年职业规划；各周 资料 节补充具体链接 | gaoz132 |
| 2026-04-16 | Eyeriss Tutorial 降级为仅 pp.1-25；新增 MIT 6.5940 (Song Han) 替代；新增 LLM 硬件加速综述 (2024)；L4 从 Year 2 提前到 Year 1；新增 KV Cache Survey + LLM 推理中文知乎文章 | gaoz132 |

---

## 附录 A · 快速参考卡片

### 三项目 I/O 速查

```
ONNX ──frontend──▶ .fsir.json + parameters/*.npy
                         │
                   stschedule（C++）
                         │
        ┌────────────────▼───────────────────┐
        │ *_c{C}_bw{BW}.000000_stschedule.json│
        │ fusion_info.json                    │
        │ log.txt (SA 日志)                   │
        └────────────────┬────────────────────┘
                         │
                   assembler（Python）
                         │
        ┌────────────────▼────────────┐
        │ inst_file.bin (16B/条)      │
        │ weight_data.bin             │
        │ net_config_*.json (给 SDK) │
        └─────────────────────────────┘
```

### 环境激活

```bash
source /datau38020T/Application/gaoz132/miniconda3/etc/profile.d/conda.sh
conda activate bjxx
```

### 一键跑通（demo）

```bash
cd /datau38020T/Application/gaoz132/test/pipeline_demo
bash run_all.sh
```

### 已知坑点

1. `stschedule/stschedule.sh` 是坏的（位置参数 vs 命名 flag），要用 `-m/-c/-d`
2. stschedule 输出文件名带 `.000000` 浮点后缀，grep 要用通配符
3. 单核 assembler 产物是 `inst_file.bin`（不是 `inst_file_core0.bin`）
4. 不要在 import numpy 的目录下放名字叫 `inspect.py` / `json.py` 的脚本，会 shadow stdlib

---

## 附录 B · log.txt 字段注释（W6 填写）

> W6 完成后把 stschedule 产出的真实 log.txt 贴在这里，逐字段注释。

```
（待填）
```
