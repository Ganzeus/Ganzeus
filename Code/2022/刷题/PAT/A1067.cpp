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
const int maxn = 100010;
int n;
int leftnum;   // 不在本位上的个数
int pos[maxn];  // pos[0] = 7表示0在7号位
int main() {
    cin >> n;
    leftnum = n-1;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        pos[num] = i;  // 记录位置
        if(num == i && num != 0) leftnum--;     // 除0以外有数已经在本位
    }
    int ans = 0;
    int k = 1;
    while(leftnum > 0) {
        while(pos[0] != 0) {    // 0回到0位，退出
            int d = pos[0]; // 0的下标
            swap(pos[0], pos[d]);  // 位置交换
            ans++;
            leftnum--;
        }
        if(pos[0] == 0) {   // 0回到原位，检查是否排好序
            while(k < n) {    // 找到第一个不在本位的数
                if(pos[k] != k) {  // 找到一个不匹配的位置，与0交换
                    swap(pos[0], pos[k]);   // 位置交换
                    ans++;
                    break;
                }
                k++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}