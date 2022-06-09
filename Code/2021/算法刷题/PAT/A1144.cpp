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
int n;
bool hash[maxn];
int main() {
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        hash[num] = true;
    }
}