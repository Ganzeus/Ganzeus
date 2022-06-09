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
int main() {
    init();
    cin >> beg >> n >> k;
    int addr;
    for(int i = 0; i < n; i++) {
        cin >> addr;
        node[addr].address = addr;
        cin >> node[addr].data >> node[addr].next;
    }
    int p = beg, cnt = 0, index = 0;
    while(p != -1) {
        cnt++;
        node[p].order = index++;
        p = node[p].next;
    }
    n = cnt;
    sort(node, node + maxn, cmp);
    int i = n - n % k;
    if(i != n) {    // 输出多余结点
        for(int j = i; j < n-1; j++) {
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j+1].address);
        }
        // 对于最后一个结点
        if(n < k) {
            printf("%05d %d -1\n", node[n-1].address, node[n-1].data);
        }else printf("%05d %d %05d\n", node[n-1].address, node[n-1].data, node[i-k].address);
    }
    i -= k;
    for(; i >= 0; i-=k) {
        int j = i;
        for(; j < i + k - 1; j++) {
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j+1].address);
        }
        // 对于最后一个结点
        if(i == 0) printf("%05d %d -1\n", node[j].address, node[j].data);
        else printf("%05d %d %05d\n", node[j].address, node[j].data, node[i-k].address);
    }
    return 0;
}