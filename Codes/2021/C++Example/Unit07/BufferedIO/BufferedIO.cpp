#include <iostream>

int main() {
	// �õ�cin����Ļ�����ָ��
	auto p = std::cin.rdbuf();

	// �Ӽ��̶����ַ��������������������ַ��ڻ�����
	auto x = std::cin.peek();	//peek����ֻ������������

	std::cout << "x = " << x << std::endl;

	// ��ʾ���������ַ�����
	auto count = p->in_avail();
	std::cout << "There are " << p->in_avail() << " characters in the buffer." << std::endl;

	// �ѻ��������ַ���ȡ��������ʾ
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << ": " << std::cin.get() << std::endl;
	}
	std::cin.get();
	return 0;
}