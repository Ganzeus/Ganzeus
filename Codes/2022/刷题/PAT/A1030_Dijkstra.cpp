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
struct Node {
    int v;      //邻接点
    int dis;    //距离
    int cost;   //花费
    Node(int v_, int dis_, int cost_):v{v_}, dis{dis_}, cost{cost_} {}
};
vector<Node> Adj[maxn]; //Adj[u]表示从u能到达的所有边的信息
bool vis[maxn] {false};
int d[maxn];    //最短路径数组
int cost[maxn]; //cost[u]表示起点到u的最短总花费
int pre[maxn];  //前驱数组
int n, m, s, t;
void Dijkstra(int s) {
    //初始化
    fill(d, d+maxn, INF);
    fill(cost, cost+maxn, INF);
    for(int i = 0; i < n; i++) pre[i] = i;
    d[s] = 0;
    cost[s] = 0;
    //n次循环
    for(int i = 0; i < n; i ++){
        int u = -1, min = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            if(!vis[v] && d[u] + Adj[u][j].dis < d[v]){ //先比距离
                d[v] = d[u] + Adj[u][j].dis;
                cost[v] = cost[u] + Adj[u][j].cost;
                pre[v] = u; 
            }else if(!vis[v] && d[u] + Adj[u][j].dis == d[v] && cost[u] + Adj[u][j].cost < cost[v]){   //距离相等再比花费
                cost[v] = cost[u] + Adj[u][j].cost;
                pre[v] = u; //更新花费时也要更新前驱
            }
        }
    }
}
void DFS(int s, int v) {
    if(v == s) {    //递归边界
        cout << v << " ";
        return;
    }
    DFS(s, pre[v]);
    cout << v <<" ";
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 0; i < m; i++){
        int c1, c2, dis, cost;
        scanf("%d%d%d%d", &c1, &c2, &dis, &cost);
        Adj[c1].push_back(Node{c2, dis, cost});
        Adj[c2].push_back(Node{c1, dis, cost});
    }
    Dijkstra(s);
    DFS(s, t);  
    cout << d[t] << " " << cost[t] << endl;
    return 0;
}