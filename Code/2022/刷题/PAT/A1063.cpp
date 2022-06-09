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

set<int> Set[55];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int num;
        scanf("%d",&num);
        while(num--){
            int data;
            scanf("%d",&data);
            Set[i].insert(data);
        }
    }
    int k;
    cin>>k;
    while(k--){
        int c,t;    
        cin>>c>>t;  //输入两个查询集合
        int totalnum = Set[c].size() + Set[t].size(), samenum = 0;
        for(set<int>::iterator it = Set[c].begin(); it != Set[c].end(); it++){
            if(Set[t].find(*it) != Set[t].end()) {
                samenum++;
                totalnum--;
            }
        }
        double ans = samenum*100.0/totalnum;
        printf("%.1f",ans);
        cout<<"%"<<endl;
    }
    return 0;
}