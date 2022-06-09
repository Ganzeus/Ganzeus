#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
const int maxn = 10010;
int sum[maxn];
int addr[maxn];
int n, k;
int main() {
    cin >> n >> k;
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {   // 下标从1开始
        int size;
        cin >> addr[i] >> size;
        sum[i] = sum[i-1] + size;
    }
    int maxj = 0;
    for(int i = 0; i < k; i++) {
        int address;
        cin >> address;
        if(address >= sum[n]) cout << "Illegal Access" << endl;
        else {
            int j = 0;
            for(; j < n; j++) {
                if(address >= sum[j] && address < sum[j+1]) {
                    break;
                }
            }
            if(j+1 > maxj) maxj = j+1; 
            // 在addr[j+1]开头的数组
            cout << addr[j+1] + 4*(address-sum[j]) << endl;
        }
    }
    cout << maxj << endl;
    return 0;
}