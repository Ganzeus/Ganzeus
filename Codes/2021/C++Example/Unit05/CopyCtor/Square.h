#pragma once
#include <iostream>
//����һ����ӿ������캯����������������������Ϣ
class Square {
private:
	double side{ 1.0 };			//ʵ�����ݳ�Ա
	static int numberOfObjects;	//��̬���ݳ�Ա

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