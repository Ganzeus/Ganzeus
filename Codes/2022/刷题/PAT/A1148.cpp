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
const int maxn = 110;
int n;
int words[maxn];    // 说的话

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> words[i];
    int a[maxn];    // a[i]=-1表示i是狼人
    vector<int> lie;    // 存放说谎的人
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) {   // 轮流假设狼人（升序）
            lie.clear();
            for(int k = 1; k <= n; k++) a[k] = 1;
            a[i] = a[j] = -1;
            for(int k = 1; k <= n; k++) {    // 检查每人说的话
                if(words[k] * a[abs(words[k])] < 0){    // 说话与假设不匹配，说明在说谎
                    lie.push_back(k);
                }
            }
            if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {  // 两人说谎且一个是狼人一个是好人
                cout << i << " " << j << endl;
                return 0;
            }
        }
    cout << "No Solution" << endl;  // 没找到符合条件的狼人
    return 0;
}