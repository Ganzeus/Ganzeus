#include <iostream>

//����ṹ�壬����double��int��Ա
struct S {
	double d1{ 1.0 };
	int i2{ 32 };
};
//�����࣬����int���ַ������Ա
class C {
public:
	int i2{ 1 };
	char c[3]{ 'a','b','\0' };
};
int main() {
	//����ṹ��������
	S s;
	C c;
	//�󶨽ṹ�����
	auto [d1, i1] {s};

	//��������ʽ��������Ա
	auto& [i2, c2] {c};
	//����󶨵ĳ�Ա

	std::cout << "s.d1= " << d1 << "s.i1= " << i1 << std::endl;
	std::cout << "c.i2= " << i2 << "c.c2= " << c2 << std::endl;
	return 0;
}