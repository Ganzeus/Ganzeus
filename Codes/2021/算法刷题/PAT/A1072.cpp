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
const int maxn = 1020;
int G[maxn][maxn];
int d[maxn];
bool vis[maxn];
int n, m, k, Ds;    //居民房数，加油站数，边数，最大服务范围

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for(int i = 0; i < n+m; i++) {
        int u = -1, min = INF;
        for(int j = 1; j <= n+m; j++){  //下标从1开始
            if(!vis[j] && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n+m; v++) {
            if(!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}
int getID(string str) {
    int id = 0;
    int i = 0, len = str.length();
    while(i < len) {
        if(str[i] != 'G') {  //只要不是G
            id = id*10 + str[i]-'0';
        }
        i++;
    }
    if(str[0] == 'G') return id + n;    //加油站
    else return id; //居民房
}
int main() {
    fill(G[0], G[0] + maxn*maxn, INF);
    cin >> n >> m >> k >>Ds;
    string c1, c2;
    int u, v, dis;
    for(int i = 0; i < k; i++) {
        
        cin >> c1 >> c2 >> dis;
        u = getID(c1);
        v = getID(c2);
        G[u][v] = G[v][u] = dis;
    }
    double ansavr = INF;    //最小平均距离
    double minD = -1; //居民房与加油站最大的最近距离
    int ansID = -1; //最终的加油站id
    for(int i = n+1; i <= n+m; i++) {  //对于所有加油站
        Dijkstra(i);    //求出d数组
        double tempavr = 0.0;    //最短距离和
        int tempd = INF;     //当前最近距离
        for(int j = 1; j <= n; j++){ //遍历居民房与加油站最短距离,计算当前平均距离tempavr与最短距离tempd
            if(d[j] > Ds){  //超过最远服务范围,直接跳出
                tempd = -1;
                break;
            }
            tempavr += d[j] * 1.0 / n;
            if(d[j] < tempd) tempd = d[j];    //更新最短距离
        }
        if(tempd == -1) continue;    //存在超过最远服务范围的点,该加油站跳过
        if(tempd > minD){    // 当前最短距离比最大最短距离大
            minD = tempd;    // 更新最大最短距离
            ansavr = tempavr;
            ansID = i;      //记录id
        }else if(tempd == minD) { // 最短距离相同，比平均距离
            if(tempavr < ansavr) { //最小总距离
                ansavr = tempavr;
                ansID = i;
            }
        }
    }
    if(ansID == -1) { // 无解
        printf("No Solution\n");
    }else {
        printf("G%d\n", ansID-n);
        printf("%.1f %.1f\n", minD, ansavr);
    }
    return 0;
}