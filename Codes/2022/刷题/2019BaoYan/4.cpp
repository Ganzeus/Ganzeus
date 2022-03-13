#include <bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;

int n, m, k;
vector<int> Adj[maxn];
set<int> circle;
map<int, int> mp;   // 存放结点度数
struct Node {
    int id, num;
};
vector<Node> ans;
bool cmp(Node a, Node b) {
    if(a.num != b.num) return a.num > b.num;
    else return a.id < b.id;
}
int main() {
    cin >> n >> m;
    int c1, c2;
    for(int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        Adj[c1].push_back(c2);
        Adj[c2].push_back(c1);
    }
    while(cin >> k) {
        if(k == 0) return 0;
        else {
            ans.clear();
            circle.clear();
            mp.clear();
            int d;
            while(k--) {
                cin >> d;
                circle.insert(d);
            }
            for(auto it = circle.begin(); it != circle.end(); it++) {
                int v = *it;
                mp[v] = 0;
                for(int i = 0; i < Adj[v].size(); i++) {
                    int u = Adj[v][i];
                    if(circle.find(u) != circle.end()) {
                        mp[v]++;
                    }
                }
            }
            for(auto it = mp.begin(); it != mp.end(); it++) {
                ans.push_back(Node{it->first, it->second});
            }
            sort(ans.begin(), ans.end(), cmp);
            for(int i = 0; i < 3; i++) {
                cout << ans[i].id;
                if(i != 2) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}