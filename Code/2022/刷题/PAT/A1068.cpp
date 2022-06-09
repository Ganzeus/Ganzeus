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
const int maxn = 10010;
int n, m;
int coins[maxn];
void cal(int d, int m, vector<int>& path) {
    path.push_back(coins[d]);
    m -= coins[d];
    if(m < 0) {
        m += path.front();
        path.pop_back();
        m += path.front();
        path.pop_back();
        cal(d, m, path);
    }
    else if(m == 0) return;
    else if(d+1 < n-1) {

        cal(d+1, m, path);
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + n);
    vector<int> path;

    return 0;
}