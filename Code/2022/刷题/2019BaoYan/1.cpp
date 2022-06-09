#include <bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
int t;
ll cal(ll n) {
    ll ret = 0;
    while(n) {
        ret += (n%10) * (n%10);
        n /= 10;
    }
    return ret;
}
set<ll> st;
int main() {
    cin >> t;
    ll n;
    while(t--) {
        st.clear();
        cin >> n;
        int cnt = 0;
        bool flag = true;
        while(n != 1) {
            ll sq = cal(n);
            cnt++;
            if(st.find(sq) != st.end()) {
                cout << sq << endl;
                flag = false;
                break;
            }
            st.insert(sq);
            n = sq;
        }  
        if(!flag) continue;    
        else cout << cnt << endl;
    }
    // cout << cal(19) << endl;
    return 0;
}