//�����C++17֧��
#include <iostream>
#include <filesystem>


int main() {
	using std::endl;	//��Сʹ�÷�Χ����ֹ��Ⱦ
	using std::cout;
	namespace fs = std::filesystem;

	// ����·������
	fs::path p{ "C:\\" };
	// չʾ���̵��ܴ�С��ʣ���С
	cout << "C: total space: " << fs::space(p).capacity << endl;
	cout << "C: free space: " << fs::space(p).free << endl;

	return 0;
}