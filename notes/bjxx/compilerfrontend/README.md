# 背景
- 简单介绍前端工具的使用方式
# Quick Start
## 代码仓库下载
```bash
git clone http://172.16.116.216:30000/compilergroup/compilerfrontend.git
cd compilerfrontend
```
## 切换到目标分支
```bash
git checkout compare_frontend_v2
```
## 安装依赖库
- 如果在组内服务器开发（强烈建议），建议安装conda后直接clone我的环境
```bash
conda create -n yourEnvName --clone /home/lyc/anaconda3/envs/pytorch_2
```
## 运行单算子模型全量测试
```bash
python3 frontend_test_single_op_v2.py single_onnx_op_config/ --all
```
# 编译工具
- 实现从量化后模型到IR算子模型的翻译，输出IR算子组成的模型
## 使用方式
```bash
python3 frontend_build.py --input /path/to/model
frontend_build  --input /path/to/model
```
## 可选参数
- `model` 输入的模型路径，必选参数
- `type` 输入模型类型（onnx, torch, paddlepaddle, tflite）, 目前暂支持onnx, torch, tflite; 默认onnx
- `dtype` 指定编译模型的类型，目前支持int8、float16、float32，默认为float16
- `output` 编译后模型的保存文件夹， 默认为output
- `batch` 指定模型编译的batch_size, 默认为1
- `quant_json_path` 量化模型所需量化文件，一般和模型文件在同一文件夹下，只在转换量化模型时使用，默认为None
- `pass_config_path` pass优化配置文件，用于自定义pass组合和参数设置，默认为None
- `debug` 是否保存编译生成的中间文件，主要用于调试，默认不保存
- `model_graph` 是否输出模型计算图，该功能只支持pytorch模型
# 运行工具
- 实现对前端输出IR算子模型
## 使用方式
```bash
python3 frontend_run.py /path/to/qm_model
frontend_run /path/to/qm_model
```
## 可选参数
  `path` 前端输出IR算子模型路径，必选参数
- `gpu` 配置gpu个数，开启多gpu加速运行，默认为-1（cpu执行）
- `save_inter` 是否保存模型中间层输出，默认为不保存
- `trim` 修剪输出结果和参数文件夹，默认为False
# 运行与比对工具
- 实现对前端输出IR算子模型和输入原模型的精度比对
## 使用方式
```bash
python3 frontend_run_and_compare.py --model /path/to/model --qm_model /path/to/qm_model
frontend_run_and_compare --model /path/to/model --qm_model /path/to/qm_model
```
## 可选参数
- `input` 指定图片输入，选填；如果不填，输入将是随机数
- `model` 输入编译前的模型路径，必填，用于与定点IR模型精度对比（如果是量化onnx编译，要求输入的是浮点模型）
- `qm_model` 输入前端编译后IR算子模型路径，必填
- `quant_json` onnx量化模型文件（量化onnx编译对比时添加）
- `output` 保存模型输入输出文件夹， 默认为output
- `param_dir` IR算子参数路径，必填
- `batch` 运行模型的batch_size, 默认为1
- `save_inter` 是否保存模型中间层输出，默认为不保存
- `gpu` 配置gpu个数，开启多gpu加速运行，默认为-1（cpu执行）
# 前端模型比对工具
- 提供对前端模型从原模型到编译到最后精度比对的全流程脚本
## 使用方式
```bash
python3 frontend_model_test.py /path/to/config --output xxx # 运行config列表中的所有模型, 并将结果保存在output指定路径
```
## 可选参数
- `config_path` 需要运行的模型列表设置json文件，必填
- `output` 指定前端编译输出的中间模型保存路径，默认为output
## 使用方式
```bash
python3 frontend_single_model_test.py --model /path/to/model --output xxx # 运行指定模型, 并将结果保存在output指定路径
```
## 可选参数
- `model` 编译模型路径（如果编译量化模型，则为量化模型路径）必填
- `quant_json` onnx量化模型文件（量化onnx编译对比时添加）
- `ori_model` 输入编译前的模型路径，必填，用于与定点IR模型精度对比（如果是量化onnx编译，要求输入的是浮点模型）
- `output` 指定前端编译输出的中间模型保存路径，默认为output
- `input` 指定前端模型和原始模型的输入文件路径，目前支持.bin、.npy、.pt数据格式
- `batch` 指定模型编译的batch_size, 默认为1
- `dtype` 指定编译模型的类型，目前支持int8、float16、float32，默认为float16
- `save_inter` 是否保存模型中间层输出，默认为不保存
- `pass_config_path` pass优化配置文件，用于自定义pass组合和参数设置，默认为None
## 使用方式
```bash
chmod +x frontend_build_run_compare.sh # 脚本增加可执行权限
./frontend_build_run_compare.sh --model /path/to/model # 执行脚本，根据实际情况传入参数
```
## 可选参数
- `model` <模型路径>
- `output` <输出目录>
- `quant_json` <量化json>
- `pass_config_path` <配置pass优化>
- `ori_model` <原始float32模型>
- `input_bin` <输入bin>
- `batch_size` <batch size>
- `dtype` <模型类型>
- `save_inter` <模型中间层输出>
- `gpu` <开启gpu加速运行>
# 单算子模型比对工具
- 提供单一onnx算子模型比对工具，用来验证算子转换的正确性
## 使用方式
```bash
python3 frontend_test_single_op_v2.py single_onnx_op_config/ --all # 运行全部算子
python3 frontend_test_single_op_v2.py single_onnx_op_config/xxx.json # 指定运行某一算子
```
## 可选参数
- `config_path` 单算子config文件路径, 如果运行的是单个算子，则路径指向具体算子文件；如果运行所有模型，则路径指向所有算子文件所在文件夹
- `--save_model` 是否保存onnx模型，默认为False
- `--save_dir` 保存onnx模型的路径，默认为output
- `--all` 是否运行所有模型

# 生成随机模型
## 作用
- 用于通过用户提供的config文件，生成指定模型结构
- 文件名：`gen_onnx_model.py`
## 使用方法
```bash
python3 gen_onnx_model.py -c /path/to/config.json -n model_name -s output -v op_version
```
## 可选参数
- `-c`, `--config_path`, 必填参数, 定义模型结构的config文件，样例文件见[two_conv.json](gen_onnx_model_config/two_conv.json), 该文件展示了如何生成参数为float32的两层Conv2d模型
- `-n`, `--model_name`, 必填参数，定义生成onnx模型文件的文件名
- `-s`, `--save_dir`, 选填参数，保存生成的onnx模型的路径，默认为output
- `-v`, `--version`, 选填参数，指定生成onnx模型所用opset版本，默认为14