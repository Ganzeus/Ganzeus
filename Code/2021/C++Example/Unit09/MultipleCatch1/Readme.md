### 捕获多个不同类型的异常

#### 1. 基于Vec3D类、RangeException异常类修改
	1.1 将Vec3D的维数组抽取出来
	1.2 将RangeException改为继承 out_of_range

#### 2. 添加ZeroException，当向量除以一个数为0时抛该异常
	该异常应继承 runtime_error

##### 3. 重载operator /(), 为Vec3D类添加标量除法（向量除以一个数）
	当除数为0.0时抛异常
	IEEE 754 Rules:
	x > 0.0 : x / 0.0 = INF
	x < 0.0 : x / 0.0 = -INF
	0.0 / 0.0 = NaN

	==注意：比较除数divisor 是否为0.0, 需要使用一些特殊技巧==

	divisor的绝对值减去0.0是否小于 std::numeric_limits<double>::epsilon()
