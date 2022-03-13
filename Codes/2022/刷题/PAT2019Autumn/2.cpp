#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;

struct Node {
    int address;
    int data;
    int next;
    int pre;
}node[maxn];
int beg1, beg2;
int n;
void init() {
    for(int i = 0; i < maxn; i++) {
        node[i].next = -1;
        node[i].pre = -1;
    }
}
vector<Node> ans;
void merge(int p1, int p2) {    // p1长，p2短
    int cnt = 0;
    while(p1 != -1) {
        ans.push_back(node[p1]);
        cnt++;
        if(cnt % 2 == 0 && p2 != -1) {
            ans.push_back(node[p2]);
            p2 = node[p2].pre;
        }
        p1 = node[p1].next;
    }
}
int main() {
    init();
    cin >> beg1 >> beg2 >> n;
    int addr;
    for(int i = 0; i < n; i++) {
        cin >> addr;
        node[addr].address = addr;
        cin >> node[addr].data >> node[addr].next;
    }
    int p = beg1, len1 = 0, len2 = 0;
    int end1;
    while(p != -1) {
        len1++;
        if(node[p].next == -1) end1 = p;
        node[node[p].next].pre = node[p].address;
        p = node[p].next;
    }
    p = beg2;
    int end2;
    while(p != -1) {
        len2++;
        if(node[p].next == -1) end2 = p;
        node[node[p].next].pre = node[p].address;
        p = node[p].next;
    }
    
    if(len1 >len2) merge(beg1, end2);
    else merge(beg2, end1);
    for(int i = 0; i < ans.size(); i++) {
        if(i != ans.size() - 1) printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i+1].address);
        else printf("%05d %d -1\n", ans[i].address, ans[i].data);
    }

    return 0;
}