#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 40;
int n;
int in[maxn];
struct node{
    int data;
    node* l, * r;
};
node* create(int inL, int inR) {
    if(inL > inR) return nullptr;
    node* root = new node;
    int minD = INF;
    for(int i = inL; i <= inR; i++) {  // 在中序中找最小的结点
        if(in[i] < minD) minD = in[i];
    }
    int i = inL;
    for(; i <= inR; i++) if(in[i] == minD) break;
    root->data = minD;
    int numLeft = i - inL;
    root->l = create(inL, i-1);
    root->r = create(i+1, inR);
    return root;
}
vector<int> level;
void levelOrder(node* root, vector<int>& path) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* front = q.front();
        q.pop();
        path.push_back(front->data);
        if(front->l != nullptr) q.push(front->l);
        if(front->r != nullptr) q.push(front->r);
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    node* root = create(0, n-1);
    levelOrder(root, level);
    for(int i = 0; i < level.size(); i++) {
        cout << level[i];
        if(i != level.size() - 1) cout << " ";
    }
    return 0;
}