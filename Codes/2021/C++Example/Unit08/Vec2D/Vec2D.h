#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <istream>
#include <ostream>
class Vec2D
{
	double x_;
	double y_;
public:
	Vec2D();
	Vec2D(double x, double y);
	// 将向量转换为字符串形式表示
	std::string toString();
	// 向量加法
	Vec2D add(const Vec2D& secondVec2D);
	Vec2D operator+(const Vec2D& secondVec2D);
	// 向量和数值的加法
	Vec2D add(double numeral);
	Vec2D operator+(const double numeral);
	// +=
	Vec2D operator+=(const Vec2D& secondVec2D);	// 两端都是向量

	// 向量减法
	Vec2D subtract(const Vec2D& secondVec2D);
	Vec2D subtract(double numeral);
	Vec2D operator -(const Vec2D& secondVec2D);
	Vec2D operator -(double numeral);
	// -=
	Vec2D operator -=(const Vec2D& secondVec2D);
	// 向量点积
	double dot(const Vec2D& secondVec2D);
	double operator *(const Vec2D& secondVec2D);
	// 向量数乘
	Vec2D multiply(double multiplier);
	Vec2D operator *(double multiplier);
	friend Vec2D operator *(double multiplier, Vec2D vec2d);
	// 向量求负值
	Vec2D negative();
	Vec2D operator-();
	// 向量自增1
	Vec2D& increase();
	Vec2D& operator++();	// ++a
	Vec2D operator++(int dummy); // a++
	// 向量自减1
	Vec2D& decrease();
	// 读取或修改向量元素
	double& at(const int index);
	double& operator[](const int& index);
	// 求向量的范数（长度）
	double magnitude();
	operator double();
	// 求向量与x+轴的夹角
	double direction();
	// 比较两个向量的长度。如果firstVec2D小于secondVec2D, 返回-1，若大于则返回1，若相等则返回0
	int compareTo(Vec2D secondVec2D);
	// 流操作运算符
	friend std::ostream& operator<<(std::ostream& os, const Vec2D& v);
	friend std::istream& operator>>(std::istream& is, Vec2D& v);
};

