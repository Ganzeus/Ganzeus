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
const int maxn = 100010;
struct Node{
    string name;
    int age;
    int worth;
}node[maxn], q[maxn];   // 所有人、各自年龄中财富排名前100的人
int n, k;
int Agenum[maxn] = {0}; // 存放某一年龄的人数
bool cmp(Node a, Node b) {
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    else return a.name < b.name;
}
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> node[i].name >> node[i].age >> node[i].worth;
    }
    sort(node, node + n, cmp);      // 先排序，在判断年龄是否在给定区间
    int index = 0;
    for(int i = 0; i < n; i++) {     // 遍历所有人（的年龄）
        if(Agenum[node[i].age] < 100) { // 当前年龄选择的人数不到100
            Agenum[node[i].age]++;      // 当前年龄人数+1
            q[index++] = node[i];       // 加入查询数组（按排序后的顺序加入，因此不用排序）
        }
    }
    for(int i = 1; i <= k; i++) {     
        int num, Min, Max;
        cin >> num >> Min >> Max;
        printf("Case #%d:\n", i);
        int printed = 0;    // 已输出的个数
        for(int j = 0; j < index && printed < num; j++) {   
            if(q[j].age >= Min && q[j].age <= Max) {    // 只需要判断年龄是否在给定区间即可输出（整体已经排好序）
                cout << q[j].name << " " << q[j].age << " " << q[j].worth << endl;
                printed++;
            }
        }   
        if(printed == 0) cout << "None" << endl;    
    }
    return 0;
}