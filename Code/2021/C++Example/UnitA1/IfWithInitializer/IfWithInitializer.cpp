/* This program needs a C++17_comformable compiler
 * ��������ʹ�÷���C++17��׼�ı���������
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
//��дһ���´�С�ĳ���
int main() {
	// �����ʾ��Ϣ���������ķ�Χ
	std::cout << "��������0-100�������...\n";
	//�����ʾ��Ϣ�����û���������
	std::cout << "���������������";
	//��������������û�������Ϣ
	auto x{ 0 };
	std::cin >> x;
	//������������ж��û�����Ĵ�С����ʾ�û��´���/��С��/������
	//rand(); <cstdlib>
	if (int z = rand() % 100; x > z) {
		std::cout << "��µ����ˣ��ҵ�����" << z << std::endl;
	}
	else if (x < z) {
		std::cout << "���С�ˣ��ҵ�����" << z << std::endl;
	}
	else {
		std::cout << "��¶��ˣ�" << std::endl;
	}

	return 0;
}