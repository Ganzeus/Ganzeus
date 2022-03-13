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
struct Node {
    int v1, v2;
}node[maxn];
int n, m, k;
set<int> s;
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> node[i].v1 >> node[i].v2;
    }
    cin >> k;
    while(k--) {
        s.clear();
        int num;
        cin >> num;
        int d;
        for(int i = 0; i < num; i++) {
            cin >> d;
            s.insert(d);
        }
        bool flag = true;
        for(int i = 0; i < m; i++) {    // 对每条边
            if(s.find(node[i].v1) == s.end() && s.find(node[i].v2) == s.end()) {   // 只要有一条边的两个点都不在集合内
                flag = false;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}