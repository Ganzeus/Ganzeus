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
const int K=2505;
vector<string> stuList[K];

int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    while(n--){
        string name;
        int num;
        cin>>name>>num;
        while(num--){
            int cno;
            scanf("%d",&cno);
            stuList[cno].push_back(name);
        }
    }
    
    for(int i = 0; i < k; i++){
        printf("%d %d\n",i+1,stuList[i+1].size());
        sort(stuList[i+1].begin(),stuList[i+1].end());
        for(int j = 0; j < stuList[i+1].size(); j++){
            printf("%s\n",stuList[i+1][j].c_str());
        }
    }
    return 0;
}