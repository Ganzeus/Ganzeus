#include <iostream>
using std::cout;
using std::endl;

class A {
public:
	virtual std::string toString() {
		return "A";
	}
};

class B : public A {
public:
	std::string toString() override { return "B"; }
};

class C :public B {
public:
	std::string toString() override { return "C"; }
};

void print(A* o) {
	cout << o->toString() << endl;
}

void print(A& o) {
	cout << o.toString() << endl;
}

int main() {
	A a; B b; C c;
	A* p1 = &a;
	A* p2 = &b;
	A* p3 = &c;
	print(p1);
	print(p2);
	print(p3);
	print(a);
	print(b);
	print(c);
	return 0;
}