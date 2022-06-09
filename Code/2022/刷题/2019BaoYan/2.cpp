#include <bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
vector<int> ini;
int n, m;
int main() {
    cin >> n >> m;
    ini.resize(n);
    for(int i = 0; i < n; i++) cin >> ini[i];
    sort(ini.begin(), ini.end());
    int flag = 1;   // 1表示正向
    for(int i = 0; i < n; i += m) { // 对于每一块
        int size = min(i+m, n);
        if(flag == 1) {  // 正向
            for(int j = i; j < size; j++) {
                cout << ini[j];
                (j == size-1) ? cout << "\n" : cout << " ";
            }
        }else {
            for(int j = size-1; j >= i; j--) {
                cout << ini[j];
                (j == i) ? cout << "\n" : cout << " ";
            }
        }
        flag *= -1;
    }
    return 0;
}