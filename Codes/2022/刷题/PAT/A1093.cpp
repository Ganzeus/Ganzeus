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
int leftNumP[100005] { 0 };
int main() {
    string str;
    cin >> str;
    int ans = 0;
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(str[i] == 'P'){
            leftNumP[i+1] = leftNumP[i] + 1;    //leftNumP数组下标从1开始
        }else{
            leftNumP[i+1] = leftNumP[i];
        }
    }
    int rightNumT = 0;
    for(int i = len-1; i >= 0; i--) {
        if(str[i] == 'T'){
            rightNumT++;
        }else if(str[i] == 'A'){
            ans += leftNumP[i+1]*rightNumT;
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}