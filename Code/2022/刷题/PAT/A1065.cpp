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
const int maxn = 1010;
int t;
ll a, b, c;
bool flag;
int main() {
    cin >> t;
    for(int i = 1; i <= t; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        ll res = a + b;
        if(a > 0 && b > 0 && res < 0) flag = true;
        else if (a < 0 && b < 0 && res >=0) flag = false;
        else if(res > c) flag = true;
        else flag = false;
        cout << "Case #" << i << ": ";
        if(flag == true) {
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
    }
    return 0;
}