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
const int maxn = 1010;
int n, m, k;
int G[maxn][maxn];
int copy[maxn][maxn];   //邻接矩阵副本
int concern[maxn];
queue<int> q;
bool inq[maxn] = { false };
void BFS(int s, int del) {   // 遍历s所在连通分支，del为被删除的结点
    // 起点s不可能被删除，因为起点是在main函数中检查
    q.push(s);
    inq[s] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {   //枚举所有顶点
            if(!inq[i] && G[front][i] != INF && i != del) { // i未入过队 && front与i有边 && i未被删除
                q.push(i);
                inq[i] = true;
            }
        }
    }
}
int main() {
    fill(G[0], G[0] + maxn*maxn, INF);
    cin >> n >> m >> k;
    int c1, c2;
    for(int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        G[c1][c2] = G[c2][c1] = 1;
    }
    for(int i = 0; i < k; i++) {
        cin >> concern[i];
    }
    for(int i = 0; i < k; i++) {
        int u = concern[i]; // 当前要"删除"的顶点
        int block = 0;  // 连通块个数，初始化为0
        memset(inq, false, sizeof(inq));
        for(int j = 1; j <= n; j++) {   // 对于每个顶点
            if(!inq[j] && j != u) { // 未入过队 && 未被删除
                BFS(j, u);
                block++;
            }
        }
        cout << block-1 << endl;
    }

    return 0;
}