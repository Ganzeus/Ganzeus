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
const int maxn = 1e5+5;
int main(){
    int n;
    cin>>n;
    double input,sum=0.0;
    for(int i=1; i<=n; i++){
        scanf("%lf",&input);
        sum+=input*i*(n-i+1);
    }
    printf("%.2f\n",sum);
    return 0;
}