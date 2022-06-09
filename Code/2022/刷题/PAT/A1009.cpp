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
const int maxn = 10;

struct Node {
    int exp;
    double coe;
}node1[maxn], node2[maxn];
map<int, double> mp;    // (exp, coe)
int k1, k2;
int main() {
    cin >> k1;
    for(int i = 0; i < k1; i++) {
        cin >> node1[i].exp  >> node1[i].coe;
    }
    cin >> k2;
    for(int i = 0; i < k2; i++) {
        cin >> node2[i].exp >> node2[i].coe;
    }
    for(int i = 0; i < k1; i++) {
        for(int j = 0; j < k2; j++) {
            mp[node1[i].exp + node2[j].exp] += node1[i].coe * node2[j].coe;
        }
    }
    int cnt = 0;
    map<int, double>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++) {
        if(it->second != 0) cnt++;
    }
    cout << cnt << " ";
    map<int, double>::reverse_iterator rit;
    int i = 0;
    for(rit = mp.rbegin(); rit != mp.rend(); rit++) {
        if(rit->second != 0) {
            cout << rit->first << " ";
            printf("%.1f", rit->second);
            if(i != cnt-1) cout << " "; 
            i++;
        }
    }
    return 0;
}
