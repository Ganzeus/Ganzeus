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
int CBT[maxn];
int n;
void inOrder(int v, vector<int>& tmp) {    // 得到完全二叉树中序序列
    if(v*2 <= n) {  // 左子树存在
        inOrder(v*2, tmp);
    }
    tmp.push_back(v-1);     // 题目序列由0开始
    if(v*2+1 <= n) {    // 右子树存在
        inOrder(v*2+1, tmp);
    }
}
int main() {
    cin >> n;
    vector<int> init, path;
    int d;
    for(int i = 0; i < n; i++) {    // 读入题目序列
        cin >> d;
        init.push_back(d);
    }
    sort(init.begin(), init.end());
    inOrder(1, path);   // 1为完全二叉树根
    for(int i = 0; i < path.size(); i++) {
        CBT[path[i]] = init[i];
    }
    for(int i = 0; i < n; i++) {
        cout << CBT[i];
        if(i != n-1) cout << " ";
    }
    return 0;
}