#include <iostream>
#include <filesystem>
using std::cout;
using std::endl;

int main() {
	namespace fs = std::filesystem;
	// 定义路径p
	fs::path p{ R"(C:\Users\Ganzeus\source\repos\Example\Unit07\PathQuery\PathQuery.cpp)" };
	// 是否存在？根名？根路径？相对路径？
	if (p.empty()) {
		cout << "Path: " << p << "is empty." << endl;
	}

	if (!fs::exists(p)) {
		cout << "Path " << p << "does not exist." << endl;
		std::exit(0);
	}

	cout << "root_name(): " << p.root_name() << endl;
	cout << "root_path(): " << p.root_path() << endl;
	cout << "relative_path(): " << p.relative_path() << endl;
	// 父路径？文件名？文件名主干？扩展名？
	cout << "parent_path(): " << p.parent_path() << endl
		<< "filename(): " << p.filename() << endl
		<< "stem(): " << p.stem() << endl
		<< " extension()" << p.extension() << endl;

	return 0;
}