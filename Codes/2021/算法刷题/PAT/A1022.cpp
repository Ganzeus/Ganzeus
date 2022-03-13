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
map<string, set<int> > mapt;
map<string, set<int> > mapn;
map<string, set<int> > mapk;
map<string, set<int> > mapp;
map<string, set<int> > mapy;
void query(map<string, set<int> >& mp, string& str){
    if(mp.find(str) == mp.end()){   //找不到str
        cout << "Not Found\n";
    }else{
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
            printf("%07d\n", *it);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int id;
        string title, name, key, pub, year;
        cin>>id;
        char c1 = getchar();  //id后的回车
        getline(cin, title);    //输入title
        mapt[title].insert(id);
        getline(cin, name);     //输入作者
        mapn[name].insert(id);
        char c; //判断回车的字符
        while(cin>>key){    //输入关键字
            mapk[key].insert(id);
            c = getchar();
            if(c == '\n') break;    //如果是回车，停止读入
        }
        getline(cin, pub);  //输入publisher
        mapp[pub].insert(id);
        cin >> year;
        mapy[year].insert(id);
    }
    int m;
    cin >> m;
    while(m--){
        int num;
        string str;
        scanf("%d: ",&num);
        getline(cin, str);
        cout<<num<<": "<<str<<endl;
        if(num == 1) query(mapt, str);
        if(num == 2) query(mapn, str);
        if(num == 3) query(mapk, str);
        if(num == 4) query(mapp, str);
        if(num == 5) query(mapy, str);
    }
    return 0;
}