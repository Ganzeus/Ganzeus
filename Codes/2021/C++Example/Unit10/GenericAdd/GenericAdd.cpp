#include <iostream>
template <typename T, typename Q>
auto add(T x, Q y) {
	return (x + y);
}
int main() {
	std::cout << add(3, 2.3) << std::endl;
}