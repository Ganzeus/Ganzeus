#include <iostream>
using namespace std;
int main(){
    int step=0;
    int n;
    cin>>n;
    while(n!=1){
        if(n%2==0){
            n/=2,step++;
        } 
        else{
            n=(3*n+1)/2,step++;
        } 
    }
    cout<<step<<endl;
    return 0;
}