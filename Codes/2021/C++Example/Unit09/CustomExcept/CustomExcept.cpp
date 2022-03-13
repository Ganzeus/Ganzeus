// ����4�����������д���Vec3D���󲢵���[]����Խ������
// �����쳣������쳣�е���Ϣ
#include <iostream>
#include <exception>
#include "Vec3D.h"
using std::cout;
using std::endl;

int main() {
	Vec3D v1{ 1.2, 3.2, 4.3 };
	try {
		cout << v1[4] << endl;
	}
	catch (std::exception& e) {
		cout << "Exception: " << e.what() << endl;
		if (typeid(e) == typeid(RangeException)) {	// ���e��RangeException����
			auto r = dynamic_cast<RangeException&>(e);	// ����ת��
			cout << "Vector dimension: " << r.getDimension() << endl;
			cout << "Index: " << r.getIndex() << endl;
		}
	}
}