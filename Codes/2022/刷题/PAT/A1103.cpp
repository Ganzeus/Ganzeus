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
const int maxn = 1020;
int n, k, p;
int MaxIsum = -1;    // 最大底数和
vector<int> fac, ans, tmp;

void init() {
    int i = 0;
    while(pow(i, p) <= n) fac.push_back(pow(i++, p));
}
void DFS(int index, int num, int sum, int isum) {   // index为fac数组下标，num为个数，sum为p次方和，isum为底数和
    if(num == k && sum == n) {  // 找到一组答案
        if(isum > MaxIsum) {
            MaxIsum = isum;
            ans = tmp;
        }
        return;
    }
    if(sum > n || num > k) return;  // 没找到答案
    if(index >= 1){ // index==0不用选
        // 选第index个数
        tmp.push_back(index);   // 底数入序列
        DFS(index, num+1, sum+fac[index], isum+index);
        tmp.pop_back();
        // 不选
        DFS(index - 1, num, sum, isum);
    }
}
int main() {
    cin >> n >> k >> p;
    init();
    DFS(fac.size() - 1, 0, 0, 0);   // fac数组倒着枚举
    if(MaxIsum == -1) { // 没找到答案
        cout << "Impossible" << endl;
    }else{
        printf("%d = ", n);
        for(int i = 0; i < ans.size(); i++) {
            printf("%d^%d", ans[i], p);
            if(i != ans.size() - 1) cout << " + ";
        }
    }
    return 0;
}