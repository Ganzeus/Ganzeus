#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 30;

struct node {
    string data;
    int l, r;
}node[maxn];
int n;
bool Hash[maxn];
string DFS(int root) {
    if(root == -1) return "";
    if(node[root].l != -1 && node[root].r != -1) {
        return "(" + DFS(node[root].l) + DFS(node[root].r) + node[root].data + ")";
    }
    if(node[root].l == -1 && node[root].r != -1) {
        return "(" + node[root].data + DFS(node[root].r) + ")";;
    } 
    if(node[root].l == -1 && node[root].r == -1) return "(" + node[root].data + ")";
}
int main() {
    for(int i = 0; i <= maxn; i++) node[i].l = node[i].r = -1;
    cin >> n;
    string d;
    int lc, rc;
    for(int i = 1; i <= n; i++) {
        cin >> d >> lc >> rc;
        if(lc != -1) Hash[lc] = true;
        if(rc != -1) Hash[rc] = true;
        node[i].data = d;
        node[i].l = lc;
        node[i].r = rc;
    }
    int root;
    for(int i = 1; i <= n; i++) {
        if(Hash[i] == false) root = i;
    }
    string ans = DFS(root);
    cout << ans << endl;
    return 0;
}