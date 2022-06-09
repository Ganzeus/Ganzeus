#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1010;
int n, m;
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
vector<int> path;   // 题目给的序列
bool Dijkstra(int s) {
    fill(d, d + maxn, INF);
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    for(int i = 1; i <= n; i++) {
        int u = -1, min = INF;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return false;
        if(d[path[i]] == min) u = path[i]; // 按照题目给的序列选择结点
        else return false;  // 不是最短距离，则不满足要求
        vis[u] = true;
        for(int v = 1; v <= n; v++) {
            if(!vis[v] && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
    return true;
}
int main() {
    fill(G[0], G[0] + maxn * maxn, INF);
    cin >> n >> m;
    int v1, v2, dis;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> dis;
        G[v1][v2] = G[v2][v1] = dis;
    }
    int k;
    cin >> k;
    path.resize(n+1);
    while(k--) {
        for(int i = 1; i <= n; i++) cin >> path[i];
        if(Dijkstra(path[1])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}