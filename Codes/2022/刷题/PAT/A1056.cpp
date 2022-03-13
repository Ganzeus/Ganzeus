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
const int N = 1e5;

struct Mouse {
    int w;
    int rank;
}mouse[N];
queue<int> q;
int main(){
    int np,ng;
    cin>>np>>ng;
    for(int i=0; i<np; i++) cin>>mouse[i].w;
    int order;
    for(int i=0; i<np; i++){
        cin>>order;
        q.push(order);  //按题目输入顺序入队
    }
    int group;
    int num = np;   //每次比较的总人数
    while(q.size()!=1){
        if(num%ng==0) group = num/ng;
        else group = num/ng+1;
        for(int i=0; i<group; i++){
            int k = q.front();  //存放最大值
            for(int j=0; j<ng; j++){    //每组一个一个比
                if(i*ng+j>=num) break;  //超过该轮比赛的总人数，停止比较，进行下一轮
                int front = q.front();
                if(mouse[front].w>mouse[k].w)
                    k = front;
                mouse[front].rank = group+1;    //该轮比较的老鼠全部修改排名
                q.pop();    //比完即出队
            }
            q.push(k);      //胜利老鼠放队尾
        }
        num = group;        //更新下一轮比较的总人数
    }
    mouse[q.front()].rank = 1;  //最后胜者排名1
    for(int i=0;i<np-1;i++){
        cout<<mouse[i].rank<<" ";
    }
    cout<<mouse[np-1].rank<<endl;
    return 0;
}