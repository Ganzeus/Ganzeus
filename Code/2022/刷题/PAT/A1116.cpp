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
const int maxn = 10010;
int n, k;
map<int, int> Rank;
set<int> query;
bool isprime(int x) {
    int sqr = sqrt(1.0 * x);
    for(int i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int main() {
    cin >> n;
    int stu;
    for(int i = 1; i <= n; i++) {
        cin >> stu;
        Rank[stu] = i;
    }
    cin >> k;
    int q;
    while(k--) {
        cin >> q;
        if(Rank.find(q) == Rank.end()) printf("%04d: Are you kidding?\n", q);   // 不存在
        else if(query.find(q) != query.end()) {  // 查过
            printf("%04d: Checked\n", q);
        }else {
            if(Rank[q] == 1) printf("%04d: Mystery Award\n", q);
            else{
                if(isprime(Rank[q])) printf("%04d: Minion\n", q);
                else printf("%04d: Chocolate\n", q);
            }
            query.insert(q);
        }
    }
    return 0;
}