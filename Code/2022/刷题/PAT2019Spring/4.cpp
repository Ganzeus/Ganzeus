#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 40;
struct node{
    int data;
    node* l, * r;
};
int n;
int post[maxn], in[maxn];
map<int, int> level, lchild, rchild, parent, sibling;
node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) return nullptr;
    node* root = new node;
    root->data = post[postR];
    int i = inL;
    for(; i <= inR; i++) {
        if(in[i] == post[postR]) break;
    }
    int numLeft = i - inL;
    root->l = create(postL, postL + numLeft - 1, inL, i-1);
    root->r = create(postL + numLeft, postR - 1, i + 1, inR);
    if(root->l != nullptr) {
        lchild[root->data] = root->l->data;
        parent[root->l->data] = root->data;
    }
    if(root->r != nullptr) {
        rchild[root->data] = root->r->data;
        parent[root->r->data] = root->data;
    }
    if(root->r != nullptr && root->l != nullptr) {  // 左右都不空
        sibling[root->l->data] = root->r->data;
        sibling[root->r->data] = root->l->data;
    }
    return root;
}

bool isFull = true;
void DFS(node* root, int l) {
    if(root == nullptr) return;
    level[root->data] = l;
    if((root->l == nullptr && root->r != nullptr) || (root->l != nullptr && root->r == nullptr)) {
        isFull = false; // 只有一个子树，说明不是满二叉树
    }
    if(root->l != nullptr) DFS(root->l, l+1);
    if(root->r != nullptr) DFS(root->r, l+1);
}
int main() { 
    cin >> n;
    for(int i = 0; i < n; i++) cin >> post[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    node* root = create(0, n-1, 0, n-1);
    DFS(root, 1);   // 根结点level=1
    int k;
    cin >> k;
    string statement;
    getchar();
    for(int i = 0; i < k; i++) {
        getline(cin, statement);
        bool flag = true;
        if(statement.substr(statement.size()-4, 4) == "root") {
            int d = stoi(statement.substr(0, statement.size() - 12));
            if(root->data != d) flag = false;
        }
        if(statement == "It is a full tree"){
            flag = isFull;
        }
        if(statement.substr(statement.size() - 8, 8) == "siblings"){
            int a, b;
			sscanf(statement.c_str(),"%d and %d are siblings", &a, &b);
            if(sibling[a] != b) flag = false;
        }
        if(statement.find("parent") != string::npos) {
            int a, b;
			sscanf(statement.c_str(),"%d is the parent of %d", &a, &b);
            if(parent[b] != a) flag = false;
        }
        if(statement.find("left") != string::npos) {
            int a, b;
			sscanf(statement.c_str(), "%d is the left child of %d", &a, &b);
            if(lchild[b] != a) flag = false;
        }
        if(statement.find("right")!= string::npos) {
            int a, b;
			sscanf(statement.c_str(), "%d is the right child of %d", &a, &b);
            if(rchild[b] != a) flag = false;
        }
        if(statement.find("same") != string::npos) {
            int a, b;
			sscanf(statement.c_str(), "%d and %d are on the same level", &a, &b);
            if(level[a] != level[b]) flag = false;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}