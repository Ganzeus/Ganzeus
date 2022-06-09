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
const int maxn = 110;

vector<int> children[maxn];
map<int, int> mp;
int maxLevel = 0;
void DFS(int id, int level) {
    if(level > maxLevel) maxLevel = level;  // 统计最大层数
    if(children[id].size() == 0){
        mp[level]++;
        return;
    }
    for(int i = 0; i < children[id].size(); i++) {
        DFS(children[id][i], level + 1);
    }

}
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int father, k;
        cin >> father >> k;
        while(k--) {
            int child;
            cin >> child;
            children[father].push_back(child);
        }
    }
    DFS(1, 0);
    for(int i = 0; i <= maxLevel; i++) {
        cout << mp[i];
        if(i != maxLevel) cout << " ";
    }
    return 0;
}