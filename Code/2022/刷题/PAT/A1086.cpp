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
    node* l;
    node* r;
};

vector<int> in, pre, post;
stack<int> stk;
int n;
node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR) return nullptr;
    node* root = new node;
    root->data = pre[preL];
    int i = inL;
    for(; i <= inR; i++) {
        if(in[i] == pre[preL]) break;
    }
    int numLeft = i - inL;
    root->l = create(preL+1, preL + numLeft, inL, i-1);
    root->r = create(preL + numLeft + 1, preR, i+1, inR);
    return root;
}
void postOrder(node* root, vector<int>& path) {
    if(root == nullptr) return;
    postOrder(root->l, path);
    postOrder(root->r, path);
    path.push_back(root->data);
}
int main() {
    cin >> n;
    string str;
    int d;
    for(int i = 0; i < n || !stk.empty();) {
        cin >> str;
        if(str == "Push") {
            cin >> d;
            stk.push(d);
            pre.push_back(d);
            i++;
        }
        if(str == "Pop"){
            in.push_back(stk.top());
            stk.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postOrder(root, post);
    for(int i = 0; i < post.size(); i++) {
        cout << post[i];
        if(i != post.size() - 1) cout << " ";
    }
    return 0;
}