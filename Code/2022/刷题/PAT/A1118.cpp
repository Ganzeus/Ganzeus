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
int n, k, q;
set<int> num;
int father[maxn];
void init() {
    for(int i = 1; i < maxn; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}
bool isRoot[maxn];
int main() {
    init();
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k;
        int f;  // 第一个结点当做根
        cin >> f;
        num.insert(f);
        int d;
        for(int i = 0; i < k-1; i++) {
            cin >> d;
            num.insert(d);
            Union(d, f);
        }
    }
    n = num.size(); // n赋值为鸟的个数
    int size = 0;
    for(int i = 1; i <= n; i++) {
        isRoot[findFather(i)] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(isRoot[i]) size++;
    }
    cout << size << " " << n << endl;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        if(findFather(n1) == findFather(n2)) cout << "Yes\n";
        else cout << "No" << endl;
    }
    return 0;
}