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
#define INF 0x3fffffff
const int maxn = 100010;
int n;
map<int, int> mp;
int main() {
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        if(num > 0) mp[num] = 1;
    }
    for(int i = 1; i < INF; i++) {
        if(mp[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
}