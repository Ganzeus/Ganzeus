#pragma once
#include <array>
#include <cmath>
#include <limits>
#include "RangeException.h"
#include "ZeroException.h"


bool isSame(double a, double b) {	// 判断浮点数相等
	return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}
class Vec3D {
public:
	constexpr static std::size_t DIMENSION = 3;
private:
	std::array<double, DIMENSION> vec{ 1.0, 1.0, 1.0 };
public:
	Vec3D() = default;
	Vec3D(double x, double y, double z) {
		vec[0] = x;
		vec[1] = y;
		vec[2] = z;
	}
	double& operator[] (const int index) {	// 返回左值
		if (index >= 0 && index <= 2) {
			return vec[index];
		}
		else {
			throw RangeException(DIMENSION, index);	// 抛出一个RangeException匿名对象
		}
	}
	Vec3D operator /(const double divisor) {
		Vec3D t(*this);
		if (isSame(divisor, 0.0))
			throw ZeroException();
		for (auto i : t.vec) {
			i /= divisor;
		}
		return t;
	}
};