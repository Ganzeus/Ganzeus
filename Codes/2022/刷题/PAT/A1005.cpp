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
string digits[10] {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() {
    ll sum = 0;
    while(1) {
        char c = getchar();
        if(c == '\n') break;
        sum += (c - '0');
    }
    // cout << sum;
    stack<string> stk;
    do {
        int digit = sum%10;
        string str = digits[digit];
        stk.push(str);
        sum /= 10;
    } while(sum);
    int size = stk.size();
    for(int i = 0; i < size; i++) {
        string ans = stk.top();
        stk.pop();
        cout << ans;
        if(i != size - 1) {
            cout << " ";
        }
    }
}