#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include<unordered_map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 100010;
int sum[maxn];  // 前缀和数组
int n, m;
int main() {
    cin >> n;
    sum[0] = 0;
    int input;
    for(int i = 1; i <= n; i++) { 
        cin >> input;
        sum[i] = sum[i-1] + input;
    }
    cin >> m;
    int c1, c2;
    for(int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        if(c1 > c2) swap(c1, c2);
        int dis = sum[c2-1] - sum[c1-1];
        int rev = sum[n] - dis;
        cout << min(dis, rev) << endl;
    }

    return 0;
}