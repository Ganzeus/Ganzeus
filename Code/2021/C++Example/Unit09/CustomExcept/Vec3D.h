#pragma once
#include <array>
#include "RangeException.h"
// ����1������Vec3D�࣬�� array ����������Ա��
//����3��ʵ��Vec3D::operator[](const int index)
//��indexԽ��ʱ���׳�RangeException����
class Vec3D {
private:
	std::array<double, 3> v{ 1.0, 1.0, 1.0 };
public:
	Vec3D() = default;
	Vec3D(double x, double y, double z) {
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}
	double& operator[] (const int index) {	// ������ֵ
		if (index >= 0 && index <= 2) {
			return v[index];
		}
		else {
			throw RangeException(3, index);	// �׳�һ��RangeException��������
		}

	}
};