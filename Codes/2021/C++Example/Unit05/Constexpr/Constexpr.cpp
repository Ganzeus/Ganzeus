#include <iostream>
#include <array>
#include <cassert>	//ʹ��assert()�����������ͷ�ļ�

using namespace std;

//����1���õݹ����factorial,��assert���3�Ľ׳�
//����2����factorial��ɳ������ʽ����static-assert���3�Ľ׳�
//����3������factorial(4)��С������
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