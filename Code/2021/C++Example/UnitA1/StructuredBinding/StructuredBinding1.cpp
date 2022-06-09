#include <iostream>

int main() {
	int a[]{ 1,2,3 };
	//std::array a{ 1, 2, 3 };
	//std::array<int, 2> b{ 11,12 };

	auto [e1, e2, e3] = a;

	//auto &[f1, f2, f3] {a};

	//f1 = 10;

	std::cout << e1 << " " << e2 << " " << e3;

	return 0;
}