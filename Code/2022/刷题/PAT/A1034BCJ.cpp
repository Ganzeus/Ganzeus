#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 2050;
map<string, int> idx;
map<int, string> id;
map<int, int> mp;   // 下标->点权
int father[maxn];
int isRoot[maxn];
void init() {
    for(int i = 0; i < maxn; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    int a = x;
    while(x != father[x]) x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int fA = findFather(a);
    int fB = findFather(b);
    if(fA != fB) {
        if(mp[fA] > mp[fB]) father[fB] = fA;    // 点权大的做根
        else father[fA] = fB;
    }
}
int n, k;
struct Node {
    int v1, v2, d;
};
vector<Node> node; // 边集数组
map<int, int> totalT;   // 每个集合的总时间
int main() {
    init();
    cin >> n >> k;
    string a, b;
    int d;
    int index = 0;
    for(int i = 0; i < n; i++) {    // 读入所有边，记录每个人的点权
        cin >> a >> b >> d;
        if(idx.find(a) == idx.end()) {
            id[index] = a;
            idx[a] = index++;
        }
        if(idx.find(b) == idx.end()) {
            id[index] = b;
            idx[b] = index++;
        }
        mp[idx[a]] += d;
        mp[idx[b]] += d;
        node.push_back(Node{idx[a], idx[b], d});
    }
    for(int i = 0; i < n; i++) {    // 遍历所有边
        int u = node[i].v1, v = node[i].v2;
        Union(u, v);
    }
    for(int i = 0; i < n; i++) {    // 统计每个集合的总时间
        totalT[findFather(node[i].v1)] += node[i].d;    // 总时间加到根结点上
    }
    for(int i = 0; i < index; i++) {    // 对每个人
        isRoot[findFather(i)]++;
    }
    int cnt = 0;
    map<string, int> ans;
    for(int i = 0; i < index; i++) {
        if(isRoot[i] > 2 && totalT[i] > k) {
            ans[id[i]] = isRoot[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    for(auto it = ans.begin(); it != ans.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}