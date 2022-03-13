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
int G[maxn][maxn];
int n, m, k;
map<int, int> ts;   // (路径长度，编号)

int main() {
    fill(G[0], G[0] + maxn * maxn, INF);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int c1, c2, dis;
        cin >> c1 >> c2 >> dis;
        G[c1][c2] = G[c2][c1] = dis;
    }
    cin >> k;
    for(int i = 1; i <= k; i++) {
        int num;
        cin >> num;
        int sum = 0;
        vector<int> tmp;
        for(int j = 0; j < num; j++) {
            int c;
            cin >> c;
            tmp.push_back(c);
        }
        set<int> path;
        bool flag = 1;
        for(int j = 1; j < num; j++) {
            int pre = tmp[j-1], cur = tmp[j];
            if(G[pre][cur] == INF){
                flag = 0;
                break;
            }
            sum += G[pre][cur];
            path.insert(pre);path.insert(cur);
        }
        cout << "Path " << i << ": ";
        if(flag == 0) cout << "NA ";
        else 
            cout << sum << " ";
        if(path.size() < n || tmp[0] != tmp[tmp.size()-1])
            cout << "(Not a TS cycle)" << endl;
        else if(path.size() == n && num == n + 1) {
            cout << "(TS simple cycle)" << endl; 
            ts[sum] = i;
        }
        else if(path.size() == n && num > n+1) {
            cout << "(TS cycle)" << endl;
            ts[sum] = i;
        }    
    }
    map<int, int>::iterator it = ts.begin();
    printf("Shortest Dist(%d) = %d", it->second, it->first);
    return 0;
}
