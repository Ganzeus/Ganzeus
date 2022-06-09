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
const int maxn = 505;
int n, m;
// int G[maxn][maxn];
struct Node{
    int v, dis;
    Node(int v_, int dis_): v{v_}, dis{dis_} {}
};
vector<Node> Adj[maxn];
int weight[maxn], dis[maxn], num[maxn], w[maxn];
bool vis[maxn] {false};
void Dijkstra(int s){
    fill(dis, dis + maxn, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    dis[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0; i < n; i++) {    //不要用while(n--)
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if(vis[v] == false && dis[u] + Adj[u][j].dis < dis[v]) {
                dis[v] = dis[u] + Adj[u][j].dis;
                num[v] = num[u];
                w[v] = w[u] + weight[v];
            } else if(dis[u] + Adj[u][j].dis == dis[v]) {
                num[v] = num[v] + num[u];
                if(w[u] + weight[v] > w[v])
                w[v] = w[u] + weight[v];
            }
        }
    }
}
int main() {
    int s, t;
    cin>>n>>m>>s>>t;
    for(int i = 0; i < n; i++) scanf("%d", &weight[i]);
    // fill(G[0], G[0] + maxn * maxn, INF);
    int u, v, dis;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &dis);
        // G[u][v] = G[v][u] = dis;
        Adj[u].push_back(Node{v, dis});
        Adj[v].push_back(Node{u, dis}); //无向边
    }
    Dijkstra(s);
    cout << num[t] <<" " << w[t] << endl;
    return 0; 
}