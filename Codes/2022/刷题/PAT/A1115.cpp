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
const int maxn = 25;
struct node {
    int data;
    node* lchild, * rchild;
};
node* newNode(int x) {
    node* root = new node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    return root;
}
void insert(node*& root, int x) {
    if(root == nullptr) {
        root = newNode(x);
        return;
    }
    if(x <= root->data) {
        insert(root->lchild, x);
    }else insert(root->rchild, x);
}

int n;
int maxDepth = 0;
map<int, int> cnt;  // 每层深度的结点数
void DFS(node* root, int depth){
    if(root == nullptr) return;
    cnt[depth]++;
    if(depth > maxDepth) maxDepth = depth;
    if(root->lchild != nullptr) DFS(root->lchild, depth+1);
    if(root->rchild != nullptr) DFS(root->rchild, depth+1);
}
int main() {
    cin >> n;
    int d;
    node* root = nullptr; 
    for(int i = 0; i < n; i++) {
        cin >> d;
        insert(root, d);
    }
    DFS(root, 0);
    cout << cnt[maxDepth] << " + " << cnt[maxDepth-1] << " = " << cnt[maxDepth]+cnt[maxDepth-1] << endl;
    return 0;
}