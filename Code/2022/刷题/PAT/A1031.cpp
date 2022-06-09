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

int main() {
    string str;
    cin >> str;
    int len = str.length();     // 11
    int leftover = (len+2) % 3; // 13%3 = 1
    int n1, n2, n3; 
    n1 = n3 = (len+2) / 3;      // 13/3 = 4
    n2 = n1 + leftover;         // 5
    int blank = n2 - 2;         // 3
    int i = 0, j = len - 1;
    for(int k = 0; k < n1; k++, i++, j--) {
        if(k == n1-1) {     // 最底层
            cout << str.substr(i, len-i-(len-1-j));   // 第二个参数为长度
            break;
        }
        cout << str[i];
        for(int ij = 0; ij < blank; ij++) cout << " ";  
        cout << str[j] << endl;
    }
    return 0;
}