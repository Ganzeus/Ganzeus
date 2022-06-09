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
const int maxn = 320;
int n, m, k;
map<string, int> indx; // id->编号
map<int, string> id;
vector<int> Adj[maxn];  // 邻接表
bool G[maxn][maxn];
struct Node {
    int c, d;
};
vector<Node> ans;
bool cmp(Node a, Node b) {
    if(a.c != b.c) return a.c < b.c;
    else return a.d < b.d;
}
int main() {
    cin >> n >> m;
    string c1, c2;
    int index = 0;
    for(int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        if(indx.find(c1) == indx.end()) {   // 没出现过
            indx[c1] = index++;   // 记录下标
            id[indx[c1]] = c1;  // 记录id
        }
        if(indx.find(c2) == indx.end()) {
            indx[c2] = index++;
            id[indx[c2]] = c2;
        }
        Adj[indx[c1]].push_back(indx[c2]);
        Adj[indx[c2]].push_back(indx[c1]);
        G[indx[c1]][indx[c2]] = G[indx[c2]][indx[c1]] = true;
    }
    cin >> k;
    while(k--) {
        string A, B, C, D;
        int cnt = 0;
        vector<Node> v;
        cin >> A >> B;
        if(indx.find(A) != indx.end() && indx.find(B) != indx.end()) {  // AB都存在
            int indA = indx[A], indB = indx[B]; // A和B的下标
            for(int i = 0; i < Adj[indA].size(); i++) { // 在A的邻接点中找同性别的
                C = id[Adj[indA][i]];
                int indC = indx[C];
                if(C.length() == A.length() && C != B) {  // 同号且不是B (字符串长度相等说明同号)
                    for(int j = 0; j < Adj[indC].size(); j++) {  // 在C的邻接点中找和B同性别的
                        D = id[Adj[indC][j]];
                        int indD = indx[D];
                        if(D.length() == B.length() && G[indD][indB] == true && D != A) {  // B和D同性别且邻接
                            v.push_back(Node{abs(stoi(C)), abs(stoi(D))});
                            cnt++;
                        } 
                    }
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        cout << cnt << endl;
        for(int i = 0; i < cnt; i++) {
            printf("%04d %04d\n", v[i].c, v[i].d);
        }
    }

    return 0;
}