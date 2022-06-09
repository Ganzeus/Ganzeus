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
const int maxn = 210;
string node[maxn];  //序号转顶点名
map<string, int> mp;  //顶点名转序号
int n, k;   //顶点数，边数
string s;    //起点
int G[maxn][maxn];
bool vis[maxn] { false };
int d[maxn];    //最短路
int num[maxn];  //最短路条数
int weight[maxn];   //点权
vector<int> pre[maxn];  //多重前驱数组
void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    memset(num, 0, sizeof(num));
    d[s] = 0;
    num[s] = 1;
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
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                    num[v] += num[u];
                }
            }
        }
    }
}
vector<int> path, tempPath;
double maxavr = 0.0;    //最大平均点权
int maxw = 0;   //最大点权和
void DFS(int v) {   //v为当前访问结点
    if(v == 0){ //递归到起点（递归边界）
        tempPath.push_back(v);
        int tempw = 0;  //临时点权和
        for(int i = tempPath.size()-1; i >=0; i--) {
            int id = tempPath[i];   //结点序号
            tempw += weight[id];
        }
        //此时已经算好临时点权和tempw
        double avr = 1.0*tempw / (tempPath.size()-1);   //临时平均点权 = 临时点权和/当前路径结点数（去掉起点）
        if(tempw > maxw) {  //先比点权和
            maxw = tempw;
            maxavr = avr;
            path = tempPath;
        }else if(tempw == maxw && avr > maxavr) {   //点权和相等再比平均点权
            maxavr = avr;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {    //递归遍历当前结点的所有前驱
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
int main() {
    fill(G[0], G[0] + maxn*maxn, INF);
    memset(weight, 0, sizeof(weight));
    cin >> n >> k >> s;
    node[0] = s;    //序号为0的是起点
    mp[s] = 0;      //起点序号为0
    
    for(int i = 1; i <= n-1; i++) {  //n-1行
        string name;
        cin >> name >> weight[i];
        mp[name] = i;   //顶点序号
        node[i] = name; //顶点名
    }
    for(int i = 0; i < k; i++) {    //k行
        string name1, name2;
        int cost;
        cin >> name1 >> name2 >> cost;
        int c1 = mp[name1], c2 = mp[name2];
        G[c1][c2] = G[c2][c1] = cost;
    }
    Dijkstra(0);
    int rom = mp["ROM"];    //rom记录终点序号
    DFS(rom);
    printf("%d %d %d %d\n", num[rom], d[rom], maxw, (int)maxavr);
    for(int i = path.size()-1; i >= 0; i--) {
        cout << node[path[i]];
        if(i != 0) cout << "->";
    }
    return 0;
}