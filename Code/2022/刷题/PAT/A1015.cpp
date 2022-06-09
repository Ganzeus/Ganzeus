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
bool isprime(int n) {
    if(n < 2) return false;
    int sqr = sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n%i == 0) return false;
    }
    return true;
}
void convert(int n, int d, vector<int>& v){
    while(n) {
        v.push_back(n%d);
        n /= d;
    }
}
int DtoT(vector<int> v, int d){
    int value = 0;
    for(int i = 0; i < v.size(); i++) {
        value = value * d + v[i];
    }
    return value;
}
int n, d;
int main() {
    cin >> n;
    vector<int> v;
    while(n >= 0) {
        cin >> d;
        v.clear();
        convert(n, d, v);
        int rn = DtoT(v, d);
        // cout << rn << endl;
        if(isprime(n) && isprime(rn)) cout << "Yes\n";
        else cout << "No\n";
        cin >> n;
    }
    return 0;
}