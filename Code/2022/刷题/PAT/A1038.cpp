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
const int maxn = 10010;
vector<string> str;
bool cmp(string a, string b) {
    return a+b < b+a;
}
int n;
int main() {
    cin >> n;
    str.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str.begin(), str.end(), cmp);
    string ans;
    for(int i = 0; i < n; i++) {
        ans += str[i];
    }
    while(ans.size() != 0 && ans[0] == '0') ans.erase(ans.begin());
    if(ans.size() == 0) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}