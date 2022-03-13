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
map<char,int> mp;
int main(){
    string str;
    cin>>str;
    for(int i = 0; i <str.length(); i++) {
        char digit = str[i];
        mp[digit]++;
    }
    for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << ":" << it->second<<endl;
    }
    return 0;
}