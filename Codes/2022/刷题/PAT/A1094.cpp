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

vector<int> children[maxn]; // 树
map<int, int> mp;   // （层数，个数）
int n, m;
void DFS(int id, int level) {
    mp[level]++;
    for(int i = 0; i < children[id].size(); i++) {
        DFS(children[id][i], level + 1);
    }
}
bool cmp(int a, int b) { return a > b; }
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int father, k;
        cin >> father >> k;
        int child;
        while(k--) {
            cin >> child;
            children[father].push_back(child);
        }
    }
    DFS(1, 1);
    int maxnum = 0, ansLevel;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second > maxnum){
            maxnum = it->second;
            ansLevel = it->first;
        }
    }
    cout << maxnum << " " << ansLevel << endl;
    return 0;
}