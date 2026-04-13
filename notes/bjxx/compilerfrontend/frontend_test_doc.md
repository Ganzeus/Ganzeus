# 背景
- 本文档主要目的是为了介绍`compiler_frontend940下各测试脚本使用说明`
# frontend_test_single_op_v2 单算子转换测试脚本使用说明
## Quick Start
```shell
# 运行单个算子测试config
python frontend_test_single_op_v2.py single_onnx_op_config/xxx.json

# 运行全部算子测试config
python frontend_test_single_op_v2.py single_onnx_op_config/ --all
```
## 增加新的算子config.json
- 建议在`single_onnx_op_config`文件夹下，创建单独的json文件。一个算子，一个json
- 这样的好处是：
    - 各算子config之间互相独立，修改或增加其中一个，不会影响另一个
    - 方便查找所需要的算子config
    - 方便单独测试某个指定算子