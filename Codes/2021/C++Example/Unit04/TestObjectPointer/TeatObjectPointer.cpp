#include <iostream>
#include "CIrcle.h"

int main() {
	auto* c1 = new Circle{ 1.0 };
	Circle c3{ 2.0 };
	auto c2 = &c3;

	std::cout << (*c1).getArea() << std::endl;
	std::cout << c2->getArea() << std::endl;

	auto c5 = new Circle[3]{ 1.0,2.0,3.0 };
	for (int i = 0; i < 3; i++) {
		std::cout << c5[i].getArea() << std::endl;
	}

	//for (auto x : c5) {	//for-each循环中的"范围"必须是集合数据类型（数组/容器）
	//	std::cout << x.getArea() << std::endl;
	//}

	delete c1;
	delete[] c5;
	c1 = c5 = nullptr;

	delete c1;
	return 0;
}