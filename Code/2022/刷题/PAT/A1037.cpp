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
const int maxn = 10010;
vector<ll> coupons, values;
int n, m;

int main() {
    cin >> n;
    ll coupon;
    for(int i = 0; i < n; i++) {
        cin >> coupon;
        coupons.push_back(coupon);
    }
    sort(coupons.begin(), coupons.end());

    cin >> m;
    ll value;
    for(int i = 0; i < m; i++) {
        cin >> value;
        values.push_back(value);
    }
    sort(values.begin(), values.end());
    int i = 0, ans = 0;
    while(i < n && i < m && coupons[i] < 0 && values[i] < 0) {  // 由小到大取两个负数
        ans += coupons[i] * values[i];
        i++;
    }
    i = n-1;
    int j = m-1;
    while(i >= 0 && j >= 0 && coupons[i] > 0 && values[j] > 0) { // 由大到小取两个正数
        ans += coupons[i] * values[j];
        i--;
        j--;
    }
    cout << ans << endl;
    return 0;
}