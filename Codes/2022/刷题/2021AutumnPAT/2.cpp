#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
const int maxn = 10010;
int n;
int hat[maxn] = {INF};
stack<int> stk;
int weight[maxn] { false };   // 排名-> 体重
map<int, int> numW; // 体重->序号
bool cmp(int a, int b) {
    return a > b; 
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> hat[i];
        stk.push(hat[i]);
    }
    sort(hat, hat + n, cmp);  
    for(int i = 0; i < n; i++){
        cin >> weight[i];
        numW[weight[i]] = i+1;
    }
    sort(weight, weight+n, cmp);
    for(int i = 0; i < n; i++) {
        int h = stk.top();
        stk.pop();
        int j = 0;
        for(; j < n; j++) if(hat[j] == h) break;
        // 此时j为帽子重量排名
        cout << numW[weight[j]];
        if(i != n-1) cout << " ";
    }
    return 0;
}