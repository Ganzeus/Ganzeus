# 背景
增加对现有qm算子实现方法说明，限制等
# VP算子
## Clip
### Clip-v1
- name: Clip
#### 算子描述
对输入张量进行截断
#### 输入
必须是三输入，否则报错
- input: 需要进行clip的tensor
- min：最小值，标量，常量输入
- max: 最大值，标量，常量输入
#### 输出
- output: clip后的输出，shape与input保持一致
#### 备注
- 必须是三输入，暂不支持非三输入情况（onnx支持）
- min和max值不能相等，否则报错
- min可以大于max的值，此时输出结果元素值与max相等

## HardSigmoid
- name: HardSigmoid
### 算子描述
HardSigmoid获取一个输入张量（Tensor）并产生一个输出张量（Tensor），其中HardSigmoid函数y=max（0，min（1，alpha*x+beta））按元素应用于张量。

### 输入
- input(必须): 输入张量，默认小于等于4维
- alpha: 常量，标量，FLOAT32，默认值0.2
- beta: 常量，标量，FLOAT32，默认值0.5

### 输出
- output: 输出张量，shape与input保持一致

## Cast
- name: Cast
### 算子描述
Cast获取一个输入张量（Tensor）并产生一个输出张量（Tensor），对于输入张量的每一个元素，将其转换为目标数据类型，可能产生误差和溢出。

### 输入
- input(必须): 输入张量，默认小于4维, 数据类型必须是`uint8`,`uint16`,`int8`,`int16`,`float16`中的一个
- output_dtype(必须): 指定输出数据类型，数据类型必须是`int8`,`int16`,`float16`中的一个

### 输出
- output: 输出张量，shape与input保持一致，输出数据类型与output_dtype一致

## L2Norm
- name: l2norm
### 算子描述
L2Norm算子获取一个输入张量（Tensor）并产生一个输出张量（Tensor），对于输入张量channel维度的每一个元素，均进行L2归一化计算。

### 输入
- input(必须): 输入张量，默认小于等于4维

### 输出
- output: 输出张量，shape与input保持一致

### 备注
- qm_ops中定义的L2Norm算子只支持对输入张量channel维度（输入layout的第二维）进行L2归一化.

## Min
- name: min
### 算子描述
Min算子获取一个输入张量（Tensor）并产生一个输出张量（Tensor），以指定axis为轴求其余维度对应位置的最小值，输出Tensor对应axis维度变为1。

### 输入
- input(必须): 输入张量，默认小于等于4维
- axis(必须)：输入张量进行比对的轴，输出之后对应位置维度变为1

### 输出
- output: 输出张量，输出axis位置变为1，其余维度保持不变；输出dtype与输入相同

## Max
- name: max
### 算子描述
Max算子获取一个输入张量（Tensor）并产生一个输出张量（Tensor），以指定axis为轴求其余维度对应位置的最大值，输出Tensor对应axis维度变为1。

### 输入
- input(必须): 输入张量，默认小于等于4维
- axis(必须)：输入张量进行比对的轴，输出之后对应位置维度变为1

### 输出
- output: 输出张量，输出axis位置变为1，其余维度保持不变；输出dtype与输入相同

## ReduceL1
### 算子描述
ReduceL1算子获取一个输入张量(Tensor), 产生一个输出张量(Tensor), 求取指定axes维度上元素的L1距离。若keepdims为True，输出Tensor对应shape与输入Tensor相同，对应axes维度变为1；若keepdims为False，则对应axes消失
### 输入
- input(必须)：输入张量，默认小于等于4维度
- axes(必须)：list[ints]，需要计算L1的维度
- keepdims(必须)：bool, 输出Tensor是否需要保持维度
### 输出
- output:输出张量，若keepdims为True，输出Tensor对应shape与输入Tensor相同，对应axes维度变为1；若keepdims为False，则对应axes消失。
### 实现方式
1. 调用Abs算子，求每个元素的绝对值
2. 调用Permute算子，将axes中需要计算L1的维度放到尾部
3. 调用Reshape算子，将所有需要加和的元素，都放到最后一维度
4. 调用acc_tree_group, 队最后一维的数据进行累加
5. 调用Reshape, 恢复output_shape
### 备注
- 当前算子将求元素绝对值的部分放在了ReduceL1算子的外面，需要更正

## ThresholdedRelu
### 算子描述
`ThresholdedRelu`算子获取一个输入张量(Tensor), 产生一个输出张量(Tensor). 对于输入张量上的每个元素，若元素值大于`alpha`（阈值），则保持不变，若元素小于等于`alpha`,则输出0.
### 输入
- input(必须)：输入张量，默认小于等于4维度
- alpha(必须)：阈值
### 输出
- output:输出张量，shape与输入张量保持一致。
### 实现方式
1. 采用分段函数拟合实现
1. 输入bp(断点)，k(斜率)，b(截距)
1. 调用`param_gen`模块生成参数
1. 调用`mul_gp`模块进行元素乘
1. 调用`sumsub_gp1`模块进行元素加

## Relu
### 算子描述
`Relu`算子获取一个输入张量(Tensor), 产生一个输出张量(Tensor). 对于输入张量上的每个元素，若大于0则输出原值；若小于等于0则变为0.以实现对tensor的非线性变化
### 输入
- input(必须)：输入张量，默认小于等于4维度
### 输出
- output:输出张量，shape与输入张量保持一致。
### 实现方式
1. 调用vp模块中的relu模块实现

## LeakyRelu
### 算子描述
`LeakyRelu`算子获取一个输入张量(Tensor), 产生一个输出张量(Tensor). 对于输入张量上的每个元素，若大于0则输出原值；若小于等于0则对该元素乘以一个小于1的系数.以实现对tensor的非线性变化
### 输入
- input(必须)：输入张量，默认小于等于4维度
### 输出
- output:输出张量，shape与输入张量保持一致。
### 实现方式
1. 调用vp模块中的fp32_mul模块实现，设置act_mode为relu

## ReluX
### 算子描述
`ReluX`算子获取一个输入张量(Tensor), 产生一个输出张量(Tensor). 对于输入张量上的每个元素，若大于max_value则输出max_value(max_value大于等于0)， 若大于0且小于max_value则输出原值；若小于等于0则输出0.以实现对tensor的非线性变化
### 输入
- input(必须)：输入张量，默认小于等于4维度
### 输出
- output:输出张量，shape与输入张量保持一致。
### 实现方式
1. 调用compare_group，将大于max_value的值变为max_value
2. 调用relu模块，将小于等于0的值变为0

## Not
### 算子描述
- 算子获取一个输入张量，产生一个输出张量，对输入张量的每个元素进行逐元素的逻辑非操作
### 输入
- input(必须)：输入张量，默认小于等于4维度
### 输出
- output:输出张量，shape与输入张量保持一致。
### 实现方式
1. 采用分段函数拟合实现
    - 分三段函数实现
    - 分别是 $[-inf, 0)$, $[0, 0+eps)$, $[0+eps, +inf)$ 
1. 输入bp(断点)，k(斜率)，b(截距)
1. 调用`param_gen`模块生成参数
1. 调用`mul_gp`模块进行元素乘
1. 调用`sumsub_gp1`模块进行元素加
### 注意事项
- 分段拟合在点的分配上遵循左闭右开原则
- 断点处的数值选择需要注意拟合目标函数在断点位置的连续性

## Tanh
### 算子描述
- 算子获取一个输入张量，产生一个输出张量，逐元素计算输入张量的双曲正切值
### 输入
- input(必须)：输入张量，默认小于等于4维度
### 输出
- output:输出张量，shape与输入张量保持一致。
### 实现方式
- 由算法提供分段拟合的断点，k值，和b值
- 采用64段分段拟合实现
### 是否对形状敏感
- 否

## Sum
### 算子描述
- 获取一个四维输入张量，并指定一个axis轴；求指定轴位置上所有元素之和。计算后的向量形状有可能发生变化
### 输入
- input(必须)：输入张量，默认小于等于4维
- axes: 对元素进行求和的轴
### 输出
- output:输出张量，需要求和的轴形状变为1，输出维度可能比输入维度小
### 实现方式
- 利用vp模块的`acc_tree_group`累加模块实现
- 对于输入axes为`c`和`chw`时，将模式调为`tree`模式
- 对于输入axes为`w`和`hw`时候，将模式调为`acc`模式
- 如果axes不为上述情况，则通过permute调整到对应的轴后再计算
### 是否形状敏感
- 是

## Sigmoid
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素根据Sigmoid公式计算其激活值
$$\sigma(x) = \frac{1}{1 + e^{-x}}$$  
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素做sigmoid操作
### 实现方式
- 利用vp模块的`param_gen`功能实现
- 在-10到10的范围里取64个点，进行拟合实现，得到斜率k和截距b
- 调用`get_fp32_mul_group`乘k
- 调用`get_fp32_sum_sub_group1`进行加b操作
### 是否形状敏感
- 否

## Erf
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素根据高斯误差公式计算其误差值
$$\text{erf}(x) = \frac{2}{\sqrt{\pi}} \int_{0}^{x} e^{-t^2} dt$$
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素做Erf求高斯误差操作
### 实现方式
- 利用vp模块的`param_gen`功能实现
- 在-5到5的范围里取64个点（63个断点），进行拟合实现，得到斜率k和截距b
- 调用`get_fp32_mul_group`乘k
- 调用`get_fp32_sum_sub_group1`进行加b操作
### 是否形状敏感
- 否

## Gelu
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素Gelu公式计算其激活值
$$\text{GELU}(x) = x \times \frac{1}{2} \left[1 + \text{erf}\left(\frac{x}{\sqrt{2}}\right)\right]$$
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素求Gelu激活值
### 实现方式
- 利用vp模块的`param_gen`功能实现
- 在-5到4的范围里取64个点（63个断点），进行拟合实现，得到斜率k和截距b
- 调用`get_fp32_mul_group`开启线性拟合功能
- 调用`get_fp32_sum_sub_group1`进行加b操作
### 是否形状敏感
- 否

## Elu
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素用Elu公式计算其激活值
$$\text{ELU}(x) = \begin{cases} 
x & \text{if } x > 0 \\
\alpha (e^x - 1) & \text{if } x \leq 0
\end{cases}$$
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素求Elu激活值
### 实现方式
- 利用vp模块的`param_gen`功能实现
- 在-5到0.5的范围里取32个点（31个断点），进行拟合实现，得到斜率k和截距b
- 由于Elu在负数阶段是近似指数函数, 在非负数阶段是线性函数, 故在取点时采用`np.geomspace` 生成对数刻度上的等间隔数列
- 调用`get_fp32_mul_group`开启线性拟合功能
- 调用`get_fp32_sum_sub_group1`进行加b操作
### 是否形状敏感
- 否

## Selu
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素用Selu公式计算其激活值
$$\text{SELU}(x) = \begin{cases} 
x & \text{if } \gamma * x > 0 \\
\alpha (e^x - 1) & \text{if } x \leq 0
\end{cases}$$
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素求Selu激活值
### 实现方式
- 利用vp模块的`param_gen`功能实现
- 在-5到0.5的范围里取32个点（31个断点），进行拟合实现，得到斜率k和截距b
- 由于Selu在负数阶段是近似指数函数, 在非负数阶段是线性函数, 故在取点时采用`np.geomspace` 生成对数刻度上的等间隔数列
- 调用`get_fp32_mul_group`开启线性拟合功能
- 调用`get_fp32_sum_sub_group1`进行加b操作
### 是否形状敏感
- 否

## Softplus
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素用SoftPlus公式计算其激活值
$$\text{SoftPlus}(x) = \ln(1 + e^x)$$
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素求SoftPlus激活值
### 实现方式
- 共分为九个模块实现, 假设原始输入为 $x$, 第$i$个模块输出为 $y_i$
- 模块一: 调用`fp32_mul_group`, 计算 $y_1 = x* \log_2{e}$
- 模块二: 调用`fp32_floor_group`, 计算 $y_2 = floor(y_1)$, 得到 $y_1$ 的整数部分
- 模块三: 调用`fp32_sum_sub_group0`, 计算 $y_3 = y_1 - y_2$, 得到 $y_1$ 的小数部分
- 模块四: 调用`fp32_mul_group`和`fp32_sum_sub_group1`, 线性拟合实现: $y_4 = 2^{y_3}$  
- 模块五: 调用`fp32_shift_group`和`post_cal`, 计算 $2^e = y_4^{y_2}$, $y_5 = 2^e+1$; 到这里就实现了原公式中的 $1 + e^x$ 的部分, 下面实现ln部分
- 模块六: 调用`fp32_dispart_group`, 得到 $y_5$ 的指数部分
- 模块七: 调用`fp32_dispart_group`, 得到 $y_5$ 的尾数部分, $y_5 = y_7 * 2^{y_6}$
- 模块八: 调用`fp32_mul_group`和`fp32_sum_sub_group1`, 线性拟合实现: $y_8 = \log_2{y_7}$
- 模块九: 调用`fp32_sum_sub_group0`和`fp32_post_cal`, 实现 $y_9 = (y_6 + y_8) * \ln{2}$; 到这里就完全实现了 $\ln(1 + e^x)$
### 是否形状敏感
- 否

## Mish
### 算子描述
- 获取一个四维输入张量，对张量中的每个元素用Mish公式计算其激活值
$$\text{Mish}(x) = x \cdot \tanh(\ln(1 + e^x))$$
### 输入
- input(必须)：输入张量，默认小于等于4维
### 输出
- output: 输出张量，对输入张量的每个元素求Mish激活值
### 实现方式
- 共分为11个模块实现, 假设原始输入为 $x$, 第$i$个模块输出为 $y_i$
- 前9个模块与SoftPlus一致,计算SoftPlus的值
- 模块10: 调用`fp32_mul_group`和`fp32_sum_sub_group1`, 线性拟合实现$y_10 = \tanh(y_9)$
- 模块11: 调用`fp32_mul_group`, 线性拟合实现$y_11 = \tanh(y_9)$
### 是否形状敏感
- 否

## L1Norm
### 算子描述
- 获取一个四维输入张量, 对张量中的指定轴求L1归一化
$$ x_i' = \frac{x_i}{\sum_{j=1}^{n} |x_j|} $$
### 输入
- input(必须)：输入张量，默认小于等于4维
- axis(轴属性): 做归一化的轴, 无默认值
### 输出
- output: 输出张量，对输入张量中的指定轴求L1归一化
### 实现方式
- 模块一: 若轴不为1(NCHW的C维), 则将目标归一化的轴,调用transpose算子转置到C维, 得到$y_1$
- 模块二: 对整个tensor求绝对值, $y_2 = abs(y_1)$
- 模块三: 依次调用`acc_tree_group`, `fp32_mul_group`, `square_root_div`模块, 求得$y_2$的倒数; $y_3 = \frac{1}{\sqrt{y_2^{2}}}$ 
- 模块四: 调用`fp32_mul_group`, 求$y_4 = y_1 * y3$
- 模块五: 若之前进行transpose操作, 这里需要还原
### 是否形状敏感
- 是

## L2Norm
### 算子描述
- 获取一个四维输入张量, 对张量中的指定轴求L2归一化
$$ \text{L2 归一化后的向量} = \frac{\mathbf{x}}{\|\mathbf{x}\|_2} = \frac{x_i}{\sqrt{x_1^2 + x_2^2 + \cdots + x_n^2}} $$
### 输入
- input(必须)：输入张量，默认小于等于4维
- axis(轴属性): 做归一化的轴, 无默认值
### 输出
- output: 输出张量，对输入张量中的指定轴求L2归一化
### 实现方式
- 模块一: 若轴不为1(NCHW的C维), 则将目标归一化的轴,调用transpose算子转置到C维, 得到$y_1$
- 模块二: 依次调用`acc_tree_group`, `fp32_mul_group`, `square_root_div`模块, 求得$y_1$的倒数; $y_2 = \frac{1}{\sqrt{y_1^{2}}}$ 
- 模块三: 调用`fp32_mul_group`, 求$y_3 = y_1 * y2$
- 模块四: 若之前进行transpose操作, 这里需要还原
### 是否形状敏感
- 是

## Abs
### 算子描述
- 获取一个四维输入张量, 对张量中的每个元素求绝对值
### 输入
- input(必须): 输入张量, 默认小于等于4维
### 输出
- output: 输出张量, 对输入张量中的每个元素求得绝对值
### 实现方式
- 模块一: 调用`param_gen`模块生成线性拟合参数
- 模块二: 调用`fp32_mul_group`的`linear_approximation`功能实现线性拟合系数相乘
- 模块三: 调用`fp32_sum_sub_group1`模块, 实现线性系数相加
### 是否形状敏感
- 否

## BatchNorm
### 算子描述
- 获取一个四维张量, 利用给定的样本均值和方差对张量进行BatchNorm操作, 该操作是逐通道进行的(Channel维度)
### 输入
- input(必须): 输入张量, 默认等于4维, NCHW排布
- k: BatchNorm归一化系数, shape为:[1, C, 1, 1]
- b: BatchNorm归一化偏移量, shape为:[1, C, 1, 1]
### 输出
- output: 输出张量, 输出BatchNorm归一化后的值, shape和dtype与输入相同
### 实现方式
- 模块一: 调用`fp32_mul_group`的`vector_tensor`,`others`模式, 乘系数k
- 模块二: 调用`fp32_sum_sub_group`模块, 加上偏移量b
### 是否形状敏感
- 是: 与channel所在维度相关

## Acos
### 算子描述
- 获取一个四维张量, 求张量中每个元素的arccos值
### 输入
- input(必须): 输入张量,默认等于四维, NCHW排布
### 输出
- output: 输出张量, 对输入张量中的每个元素求arccos值
### 实现方式
- 模块一: 调用`param_gen`生成线性拟合参数k, b, 断点数为64
- 模块二: 调用`fp32_mul_group`乘以线性拟合参数k,
- 模块三: 调用`fp32_sum_sub_group1`加上偏移量b
### 是否形状敏感
- 否

## Asin
### 算子描述
- 获取一个四维张量, 求张量中每个元素的arcsin值
### 输入
- input(必须): 输入张量,默认等于四维, NCHW排布
### 输出
- output: 输出张量, 对输入张量中的每个元素求arcsin值
### 实现方式
- 模块一: 调用`param_gen`生成线性拟合参数k, b, 断点数为64
- 模块二: 调用`fp32_mul_group`乘以线性拟合参数k,
- 模块三: 调用`fp32_sum_sub_group1`加上偏移量b
### 是否形状敏感
- 否

## Atan
### 算子描述
- 获取一个四维张量, 求每个元素的arctan值
### 输入
- input(必须): 输入张量, 默认等于四维, NCHW排布
### 输出
- output: 输出张量, 对输入张量中的每个元素求arctan值
### 实现方式
- 模块一: 调用`param_gen`生成线性拟合参数k, b, 断点数为64, 取值范围是(-100, 100)
- 模块二: 调用`fp32_mul_group`乘以线性拟合参数k,
- 模块三: 调用`fp32_sum_sub_group1`加上偏移量b
### 是否形状敏感
- 否

## Shrink
### 算子描述
- 获取一个四维张量, 根据Shrink公式,逐元素求值
$$ \text{Shrink}(x, \lambda) = \text{sign}(x) \cdot \max(\lvert x \rvert - \lambda, 0)  $$
### 输入
- input(必须): 输入张量, 默认等于四维, NCHW排布
### 输出
- output: 输出张量, 对输入张量中的每个元素求Shrink值
### 实现方式
- 模块一: 调用`param_gen`生成线性拟合参数k, b, 断点数为32, 取值范围是(-lambda, lambda)
- 模块二: 调用`fp32_mul_group`乘以线性拟合参数k,
- 模块三: 调用`fp32_sum_sub_group1`加上偏移量b
### 是否形状敏感
- 否

## ThresholdedRelu
### 算子描述
- 获取一个四维张量, 根据ThresholdedRelu公式, 逐元素求值, 其中 $\theta$ 是指定阈值
$$
\text{ThresholdedReLU}(x) = 
\begin{cases} 
x & \text{if } x > \theta \\
0 & \text{otherwise}
\end{cases}
$$
### 输入
- input(必须): 输入张量, 默认等于四维, NCHW排布
### 输出
- output: 输出张量, 对输入张量中的每个元素求ThresholdedRelu值
### 实现方式
- 模块一: 调用`param_gen`生成线性拟合参数k, b, 断点数为32, 分为两个线性阶段分别求参数
- 模块二: 调用`fp32_mul_group`乘以线性拟合参数k,
- 模块三: 调用`fp32_sum_sub_group1`加上偏移量b
### 是否形状敏感
- 否

## NumApprox
### 算子描述
- 获取一个四维张量, 对张量内的每个元素进行数值取整，具体取整方式由`round_type`属性决定, `round_type`只支持（`round`, `ceil`, `floor`）三种取整方式
### 输入
- input(必须): 输入张量, 默认等于四维, NCHW排布
### 输出
- output: 输出张量, 对输入张量中的每个元素按照`round_type`属性要求进行数值取整
### 实现方式
- 模块一: 调用`post_cal`, 根据`round_type`属性进行数值取整.注: 调用`post_cal`方法（无论是`round`, `ceil`, `floor`）得到的输出一定是定点数
- 模块二: 将定点数转换为目标输出数据类型
### 是否形状敏感
- 否

# 组合类VP算子
- 由其他VP算子组合而成的算子
## HardSwish
- name: HardSwish
- 组合：Mult + HardSigmoid
### 算子描述
HardSwish获取一个输入张量（Tensor）并产生一个输出张量（Tensor），其中HardSwish函数y=x * max（0，min（1，alpha*x+beta））按元素应用于张量, 其中`alpha`固定为1/6, `beta`固定为0.5

### 输入
- input(必须): 输入张量，默认小于4维

### 输出
- output: 输出张量，shape与input保持一致

