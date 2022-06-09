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
const int maxn = 100010;
map<int, bool> mp;  // 是否满足要求
set<int> ans;   // 答案递增排序
int n;
int num[maxn]{0};
int main() {
    cin >> n;
    int min = INF, max = 0;
    for(int i = 0; i < n; i++) {   // 从左到右边读入边判断
        cin >> num[i];
        if(num[i] > max) {      // 右边比左边最大值大，满足
            mp[num[i]] = true;
            max = num[i];   // 更新左边的最大值
        }
        else mp[num[i]] = false;    // 否则不满足
    }
    for(int i = n-1; i >= 0; i--) {
        if(mp[num[i]]) {    // 只判断暂时满足的
            if(num[i] > min) mp[num[i]] = false;    // 左边比右边最小值大，不满足
        }
        if(num[i] < min) min = num[i];  // 更新右边的最小值   
    }
    for(map<int, bool>::iterator it = mp.begin(); it != mp.end(); it++) {   // 满足条件的存入答案集合
        if(it->second) ans.insert(it->first);
    }
    cout << ans.size() << endl;
    int i = 0;
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++, i++){
        cout << *it;
        if(i != ans.size() - 1) cout << " ";
    }
    return 0;
}