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
const int maxn = 30010;

struct Node {
    string id;
    int score;
    int final_rank;
    int local_num;
    int local_rank;
}stu[maxn];
bool cmp(Node a, Node b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}
int n, k;
int main() {
    cin >> n;
    int total = 0;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        int start = total;  // 当前组的起始下标
        for(int j = 0; j < k; j++) {
            cin >> stu[total].id >> stu[total].score;
            stu[total].local_num = i;
            total++;
        }
        // 组内排序
        sort(stu + start, stu + start + k, cmp);
        for(int j = start; j < start + k; j++) {
            if(j > start && stu[j].score == stu[j-1].score) {
                stu[j].local_rank = stu[j-1].local_rank;
            }else stu[j].local_rank = j - start + 1;
        }
    }
    // cout << total << endl;
    sort(stu, stu + total, cmp);    // 全部排序
    for(int i = 0; i < total; i++) {
        if(i > 0 && stu[i].score == stu[i-1].score) {
            stu[i].final_rank = stu[i-1].final_rank;
        }else stu[i].final_rank = i + 1;
    }
    cout << total << endl;
    for(int i = 0; i < total; i++) {
        cout << stu[i].id << " " << stu[i].final_rank << " " << stu[i].local_num << " " << stu[i].local_rank << endl;
    }
    return 0;
}