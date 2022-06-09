#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 250010;
int n, m, k;
struct Node {
    int v1, v2;
}node[maxn];    // 边集数组
map<int, int> mp;   // 每个点的颜色
set<int> st;    // 颜色
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> node[i].v1 >> node[i].v2;
    }
    int q;
    cin >> q;
    while(q--) {
        mp.clear();
        st.clear();
        int color;
        for(int i = 1; i <= n; i++) {
            cin >> color;
            mp[i] = color;
            st.insert(color);
        }
        if(st.size() < k) {
            cout << "Error: Too few species." << endl;
        }else if(st.size() > k) {
            cout << "Error: Too many species." << endl;
        }else {
            bool flag = true;
            for(int i = 0; i < m; i++) {    // 遍历每条边
                if(mp[node[i].v1] == mp[node[i].v2]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}