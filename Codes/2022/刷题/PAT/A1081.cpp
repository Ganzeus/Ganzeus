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
const int maxn = 105;
struct Frac{
    ll up, down;
};
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
Frac reduction(Frac f) {    // 化简 
    if(f.down < 0){         // 1. 控制分母为正
        f.up = -f.up;
        f.down = -f.down;
    }
    if(f.up == 0) {         // 2. 0 = 0/1
        f.down = 1;
    }else {                 // 3. 约分
        ll d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}
Frac add(Frac a, Frac b) {
    Frac ret;
    ret.up = a.up * b.down + a.down * b.up;
    ret.down = a.down * b.down;
    return reduction(ret);
}
Frac sub(Frac a, Frac b) {
    Frac ret;
    ret.up = a.up * b.down - a.down * b.up;
    ret.down = a.down * b.down;
    return reduction(ret);
}
Frac mul(Frac a, Frac b) {
    Frac ret;
    ret.up = a.up * b.up;
    ret.down = a.down * b.down;
    return reduction(ret);
}
Frac div(Frac a, Frac b) {
    Frac ret;
    ret.up = a.up * b.down;
    ret.down = a.down * b.up;
    return reduction(ret);
}
void print(Frac f) {    // 输出分数
    f = reduction(f);   // 输出前先化简
    if(f.down == 1) cout << f.up;
    else if(abs(f.up) > abs(f.down)) {  // 假分数，以带分数形式输出
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    }else {     // 真分数
        printf("%lld/%lld", f.up, f.down);
    }
}
int n;
int main() {
    cin >> n;
    Frac sum;
    sum.up = 0;
    sum.down = 1;
    Frac tmp;
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        sum = add(sum, tmp);
    }
    print(sum);
    return 0;
}