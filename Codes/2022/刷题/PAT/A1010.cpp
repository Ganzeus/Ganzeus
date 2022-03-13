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
const int maxn = 100020;
string n1, n2;
int tag, radix;
map<char, int> mp;
ll BTD(string s, int base) { // 各种进制转10进制
    ll ret = 0;
    for(int i = 0; i < s.length(); i++) {
        int d = mp[s[i]];
        ret = ret * base + d;
    }
    return ret;

}
ll findRadix(string s, ll d) { // 二分n2的进制，找不到返回-1
    char c = *max_element(s.begin(), s.end());  // 找到最大的位
    ll low = mp[c] + 1;    // 最大的位为c, 表示n2至少是c进制
    ll high = max(low, d);
    while(low <= high){
        ll mid = low + (high-low)/2;
        ll tmp = BTD(s, mid);
        if(tmp < 0 || tmp > d) {    // <0表示溢出，>d表示进制太小
            high = mid - 1;
        }else if(tmp == d) return mid;    // 找到解
        else low = mid + 1;
    }
    return -1;
}
int main() {
    for(char i = '0'; i <= '9'; i++) mp[i] = i-'0';
    for(char i = 'a'; i <= 'z'; i++) mp[i] = i-'a' + 10;
    cin >> n1 >> n2 >> tag >> radix;
    if(tag == 2) swap(n1, n2);  // 保持题目给的是n1的进制
    ll d = BTD(n1, radix);
    ll ans = findRadix(n1, d);
    if(ans != -1) cout << ans << endl;
    else cout << "Impossible" << endl;
    return 0;
}