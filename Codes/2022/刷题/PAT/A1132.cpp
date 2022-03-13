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
const int maxn = 30;
int n;
int main() {
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        int mid = str.size() / 2;   // 一半长度
        string s1 = str.substr(0, mid);
        string s2 = str.substr(mid, mid);
        ll a1 = stoi(s1), a2 = stoi(s2);
        ll a = stoi(str);
        ll product = a1 * a2;
        if(product == 0 || a % product) cout << "No" << endl;
        else if(a % product == 0) cout << "Yes" << endl;
    }
    return 0;
}