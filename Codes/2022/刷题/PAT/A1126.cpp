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
vector<int> Adj[maxn];  // 邻接表
int n, m;
int cntV = 0;
bool vis[maxn];
void DFS(int v) {   // 判断连通性
    vis[v] = true;
    cntV++;
    for(int i = 0; i < Adj[v].size(); i++) {
        if(!vis[Adj[v][i]]) DFS(Adj[v][i]);
    }
}
int main() {
    cin >> n >> m;
    int v1, v2;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        Adj[v1].push_back(v2);
        Adj[v2].push_back(v1);
    }
    int cntOdd = 0;
    for(int i = 1; i <= n; i++) {
        int d = Adj[i].size();
        if(d & 1) cntOdd++;
        cout << d;
        if(i != n) cout << " ";
    }
    cout << endl;
    DFS(1);
    if(cntOdd == 0 && cntV == n) cout << "Eulerian" << endl;    // 必须是连通图
    else if(cntOdd == 2 && cntV == n) cout << "Semi-Eulerian" << endl;
    else cout << "Non-Eulerian" << endl;
    return 0;
}