#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
const int maxn = 100010;
bool isprime(int x) {
    if(x <= 1) return false;
    int sqr = sqrt(x * 1.0);
    for(int i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
bool isSexy(int x) {
    if(isprime(x) && isprime(x-6)) return true;
    if(isprime(x) && isprime(x+6)) return true;
    return false;
}
int n;
int main() {
    cin >> n;
    if(isprime(n) && isprime(n-6)) {
        cout << "Yes" << endl;
        cout << n-6 << endl;
    }else if(isprime(n) && isprime(n+6)) {
        cout << "Yes" << endl;
        cout << n + 6 << endl;
    }else {
        cout << "No" << endl;
        int i = n;
        while(!isSexy(i)) i++;
        cout << i << endl;
    }
    return 0;
}