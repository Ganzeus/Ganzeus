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
struct Date{
    int hh, mm, ss;
};
int timeToInt(Date d) {
    return d.ss + 60*(d.mm) + 60*60*d.hh;
}
struct Node {
    string id;
    int time;
    bool status;
}node[maxn], valid[maxn];
int n, k;
bool cmp(Node a, Node b) {
    if(a.id != b.id) return a.id < b.id;
    else return a.time < b.time;
}
bool cmp2(Node a, Node b) {
    return a.time < b.time;
}
map<string, int> mp;   // 每个人停车总时间(s)
int main() {
    cin >> n >> k;
    string str;
    Date d;
    for(int i = 0; i < n; i++) {
        cin >> node[i].id;
        scanf(" %d:%d:%d ", &d.hh, &d.mm, &d.ss);
        node[i].time = timeToInt(d);
        cin >> str;
        if(str == "in") node[i].status = true;
        else if(str == "out") node[i].status = false;
    }
    sort(node, node + n, cmp);

    int maxLength = -1;    // 最长停车时间
    int index = 0;  // 记录valid数组长度
    for(int i = 0; i < n-1; i++) {    // 遍历所有记录，统计每个人的总停车时间以及最长时间
        if(node[i].id == node[i+1].id && node[i].status == true && node[i+1].status == false){
            valid[index++] = node[i];   // 匹配则存入valid数组
            valid[index++] = node[i+1];
            int length = node[i+1].time - node[i].time; // 本次停车时间
            mp[node[i].id] += length;   // 更新总时间
            if(mp[node[i].id] > maxLength) {
                maxLength = mp[node[i].id];
            }
        }
    }

    sort(valid, valid + index, cmp2);
    int now = 0, num = 0;   // 当前记录，当前车辆数
    for(int i = 0; i < k; i++) {
        Date q;
        scanf("%d:%d:%d", &q.hh, &q.mm, &q.ss);
        int time = timeToInt(q);
        while(now < index && valid[now].time <= time) { // now增加到当前时间
            if(valid[now].status == true) num++; // 车辆在停车场，个数+1
            else if(valid[now].status == false) num--;
            now++;
        }
        cout << num << endl;
    }
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second == maxLength) cout << it->first << " ";
    }
    printf("%02d:%02d:%02d\n", maxLength/3600, maxLength%3600/60, maxLength%60);
    return 0;
}