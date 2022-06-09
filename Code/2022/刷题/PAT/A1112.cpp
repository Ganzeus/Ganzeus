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
#define INF 0x3fffffff
const int maxn = 2010;
int k;
map<char, bool> notbroken;     // 只会置true
map<char, bool> mayBroken;
set<char> printed;
int main() {
    cin >> k;
    string str;
    cin >> str;
    
    char pre = '#';
    // str += '#';
    int cnt = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == pre) cnt++;
        else{
            if(cnt % k) notbroken[pre] = true;  // 一定没坏
            cnt = 1;
        }
        mayBroken[str[i]] = (cnt % k == 0);
        pre = str[i];
    }
    for(map<char, bool>::iterator it = notbroken.begin(); it != notbroken.end(); it++){
        mayBroken[it->first] = false;
    }
    // 输出
    for(int i = 0; i < str.length(); i++) {
        if(printed.find(str[i]) == printed.end() && mayBroken[str[i]]) {    // 没输出过且坏了
            cout << str[i];
            printed.insert(str[i]);
        }
    }
    cout << endl;
    for(int i = 0; i < str.length(); i++) {
        if(mayBroken[str[i]]) { //如果坏了，就输出一次，跳过k格
            cout << str[i];
            i += k-1;
            continue;
        }else cout << str[i];
    }
    return 0;
}