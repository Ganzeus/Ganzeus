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
ll n;
int main(){
    cin >> n;
    int maxnum = 0; //最大连续长度
    int st; // 所求起点
    int Sqrt = static_cast<int>(sqrt(1.0*n));
    for(int i = 2; i <= Sqrt; i++) { // 遍历起点i
        int j = i;      // j存放连续整数的终点
        int temp = 1;   // temp存放以i为起点，j为终点的乘积
        while(1) {
            temp *= j;
            if(n % temp != 0) break;    //不能整除，跳出
            int tempnum = j - i + 1;
            if(tempnum > maxnum) {
                maxnum = tempnum;
                st = i;
            }
            j++;
        }
    }
    if(maxnum == 0){    //sqrt(n)内没有因子
        cout << 1 << endl << n << endl;
    }else{
        cout << maxnum << endl;
        for(int i = 0; i < maxnum; i++) {
            cout << i + st;
            if(i != maxnum-1) cout << "*";
        }
    }
    return 0;
}