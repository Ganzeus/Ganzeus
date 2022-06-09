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
const int maxn = 10020;
int n, m;
struct Node {
    string id;
    char level;
    int site;
    int date;
    int num;
    int score;
}node[maxn];
bool cmp(Node a, Node b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}
struct SiteNum{
    int site;
    int num;
};
bool cmp2(SiteNum a, SiteNum b) {
    if(a.num != b.num) return a.num > b.num;
    else return a.site < b.site;
}
int main() {
    cin >> n >> m;
    string str;
    int d;
    for(int i = 0; i < n; i++) {
        cin >> str >> d;
        node[i].id = str, node[i].score = d;
        node[i].level = str[0];
        node[i].site = stoi(str.substr(1, 3));
        node[i].date = stoi(str.substr(4, 6));
        node[i].num = stoi(str.substr(10, 3));
    }
    sort(node, node + n, cmp);
    int type;
    string term;
    for(int j = 1; j <= m; j++) {
        cin >> type >> term;
        int cnt = 0;    // 记录输出个数
        if(type == 1) {
            cout << "Case " << j << ": " << type << " " << term << endl;
            for(int i = 0; i < n; i++) {    
                if(node[i].level == term[0]) {
                    cout << node[i].id << " " << node[i].score << endl;
                    cnt++;
                }
            }

        }
        if(type == 2) {
            cout << "Case " << j << ": " << type << " " << term << endl;
            int site = stoi(term);
            int totalc = 0, totals = 0;
            bool flag = false;
            for(int i = 0; i < n; i++) {
                if(node[i].site == site) {
                    flag = true;    
                    totalc++;
                    totals += node[i].score;
                }
            }
            if(flag){ 
                cout << totalc << " " << totals << endl;
                cnt++;
            }
        }
        if(type == 3) {
            cout << "Case " << j << ": " << type << " " << term << endl;
            int Date = stoi(term);
            int mp[1000] = {0};
            SiteNum ans[1000];
            int index = 0;
            for(int i = 0; i < n; i++) {
                if(node[i].date == Date) {
                    mp[node[i].site]++;
                }
            }
            for(int i = 0; i < 1000; i++) {
                if(mp[i] != 0) {
                    ans[index].site = i;
                    ans[index].num = mp[i];
                    index++;
                }
            }
            sort(ans, ans + index, cmp2);
            for(int i = 0; i < index; i++) {
                cout << ans[i].site << " " << ans[i].num << endl;
                cnt++;
            }
        }
        if(cnt == 0) cout << "NA" << endl;
    }
    return 0;
}