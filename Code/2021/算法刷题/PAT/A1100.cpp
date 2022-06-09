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
//个位[0,12]
string lowdigit[13] {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
//十位[0,12]
string hidigit[13] {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

string ETM[170];    //地球->火星
map<string, int> MTE;//火星->地球
void init(){    //打表
    //一位火星文打表
    for(int i = 0; i < 13; i++){
        ETM[i] = lowdigit[i];   //个位为0，十位[0,12]
        MTE[lowdigit[i]] = i;   
        ETM[i*13] = hidigit[i]; //十位为0，个位[0,12]
        MTE[hidigit[i]] = i*13;
    }
    //两位火星文打表
    for(int i = 1; i < 13; i++){
        for(int j = 1; j < 13; j++){
            string mar = hidigit[i] + " " + lowdigit[j];    //两位火星文组成的字符串
            ETM[i*13+j] = mar;
            MTE[mar] = i*13+j;
        }
    }
}

int main(){
    init(); //打表
    int n;
    cin>>n;
    cin.get();  //读入回车
    while(n--){
        string str;
        getline(cin,str);
        if('0' <= str[0] && str[0] <= '9'){ //数字
            int num = 0;
            for(int i = 0; i < str.length(); i++){
                num = num*10 + (str[i]-'0');
            }
            // cout<<num<<endl;
            cout << ETM[num] <<endl;
        }else{  //火星文
            cout << MTE[str] <<endl;
        }
    }
    return 0;
}