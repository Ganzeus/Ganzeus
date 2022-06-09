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
int cmax, n, m, t;  //最大点权，结点数，边数，终点
int G[maxn][maxn];  //邻接矩阵
int weight[maxn];   //点权
bool vis[maxn] { false };
int d[maxn];    //最短路数组
vector<int> pre[maxn];  //多重前驱数组

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    d[s] = 0;
    for(int i = 0; i < n+1; i++){   //循环n+1次
        int u = -1, min = INF;
        for(int j = 0; j < n+1; j++){ //找到距离最短点
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n+1; v++){
            if(!vis[v] && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
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
int minNeed = INF, minRemain = INF; 
vector<int> path, tempPath; //最优路径、临时路径
void DFS(int s, int v) {    //s为起点，v为当前访问结点
    //递归边界
    if(v == s) {    //v递归到达起点
        tempPath.push_back(v);
        int remain = 0, need = 0;   //存放当前需要携带和带回的自行车
        for(int i = tempPath.size()-2; i >= 0; i--) {   //起点不算
            int id = tempPath[i];
            if(weight[id] > 0) {  //点权为正，说明不需要补给，留给后面的结点
                remain += weight[id];
            }else {
                if(remain > abs(weight[id])) {
                    remain -= abs(weight[id]);
                }else {
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed){ //先比支出
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        }else if(need == minNeed && remain < minRemain) {   //支出相等再比剩余
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    //递归式
    tempPath.push_back(v);  //将当前结点加入临时路径
    for(int i = 0; i < pre[v].size(); i++){
        DFS(0, pre[v][i]); //递归访问前驱结点
    }
    tempPath.pop_back();    //访问完当前结点的所有前驱后，删除当前结点
}
int main() {
    fill(G[0], G[0] + maxn*maxn, INF);  //初始化邻接矩阵
    fill(weight, weight+maxn, INF); //初始化点权为INF
    cin >> cmax >> n >> t >> m;
    for(int i = 1; i <= n; i++) {
        cin>>weight[i];
        weight[i] -= cmax/2;
    }
    int c1, c2, w;
    for(int i = 0; i < m; i++){
        cin >> c1 >> c2 >> w;
        G[c1][c2] = G[c2][c1] = w;
    }
    Dijkstra(0);
    DFS(0, t);
    cout << minNeed << " ";
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i];
        if(i != 0) cout << "->";
    }
    cout << " " << minRemain << endl;
    return 0;
}