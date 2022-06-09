#include <iostream>	//系统提供的头文件用尖括号
#include "Circle.h"	//程序员写的头文件用双引号

Circle::Circle() {
	radius = 1.0;
}

Circle::Circle(double radius_) {
	radius = radius_;
}

double Circle::getArea() {
	return (3.14 * radius * radius);
}
