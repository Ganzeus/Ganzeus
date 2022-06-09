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
const int maxn = 25;
struct Node {
    int lchild, rchild; 
}node[maxn];
bool Hash[maxn];    // hash[i] = true表示出现过
int n;  
bool BFS(int root, int& last, int n) {  // n为非空结点个数
    queue<int> q;
    q.push(root);
    while(n) {  // 只要n不为0，即还没有访问完全部非空结点
        int front = q.front();
        q.pop();
        if(front == -1) return false;   // 遍历到空结点，一定不是完全二叉树
        n--;    // 不是空结点，n--
        last = front;   // 每次遍历到非空结点就更新last
        q.push(node[front].lchild); // 左右结点入队（包括空结点）
        q.push(node[front].rchild);    
    }
    return true;    // 连续访问完所有非空结点，即为完全二叉树
}
int main() {
    for(int i = 0; i < maxn; i++) node[i].lchild = node[i].rchild = -1; // 子结点初始化-1
    cin >> n;
    string c1, c2;
    for(int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        if(c1 != "-"){
            node[i].lchild = stoi(c1);
            Hash[stoi(c1)] = true;
        }
        if(c2 != "-") {
            node[i].rchild = stoi(c2);
            Hash[stoi(c2)] = true;
        }
    }
    int root;
    for(int i = 0; i < n; i++) {    // 找根
        if(Hash[i] == false) {
            root = i;
            break;
        }
    }
    int last;   // 树的最后一个结点
    if(BFS(root, last, n)) cout << "YES " << last << endl;
    else cout << "NO " << root << endl;
    return 0;
}