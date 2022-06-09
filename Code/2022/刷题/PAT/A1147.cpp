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
const int maxn = 1020;
int n, k;
int heap[maxn];
vector<int> post;

void postOrder(int root) {
    if(root > n) return;
    postOrder(root*2);  // 左子树   
    postOrder(root*2+1);    // 右子树
    post.push_back(heap[root]);
}
void print() {
    for(int i = 0; i < post.size(); i++) {
        cout << post[i];
        if(i != post.size() - 1) cout << " ";
    }
    cout << endl;
}
bool testMax() {
    for(int i = 1; i <= n/2; i++) { // 对于每个非叶子结点
        int l = i * 2, r = i * 2 + 1;
        if((l <= n && heap[l] > heap[i]) || (r <= n && heap[r] > heap[i])) {    // 叶子结点比根结点大，不是大顶堆
            return false;
        }
    }
    return true;
}
bool testMin() {
    for(int i = 1; i <= n/2; i++) {
        int l = i * 2, r = i * 2 + 1;
        if((l <= n && heap[l] < heap[i]) || (r <= n && heap[r] < heap[i])) {
            return false;
        }
    }
    return true;
}
int main() {
    for(int i = 1; i < maxn; i++) heap[i] = INF;
    cin >> k >> n;
    while(k--) {
        post.clear();
        int Max = -INF, Min = INF;
        for(int i = 1; i <= n; i++) {
            cin >> heap[i];
            if(heap[i] > Max) Max = heap[i];
            if(heap[i] < Min) Min = heap[i];
        }
        bool flag = true;
        if(heap[1] == Max) {    // 判断是否是大顶堆
            if(testMax()) {
                cout << "Max Heap" << endl;
            }else cout << "Not Heap" << endl;
            postOrder(1);
            print();
        }else if(heap[1] == Min) {  // 判断是否是小顶堆
            if(testMin()) {
                cout << "Min Heap" << endl;
            }else cout << "Not Heap" << endl;
            postOrder(1);
            print();
        }else {     // 不是堆，直接后序
            cout << "Not Heap" << endl;
            postOrder(1);
            print();
        }
    }
    return 0;
}