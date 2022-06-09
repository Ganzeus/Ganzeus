#include <iostream>
using std::endl;
using std::cout;
// ����1��������ṹ��Computer->PC->Desktop/Laptop�Լ���Ӧ��ctor/dtor���ô���
//	main�д���Desktop/Laptop���󣬹۲�ctor/dtor���ô���
// 
// ����2��������Camera��ΪLaptop����ǰ����c������
//	main�д���Laptop���󣬹۲���Ƕ����c�Ĺ�������๹�����

class Computer {
public:
	Computer() { cout << "Computer()" << endl; }
	~Computer() { cout << "~Computer()" << endl; }
};
class PC :public Computer {
public:
	PC() { cout << "PC()" << endl; }
	~PC() { cout << "~PC()" << endl; }
};
class Desktop :public PC {
public:
	Desktop() { cout << "Desktop()" << endl; }
	~Desktop() { cout << "~Desktop()" << endl; }
};
class Camera {
public:
	Camera() { cout << "Embedded Camera()" << endl; }
	~Camera() { cout << "Embedded ~Camera()" << endl; }
};
class Laptop :public PC {
private:
	Camera c{};
public:
	Laptop() { cout << "Laptop()" << endl; }
	~Laptop() { cout << "~Laptop()" << endl; }
};

int main() {
	{
		Desktop d{};
		Laptop l{};
	}
	std::cin.get();
	return 0;
}