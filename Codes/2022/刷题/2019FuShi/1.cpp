#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
// bool p[maxn];
int prime[maxn];
bool isprime(ll x) {
    if(x <= 1) return false;
    ll sqr = sqrt(x * 1.0);
    for(ll i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
void init(int& index) {   // 打表
    for(int i = 2; i < maxn; i++) {
        if(isprime(i)) {
            // p[i] = true;
            prime[index++] = i;
        }
    }
}
// ll combine(ll a, ll b) {
//     int cntb = 0;
//     ll tmp = b;
//     while(tmp) {
//         tmp/=10;
//         cntb++;
//     }
//     return a * pow(10, cntb) + b;
// }
ll n;
vector<ll> fac;
int main() {
    int index = 0;
    init(index);
    // cout << index << endl;  // 9593
    cin >> n;
    
    int sqr = sqrt(n * 1.0);
    for(int i = 0; i < sqr; i++) {
        if(prime[i] > n) break;
        ll a = prime[i], cnt = 0;
        while(n % a == 0) {
            cnt++;
            n /= a;
        }
        if(cnt == 1) fac.push_back(a);
        else if(cnt > 1) {
            fac.push_back(a);   
            fac.push_back(cnt);
        }
    }
    string ans = "";
    for(int i = 0; i < fac.size(); i++) {
        ans += to_string(fac[i]);
    }
    // for(int i = 0; i < fac.size(); i++) {
    //     ans = combine(ans,fac[i]);
    // }
    // cout << fac[fac.size()-1] << endl;
    cout << ans << endl;
    if(isprime(stoll(ans))) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}