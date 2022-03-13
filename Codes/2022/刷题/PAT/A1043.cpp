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

struct Node {   //树结点
    int data;
    Node* lchild;
    Node* rchild;
};
void insert(Node* &root, int data){
    if(root == NULL){
        root = new Node;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL; 
        return; 
    }
    if(data < root->data){
        insert(root->lchild, data);
    }else if(data >= root->data){
        insert(root->rchild, data);
    }
}
void preOrder(Node* root, vector<int>& v){
    if(root == NULL) return;
    v.push_back(root->data);
    preOrder(root->lchild, v);
    preOrder(root->rchild, v);
}
void preMOrder(Node* root, vector<int>& v){
    if(root == NULL) return;
    v.push_back(root->data);
    preMOrder(root->rchild, v);
    preMOrder(root->lchild, v);
}
void postOrder(Node* root, vector<int>& v){
    if(root == NULL) return;
    postOrder(root->lchild, v);
    postOrder(root->rchild, v);
    v.push_back(root->data);
}
void postMOrder(Node* root, vector<int>& v){
    if(root == NULL) return;
    postMOrder(root->rchild, v);
    postMOrder(root->lchild, v);
    v.push_back(root->data);
}
vector<int> origin, pre, preM, post, postM; //题目序列，前序，镜像前序，后续，镜像后续
int main(){
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preMOrder(root, preM);
    postOrder(root, post);
    postMOrder(root, postM);
    // for(int i = 0; i < origin.size(); i++){
    //     printf("%d",origin[i]);
    //     if(i < origin.size()-1) printf(" ");
    // }
    if(origin == pre){  
        printf("YES\n");
        for(int i = 0; i < post.size(); i++){
            printf("%d",post[i]);
            if(i < post.size()-1) printf(" ");
        }
    }else if(origin == preM) {
        printf("YES\n");
        for(int i = 0; i < postM.size(); i++){
            printf("%d",postM[i]);
            if(i < postM.size()-1) printf(" ");
        }
    }else{
        printf("NO\n");
    }
    // cout<<"post:\n";
    // for(int i = 0; i < post.size(); i++){
    //     printf("%d",post[i]);
    //     if(i < post.size()-1) printf(" ");
    // }
    // cout<<"postM:\n";
    // for(int i = 0; i < postM.size(); i++){
    //     printf("%d",postM[i]);
    //     if(i < postM.size()-1) printf(" ");
    // }
    return 0;
}