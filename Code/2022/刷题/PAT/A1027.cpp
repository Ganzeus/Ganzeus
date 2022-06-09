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

string digit[13] {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};
string convert(int color) {     // 15
    string ans = "";
    int d1 = color%13;  // 2
    color /= 13;
    int d2 = color%13;  // 1
    ans += digit[d2];
    ans += digit[d1];
    return ans;
}
int main() {
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    string ans1 = convert(c1);
    string ans2 = convert(c2);
    string ans3 = convert(c3);
    cout << "#" << ans1 << ans2 << ans3<< endl;
    return 0;
}