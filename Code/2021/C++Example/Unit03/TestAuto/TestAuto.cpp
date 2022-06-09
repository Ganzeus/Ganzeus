#include <iostream>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;
auto max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	//auto变量必须在定义时初始化
	auto x = 3;
	auto y{ 42 };

	//定义一个auto序列的变量必须始终推导成同一类型
	auto x1{ 1 }, x2{ 2 };

	//如果初始化表达式是引用或const，则去除引用或const语义
	int y1{ 42 },&y2{ y1 };
	auto y3{ y2 };
	cout << typeid(y3).name() << endl;	//int

	//如果auto关键字带上&号，则不去除引用或const语义
	auto& z1{ y2 };
	cout << typeid(z1).name() << endl;	//int(引用)

	//初始化表达式为数组时，auto关键字推导类型为指针
	int p[3]{ 1,2,3 };
	auto p1 = p;
	cout << typeid(p1).name() << endl;	//int *

	//若表达式为数组且auto带上&，则推导类型为数组类型】
	auto& p2{ p };
	cout << typeid(p2).name() << endl;	//int [3]
	//C++14中，auto可以作为函数的返回值类型和参数类型
	cout << max(x1, x2) << endl;
	return 0;
}