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
const int maxn = 30010;
int main() {
    string d;
    int n;
    cin >> d >> n;
    string ans;
    for(int k = 0; k < n-1; k++) {    // 做n次
        ans = "";
        int i = 0;
        while(i < d.length()) {
            char c = d[i];
            int cnt = 1;
            i++;
            while(i < d.length() && d[i] == c) {    // 从下一个字符开始，不等就退出
                cnt++;
                i++;
            }
            string s = "  ";
            s[0] = c;
            s[1] = cnt + '0';
            ans += s;
        }
        d = ans;
    }
    if(n == 1) cout << d << endl;
    else cout << ans << endl;

    return 0;
}