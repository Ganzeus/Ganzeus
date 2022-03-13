// std::c++latest
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
namespace fs = std::filesystem;

int main() {
	fs::path p{ "scores.txt" };

	ifstream input{ p };

	if (input.fail()) {	//检测文件是否成功打开
		cout << "Can't open file " << p << endl;
		return 0;
	}

	string name{ "" };
	double score{ 0.0 };

	//input >> name >> score;
	//cout << name << " " << score << endl;
	//input >> name >> score;
	//cout << name << " " << score << endl;

	char x;
	while (!input.eof()) {
		input.get(x);//存入变量x
		cout << x;
	}
	std::cin.get();
	return 0;
}