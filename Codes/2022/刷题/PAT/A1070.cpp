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
struct Node {
    double p, price;
    double amount;
}node[maxn];
bool cmp(Node a, Node b) {  // 按单价降序
    return a.p > b.p;
}
int n, total;
int main() {
    cin >> n >> total;
    for(int i = 0; i < n; i++) {
        cin >> node[i].amount;
    }
    for(int i = 0; i < n; i++) {
        cin >> node[i].price;
        node[i].p = node[i].price / node[i].amount;
    }
    sort(node, node + n, cmp);
    double ans = 0;
    for(int i = 0; i < n && total != 0; i++){
        if(total >= node[i].amount) {
            ans += node[i].price;
            total -= node[i].amount;
        }
        else {
            ans += total * 1.0/node[i].amount * node[i].price;
            total = 0;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}