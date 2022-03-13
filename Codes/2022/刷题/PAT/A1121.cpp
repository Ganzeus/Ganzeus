#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 10010;

map<int, int> mp1;
map<int, int> mp2;
int query[maxn];
set<int> st;
set<int> ans;
int n, m;
int main() {
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        mp1[a] = b;
        mp2[b] = a;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> query[i];
        st.insert(query[i]);
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(mp1.find(query[i]) == mp1.end() && mp2.find(query[i]) == mp2.end()) {    // 不在所给couple中
            ans.insert(query[i]);
        } else if(mp1.find(query[i]) != mp1.end()) {    // 在mp1中
            if(st.find(mp1[query[i]]) == st.end()) {   // 查询序列中没有其对象
                ans.insert(query[i]);
            }
        }else if(mp2.find(query[i]) != mp2.end()) {     // 在mp2中
            if(st.find(mp2[query[i]]) == st.end()) {   // 查询序列中没有其对象
                ans.insert(query[i]);
            }
        }
    }
    cout << ans.size() << endl;
    int i = 0;
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++, i++){
        printf("%05d", *it);
        if(i != ans.size() - 1) cout << ' ';
    }
    return 0;
}