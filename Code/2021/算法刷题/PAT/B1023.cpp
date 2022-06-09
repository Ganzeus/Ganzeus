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
int num[10];
int main() {
    for(int i = 0; i < 10; i++){
        cin>>num[i];
    }
    for(int i = 1; i < 10; i++){    //从1开始枚举,找到第一个非零个数的数
        if(num[i]) {
            cout << i;
            num[i]--;
            break;
        }
    }
    while(num[0]--) cout<<0;    //输出0
    for(int i = 1; i < 10; i++){
        if(num[i]){
            while(num[i]--) cout << i;
        }
    }

    return 0;
} 