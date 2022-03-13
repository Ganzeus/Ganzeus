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
vector<int> Adj[maxn];  // 邻接表
int n, m, k;
int in[maxn];   // 入度表
vector<int> path[maxn]; // 拓扑序列
void init() {   // 记录入度
    memset(in, 0, sizeof(in));  // 初始化入度为0
    for(int i = 1; i <= n; i++) {   // 遍历整个邻接表
        for(int j = 0; j < Adj[i].size(); j++) {
            in[Adj[i][j]]++;
        }
    }
}
vector<int> ans;    // 答案
int main() {
    cin >> n >> m;
    int v1, v2;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        Adj[v1].push_back(v2);
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        path[i].resize(n);
        for(int j = 0; j < n; j++) cin >> path[i][j];
    }
    for(int i = 0; i < k; i++) {    // 对每个top序列
        init(); // 先初始化入度
        for(int j = 0; j < path[i].size(); j++) {
            int d = path[i][j];
            if(in[d] != 0) {
                ans.push_back(i);
                break;
            }else{
                for(int ii = 0; ii < Adj[d].size(); ii++) { // 当前顶点所有邻接点入度-1
                    in[Adj[d][ii]]--;
                }
            }
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    return 0;
}