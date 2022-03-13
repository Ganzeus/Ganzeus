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

struct Node{
    int data,next,address;
    int order;
}node[maxn];
bool cmp(Node a,Node b){
    return a.order<b.order;
}
bool exist[10010]={false};
int main(){
    for(int i=0; i<maxn; i++) node[i].order = maxn+maxn;    //初始化为无效结点
    int begin,n;
    cin>>begin>>n;
    int addr;
    for(int i=0; i<n; i++){
        cin>>addr;
        node[addr].address = addr;
        cin>>node[addr].data>>node[addr].next;
    }
    int p = begin,countValid = 0,countDelete = 0;
    while(p!=-1){
        if(exist[abs(node[p].data)]==false){    //绝对值没出现过
            exist[abs(node[p].data)]=true;
            node[p].order = countValid++;
        }else if(exist[abs(node[p].data)]==true){  //绝对值出现过
            node[p].order = maxn+countDelete++;
        }
        p = node[p].next;
    }
    sort(node,node+maxn,cmp);   //静态链表元素为：有效链表、被删链表、无效链表
    n = countValid+countDelete;
    //输出
    for(int i=0; i<n; i++){
        if(i!=countValid-1&&i!=n-1)
        printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        else printf("%05d %d -1\n",node[i].address,node[i].data);
    }
    return 0;
}