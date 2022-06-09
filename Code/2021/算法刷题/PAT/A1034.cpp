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
const int maxn = 2005;
int n, k;
map<string, int> strTint;   //名字对应的编号
string intTstr[maxn];   //编号对应的名字
int weight[maxn] {0};   //点权
int numpeople = 0;      //总人数
int G[maxn][maxn] {0};  //邻接矩阵
bool vis[maxn] {false};
map<string, int> Gang;  //存放Gang的head与人数

int change(string str){ //姓名转编号(下标i)
    if(strTint.find(str) != strTint.end()){ //名字处理过
        return strTint[str];
    }else{
        strTint[str] = numpeople;
        intTstr[numpeople] = str;
        return numpeople++;    //返回编号，总人数+1
    }
}

void DFS(int curid, int& head, int& numOfmem, int& totallen) {
    numOfmem++; //成员数+1
    vis[curid] = true;  //标记已访问
    if(weight[curid] > weight[head]) {  //计算最大点权head
        head = curid;
    }
    for(int i = 0; i < numpeople; i++){ //遍历所有顶点，找邻接点
        if(G[curid][i] > 0) {   //curid与i有边,就把边权加上totallen
            totallen += G[curid][i];
            G[curid][i] = G[i][curid] = 0;  //加过后就将此边删除，防止重复添加边权 
            if(!vis[i]) DFS(i, head, numOfmem, totallen);    
        }
    }
}
void DFSTraverse() {
    for(int i = 0; i < numpeople; i++){ //遍历所有顶点
        if(!vis[i]){
            int head = i, numOfmem = 0, totallen = 0;
            DFS(i, head, numOfmem, totallen);   //遍历该连通分支
            if(totallen > k && numOfmem > 2) {
                Gang[intTstr[head]] = numOfmem; 
            }
        }
    }
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string str1, str2;
        int w;
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;   //更新点权
        weight[id2] += w;
        G[id1][id2] += w;   //更新边权
        G[id2][id1] += w;
    }
    //此时所有点权边权都已修改完成
    DFSTraverse();
    cout<<Gang.size()<<endl;
    if(Gang.size() != 0){
        for(map<string, int>::iterator it = Gang.begin(); it !=Gang.end(); it++){
            printf("%s %d\n", it->first.c_str(), it->second);
        }
    }
    return 0;
}