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
const int maxn = 10020;
int n, m, k;
struct Node{
    int v1, v2;
}node[maxn];    // 边集数组
int color[maxn];    // 存放顶点颜色
set<int> num;   // 颜色个数
int main() {
    cin >> n >> m;
    int c1, c2;
    for(int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        node[i].v1 = c1, node[i].v2 = c2;
    }
    cin >> k;
    while(k--){
        num.clear();
        for(int i = 0; i < n; i++) {
            cin >> color[i];
            num.insert(color[i]);
        }
        int flag = true;
        for(int i = 0; i < m; i++) {    // 枚举所有边
            if(color[node[i].v1] == color[node[i].v2]){
                flag = false;
                break;
            }
        }
        if(flag) cout << num.size() << "-coloring" << endl;
        else cout << "No" << endl;
    }
    return 0;
}