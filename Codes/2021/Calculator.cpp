#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

struct node {
	double opnd;	//操作数
	char optr;		//操作符
	bool flag;		//true表示操作数，false表示操作符
};
stack<node> stk;	//操作符栈

queue<node> post;	//后缀表达式队列
map<char, int> priority;	//操作符与优先级
string str;			//输入的表达式
void Turn() {		//中缀表达式转后缀表达式
	node temp;
	//double num;
	for (int i = 0;i < str.length();) {		//从头到尾遍历表达式
		if (str[i] >= '0' && str[i] <= '9') {	//如果是数字
			temp.opnd = str[i] - '0';	//记录数字第一位
			temp.flag = true;
			i++;		//判断下一位
			while (str[i] >= '0' && str[i] <= '9' && i < str.length()) {	//下一位仍是数字
				temp.opnd = temp.opnd * 10 + str[i] - '0';	//更新操作数
				i++;
			}
			post.push(temp);		//加入后缀表达式队列
		}
		else {									//如果是操作符
			temp.flag = false;		//标记是操作符
			if (str[i] == '(') {	//如果是左括号
				temp.optr = str[i];
				stk.push(temp);		//直接压栈
				i++;
				continue;
			}
			else if (str[i] == ')') {//如果是右括号
				while (stk.top().optr != '(') {	//一直出栈直到遇到左括号匹配
					post.push(stk.top());	//左括号上方的操作符入栈
					stk.pop();
				}
				stk.pop();	//左括号出栈
				i++;
				continue;
			}
			else {					//是加减乘除
				//只要当前操作符比栈顶操作符优先级低，就一直出栈
				while (!stk.empty() && priority[str[i]] <= priority[stk.top().optr]) {
					post.push(stk.top());
					stk.pop();
				}
				//遇到优先级高的操作符或栈空时，将该操作符入栈
				temp.optr = str[i];
				stk.push(temp);
				i++;
			}

		}
	}
	while (!stk.empty()) {		//将栈中剩余的操作符出栈入队
		post.push(stk.top());
		stk.pop();
	}
}

double Cal() {		//计算后缀表达式
	double temp1, temp2;	//前操作数、后操作数
	node cur, tmp;
	while (!post.empty()) {	//只要后缀队列非空
		cur = post.front();	//cur记录队首元素
		post.pop();
		if (cur.flag == true) stk.push(cur);	//如果是操作数直接压栈
		else {		//是操作符
			temp2 = stk.top().opnd;	//弹出后操作数
			stk.pop();
			temp1 = stk.top().opnd;	//弹出前操作数
			stk.pop();
			tmp.flag = true;	//记录双目运算结果存入tmp中
			if (cur.optr == '+') tmp.opnd = temp1 + temp2;
			else if (cur.optr == '-') tmp.opnd = temp1 - temp2;
			else if (cur.optr == '*') tmp.opnd = temp1 * temp2;
			else if (cur.optr == '/') tmp.opnd = temp1 / temp2;
			stk.push(tmp);		//把该操作数压栈
		}
	}
	return stk.top().opnd;		//栈顶元素即最终计算结果
}

int main() {
	//设定操作符优先级
	priority['+'] = priority['-'] = 1;
	priority['*'] = priority['/'] = 2;
	cout << "输入需要计算的表达式：" << endl;
	while (getline(cin, str), str != "0") {
		for (string::iterator it = str.begin(); it != str.end()-1; it++) {
			if (*it == ' ')	str.erase(it);	//去除表达式中的空格
		}
		while (!stk.empty())	stk.pop();//初始化清空表达式栈
		Turn();					//转后缀表达式
		double ans = Cal();		//计算答案
		printf("%.2f\n", ans);	//输出
	}
	return 0;
}
