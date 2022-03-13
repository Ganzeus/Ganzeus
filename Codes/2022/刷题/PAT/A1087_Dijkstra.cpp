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
int w[maxn];    //最短点权和
int weight[maxn];   //点权
int num[maxn];  //最短路径条数
int dnum[maxn]; //最短路径上顶点数目
int pre[maxn];  //前驱数组
void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    memset(dnum, 0, sizeof(dnum));
    for(int i = 0; i < n; i++)  pre[i] = i; //初始化前驱为自身
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[0];
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
                if(d[u] + G[u][v] < d[v]){  //先比最短路
                    d[v] = d[u] + G[u][v];  //更新最短路经
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    dnum[v] = dnum[u] + 1;  //当前路径顶点个数+1
                    pre[v] = u;
                }else if(d[u] + G[u][v] == d[v]){   //最短路相等
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v]){    //再比点权和
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                        dnum[v] = dnum[u] + 1;
                    }else if(w[u] + weight[v] == w[v]){   //最短路和点权和都相等
                        //计算平均点权
                        double uavr = 1.0*(w[u] + weight[v]) / (dnum[u] + 1);   //以u为中介
                        double vavr = 1.0*w[v] / dnum[v];   //不以u为中介
                        if(uavr > vavr) {   //平均点权更大
                            dnum[v] = dnum[u] + 1;
                            pre[v] = u;
                        }
                    }
                }
            }  
        }
    }
}
void printPath(int v) {  //s为起点，v为当前访问结点
    if(v == 0) {
        cout << node[v];
        return;
    }
    printPath(pre[v]);  //递归前驱结点
    cout << "->" << node[v];
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
    int rom = mp["ROM"];    //获取终点序号
    // cout << dnum[rom];
    printf("%d %d %d %d\n",num[rom], d[rom], w[rom], w[rom]/dnum[rom]);
    printPath(rom);
    return 0;
}