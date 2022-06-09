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
ll a, b;
int main() {
    cin >> a >> b;
    ll res = a + b;
    ll abs = res;
    if(res < 0) {
        cout << "-";
        abs = -res;
    }
    ll r = abs%1000;
    abs /= 1000;
    ll m = abs % 1000;
    abs /= 1000;
    ll l = abs%1000;
    if(l == 0) {
        if(m == 0) {
            printf("%d", r);
        }else {
            printf("%d,%03d",m,r);
        }
    }else {
        printf("%d,%03d,%03d",l,m,r);
    }
    return 0;
}