//�������ͨ������/��������Ӷ��̬��Ա����

#include <iostream>
#include "Square.h"
#include <cassert>

int Square::numberOfObjects = 10;//���Բ���ֵ
int main() {
	Square s1;
	std::cout << s1.getNumberOfObjects() << std::endl;
	assert(s1.getNumberOfObjects() == 11);
	Square s2{ 20.0 };
	std::cout << Square::getNumberOfObjects() << std::endl;
	//�Ǿ�̬��Ա�������ʾ�̬��Ա
	std::cout << s2.getNumberOfObjectsNonStatic() << std::endl;

	//std::cout << Square::getNumberOfObjectsNonStatic() << std::endl;
	return (0);
}