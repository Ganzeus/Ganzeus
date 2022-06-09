#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include<unordered_map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 100010;
map<char, bool> mp;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s2.length(); i++) {
        mp[s2[i]] = true;
    }
    for(int i = 0; i < s1.length(); i++) {
        if(!mp[s1[i]]) cout << s1[i];
    }
    return 0;
}