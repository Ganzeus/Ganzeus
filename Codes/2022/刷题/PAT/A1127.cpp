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
vector<int> post, in;
node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) return nullptr;
    node* root = new node;
    root->data = post[postR];
    int k = inL;
    for(; k <= inR; k++) {
        if(in[k] == post[postR]) break;
    }
    int numLeft = k - inL;
    root->l = create(postL, postL + numLeft - 1, inL, k-1);
    root->r = create(postL + numLeft, postR - 1, k+1, inR);
    return root;
}
map<int, vector<int> > mp;  // 层数，序列
int maxDepth = 0;
void DFS(node* root, int depth) {
    if(depth > maxDepth) maxDepth = depth;
    mp[depth].push_back(root->data);
    if(root->l != nullptr) DFS(root->l, depth+1);
    if(root->r != nullptr) DFS(root->r, depth+1);
}
int n;
int main() {
    cin >> n;
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    node* root = create(0, n-1, 0, n-1);
    DFS(root, 0);
    for(int i = 0; i <= maxDepth; i++) { // 输出每层的序列
        if(i % 2 == 0)  {   // 偶数层颠倒
            for(int j = mp[i].size() - 1; j >= 0; j--){
                cout << mp[i][j];
                if(!(i == maxDepth && j == 0)) cout << " "; // 只要不是最后一层的最后一个结点
            }
        }else {
            for(int j = 0; j < mp[i].size(); j++) {
                cout << mp[i][j];
                if(!(i == maxDepth && j == mp[i].size() - 1)) cout << " "; // 只要不是最后一层的最后一个结点
            }
        }
    }
    return 0;
}