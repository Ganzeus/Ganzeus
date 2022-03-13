#include <iostream>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;
auto max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	//auto���������ڶ���ʱ��ʼ��
	auto x = 3;
	auto y{ 42 };

	//����һ��auto���еı�������ʼ���Ƶ���ͬһ����
	auto x1{ 1 }, x2{ 2 };

	//�����ʼ�����ʽ�����û�const����ȥ�����û�const����
	int y1{ 42 },&y2{ y1 };
	auto y3{ y2 };
	cout << typeid(y3).name() << endl;	//int

	//���auto�ؼ��ִ���&�ţ���ȥ�����û�const����
	auto& z1{ y2 };
	cout << typeid(z1).name() << endl;	//int(����)

	//��ʼ�����ʽΪ����ʱ��auto�ؼ����Ƶ�����Ϊָ��
	int p[3]{ 1,2,3 };
	auto p1 = p;
	cout << typeid(p1).name() << endl;	//int *

	//�����ʽΪ������auto����&�����Ƶ�����Ϊ�������͡�
	auto& p2{ p };
	cout << typeid(p2).name() << endl;	//int [3]
	//C++14�У�auto������Ϊ�����ķ���ֵ���ͺͲ�������
	cout << max(x1, x2) << endl;
	return 0;
}