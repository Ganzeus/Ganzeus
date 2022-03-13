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
    bool flag;
}node[maxn];

bool cmp(Node a,Node b){
    if(a.flag == false || b.flag == false) return a.flag>b.flag;  //a和b中有无效结点，就把它放到后面
    else return a.data<b.data;  //都是有效结点，按要求排序(数据域升序)
}
int main(){
    for(int i=0; i<maxn; i++) node[i].flag == false;    //初始化，认为全是无效结点
    int n,head;
    cin>>n>>head;
    int address;
    for(int i=0; i<n; i++){
        cin>>address;
        cin>>node[address].data>>node[address].next;
        node[address].addr = address;  
    }
    int count = 0,p=head;
    while(p!=-1){       //对有效结点进行标记
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if(count==0) printf("0 -1\n"); //特判，链表无有效结点
    else{
        sort(node,node+maxn,cmp);
        printf("%d %05d\n",count,node[0].addr);
        for(int i=0;i<count;i++)  {
            if(i!=count-1) printf("%05d %d %05d\n",node[i].addr,node[i].data,node[i+1].addr);
            else printf("%05d %d -1\n",node[i].addr,node[i].data);    //最后一个结点
        }
    }
    return 0;
}