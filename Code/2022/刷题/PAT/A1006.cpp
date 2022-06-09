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
const int maxn = 1020;

struct Node{
    string id;
    int inh, inm, ins;
    int outh, outm, outs;
}node[maxn];
bool cmpin(Node a, Node b) {
    if(a.inh != b.inh) return a.inh < b.inh;
    else if(a.inm != b.inm) return a.inm < b.inm;
    else return a.ins < b.ins;
}
bool cmpout(Node a, Node b) {
    if(a.outh != b.outh) return a.outh > b.outh;
    else if(a.outm != b.outm) return a.outm > b.outm;
    else return a.outs > b.outs; 
}
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> node[i].id;
        scanf("%d:%d:%d %d:%d:%d", &node[i].inh, &node[i].inm, &node[i].ins, &node[i].outh, &node[i].outm, &node[i].outs);
    }
    sort(node, node + n, cmpin);
    cout << node[0].id << " ";
    sort(node, node + n, cmpout);
    cout << node[0].id << endl;
    return 0;
}