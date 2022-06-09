#include <iostream>
#include <array>
#include <cassert>	//使用assert()断言须包含本头文件

using namespace std;

//任务1：用递归计算factorial,用assert检查3的阶乘
//任务2：将factorial变成常量表达式，用static-assert检查3的阶乘
//任务3：创建factorial(4)大小的数组
constexpr int factorial(int n) {
	if (n == 0) {
		//return 2;	//error
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	//int x = 3;
	//auto f = factorial(x);

	static_assert(factorial(4) == 24, "factorial(4) should be 24");

	array<int, factorial(4)> a;
	cout << a.size();
	//assert(f == 6);
	return 0;
}