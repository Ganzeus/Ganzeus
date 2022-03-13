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
const int maxn = 1020;
int n, b;
bool isPal(vector<int> digit) {     // 判断是否是回文数
    int i = 0, j = digit.size() - 1;
    for(;i < j; i++, j--) {
        if(digit[i] != digit[j]) return false;
    }
    return true;
}
void convert(int n, int b, vector<int>& digit) {
    while(n) {
        digit.push_back(n%b);
        n /= b;
    }
}
int main() {
    cin >> n >> b;
    vector<int> digit;
    convert(n, b, digit);
    cout << (isPal(digit) ? "Yes" : "No") << endl;
    for(int i = digit.size() - 1; i >= 0; i--){
        cout << digit[i];
        if(i != 0) cout << " ";
    }
    return 0;
}