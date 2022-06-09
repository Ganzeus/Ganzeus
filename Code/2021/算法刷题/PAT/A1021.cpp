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
const int maxn = 10010;
int n, node1, node2;
vector<int> Adj[maxn];  //邻接表
bool vis[maxn];
int depth[maxn];    // depth[i]表示以i为顶点树的深度
void DFS(int v, int depth, int& tmpdep) {  // v为当前访问结点，depth为v的深度, tmpdep为临时最大深度
    vis[v] = true;
    for(int i = 0; i < Adj[v].size(); i++) {
        int u = Adj[v][i];
        if(!vis[u]) {
            if(depth + 1 > tmpdep) {    //当前u的深度更大
                tmpdep = depth + 1;
            }
            DFS(u, depth+1, tmpdep);
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {  //n-1条边，如果不是树，那么至少有两个连通分支
        cin >> node1 >> node2;
        Adj[node1].push_back(node2);    //无向边
        Adj[node2].push_back(node1);
    }
    int maxdep = 0; // 最大深度
    int block = 0;  // 连通分支个数
    for(int i = 1; i <= n; i++){    //判断连通分支个数
        int tmp = 0;    // 没用
        if(!vis[i]){
            DFS(i, 0, tmp);
            block++;
        }
    }
    if(block != 1)  {
        cout << "Error: " << block << " components" << endl;    //不是树，直接输出
        return 0;
    }
    for(int i = 1; i <= n; i++) {   //以每个点为树根进行DFS
        memset(vis, false, sizeof(vis));
        int tmpdep = 0;
        DFS(i, 0, tmpdep);  // tmpdep修改为以i为根的最大深度
        depth[i] = tmpdep;  // 记录每个顶点的树深度
        if(tmpdep > maxdep) {   // 深度更大
            maxdep = tmpdep;
        }
    }
    for(int i = 1; i <= n; i++) {    // 遍历深度数组
        if(depth[i] == maxdep) cout << i << endl;
    }
    return 0;
}
