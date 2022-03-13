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
const int maxn = 10020;
bool vis[maxn];
vector<int> Adj[maxn];  // 邻接表
map<int, int> line;     // 8位key表示两个站，value为第几号线
int n, m, k, st, ed;
int minV = INF, minTran = INF;  // 最少顶点数，最少换乘数
vector<int> tempPath, path;
void DFS(int v) {
    if(v == ed) {   // 递归到终点
        tempPath.push_back(v);
        int tmpV = 0, tmpTran = 0;
        for(int i = 1; i < tempPath.size()-1; i++) { // 该条线上的所有顶点（不算起点和终点）
            tmpV++;
            int pre = tempPath[i-1], now = tempPath[i], next = tempPath[i+1];
            if(line[pre*10000+now] != line[now*10000+next]) tmpTran++;  // 前一条和后一条不在同一条线路上，即换乘
        }
        tmpV++; // 少算了一个终点
        if(tmpV < minV) {   // 经过站数更少
            minV = tmpV;
            minTran = tmpTran;
            path = tempPath;
        }else if(tmpV == minV && tmpTran < minTran) {   // 换乘数更少
            minTran = tmpTran;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < Adj[v].size(); i++) {    // 路径的顺序为正向！！
        int next = Adj[v][i];
        if(!vis[next]){ // 没访问过
            tempPath.push_back(next);
            vis[next] = true;   // 记录已经访问过
            DFS(next);
            tempPath.pop_back();
            vis[next] = false;  // 递归完后记为没访问过
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        int first;
        cin >> first;   // 该线路第一个站
        int stop;
        for(int j = 0; j < m; j++) {
            cin >> stop;
            line[first*10000 + stop] = line[stop*10000 + first] = i;  // 记录线路编号
        }
    }
    cin >> k;
    while(k--) {
        minV = INF, minTran = INF;
        tempPath.clear();
        memset(vis, 0, sizeof(vis));
        cin >> st >> ed;
        tempPath.push_back(st);
        vis[st] = true;
        DFS(st);    // 得到path
        vis[st] = false;
        cout << minV << endl;
        int preLine = 0, preTrans = st;
        for(int i = 1; i < path.size(); i++) {  // 对于路径上的每个点
            int pre = path[i-1], now = path[i];
            if(line[pre*10000 + now] != preLine) {  
                if(preLine != 0){   
                    printf("Take Line#%d from %04d to %04d.", preLine, preTrans, pre);
                }
                preLine = line[pre*10000+now];
                preTrans = pre;
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans,ed);
    }
    return 0;
}