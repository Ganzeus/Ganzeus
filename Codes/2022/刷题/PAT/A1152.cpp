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
bool isprime(int n) {
    int sqr = (int)sqrt(1.0*n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int l, k;
string str;
int main() {
    cin >> l >> k;
    cin >> str; // 读入l位整数，存入字符串
    int flag = false;   // flag = false 表示没找到k位素数
    for(int i = 0; i < l-k+1; i++) {    // 对于每一位
        int num = 0;    // 存放5位整数
        for(int j = 0; j < k; j++) {    // 计算num
            num = num*10 + str[i + j] - '0';
        }
        int tmp = num;
        int cnt = 0;    // 存放num位数
        while(tmp) {
            tmp /= 10;
            cnt++;
        }
        if(isprime(num)) {  // 找到第一个素数，直接输出
            if(cnt != k) {  // num不是k位(前面含0)
                for(int j = 0; j < k-cnt; j++) {    // 补0
                    cout << "0";
                }
            }
            cout << num << endl;  
            flag = true;
            break;      // 跳出循环
        }
    }
    if(!flag) cout << "404" << endl;    // 没找到素数
    return 0;
}