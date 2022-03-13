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
vector<int> Adj[maxn];  // 邻接表
int n, l, k;
bool inq[maxn];
struct Node{
    int u;
    int depth;
    Node(int u_, int depth_):u{u_}, depth{depth_}{}
};
int BFS(int s, int depth) {   // s为起点, depth为起点深度
    queue<Node> q;
    q.push(Node{s, depth});
    inq[s] = true;
    int cnt = 0;
    while(!q.empty()) {
        Node front = q.front();
        q.pop();
        int u = front.u;
        for(int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if(!inq[v] && front.depth + 1 <= l){
                q.push(Node{v, front.depth + 1});
                inq[v] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    cin >> n >> l;
    int m;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        int father;
        while(m--) {
            cin >> father;
            Adj[father].push_back(i);
        }
    }
    cin >> k;
    while(k--) {
        memset(inq, false, sizeof(inq));
        int st;
        cin >> st;
        int cnt = BFS(st, 0);
        cout << cnt << endl;
    }
    return 0;
}