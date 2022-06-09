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
};
int pre[maxn], post[maxn];
bool isUnique = true;
node* create(int preL, int preR, int postL, int postR) {
    if(preL > preR) return nullptr; // 递归边界
    node* root = new node;
    root->data = pre[preL]; // 根结点
    // 在后序序列中找到先序序列的第二个结点，即为左子树的根结点, 下标为k。
    int k = postL, numLeft = 0;
    for(; k < postR; k++) {
        numLeft++;  // preL == preR时numLeft用k-postL+1会出错，因此要在循环中记录结点个数
        if(post[k] == pre[preL + 1]) break;
    }

    if(k == postR-1) isUnique = false;  // 先序第二个结点等于后序倒数第二个，即只有一棵子树，说明不唯一
    
    root->l = create(preL+1, preL + numLeft, postL, k);   // 当有一边子树不存在时，默认为左子树
    root->r = create(preL + numLeft + 1, preR, k+1, postR-1);
    return root;
}
vector<int> in;
void inOrder(node* root) {
    if(root == nullptr) return;
    inOrder(root->l);
    in.push_back(root->data);
    inOrder(root->r);
}
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    node* root = create(0, n-1, 0, n-1);
    inOrder(root);
    if(isUnique) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = 0; i < in.size(); i++) {
        cout << in[i];
        if( i != in.size() - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}