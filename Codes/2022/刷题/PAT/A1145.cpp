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
const int maxn = 10020;
bool isprime(int x){
    if(x <= 1) return false;
    int sqr = sqrt(x * 1.0);
    for(int i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int Key[maxn];
int T, n, m;
int H(int key) {
    return key%T;
}

int main() {
    for(int i = 0; i < maxn; i++) Key[i] = -1;  // -1表示空
    cin >> T >> n >> m;
    if(!isprime(T)) {
        while(++T) {
            if(isprime(T)) break;
        }
    }
    int d;
    for(int i = 0; i < n; i++) {
        cin >> d;
        if(Key[H(d)] == -1) {   // 有位置
            Key[H(d)] = d;  // 插入
        }else { // 没位置
            int i = 1;
            while(Key[H(d)] != -1) {    // 找空位置
                if(i >= T) break; // 找不到位置
                int pos = H(d + i * i);
                if(Key[pos] == -1) {    // 找到了空位置
                    Key[pos] = d;   // 插入
                    break;
                }
                i++;
            }
            if(i >= T) printf("%d cannot be inserted.\n", d);
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> d;
        for(int j = 0; j <= T; j++) {   // 最多查询T+1次
            ans++;
            int pos = H(d + j * j);
            if(Key[pos] == d || Key[pos] == -1) {   // 元素存在或找到空位置
                break;
            }
        }
    }
    printf("%.1f\n", ans*1.0 / m);
    return 0;
}