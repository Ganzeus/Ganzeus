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
const int maxn = 100020;

struct Node {
    string id;
    string name;
    int grade;
    Node(){}
    Node(string id_, string name_, int grade_): id{id_}, name{name_}, grade{grade_} {}
}stu[maxn];
vector<Node> ans;
bool cmp(Node a, Node b) {
    return a.grade > b.grade;
}
int n;
int l, r;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].id >> stu[i].grade;
    }
    cin >> l >> r;
    for(int i = 0; i < n; i++) {
        if(stu[i].grade >= l && stu[i].grade <= r) {
            ans.push_back(Node{stu[i].id, stu[i].name, stu[i].grade});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if(ans.size() == 0) {
        cout << "NONE" << endl;
    }else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].name << " " << ans[i].id << endl;
        }
    }
    return 0;
}