#include <iostream>

int main() {
	//�б��ʼ��������խ��
	int x{ 1 };
	std::cout << x << std::endl;

	//ǿ������ת����int->double;double->int
	std::cout << 1 / 2 << std::endl;
	std::cout << static_cast<double>(1) / 2 << std::endl;
	std::cout << static_cast<double>(1 / 2) << std::endl;

	std::cout << 1.0f / 2.f << std::endl;

	return 0;
}