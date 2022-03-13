#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 210;

int n, m, k;
int G[maxn][maxn];

int main() {
    cin >> n >> m;
    int c1, c2;
    for(int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        G[c1][c2] = G[c2][c1] = 1;
    }
    for(int i = 0; i < maxn; i++) G[i][i] = 1;
    vector<int> area;
    cin >> k;
    for(int a = 1; a <= k; a++) {
        int num;
        cin >> num;
        area.clear();
        bool Hash[maxn] = {false};  // 是否出现过
        int d;
        for(int i = 0; i < num; i++) {
            cin >> d;
            area.push_back(d);
            Hash[d] = true;
        }
        bool flag = true;
        for(int i = 0; i < area.size(); i++) {
            for(int j = i; j < area.size(); j++) {
                if(!G[area[i]][area[j]]) { 
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) printf("Area %d needs help.\n", a);
        else {  // 查询是否满
            int flag1 = true;
            int ans = 0;
            for(int i = 1; i <= n; i++) {   // 检查其他人
                if(!Hash[i]) {  // 不在area中
                    bool hasBreak = false;
                    for(int j = 0; j < area.size(); j++) {  // 对于area中的所有人
                        if(!G[i][area[j]]) {
                            hasBreak = true;
                            break;   // 只要有一个没边，就判断下一个
                        }
                    }
                    if(hasBreak) continue;
                    flag1 = false;  // 表明不满
                    ans = i;    // 找到答案
                    break;
                }
            }
            if(flag1) printf("Area %d is OK.\n", a);
            else printf("Area %d may invite more people, such as %d.\n", a, ans);
        }
    }
    return 0;
}
