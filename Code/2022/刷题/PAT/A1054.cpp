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
map<int,int> cnt;   //value默认为0
int main(){
    int m,n;
    cin>>m>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int bit;
            cin>>bit;
            cnt[bit]++;
        }
    }
    int ans = 0,half = m*n/2;
    for(map<int,int>::iterator it = cnt.begin(); it !=cnt.end(); it++){
        if(it->second > half) ans = it->first;
        else continue;
    }
    cout << ans <<endl;
    return 0;
}