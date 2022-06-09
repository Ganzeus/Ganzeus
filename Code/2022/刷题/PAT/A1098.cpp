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
const int maxn = 120;
int n;
int flag = 1;
vector<int> heap;
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while(j <= high) {
        if(j+1 <= high && heap[j+1] > heap[j]) j = j+1;
        if(heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }else break;
    }
}
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while(j >= low) {
        if(heap[j] < heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }else break;
    }
}
void insert(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}
void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}
void createHeap() {
    for(int i = n/2; i > 0; i--) {
        downAdjust(i, n);
    }
}
vector<int> ini, cur;
void heapSort() {
    createHeap();
    // bool changed = false;
    for(int i = n; i > 1; i--) {
        if(heap == cur) {
            flag = 2;
        }
        swap(heap[1], heap[i]);
        downAdjust(1, i-1);
        // changed = true;
        if(flag == 2) {
            ini = heap;
            return;
        }
    }
}

int main() {
    cin >> n;
    ini.resize(n+1);
    cur.resize(n+1);
    heap.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> ini[i];
    }
    heap = ini;
    for(int i = 1; i <= n; i++) cin >> cur[i];
    heapSort();
    if(flag == 2) {
        cout << "Heap Sort" << endl;
        for(int i = 1; i <= n; i++) {
            cout << ini[i];
            if(i != n) cout << " ";
        }
    }else {
        cout << "Insertion Sort" << endl;
        int i = 2;
        for(; i <= n; i++) {
            sort(ini.begin() + 1, ini.begin() + i + 1);
            if(ini == cur) break;
        }
        sort(ini.begin() + 1, ini.begin() + i + 2);
        for(int i = 1; i <= n; i++) {
            cout << ini[i];
            if(i != n) cout << " ";
        }
    }
    return 0;
}