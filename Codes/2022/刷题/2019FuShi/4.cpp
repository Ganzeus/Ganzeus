#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1020;
int G[maxn][maxn];
int d[maxn];    // 最短距离
map<int, int> mp;   // 剩余的救护车数量
bool vis[maxn];
int n, m;   // 结点数、医院树
vector<int> pre[maxn];
void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    for(int i = 1; i <= n + m; i++) {
        int min = INF, u = -1;
        for(int j = 1; j <= n + m; j++) {
            if(!vis[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(!vis[v] && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> tempPath, ans;
vector<vector<int> > wait;
int tmpNum = 0;
int minPaths = INF; // 经过最少条路
void DFS(int v, int st) {   // v初始为医院编号
    if(v == st) {   
        tempPath.push_back(v);
        wait.push_back(tempPath);
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i], st);
    }
    tempPath.pop_back();
}
int k;  // 查询数
int main() {
    fill(G[0], G[0] + maxn*maxn, INF);
    cin >> n >> m;
    int w;
    for(int i = 0; i < m; i++) {
        cin >> w;
        mp[n + i + 1] = w;
    }
    int k;
    cin >> k;
    string c1, c2;
    for(int i = 0; i < k; i++) {
        cin >> c1 >> c2 >> w;
        int v1, v2;
        if(c1[0] == 'A') {
            v1 = stoi(c1.substr(2, c1.size() - 2)) + n;
        }else v1 = stoi(c1);
        if(c2[0] == 'A') {
            v2 = stoi(c2.substr(2, c2.size() - 2)) + n;
        }else v2 = stoi(c2);
        G[v1][v2] = G[v2][v1] = w;
    }
    cin >> k;   // 查询数
    int q;
    for(int i = 0; i < k; i++) {
        wait.clear();
        cin >> q;
        Dijkstra(q);
        vector<int> hosp;
        int minT = INF, maxRemain = -1;
        for(int j = n+1; j <= n+m; j++) {   // 在有剩余救护车的医院中找到最近的, 若时间一样找剩余最多的, 还一样就加入队列
            
            if(mp[j] > 0) {
                if(d[j] < minT) {
                    minT = d[j];
                    maxRemain = mp[j];
                    hosp.clear();
                    hosp.push_back(j);
                }else if(d[j] == minT && mp[j] > maxRemain) {
                    maxRemain = mp[j];
                    hosp.clear();
                    hosp.push_back(j);
                }else if(d[j] == minT && mp[j] == maxRemain) {
                    hosp.push_back(j);
                }
            }
        }
        if(hosp.size() == 0) {    // 没找到有救护车的医院
            cout << "All Busy" << endl;
            continue;
        }
        minPaths = INF;
        for(int j = 0; j < hosp.size(); j++) {
            DFS(hosp[j], q);
            for(int k = 0; k < wait.size(); k++) {
                if(wait[k].size() < minPaths) {
                    minPaths = wait[k].size();
                    ans = wait[k];
                }
            }
        }
        cout << "A-" << ans[0] - n;
        for(int j = 1; j < ans.size(); j++) {
            cout << " " << ans[j];
            
        }
        cout << endl;
        cout << d[ans[0]] << endl;
        mp[ans[0]]--;
    }
    return 0;
}