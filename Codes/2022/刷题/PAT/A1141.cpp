#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 100020;
struct Node {
    string id;
    int TWS;
    int num;
    int rank;
}node[maxn];
unordered_map<string, int> mp;    // (学校, 序号)
int n;
bool cmp(Node a, Node b) {
    if(a.TWS != b.TWS) return a.TWS > b.TWS;
    else if(a.num != b.num) return a.num < b.num;
    else return a.id < b.id;
}
int main() {
    cin >> n;
    string str, sch;
    int score;
    int index = 0;
    for(int i = 0; i < n; i++) {
        cin >> str >> score >> sch;
        for(int i = 0; i < sch.length(); i++){  // 学校名字转小写
            if(sch[i] <= 'Z' && sch[i] >= 'A')
                sch[i] += 'a' - 'A';
        }
        if(str[0] == 'B') score /= 1.5;
        if(str[0] == 'T') score *= 1.5;
        if(mp.find(sch) != mp.end()) {  // 学校出现过
            node[mp[sch]].num++;
            node[mp[sch]].TWS += score;
        }else { // 没出现过
            Node a;     // 新建结点
            a.id = sch;
            a.num = 1;
            a.TWS = score;
            node[index] = a;
            mp[sch] = index++;
        }
    }
    sort(node, node + index, cmp);
    for(int i = 0; i < index; i++) {
        if(i > 0 && node[i].TWS == node[i-1].TWS) node[i].rank = node[i-1].rank;
        else node[i].rank = i+1;
    }
    cout << index << endl;
    for(int i = 0; i < index; i++) {
        cout << node[i].rank << " " << node[i].id << " " << node[i].TWS << " " << node[i].num << endl;
    }
    return 0;
}