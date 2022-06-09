#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
//����Shape/Circle/Rectangle����
//�������������û��ຯ��toString()
int main() {
	Shape s1{ Color::blue, false };
	Circle c1{ 3.9, Color::green, true };
	Rectangle r1{ 4.0, 1.0, Color::white, true };

	std::cout << s1.toString() << std::endl;
	std::cout << c1.toString() << std::endl;
	std::cout << r1.toString() << std::endl;

	std::cout << "c1 area: " << c1.getArea() << std::endl;
	std::cout << "r1 area: " << r1.getArea() << std::endl;
	return 0;
}