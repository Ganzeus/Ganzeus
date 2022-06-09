#pragma once
//任务一：创建square类
class Square {
private:
	double side{ 1.0 };			//实例数据成员
	static int numberOfObjects;	//静态数据成员
public:
	double getSide() { return side;}
	void setSide(double side) { this->side = side; }
	Square(double side) {
		this->side = side;
		numberOfObjects++;
	}
	Square():Square(1.0){}
	double getArea() { return side * side; }
	static int getNumberOfObjects() { return numberOfObjects; }
	int getNumberOfObjectsNonStatic() { return numberOfObjects; }

};