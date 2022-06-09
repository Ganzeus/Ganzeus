#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

int main() {
    string s;
    cin >> s;
    bool positive = true;
    if(s[0] == '-') positive = false;
    int indexE = 0;
    string sig = "";
    sig.append(s.substr(1, 1)); // "1"
    for(int i = 2; i < s.length(); i++) {   // 找E下标
        if(s[i] == 'E') {
            indexE = i;
            break;
        }
    }
    sig.append(s.substr(3, indexE - 3));    // 123400
    // cout << sig << endl;
    bool left = false;  // + 小数点右移
    if(s[indexE + 1] == '-') left = true;
    int shiftnum = 0;
    for(int i = indexE + 2; i < s.length(); i++) {  // 计算小数点移动的位数
        shiftnum = 10 * shiftnum + s[i] - '0';
    }
    // 开始输出
    if(!positive) cout << "-";  // 负数输出负号
    if(left) {  // 小数点左移
        cout << "0.";
        shiftnum--;
        while(shiftnum--) cout << '0';
        cout << sig << endl;
    }else{  // 右移
        if(shiftnum + 1 < sig.length()){    // 后面不添0
            cout << sig.substr(0, shiftnum + 1);
            cout << ".";
            cout << sig.substr(shiftnum + 1, sig.length() - shiftnum - 1);
        }else {   // 没有小数点，后面添0
            cout << sig;
            int num = shiftnum - sig.length() + 1;
            while(num--) cout << "0";
        }
    }

    return 0;
}