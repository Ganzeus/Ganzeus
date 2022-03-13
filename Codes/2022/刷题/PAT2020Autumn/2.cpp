#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 10010;
int sum[maxn];  //  前缀和
int n, m;
int main() {
    cin >> n >> m;
    sum[0] = 0;
    int d;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        sum[i] = sum[i-1] + d;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {    // 枚举开头
        for(int j = i+1; j <= n; j++) {    // 枚举结尾
            if(sum[j] - sum[i] <= m) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}