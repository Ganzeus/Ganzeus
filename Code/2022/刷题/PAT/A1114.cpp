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
int n;
int father[maxn];
int isRoot[maxn];
void init() {
    for(int i = 1; i < maxn; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = a;
    }
    return x;
}
void Union(int a, int b) {
    int fA = findFather(a);
    int fB = findFather(b);
    if(fA != fB) {
        if(fA > fB) swap(fA, fB);
        father[fB] = fA;    // 小的作为根
    }
}
struct Node {
    int id;
    int size;
    double TS, TA;
};
vector<Node> ans;
bool cmp(Node a, Node b) {
    if(a.TA != b.TA) return a.TA > b.TA;
    else return a.id < b.id;
}
map<int, Node> mp;  // 每个人对应的房产
set<int> people;
int main() {
    init();
    cin >> n;
    int id, f, m, k, ch, mes;
    double area;
    for(int i = 0; i < n; i++) {
        cin >> id >> f >> m >> k;
        people.insert(id);
        if(f != -1) { Union(id, f); people.insert(f); }
        if(m != -1) { Union(id, m); people.insert(m); }
        for(int j = 0; j < k; j++) {
            cin >> ch;
            Union(id, ch);
            people.insert(ch);
        }
        cin >> mes >> area;
        int root = findFather(id);
        mp[root].id = root;
        mp[root].TS += mes;
        mp[root].TA += area;
    }
    for(int i = 1; i < maxn; i++) {
        if(people.find(i) != people.end()) { // 父结点在题目中出现过
            isRoot[findFather(i)]++;
            if(findFather(i) != i) {    // 不是根结点
                mp[findFather(i)].TA += mp[i].TA;   // 自己的房产加到根结点上
                mp[findFather(i)].TS += mp[i].TS;
            }
        }

    }
    int size = 0;
    for(int i = 1; i < maxn; i++) {
        if(isRoot[i]) {
            ans.push_back(mp[i]);
            size++;
        }
    }
    for(int i = 0; i < ans.size(); i++) {   // 计算平均值和总数
        ans[i].size = isRoot[ans[i].id];
        ans[i].TA /= ans[i].size;
        ans[i].TS /= ans[i].size;
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << size << endl;
    for(int i = 0; i < ans.size(); i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].size, ans[i].TS, ans[i].TA);
    }
    return 0;
}