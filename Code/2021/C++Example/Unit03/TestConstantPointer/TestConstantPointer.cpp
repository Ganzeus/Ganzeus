#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	// ��������
	const int x = 42;
	// �������ɱ�
	// x = 21;
	// ����ָ����ָ���ݲ��ɱ�
	int y = 2;
	const int* p = &x;
	// (*p) = 24;
	const int* q = &y;
	//(*q) = 42;
	// ָ�볣�����ɱ�
	int* const r = &y;
	int z = 5;
	*r = 20;
	cout << *r <<" "<< y << endl;
	// ��ָ�볣��
	const int* const s = &y;
	//s = &z;
	const char* str = "Hello";

	auto p1 = &y;
	auto p2 = "World";
	auto const p3 = "!";
	return 0;
}