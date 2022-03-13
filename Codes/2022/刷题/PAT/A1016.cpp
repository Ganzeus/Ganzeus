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
const int maxn = 1010;
int toll[25];
struct Date{
    int month, day, hour, minute;
};
struct Node {
    string id;
    Date date;
    bool status;    // true表online，false表offline
}node[maxn];
bool operator<(Date a, Date b) {
    if(a.month != b.month) return a.month < b.month;
    else if(a.day != b.day) return a.day < b.day;
    else if(a.hour != b.hour) return a.hour < b.hour;
    else return a.minute < b.minute;    
}

bool cmp(Node a, Node b) {
    if(a.id != b.id) return a.id < b.id;
    else return a.date < b.date;
}
void cal(Date a, Date b, int& time, int& cost) {    // 计算时间a到b的分钟数和花费
    while(a < b) {
        time++; // time一直加到等于b为止（每次加1min），即为总相差时间
        cost += toll[a.hour];
        a.minute++;
        if(a.minute >= 60) {
            a.hour++;
            a.minute = 0;
        }
        if(a.hour >= 24) {
            a.day++;
            a.hour = 0;
        }
    }
}

int n;
int main() {
    for(int i = 0; i < 24; i++) cin >> toll[i];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> node[i].id;
        Date d;
        scanf("%d:%d:%d:%d", &d.month, &d.day, &d.hour, &d.minute);
        node[i].date = d;
        string str;
        cin >> str;
        if(str == "on-line") node[i].status = true;
        if(str == "off-line") node[i].status = false;
    }
    sort(node, node + n, cmp);
    int cur = 0, off, next;    // cur为当前用户，off为与cur配对的off，next为下一个用户（都是下标）
    while(cur < n) {    // 一次循环处理一个人的信息
        int needprint = 0;
        next = cur;
        while(next < n && node[cur].id == node[next].id) {  //找到下一个用户的下标（next）
            if(needprint == 0 && node[next].status == true){    // 找到一个online
                needprint = 1;
            }else if(needprint == 1 && node[next].status == false) {    // 在on的基础上找到一个off
                needprint = 2;  // 说明cur用户有信息要输出
            }
            next++;
        }
        if(needprint < 2) {    // cur用户没有信息输出，跳到下一个用户
            cur = next;
            continue;
        }
        // 下面计算cur用户的信息并输出（一条一条输出）
        int total = 0;
        cout << node[cur].id;
        printf(" %02d\n", node[cur].date.month);
        while(cur < next) {
            while(cur < next-1 &&!(node[cur].status == true && node[cur+1].status == false)) {   // 找到离offline在最近的一个online
                cur++;
            }
            off = cur + 1;  // 题目要求online和offline必须相邻
            if(off == next) {   // cur用户已经处理完毕
                cur = next;
                break;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d ", node[cur].date.day, node[cur].date.hour, node[cur].date.minute,node[off].date.day, node[off].date.hour, node[off].date.minute);
            int time = 0, cost = 0;
            cal(node[cur].date, node[off].date, time, cost);
            total += cost;
            printf("%d $%.2f\n", time, cost/100.0);
            cur = off+1;    // 找下一组
        }
        printf("Total amount: $%.2f\n", total/100.0);
    }
    return 0;
}