#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;
const int M = 26*26*26*10+1;  
vector<int> selectcourse[M];  //每个元素都是所选课程号的vector数组

int getID(char name[]){
    int id = 0;
    for(int i = 0; i < 3; i++){
        id = id*26 + (name[i]-'A');
    }
    id = id*10 + (name[3]-'0');
    return id;
}
int main(){
    int n,k;
    scanf("%d %d", &n, &k);  //n个学生，k门课
    int cno,cnum;
    while(k--){ //k次循环，输入选课信息
        scanf("%d %d",&cno,&cnum);    //输入课程号，选课人数
        while(cnum--){
            char name[5];
            scanf("%s",name);//输入一个学生名
            int id = getID(name);//得到哈希后的id
            selectcourse[id].push_back(cno);//课程号加入选课列表
        }
    }

    for(int i = 0; i < n; i++){
        char qname[5];
        // cin>>qname;
        scanf("%s",qname);
        int id = getID(qname);
        sort(selectcourse[id].begin(),selectcourse[id].end());
        int size = selectcourse[id].size();
        printf("%s %d",qname,size);
        for(int j = 0; j < size; j++){
            printf(" %d",selectcourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}
