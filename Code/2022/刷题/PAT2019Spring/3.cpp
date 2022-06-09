#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 1010;
vector<int> suspect;
set<int> shortcall[maxn];
set<int> in[maxn];
int G[maxn][maxn];  // 存放每个人打某个人电话的总时间
int K, m, n;
set<int> group[maxn];
map<int, int> father;
int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
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
        if(fA > fB) father[fA] = fB;
        else father[fB] = fA;
    }
}
int main() {
    cin >> K >> n >> m;
    int call, rec, d;
    for(int i = 0; i < m; i++) {
        cin >> call >> rec >> d;
        G[call][rec] += d;
        in[rec].insert(call);
        // if(d <= 5) shortcall[call].insert(rec);
    }
    // for(int i = 1; i <= n; i++) {   // 对每个人
    //     int toNum = 0, backNum = 0;
    //     for(int j = 1; j <= n; j++) {
    //         if(G[i][j] > 0 && G[i][j] <= 5){
    //             toNum++;
    //             if(G[j][i] > 0) backNum++;  // 打过去的人有人打回来
    //         }
    //     }
    //     if(toNum > K && backNum * 1.0 / toNum <= 0.2) suspect.push_back(i);
    // }
    for(int i = 1; i <= n; i++) {   // 对每个人
        for(int j = 1; j <= n; j++) {
            if(G[i][j] > 0 && G[i][j] <= 5)
                shortcall[i].insert(j);
        }
    }
    for(int i = 1; i <= n; i++) {   // 遍历每个人
        if(shortcall[i].size() > K) {   // 短电话超过K人
            int cntin = 0;  // 记录打回来的人
            for(set<int>::iterator it = in[i].begin(); it != in[i].end(); it++) {
                if(shortcall[i].find(*it) != shortcall[i].end()) {
                    cntin++;
                }
            }
            if(cntin * 1.0 / shortcall[i].size() <= 0.2) suspect.push_back(i);
        }
    }
    if(suspect.size() == 0) cout << "None" << endl;
    else {
        for(int i = 0; i < suspect.size(); i++) father[suspect[i]] = suspect[i];
        for(int i = 0; i < suspect.size(); i++) {   // 遍历嫌疑犯
            for(int j = i+1; j < suspect.size(); j++) {
                if(G[suspect[i]][suspect[j]] > 0 && G[suspect[j]][suspect[i]] > 0) {
                    Union(suspect[i], suspect[j]);
                }
            }
        }
        int size = 0;
        for(int i = 0; i < suspect.size(); i++) {
            group[findFather(suspect[i])].insert(suspect[i]);  // 存放根结点
        }
        for(int i = 0; i < suspect.size(); i++) {
            for(auto it = group[suspect[i]].begin(); it != group[suspect[i]].end(); it++) {
                if(it != group[suspect[i]].begin()) cout << " ";
                cout << *it;
            }
            if(group[suspect[i]].size() != 0) cout << endl;
        }

    }
    return 0;
}