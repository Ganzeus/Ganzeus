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
const int maxn = 30;
struct Node {
    string data;
    int lchild, rchild;
}node[maxn];
int n, root;
bool Hash[maxn];
string dfs(int root) {
    if(node[root].lchild == -1 && node[root].rchild == -1) {    // 左右都空，返回根
        return node[root].data;
    }
    if(node[root].lchild == -1 && node[root].rchild != -1) {    // 左空右不空，返回"(+根+右"
        return "(" + node[root].data + dfs(node[root].rchild) + ")";
    }
    if(node[root].lchild != -1 && node[root].rchild != -1) {    // 左右都不空，返回"(左+根+右)"
        return "(" + dfs(node[root].lchild) + node[root].data + dfs(node[root].rchild) + ")";
    }
    return "";
}

int main() {
    for(int i = 0; i < maxn; i++) node[i].lchild = node[i].rchild = -1;
    cin >> n;
    int l, r;
    for(int i = 1; i <= n; i++) {
        cin >> node[i].data;
        cin >> l >> r;
        if(l != -1) {
            node[i].lchild = l;
            Hash[l] = true;
        }
        if(r != -1) {
            node[i].rchild = r;
            Hash[r] = true;
        }        
    }
    for(int i = 1; i <= n; i++){
        if(Hash[i] == false){
            root = i;
            break;
        }
    }
    string ans = dfs(root);
    if(ans[0] == '(') ans = ans.substr(1, ans.size() - 2);
    cout << ans << endl;
    return 0;
}