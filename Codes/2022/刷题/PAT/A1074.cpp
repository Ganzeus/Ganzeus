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
const int maxn = 100010;
struct Node {
    int address;
    int data;
    int next;
    int order;  // 每个结点在链表中的序号
}node[maxn];
int n, k, first;
void init() {
    for(int i = 0; i < maxn; i++) {
        node[i].next = -1;
        node[i].order = INF;
    }
}
bool cmp(Node a, Node b) {
    return a.order < b.order;
}
int main() {
    init();
    cin >> first >> n >> k;
    int addr;
    for(int i = 0; i < n; i++) {
        cin >> addr;
        node[addr].address = addr;
        cin >> node[addr].data >> node[addr].next;
    }
    int p = first, count = 0;
    while(p != -1) {
        node[p].order = count++;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    n = count;  // 有效结点个数赋给n，便于编码
    int block = n / k;  // 完整的块个数
    for(int i = 0; i < block; i++){   // 对每个块:i*k为当前块的第一个结点，(i+1)*k-1是当前块最后一个结点
        for(int j = (i+1)*k-1; j > i*k; j--) {  // 倒着输出当前块前k-1个结点
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
        }
        // 对于每块的最后一个结点（倒）
        printf("%05d %d ", node[i*k].address, node[i*k].data);
        if(i != block-1) {  // 不是最后一个完整块，输出下一块的第一个结点
            printf("%05d\n", node[(i+2)*k-1].address);  // 下下块的最后一个结点，倒过来便是下一块的第一个结点
        }else { // 对于最后一个完整块的最后一个结点
            if(n % k == 0) {    // 表示没有不完整的块
                cout << -1 << endl;
            }else{  // 有一个不完整的块，按原顺序输出
                printf("%05d\n", node[(i+1)*k].address);
                for(int j = (i+1)*k; j < n; j++) {
                    printf("%05d %d ", node[j].address, node[j].data);
                    if(j != n-1) printf("%05d\n", node[j+1].address);
                    else cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}