#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;

struct Node {
    int address;
    int data;
    int next;
    int order;
}node[maxn];
void init() {
    for(int i = 0; i < maxn; i++) {
        node[i].next = -1;
        node[i].order = maxn;
    }
}
bool cmp(Node a, Node b) {
    return a.order < b.order;
}
int beg, n, k;
vector<Node> ans;
int main() {
    init();
    cin >> beg >> n >> k;
    int addr;
    for(int i = 0; i < n; i++) {
        cin >> addr;
        node[addr].address = addr;
        cin >> node[addr].data >> node[addr].next;
    }
    int p = beg, index = 0;
    while(p != -1) {
        node[p].order = index++;
        p = node[p].next;
    }
    n = index;
    sort(node, node + maxn, cmp);
    for(int i = n-1; i >= k; i--) {
        ans.push_back(node[i]);
    }
    // for(int i = 0; i < ans.size(); i++) cout << ans[i].data;
    int pos = 0;
    for(int i = k-1; i >= 0; i--) {
        ans.insert(min(ans.begin() + pos, ans.end()), node[i]);
        pos += 2;
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != ans.size() - 1) printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i+1].address);
        else printf("%05d %d -1\n", ans[i].address, ans[i].data);
    }
    return 0;
}