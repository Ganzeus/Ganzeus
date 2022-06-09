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

struct Node {
    int address;
    int data;
    int next;
    int order;
    int flag;   // flag = 1表示有效结点
    int flag1, flag2;   // flag1为0表示<=k, flag2为0表示<0
}node[maxn];
int st, n, k;
void init() {
    for(int i = 0; i < maxn; i++) {
        node[i].next = node[i].order = -1;
        node[i].flag = 0;
    }
}
bool cmp(Node a, Node b) {
    if(a.flag == 0 || b.flag == 0) return a.flag > b.flag;  // 有效结点排前面
    else if(a.flag1 != b.flag1) return a.flag1 < b.flag1;   // 小于k的在前
    else if(a.flag2 != b.flag2) return a.flag2 < b.flag2;   // 小于0的在前
    else return a.order < b.order;  // 按链表顺序排
}
int main() {
    cin >> st >> n >> k;
    int addr;
    for(int i = 0; i < n; i++) {
        cin >> addr;
        node[addr].address = addr;
        cin >> node[addr].data >> node[addr].next;
    }

    int q = st, cnt = 0;
    while(q != -1) {
        node[q].order = cnt++;
        node[q].flag = 1;
        if(node[q].data <= k) node[q].flag1 = 0;
        else node[q].flag1 = 1;
        if(node[q].data < 0) node[q].flag2 = 0;
        else node[q].flag2 = 1;
        q = node[q].next;
    }
    sort(node, node + maxn, cmp);
    for(int i = 0; i < cnt; i++) {
        if(i == cnt-1) {    // 最后一个结点
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }else {
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
        }

    }
    return 0;
}