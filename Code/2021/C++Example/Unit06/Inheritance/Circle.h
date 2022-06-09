#pragma once
#include "Shape.h"
//��ȫCircle�࣬��Shape�̳�
class Circle : public Shape {
	double radius;

public:
	Circle();
	Circle(double radius_, Color color_, bool filled_);
	double getArea();
	double getRadius() const;
	void setRadius(double radius);
};