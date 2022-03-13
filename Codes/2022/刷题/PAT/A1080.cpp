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
const int maxn = 40010;
struct Node {
    int id;
    int Ge; // 高考分
    int G;  // 总分
    int rank;
    vector<int> apply;
}node[maxn];
bool cmp(Node a, Node b) {
    if(a.G != b.G) return a.G > b.G;
    else return a.Ge > b.Ge;
}
bool cmp2(Node a, Node b) {
    return a.id < b.id;
}
int n, m, k;
int quota[105];
vector<Node> admit[105];  // 每个学校的录取名单
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) cin >> quota[i];
    int ge, gi;
    for(int i = 0; i < n; i++) {
        node[i].id = i;
        cin >> ge >> gi;
        node[i].Ge = ge;
        node[i].G = ge + gi;
        int a;
        for(int j = 0; j < k; j++) {    // 输入志愿
            cin >> a;
            node[i].apply.push_back(a);
        }
    }
    sort(node, node + n, cmp);
    for(int i = 0; i < n; i++) {    // 记录排名
        if(i > 0 && node[i].G == node[i-1].G && node[i].Ge == node[i-1].Ge) node[i].rank = node[i-1].rank;
        else node[i].rank = i + 1;
    }
    for(int i = 0; i < n; i++) {    // 对于每个人(排名顺序)
        for(int j = 0; j < node[i].apply.size(); j++) { // 遍历志愿队列
            int app = node[i].apply[j]; // 志愿学校
            int lastIndex = admit[app].size() - 1;  // 当前学校的最后一个录取
            if(quota[app] > 0) {    // 学校有余量
                admit[app].push_back(node[i]);
                quota[app]--;
                break;
            }else if(lastIndex != -1 && node[i].rank == admit[app][lastIndex].rank) {  // 没有余量时，若与当前学校上一个录取的人排名相同，则也应该录取
                admit[app].push_back(node[i]);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        sort(admit[i].begin(), admit[i].end(), cmp2);
    }
    for(int i = 0; i < m; i++) {    // 输出每个学校的录取信息
        for(int j = 0; j < admit[i].size(); j++) {
            cout << admit[i][j].id;
            if(j != admit[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}