#include <iostream>
using std::cout;
using std::endl;
//任务1：继承构造函数
//	创建基类B及构造函数B(int),B(char)和派生类D；D中不继承/继承B的ctor时的效果

//任务2：派生类中调用基类构造函数
//	D中增加成员double x；及D(double)，在D(double)初始化列表调用B(i)并初始化x

//任务3：派生类先调基类ctor，再构造内嵌对象
//	增加类E及E(int)，并在D中加入E的两个对象；创建D对象观察E ctor和B ctor次序

class B {
public:
	B() { cout << "B()" << endl; }
	B(int i) { cout << "B(" << i << ")" << endl; }
	B(char c) { cout << "B(" << c << ")" << endl; }
};

class E {
public:
	E() { cout << "E()" << endl; }
};
class D : public B {	//类D无成员时，生成的默认构造函数会调用基类的构造函数
public:
	using B::B;
	D() = default;
	//D(): B() {}
	//D(int i): B(int i) {}
	//D(char c): B(char c) {}
	D(double x) : e1{}, e2{}, B(static_cast<int>(x)) {
		cout << "D(" << x << ")" << endl;
	}
private:
	//double x{ 1.0 };
	E e1, e2;
};

int main() {
	B b;
	D d;
	D d2(3.03);
	return 0;
}