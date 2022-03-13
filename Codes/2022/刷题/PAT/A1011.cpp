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
struct Node{
    double odd;
    char type;
    Node(double odd_, char type_): odd{odd_}, type{type_} {}
};
bool cmp(Node a, Node b) {
    return a.odd > b.odd;
}
vector<Node> odds[3];
int main() {
    double w, t, l;
    for(int i = 0; i < 3; i++) {
        cin >> w >> t >> l;
        odds[i].push_back(Node{w, 'W'});
        odds[i].push_back(Node{t, 'T'});
        odds[i].push_back(Node{l, 'L'});
    }
    for(int i = 0; i < 3; i++) {
        sort(odds[i].begin(), odds[i].end(), cmp);
    }
    double sum = (odds[0][0].odd * odds[1][0].odd * odds[2][0].odd * 0.65 - 1) * 2;
    printf("%c %c %c %.2f", odds[0][0].type, odds[1][0].type, odds[2][0].type, sum);
    return 0;
}