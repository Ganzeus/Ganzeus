#include <iostream>
using std::cout;
using std::endl;
/*
����1����д������չʾ��Ϊ��������noexcept��noexcept(true), noexcept(false) ������
����2��չʾnoexcept������������
����3����noexcept�������׳��쳣
����4��չʾnoexcept��Ϊ�������Ч��
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