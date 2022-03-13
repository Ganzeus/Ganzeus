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
struct Node {
    string name, gender, id;
    int grade;
};
int n;
int main() {
    Node ansF, ansM;
    ansF.id = ansM.id = "#";
    cin >> n;
    string name, gender, id;
    int grade;
    int minG = INF, maxG = -1;
    for(int i = 0; i < n; i++) {
        cin >> name >> gender >> id >> grade;
        if(gender == "M" && grade < minG) {
            ansM.name = name; ansM.gender = gender; ansM.id = id; ansM.grade = grade;
            minG = grade;
        }
        if(gender == "F" && grade > maxG) {
            ansF.name = name; ansF.gender = gender; ansF.id = id; ansF.grade = grade;
            maxG = grade;
        }
    }
    if(ansF.id == "#") {
        cout << "Absent" << endl;
    }else cout << ansF.name << " " << ansF.id << endl;
    if(ansM.id == "#") {
        cout << "Absent" << endl;
    }else cout << ansM.name << " " << ansM.id << endl;
    if(ansF.id == "#" || ansM.id == "#") cout << "NA" << endl;
    else cout << maxG-minG << endl;
    return 0;
}