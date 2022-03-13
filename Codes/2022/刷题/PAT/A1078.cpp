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
int T, n;
int H(int key) {
    return key%T;
}

int main() {
    for(int i = 0; i < maxn; i++) Key[i] = -1;  // -1表示空
    cin >> T >> n;
    if(!isprime(T)) {
        while(++T) {
            if(isprime(T)) break;
        }
    }
    int d;
    for(int i = 0; i < n; i++) {
        cin >> d;
        if(Key[H(d)] == -1) {   // 有位置
            Key[H(d)] = d;
            cout << H(d);
        }else { // 没位置
            int i = 1;
            while(Key[H(d)] != -1) {    // 找空位置
                if(i >= T) break; // 找不到位置
                int pos = H(d + i * i);
                if(Key[pos] == -1) {    // 找到了空位置
                    Key[pos] = d;
                    cout << pos;
                    break;
                }
                i++;
            }
            if(i >= T) cout << "-";
        }
        if(i != n-1) cout << " ";
    }
    return 0;
}