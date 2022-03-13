//任务二：通过类名/对象名调佣静态成员函数

#include <iostream>
#include "Square.h"
#include <cassert>

int Square::numberOfObjects = 10;//可以不赋值
int main() {
	Square s1;
	std::cout << s1.getNumberOfObjects() << std::endl;
	assert(s1.getNumberOfObjects() == 11);
	Square s2{ 20.0 };
	std::cout << Square::getNumberOfObjects() << std::endl;
	//非静态成员函数访问静态成员
	std::cout << s2.getNumberOfObjectsNonStatic() << std::endl;

	//std::cout << Square::getNumberOfObjectsNonStatic() << std::endl;
	return (0);
}