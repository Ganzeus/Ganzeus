#include <iostream>
using namespace std;
int main() {
	int* p = nullptr;
	int* q{ nullptr };		//C++11 Initializer List

	p = new int(42);
	q = new int[4];

	cout << "Before: *p =" << *p << endl;
	*p = 24;
	cout << "After: *p =" << *p << endl;

	for (int i = 0; i < 4; i++) {
		*(q + i) = 10 + i;
		cout << *(q + i) << endl;
	}

	delete p;
	delete[] q;
	return 0;
}