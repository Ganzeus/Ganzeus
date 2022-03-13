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
const int maxn = 10010;
struct Node{
    int id;
    int score[6];   // 每道题的最高分数.-2表示没交过，-1表示编译错误
    int totals;     // 总分
    int psnum;  // perfect-solved题的个数
    int rank;

}node[maxn];
bool cmp(Node a, Node b) {
    if(a.totals != b.totals) return a.totals > b.totals;    // 先按总分降序
    else if(a.psnum != b.psnum) return a.psnum > b.psnum;  // 再按满分数降序
    else return a.id < b.id;    // 最后按id升序
}
int mscore[6];  // 每道题的总分
int n, k, m;
void init() {
    for(int i = 0; i < maxn; i++) {
        fill(node[i].score, node[i].score + 6, -2); // 没交过
        node[i].totals = -8;
    }
}
int main() {
    init();
    cin >> n >> k >> m;
    for(int i = 1; i <= k; i++) cin >> mscore[i];
    int uid, pid, sc;
    while(m--) {
        cin >> uid >> pid >> sc;
        node[uid].id = uid;
        if(sc > node[uid].score[pid]) {
            node[uid].score[pid] = sc;
            if(sc == mscore[pid]) node[uid].psnum++;    // 第一次满分，满分次数+1
        }
    }
    for(int i = 1; i <= n; i++) {   // 算总分
        int total = 0;
        for(int j = 1; j <= k; j++) {
            if(node[i].score[j] >= 0) total += node[i].score[j];
        }
        node[i].totals = total;
    }
    sort(node, node + maxn, cmp);
    for(int i = 0; i < n; i++) {    // 记录排名
        if(i > 0 && node[i].totals == node[i-1].totals) node[i].rank = node[i-1].rank;
        else node[i].rank = i+1;
    }
    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(int j = 1; j <= k; j++) {
            if(node[i].score[j] >= 0) { // 只要有分就应输出
                flag = true;
                break;
            }
        }
        if(flag) {  // 输出
            cout << node[i].rank;
            printf(" %05d %d ", node[i].id, node[i].totals);
            for(int j = 1; j <= k; j++) {
                if(node[i].score[j] == -2) cout << "-";
                else if(node[i].score[j] == -1) cout << "0";
                else cout << node[i].score[j];
                if(j != k) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}