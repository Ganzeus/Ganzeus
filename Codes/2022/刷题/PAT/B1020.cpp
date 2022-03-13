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
double d;
struct mooncake{
    double storage;
    double sale;
    double rate;
}cake[1010];
bool cmp(mooncake a, mooncake b) {
    return a.rate > b.rate;
}
double gross = 0.0;
int main() {
    scanf("%d %lf",&n,&d);
    for(int i = 0; i < n; i++){
        scanf("%lf",&cake[i].storage);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf",&cake[i].sale);
        cake[i].rate = cake[i].sale / cake[i].storage; 
    }
    sort(cake, cake+n, cmp);
    for(int i = 0; i < n; i++){
        if(cake[i].storage >= d){
            gross += cake[i].rate*d;
            break;
        }else{
            gross += cake[i].sale;
            d -= cake[i].storage;
        }
    }
    printf("%.2f\n", gross);
    return 0;
}