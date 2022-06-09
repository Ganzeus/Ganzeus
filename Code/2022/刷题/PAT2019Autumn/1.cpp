#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
bool isprime(int x) {
    if(x <= 2) return false;
    int sqr = sqrt(x*1.0);
    for(int i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int caldigits(int n) {
    int ret = 0;
    while(n) {
        ret += n % 10;
        n/=10;
    }
    return ret;
}
// struct Node{
//     int n, A;
// };
// vector<Node> ans;
// bool cmp(Node a, Node b) {
//     if(a.n != b.n) return a.n < b.n;
//     else return a.A < b.A;
// }
int main() {
    int t;
    cin >> t;
    
    for(int j = 1; j <= t; j++) {
        vector<vector<int> > ans;
        ans.resize(100);
        printf("Case %d\n", j);
        int k, m;
        cin >> k >> m;
        if(k*9 < m) {
            cout << "No Solution"<< endl;
            continue;
        }
        int start = pow(10, k-1);
        int cnt = 0;
        // 末尾必须是9
        for(int i = start + 9; i < start*10; i += 10) {   // 由100..09开始，直到100..00(k个0), 每次+10
            if(caldigits(i) == m) {
                int n = caldigits(i+1);
                if(isprime(gcd(m, n))) {
                    ans[n].push_back(i);
                    cnt++;
                }
            }
        }
        if(cnt == 0) cout << "No Solution" << endl;
        else {
            for(int i = 0; i < 100; i++) {
                if(ans[i].size() != 0){
                    for(int p = 0; p < ans[i].size(); p++){
                        printf("%d %d\n", i, ans[i][p]);
                    }
                }
            }
        }
    }
    return 0;
}