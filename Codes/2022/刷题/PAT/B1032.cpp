#include <iostream>
#include <cstdio>
using namespace std;
#define N 100005
int school[N]={0};
int main(){
    int n,id,score;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d %d",&id,&score);
        school[id]+=score;
    }
    int max=-1,k=1;
    for(int i=1;i<=n;i++){
        if(school[i]>=max){
            max=school[i];
            k=i;
        }
    }
    printf("%d %d\n",k,max);
    return 0;   
}