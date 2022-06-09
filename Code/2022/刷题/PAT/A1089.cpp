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
int n;
vector<int> ini, cur;
int flag = 1;   // 1表示insert, 2表示merge
void merge(vector<int> ini, vector<int>& cur) {
    bool changed = false;
    for(int step = 2; step/2 <= n; step *= 2) {
        if(ini == cur && changed) { // 已经排过序再进行判断
            flag = 2;
        }
        for(int i = 1; i <= n; i += step) {
            sort(ini.begin() + i, ini.begin() + min(i + step, n+1));
        }
        changed = true;
        if(flag == 2) {
            cur = ini;
            return;
        }
    }
}
void insert(vector<int>& ini, vector<int> cur) {
    for(int i = 2; i <= n; i++) {
        sort(ini.begin() + 1, ini.begin() + i);
        if(ini != cur) return;
    }
}
int main() {
    cin >> n;
    ini.resize(n+1);
    cur.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> ini[i];
    for(int i = 1; i <= n; i++) cin >> cur[i];
    merge(ini, cur);
    if(flag == 2) {
        cout << "Merge Sort" << endl;
        for(int i = 1; i <= n; i++) {
            cout << cur[i];
            if(i != n) cout << " ";
        }
    }else {
        cout << "Insertion Sort" << endl;
        int i = 2;
        for(; i <= n; i++) {
            sort(ini.begin() + 1, ini.begin() + i + 1);
            if(ini == cur) break;
        }
        // 此时i为有序序列的最后一位
        sort(ini.begin() + 1, ini.begin() + i + 2);
        for(int i = 1; i <= n; i++) {
            cout << ini[i];
            if(i != n) cout << " ";
        }
    }
    return 0;
}