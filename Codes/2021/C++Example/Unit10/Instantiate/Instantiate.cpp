#include <iostream>
#include <string>
using namespace std::string_literals;

// ����ģ�嶨��
template <typename T>
T max(T x, T y) {
	return (x > y ? x : y);
}
// ��ʽʵ����������
template <int> int max(int, int);

int main() {
	// ������ʽʵ�����ĺ���
	std::cout << "max(1, 2): " << max(1, 2) << std::endl;

	// ������ʵ����
	std::cout << "max(2.9, 1.0) : " << max(2.9, 1.0) << std::endl;

	// �ַ�ʵ����
	std::cout << "max('A', 'D') : " << max('A', 'D') << std::endl;

	// �ַ���������ʵ����
	std::cout << R"(max("ABC", "ABD") : )" << max("ABC", "ABD") << std::endl;
	std::cout << R"(max("ABD", "ABC") : )" << max("ABD", "ABC") << std::endl;

	// std::string����ʵ����
	//std::cout << R"(max("ABC"s, "ABD"s) : )" << max("ABC"s, "ABD"s) << std::endl;
	//std::cout << R"(max("ABD"s, "ABC"s) : )" << max("ABD"s, "ABC"s) << std::endl;

	// ���ֿռ��ͻ����


}