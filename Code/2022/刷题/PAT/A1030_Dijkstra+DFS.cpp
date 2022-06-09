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
int n, m, s, t;
int G[maxn][maxn];  //邻接矩阵
bool vis[maxn] = {false};
int d[maxn];    //最短距离
int cost[maxn][maxn];
int minCost = INF;  //所求最短花费
vector<int> pre[maxn];  //多重前驱数组
vector<int> tempPath, path;

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, min = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(!vis[v] && G[u][v] != INF){  //v为u的邻接点
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int s, int v){ //s为起点，v为当前访问结点
    if(v == s){ //递归边界，到达路径起点
        tempPath.push_back(v);
        int tmpCost = 0;    //记录当前路径花费
        for(int i = tempPath.size()-1; i > 0; i--){ //倒着访问
            int cur = tempPath[i], nxt = tempPath[i-1];
            tmpCost += cost[cur][nxt];
        }
        if(tmpCost < minCost){
            minCost = tmpCost;
            path = tempPath;
        }
        tempPath.pop_back();    //删除刚加的结点
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){ //遍历前驱数组(子结点)进行递归
        DFS(s, pre[v][i]);
    }
    tempPath.pop_back();  //每次访问所有子结点后弹出
}
int main() {
    fill(G[0], G[0]+maxn*maxn, INF);
    fill(cost[0], cost[0]+maxn*maxn, INF);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 0; i < m; i++){
        int c1, c2, dis, cst;
        scanf("%d%d%d%d", &c1, &c2, &dis, &cst);
        G[c1][c2] = G[c2][c1] = dis;
        cost[c1][c2] = cost[c2][c1] = cst;
    }
    Dijkstra(s);
    DFS(s, t);  //获取最优路径
    for(int i = path.size()-1; i >= 0; i--){
        cout << path[i] << " ";
    }
    cout << d[t] << " " << minCost << endl;
    return 0;
}