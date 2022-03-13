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
int weight[17] {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11] {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
char testm;
char id[20];
int main(){
    int t;
    cin>>t;
    bool all = true;
    while(t--){
        int z = 0;
        bool flag {true};  //true表示没问题
        for(int i = 0; i < 17; i++){
            cin >> id[i];
            if(id[i] < '0' || id[i] > '9'){
                flag = false;   //不是数字，flag置false
                all = false;
            }else{
                z += ((id[i]-'0')*weight[i])%11;
            }
        }
        z %= 11;
        cin>>testm;
        if(testm != M[z]) flag = false;
        // for(int i = 0; i < 17; i++){
        //     cout<<id[i];
        // }
        // cout<<testm<<endl;
        // cout << z <<endl;
        if(!flag){
            for(int i = 0; i < 17; i++){
                cout<<id[i];
            }
            cout<<testm<<endl;
        }
    }
    if(all) cout<< "All passed"<<endl;
    return 0;
}