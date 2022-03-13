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
map<char, int> mp;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s2.length(); i++) {
        mp[s2[i]]++;
    }
    
    for(int i = 0; i < s1.length(); i++) {
        if(mp.find(s1[i]) != mp.end()) mp[s1[i]]--;
    }
    // for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    bool flag = true;
    for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second > 0) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "Yes " << s1.length() - s2.length() << endl;
    else{
        int ans = 0;
        for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if(it->second > 0) {
                flag = false;
                ans += it->second;
            }
        }
        cout << "No " << ans << endl;
    }
}