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
int n;
int main(){
    cin>>n;
    int fir,sec,thr;
    fir = n%10;
    sec = (n/10)%10;
    thr = (n/100)%10;
    // printf("%d %d %d\n",fir,sec,thr);
    for(int i = 0; i < thr; i++){
        cout<<"B";
    }
    for(int i = 0; i < sec; i++){
        cout<<"S";
    }
    for(int i = 1; i <= fir; i++){
        cout<<i;
    }
    return 0;
}