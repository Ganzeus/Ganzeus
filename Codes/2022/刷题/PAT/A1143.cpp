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
const int maxn = 320;
int m, n;
vector<int> pre;
set<int> s;
int main() {
    cin >> m >> n;
    int d;
    for(int i = 0; i < n; i++) {
        cin >> d;
        pre.push_back(d);
        s.insert(d);
    }
    while(m--) {
        int q1, q2;
        cin >> q1 >> q2;
        if(s.find(q1) != s.end() && s.find(q2) != s.end()) {    // 两个都存在
            int cur;
            for(int i = 0; i < n; i++) {
                cur = pre[i];
                // 当前结点值在两结点之间，即为公共祖先，并且是最近的
                if((cur >= q1 && cur <= q2) || (cur >= q2 && cur <= q1)) {
                    break;  // 退出循环输出
                }
            }
            if(cur != q1 && cur != q2) printf("LCA of %d and %d is %d.\n", q1, q2, cur);
            else if(cur == q1) printf("%d is an ancestor of %d.\n", cur, q2);
            else printf("%d is an ancestor of %d.\n", cur, q1);
        }else {
            if(s.find(q1) == s.end() && s.find(q2) != s.end()) {
                printf("ERROR: %d is not found.\n", q1);
            }
            if(s.find(q2) == s.end() && s.find(q1) != s.end()) {
                printf("ERROR: %d is not found.\n", q2);
            }
            if(s.find(q2) == s.end() && s.find(q1) == s.end()) {    // 都不存在
                printf("ERROR: %d and %d are not found.\n", q1, q2);
            }
        }
    }
    return 0;
}