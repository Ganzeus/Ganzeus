#include <iostream>
using namespace std;
int main(){
    char a[90][90];
    int num=0;
    while(~scanf("%s",&a[num])){
        num++;
    }
    for(int i=num-1;i>=0;i--){
        cout<<a[i];
        if(i!=0) cout<<" ";
    }
}