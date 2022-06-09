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
const int maxn = 110;
struct Node{
    int data;
    int lchild, rchild;
}node[maxn];
int n;           
vector<int> init, path;
void inOrder(int v, vector<int>& tmp) { // 下标中序
    if(v == -1) return;
    if(node[v].lchild != -1) inOrder(node[v].lchild, tmp);
    tmp.push_back(v);
    if(node[v].rchild != -1) inOrder(node[v].rchild, tmp);
}
void levelOrder(int v, vector<int>& tmp) {  // 下标层序
    queue<int> q;   // 存放下标
    q.push(v);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        tmp.push_back(front);
        if(node[front].lchild != -1) q.push(node[front].lchild);
        if(node[front].rchild != -1) q.push(node[front].rchild);
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> node[i].lchild >> node[i].rchild;
    }
    int data;
    for(int i = 0; i < n; i++) {    // 读入题目序列
        cin >> data;
        init.push_back(data);
    }
    sort(init.begin(), init.end());
    inOrder(0, path);   // 得到下标中序序列
    for(int i = 0; i < n; i++) {
        node[path[i]].data = init[i];
    }
    path.clear();   // 清空，重新存放层序
    levelOrder(0, path);    // 得到下标层序序列
    for(int i = 0; i < path.size(); i++) {
        cout << node[path[i]].data;
        if(i != path.size() - 1) cout << " ";
    }
    return 0;
}