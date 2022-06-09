#include <bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
int t, n;
struct node{
    int data;
    int height;
    node* l, * r;
};
int getHeight(node* root) {
    if(root == nullptr) return 0;
    return root->height;
}
void updateHeight(node*& root) {
    root->height = max(getHeight(root->l), getHeight(root->r)) + 1;
}
int getBF(node* root) {
    if(root == nullptr) return 0;
    int bf = getHeight(root->l) - getHeight(root->r);
    return bf;
}
node* newNode(int x) {
    node* root = new node;
    root->data = x;
    root->height = 1;
    root->l = root->r = nullptr;
    return root;
}
void insert(node*& root, int x) {
    if(root == nullptr) {
        root = newNode(x);
        return;
    }
    if(x < root->data) {
        insert(root->l, x);
        updateHeight(root);
    }else {
        insert(root->r, x);
        updateHeight(root);
    }
}
bool test(node* root) {
    if(root == nullptr) return true;
    bool flag = (getBF(root) >= -1 && getBF(root) <= 1);
    return flag && test(root->r) && test(root->l);
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        node* root = nullptr;
        int d;
        for(int i = 0; i < n; i++) {
            cin >> d;
            insert(root, d);
        }
        if(test(root)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}