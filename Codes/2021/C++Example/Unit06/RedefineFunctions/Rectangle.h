#pragma once
#include "Shape.h"
//创建Rectangle类，从Shape类继承
class Rectangle : public Shape {
private:
	double width{ 1.0 };
	double height{ 1.0 };
public:
	Rectangle() = default;
	Rectangle(double w, double h, Color color_, bool filled_);

	double getWidth() const;	//const：函数本身不修改对象的私有成员
	void setWidth(double w);
	double getHeight() const;
	void setHeight(double h);

	double getArea() const;

	string toString();
};