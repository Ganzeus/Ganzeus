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
const int maxn = 50020;
int n, k;
struct Node{
    int id;
    int fq;
};
int cnt[maxn];  // 记录出现次数
set<Node> st;
bool operator<(Node a, Node b) {    // set自动排序
    if(a.fq != b.fq) return a.fq > b.fq;
    else return a.id < b.id;
}

int main() {
    cin >> n >> k;
    int d;
    for(int i = 0; i < n; i++) {
        cin >> d;
        if(i != 0) {    // 输出
            cout << d << ":";
            // int num = min(k, size);
            auto it = st.begin();
            int size = 0;
            for(auto it = st.begin(); size < k && it != st.end(); it++) {
                cout << " " << it->id;
                size++;
            }
            cout << endl;   
        }
        // 加入本次输入的结点
        auto it = st.find(Node{d, cnt[d]});
        if(it != st.end()) {  // 结点出现过
            st.erase(it);   // 删除重新加入
        }
        cnt[d]++;
        st.insert(Node{d, cnt[d]});
    }
    return 0;
}