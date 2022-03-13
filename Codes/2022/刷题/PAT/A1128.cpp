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
const int maxn = 520;
int t, n;
vector<int> a;
set<int> st;
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        a.resize(n);
        a.clear();
        st.clear();
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        bool flag = true;
        if(st.size() != n) flag = false;
        for(int i = 0; i < n-1; i++) 
            for(int j = i+1; j < n; j++) 
                if((j-i) == abs(a[j]-a[i])) {
                    flag = false;
                }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}