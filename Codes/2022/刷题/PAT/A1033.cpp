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
const int maxn = 520;
struct Node {
    double price, dis;
}node[maxn];

bool cmp(Node a, Node b) {  // 按距离排序
    return a.dis < b.dis;
}
double Cm, D, Da;
int n;
int main() {
    cin >> Cm >> D >> Da >> n;
    double maxT = Cm * Da;
    for(int i = 0; i < n; i++) {
        cin >> node[i].price >> node[i].dis;
    }
    node[n].price = 0;
    node[n].dis = D;
    sort(node, node + n, cmp);
    if(node[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
    }else{
        double ans = 0;
        double remain = 0;  // 当前油箱剩余油量
        int now = 0;    // 当前加油站
        while(now < n) {
            int next = -1;  // 下一个应该去的加油站编号
            double minP = INF;  // 当前最低油价
            // 在从当前加油站能到达的范围内找到油价低的
            for(int i = now+1; i <= n && node[i].dis <= node[now].dis + maxT; i++) {
                if(node[i].price < minP) {
                    minP = node[i].price;
                    next = i;
                }
                if(node[i].price < node[now].price) {   // 找到比当前加油站还便宜的，直接去
                    break;
                }
            }
            if(next == -1) break;  // 范围内没有能去的加油站，退出
            double fuel = node[next].dis - node[now].dis;    // now到next需要的距离
            if(node[next].price < node[now].price) {    // 加刚好能到next的油量
                if(remain < fuel) {
                    ans += (fuel - remain) * node[now].price / Da;
                    remain = 0;
                }else remain -= fuel;
            }else { // next价格比当前高
                // 在当前加油站加满
                ans += (maxT - remain) * node[now].price / Da;
                remain = maxT - fuel;
            }
            now = next;    // 去下一个加油站
        }
        if(now == n) {  // 能到终点
            printf("%.2f", ans);
        }else printf("The maximum travel distance = %.2f", node[now].dis + maxT);
    }
    return 0;
}