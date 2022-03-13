#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 210;

map<pair<int, int>, bool> mp;   // 边集映射
int n, m, k;
set<int> tmp;
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        if(v1 > v2) swap(v1, v2);
        mp[make_pair(v1, v2)] = true;
    }
    cin >> k;
    vector<int> cycle;
    while(k--) {
        cycle.clear();
        tmp.clear();
        int num;
        cin >> num;
        for(int i = 0; i < num; i++) {
            int v;
            cin >> v;
            cycle.push_back(v);
            tmp.insert(v);
        }
        if(num != n + 1 || tmp.size() != n){       // 环的点数必须是n+1, 必须有n的不重复的点
            cout << "NO" << endl;
            continue;
        }
        bool flag = true;
        int size = cycle.size();
        for(int i = 0; i < size-1; i++) {
            int v1 = cycle[i], v2 = cycle[i+1];
            if(v1 > v2) swap(v1, v2);
            if(mp.find(make_pair(v1, v2)) == mp.end()) {    // 没有这条边
                flag = false;
                break;
            } 
        }
        if(cycle[0] != cycle[size - 1]) flag = false;   // 不是环
        
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}