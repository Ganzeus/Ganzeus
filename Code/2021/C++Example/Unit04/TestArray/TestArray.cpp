#include <iostream>
using namespace std;
#include <array>
#include <algorithm>
//必须用C++17标准

void print(array<int, 3>& a) {
	for (int x : a) {
		cout << x << " ";
	}
}

int search(array<int, 3>& a, int token) {	//查找token元素，返回下标
	bool exist{ false };
	int i = 0;
	for (auto element : a) {
		if (element == token) {
			exist = true;
			break;
		}
		i++;
	}
	if (exist) return i;
	else return -1;
}
int main() {
	//1.创建数组
	array a1 = { 1,2,4 };	//推断成array<int,3>
	print(a1);
	//2.为数组赋值
	a1 = { 7,8,9 };
	cout << endl;
	print(a1);
	cout << endl;
	//3.交换数组
	array b1{ 100,200,300 };
	print(b1);
	a1.swap(b1);
	print(a1);
	print(b1);
	cout << endl;
	//4.求数组大小
	cout << a1.size() << endl;
	cout << a1.max_size() << endl;
	//5.编写search函数，在数组中查找一个值
	cout << "search 300: " << search(a1, 300) << endl;
	cout << "search 1: " << search(a1, 1) << endl;
	//6.sort
	sort(a1.begin(), a1.end());
	print(a1);
	//7.二维数组
	array<array<int, 3>, 4> a8;
}