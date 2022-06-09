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
const int maxn = 25;
int n;
vector<ll> a;
int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < a.size()/2; i++) {
        sum1 += a[i];
    }
    for(int i = a.size()/2; i < a.size(); i++) {
        sum2 += a[i];
    }
    if(a.size() % 2 == 0) cout << 0 << " ";
    else cout << 1 << " ";
    cout << sum2 - sum1 << endl;
    return 0;
}