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
const int maxn = 100010;

int main() {
    ll a = 1;  // a记位数
    ll n;
    scanf("%lld", &n);
    int sum = 0;    // 统计1的个数
    while(n/a != 0) {   // a的位数比n小
        ll tmp = n;
        ll right = tmp % a;   // 右边的数
        tmp /= a;
        ll cur = tmp % 10;  // 当前位的值
        ll left = tmp / 10; // 左边的数
        if(cur == 0) sum += left * a;   // 左边取值范围[0, left-1] 有left个，右边有a种取值
        else if(cur == 1) sum += left * a + (right+1);  // 先按0算；再令当前位为1，统计右边可能取值: [0, right], 有 right+1个
        else if(cur >= 2) sum += (left+1) * a;  // 当前位为0或1, 左边取值一样，共有[0, left]：left+1 个；右边有a种取值
        a *= 10;    // 进一位
    }
    cout << sum << endl;
    return 0;
}