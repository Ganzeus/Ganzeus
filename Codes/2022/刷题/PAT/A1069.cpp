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

bool cmp(int a, int b) { return a > b; }
int main() {
    string str;
    cin >> str;
    str.insert(0, 4-str.length(), '0');
    do {
        string op1 = str, op2 = str;
        sort(op1.begin(), op1.end(), cmp);
        sort(op2.begin(), op2.end());
        int ans = stoi(op1) - stoi(op2);
        str = to_string(ans);
        str.insert(0, 4-str.length(), '0');
        cout << op1 << " - " << op2 << " = " << str << endl;
    }while(str != "6174" && str != "0000");
    return 0;
}