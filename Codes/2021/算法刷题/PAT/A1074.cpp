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
const int INF = 1e9;
const int maxn = 1e5;

struct Node {
    int addr;
    int data;
    int next;
    int order;  //元素序号
}node[maxn];

bool cmp(Node a,Node b){    //按序号排序
    return a.order<b.order;
}

int main(){
    for(int i=0; i<maxn; i++) node[i].order = INF;  //全部初始化为无效结点
    int start,n,k;
    cin>>start>>n>>k;
    int address;
    for(int i=0; i<n; i++){
        cin>>address;
        node[address].addr = address;
        cin>>node[address].data>>node[address].next;
    }
    int count = 0;
    int p = start;
    while(p!=-1){
        node[p].order = count++;    //计数有效顶点
        p = node[p].next;
    }
    n = count;
    sort(node,node+maxn,cmp);   //排完序后有效结点都排在前面
    //按题目要求输出（分块）
    for(int i=0; i<n/k; i++){
        for(int j=(i+1)*k-1; j>i*k; j--){   //完整的块倒序输出
            printf("%05d %d %05d\n",node[j].addr,node[j].data,node[j-1].addr);
        }
        //每块的最后一个结点
        printf("%05d %d ",node[i*k].addr,node[i*k].data);

        //每块最后一个结点的next处理
        if(i<n/k-1)//i不是最后一个完整块,next为下一个块最后元素的地址
            printf("%05d\n",node[(i+2)*k-1].addr);
        else{   //i是最后一块
            if(n%k==0)//恰好分成i个完整块，没有多余结点
                cout<<"-1\n";
            else{   //剩下不完整块按顺序输出
                cout<<node[(i+1)*k].addr<<endl; //剩余第一个结点的地址
                for(int i=n/k*k; i<n; i++){
                    if(i<n-1)
                        printf("%05d %d %05d\n",node[i].addr,node[i].data,node[i].next);
                    else
                        printf("%05d %d -1\n",node[i].addr,node[i].data);
                }
            }
        }
    }
    return 0;
}