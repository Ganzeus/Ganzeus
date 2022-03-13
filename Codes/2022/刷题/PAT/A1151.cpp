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
int m, n;
int pre[maxn], in[maxn];
map<int, int> pos;  // 结点在中序的位置
void LCA(int preL, int preR, int inL, int inR, int a, int b) {
    if(preL > preR) return;
    int pRoot = pos[pre[preL]], pa = pos[a], pb = pos[b];   // 根结点、查询结点在中序中的序号（保证存在）
    int numLeft = pRoot - inL;  // 左子树结点个数
    if(pa < pRoot && pb < pRoot) {  // 查询结点都在根结点左边
        LCA(preL + 1, preR + numLeft, inL, pRoot-1, a, b);  // 往左子树查询
    }else if((pa < pRoot && pb > pRoot) || (pb < pRoot && pa > pRoot)) {    
        // a和b在根结点两边，说明根结点即为a和b的LCA
        printf("LCA of %d and %d is %d.\n", a, b, pre[preL]);
    }else if(pa > pRoot && pb > pRoot) {    // 查询结点都在根结点右边
        LCA(preL + numLeft + 1, preR, pRoot + 1, inR, a, b);
    }else if(pa == pRoot) { // a是b的LCA
        printf("%d is an ancestor of %d.\n", a, b);
    }else if(pb == pRoot) { // b是a的LCA    
        printf("%d is an ancestor of %d.\n", b, a);
    }
}
int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    for(int i = 1; i <= n; i++) cin >> pre[i];
    int a, b;
    while(m--) {
        cin >> a >> b;
        if(pos[a] == 0 && pos[b] == 0) {    // 都不存在
            printf("ERROR: %d and %d are not found.\n", a, b);
        }else if(pos[a] == 0 || pos[b] == 0) {
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        }else {
            LCA(1, n, 1, n, a, b);
        }
    }
    return 0;
}