// 任务4：在主函数中创建Vec3D对象并调用[]制造越界问题
// 捕获异常并输出异常中的信息
#include <iostream>
#include <exception>
#include "Vec3D.h"
using std::cout;
using std::endl;

int main() {
	Vec3D v1{ 1.2, 3.2, 4.3 };
	try {
		cout << v1[4] << endl;
	}
	catch (std::exception& e) {
		cout << "Exception: " << e.what() << endl;
		if (typeid(e) == typeid(RangeException)) {	// 如果e是RangeException类型
			auto r = dynamic_cast<RangeException&>(e);	// 类型转换
			cout << "Vector dimension: " << r.getDimension() << endl;
			cout << "Index: " << r.getIndex() << endl;
		}
	}
}