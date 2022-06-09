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
const int maxn = 100020;
int sum[maxn];  // 前缀和  sum[j]-sum[i]为Di+1 +...+ Dj
int n, m;
char eq[maxn][30], gt[maxn][30];
int search(int i) {  // 由i+1开始找到第一个sum[j]-sum[i]>=m的下标j，找不到返回-1
    int left = i+1, right = n, mid;
    while(left <= right) {
        mid = left + (right-left)/2;
        if(left == right) return mid;
        else if(sum[mid]-sum[i] >= m) right = mid;
        else left = mid+1;
    }
    return -1;
}
int main() {
    cin >> n >> m;
    sum[0] = 0;
    int d;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        sum[i] = sum[i-1] + d;
    }
    bool flag = false;
    int index1 = 0, index2 = 0;
    int cnt = 0;
    int minsub = INF;
    for(int i = 0; i < n; i++) {
        int j = search(i);  // 二分sum[j]-sum[i]>=m
        if(sum[j]-sum[i] == m) {
            flag = true;    // 表示有答案
            sprintf(eq[index1++], "%d-%d", i+1, j);
        }else if(sum[j]-sum[i] > m) {
            if(sum[j]-sum[i]-m < minsub){
                minsub = sum[j]-sum[i]-m;   // 更新最小值
                cnt = 1;    // 重新计数
                sprintf(gt[index2++], "%d-%d", i+1, j);
            } else if(sum[j]-sum[i]-m == minsub) {
                sprintf(gt[index2++], "%d-%d", i+1, j);
                cnt++;
            }
        }
    }
    if(flag){
        for(int i = 0; i < index1; i++) {
            printf("%s\n", eq[i]);
        }
    }else{
        for(int i = index2-cnt; i < index2; i++) {
            printf("%s\n", gt[i]);
        }
    }
    return 0;
}