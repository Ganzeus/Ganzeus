# Conv2d
## 算子描述
- 卷积操作符消耗一个输入张量和一个滤波器，并计算输出。
## 输入
- input(必须)：输入张量，默认等于4维
- weight(必须)：滤波器参数，默认等于4维度
## 属性
- padding: [0, 4096]
- kernel_size: [1, 32], kernel_h * kernel_w <= 256
- strides: [1, 32]
- activation_type: 激活值类型（内置激活函数）
- activation_attr：激活属性（为什么默认为None）
- k, b 偏置(具体的含义)

## 输入限制
- weight_dtype为int8，则需要满足(kernel_r*kernel_s*Cin（对齐后的值）*weight_dtype)对齐32byte+256+ceil(ci/256)*32*8（分组卷积时才需要加Cin，且为对齐后的值））≤2368*64，上述值单位均为bit
- weight_dtype为int4，则需要满足(kernel_r*kernel_s*Cin（对齐后的值）*weight_dtype)对齐32byte*2（*2是表示两个ochl进行拼接）+256+ceil(ci/256)*32*8（分组卷积时才需要加Cin，且为对齐后的值））≤2368*64，上述值单位均为bit
- weight_dtype为fp16，则需要满足(kernel_r*kernel_s*Cin（对齐后的值）*weight_dtype)对齐32byte+256+ceil(ci/256)*32*8（分组卷积时才需要加Cin，且为对齐后的值））≤2368*64，上述值单位均为bit（具体原因是啥来着）
## 输出
- output: 输出张量，shape为4维度，dtype与输入相同
## 实现方式
### 若weight大小满足硬件限制
- 直接生成一个Conv IR
### 若weight大小超过硬件限制
- 先调用Split算子对weight和input在channel维度进行切分
- 切分后分别进行Conv运算，运算后的结果在channel维度进行对应元素相加
- 设置激活函数

# Dense
## 算子描述
- 算子在神经网络中用于实现全连接层（Dense Layer），也称为密集层。该层将每个输入与其权重矩阵相乘，并加上偏置（如果有），通常后接一个激活函数。Dense 层在处理非时序数据的深度学习模型中非常常见，尤其是在分类和回归问题中.
## 输入
- input(必须)：输入张量，默认等于4维
- weight(必须)：滤波器参数，默认等于4维度(常量)
## 属性
- activation_type: 激活值类型（内置激活函数）
- activation_attr：激活属性（为什么默认为None）
- k, b 偏置(具体的含义是什么)
## 输入限制
- 无要求
## 输出
- output: 输出张量，shape为4维度，dtype与输入相同
## 实现方式
- 直接生成一个DenseIR

