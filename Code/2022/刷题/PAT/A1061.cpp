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
string Day[8] = {"", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int len1 = min(s1.length(), s2.length());
    int index1 = 0;
    int d, h, m;
    for(int i = 0; i < len1; i++) {
        if(s1[i] == s2[i] && s1[i] <= 'G' && s1[i] >= 'A') {
            index1 = i;
            d = s1[i] - 'A' + 1;
            break;
        }
    }
    for(int i = index1 + 1; i < len1; i++) {
        if(s1[i] == s2[i]) {
            if(s1[i] <= '9' && s1[i] >= '0') {
                h = s1[i] - '0';
                break;
            }
            if(s1[i] <= 'N' && s1[i] >= 'A') {
                h = s1[i] - 'A' + 10;
                break;
            }
        }
    }
    int len2 = min(s3.length(), s4.length());
    for(int i = 0; i < len2; i++) {
        if(s3[i] == s4[i]) {
            if((s3[i] <= 'z' && s3[i] >= 'a') || (s3[i] <= 'Z' && s3[i] >= 'A')){
                m = i;
                break;
            }
        }
    }
    cout << Day[d] << " ";
    printf("%02d:%02d",h, m);
    return 0;
}