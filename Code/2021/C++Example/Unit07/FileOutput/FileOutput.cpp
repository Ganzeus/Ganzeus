// C++17
#include <iostream>
#include <fstream>
#include <filesystem>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
namespace fs = std::filesystem;

int main() {
	fs::path p{ "scores.txt" };

	ofstream output{ p };

	double lileiScore{ 90.5 };
	int hanmeimeiScore{ 84 };

	output << " LiLei " << lileiScore << endl;
	output << " HanMeiMei " << hanmeimeiScore << endl;

	output.close();

	cout << "size of " << p << "is: " << fs::file_size(p) << endl;
	return 0;
}