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
int X[6] = {0, 0, 1, -1, 0, 0};
int Y[6] = {0, 0, 0, 0, 1, -1};
int Z[6] = {1, -1, 0, 0, 0, 0};
int m, n, l, t;
int brain[1300][140][80];   // (x, y, z)
int ans; 
bool vis[1300][140][80];
struct Node{
    int x, y, z;
};
bool judge(int x, int y, int z) {
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(brain[x][y][z] == 0 || vis[x][y][z] == true) return false;
    return true; 
}
int BFS(int x, int y, int z) { // 返回一整块的1的个数
    queue<Node> q;
    int cnt = 0;    // 当前块1的个数
    q.push(Node{x, y, z});
    vis[x][y][z] = true;
    while(!q.empty()) {
        Node front = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i < 6; i++) {    // 对于6个邻接点
            int fx = front.x + X[i];
            int fy = front.y + Y[i];
            int fz = front.z + Z[i];
            if(fx < m && fx >= 0 && fy < n && fy >= 0 && fz < l && fz >= 0 && !vis[fx][fy][fz] && brain[fx][fy][fz] == 1) {
                // 先判断是否越界
                q.push(Node{fx, fy, fz});
                vis[fx][fy][fz] = true;
            }
        }
    }
    // return cnt;
    if(cnt >= t) return cnt;
    else return 0;
}
int main() {
    cin >> m >> n >> l >> t;
    for(int z = 0; z < l; z++)
        for(int x = 0; x < m; x++)
            for(int y = 0; y < n; y++)
                cin >> brain[x][y][z];
    for(int z = 0; z < l; z++)
        for(int x = 0; x < m; x++)
            for(int y = 0; y < n; y++) 
                if(!vis[x][y][z] && brain[x][y][z] == 1)
                    ans += BFS(x, y, z);
    cout << ans << endl;
    return 0;
}