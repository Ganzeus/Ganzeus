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
const int maxn = 1020;
map<int, vector<int> >mp;
int n, m;
int G[1010];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        mp[n1].push_back(n2);
        mp[n2].push_back(n1);
    }
    while(m--) {    // m次查询
        int num;
        cin >> num;
        for(int i = 0; i < num; i++) {
            cin >> G[i];
        }
        int flag = 0;
        for(int i = 0; i < num-1; i++) {
            if(mp[G[i]].size() == 0) continue;
            for(int j = 0; j < mp[G[i]].size(); j++) {
                int incmp = mp[G[i]][j];
                for(int k = i + 1; k < num; k++) {
                    if(incmp == G[k]) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}