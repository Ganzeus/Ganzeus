#include <iostream>
#include <string>
using namespace std;

int main() {
	//�����ַ���
	string s{ "Hello" };
	//clear
	s.clear();
	//������Ϊ�ַ�����ֵ
	char arr[] { 'W','o','r','l','d' };
	s += arr;
	//assign()
	//s.assign("Hello,World!");
	s.assign("1024");
	//append
	s.append("  ");
	s.append(5, '\t');
	//s.append("!");
	//insert �հ�
	s.insert(0, "    ");
	cout << s << endl;
	//�Ƴ��ִ�ǰ��Ŀհ�
	s.erase(0, s.find_first_not_of(" \t\n\r"));
	//�Ƴ��ִ�����Ŀհ�
	s.erase(s.find_last_not_of(" \t\n\r")+1);
	s.append("&");
	//���ִ�ת��Ϊ�����򸡵���
	int x = stoi(s);
	cout << s << endl;
	cout << "x = " << x << endl;

	string s2 = to_string(x);
	cout << "s2 : " << s2 << endl;
	return 0;
}