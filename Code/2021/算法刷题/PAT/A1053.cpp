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
struct Node {
    int weight;
    vector<int> children;
};
Node node[maxn];
int n;  // 顶点数
int m;  // 非叶子结点数
int s;  // 题目所给路径结点和
vector<vector<int> > ans;   // 答案序列
vector<int> tempPath;   
void DFS(int v) {   // v为当前访问结点
    if(node[v].children.size() == 0) {    // 递归边界：v为叶子结点
        tempPath.push_back(node[v].weight);   // tempPath中存放的是结点权值
        int tempsum = 0;
        for(int i = 0; i < tempPath.size(); i++) {  // 计算路径上点权和
            tempsum += tempPath[i];
        }
        if(tempsum == s) ans.push_back(tempPath);   // 路径上点权和符合题意，加入ans数组
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(node[v].weight);
    for(int i = 0; i < node[v].children.size(); i++) {
        DFS(node[v].children[i]);
    }
    tempPath.pop_back();
}
bool cmp(int a, int b) {
    return node[a].weight > node[b].weight;
}
int main() {
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++) cin >> node[i].weight;
    for(int i = 0; i < m; i++) {
        string father;
        int num;
        cin >> father >> num;
        int fa = 10*(father[0]-'0') + father[1]-'0';
        while(num--) {
            string ch;
            cin >> ch;
            int child = 10*(ch[0]-'0') + ch[1]-'0';
            node[fa].children.push_back(child);
        }
    }
    DFS(0);
    sort(ans.begin(), ans.end());   // ans数组递增排序 
    for(int i = ans.size() - 1; i >= 0; i--) {  // 倒序输出
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if(j != ans[i].size()-1) cout << " ";
        }
        if(i != 0) cout << endl;
    }
    return 0;
}