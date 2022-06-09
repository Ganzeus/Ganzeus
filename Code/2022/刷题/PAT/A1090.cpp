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
    int level;
    vector<int> children;
}node[maxn];
int n;
double p, r;
double rate;
int maxLevel = 0;
int root;
void DFS(int id, int level) {
    node[id].level = level;
    if(node[id].children.size() == 0) {
        if(level > maxLevel) maxLevel = level;
        return;
    }
    for(int i = 0; i < node[id].children.size(); i++) {
        DFS(node[id].children[i], level + 1);
    }
}
int main() {
    cin >> n >> p >> r;
    rate = 1 + r/100;
    int father;
    for(int i = 0; i < n; i++) {
        cin >> father;
        if(father == -1) {
            root = i;
        }else {
            node[father].children.push_back(i);
        }

    }
    DFS(root, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(node[i].level == maxLevel) ans++;
    }
    printf("%.2f ",p * pow(rate, maxLevel));
    cout << ans << endl;
    return 0;
}