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
const int maxn = 100020;
vector<string> card;
void init() {
    for(int i = 1; i <= 9; i++) {
        string s = "  ";
        s[0] = 'S';
        s[1] = i + '0';
        card[i] = s;
    }
    card[10]="S10", card[11]="S11", card[12]="S12", card[13]="S13";
    for(int i = 14; i <= 22; i++) {
        string s = "  ";
        s[0] = 'H';
        s[1] = i-13 + '0';
        card[i] = s;
    }
    card[23]="H10", card[24]="H11", card[25]="H12", card[26]="H13";
    for(int i = 27; i <= 35; i++) {
        string s = "  ";
        s[0] = 'C';
        s[1] = i-26 + '0';
        card[i] = s;
    }
    card[36]="C10", card[37]="C11", card[38]="C12", card[39]="C13";
    for(int i = 40; i <= 48; i++) {
        string s = "  ";
        s[0] = 'D';
        s[1] = i-39 + '0';
        card[i] = s;
    }
    card[49]="D10", card[50]="D11", card[51]="D12", card[52]="D13";
    card[53] = "J1", card[54] = "J2";
}
int num;
int order[55];
void shuffle(vector<string> tmp, vector<string>& ans) {
    for(int i = 1; i <= 54; i++) {
        ans[order[i]] = tmp[i];
    }
}
int main() {
    card.resize(55);
    init();
    cin >> num;
    for(int i = 1; i <= 54; i++) cin >> order[i];
    vector<string> ans;
    ans.resize(55);
    while(num--) {
        shuffle(card, ans);
        card = ans;
    }
    for(int i = 1; i < 55; i++) {
        cout << ans[i];
        if(i != 54) cout << " ";
    }
    return 0;
}