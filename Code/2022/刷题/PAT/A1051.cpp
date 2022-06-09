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
const int INF = 1e9;
const int N = 1e5;
stack<int> stk;
int arr[N];
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    while(k--){
        bool flag=true;
        int cur=1;
        while(!stk.empty()) stk.pop();
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        for(int i=1; i<=n; i++){
            stk.push(i);
            if(stk.size()>m) {flag=false;break;}  //超出容量，不满足
            while(!stk.empty() && arr[cur]==stk.top()){  //只要cur等于栈顶元素就出栈
                stk.pop();
                cur++;
            }
        }
        if(flag&&stk.empty()) cout<<"YES"<<endl;   //栈不空说明无法按照给定序列出栈
        else cout<<"NO"<<endl;
    }
}