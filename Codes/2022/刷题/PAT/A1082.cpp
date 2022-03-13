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
string str;
string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string wei[5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
    cin >> str;
    int n = str.length();
    int left = 0, right = n - 1;
    if(str[0] == '-') {
        cout << "Fu";
        left++;
    }
    while(left + 4 <= right) { // 获取最前面一节
        right -= 4;
    }

    while(left < n) {   // 一次循环处理一节
        bool flag = false;  // 是否有累积的0
        bool printed = false;   // 该小节是否已经输出过内容
        while(left <= right) {  // 从左到右处理该小节每一位
            if(left > 0 && str[left] == '0') {    // 当前位为0
                flag = true;
            }else { // 当前位不为0
                if(flag) {
                    cout << " ling";   // 有累积的0
                    flag = false;   // 累积的0已经被输出
                }
                if(left > 0) cout << " ";
                cout << digit[str[left] - '0'];
                if(left != right) { // 不是该小节的最后一位，就要输出千百十
                    cout << " " << wei[right - left - 1];
                }
                printed = true; // 该小节输出过内容
            }
            left++; // 下一位
        }
        // 该小节最后一位已经处理完，下面判断是否输出万亿
        if(right != n-1 && printed) {  // 不是最后一位并且当前小节输出过内容
            cout << " " << wei[(n-right)/4 + 2];
        }
        right += 4; // 下一小节
    }
    return 0;
}