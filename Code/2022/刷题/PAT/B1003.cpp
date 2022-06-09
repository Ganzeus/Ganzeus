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
int n;

int main() {
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        int flag = true;
        string a = "", b = "", c = "";
        int indexP = 0;
        int indexT = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == 'A') {
                a += str[i];
                continue;
            }
            else if(str[i] != 'P') {    // 前面的字母不是A也不是T,答案错误
                flag = false;
                break;
            }else {     // 遇到P
                indexP = i; // 记录P的下标
                break;
            }
        }
        for(int i = indexP + 1; i < str.length(); i++) {    // 查看P后的字母
            if(str[i] == 'A') b += str[i];
            else if(str[i] == 'T') { indexT = i; break;}    // 记录T的下标
            else {flag = false; break;}     // 不是A也不是T，答案错误
        }
        for(int i = indexT + 1; i < str.length(); i++) {    // 查看T后的字母
            if(str[i] == 'A') c += str[i];
            else {  // 不是A, 答案错误
                flag = false;
                break;
            }
        }
        // cout << a << " " << b << " " << c << endl;
        // 此时a, b, c全是A组成的字符串
        int la = a.length();
        int lb = b.length();
        int lc = c.length();
        if(la == 0 && lc == 0) {
            if(lb == 0) flag = false;
        }
        else if(la == 0 || lc == 0){  // a和c有一个是0
            flag = false;
        }else { //a和c都不是0
            if(lc % la != 0) flag = false;
            else {  // a整除c
                int cnt = lc/la;        // lc/la 必须与lb个数一致，否则答案错误
                if (cnt != lb) flag = false;
            }
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
    return 0;
}