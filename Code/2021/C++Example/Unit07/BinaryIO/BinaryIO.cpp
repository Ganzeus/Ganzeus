// ������C++17����
#include <iostream>
#include <fstream>
#include <filesystem>
#include <array>

int main() {
	namespace fs = std::filesystem;
	using io = std::ios;
	fs::path p{ "array.dat" };

	// ���������������
	std::fstream out{ p, io::out | io::app };

	// �ж����Ƿ�ɹ���

	// ��һ���������������������������ļ���
	std::array a{ 21L, 42L, 63L };
	std::streamsize size = a.size() * sizeof(a[0]);
	out.write(reinterpret_cast<char*>(&a[0]), size);

	// �Զ�ȡģʽ���´򿪶������ļ������߽���궨λ���ļ�ͷ fstream::seekg()
	out.close();
	out.open(p, io::in);

	// �Ӷ��������ж���һ����������ʾ����Ļ��
	auto x{ 0L };
	out.read(reinterpret_cast<char*>(&x), sizeof(x));
	std::cout << x << std::endl;

	return 0;
}