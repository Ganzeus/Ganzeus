#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 105;
unordered_map<char, bool> mp;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] <= 'z' && s1[i] >= 'a') {
            mp[s1[i] - 32] = true;
        }else mp[s1[i]] = true;
    }
    for(int i = 0; i < s2.length(); i++) {
        if(s2[i] <= 'z' && s2[i] >= 'a') {
            mp[s2[i] - 32] = false;
        }else mp[s2[i]] = false;
    }
    
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] <= 'z' && s1[i] >= 'a') {
            if(mp[s1[i] - 32]) {
                cout << char(s1[i] - 32);
                mp[s1[i] - 32] = false;
            }
        }else if(mp[s1[i]]){
            cout << s1[i];
            mp[s1[i]] = false;
        }
    }
    return 0;
}