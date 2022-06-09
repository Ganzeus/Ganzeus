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
int n, m, G[maxn][maxn];
int T[maxn][maxn];
int st, ed;
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
void Dijkstra1(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(!vis[v] && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int minT = INF;
vector<int> tempPath, path, path2;
void DFS1(int v) {
    if(v == st) {
        tempPath.push_back(v);
        int tmpT = 0;
        for(int i = tempPath.size()-1; i > 0; i--) {
            int v1 = tempPath[i], v2 = tempPath[i-1];
            tmpT += T[v1][v2];
        }
        if(tmpT < minT) {
            minT = tmpT;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS1(pre[v][i]);
    }
    tempPath.pop_back();
}
void Dijkstra2(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(!vis[v] && T[u][v] != INF) {
                if(d[u] + T[u][v] < d[v]) {
                    d[v] = d[u] + T[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + T[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int minSize = INF;
void DFS2(int v) {
    if(v == st) {
        tempPath.push_back(v);
        int tmp = tempPath.size();
        if(tmp < minSize) {
            minSize = tmp;
            path2 = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS2(pre[v][i]);
    }
    tempPath.pop_back();
}
int main() {
    fill(G[0], G[0] + maxn*maxn, INF);
    fill(T[0], T[0] + maxn*maxn, INF);
    cin >> n >> m;
    int v1, v2, flag, l, t;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> flag >> l >> t;
        if(flag == 1) { // 有向
            G[v1][v2] = l;
            T[v1][v2] = t;
        }else {
            G[v1][v2] = G[v2][v1] = l;
            T[v1][v2] = T[v2][v1] = t;
        }
    }
    cin >> st >> ed;
    Dijkstra1(st);
    DFS1(ed);
    int ansD = d[ed];
    memset(vis, false, sizeof(vis));
    tempPath.clear();
    Dijkstra2(st);
    DFS2(ed);
    int ansT = d[ed];
    if(path != path2) {
        cout << "Distance = " << ansD << ": ";
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if(i != 0) cout << " -> ";
        }
        cout << endl;
        cout << "Time = " << ansT << ": ";
        for(int i = path2.size() - 1; i >= 0; i--) {
            cout << path2[i];
            if(i != 0) cout << " -> ";
        }
    }else {
        printf("Distance = %d; Time = %d: ", ansD, ansT);
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if(i != 0) cout << " -> ";
        }
    }
    return 0;
}