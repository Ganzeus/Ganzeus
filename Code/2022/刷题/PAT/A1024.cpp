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
#include <unordered_map>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 220;
string n;
int k;
string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}
string add(string a, string b) {    // a和b长度一样
    int carry = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
        a[i] += b[i] - '0' + carry;
        carry = 0;
        if(a[i] > '9') {    
            a[i] -= 10;
            carry = 1;
        }
    }
    if(carry > 0) a.insert(0, "1");
    return a;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        if(n == rev(n)) {
            cout << n << endl;
            cout << i-1 << endl;
            return 0;
        }
        n = add(n, rev(n));
    }
    cout << n << endl;
    cout << k << endl;
    return 0;
}