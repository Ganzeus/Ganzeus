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
const int maxn = 100010;
bool isPalin(string s) {    // 判断回文数
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

string add(string a, string b) {
    int carry = 0;
    string ret;
    int i = a.size() - 1, j = b.size() - 1;
    for(; i >= 0 && j >= 0; i--, j--) {
        int d1 = a[i] - '0', d2 = b[j] - '0';
        int res = d1 + d2 + carry;
        carry = res / 10;
        res = res % 10;
        char c = res + '0';
        string s = "0";
        s[0] = c;
        ret.insert(0, s);
    }
    while(i >= 0) {
        int d = a[i] - '0';
        int res = d + carry;
        carry = res/10;
        res = res%10;
        char c = res + '0';
        string s = " ";
        s[0] = c;
        ret.insert(0, s);
    }
    while(j >= 0) {
        int d = a[j] - '0';
        int res = d + carry;
        carry = res/10;
        res = res%10;
        char c = res + '0';
        string s = " ";
        s[0] = c;
        ret.insert(0, s);
    }
    if(carry > 0) {
        char c = carry + '0';
        string s = " ";
        s[0] = c;
        ret.insert(0, s);
    }
    return ret;
}
string rev(string s) {
    string ret;
    for(int i = 0; i < s.length(); i++) {
        ret.insert(0, s.substr(i, 1));
    }
    return ret;
}
int main() {
    string str;
    cin >> str;
    int cnt = 1;
    while(1) {
        if(cnt > 10) {
            cout << "Not found in 10 iterations." << endl;
            return 0;
        }
        if(isPalin(str)) {
            cout << str << " is a palindromic number." << endl;
            break;
        }
        string ans = add(str, rev(str));
        cout << str << " + " << rev(str) << " = " << ans << endl;
        str = ans;
        cnt++;
    }
    return 0;
}