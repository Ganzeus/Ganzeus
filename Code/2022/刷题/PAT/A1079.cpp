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
const int maxn = 100010;

struct Node{
    vector<int> children;
    int amount;
}node[maxn];

int n;
double p, r;
double rate;
double ans = 0;
void DFS(int id, int level) {
    if(node[id].children.size() == 0)  {    // 叶子结点
        ans += node[id].amount * pow(rate, level);
        return;
    }
    for(int i = 0; i < node[id].children.size(); i++) {
        DFS(node[id].children[i], level + 1);
    }
}
int main() {
    cin >> n >> p >> r;
    rate = 1 + r/100;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num == 0) {
            cin >> node[i].amount;
            continue;
        }
        int id;
        while(num--) {
            cin >> id;
            node[i].children.push_back(id);
        }
    }
    DFS(0, 0);
    ans *= p;
    printf("%.1f\n", ans);
    
    return 0;
}