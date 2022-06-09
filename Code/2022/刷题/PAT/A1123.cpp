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
const int maxn = 50;
struct node {
    int data;
    node* l;
    node* r;
    int height;
};
node* newNode(int x) {
    node* root = new node;
    root->data = x;
    root->height = 1;
    root->l = root->r = nullptr;
    return root;
}
int getHeight(node* root) {
    if(root == nullptr) return 0;
    else return root->height;
}
void updateHeight(node* root) {
    root->height = max(getHeight(root->l), getHeight(root->r)) + 1;
}
int getBF(node* root) {
    return getHeight(root->l) - getHeight(root->r);
}

void L(node*& root) {
    node* tmp = root->r;
    root->r = tmp->l;
    tmp->l = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void R(node*& root) {
    node* tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void insert(node*& root, int x) {
    if(root == nullptr) {
        root = newNode(x);
        return;
    }
    if(x < root->data) {    // 往左插
        insert(root->l, x);
        updateHeight(root);
        if(getBF(root) == 2) {
            if(getBF(root->l) == 1){
                R(root);
            }else if(getBF(root->l) == -1) {
                L(root->l);
                R(root);
            }
        }
    }else { // 往右插
        insert(root->r, x);
        updateHeight(root);
        if(getBF(root) == -2) {
            if(getBF(root->r) == -1) {
                L(root);
            }else if(getBF(root->r) == 1) {
                R(root->r);
                L(root);
            }
        }
    }
}
int n;
vector<int> level;
bool isComplete = true;
void BFS(node* root, int n) {
    queue<node*> q;
    q.push(root);
    while(n) {
        node* front = q.front();
        q.pop();
        if(n > 0 && front == nullptr){  // 还没访问完所有非空结点时就碰到了空结点，则不是完全二叉树
            isComplete = false;
            continue;   // 空结点跳过不访问
        }
        level.push_back(front->data);   // 非空结点入序列
        n--;
        q.push(front->l);
        q.push(front->r);
    }
}

int main() {
    cin >> n;
    int d;
    node* root = nullptr;
    for(int i = 0; i < n; i++) {
        cin >> d;
        insert(root, d);
    }
    BFS(root, n);
    for(int i = 0; i < level.size(); i++) {
        cout << level[i];
        if(i != level.size() - 1) cout << " ";
        else cout << endl;
    }
    if(isComplete) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}