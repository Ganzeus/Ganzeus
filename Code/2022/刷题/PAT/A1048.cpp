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
const int maxn = 100020;

int n;
int sum;
vector<int> coins;
int main() {
    cin >> n >> sum;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        coins.push_back(a);
    }
    sort(coins.begin(), coins.end());
    int i = 0, j = coins.size() - 1;
    while(i < j) {
        if(coins[i] + coins[j] < sum) i++;
        else if(coins[i] + coins[j] > sum) j--;
        else break;
    }
    if(i >= j) {
        cout << "No Solution" << endl;
    }else cout << coins[i] << " " << coins[j] << endl;
    return 0;
}