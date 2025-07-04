# 算法模板默写



### BFS

```C++
struct Node{
    int u;		// 顶点编号
    int level;	// 顶点层数
    Node(int u_, int level_):u{u_}, level{level_}{}
};
vector<int> Adj[maxn];	// 邻接表
bool inq[maxn] = { false };
void BFS(int s, int level) { // s为起点，level为起点层数
    queue<Node> q;          // BFS队列
    q.push(Node{s, level}); // 起点入队
    inq[s] = true;          // 设置起点已入过队
    while(!q.empty()) {
        Node front = q.front(); // 取出队首顶点
        q.pop();
        int u = front.u;        // 队首顶点编号
        for(int i = 0; i < Adj[u].size(); i++) {    // 遍历队首顶点的子结点
            int next = Adj[u][i];   // next存放子结点编号
            if(!inq[next]) {        // 子结点未入过队，则加入队列
                q.push(Node{next, front.level + 1});   // 子结点层数为队首结点层数+1
                inq[next] = true;   // 设置已入队
            }
        }
    }
}
```
### Dijkstra+多重前驱pre数组

```C++
vector<int> pre[maxn];  //多重前驱数组

void Dijkstra(int s) {   //s为起点
    fill(d, d+maxn, INF);
    d[s] = 0;       //起点到自身的距离为0
    for(int i = 0; i < n; i++){	//n次循环，每次循环找到一个未访问点中距离起点最近的点
        int u = -1, min = INF;
        for(int j = 0; j < n; j++){ 	//找到未访问结点中最小的d[u]
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;	//找不到小于INF的d[u], 说明剩下的顶点与起点s都不连通
        vis[u] = true;		//标记u已访问
        // 更新u的所有邻接点的d(距起点s的最短路)
        for(int v = 0; v < n; v++){ //遍历所有顶点
            if(!vis[v] && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();			//清空pre[v]
                    pre[v].push_back(u);	//令v的前驱为u
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);	//最短路没有更新，不需要清空pre[v]
                }
            }
        }
    }
}
```
### DFS求最短路径条数+点权和+最大平均点权

>先比点权和
>
>点权和相等，再比平均点权

```C++
int st;             // 起点编号
int weight[maxn];   // 各点点权
int numPath = 0;    // 最短路径条数
int maxW = 0;       // 最大点权和
double maxAvr = 0;  // 最大平均点权
vector<int> tempPath, path; // 临时路径、最优路径
void DFS(int v) {   // v为当前访问结点
    // 递归边界
    if(v == st) {   // 递归到起点时，tempPath得到整条路径
        tempPath.push_back(v);  // tempPath最后一个点为起点

        // 开始计算各种最优
        numPath++;  // 遍历到起点时得到一条最短路径，此时录条数
        int tempW = 0;  // 临时点权和
        for(int i = tempPath.size() - 1; i >= 0; i--) { // 由起点(tempPath.size() - 1)开始计算点权和
            int id = tempPath[i];   // 当前结点的编号(注意不是i)
            tempW += weight[id];    // 累加点权
        }
        // 此时点权和tempW已经算好

        double tempAvr = 1.0 * tempW / tempPath.size();   // 临时平均点权 = 临时点权和/当前路径结点数
        if(tempW > maxW) {  	// 找到更优点权和
            maxW = tempW;       // 优化maxW
            maxAvr = tempAvr;   // 覆盖maxAvr
            path = tempPath;    // 覆盖最优路径path
        }else if(tempW == maxW && tempAvr > maxAvr) {   // 点权和相等再比平均点权
            maxAvr = tempAvr;   // 优化maxAvr
            path = tempPath;    // 覆盖最优路径
        }

        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {    // 递归遍历当前结点的所有前驱
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
```



### Prim算法

```C++
```

#### prim 与 Dijkstra 比较：

+ prim算法每次循环找到与当前最小生成树距离最近的点；而Dijkstra每次循环找到与起点距离最近的点

### 并查集

+ ==获得根结点用`findFather(i)`！！,不要用`father[i]`！==

```C++
#define N 1010
int father[N];  // father[i] 表示i所在集合的根结点

/* 初始化，每个元素都是独立的集合，根节点为自身 */
void init() {
    for(int i = 1; i <= N; i++)  {
        father[i] = i;
    }
}
int findFather(x) {
    // 由于第一次循环会把x变为根结点，因此此处保存原来的x
    int a = x;
    // 第一次循环，找到根结点
    while(x != father[x]) { //根结点的father为自身
        x = father[x];
    }
    // 此时x为根结点
    //第二次循环，路径压缩，将原来的x到根结点路径上所有结点的father置为根结点
    while(a != father[a]) {
        int b = a;      // 保存还未被修改的结点
        a = father[a];  // 回溯a父结点
        father[b] = x;  // 修改为根结点
    }
    return x;   // 返回根结点
}

/* 合并两个集合 */
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){ //不属于同一集合
        father[faA] = faB;  //合并根结点
    }
}

/* 统计共有多少集合以及每个集合的人数 */
int isRoot[N] = {0};      // 记录每个根结点所在集合的人数

for(int i = 1; i <= N; i++) {
        isRoot[findFather(i)]++;        // i的根结点是parent[i], 将根结点所在集合个数+1
}

int size = 0;   // 集合个数
for(int i = 1; i <= N; i++) {
    if(isRoot[i] != 0) size++;  // 统计个数不为0的集合
}
```



### BST（二叉链表）

##### 存储结构

```C++
struct node{
    int data;   
    node* lchild;
    node* rchild;
};

node* newNode(int v){	// 新建结点
    node* Node = new node;
    Node->data = v;
    Node->lchild = nullptr;
    Node->rchild = nullptr;   
    return Node;
}
```

##### 查找

```C++
void search(node* root, int x) {    // 在树中查找值为x的结点，输出x
    if(root == nullptr) return;     // 空树，查找失败
    if(root->data == x) cout << x;  // 找到，访问
    else if(x < root->data) search(root->lchild, x);    // x比根结点数据域小，往左找
    else search(root->rchild, x);   // 否则往右找
}
```

##### 插入

```C++
void insert(node* &root, int x) {   // 注意root要加引用
    if(root == nullptr) {   // 空树，即插入位置
        root = newNode(x);
        return;
    }
    if(root->data == x) return; // 结点已存在，返回
    else if(x < root->data) insert(root->lchild, x);    // x比根结点数据域小，往左找
    else insert(root->rchild, x);   // 否则往右找
    
}
```

##### 建树

```C++
int a[maxn];
node* Create(int a[], int n) {   // n为要插入的结点个数
    node* root = nullptr;   // 新建结点root
    for(int i = 0; i < n; i++) {    //一个一个插入
        insert(root, a[i]);
    }
    return root;
}
```

##### 遍历（先序）

```C++
void preOrder(node* root) {
    if(root == nullptr) return; // 递归边界
    cout << root->data;
    preOrder(root->lchild);
    preOrder(root->rchild);
}
```



### 树（静态+多子）

##### 存储结构

```C++
struct Node{
    int data;
    int layer;  // 层号
    vector<int> children;
}node[maxn];
```

##### 先序遍历

```C++
void preOrder(int root) {
    cout << node[root].data;    // 访问当前结点
    for(int i = 0; i < node[root].children.size(); i++) {
        preOrder(node[root].children[i]);   // 递归访问root的所有子结点
    }
}
```

##### 层序遍历

```C++
void layerOrder(int root) {
    queue<int> q;
    q.push(root);   // 根结点下标入队
    node[root].layer = 0;   // 根结点层号为0
    while(!q.empty()) {
        int front = q.front();  // 取队首结点下标
        cout << node[front].data;
        q.pop();
        for(int i = 0; i < node[front].children.size(); i++) {
            int child = node[front].children[i];
            node[child].layer = node[front].layer + 1;
            q.push(child);
        }
    }
}
```



### 堆

```C++
int n;	// 最大堆元素个数
int heap[maxn];     // 最大堆，下标[1, n]

void downAdjust(int low, int high) {	
    int i = low, j = i*2;   // i为欲调整结点，j为其左孩子
    while(j <= high) {   // 左子树存在，就一直往下循环
        // 找到左右子树中较大结点的下标, 存放在j中
        if(j + 1 <= high && heap[j + 1] > heap[j]) { // 右子树存在&&右孩子>左孩子
            j = j + 1;
        }
        if(heap[j] > heap[i]) { // 子树较大结点比父结点大，交换
            swap(heap[j], heap[i]);
            i = j;      // 保持i为原来欲调整结点的下标
            j = i * 2;  // 左子树
        }else {     // 父结点比子结点大，不交换，并退出循环
            break;
        }
    }
}

void upAdjust(int low, int high) {
    int i = high, j = i/2;  // i为欲调整的结点，j为其父结点
    while(j >= low) {   // 父结点在规定范围内
        if(heap[j] < heap[i]) { // 父结点<子结点，交换
            swap(heap[j], heap[i]);
            i = j;      // 保持i为原来欲调整的结点
            j = i / 2;  // 父结点
        }else {
            break;
        }
    }
}

void createHeap() {		// 建堆
    for(int i = n/2; i >= 1; i--) { // 从第一个非叶子结点倒着向下调整
        downAdjust(i, n);
    }
}

void deleteTop() {      // 删除堆顶元素
    heap[1] = heap[n--];    // 最后一个元素覆盖堆顶，元素数量-1
    downAdjust(1, n);       // 并从堆顶向下调整
}

void insert(int x) {    // 向最大堆添加元素
    heap[++n] = x;      // 元素数量+1，在最后添加x
    upAdjust(1, n);     // 并从x处向上调整
}

void heapSort() {       // 堆排序（递增），排序结果存入原来堆数组
    createHeap();       // 建堆
    for(int i = n; i > 1; i--) {   	// 将堆顶调至最后-> 向下调整，重复操作，直到堆中只有一个元素
        swap(heap[1], heap[i]);		// 交换heap[i]与堆顶
        downAdjust(1, i-1);
    }
}
```



###归并排序

+ O(nlogn)
+ 分治的复杂度：O(logn)
+ 序列合并的复杂度：O(n)
+ **本质：将排序的任务转换为两个有序区间合并（从个数为1开始）。区间合并利用two-pointers思想，复杂度为O(n)**

```C++
// 将数组a的[L1, R1]和[L2, R2]区间合并为有序区间（此处L2 = R1 + 1）
void merge(int a[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2;
    int tmp[maxn], index = 0;   // tmp数组存放合并后的序列
    while(i <= R1 && j <= L2) {
        if(a[i] <= a[j]) {
            tmp[index++] = a[i++];
        }else tmp[index++] = a[j++];
    }
    while(i <= R1) tmp[index++] = a[i++];
    while(j <= R2) tmp[index++] = a[j++];
    for(int i = 0; i < index; i++) a[L1 + i] = tmp[i];  // 将合并后的序列赋值给a
}

void mergeSort(int a[]) {	// 归并排序
    // step为组内元素个数，step/2为左子区间元素个数，等号可以不取
    for(int step = 2; step/2 <= n; step *= 2) {
        // 每step个元素一组，组内前step/2和后step/2个元组进行合并
        for(int i = 1; i <= n; i += step) {     // 对每一组
            // sort(a + i, a + min(i+step, n+1));  // O(nlogn)
            int mid = i + step/2 - 1;   // 左子区间[i, mid]有严格step/2个元素
            if(mid + 1 <= n) {  // 此条件成立区间[mid+1, n]必有1个元素以上，即右子区间存在
                merge(a, i, mid, mid+1, min(mid + step/2, n));  // O(n)
            } 
        }
        // 此处可以输出归并排序某一趟结束后的序列
    }
}
```



### 快速排序

##### 步骤：

1. 设k(==主元==)为a[0]，**将k挪动到适当位置，使得比k小的元素都在k左边，比k大的元素在k右边**。***这一步复杂度为O(n)***
2. 递归k左边的部分
3. 递归k右边的部分

```C++
void quickSort(int a[], int st, int ed) {   // 对数组a的区间[st, ed]快排
    if(st >= ed) return;    // 递归边界
    int k = a[st];  // 选主元（若主元是随机选取则需要将主元与a[st]交换位置）
    // 移动主元至适当位置
    int i = st, j = ed; //two-pointers	O(n)
    while(i != j) {     // i与j相遇时退出
        while(j > i && a[j] >= k) j--;   // 右边大，j左移
        swap(a[i], a[j]);
        while(i < j && a[i] <= k) i++;  // 左边小，i右移
        swap(a[i], a[j]);
    }//处理完后，a[i] = a[j] = k	
    quickSort(a, st, i-1);  // 递归k的左边
    quickSort(a, i+1, ed);  // 递归k的右边
}
```



### 二分查找

```C++
//在递增序列a的[left，right]区间进行二分，找x返回下标，找不到返回-1
int binarySearch(int a[], int left, int right, int x) {
    while(left <= right) {      // 条件不成立说明找不到
        int mid = left + (right-left)/2;    // 取中点
        if(a[mid] == x) return mid;       // 找到，返回下标
        else if(a[mid] > x) right = mid-1;  // 中点值在要找的数右边，往左[left, mid-1]找
        else left = mid + 1;    // 往右[mid+1, right]找
    }
    return -1;
}


int lowerBound(vector<int>& a, int k) { // 大于等于k的最小下标
    int l = 0, r = a.size() - 1;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(a[mid] >= k) r = mid;    // 中点大于等于k，可能就是此处，往左找
        else l = mid + 1;
    }
    return l;   // l==r说明找到
}

int upperBound(vector<int>& a, int k) { // 大于k的最小下标
    int l = 0, r = a.size() - 1;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(a[mid] <= k) l = mid + 1;    // 中点小于等于k，往右找
        else r = mid;   // 中点大于k，可能就是此处
    }
    return l;
}
```



### 插入排序

```C++
void insertSort(vector<int>& a, int n) {   // 插入排序，下标1~n;
    for(int i = 2; i <= n; i++) {   // a[i]是当前准备插入的元素
        int j = i;  // j从i往前遍历，找到插入位置
        int temp = a[i];    // 临时存放准备插入的元素
        while(j > 1 && a[j-1] > temp) {	// 只要前面元素大
            a[j] = a[j-1];		// 就把前面元素后移
            j--;		// j枚举到1时结束
        }
        a[j] = temp;    // 插入
    }
}
```





### 素数表(在线打表) + 质因子分解

```C++
const int maxn = 100020;
ll n;
map<int, int> hashTable;	// (质因子，个数)

bool isprime(int x) {	// 判断素数
    if(x < 2) return false;
    int sqr = sqrt(1.0 * x);
    for(int i = 2; i <= sqr; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

const int maxn = 1e7+1000;
vector<int> prime;  // 存放所有素数
bool isprime[maxn];   // isprime[i] == true表示i是素数
void findPrime() {
    memset(isprime, 1, sizeof(isprime));	// 初始化全为素数
    for(int i = 2; i < maxn; i++) {
        if(isprime[i]) { // i是素数
            prime.push_back(i);
            for(int j = i + i; j < maxn; j += i) {  // 筛去i所有倍数
                isprime[j] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    init();
    if(n == 1) cout << "1=1" << endl;   // n==1特判
    else {
        cout << n << "=";
        int sqr = sqrt(1.0 * n);
        for(int i = 0; i < maxn && prime[i] < sqr; i++) {   // 枚举根号n以内的因子
            while(n % prime[i] == 0) {      // prime[i]是n的质因子
                hashTable[prime[i]]++;      // 该质因子次数+1
                n /= prime[i];		// 只要prime[i]还是n的因子, 就一直除, 直到不是因子为止
            }
        }
        if(n != 1) hashTable[n]++;      // 分解到最后剩下的一定是质因子

        // 输出
        int i = 0;
        for(map<int, int>::iterator it = hashTable.begin(); it != hashTable.end(); it++, i++) {
            if(i > 0) cout << "*";
            cout << it->first;
            if(it->second > 1) cout << "^" << it->second;
        }
    }
    return 0;
}
```

+ 输出样例：

  `97532468=2^2*11*17*101*1291`



### AVL树

```C++
struct node {
    int data;   // 结点权值
    int height; // 当前子树高度
    node* lchild, * rchild;
};
node* newNode(int x) {   // 新建权值为x的结点
    node* root = new node;
    root->data = x;
    root->height = 1;   // 单个结点的高度为1
    root->lchild = root->rchild = nullptr;
    return root;
}
int getHeight(node* root) { // 计算当前子树高度
    if(root == nullptr) return 0;   // 空子树高度为0
    else return root->height;
}
int getBF(node* root) {     // 计算平衡因子
    return getHeight(root->lchild) - getHeight(root->rchild);   // 左子树高-右子树高
}
void updateHeight(node* root) { // 更新当前子树高度
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;   // 左右子树高度较大值+1
}

void search(node* root, int x) {   // AVL的搜索（与BST完全相同）
    if(root == nullptr) return;
    if(root->data == x) cout << x << endl;
    else if(x < root->data) search(root->lchild, x);
    else search(root->rchild, x);
}
void L(node*& root) {    // 左旋
    node* tmp = root->rchild;   // 保存最终的根结点，后面紧接着修改
    root->rchild = tmp->lchild; 
    tmp->lchild = root;         
    updateHeight(root);         // 修改根结点之前要更新高度
    updateHeight(tmp);
    root = tmp;
}
void R(node*& root) {    // 右旋（与左旋操作完全对应），只要把l改r
    node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void insert(node*& root, int x) {    // AVL的插入
    if(root == nullptr) {
        root = newNode(x);
        return;
    }
    if(x < root->data) {    // 欲插结点比当前结点小，往左插
        insert(root->lchild, x);
        updateHeight(root);     // 更新树高
        if(getBF(root) == 2) {  // 若插入后当前子树不平衡
            if(getBF(root->lchild) == 1) {  // LL型
                R(root);
            }else if(getBF(root->lchild) == -1) {   // LR型
                L(root->lchild);
                R(root);
            }
        }
    }else { // 欲插结点比当前结点大，往右插
        insert(root->rchild, x);
        updateHeight(root);
        if(getBF(root) == -2) { // 插入后当前子树不平衡
            if(getBF(root->rchild) == -1) { // RR型
                L(root);
            }else if(getBF(root->rchild) == 1) {    // RL型
                R(root->rchild);
                L(root);
            }
        }
    }
}
node* Create(int data[], int n) {   // 建AVL, 返回根结点
    node* root = nullptr;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}
```



### 前序+后序建树(并判断唯一性)

```C++
struct node {
    int data;
    node* l;
    node* r;
};
int pre[maxn], post[maxn];
bool isUnique = true;
node* create(int preL, int preR, int postL, int postR) {
    if(preL > preR) return nullptr; // 递归边界
    node* root = new node;
    root->data = pre[preL]; // 根结点
    // 在后序序列中找到先序序列的第二个结点，即为左子树的根结点, 下标为k。
    int k = postL, numLeft = 0;
    for(; k < postR; k++) {
        numLeft++;  // preL == preR时numLeft用k-postL+1会出错，因此要在循环中记录结点个数
        if(post[k] == pre[preL + 1]) break;
    }

    if(k == postR-1) isUnique = false;  // 先序第二个结点等于后序倒数第二个，即只有一棵子树，说明不唯一
    
    root->l = create(preL+1, preL + numLeft, postL, k);   // 当有一边子树不存在时，默认为左子树
    root->r = create(preL + numLeft + 1, preR, k+1, postR-1);
    return root;
}
```

