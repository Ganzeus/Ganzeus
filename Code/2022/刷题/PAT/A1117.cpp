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
int a[maxn];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int e = 0;
    for(int i = 0; i < n; i++) if(a[i] > i+1) e++;
    cout << e << endl;
    return 0;
}