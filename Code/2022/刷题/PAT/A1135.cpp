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
const int maxn = 40;
struct node {
    int data;
    node* l, * r;
};
int pre[maxn];
set<int> red;   // 存放红色结点
node* newNode(int x) {
    node* root = new node;
    root->data = x;
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
    } else insert(root->r, x);
}
int n, k;
bool judge1(node* root) {   // 判断是否有连续两个红
    if(root == nullptr) return true;
    if(red.find(root->data) != red.end()) { // 当前结点为红
        if(root->l != nullptr && red.find(root->l->data) != red.end()) return false;
        if(root->r != nullptr && red.find(root->r->data) != red.end()) return false;
    }
    return judge1(root->l) && judge1(root->r);  // 递归判断左右子树
}
int getBlacknum(node* root) {
    if(root == nullptr) return 0;
    int lnum = getBlacknum(root->l);
    int rnum = getBlacknum(root->r);
    if(red.find(root->data) == red.end()) return max(lnum, rnum) + 1;
    else return max(lnum, rnum);
}
bool judge2(node* root) {   // 判断所有结点的左右黑结点个数是否相等
    if(root == nullptr) return true;
    int lnum = getBlacknum(root->l);
    int rnum = getBlacknum(root->r);
    if(lnum != rnum) return false;
    return judge2(root->l) && judge2(root->r); // 递归判断左右子树
}
int main() {
    cin >> k;
    while(k--) {
        red.clear();
        cin >> n;
        int d;
        node* root = nullptr;
        for(int i = 0; i < n; i++) {
            cin >> d;
            if(d < 0) red.insert(abs(d));   // 红结点加入集合
            insert(root, abs(d));
            pre[i] = d;
        }
        if(pre[0] < 0 || judge1(root) == false || judge2(root) == false) {
            cout << "No" << endl;
        }else cout << "Yes" << endl;
    }
    return 0;
}