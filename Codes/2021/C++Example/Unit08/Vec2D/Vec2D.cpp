#include "Vec2D.h"

Vec2D::Vec2D() {

}
Vec2D::Vec2D(double x, double y) {
	x_ = x;
	y_ = y;
}


// 将向量转换为字符串形式表示
std::string Vec2D::toString()
{
	// TODO: 在此处添加实现代码.
	return std::string("(" + std::to_string(x_) + ",	" + std::to_string(y_) + ")");
}


// 向量加法
Vec2D Vec2D::add(const Vec2D& secondVec2D)
{
	// TODO: 在此处添加实现代码.
	return Vec2D(x_ + secondVec2D.x_, y_ + secondVec2D.y_);
}
Vec2D Vec2D::operator+(const Vec2D& secondVec2D) {
	return this->add(secondVec2D);
}
Vec2D Vec2D::operator+(const double numeral) {
	return this->add(numeral);
}
Vec2D Vec2D::operator+=(const Vec2D& secondVec2D) {	// v1 += v2
	this->x_ += secondVec2D.x_;
	this->y_ += secondVec2D.y_;
	return (*this);
}
// 向量和数值的加法
Vec2D Vec2D::add(double numeral) {
	return Vec2D(this->x_ + numeral, this->y_ + numeral);
}

// 向量减法
Vec2D Vec2D::subtract(const Vec2D& secondVec2D)
{
	// TODO: 在此处添加实现代码.
	return Vec2D(x_ - secondVec2D.x_, y_ - secondVec2D.y_);
}
Vec2D Vec2D::operator-(const Vec2D& secondVec2D) {
	return this->subtract(secondVec2D);
}
Vec2D Vec2D::operator -=(const Vec2D& secondVec2D) {
	this->x_ -= secondVec2D.x_;
	this->y_ -= secondVec2D.y_;
	return (*this);
}
// 向量减数值
Vec2D Vec2D::subtract(double numeral) {
	return Vec2D(x_ - numeral, y_ - numeral);
}
Vec2D Vec2D::operator-(double numeral) {
	return this->subtract(numeral);
}

// 向量点积
double Vec2D::dot(const Vec2D& secondVec2D)
{
	// TODO: 在此处添加实现代码.
	return (x_ * secondVec2D.x_ + y_ * secondVec2D.y_);
}
double Vec2D::operator*(const Vec2D& secondVec2D) {
	return this->dot(secondVec2D);
}

// 向量数乘
Vec2D Vec2D::multiply(double multiplier)
{
	// TODO: 在此处添加实现代码.
	return Vec2D(x_ * multiplier, y_ * multiplier);
}
Vec2D Vec2D::operator *(double multiplier) {
	return this->multiply(multiplier);
}
Vec2D operator*(double multiplier, Vec2D vec2d) {
	return vec2d.multiply(multiplier);
}

// 向量求负值
Vec2D Vec2D::negative()
{
	// TODO: 在此处添加实现代码.
	return Vec2D(-x_, -y_);
}
Vec2D Vec2D::operator-() {
	return Vec2D(-this->x_, -this->y_);
}

// 向量自增1
Vec2D& Vec2D::increase()
{
	// TODO: 在此处添加实现代码.
	x_++; y_++;
	return *this;
}
Vec2D& Vec2D::operator++() {	// ++a
	x_++; y_++;
	return *this;
}
Vec2D Vec2D::operator++(int dummy) {	// a++
	Vec2D temp{ *this };
	x_++; y_++;
	return temp;
}

// 向量自减1
Vec2D& Vec2D::decrease()
{
	// TODO: 在此处添加实现代码.
	x_--;y_--;
	return *this;
}


// 读取或修改向量元素
double& Vec2D::at(const int index)
{
	if (0 == index)
		return x_;
	else if (1 == index)
		return y_;
	else
		throw std::out_of_range("at() only accept 0 or 1 as parameter");
}
double& Vec2D::operator[](const int& index) {
	return at(index);
}

// 求向量的范数（长度）
double Vec2D::magnitude()
{
	// TODO: 在此处添加实现代码.
	return sqrt(x_ * x_ + y_ * y_);
}
Vec2D::operator double() {
	return this->magnitude();
}

// 求向量与x+轴的夹角
double Vec2D::direction()
{
	// TODO: 在此处添加实现代码.
	return atan(y_ / x_);
}


// 比较两个向量的长度。如果firstVec2D小于secondVec2D, 返回-1，若大于则返回1，若相等则返回0
int Vec2D::compareTo(Vec2D secondVec2D)
{
	// TODO: 在此处添加实现代码.
	double m1 = this->magnitude();
	double m2 = secondVec2D.magnitude();
	if (abs(m1 - m2) < 1e-10)
		return 0;
	else
		return (m1 > m2 ? 1 : -1);
}

std::ostream& operator<<(std::ostream& os, const Vec2D& v) {	// cout << v1;
	os << "(" << v.x_ << ", " << v.y_ << ")";	// 这里的<<是标准库中的运算符
	return os;
}
std::istream& operator>>(std::istream& is, Vec2D& v) {
	is >> v.x_ >> v.y_;
	return is;
}