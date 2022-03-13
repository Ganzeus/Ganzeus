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
int n;
double p, r;
double rate;
int minLevel = INF;   // 叶子的最小层数
int numLeaves = 0;    // 最小层数的叶子个数
vector<int> children[maxn];
void DFS(int id, int level) {
    
    if(children[id].size() == 0) {
        if(level < minLevel) {
            minLevel = level;
            numLeaves = 1;
        }else if(level == minLevel) {
            numLeaves++;
        }
        return;
    }
    for(int i = 0; i < children[id].size(); i++) {
        DFS(children[id][i], level + 1);
    }
}
int main() {
    cin >> n >> p >> r;
    rate = 1 + r/100;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        while(num--) {
            int child;
            cin >> child;
            children[i].push_back(child);
        }
    }
    DFS(0, 0);
    printf("%.4f %d", p * pow(rate, minLevel), numLeaves);
    return 0;
}