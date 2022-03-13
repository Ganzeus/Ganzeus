#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int n;
string deal(string s,int& e){
    int k=0;
    while(s.length()>0&&s[0]=='0'){
        s.erase(s.begin());     //去掉前导0
    }
    
    if(s[0]=='.'){         //s小于1
        s.erase(s.begin());
        while(s.length()>0&&s[0]=='0'){    //去掉小数点后有效数字前的0
            s.erase(s.begin());
            e--;
        }
    }else{
        while(k!=s.length()&&s[k]!='.'){
            k++;
            e++;
        }
        if(k!=s.length()){      //找到小数点
            s.erase(s.begin()+k);//删除小数点
        }
    }
    if(s.length()==0) e=0;      //去掉前导0和小数点后字符串为空，则该数为0
    /*现在s只剩有效数字*/
    string ret;
    k=0;
    int num=0;
    while(num<n){
        if(k<s.length()) ret+=s[k++];
        else ret+='0';      //有效数字长度不够精度，就在末尾加0
        num++;
    }
    return ret;
}
int main(){
    string a,b,suba,subb;
    cin>>n>>a>>b;
    int e1=0,e2=0;
    suba=deal(a,e1);
    subb=deal(b,e2);
    if(suba==subb&&e1==e2){
        cout<<"YES 0."<<suba<<"*10^"<<e1<<endl;
    }else{
        cout<<"NO 0."<<suba<<"*10^"<<e1<<" 0."<<subb<<"*10^"<<e2<<endl;
    }
}