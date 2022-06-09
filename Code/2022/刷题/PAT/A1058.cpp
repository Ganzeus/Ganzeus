#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include<unordered_map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 100010;

int main() {
    ll a1, b1, c1, a2, b2, c2;
    scanf("%ld.%ld.%ld %ld.%ld.%ld", &a1, &b1, &c1, &a2, &b2, &c2);
    ll total1 = (a1*17 + b1) * 29 + c1, total2 = (a2*17 + b2) * 29 + c2;
    ll total = total1 + total2;
    ll c = total % 29;
    total /= 29;

    ll b = total % 17;
    ll a = total / 17;
    printf("%ld.%ld.%ld", a, b, c);
    return 0;
}