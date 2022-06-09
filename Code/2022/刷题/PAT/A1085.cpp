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
const int maxn = 100020;
ll n, p;
ll a[maxn];
int search(int i, ll x) {
    if(a[n-1] < x) return n;    // 所有数都不大于x，返回n
    int left = i+1, right = n-1;
    int mid;
    while(left < right) {
        mid = left + (right - left)/2;
        if(a[mid] <= x) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int j = search(i, a[i]*p);
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}