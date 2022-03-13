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
    int id;
    string name;
    int grade;
}stu[maxn];
int n, c;
bool cmp1(Node a, Node b) {
    return a.id < b.id;
}
bool cmp2(Node a, Node b) {
    if(a.name != b.name) return a.name < b.name;
    else return a.id < b.id;
}
bool cmp3(Node a, Node b) {
    if(a.grade != b.grade) return a.grade < b.grade;
    else return a.id < b.id;
}
int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> stu[i].id >> stu[i].name >> stu[i].grade;
    }
    if(c == 1) sort(stu, stu + n, cmp1);
    else if(c == 2) sort(stu, stu + n, cmp2);
    else sort(stu, stu + n, cmp3);
    for(int i = 0; i < n; i++) {
        printf("%06d ", stu[i].id);
        cout << stu[i].name << " " << stu[i].grade << endl;
    }
    return 0;
}