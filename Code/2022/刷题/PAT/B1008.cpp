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
const int maxn = 110;
int a[maxn];
int n, m;
int gcd(int a,int b) {
    return b==0 ? a : gcd(b, a%b);
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int mov = m % n;
    if(m % n == 0) mov = n;
    for(int i = n - mov; i < n; i++ ) {
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    for(int i = 0; i < n-mov; i++) {
        cout << " ";
        cout << a[i];
    }
    return 0;
}