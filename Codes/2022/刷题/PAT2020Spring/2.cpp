#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1010;
set<int> dif;   // 存放当前序列元素的差值
set<int> now;   // 当前序列所有元素集合
int n, m;
set<int> winner;
vector<int> rnd[maxn];
int main() {
    int b1, b2;
    cin >> b1 >> b2;
    now.insert(b1); now.insert(b2);
    dif.insert(abs(b1-b2));
    cin >> n >> m;
    int d;
    for(int i = 1; i <= n; i++) {
        winner.insert(i);   // 默认全是赢家
        for(int j = 1; j <= m; j++) {
            cin >> d;
            rnd[j].push_back(d);
        }
    }
    set<int> out;
    for(int i = 1; i <= m; i++) {    // 每一轮
        out.clear();
        for(int j = 0; j < n; j++) {   // 对每个人
            if(winner.find(j+1) != winner.end()) {    // 没有被淘汰
                auto it = dif.find(rnd[i][j]);
                int tmp = *it;
                if(it != dif.end() && now.find(*it) == now.end()) {   // 差值存在（不重复）
                    for(auto it1 = now.begin(); it1 != now.end(); it1++) { // 加入当前数与已有数的差值
                        dif.insert(abs(rnd[i][j] - *it1));
                    }
                    now.insert(rnd[i][j]);
                    dif.erase(it);  // 删除重复
                }else { // 差值不存在，淘汰
                    out.insert(j+1);
                }
            }
        }
        if(out.size() != 0) {
            printf("Round #%d: ", i);
            for(auto it = out.begin(); it != out.end(); it++) {
                cout << *it << " ";
                winner.erase(winner.find(*it));
            }
            cout << "is out." << endl;
        }
    }
    if(winner.size() == 0) cout << "No winner." << endl;
    else {
        cout << "Winner(s):";
        for(auto it = winner.begin(); it != winner.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}