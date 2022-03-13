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
const int maxn = 10010;
struct Node {
    string id;
    int height;
}node[maxn];
bool cmp(Node a, Node b) {
    if(a.height != b.height) return a.height < b.height;
    else return a.id > b.id;    // 字典序小的算高
}
int n, k;
vector<Node> row[15];
int main() {
    cin >> n >> k;
    int m = n/k; // 每排n/k个
    for(int i = 0; i < n; i++) {
        cin >> node[i].id >> node[i].height;
    }
    sort(node, node + n, cmp);
    for(int i = 0; i < k; i++) {    // 对于每排
        int num;    // 每排的人数
        if(n - i * m >= 2 * m) num = m;
        else num = n - i * m;
        int mid = num/2+1;  // 这一排的中间位置
        int flag = 1;
        for(int j = i*m + num - 1; j >= i*m; j--) { // 由大到小
            if(flag == 1) row[i].insert(row[i].end(), node[j]);    // 先往右
            if(flag == -1) row[i].insert(row[i].begin(), node[j]);   // 再往左
            flag *= -1;
        }
    }
    for(int i = k-1; i >= 0; i--) {
        for(int j = 0; j < row[i].size(); j++) {
            cout << row[i][j].id;
            if(j != row[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}