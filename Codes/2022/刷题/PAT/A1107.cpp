#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 1010;
int n;  
int parent[maxn];       // 每个hobby的树根
int id[maxn] = {0};  // 存放喜欢某一hobby的人id 
int isRoot[maxn] = {0}; // 每个集合的人数初始化为0
void init(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}
int findParent(int x) {
    int a = x;
    while(x != parent[x]) {
        x = parent[x];   
    }
    while(a != parent[a]) {
        int z = a;
        a = parent[a];
        parent[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int paA = findParent(a);
    int paB = findParent(b);
    if(paA != paB) {
        parent[paA] = paB;
    }
}
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; i++) {   // 对每个人
        int num;
        scanf("%d: ", &num);
        while(num--) {
            int hobby;
            scanf("%d", &hobby);
            if(id[hobby] == 0) {    // 没有人喜欢过
                id[hobby] = i;
            }
            Union(i, findParent(id[hobby]));
        }
    }
    for(int i = 1; i <= n; i++) {
        isRoot[findParent(i)]++;        // i的根结点是parent[i], 将根结点个数+1
    }
    int size = 0;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) size++;
    }
    cout << size << endl;
    sort(isRoot + 1, isRoot + 1 + n, cmp);
    for(int i = 1; i <= size; i++) {
        cout << isRoot[i];
        if(i != size) cout << " ";
    }
    return 0;
}