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
map<string, int> mp;
bool check(char c){
    if(c >= '0' && c <= '9') return true;
    else if(c >= 'a'&& c <= 'z') return true;
    else if(c >= 'A'&& c <= 'Z') return true;
    else return false;
}
int main(){
    string str;
    getline(cin, str);
    int i = 0;
    while(i < str.length()) {   //遍历整个字符串
        string word = "";    //每次外层循环提取一个新单词
        while(i < str.length() && check(str[i])){   //提取一个单词，循环结束时str[i]为无效字符
            if(str[i] >= 'A' && str[i] <= 'Z'){ //大写转小写
                str[i] += 32;
            }
            word += str[i];
            i++;    //判断下一个字符
        }
        if(word != "") mp[word]++; //word非空，次数+1
        while(!check(str[i])){   //去除连续无效字符，循环结束时str[i]为有效字符，进入下一层循环
            i++;
        }
    }

    string ans;
    int maxcnt = 0;
    for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > maxcnt){
            maxcnt = it->second;
            ans = it->first;
        }
    }
    cout<<ans<<" "<<maxcnt<<endl;
    return 0;
}