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
const int maxn = 15;
int Hash[maxn];
int n;
struct Node {
    int lchild, rchild;
}node[maxn];

vector<int> level, in;
void levelOrder(int root, vector<int>& path) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        path.push_back(front);
        if(node[front].lchild != -1) q.push(node[front].lchild);
        if(node[front].rchild != -1) q.push(node[front].rchild);
    }
}
void inOrder(int root, vector<int>& path) {
    if(root == -1) return;
    if(node[root].lchild != -1) inOrder(node[root].lchild, path);
    path.push_back(root);
    if(node[root].rchild != -1) inOrder(node[root].rchild, path);
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) Hash[i] = 1;
    char lc, rc;
    for(int i = 0; i < n; i++) {
        cin >> lc >> rc;
        int l = lc - '0', r = rc - '0';
        if(lc == '-') l = -1;
        if(rc == '-') r = -1;
        node[i].lchild = r;     // 反转二叉树
        node[i].rchild = l;
        Hash[l]--;
        Hash[r]--;
    }
    int root = 0;
    for(int i = 0; i < n; i++) {    // 找树根
        if(Hash[i]) {
            root = i;
            break;
        }
    }
    inOrder(root, in);
    levelOrder(root, level);
    for(int i = 0; i < n; i++) {
        cout << level[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << in[i];
        if(i != n-1) cout << " ";
    }
    return 0;
}