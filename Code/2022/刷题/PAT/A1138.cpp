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
struct node {
    int data;
    node* l, * r;
};
vector<int> pre, in, post;
node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR) return nullptr;
    node* root = new node;
    root->data = pre[preL];
    int k = inL;
    for(; k <= inR; k++) {
        if(in[k] == pre[preL]) break;
    }
    int numLeft = k - inL;
    root->l = create(preL + 1, preL + numLeft, inL, k-1);
    root->r = create(preL + numLeft + 1, preR, k+1, inR);
    return root;
}
void postOrder(node* root, vector<int>& path) {
    if(root == nullptr) return;
    postOrder(root->l, path);
    postOrder(root->r, path);
    path.push_back(root->data);
}
int n;
int main() {
    cin >> n;
    in.resize(n);
    pre.resize(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    node* root = create(0, n-1, 0, n-1);
    postOrder(root, post);
    cout << post[0] << endl;
    return 0;
}