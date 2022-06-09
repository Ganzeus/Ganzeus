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
#define INF 0x3fffffff
const int maxn = 2010;
struct Node{
    int id;
    int score[4];   // A-C-M-E
}nodes[maxn];
int Rank[1000000][4] = {0}; // 排名A-C-M-E
int flag;
bool cmp(Node a, Node b) { return a.score[flag] > b.score[flag]; }
int n, k;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nodes[i].id >> nodes[i].score[1] >> nodes[i].score[2] >> nodes[i].score[3];
        nodes[i].score[0] = nodes[i].score[1] + nodes[i].score[2] + nodes[i].score[3];  //平均分用总分代替
    }
    for(flag = 0; flag < 4; flag++) {
        sort(nodes, nodes + n, cmp); // 轮流排名
        // 记录排名
        for(int i = 0; i < n; i++) {
            if(i >= 1 && nodes[i].score[flag] == nodes[i-1].score[flag]) {
                Rank[nodes[i].id][flag] = Rank[nodes[i-1].id][flag];
            }else Rank[nodes[i].id][flag] = i+1;
        }
    }
    char course[4] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < k; i++) {
        int qid;
        cin >> qid;
        if(Rank[qid][0] == 0) { // id不存在
            cout << "N/A" << endl;
        }else{
            int index = 0;  // 最好排名的种类(0-4对应A-C-M-E)
            for(int j = 0; j < 4; j++) {
                if(Rank[qid][j] < Rank[qid][index]) {   // 只有排名更靠前才会更新
                    index = j;
                }
            }
            cout << Rank[qid][index] << " " << course[index] << endl;
        }
    }
    return 0;
}