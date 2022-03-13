//�����C++17֧��
#include <iostream>
#include <filesystem>
#include <string>
using std::endl;
using std::cout;

namespace fs = std::filesystem;

// C:\\Users\\Ganzeus\\Documents
int main() {
	// ����·������
	fs::path p1{ R"(C:\Users)" };
	fs::path p2{ R"(C:\Users)" };
	fs::path p3{ "" };
	// append��/=
	p1.append(R"(Ganzeus)");
	p1 /= R"(Documents)";

	cout << p1 << endl;
	// concat��+=
	p2.concat(R"(Ganzeus)");
	p2 += R"(Documents)";

	cout << p2 << endl;
	//������� / ƴ��һ����·��
	p3 = p3 / R"(C:\Users)" / R"(Ganzeus)" / R"(Documents)";

	cout << p3 << endl;

	return 0;
}