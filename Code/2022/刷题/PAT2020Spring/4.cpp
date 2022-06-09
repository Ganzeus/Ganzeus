#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 10010;
int n, m;
vector<int> out;   // 已经被输出过的数
vector<int> ini;    // 题目序列

int main() {
    cin >> n >> m;
    ini.resize(n);
    for(int i = 0; i < n; i++) cin >> ini[i];
    vector<int> tmp;
    for(int i = 0; i < m; i++) tmp.push_back(ini[i]);
    sort(tmp.begin(), tmp.end());
    cout << tmp[0];
    out.push_back(tmp[0]);
    tmp.erase(tmp.begin());
    for(int i = m; i < n || tmp.size() != 0; i++) {    // 一个一个加入排序队列
        if(i < n) {
            // int index = 0;
            // while(index < tmp.size() && tmp[index] < ini[i]) index++;
            // tmp.insert(tmp.begin() + index, ini[i]);
            tmp.push_back(ini[i]);
        }
        int size = tmp.size();
        sort(tmp.begin(), tmp.begin() + min(m, size));
        bool printed = false;
        for(int j = 0; j < tmp.size(); j++) {
            if(out.size() == 0) {
                cout << tmp[j];
                out.push_back(tmp[j]);
                tmp.erase(tmp.begin() + j);
                printed = true;
                break;
            }else if(tmp[j] >= *out.rbegin()) {
                cout << " " << tmp[j];
                out.push_back(tmp[j]);
                tmp.erase(tmp.begin() + j);
                printed = true;
                break;
            }
        }
        if(!printed) {
            cout << endl;
            out.clear();
        }
    }
    return 0;
}