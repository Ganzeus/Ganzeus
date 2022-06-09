#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
ll ans = 0;
vector<int> panda;
int n;
int main() {
    cin >> n;
    panda.resize(n);
    for(int i = 0; i < n; i++) cin >> panda[i];
    int i = 1;
    ans += 200;
    int cnt = 1;
    while(i < n) {
        while(i < n && panda[i] < panda[i-1]) {  // 统计递减序列长度
            ans += cnt*100 + 200;
            cnt++;
            i++;
        }
        if(cnt > 1) {   // 存在递减序列
            cnt = 1;
            i++;
            if(i < n) ans += 200;
            
        }
        while(i < n && panda[i] > panda[i-1]) {  // 统计递增序列
            ans += cnt*100 + 200;
            cnt++;
            i++;
        }
        if(cnt > 1) {   // 存在递增序列
            cnt = 1;
            i++;
            if(i < n) ans += 200;
            
        }
        while(i < n && panda[i] == panda[i-1]) { // 统计相等序列
            cnt++;
            ans += 200;
            i++;
        }
        if(cnt > 1) {
            cnt = 1;
        }
    }
    cout << ans << endl;
    return 0;
}