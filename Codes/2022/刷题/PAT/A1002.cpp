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
map<int, double> mp;
int main() {
    int k;
    cin >> k;
    int exp;
    double coe;
    for(int i = 0; i < k; i++) {
        cin >> exp >> coe;
        mp[exp] = coe;
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> exp >> coe;
        mp[exp] += coe;
    }
    int cnt = 0;
    for(map<int, double>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second != 0.0) cnt++;
    }
    if(cnt == 0) {  // 最后一组数据
        cout << 0;
        return 0;
    }
    cout << cnt << " ";
    int i = 0;
    for(map<int, double>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
        if(it->second != 0.0) {
            cout << it->first << " ";
            printf("%.1f", it->second);
            if(i < cnt - 1) cout << " ";
            i++;
        }
        
    }
    return 0;
}