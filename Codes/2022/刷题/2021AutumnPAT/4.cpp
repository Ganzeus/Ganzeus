#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
const int maxn = 35;
int n;
struct Node {
    int key;
    int value;
}node[maxn];
bool cmp(Node a, Node b) {
    return a.value < b.value;
}
struct TreeNode{
    Node data;
    TreeNode* lchild, * rchild;
};
TreeNode* newNode(Node data) {
    TreeNode* nd = new TreeNode;
    nd->data = data;
    nd->lchild = nd->rchild = nullptr;
    return nd;
}
void insert(TreeNode* &root, Node data) {
    if(root == nullptr) {
        root = newNode(data);
        return;
    }
    if(data.key < root->data.key) {
        insert(root->lchild, data);
    }else insert(root->rchild, data);
}
void BFS1(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int num = 0;
    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        num++;
        cout << front->data.key;
        if(num != n) cout << " ";
        if(front->lchild != nullptr) {
            q.push(front->lchild);
        }
        if(front->rchild != nullptr) {
            q.push(front->rchild);
        }
    }
}
void BFS2(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int num = 0;
    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        num++;
        cout << front->data.value;
        if(num != n) cout << " ";
        if(front->lchild != nullptr) {
            q.push(front->lchild);
        }
        if(front->rchild != nullptr) {
            q.push(front->rchild);
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> node[i].key >> node[i].value;
    }
    sort(node, node + n, cmp);  // 按value排序
    TreeNode* root = newNode(node[0]);
    for(int i = 1; i < n; i++) {
        insert(root, node[i]);
    }
    BFS1(root);
    cout << endl;
    BFS2(root);
    return 0;
    
}