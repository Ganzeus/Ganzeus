### 自定义异常类

#### 展示内容如下：

##### 任务1：创建Vec3D类，用 array 保存向量成员；
##### 任务2：创建RangeException类
	定义构造函数
	RangeException(std::size_t dimension, const int index)

##### 任务3：实现Vec3D::operator[](const int index)
	当index越界时，抛出RangeException对象

##### 任务4：在主函数中创建Vec3D对象并调用[]制造越界问题
	捕获异常并输出异常中的信息
