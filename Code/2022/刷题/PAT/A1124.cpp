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
const int maxn = 520;
int n, m, st;
vector<string> forw;
set<string> win;
vector<string> ans;
int main() {
    cin >> n >> m >> st;
    forw.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> forw[i];
    }
    while(st < forw.size()) {
        while(win.find(forw[st]) != win.end())  st++;   // 已经中过奖就往后移
        win.insert(forw[st]);
        ans.push_back(forw[st]);
        st += m;
    }
    if(ans.size() == 0) cout << "Keep going..." << endl;
    else for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}