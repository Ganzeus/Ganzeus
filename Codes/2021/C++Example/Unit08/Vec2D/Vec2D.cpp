#include "Vec2D.h"

Vec2D::Vec2D() {

}
Vec2D::Vec2D(double x, double y) {
	x_ = x;
	y_ = y;
}


// ������ת��Ϊ�ַ�����ʽ��ʾ
std::string Vec2D::toString()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return std::string("(" + std::to_string(x_) + ",	" + std::to_string(y_) + ")");
}


// �����ӷ�
Vec2D Vec2D::add(const Vec2D& secondVec2D)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
// ��������ֵ�ļӷ�
Vec2D Vec2D::add(double numeral) {
	return Vec2D(this->x_ + numeral, this->y_ + numeral);
}

// ��������
Vec2D Vec2D::subtract(const Vec2D& secondVec2D)
{
	// TODO: �ڴ˴����ʵ�ִ���.
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
// ��������ֵ
Vec2D Vec2D::subtract(double numeral) {
	return Vec2D(x_ - numeral, y_ - numeral);
}
Vec2D Vec2D::operator-(double numeral) {
	return this->subtract(numeral);
}

// �������
double Vec2D::dot(const Vec2D& secondVec2D)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return (x_ * secondVec2D.x_ + y_ * secondVec2D.y_);
}
double Vec2D::operator*(const Vec2D& secondVec2D) {
	return this->dot(secondVec2D);
}

// ��������
Vec2D Vec2D::multiply(double multiplier)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return Vec2D(x_ * multiplier, y_ * multiplier);
}
Vec2D Vec2D::operator *(double multiplier) {
	return this->multiply(multiplier);
}
Vec2D operator*(double multiplier, Vec2D vec2d) {
	return vec2d.multiply(multiplier);
}

// ������ֵ
Vec2D Vec2D::negative()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return Vec2D(-x_, -y_);
}
Vec2D Vec2D::operator-() {
	return Vec2D(-this->x_, -this->y_);
}

// ��������1
Vec2D& Vec2D::increase()
{
	// TODO: �ڴ˴����ʵ�ִ���.
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

// �����Լ�1
Vec2D& Vec2D::decrease()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	x_--;y_--;
	return *this;
}


// ��ȡ���޸�����Ԫ��
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

// �������ķ��������ȣ�
double Vec2D::magnitude()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return sqrt(x_ * x_ + y_ * y_);
}
Vec2D::operator double() {
	return this->magnitude();
}

// ��������x+��ļн�
double Vec2D::direction()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return atan(y_ / x_);
}


// �Ƚ����������ĳ��ȡ����firstVec2DС��secondVec2D, ����-1���������򷵻�1��������򷵻�0
int Vec2D::compareTo(Vec2D secondVec2D)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	double m1 = this->magnitude();
	double m2 = secondVec2D.magnitude();
	if (abs(m1 - m2) < 1e-10)
		return 0;
	else
		return (m1 > m2 ? 1 : -1);
}

std::ostream& operator<<(std::ostream& os, const Vec2D& v) {	// cout << v1;
	os << "(" << v.x_ << ", " << v.y_ << ")";	// �����<<�Ǳ�׼���е������
	return os;
}
std::istream& operator>>(std::istream& is, Vec2D& v) {
	is >> v.x_ >> v.y_;
	return is;
}