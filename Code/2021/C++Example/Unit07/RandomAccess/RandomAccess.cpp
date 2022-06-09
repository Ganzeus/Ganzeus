// C++17��׼����
#include <iostream>
#include <fstream>
#include <filesystem>
#include <array>
#include <vector>

namespace fs = std::filesystem;
using std::cout;
using std::endl;
using std::fstream;

int main() {
	// ����1�����ļ��д�2��long long int �� "Hello World"�ַ���
	fs::path p{ "test.dat" };
	fstream file{ p, std::ios::out | std::ios::in | std::ios::trunc };

	auto x{ 12LL }, y{ 24LL };
	char str[]{ "Hello World" };

	file.write(reinterpret_cast<char*>(&x), sizeof(x));
	file.write(reinterpret_cast<char*>(&y), sizeof(long long int));
	file.write(str, sizeof(str));

	// ����2�����ļ���ȡHello�ַ���
	char buf[100]{ 0 };
	file.seekg(2 * sizeof(long long int), std::ios::beg);
	file.read(buf, sizeof("Hello"));

	cout << buf << endl;
	return 0;
}