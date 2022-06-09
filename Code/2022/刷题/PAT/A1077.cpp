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
const int maxn = 105;

string lines[maxn];
int n;
int main() {
    cin >> n;
    getchar();
    string str;
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        lines[i] = str;
    }
    string ans = "";
    int len = lines[0].length();
    for(int i = 1; i <= len; i++) {     // 对于第一行每个字符（倒序）
        char c = lines[0][len-i];
        string s = " ";
        s[0] = c;
        bool flag = true;
        for(int j = 1; j < n; j++) {     // 检查下面所有行的对应字符
            if(lines[j][lines[j].length()-i] != c) flag = false;
        }
        if(flag) ans.insert(0, s);
        else break;
    }
    if(ans == "") cout << "nai" << endl;
    else cout << ans << endl;
    return 0;
}