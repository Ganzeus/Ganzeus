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
#include <unordered_map>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 220;
bool G[maxn][maxn];
int n, m, k;
int main() {
    cin >> n >> m;
    int v1, v2;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = true;
    }
    for(int i = 1; i <= n; i++) G[i][i] = true;
    cin >> k;
    vector<int> v;
    set<int> s;
    while(k--) {
        int num;
        v.clear();
        s.clear();
        cin >> num;
        int d;
        for(int i = 0; i < num; i++) {
            cin >> d;
            s.insert(d);
            v.push_back(d);
        }
        bool isClique = true;
        for(int i = 0; i < num; i++) {  // 判断每两个点是否邻接
            for(int j = i; j < num; j++) {
                if(G[v[i]][v[j]] == false) {
                    isClique = false;
                    cout << "Not a Clique" << endl;
                    break;
                }
            }
            if(!isClique) break;
        }
        if(!isClique) continue;
        bool notMax = false;
        for(int i = 1; i <= n; i++) {
            if(s.find(i) == s.end()) {  // 其他点
                bool canAdd = true;
                for(int j = 0; j < num; j++) {  // 对集合每个点
                    if(G[v[j]][i] == false) {   // 只要有一个不邻接
                        canAdd = false; // 这个点加不了
                        break;   
                    }
                }
                if(canAdd) notMax = true;   // 有一个可以加
            }
        }
        if(notMax) cout << "Not Maximal" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}