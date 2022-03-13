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
const int maxn = 110;
struct Node{
    int id;
    int virtue, talent;
    Node(int id_, int virtue_, int talent_) : id(id_), virtue(virtue_), talent(talent_) {}
};
vector<Node> nodes;
vector<Node> sages;
vector<Node> nobles;
vector<Node> fools;
vector<Node> smalls;
bool cmp(Node a, Node b) {
    int totala = a.virtue + a.talent;
    int totalb = b.virtue + b.talent;
    if(totala > totalb) return true;
    else if(totala == totalb) {
        if(a.virtue > b.virtue) return true;
        else if(a.virtue == b.virtue) return a.id < b.id;
    }
    return false;
}
void print(vector<Node> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].id << " " << v[i].virtue << " " << v[i].talent << endl;
    }
}
int n, l, h;
int main() {
    cin >> n >> l >> h;
    int num = 0;
    for(int i = 0; i < n; i++) {
        int id, v, t;
        cin >> id >> v >> t;
        if(v >= l && t >= l) {
            num++;
            Node node{id, v, t};
            if(v >= h && t >= h) sages.push_back(node);
            else if(t < h && v >= h) nobles.push_back(node);
            else if(v < h && t < h && v >= t) fools.push_back(node);
            else smalls.push_back(node);
        }
    }
    sort(sages.begin(), sages.end(), cmp);
    sort(nobles.begin(), nobles.end(), cmp);
    sort(fools.begin(), fools.end(), cmp);
    sort(smalls.begin(), smalls.end(), cmp);
    
    cout << num << endl;
    print(sages);
    print(nobles);
    print(fools);
    print(smalls);
    return 0;
}