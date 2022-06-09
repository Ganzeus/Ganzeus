#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;
#define ll long long
#define maxn 35
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int in[maxn],post[maxn];
/*给定后序序列[postL,postR]和中序序列[inL,inR],建立二叉树，返回根结点地址*/
node* create(int postL,int postR,int inL,int inR){
    if(postL>postR) return NULL;    //递归边界

    node* root = new node;
    root->data = post[postR];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==post[postR])      //在中序序列中找in[k]==post[postR](根)的结点
            break;
    }
    int numLeft=k-inL;
    //左子树后序区间[postL,postL+numLeft-1],中序[inL,k-1]
    root->lchild = create(postL,postL+numLeft-1,inL,k-1); 
    //右子树后序区间[postL+numLeft,postR-1],中序[k,inR]   
    root->rchild = create(postL+numLeft,postR-1,k+1,inR);
    return root;
}

void BFS(node* root,int n){
    int num = 0;
    queue <node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        cout<<now->data;
        num++;
        if(num<n) cout<<" ";
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>post[i];
    for(int i=0;i<n;i++) cin>>in[i];
    node* root = create(0,n-1,0,n-1);
    BFS(root,n);
    return 0;
}