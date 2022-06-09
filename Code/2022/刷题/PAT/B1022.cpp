#include <iostream>
using namespace std;
int main(){
    int a,b,d;
    cin>>a>>b>>d;
    int n=a+b;
    int digit[40],num=0;
    do{
        digit[num++]=n%d;
        n/=d;
    }while(n!=0);
    for(int i=num-1;i>=0;i--)
        cout<<digit[i];
    return 0;
}