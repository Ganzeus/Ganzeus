#pragma once
#include <iostream>
//任务一：添加拷贝构造函数、析构函数，添加输出信息
class Square {
private:
	double side{ 1.0 };			//实例数据成员
	static int numberOfObjects;	//静态数据成员

public:
	Square() :Square(1.0) {}
	Square(double side) {
		this->side = side;
		numberOfObjects++;
	}
	Square(Square& s) {
		this->side = side;
		numberOfObjects++;
		std::cout << "Square(const Square&) is invoked" << std::endl;
	}

	double getSide() { return side; }
	void setSide(double side) { this->side = side; }
	double getArea() { return side * side; }
	static int getNumberOfObjects() { return numberOfObjects; }
	int getNumberOfObjectsNonStatic() { return numberOfObjects; }

	~Square() {
		numberOfObjects--;
	}
};