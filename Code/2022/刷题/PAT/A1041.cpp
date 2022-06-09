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
int bets[maxn] = {0};
int n;
map<int, int> cnt;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> bets[i];
    for(int i = 0; i < n; i++) {
        cnt[bets[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(cnt[bets[i]] == 1) {cout << bets[i] << endl; return 0;}
    }
    cout << "None" << endl;
    return 0;
}