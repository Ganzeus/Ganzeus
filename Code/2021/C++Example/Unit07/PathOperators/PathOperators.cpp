//必须打开C++17支持
#include <iostream>
#include <filesystem>
#include <string>
using std::endl;
using std::cout;

namespace fs = std::filesystem;

// C:\\Users\\Ganzeus\\Documents
int main() {
	// 定义路径对象
	fs::path p1{ R"(C:\Users)" };
	fs::path p2{ R"(C:\Users)" };
	fs::path p3{ "" };
	// append和/=
	p1.append(R"(Ganzeus)");
	p1 /= R"(Documents)";

	cout << p1 << endl;
	// concat和+=
	p2.concat(R"(Ganzeus)");
	p2 += R"(Documents)";

	cout << p2 << endl;
	//用运算符 / 拼凑一个新路径
	p3 = p3 / R"(C:\Users)" / R"(Ganzeus)" / R"(Documents)";

	cout << p3 << endl;

	return 0;
}