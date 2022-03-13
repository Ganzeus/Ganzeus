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
const int maxn = 1020;
int q[110];
int sum = 0;
int main() {
    int n;
    cin >> n;
    q[0] = 0;
    for(int i = 1; i <= n; i++) cin >> q[i];
    for(int i = 1; i <= n; i++) {
        if(q[i] - q[i-1] > 0) {
            sum += (q[i] - q[i-1]) * 6;
        }else {
            sum -= (q[i] - q[i-1]) * 4;
        }
    }
    sum += n*5;
    cout << sum << endl;
    return 0;
}