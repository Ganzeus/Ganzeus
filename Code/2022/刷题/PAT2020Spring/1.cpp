#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 10010;
bool isprime(int x) {
    if (x <= 1) return false;
    int sqr = sqrt(x * 1.0);
    for(int i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

string s;
int main() {
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.length(); i++) {
        string sub = s.substr(i, s.length() - i);
        if(isprime(stoi(sub))) {
            cout << sub << " Yes" << endl;
        }else {
            flag = false;
            cout << sub << " No" << endl;
        }
    }
    if(flag) cout << "All Prime!" << endl;
    return 0;
}