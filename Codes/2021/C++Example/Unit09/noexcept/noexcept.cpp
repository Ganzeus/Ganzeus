#include <iostream>
using std::cout;
using std::endl;
/*
任务1：编写函数，展示作为声明符的noexcept，noexcept(true), noexcept(false) 的区别。
任务2：展示noexcept不能区分重载
任务3：在noexcept函数中抛出异常
任务4：展示noexcept作为运算符的效果
*/
void foo() noexcept { throw 1; }
//void foo(){}
void tao() noexcept(1) {}
void zen() noexcept(1 - 1) {}
int main() {
	cout << "foo() noexcept : " << noexcept(foo()) << endl
		//<< "foo() : " << noexcept(foo()) << endl

		<< "tao() noexcept(1) : " << noexcept(tao()) << endl
		<< "zen() noexcept(1-1) : " << noexcept(zen()) << endl;
}