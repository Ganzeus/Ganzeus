#include <iostream>
#include <exception>
#include "Vec3D.h"
using std::cout;
using std::endl;

int main() {
	Vec3D v{ 3.5, 2.1, 8.6 };
	try {
		//cout << v[3] << endl;
		cout << (v / 0.0)[0] << endl;
	}
	catch (RangeException& e) {
		cout << "Exception: " << e.what() << endl;
		cout << "Vector dimension is: " << e.getDimension() << endl;
		cout << "You used index " << e.getIndex() << endl;
	}
	catch (ZeroException& e) {
		cout << "Exception: " << e.what() << endl;
	}
}