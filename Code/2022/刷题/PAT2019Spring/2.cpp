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
map<string, bool> mp;
struct Node {
    string id;
    int birthdate;
};
vector<Node> node;
bool cmp(Node a, Node b) {
    return a.birthdate < b.birthdate;
}
int n, m;
int main() {
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        mp[str] = true;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> str;
        int d = stoi(str.substr(6, 8));
        node.push_back(Node{str, d});
    }
    sort(node.begin(), node.end(), cmp);
    int cnt = 0;
    vector<Node> ans;
    for(int i = 0; i < m; i++) {
        if(mp.find(node[i].id) != mp.end()) {
            cnt++;
            ans.push_back(node[i]);
        }
    }
    cout << cnt << endl;
    if(cnt == 0) cout << node[0].id << endl;
    else{
        sort(ans.begin(), ans.end(), cmp);
        cout << ans[0].id << endl;
    }
    return 0;
}