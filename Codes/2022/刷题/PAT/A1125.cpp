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
const int maxn = 520;
vector<double> l;
int main() {
    int n;
    cin >> n;
    l.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    double ans = l[0];
    for(int i = 1; i < n; i++) {
        ans = (l[i] + ans) / 2;
    }
    
    cout << int(ans) << endl;
    return 0;
}