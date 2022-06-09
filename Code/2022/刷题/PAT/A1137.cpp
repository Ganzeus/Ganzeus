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
const int maxn = 30010;
struct Node {
    string id;
    int Gp, Gm, Gf, G;
}node[maxn];
map<string, int> mp;    // （姓名，下标）
int p, n, m;
bool cmp(Node a, Node b) {
    if(a.G != b.G) return a.G > b.G;
    else return a.id < b.id;
}

int main() {
    for(int i = 0; i < maxn; i++) node[i].Gm = node[i].Gf = node[i].G = -1;
    cin >> p >> m >> n;
    string name;
    int score;
    int index = 1;  // 下标由1开始，0表示不存在
    for(int i = 0; i < p; i++) {
        cin >> name >> score;
        if(score >= 200) {  // 只存放Gp>=200的
            node[index].id = name;
            node[index].Gp = score;
            mp[name] = index++;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> name >> score;
        if(mp[name] != 0) { // 等于0表示不存在，不需要存
            node[mp[name]].Gm = score;
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> name >> score;
        if(mp[name] != 0) {
            int m = node[mp[name]].Gm;
            node[mp[name]].Gf = node[mp[name]].G = score;
            if(m > score) node[mp[name]].G = m*0.4 + score*0.6 + 0.5;
        }
    }
    vector<Node> ans;
    for(int i = 0; i < index; i++) {
        if(node[i].G >= 60){    // 只存放总分>=60的
            ans.push_back(node[i]);
        }   
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].id;
        printf(" %d %d %d %d\n", ans[i].Gp, ans[i].Gm, ans[i].Gf, ans[i].G);
    }
    return 0;
}