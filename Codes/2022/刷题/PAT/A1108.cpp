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
#define INF 0x3fffffff
const int maxn = 2010;
int n;
int main() {
    cin >> n;
    int cnt = 0;
    double ans = 0.0;
    char a[50], b[50];
    double tmp; 
    while(n--) {
        scanf("%s", a);     // 读入字符串，存入字符数组a
        sscanf(a, "%lf", &tmp);  // 将a以double格式存入tmp，若格式不匹配则不修改tmp
        sprintf(b, "%.2f", tmp);  // 将tmp以2位小数格式存入字符数组b
        bool flag = true;
        for(int i = 0; i < strlen(a); i++){
            if(a[i] != b[i]) flag = false;  // 如果a和b不严格相等，说明a小数点后位数超过2个
        }
        if(!flag || tmp < -1000 || tmp > 1000) {    // 不符合要求的浮点数
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }else{
            cnt++;
            ans += tmp;
        }
    }
    if(cnt == 0) cout << "The average of 0 numbers is Undefined" << endl;
    else if(cnt == 1) printf("The average of 1 number is %.2f\n", ans);
    else printf("The average of %d numbers is %.2f\n", cnt, ans/cnt);
    return 0;
}