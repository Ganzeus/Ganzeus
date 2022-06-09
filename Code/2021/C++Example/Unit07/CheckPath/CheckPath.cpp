// �����C++17֧��
#include <iostream>
#include <filesystem>
#include <string>

int main() {
	namespace fs = std::filesystem;
	// ����·����ʹ�����ַ�����ת���ַ�������б���ַ���
	fs::path p1{ "C:\\Users\\Ganzeus\\source\\repos\\Example\\Unit07\\CheckPath\\Hello.txt" };	//ת���ַ���
	fs::path p2{ R"(C:\Users\Ganzeus\source\repos\Example\Unit07\CheckPath)" };	//���ַ���
	fs::path p3{ "C:/Users/Ganzeus/source/repos/Example/Unit07/CheckPath/Hello.txt" };	//��б��
	// ���Ĭ���ļ��ָ���
	std::cout << "file seperator is: " << fs::path::preferred_separator << std::endl;

	// �ж��Ƿ��ǳ����ļ�������ǣ�����ļ���С
	if (fs::is_regular_file(p2)) {
		std::cout << p2 << "'s size is: "<< fs::file_size(p2) << std::endl;
	}	// �ж��Ƿ���Ŀ¼�������Ŀ¼���г�����Ŀ¼
	else if (fs::is_directory(p2)) {
		std::cout << p2 << "is a directory, includes: " << std::endl;
		for (auto& e : fs::directory_iterator(p2)) {
			std::cout << " " << e.path();
		}
	}
	// �ж�·���Ƿ����
	else if (fs::exists(p2)) {
		std::cout << p2 << "is a special file" << std::endl;
	}
	else {
		std::cout << p2 << "does not exist" << std::endl;
	}
	return 0;
}