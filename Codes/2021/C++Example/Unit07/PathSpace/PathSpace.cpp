//必须打开C++17支持
#include <iostream>
#include <filesystem>


int main() {
	using std::endl;	//缩小使用范围，防止污染
	using std::cout;
	namespace fs = std::filesystem;

	// 定义路径对象
	fs::path p{ "C:\\" };
	// 展示磁盘的总大小和剩余大小
	cout << "C: total space: " << fs::space(p).capacity << endl;
	cout << "C: free space: " << fs::space(p).free << endl;

	return 0;
}