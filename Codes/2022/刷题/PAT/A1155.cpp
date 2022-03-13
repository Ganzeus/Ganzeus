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
int n;
int heap[maxn];
vector<vector<int> > path;
void print() {
    for(int i = 0; i < path.size(); i++) {  // 对每条路径
        for(int j = 0; j < path[i].size(); j++) {
            cout << path[i][j];
            if(j != path[i].size() -1) cout << " ";
        }
        cout << endl;
    }
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
vector<int> tempPath;
void DFS(int v) {
    if(v*2 > n) {   // 没有左子树说明是叶子
        tempPath.push_back(heap[v]);
        path.push_back(tempPath);
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(heap[v]);
    if(v*2+1 <= n) DFS(v*2+1);  // 先右再左
    if(v*2 <= n) DFS(v*2);
    tempPath.pop_back();
}
int main() {
    cin >> n;
    int Max = -INF, Min = INF;
    for(int i = 1; i <= n; i++) {
        cin >> heap[i];
        if(heap[i] > Max) Max = heap[i];
        if(heap[i] < Min) Min = heap[i];
    }
    DFS(1);
    print();
    if(heap[1] == Max && testMax() == true) cout << "Max Heap" << endl;
    else if(heap[1] == Min && testMin() == true) cout << "Min Heap" << endl;
    else cout << "Not Heap" << endl;
    return 0;
}