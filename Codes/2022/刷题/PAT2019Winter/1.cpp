#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 100010;
char L[26][7][5];

int main() {
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 7; j++) {
            for(int k = 0; k < 5; k++) {
                cin >> L[i][j][k];
            }
        }
    }
    string str;
    getchar();
    getline(cin, str);
    int index = 0;
    vector<char> word;
    while(index < str.length()) {
        word.clear();
        while(str[index] < 'A' || str[index] > 'Z') index++;    // 找到第一个字母
        while(str[index] >= 'A' && str[index] <= 'Z') word.push_back(str[index++]); // 得到一个word
        // 输出该word
        for(int i = 0; i < 7; i++) {    // 7行
            for(int j = 0; j < word.size(); j++) {  // 每行遍历word各个字母
                int c = word[j]-'A';
                for(int k = 0; k < 5; k++) cout << L[c][i][k];
                if(j != word.size()-1) cout << " ";
            }
            cout << endl;
        }
        while(str[index] < 'A' || str[index] > 'Z') index++;    // 找到下一个字母
        if(index < str.length()) cout << endl;
    }
    return 0;
}