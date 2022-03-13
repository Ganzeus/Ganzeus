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
string mul2(string str) {    // 大整数乘2
    string ans = "";
    int carry = 0;
    for(int i = str.length() - 1; i >= 0; i--) {
        int d = str[i] - '0';   // 9
        d *= 2; // 18
        d += carry;
        string s = " ";
        s[0] = d%10 + '0';
        ans.insert(0, s);
        carry = d/10;   // 1
    }
    if(carry) {     // 最高位有进位
        string s = " ";
        s[0] = carry + '0';
        ans.insert(0, s);
    }
    return ans;
}
int num[10]{0};
int main() {
    string str;
    cin >> str;
    string ans = mul2(str);
    for(int i = 0; i < str.length(); i++) { // 对于原来的数，统计次数
        int d = str[i] - '0';
        num[d]++;
    }
    for(int i = 0; i < ans.length(); i++) { // 对于乘2的数，将统计的次数减掉，如果最后不全为0，则不符合题目要求
        int d = ans[i] - '0';
        num[d]--;
    }
    int flag = 1;
    for(int i = 0; i < 10; i++) {
        if(num[i]) flag = 0;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    int i = 0;
    for(; i < ans.length(); i++) {
        if(ans[i] != '0') break;
    }
    ans = ans.substr(i, ans.length());
    cout << ans << endl;
    return 0;
}