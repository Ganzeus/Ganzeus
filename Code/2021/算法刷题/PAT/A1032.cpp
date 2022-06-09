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
    char c;
    int next;
    int flag;
}node[maxn];
int main(){
    int head1,head2;
    int n;
    cin>>head1>>head2>>n;
    int add;
    for(int i=0;i<n;i++){
        cin>>add;
        cin>>node[add].c>>node[add].next;
    }
    for(int i=0;i<maxn;i++){
        node[i].flag=0;
    }
    int p1=head1;
    while(p1!=-1){      //遍历链表1，将经过的结点flag置1
        node[p1].flag=1;
        p1=node[p1].next;
    }
    int p2=head2;
    while(p2!=-1){      //遍历链表2，找到第一个flag为1的结点即为答案
        if(node[p2].flag==1){
            break;
        }
        p2 = node[p2].next;
    }
    if(p2==-1) cout<<-1<<endl;
    else printf("%05d\n",p2);
    return 0;
}