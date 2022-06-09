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
const int maxn = 400020;
ll n1, n2;
ll all[maxn];
ll a1[maxn], a2[maxn];
int main() {
    cin >> n1;
    for(ll i = 0; i < n1; i++) {
        cin >> a1[i];
    }
    cin >> n2;
    for(ll i = 0; i < n2; i++) {
        cin >> a2[i];
    }
    ll n = n1 + n2;
    ll i = 0, j = 0;
    ll index = 0;
    while(i < n1 && j < n2) {
        if(a1[i] < a2[j]) all[index++] = a1[i++];
        else all[index++] = a2[j++];
    }
    while(i < n1) all[index++] = a1[i++];
    while(j < n2) all[index++] = a2[j++];
    cout << all[(n-1)/2] << endl;
    return 0;
}