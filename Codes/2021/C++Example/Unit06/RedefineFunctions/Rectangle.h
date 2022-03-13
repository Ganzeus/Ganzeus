#pragma once
#include "Shape.h"
//����Rectangle�࣬��Shape��̳�
class Rectangle : public Shape {
private:
	double width{ 1.0 };
	double height{ 1.0 };
public:
	Rectangle() = default;
	Rectangle(double w, double h, Color color_, bool filled_);

	double getWidth() const;	//const�����������޸Ķ����˽�г�Ա
	void setWidth(double w);
	double getHeight() const;
	void setHeight(double h);

	double getArea() const;

	string toString();
};