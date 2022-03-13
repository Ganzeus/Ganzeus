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
const int maxn = 1020;
set<int> ans;
int n;
int cal(int n) {
    int ret = 0;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
int main() {
    cin >> n;
    int num;
    while(n--) {
        cin >> num;
        ans.insert(cal(num));
    }
    cout << ans.size() << endl;
    int i = 0;
    for(set<int>::iterator it = ans.begin(); it != ans.end(); i++, it++) {
        cout << *it;
        if(i != ans.size() - 1) cout << " ";
    }

    return 0;
}