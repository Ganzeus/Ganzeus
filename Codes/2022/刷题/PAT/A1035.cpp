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
const int maxn = 1010;
struct Node {
    string account;
    string password;
    Node(string acnt, string pswd): account{acnt}, password{pswd}{}
};
vector<Node> v;
int n;
int main() {
    cin >> n;
    string acnt, pswd;
    for(int i = 0; i < n; i++) {
        cin >> acnt >> pswd;
        v.push_back(Node{acnt, pswd});
    }
    vector<Node> ans;
    for(int i = 0; i < v.size(); i++) {
        string str = v[i].password;
        int j = 0;
        bool flag = false;  // 未作修改
        for(; j < str.length(); j++) {   // 遍历password
            if(str[j] == '1') {str[j] = '@'; flag = true;}
            else if(str[j] == 'l') {str[j] = 'L'; flag = true;}
            else if(str[j] == '0') {str[j] = '%'; flag = true;}
            else if(str[j] == 'O') {str[j] = 'o'; flag = true;}
        }
        if(flag) { //做出了修改
            ans.push_back(Node{v[i].account, str});
        }
    }
    if(ans.size() == 0) {
        if(n == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", n);
    }else{
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].account << " " << ans[i].password << endl;
        }
    }
    return 0;
}