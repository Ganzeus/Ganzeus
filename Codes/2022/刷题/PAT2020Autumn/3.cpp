#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 30;
struct node{
    int data;
    node* l, * r;
};
int pre[maxn], in[maxn];
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
    root->r = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}
vector<int> ans;
void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) { // 每次循环遍历一层结点，队列的第一个结点即为当前层最左边的结点
        int size = q.size();
        ans.push_back(q.front()->data);
        for(int i = 0; i < size; i++) { // 遍历当前层所有结点
            node* front = q.front();
            q.pop();
            if(front->l != nullptr) q.push(front->l);
            if(front->r != nullptr) q.push(front->r);
        }

    }
}
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> pre[i];
    node* root =create(0, n-1, 0, n-1);
    BFS(root);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    return 0;
}