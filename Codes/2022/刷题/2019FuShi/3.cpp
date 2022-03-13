#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1010;
int T, M, n;
int H(int key) {
    return key % M; 
}
bool Hash[maxn];
int main() {
    cin >> T >> M >> n;
    int d;
    for(int i = 0; i < n; i++) {
        cin >> d;
        int pos = H(d); // 初始位置
        for(int j = 0; j < T; j++) {   // 最多探测T次
            if(Hash[pos] == false) {   // 找到插入位置
                Hash[pos] = true;  // 插入
                break;
            }else pos = (pos+1) % T;    // 线性探测
        }
    }
    // for(int i = 0; i < T; i++) cout << Hash[i];
    int cnt = 0;
    for(int i = 0; i < M; i++) {
        int pos = i;
        for(int j = 0; j <= T; j++) {   // 最多查T+1次
            cnt++;
            if(Hash[pos] == false) {
                break;
            }else pos = (pos+1) % T;
        }
    }
    printf("%.1f\n", (double)cnt/M);
    return 0;
}