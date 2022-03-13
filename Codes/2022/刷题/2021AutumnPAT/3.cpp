#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
const int maxn = 110;
int n, m;
int G[maxn][maxn];
int depth = 0;
bool vis[maxn] = { false };
void DFS(int u) {
    vis[u] = true;
    depth++;
    for(int v = 1; v <= n; v++) {    // 题目要求：总是优先遍历编号小的顶点
        if(!vis[v] && G[u][v] != INF) {
            DFS(v);
            break;  // 遍历完不回头
        }
    }
}
int main() {
    fill(G[0], G[0] + maxn * maxn, INF);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    }
    int maxDepth = 0;
    int st;
    for(int i = 1; i <= n; i++) {   // 由小到大DFS可使起点编号最小
        memset(vis, false, sizeof(vis));
        depth = 0;
        DFS(i);
        if(depth > maxDepth){
            maxDepth = depth;
            st = i;
        }
    }
    cout << st << " " << maxDepth << endl;
    return 0;
}