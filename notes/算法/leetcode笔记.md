## 实用API

### 输入输出

#### python

```python
# 1. input()读取一整行（字符串）
s = input()

# 2. 一行用分隔符拆分的多个字符串（默认用空格拆分）
a, b = input().split()  # 输入: hello world
						 # a = "hello", b = "world"
a, b = input().split(",")	# 输入: hello,world
							 # a = "hello", b = "world"

# 3. map+int 读取整数
a, b = map(int, input().split())  # 输入: 10 20
								   # a = 10, b = 20

# 4. 一行多个整数转为列表
nums = list(map(int, input().split()))  # 输入: 1 2 3 4
										 # nums = [1, 2, 3, 4]

# 5. 多行输入（for循环）
n = int(input())		# 第一行一个整数n
for _ in range(n):		# 接下来n行，每行两个整数
    a, b = map(int, input().split())
    print(a + b)

# 一次性读入所有输入
import sys

data = sys.stdin.read().split()  # 所有输入按空格或换行拆分
nums = list(map(int, data))
```

#### C++

```C++
// 1. 读入一整行
string s;
getline(cin, s);
```



#### 图

1. 邻接矩阵

```c++
int m, n;
int G[maxn][maxn];
int main() {
    fill(G[0], G[0] + maxn*maxn, 0);
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> G[i][j];        
        }
    }
}
```





### python

#### Counter

> 类似c++ STL的map

```python
from collections import Counter

# 用法1: 统计列表/字符串元素出现次数（直接传入括号）
lst = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple']
counter = Counter(lst)		# 一个map, 统计元素出现次数
print(counter)	# Counter({'apple': 3, 'banana': 2, 'orange': 1})

s = "hello world"
counter = Counter(s)
print(counter)	# Counter({'l': 3, 'o': 2, 'h': 1, 'e': 1, ' ': 1, 'w': 1, 'r': 1, 'd': 1})

# 用法2：单独添加元素并计数
counter = Counter()
counter['l'] += 2	# 可以单独添加字符
counter['l'] -= 1	# 可以增减计数

# 用法3: 使用 .most_common(n) 获取出现频率最高的 n 个元素
counter = Counter("abracadabra")
print(counter.most_common(2))	# [('a', 5), ('b', 2)]

# 用法4：与普通字典一样访问元素计数
counter = Counter(['a', 'b', 'a', 'c'])
print(counter['a'])  # 输出 2
print(counter['z'])  # 输出 0（不存在的键默认是0）

# 用法5：Counter 的运算操作
c1 = Counter('abca')
c2 = Counter('acdd')

print(c1 + c2)   # 合并计数
print(c1 - c2)   # 相减（只保留正数）
print(c1 & c2)   # 交集：取 min
print(c1 | c2)   # 并集：取 max

"""
输出：
Counter({'a': 3, 'c': 2, 'b': 1, 'd': 2})
Counter({'b': 1})
Counter({'a': 1, 'c': 1})
Counter({'a': 2, 'c': 1, 'b': 1, 'd': 2})
"""
```



### STL

| 容器                                  | API                                                          | 备注                                         |
| ------------------------------------- | ------------------------------------------------------------ | -------------------------------------------- |
| vector                                | 头文件`<vector> `                                            |                                              |
|                                       | `vector<int> num(n, 0)`（等价于`vector<int> num(n)`）<br />`vector<vector<int>> v(9, vector<int>(9, 0));` | **指定大小和默认值**                         |
|                                       | v.push_back(val), v.pop_back()                               | 尾部插入/删除                                |
|                                       | v.insert(it, val)                                            | 迭代器位置插入                               |
|                                       | v.erase(it), v.erase(it1, it2)                               | 删除元素/范围                                |
|                                       | v.clear()                                                    | 清空                                         |
|                                       | v.size()                                                     | 大小                                         |
|                                       | v.empty()                                                    | 是否为空                                     |
|                                       | v.resize(n)                                                  | 重设大小                                     |
|                                       | fill(v.begin(), v.end(), 0)                                  | **全部元素设为0**                            |
|                                       |                                                              |                                              |
| string                                | 头文件`<string>`                                             |                                              |
|                                       | s.length(), s.size()                                         | 长度                                         |
|                                       | s.empty()                                                    | 是否为空                                     |
|                                       | s.push_back(c), s.pop_back()                                 | **尾部增删字符**                             |
|                                       | s.append(str), s += str                                      | 追加字符串                                   |
|                                       | s.insert(pos, str)                                           | 插入字符串                                   |
|                                       | s.erase(pos, len)                                            | 删除子串                                     |
|                                       | s.replace(pos, len, str)                                     | 替换子串                                     |
|                                       | s.find(str), s.rfind(str)                                    | 正向/反向查找                                |
|                                       | s.find_first_of(chars)                                       | 查找任一字符首次出现                         |
|                                       | s.substr(pos, len)                                           | 提取子串                                     |
|                                       | **to_string()**                                              | int->string                                  |
|                                       | **stoi()**                                                   | string->int                                  |
|                                       | s = s1 + s2                                                  | **字符串加法（合并）**                       |
|                                       |                                                              |                                              |
| deque                                 |                                                              | 头文件`<deque>`                              |
|                                       | dq.push_front(val), dq.push_back(val)                        | 头尾插入                                     |
|                                       | dq.pop_front(), dq.pop_back()                                | 头尾删除                                     |
|                                       | dq.front(), dq.back()                                        | 头尾访问                                     |
|                                       | 其他操作类似vector                                           |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| set                                   | 头文件`<set>`                                                |                                              |
| multiset(允许重复)                    | **`set<int, greater<int>>`**                                 | 降序排列                                     |
|                                       | s.size(), s.empty()                                          | 大小                                         |
|                                       | s.insert(val)                                                | 插入元素                                     |
|                                       | s.erase(val), s.erase(it)                                    | 删除值/迭代器                                |
|                                       | s.clear()                                                    | 清空                                         |
|                                       | s.find(val)                                                  | 查找元素，返回迭代器（**查不到返回s.end()**) |
|                                       | s.count(val)                                                 | 统计个数                                     |
|                                       | s.lower_bound(val)                                           | 第一个>=val的位置                            |
|                                       | s.upper_bound(val)                                           | 第一个>val的位置                             |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| map                                   | 头文件`<map>`                                                |                                              |
| multimap(key可重复)                   | **`map<int, string, greater<int>>`**                         | 降序排列                                     |
|                                       | m[key] = value                                               | 下标访问/创建（**仅map**）                   |
|                                       | m.insert({key, value})                                       | 插入键值对                                   |
|                                       | m.at(key)                                                    | 安全访问                                     |
|                                       | m.find(key)                                                  | 查找key                                      |
|                                       | m.count(key)                                                 | 统计key个数                                  |
|                                       | m.lower_bound(key), m.upper_bound(key)                       |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| unordered_set                         | `<unordered_set>`                                            | API与set基本相同，但无序且平均O(1)时间复杂度 |
| unordered_multiset                    | us.insert(val), us.erase(val)                                |                                              |
|                                       | us.find(val), us.count(val)                                  |                                              |
|                                       | 没有lower_bound/upper_bound                                  |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| unordered_map<br />unordered_multimap | `<unordered_map>`                                            | API与map基本相同，但无序且平均O(1)时间复杂度 |
|                                       | um[key] = value                                              |                                              |
|                                       | um.insert({key, value})                                      |                                              |
|                                       | um.find(key), um.count(key)                                  |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| stack                                 | `<stack>`                                                    |                                              |
|                                       | st.push(val)                                                 | 入栈                                         |
|                                       | st.pop()                                                     | 出栈（无返回值）                             |
|                                       | st.top()                                                     | 栈顶元素                                     |
|                                       | st.size(), st.empty()                                        | 大小和是否为空                               |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| queue                                 | `<queue>`                                                    |                                              |
|                                       | q.push(val)                                                  | 入队                                         |
|                                       | q.pop()                                                      | 出队（无返回值）                             |
|                                       | q.front(), q.back()                                          | 队首队尾元素                                 |
|                                       | q.size(), q.empty()                                          | 大小和是否为空                               |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| priority_queue<br />（优先队列/堆）   | `<queue>`                                                    |                                              |
|                                       | `priority_queue<int> pq;`                                    | 大顶堆                                       |
|                                       | **`priority_queue<int, vector<int>, greater<int>> pq;`**     | 小顶堆                                       |
|                                       | pq.push(val)                                                 | 插入元素                                     |
|                                       | pq.pop()                                                     | 删除堆顶                                     |
|                                       | pq.top()                                                     | 堆顶元素                                     |
|                                       | pq.size(), pq.empty()                                        |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| 常用算法函数                          | `<algorithm>`                                                |                                              |
|                                       | sort(v.begin(), v.end())                                     | 升序排序                                     |
|                                       | sort(v.begin(), v.end(), greater<int>())                     | 降序                                         |
|                                       | find(v.begin(), v.end(), val)                                | 查找元素                                     |
|                                       | binary_search(v.begin(), v.end(), val)                       | 二分查找（需有序）                           |
|                                       | lower_bound(v.begin(), v.end(), val)                         | 第一个>=val位置                              |
|                                       | upper_bound(v.begin(), v.end(), val)                         | 第一个>val位置                               |
|                                       | reverse(v.begin(), v.end())                                  | 反转                                         |
|                                       | next_permutation(v.begin(), v.end())                         | 下一个排列                                   |
|                                       | max_element(v.begin(), v.end())                              | 最大元素位置                                 |
|                                       | min_element(v.begin(), v.end())                              | 最小元素位置                                 |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |



## 模板

### 数学

#### 素数表(在线打表) + 质因子分解

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
            while(n % prime[i] == 0) {	      // prime[i]是n的质因子
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



#### 最大公约数GCD & 最小公倍数LCM

```c++
int gcd(int a, int b) {			// 辗转相除法
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {			// 最小公倍数 = 乘积 / 最大公因数
    return a / gcd(a, b) * b;
}
```

 



#### 判断回文数

```c++
bool isPalin(int x) {
    if(x < 0) return false;     // 负数不是回文数
    string s = to_string(x);
    string tmp = s;             // 保存正序
    reverse(s.begin(), s.end());
    return s == tmp;

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



### 排序

#### 快速排序

步骤：

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





#### 插入排序

+ 理牌
+ 每轮只看前i个元素，把第i个元素插入到对应的位置（不是最终位置）

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





#### 冒泡排序

```c++
void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    
    for(int i = 0; i < n - 1; i++) {	// n-1轮, 每轮得到一个最大元素的最终位置
        bool swapped = false;  // 标记这轮是否有交换
        for(int j = 0; j < n - 1 - i; j++) {	// 每轮比较相邻元素，大的往后移
            if(nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        // 如果这轮没有交换，说明已经有序
        if(!swapped) break;
    }
}
```

+ 通常比插入排序慢
+ 需要很多交换操作，而插入排序通过元素移动代替交换


#### 选择排序

+ 最容易理解：n轮，每轮找到最小值，与当前位置交换

```c++
void selectSort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {		// 每轮按顺序得到一个最终位置
        int min_pos = i;
        for(int j = i; j < n; j++) {	// 在后面找更小的
            if(a[j] < a[i]) {
            	min_pos = j;		// 记录最小值下标
            }
        }
        if(min_pos != i) swap(a[min_pos], a[i]);
     }
}
```



### 树



#### 二叉树求高度

```c++
int maxDepth(TreeNode* root) {			// 自底向上求高度
    if(root == nullptr) return 0;		// 直到遍历到叶子才会返回
    int maxL = maxDepth(root->left);
    int maxR = maxDepth(root->right);
    return max(maxL, maxR) + 1;			// 不断向上返回当前结点最大深度，直到树根
}
```



#### 树层序遍历（BFS)

```c++
//存储结构
struct Node{
    int data;
    int layer;  // 层号
    vector<int> children;
}node[maxn];

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



#### LCA最近公共祖先

```c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 思路：在左右子树递归找给的两个节点.递归过程中:
    // 1. 如果左右子树分别找到了两个结点，则当前root就是答案，直接返回（自底向上的特性保证了当前root就是LCA）
    // 2. 如果只在一边找到，另一边没找到，说明找到的那边就是LCA

    if(root == nullptr) return nullptr;   // 没找到
    if(root == p || root == q) return root;     // 递归到了目标节点就返回这个结点
    // 分别在左右子树找
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    // 查看结果
    if(left != nullptr && right != nullptr) {   // 两个结点分别在两边
        return root;        // 当前root就是答案
    }else {
        return left != nullptr ? left : right;  // 否则哪边找到了就返回哪边
    }
}
```



#### 后序+中序建树

<img src="..\..\img\typora-user-images\image-20211214144725375.png" alt="image-20211214144725375" style="zoom: 50%;" />

```c++
/* 中序+后序建二叉树 */
Node* create(int postL, int postR, int inL, int inR) {
  if(postL > postR) return NULL;  // 递归边界
  Node* root = new Node;
  root->data = post[postR];		// 根节点为后序的最后一个位置
  int k = inL;
  for(; k <= inR; k++) {  // 找树根下标k
    if(in[k] == post[postR]) break;
  }
  // 此时in[k]为树根结点值，中序中k左边为左子树[inL, k-1], 右边为右子树[k+1, inR]
  int numLeft = k - inL;          // numLeft用于判断后序中的左右子树区间
  // 后序中左子树[postL, postL+numLeft-1], 右子树[postL+numLeft, postR-1]
  root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
  root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
  return node;
}
```





### 并查集

+ ==获得根结点用`findFather(i)`！！,不要用`father[i]`！==

```c++
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



## 动态规划

### 一 背包问题

> 选择物品的动态规划问题本质上就是dfs递归改递推，
>
> 复杂度和dfs+剪枝(记忆化搜索)一样，只是写法不同。
>
> 解题思路就是**先考虑所有的情况**，即对每个物品选还是不选分别进行dfs，
>
> 什么情况选以及下一层dfs传入的参数就是要思考的内容

#### 0-1背包

> capacity: 背包体积
>
> w[i]: 第i个物品体积
>
> v[i]: 第i个物品价值
>
> 返回物品总体积不超过背包容量情况下的最大总价值

```c++
int zero_one_backpack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();  // 物品数量
    
    /* ========== 二维数组版本 ========== */
    /*
    // dp[i][j] 表示用前i个物品，容量不超过j的最大价值
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (j >= w[i-1]) {	// 容量足够才能选第i个物品
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }else {		// 选不了第i个
            	dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][capacity];
    */
    
    /* ========== 一维数组版本（空间优化）========== */
    // dp[j] 表示容量不超过j的最大价值
    vector<int> dp(capacity + 1, 0);
    
    // 遍历每个物品
    for (int i = 0; i < n; i++) {
        // 从大到小遍历容量（逆序是关键！）
        // 这样可以保证每个物品只被使用一次
        for (int j = capacity; j >= w[i]; j--) {
            // 状态转移：选择当前物品 vs 不选择当前物品
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    return dp[capacity];
}
```

##### 0-1背包及其变形的状态转移方程

> dp[i, c]: 前i个物品所构成的子问题

1. 求最多/恰好装capacity的**最大总价值**：
   `dp[i, c] =max(dp[i-1, c-w[i]] + v[i], dp[i-1, c]) `
2. 求至少/恰好装capacity的**最小总价值**
   `dp[i, c] = min(dp[i-1, c-w[i]] + v[i], dp[i-1, c]) `
3. 求恰好/最多/至少装capacity时, **有多少种组合**：**（组合问题不需要价值数组）**
   `dp[i,c] = dp[i-1,c] + dp[i-1,c-w[i]]`
   其中至少装capacity的组合数为**恰好装capacity ~ sum的组合数之和**



#### 完全背包

> 与0-1背包区别:
> 选i时状态转移为dp[i, c-w[i]]而不是dp[i-1, c-w[i]]————因为**可以重复选**

```C++
int unbounded_backpack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();  // 物品数量
    
    /* ========== 二维数组版本 ========== */
    /*
    // dp[i][j] 表示用前i种物品，容量不超过j的最大价值
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    // 遍历每种物品
    for (int i = 1; i <= n; i++) {
        // 遍历每个容量
        for (int j = 0; j <= capacity; j++) {
            if (j >= w[i-1]) {
                // 注意：这里是dp[i][j-w[i-1]]，不是dp[i-1][j-w[i-1]]
                // 因为同一种物品可以选择多次
                dp[i][j] = max(dp[i][j], dp[i][j-w[i-1]] + v[i-1]);
            }else {		// 选不了第i个
            	dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][capacity];
    */
    
    /* ========== 一维数组版本（空间优化）========== */
    // dp[j] 表示容量不超过j的最大价值
    vector<int> dp(capacity + 1, 0);
    
    // 遍历每种物品
    for (int i = 0; i < n; i++) {
        // 从小到大遍历容量（正序是关键！）
        // 这样可以保证同一种物品可以被重复使用
        for (int j = w[i]; j <= capacity; j++) {
            // 状态转移：选择当前物品 vs 不选择当前物品
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    return dp[capacity];
}
```



##### 完全背包及其变形的状态转移方程

1. 求最多/恰好装capacity的**最大总价值**：
   `dp[i, c] =max(dp[i, c-w[i]] + v[i], dp[i-1, c]) `
2. 求至少/恰好装capacity的**最小总价值**
   `dp[i, c] = min(dp[i, c-w[i]] + v[i], dp[i-1, c]) `
3. 求恰好/最多/至少装capacity时, **有多少种组合**：**（组合问题不需要价值数组）**
   `dp[i,c] = dp[i-1,c] + dp[i,c-w[i]]`
   其中至少装capacity的组合数为**恰好装capacity ~ sum的组合数的总和**

+ 上面三个和0-1背包唯一区别就是选i时状态转为i而不是i-1

4. 能达到最大价值的方案有多少种？

   ```python
   # 两阶段dp：先求最大价值，再求方案数
   # 1. 求最大价值: max_val[i, c]表示前i个物品恰好装c的最大价值
   # 2. dp[i, c]表示前i个物品恰好装c的方案数
   dp[i, c] = 0
   if max_val[i,c] == max_val[i-1,c]:  # 不选也能达到最大值
       dp[i,c] += dp[i-1,c]
   if c >= w[i] and max_val[i,c] == max_val[i,c-w[i]] + v[i]:  # 选也能达到最大值
       dp[i,c] += dp[i,c-w[i]]
   ```

5. 恰好装c的**最多/最少物品数**
   `dp[i, c] = max/min(dp[i-1,c], dp[i,c-w[i]] + 1) `

6. 达到最大价值最少用多少物品？

   + 两阶段DP：先求最大价值，再在相同最大价值下求最少物品数
   + 类似最大价值方案数的思路，但用min而不是加法

7. **恰好用k个物品**装满容量C有多少种方案?

   ```python
   # dp[i,c,k] = 用前i种物品，容量为c，恰好用k个物品的方案数
   if c >= w[i] and k >= 1:
       dp[i,c,k] = dp[i-1,c,k] + dp[i,c-w[i],k-1]
   else:
       dp[i,c,k] = dp[i-1,c,k]
   ```

   



### 二 线性dp

#### 最长公共子序列LCS

> #### 从最简单的情况开始观察
>
> 假设我们有 text1 = "abc", text2 = "ac"
>
> 第一步：观察最基础的情况
>
> 让我们先看看最简单的子问题：
>
> **情况1：其中一个字符串为空**
>
> - "" 和 "a" 的LCS长度 = 0
> - "" 和 "ac" 的LCS长度 = 0
> - "a" 和 "" 的LCS长度 = 0
>
> 这很容易理解：空字符串和任何字符串的公共子序列只能是空串。
>
> **情况2：两个字符串都只有一个字符**
>
> - "a" 和 "a" 的LCS长度 = 1 (公共子序列是"a")
> - "a" 和 "c" 的LCS长度 = 0 (没有公共字符)
> - "b" 和 "a" 的LCS长度 = 0
>
> 
>
> #### 第二步：扩展到稍微复杂的情况
>
> 现在看看稍微复杂一点的：
>
> **"a" 和 "ac"**
>
> - 我们有字符'a'在两个字符串中都出现
> - 所以LCS长度 = 1
>
> **"ab" 和 "a"**
>
> - 只有字符'a'是公共的
> - 所以LCS长度 = 1
>
> **"ab" 和 "ac"**
>
> - 字符'a'是公共的
> - 字符'b'和'c'不匹配
> - 所以LCS长度 = 1
>
> 
>
> #### 第三步：发现关键规律
>
> 现在我们来看关键的观察。假设我们要求"abc" 和 "ac"的LCS：
>
> **分析过程：**
>  我们可以这样思考 - 看最后一个字符：
>
> - text1的最后一个字符是'c'
> - text2的最后一个字符是'c'
> - 它们相同！
>
> 既然最后的字符相同，那么：
>
> - "abc" 和 "ac" 的LCS = "ab" 和 "a" 的LCS + 1
>
> 让我们验证：
>
> - "ab" 和 "a" 的LCS长度是1（字符'a'）
> - 加上共同的'c'，总长度是2
> - 确实，"abc" 和 "ac" 的LCS是"ac"，长度为2
>
> 
>
> #### 第四步：当最后字符不同时
>
> 现在考虑"ab" 和 "ac"：
>
> - text1的最后字符是'b'
> - text2的最后字符是'c'
> - 它们不同
>
> 这时我们怎么办？我们有两个选择：
>
> 1. 忽略text1的最后字符'b'，求"a" 和 "ac" 的LCS
> 2. 忽略text2的最后字符'c'，求"ab" 和 "a" 的LCS
>
> 让我们计算：
>
> 1. "a" 和 "ac" 的LCS长度 = 1
> 2. "ab" 和 "a" 的LCS长度 = 1
>
> 两者都是1，所以"ab" 和 "ac" 的LCS长度 = max(1,1) = 1
>
> 
>
> #### 第五步：完整构建过程
>
> 现在让我们系统地构建所有子问题的解：
>
> 我用表格来展示，每个位置(i,j)表示text1前i个字符和text2前j个字符的LCS长度：
>
> ```c++
> text1 = "abc"
> text2 = "ac"
> 
>         ""  a   c
>     ""   0   0   0
>     a    0   ?   ?
>     b    0   ?   ?  
>     c    0   ?   ?
> ```
>
> **填充第一行和第一列（边界情况）：**
>
> ```C++
>         ""  a   c
>     ""   0   0   0
>     a    0   
>     b    0   
>     c    0   
> ```
>
> **填充(1,1)位置：**
>
> - 比较text1[0]='a' 和 text2[0]='a'
> - 相同！所以 = 左上角(0,0) + 1 = 0 + 1 = 1
>
> ```C++
>         ""  a   c
>     ""   0   0   0
>     a    0   1
>     b    0   
>     c    0   
> ```
>
> **填充(1,2)位置：**
>
> - 比较text1[0]='a' 和 text2[1]='c'
> - 不同，所以 = max(左边(1,1), 上边(0,2)) = max(1, 0) = 1
>
> ```C++
>         ""  a   c
>     ""   0   0   0
>     a    0   1   1
>     b    0   
>     c    0   
> ```
>
> **填充(2,1)位置：**
>
> - 比较text1[1]='b' 和 text2[0]='a'
> - 不同，所以 = max(左边(2,0), 上边(1,1)) = max(0, 1) = 1
>
> **填充(2,2)位置：**
>
> - 比较text1[1]='b' 和 text2[1]='c'
> - 不同，所以 = max(左边(2,1), 上边(1,2)) = max(1, 1) = 1
>
> **填充(3,1)位置：**
>
> - 比较text1[2]='c' 和 text2[0]='a'
> - 不同，所以 = max(左边(3,0), 上边(2,1)) = max(0, 1) = 1
>
> **填充(3,2)位置：**
>
> - 比较text1[2]='c' 和 text2[1]='c'
> - 相同！所以 = 左上角(2,1) + 1 = 1 + 1 = 2
>
> **最终结果：**
>
> ```C++
>         ""  a   c
>     ""   0   0   0
>     a    0   1   1
>     b    0   1   1
>     c    0   1   2
> ```
>
> 答案是2，对应的LCS是"ac"。
>
> 
>
> #### 总结规律
>
> 通过这个构建过程，我们发现了规律：
>
> 1. **如果当前字符相同**：当前位置的值 = 左上角的值 + 1
> 2. **如果当前字符不同**：当前位置的值 = max(左边的值, 上边的值)
>
> 这就是我们的状态转移方程！我们是通过观察和逐步构建自然地发现了这个规律，而不是一开始就假设知道了。


##### 代码

```c++
int longestCommonSubsequence(string text1, string text2) {
    // 二维dp: dp[i][j]表示str1前i个和str2前j个的最长公共子序列
    // 从头开始思考，对于两个字符串的当前字符str1[i]和str[j]:
    // 如果相同，直接加入答案，此时dp[i, j] = dp[i-1, j-1] + 1
    // 如果不同, 两种情况：
    //  1. 忽略str1[i]: 即考虑dp[i-1, j]
    //  2. 忽略str2[j]: 即考虑dp[i, j-1]
    //  此时dp[i, j] = max(dp[i-1, j], dp[i, j-1])

    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {  // 相等
                dp[i][j] = dp[i-1][j-1] + 1;    // 直接加入答案
            }else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
```



#### 子序列dp变体

> ## 第一类：直接变体（核心思路完全相同）
>
> ### 1035. 不相交的线
>
> **问题：** 在两个数组之间画线连接相同的数，线不能相交，求最多能画多少条线。
>
> **思考方式：** 这本质上就是LCS问题！
>
> - 不相交的条件等价于保持相对顺序
> - 连线的数量 = 最长公共子序列的长度
> - 完全相同的DP状态转移
>
> ### 1458. 两个子序列的最大点积
>
> **问题：** 计算两个子序列的最大点积。
>
> **思考方式：** LCS的加强版
>
> - 状态定义：`dp[i][j]` = 前i个和前j个元素中，必须选择第i个和第j个的最大点积
> - 需要考虑：选当前对、不选当前对、部分选择
>
> ## 第二类：LCS的直接扩展
>
> ### 516. 最长回文子序列
>
> **问题：** 求字符串的最长回文子序列长度。
>
> **思考方式：** 转化为LCS
>
> - 将字符串反转得到新字符串
> - 求原字符串和反转字符串的LCS
> - 例如："bbbab" 和 "babbb" 的LCS就是最长回文子序列
>
> ### 1092. 最短公共超序列
>
> **问题：** 求包含两个字符串的最短超序列。
>
> **思考方式：** 基于LCS的构造
>
> - 最短超序列长度 = len1 + len2 - LCS长度
> - 先求出LCS，然后构造包含两个字符串的最短序列
> - 状态转移需要记录构造路径
>
> ### 583. 两个字符串的删除操作
>
> **问题：** 通过删除操作使两个字符串相同，求最少删除次数。
>
> **思考方式：** 基于LCS
>
> - 最少删除次数 = len1 + len2 - 2 × LCS长度
> - 保留LCS部分，删除其他字符
>
> ### 712. 两个字符串的最小ASCII删除和
>
> **问题：** 删除字符使两字符串相同，求最小ASCII值删除和。
>
> **思考方式：** LCS的变种
>
> - 不是计算长度，而是计算保留字符的最大ASCII和
> - `dp[i][j]` = 前i个和前j个字符的最大保留ASCII和
>
> ## 第三类：三个或多个序列的LCS
>
> ### 最长公共子序列III（多个字符串）
>
> **问题：** 求三个或更多字符串的LCS。
>
> **思考方式：** 维度扩展
>
> - 三个字符串：`dp[i][j][k]`
> - 状态转移考虑三个字符是否相同
> - 时间复杂度 O(n³)
>
> ## 第四类：相似DP模式（区间/序列DP）
>
> ### 72. 编辑距离
>
> **问题：** 将一个字符串转换为另一个字符串的最少操作数。
>
> **思考方式：** 类似LCS的二维DP
>
> ```
> if s1[i] == s2[j]:
>     dp[i][j] = dp[i-1][j-1]
> else:
>     dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
> ```
>
> ### 97. 交错字符串
>
> **问题：** 判断s3是否由s1和s2交错组成。
>
> **思考方式：** 类似LCS的路径问题
>
> - `dp[i][j]` = s1前i个字符和s2前j个字符能否组成s3前i+j个字符
> - 状态转移考虑选择s1还是s2的当前字符
>
> ### 115. 不同的子序列
>
> **问题：** 在s中找t作为子序列的方案数。
>
> **思考方式：** LCS思路的计数版本
>
> ```
> if s[i] == t[j]:
>     dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
> else:
>     dp[i][j] = dp[i-1][j]
> ```
>
> ### 392. 判断子序列
>
> **问题：** 判断s是否为t的子序列。
>
> **思考方式：** LCS的简化版
>
> - 只需要判断LCS长度是否等于s的长度
> - 或者用双指针贪心解决
>
> ## 第五类：回文相关（利用LCS思想）
>
> ### 5. 最长回文子串
>
> **问题：** 求最长回文子串（注意是子串不是子序列）。
>
> **思考方式：** 中心扩展或Manacher算法，与LCS关系较远
>
> ### 1312. 让字符串成为回文串的最少插入次数
>
> **问题：** 最少插入多少字符使字符串变成回文。
>
> **思考方式：** 基于LCS
>
> - 求字符串与其反转的LCS
> - 答案 = n - LCS长度
>
> ## 第六类：背包问题的序列版本
>
> ### 1143变体：带权重的LCS
>
> **问题：** 每个字符有权重，求最大权重的公共子序列。
>
> **思考方式：** LCS + 权重
>
> - 状态转移时不是+1，而是+当前字符权重
>
> ## 统一的思考模式
>
> 解决这类问题的通用思考步骤：
>
> 1. **识别是否是序列匹配问题**
>    - 涉及两个序列的比较
>    - 需要保持相对顺序
>    - 求最优值（最长、最短、最少等）
> 2. **确定状态定义**
>    - 通常是 `dp[i][j]` 表示第一个序列前i个元素和第二个序列前j个元素的最优解
>    - 有时需要额外维度记录更多信息
> 3. **分析状态转移**
>    - 当前元素相同时的处理
>    - 当前元素不同时的选择策略
>    - 是否需要考虑不选择任何一个的情况
> 4. **确定边界条件**
>    - 空序列的处理
>    - 初始状态的设定
> 5. **优化空间复杂度**
>    - 观察是否只依赖于前一行/列
>    - 考虑滚动数组优化
>
> 这个思维框架可以帮你快速识别和解决大部分序列型动态规划问题。



##### 编辑距离（LCS变体）

> 和LCS的区别：
>
> - **LCS找相同**：保留匹配的字符，忽略不匹配的
> - **编辑距离找不同**：修正不匹配的字符，保持匹配的
>
> ## 从最简单情况开始思考
>
> ### 第一步：理解问题本质
>
> 我们要把 word1 变成 word2，有三种操作：
>
> - **插入**：在word1中插入一个字符
> - **删除**：从word1中删除一个字符
> - **替换**：把word1中的一个字符替换成另一个
>
> ### 第二步：观察最简单的情况
>
> **情况1：其中一个字符串为空**
>
> - "" → "abc" 需要3次插入操作
> - "abc" → "" 需要3次删除操作
>
> **情况2：两个字符串相同**
>
> - "abc" → "abc" 需要0次操作
>
> **情况3：只有一个字符不同**
>
> - "abc" → "abd" 需要1次替换操作（c→d）
>
> ### 第三步：发现递推关系
>
> 假设我们要把 word1 的前 i 个字符变成 word2 的前 j 个字符。
>
> **当 word1[i-1] == word2[j-1] 时：**
>
> - 最后一个字符已经匹配了，不需要额外操作
> - 操作数 = 把前面部分转换的操作数
>
> **当 word1[i-1] != word2[j-1] 时，我们有三种选择：**
>
> 1. **删除** word1[i-1]：相当于把 word1 前 i-1 个字符变成 word2 前 j 个字符，再删除一个字符
> 2. **插入** word2[j-1]：相当于把 word1 前 i 个字符变成 word2 前 j-1 个字符，再插入一个字符
> 3. **替换** word1[i-1] 为 word2[j-1]：相当于把 word1 前 i-1 个字符变成 word2 前 j-1 个字符，再替换一个字符
>
> ## 示例2：一步步构建 "intention" → "execution"
>
> ### 定义状态
>
> `dp[i][j]` = 将 "intention" 的前 i 个字符转换为 "execution" 的前 j 个字符所需的最少操作数
>
> ### 初始化边界条件
>
> ```
> word1 = "intention" (长度9)
> word2 = "execution" (长度9)
> 
>        ""  e  x  e  c  u  t  i  o  n
>     "" 0   1  2  3  4  5  6  7  8  9
>     i  1   
>     n  2   
>     t  3   
>     e  4   
>     n  5   
>     t  6   
>     i  7   
>     o  8   
>     n  9   
> ```
>
> 边界含义：
>
> - `dp[0][j] = j`：空字符串变成 "execution" 前j个字符，需要插入j次
> - `dp[i][0] = i`：**intention** 前i个字符变成空字符串，需要删除i次
>
> 填充边界后：
>
> ```
>        ""  e  x  e  c  u  t  i  o  n
>     "" 0   1  2  3  4  5  6  7  8  9
>     i  1   
>     n  2   
>     t  3   
>     e  4   
>     n  5   
>     t  6   
>     i  7   
>     o  8   
>     n  9   
> ```
>
> ### 逐步填充DP表
>
> **填充 dp[1][1]：** "i" → "e"
>
> - word1[0]='i', word2[0]='e'，不相同
> - 三种操作：
>   - 删除'i'：dp[0][1] + 1 = 1 + 1 = 2
>   - 插入'e'：dp[1][0] + 1 = 1 + 1 = 2
>   - 替换'i'→'e'：dp[0][0] + 1 = 0 + 1 = 1
> - dp[1][1] = min(2, 2, 1) = 1
>
> **填充 dp[1][2]：** "i" → "ex"
>
> - word1[0]='i', word2[1]='x'，不相同
> - 三种操作：
>   - 删除'i'：dp[0][2] + 1 = 2 + 1 = 3
>   - 插入'x'：dp[1][1] + 1 = 1 + 1 = 2
>   - 替换'i'→'x'：dp[0][1] + 1 = 1 + 1 = 2
> - dp[1][2] = min(3, 2, 2) = 2
>
> 继续这个过程，我逐行填充（为了节省篇幅，我重点展示几个关键位置）：
>
> **填充 dp[4][1]：** "inte" → "e"
>
> - word1[3]='e', word2[0]='e'，相同！
> - dp[4][1] = dp[3][0] = 3
>
> 让我展示完整的填充过程的关键步骤：
>
> ```
>        ""  e  x  e  c  u  t  i  o  n
>     "" 0   1  2  3  4  5  6  7  8  9
>     i  1   1  2  3  4  5  6  7  8  9
>     n  2   2  2  3  4  5  6  7  8  8
>     t  3   3  3  3  4  5  5  6  7  8
>     e  4   3  4  3  4  5  6  6  7  8
>     n  5   4  4  4  4  5  6  7  7  7
>     t  6   5  5  5  5  5  5  6  7  8
>     i  7   6  6  6  6  6  6  5  6  7
>     o  8   7  7  7  7  7  7  6  5  6
>     n  9   8  8  8  8  8  8  7  6  5
> ```
>
> ### 关键计算示例
>
> **dp[7][7]：** "intenti" → "executi"
>
> - word1[6]='i', word2[6]='i'，相同！
> - dp[7][7] = dp[6][6] = 5
>
> **dp[8][8]：** "intentio" → "executio"
>
> - word1[7]='o', word2[7]='o'，相同！
> - dp[8][8] = dp[7][7] = 5
>
> **dp[9][9]：** "intention" → "execution"
>
> - word1[8]='n', word2[8]='n'，相同！
> - dp[9][9] = dp[8][8] = 5
>
> ## 最终答案：5
>
> 转换路径一种可能的方案：
>
> 1. "intention" → "entention" (替换 i→e)
> 2. "entention" → "exention" (替换 n→x)
> 3. "exention" → "exection" (替换 n→c)
> 4. "exection" → "execution" (插入 u)
> 5. "execution" → "execution" (删除多余的字符)
>
> 实际上是5步操作，这与我们的DP结果一致！
>
> ## 状态转移方程总结
>
> ```python
> if word1[i-1] == word2[j-1]:
>     dp[i][j] = dp[i-1][j-1]  # 字符相同，无需操作
> else:
>     dp[i][j] = 1 + min(
>         dp[i-1][j],    # 删除
>         dp[i][j-1],    # 插入
>         dp[i-1][j-1]   # 替换
>     )
> ```

代码

```C++
int minDistance(string word1, string word2) {
    // 和LCS（最长公共子序列）的区别：
    // LCS: 保留相同的字符，忽略不同的
    // 编辑距离: 修复不同的字符，跳过相同的
    /* 从头开始思考：（下面假设下标从1开始）
        当 word1[i] == word2[j] 时: 不需要操作，直接跳过
            dp[i, j] = dp[i-1, j-1] + 0

        当 word1[i] != word2[j] 时，我们有三种选择：
            1. 删除 word1[i] -> dp[i-1, j] + 1
                相当于已经把word1前i-1个字符变成了word2前j个字符基础上再删除一个字符
            2. 插入 word2[j] -> dp[i, j-1] + 1
                相当于已经把word1前i个字符变成了word2前j-1个字符基础上再插入一个字符
            3. 直接替换: dp[i-1, j-1] + 1
                相当于已经把word1前i-1个字符变成了word2前j-1个字符基础上再替换一个字符
            此时dp[i, j] = min(上面三种)
    */
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 0; i <= m; i++ ){
        dp[i][0] = i;		// i个字符变为空串需要删除i次
    }
    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;		// 空串变为j个字符需要插入j次
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }else {
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;	// 多个元素的min需要加上{}
            }
        }
    }
    return dp[m][n];
}
```









#### 最长公共子串（连续）

> 与最长公共子序列唯一区别：不相等时dp=0，而不是继承前面的答案

```c++
for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
        if(s1[i-1] == s2[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
        }else {
            dp[i][j] = 0;	// 不相等直接变为0
        }
    }
}
```



#### 子串dp变体

> # 连续子串线性DP的经典变体
>
> ## 1. 最大子数组和（Kadane算法）
>
> ### 核心思路
>
> **状态定义：** `dp[i]` = 以第i个元素结尾的最大连续子数组和
>  **转移方程：** `dp[i] = max(nums[i], dp[i-1] + nums[i])`
>
> ### 核心代码
>
> ```cpp
> int maxSubArray(vector<int>& nums) {
>     int maxSum = nums[0];
>     int currentSum = nums[0];
>     
>     for (int i = 1; i < nums.size(); i++) {
>         // 要么重新开始，要么继续累加
>         currentSum = max(nums[i], currentSum + nums[i]);
>         maxSum = max(maxSum, currentSum);
>     }
>     
>     return maxSum;
> }
> ```
>
> ### 返回具体子数组的版本
>
> ```cpp
> vector<int> maxSubArray(vector<int>& nums) {
>     int maxSum = nums[0], currentSum = nums[0];
>     int start = 0, end = 0, tempStart = 0;
>     
>     for (int i = 1; i < nums.size(); i++) {
>         if (currentSum < 0) {
>             currentSum = nums[i];
>             tempStart = i;  // 重新开始
>         } else {
>             currentSum += nums[i];
>         }
>         
>         if (currentSum > maxSum) {
>             maxSum = currentSum;
>             start = tempStart;
>             end = i;
>         }
>     }
>     
>     return vector<int>(nums.begin() + start, nums.begin() + end + 1);
> }
> ```
>
> ## 2. 最大子数组乘积
>
> ### 核心思路
>
> 由于负数×负数=正数，需要同时维护最大值和最小值
>  **状态定义：** `maxDP[i]` = 以第i个元素结尾的最大连续子数组乘积，`minDP[i]` = 最小值
>
> ### 核心代码
>
> ```cpp
> int maxProduct(vector<int>& nums) {
>     int maxProd = nums[0], minProd = nums[0], result = nums[0];
>     
>     for (int i = 1; i < nums.size(); i++) {
>         // 当前数为负数时，最大最小值会交换
>         if (nums[i] < 0) {
>             swap(maxProd, minProd);
>         }
>         
>         // 要么重新开始，要么继续累乘
>         maxProd = max(nums[i], maxProd * nums[i]);
>         minProd = min(nums[i], minProd * nums[i]);
>         
>         result = max(result, maxProd);
>     }
>     
>     return result;
> }
> ```
>
> ## 3. 最长递增连续子序列
>
> ### 核心思路
>
> **状态定义：** `dp[i]` = 以第i个元素结尾的最长递增连续子序列长度
>  **转移方程：** 如果`nums[i] > nums[i-1]`，则`dp[i] = dp[i-1] + 1`，否则`dp[i] = 1`
>
> ### 核心代码
>
> ```cpp
> int findLengthOfLCIS(vector<int>& nums) {
>     if (nums.empty()) return 0;
>     
>     int maxLen = 1, currentLen = 1;
>     
>     for (int i = 1; i < nums.size(); i++) {
>         if (nums[i] > nums[i-1]) {
>             currentLen++;  // 继续递增
>         } else {
>             currentLen = 1;  // 重新开始
>         }
>         maxLen = max(maxLen, currentLen);
>     }
>     
>     return maxLen;
> }
> ```
>
> ## 4. 最长连续1（可翻转k个0）
>
> ### 核心思路
>
> **滑动窗口 + DP思想：** 维护一个窗口，窗口内最多包含k个0
>  **状态维护：** 窗口内0的个数，窗口的起始位置
>
> ### 核心代码
>
> ```cpp
> int longestOnes(vector<int>& nums, int k) {
>     int left = 0, maxLen = 0, zeroCount = 0;
>     
>     for (int right = 0; right < nums.size(); right++) {
>         if (nums[right] == 0) {
>             zeroCount++;
>         }
>         
>         // 如果0的个数超过k，收缩左边界
>         while (zeroCount > k) {
>             if (nums[left] == 0) {
>                 zeroCount--;
>             }
>             left++;
>         }
>         
>         maxLen = max(maxLen, right - left + 1);
>     }
>     
>     return maxLen;
> }
> ```
>
> ## 5. 和为k的最短连续子数组
>
> ### 核心思路
>
> **前缀和 + 哈希表：** 利用前缀和的差值来快速判断子数组和
>  **状态维护：** 每个前缀和第一次出现的位置
>
> ### 核心代码
>
> ```cpp
> int shortestSubarray(vector<int>& nums, int k) {
>     int n = nums.size();
>     vector<long long> prefixSum(n + 1, 0);
>     
>     // 计算前缀和
>     for (int i = 0; i < n; i++) {
>         prefixSum[i + 1] = prefixSum[i] + nums[i];
>     }
>     
>     int minLen = INT_MAX;
>     deque<int> dq;  // 单调队列，存储下标
>     
>     for (int i = 0; i <= n; i++) {
>         // 检查是否存在和为k的子数组
>         while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
>             minLen = min(minLen, i - dq.front());
>             dq.pop_front();
>         }
>         
>         // 维护单调性（递增）
>         while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
>             dq.pop_back();
>         }
>         
>         dq.push_back(i);
>     }
>     
>     return minLen == INT_MAX ? -1 : minLen;
> }
> ```
>
> ## 6. 连续子数组最大平均值
>
> ### 核心思路
>
> **滑动窗口：** 固定长度k的窗口，求最大和再除以k
>  **状态维护：** 当前窗口的和
>
> ### 核心代码
>
> ```cpp
> double findMaxAverage(vector<int>& nums, int k) {
>     // 计算第一个窗口的和
>     int windowSum = 0;
>     for (int i = 0; i < k; i++) {
>         windowSum += nums[i];
>     }
>     
>     int maxSum = windowSum;
>     
>     // 滑动窗口
>     for (int i = k; i < nums.size(); i++) {
>         windowSum = windowSum - nums[i - k] + nums[i];
>         maxSum = max(maxSum, windowSum);
>     }
>     
>     return (double)maxSum / k;
> }
> ```
>
> ## 7. 最长连续相同字符（可替换k个字符）
>
> ### 核心思路
>
> **滑动窗口 + 频率统计：** 维护窗口内字符频率，保证需要替换的字符不超过k个
>
> ### 核心代码
>
> ```cpp
> int characterReplacement(string s, int k) {
>     vector<int> count(26, 0);
>     int left = 0, maxCount = 0, maxLen = 0;
>     
>     for (int right = 0; right < s.length(); right++) {
>         count[s[right] - 'A']++;
>         maxCount = max(maxCount, count[s[right] - 'A']);
>         
>         // 如果需要替换的字符超过k个，收缩窗口
>         if (right - left + 1 - maxCount > k) {
>             count[s[left] - 'A']--;
>             left++;
>         }
>         
>         maxLen = max(maxLen, right - left + 1);
>     }
>     
>     return maxLen;
> }
> ```
>
> ## 各变体核心思想总结
>
> | 问题               | 核心思想                   | 状态转移关键                      | 时间复杂度 |
> | ------------------ | -------------------------- | --------------------------------- | ---------- |
> | **最大子数组和**   | 要么重新开始，要么继续累加 | `max(nums[i], dp[i-1] + nums[i])` | O(n)       |
> | **最大子数组乘积** | 维护最大最小值（负负得正） | 考虑正负号影响                    | O(n)       |
> | **最长递增子序列** | 连续性约束，断了就重置     | 比较相邻元素                      | O(n)       |
> | **最长连续1**      | 滑动窗口，维护0的个数      | 窗口伸缩                          | O(n)       |
> | **和为k子数组**    | 前缀和差值，单调队列       | 前缀和技巧                        | O(n)       |
> | **最大平均值**     | 固定窗口大小               | 窗口滑动                          | O(n)       |
> | **字符替换**       | 窗口内维护字符频率         | 频率统计                          | O(n)       |
>
> ## 通用模式识别
>
> ### 1. **累积型问题**（和、积）
>
> - 维护当前累积值
> - 决策：继续累积 vs 重新开始
>
> ### 2. **计数型问题**（长度、个数）
>
> - 维护当前计数
> - 条件满足时计数+1，不满足时重置
>
> ### 3. **窗口型问题**（固定/可变窗口）
>
> - 维护窗口状态
> - 根据条件伸缩窗口边界
>
> ### 4. **约束型问题**（最多k个某元素）
>
> - 维护约束条件
> - 违反约束时调整策略
>
> **核心记忆：** 连续子串DP的精髓在于"**断了就重新开始**"的思想，这是与普通DP最大的区别。



#### 最长递增子序列LIS

> ## 从DFS到DP的思维转换
>
> ### 1. DFS思路分析
>
> 你的DFS思路是：**对每个位置决定选不选**
>
> ```cpp
> // 站在位置i，前一个选择的元素是prev，当前长度是cnt
> dfs(nums, i, prev, cnt)
> ```
>
> ### 2. 关键观察：重叠子问题
>
> ```python
> 考虑数组 [1, 3, 2, 4]
> 
> DFS会产生这样的调用：
> dfs(0, -∞, 0) 
> ├── 选1: dfs(1, 1, 1)
> │   ├── 选3: dfs(2, 3, 2)
> │   │   ├── 不选2: dfs(3, 3, 2)  ← 状态A
> │   │   └── ...
> │   └── 不选3: dfs(2, 1, 1)
> │       ├── 选2: dfs(3, 2, 2)
> │       └── 不选2: dfs(3, 1, 1)  ← 状态B
> └── 不选1: dfs(1, -∞, 0)
>     └── 选3: dfs(2, 3, 1)
>         └── 不选2: dfs(3, 3, 1)  ← 又是状态A！
> ```
>
> **发现**：相同的`(位置, 前一个元素)`会被重复计算！
>
> ### 3. 思维转换的关键步骤
>
> #### 步骤1：识别状态
>
> ```c++
> // DFS的参数实际上定义了状态
> dfs(int i, int prev_idx) // 返回从位置i开始，前一个选择prev_idx的最大长度
> ```
>
> #### 步骤2：自顶向下 → 自底向上
>
> ```cpp
> // DFS (自顶向下)：从全局问题开始，递归求解子问题
> int dfs(i, prev_idx) {
>     if (i == n) return 0;
>     // 当前的最优解依赖于后面的子问题
>     return max(选当前的结果, 不选当前的结果);
> }
> 
> // DP (自底向上)：从最小子问题开始，逐步构建
> // 换个角度：dp[i] = 以nums[i]结尾的最长递增子序列长度
> for (int i = 0; i < n; i++) {
>     // 当前的最优解依赖于前面已经计算好的结果
>     dp[i] = max(dp[j] + 1) for all j < i where nums[j] < nums[i]
> }
> ```
>
> ### 4. 状态定义的转换
>
> **DFS状态**：`dfs(i, prev_idx)` = 从位置i开始，前一个选择prev_idx的最大长度
>
> **DP状态**：`dp[i]` = 以nums[i]结尾的最长递增子序列长度
>
> 这是**视角的转换**：
>
> - DFS：我在位置i，向后看还能得到多长？
> - DP：我在位置i，向前看已经得到多长？
>
> ### 5. 完整的转换对照
>
> ```cpp
> // DFS版本（记忆化）
> map<pair<int,int>, int> memo;
> int dfs(vector<int>& nums, int i, int prev_idx) {
>     if (i == nums.size()) return 0;
>     if (memo.count({i, prev_idx})) return memo[{i, prev_idx}];
>     
>     int result = dfs(nums, i+1, prev_idx); // 不选
>     if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
>         result = max(result, dfs(nums, i+1, i) + 1); // 选
>     }
>     return memo[{i, prev_idx}] = result;
> }
> 
> // DP版本
> int lengthOfLIS(vector<int>& nums) {
>     vector<int> dp(nums.size(), 1);
>     for (int i = 1; i < nums.size(); i++) {
>         for (int j = 0; j < i; j++) {
>             if (nums[j] < nums[i]) {
>                 dp[i] = max(dp[i], dp[j] + 1);
>             }
>         }
>     }
>     return *max_element(dp.begin(), dp.end());
> }
> ```
>
> ### 6. 转换的一般规律
>
> 1. **DFS → 记忆化搜索**：识别重叠子问题，添加缓存
> 2. **记忆化搜索 → DP**：改变计算顺序，从自顶向下变成自底向上
> 3. **状态重新定义**：有时需要换个角度定义状态，让转移更自然
>
> 这样看来，DFS和DP本质上是同一个问题的不同求解方式，关键是要找到状态和转移关系！



### 三 区间dp

> *Thinking...*
>
> > 用户要求我总结经典区间DP以及变体，包括思路与核心代码。让我按照不同的类型来分类整理：
> >
> > 1. 基础区间DP
> >    - 最长回文子串
> >    - 最长回文子序列
> >    - 区间内最小分割次数
> > 2. 合并类区间DP
> >    - 矩阵链乘法
> >    - 石子合并
> >    - 戳气球
> > 3. 匹配类区间DP
> >    - 括号匹配
> >    - 有效括号最少添加
> > 4. 博弈类区间DP
> >    - 石子游戏
> >    - 预测赢家
> > 5. 其他经典变体
> >    - 回文串分割
> >    - 最优二叉搜索树
> >
> > 每个问题我需要提供：
> >
> > - 问题描述
> > - 核心思路
> > - 状态定义
> > - 转移方程
> > - 完整代码
> > - 复杂度分析
> >
> > 让我按照这个结构来组织答案。
>
> # 经典区间DP及变体全解析
>
> ## 1. 基础回文类区间DP
>
> ### 1.1 最长回文子串
>
> #### 问题描述
>
> 给定字符串s，找出最长回文子串。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 区间[i,j]是否为回文串
>  **转移方程：** 去掉两端，看内部是否回文
>
> #### 核心代码
>
> ```cpp
> string longestPalindrome(string s) {
>     int n = s.length();
>     if (n <= 1) return s;
>     
>     vector<vector<bool>> dp(n, vector<bool>(n, false));
>     string result = "";
>     
>     // 按区间长度填充
>     for (int len = 1; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             
>             if (len == 1) {
>                 dp[i][j] = true;  // 单字符
>             } else if (len == 2) {
>                 dp[i][j] = (s[i] == s[j]);  // 双字符
>             } else {
>                 dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
>             }
>             
>             if (dp[i][j] && len > result.length()) {
>                 result = s.substr(i, len);
>             }
>         }
>     }
>     
>     return result;
> }
> ```
>
> ### 1.2 最长回文子序列
>
> #### 问题描述
>
> 给定字符串s，找出最长回文子序列的长度。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 区间[i,j]内最长回文子序列长度
>  **转移方程：** 首尾相等时+2，否则取较大值
>
> #### 核心代码
>
> ```cpp
> int longestPalindromeSubseq(string s) {
>     int n = s.length();
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     
>     // 按区间长度填充
>     for (int len = 1; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             
>             if (len == 1) {
>                 dp[i][j] = 1;  // 单字符长度为1
>             } else if (s[i] == s[j]) {
>                 dp[i][j] = dp[i+1][j-1] + 2;  // 首尾相等
>             } else {
>                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);  // 去掉一端
>             }
>         }
>     }
>     
>     return dp[0][n-1];
> }
> ```
>
> ### 1.3 回文串分割（最少分割次数）
>
> #### 问题描述
>
> 给定字符串s，返回使每个子串都是回文串的最少分割次数。
>
> #### 核心思路
>
> **预处理：** 先用区间DP求出所有回文子串
>  **状态定义：** `dp[i]` = 前i个字符的最少分割次数
>
> #### 核心代码
>
> ```cpp
> int minCut(string s) {
>     int n = s.length();
>     
>     // 预处理：判断所有子串是否为回文
>     vector<vector<bool>> isPalin(n, vector<bool>(n, false));
>     for (int len = 1; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             if (len == 1) {
>                 isPalin[i][j] = true;
>             } else if (len == 2) {
>                 isPalin[i][j] = (s[i] == s[j]);
>             } else {
>                 isPalin[i][j] = (s[i] == s[j]) && isPalin[i+1][j-1];
>             }
>         }
>     }
>     
>     // dp[i] = 前i个字符的最少分割次数
>     vector<int> dp(n + 1, INT_MAX);
>     dp[0] = 0;
>     
>     for (int i = 1; i <= n; i++) {
>         if (isPalin[0][i-1]) {
>             dp[i] = 0;  // 整个前缀就是回文
>         } else {
>             for (int j = 1; j < i; j++) {
>                 if (isPalin[j][i-1]) {
>                     dp[i] = min(dp[i], dp[j] + 1);
>                 }
>             }
>         }
>     }
>     
>     return dp[n];
> }
> ```
>
> ## 2. 合并类区间DP
>
> ### 2.1 矩阵链乘法
>
> #### 问题描述
>
> 给定矩阵链，求最少的标量乘法次数。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 计算矩阵i到j的最少乘法次数
>  **转移方程：** 枚举分割点k，分成两部分计算
>
> #### 核心代码
>
> ```cpp
> int matrixChainOrder(vector<int>& dims) {
>     int n = dims.size() - 1;  // n个矩阵
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     
>     // 按区间长度填充
>     for (int len = 2; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             dp[i][j] = INT_MAX;
>             
>             // 枚举分割点
>             for (int k = i; k < j; k++) {
>                 int cost = dp[i][k] + dp[k+1][j] + 
>                           dims[i] * dims[k+1] * dims[j+1];
>                 dp[i][j] = min(dp[i][j], cost);
>             }
>         }
>     }
>     
>     return dp[0][n-1];
> }
> ```
>
> ### 2.2 石子合并
>
> #### 问题描述
>
> 有n堆石子，每次只能合并相邻的两堆，求最小合并代价。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 合并第i堆到第j堆的最小代价
>  **转移方程：** 枚举分割点，加上合并代价
>
> #### 核心代码
>
> ```cpp
> int stoneGame(vector<int>& stones) {
>     int n = stones.size();
>     
>     // 前缀和
>     vector<int> prefixSum(n + 1, 0);
>     for (int i = 0; i < n; i++) {
>         prefixSum[i + 1] = prefixSum[i] + stones[i];
>     }
>     
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     
>     // 按区间长度填充
>     for (int len = 2; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             dp[i][j] = INT_MAX;
>             
>             int sum = prefixSum[j + 1] - prefixSum[i];  // 区间和
>             
>             for (int k = i; k < j; k++) {
>                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
>             }
>         }
>     }
>     
>     return dp[0][n-1];
> }
> ```
>
> ### 2.3 戳气球（最大分数）
>
> #### 问题描述
>
> 有n个气球，戳破第i个气球得分为`nums[left]*nums[i]*nums[right]`，求最大得分。
>
> #### 核心思路
>
> **技巧：** 两端添加虚拟气球（值为1）
>  **状态定义：** `dp[i][j]` = 戳破开区间(i,j)内所有气球的最大得分
>  **转移方程：** 枚举最后戳破的气球k
>
> #### 核心代码
>
> ```cpp
> int maxCoins(vector<int>& nums) {
>     int n = nums.size();
>     vector<int> arr(n + 2);
>     arr[0] = arr[n + 1] = 1;  // 添加虚拟边界
>     for (int i = 1; i <= n; i++) {
>         arr[i] = nums[i - 1];
>     }
>     
>     // dp[i][j] = 戳破开区间(i,j)内所有气球的最大得分
>     vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
>     
>     // 按区间长度填充
>     for (int len = 2; len <= n + 1; len++) {
>         for (int i = 0; i <= n + 1 - len; i++) {
>             int j = i + len;
>             
>             // 枚举最后戳破的气球k
>             for (int k = i + 1; k < j; k++) {
>                 int score = arr[i] * arr[k] * arr[j];
>                 dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + score);
>             }
>         }
>     }
>     
>     return dp[0][n + 1];
> }
> ```
>
> ## 3. 匹配类区间DP
>
> ### 3.1 有效括号匹配
>
> #### 问题描述
>
> 给定只包含括号的字符串，判断是否有效。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 区间[i,j]是否能完全匹配
>  **转移方程：** 首尾匹配+内部匹配，或分割成两部分
>
> #### 核心代码
>
> ```cpp
> bool isValidParentheses(string s) {
>     int n = s.length();
>     if (n % 2 == 1) return false;
>     
>     vector<vector<bool>> dp(n, vector<bool>(n, false));
>     
>     // 按区间长度填充
>     for (int len = 2; len <= n; len += 2) {  // 只考虑偶数长度
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             
>             // 情况1：首尾匹配，内部也匹配
>             if (isMatch(s[i], s[j]) && dp[i+1][j-1]) {
>                 dp[i][j] = true;
>             }
>             
>             // 情况2：分割成两部分
>             for (int k = i + 1; k < j; k += 2) {
>                 if (dp[i][k] && dp[k+1][j]) {
>                     dp[i][j] = true;
>                     break;
>                 }
>             }
>         }
>     }
>     
>     return dp[0][n-1];
> }
> 
> bool isMatch(char left, char right) {
>     return (left == '(' && right == ')') ||
>            (left == '[' && right == ']') ||
>            (left == '{' && right == '}');
> }
> ```
>
> ### 3.2 最少添加括号使其有效
>
> #### 问题描述
>
> 给定括号字符串，返回使其有效需要添加的最少括号数。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 使区间[i,j]有效需要添加的最少括号数
>
> #### 核心代码
>
> ```cpp
> int minAddToMakeValid(string s) {
>     int n = s.length();
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     
>     // 单个字符需要添加1个
>     for (int i = 0; i < n; i++) {
>         dp[i][i] = 1;
>     }
>     
>     // 按区间长度填充
>     for (int len = 2; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             dp[i][j] = len;  // 最坏情况：每个字符都需要添加1个
>             
>             // 情况1：首尾匹配
>             if (isMatch(s[i], s[j])) {
>                 dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
>             }
>             
>             // 情况2：分割成两部分
>             for (int k = i; k < j; k++) {
>                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
>             }
>         }
>     }
>     
>     return dp[0][n-1];
> }
> ```
>
> ## 4. 博弈类区间DP
>
> ### 4.1 石子游戏（预测赢家）
>
> #### 问题描述
>
> 两人轮流取数组两端的数，求先手能否获胜。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 在区间[i,j]中先手比后手多得的最大分数
>  **转移方程：** 选左端或右端，对手变成先手
>
> #### 核心代码
>
> ```cpp
> bool predictTheWinner(vector<int>& nums) {
>     int n = nums.size();
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     
>     // 单个元素时，先手直接拿走
>     for (int i = 0; i < n; i++) {
>         dp[i][i] = nums[i];
>     }
>     
>     // 按区间长度填充
>     for (int len = 2; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             
>             // 选择左端或右端，使得领先分数最大
>             int takeLeft = nums[i] - dp[i+1][j];
>             int takeRight = nums[j] - dp[i][j-1];
>             dp[i][j] = max(takeLeft, takeRight);
>         }
>     }
>     
>     return dp[0][n-1] >= 0;  // 先手领先分数≥0就能获胜
> }
> ```
>
> ### 4.2 石子游戏II（动态M值）
>
> #### 问题描述
>
> 每次可以取1到2*M堆石子，M的初值为1，取了X堆后M更新为max(M,X)。
>
> #### 核心思路
>
> **状态定义：** `dp[i][m]` = 从第i堆开始，当前M值下先手能得到的最大石子数
>
> #### 核心代码
>
> ```cpp
> int stoneGameII(vector<int>& piles) {
>     int n = piles.size();
>     
>     // 后缀和
>     vector<int> suffixSum(n + 1, 0);
>     for (int i = n - 1; i >= 0; i--) {
>         suffixSum[i] = suffixSum[i + 1] + piles[i];
>     }
>     
>     // dp[i][m] = 从位置i开始，M值为m时先手能得到的最大值
>     vector<vector<int>> dp(n, vector<int>(n + 1, 0));
>     
>     // 从后往前填充
>     for (int i = n - 1; i >= 0; i--) {
>         for (int m = 1; m <= n; m++) {
>             // 如果能取完所有剩余石子
>             if (i + 2 * m >= n) {
>                 dp[i][m] = suffixSum[i];
>             } else {
>                 // 枚举取x堆（1 <= x <= 2*m）
>                 for (int x = 1; x <= 2 * m; x++) {
>                     int newM = max(m, x);
>                     dp[i][m] = max(dp[i][m], 
>                                   suffixSum[i] - dp[i + x][newM]);
>                 }
>             }
>         }
>     }
>     
>     return dp[0][1];
> }
> ```
>
> ## 5. 其他经典变体
>
> ### 5.1 最优二叉搜索树
>
> #### 问题描述
>
> 给定搜索频率，构造最优二叉搜索树使得搜索代价最小。
>
> #### 核心思路
>
> **状态定义：** `dp[i][j]` = 构造包含keys[i]到keys[j]的最优BST的最小代价
>  **转移方程：** 枚举根节点
>
> #### 核心代码
>
> ```cpp
> int optimalBST(vector<int>& keys, vector<int>& freq) {
>     int n = keys.size();
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     vector<int> prefixSum(n + 1, 0);
>     
>     for (int i = 0; i < n; i++) {
>         prefixSum[i + 1] = prefixSum[i] + freq[i];
>     }
>     
>     // 按区间长度填充
>     for (int len = 1; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             dp[i][j] = INT_MAX;
>             
>             int sum = prefixSum[j + 1] - prefixSum[i];
>             
>             if (len == 1) {
>                 dp[i][j] = freq[i];
>             } else {
>                 // 枚举根节点
>                 for (int r = i; r <= j; r++) {
>                     int cost = sum;
>                     if (r > i) cost += dp[i][r-1];
>                     if (r < j) cost += dp[r+1][j];
>                     dp[i][j] = min(dp[i][j], cost);
>                 }
>             }
>         }
>     }
>     
>     return dp[0][n-1];
> }
> ```
>
> ### 5.2 回文串删除（最少删除次数）
>
> #### 问题描述
>
> 删除最少字符使字符串变成回文串。
>
> #### 核心思路
>
> **转化：** 原串长度 - 最长回文子序列长度
>
> #### 核心代码
>
> ```cpp
> int minDeletions(string s) {
>     int n = s.length();
>     vector<vector<int>> dp(n, vector<int>(n, 0));
>     
>     // 求最长回文子序列
>     for (int len = 1; len <= n; len++) {
>         for (int i = 0; i <= n - len; i++) {
>             int j = i + len - 1;
>             
>             if (len == 1) {
>                 dp[i][j] = 1;
>             } else if (s[i] == s[j]) {
>                 dp[i][j] = dp[i+1][j-1] + 2;
>             } else {
>                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
>             }
>         }
>     }
>     
>     return n - dp[0][n-1];
> }
> ```
>
> ## 6. 区间DP模板总结
>
> ### 通用模板
>
> ```cpp
> // 区间DP通用模板
> vector<vector<int>> dp(n, vector<int>(n, 初始值));
> 
> // 初始化单个元素
> for (int i = 0; i < n; i++) {
>     dp[i][i] = 单个元素的值;
> }
> 
> // 按区间长度递增填充
> for (int len = 2; len <= n; len++) {           // 区间长度
>     for (int i = 0; i <= n - len; i++) {       // 左端点
>         int j = i + len - 1;                   // 右端点
>         
>         // 方式1：去掉两端（如回文问题）
>         if (condition) {
>             dp[i][j] = dp[i+1][j-1] + 额外代价;
>         }
>         
>         // 方式2：枚举分割点（如合并问题）
>         for (int k = i; k < j; k++) {
>             dp[i][j] = min/max(dp[i][j], 
>                               dp[i][k] + dp[k+1][j] + 合并代价);
>         }
>         
>         // 方式3：其他转移
>         dp[i][j] = f(dp[其他状态]);
>     }
> }
> 
> return dp[0][n-1];  // 整个区间的答案
> ```
>
> ### 复杂度分析
>
> | 类型           | 时间复杂度 | 空间复杂度 | 特点             |
> | -------------- | ---------- | ---------- | ---------------- |
> | **基础区间DP** | O(n²)      | O(n²)      | 简单转移         |
> | **合并类**     | O(n³)      | O(n²)      | 三重循环         |
> | **博弈类**     | O(n³)      | O(n²)      | 考虑对手最优策略 |
>
> ### 记忆要点
>
> 1. **填充顺序：** 按区间长度从小到大
> 2. **边界处理：** 单个元素和相邻元素
> 3. **转移方向：** 从小区间推大区间
> 4. **分割策略：** 枚举所有可能分割点
> 5. **状态压缩：** 某些情况可以用滚动数组优化空间





### 四 状态机dp

> ## 什么是状态机？
>
> 状态机就像一个游戏角色，在不同的"状态"之间切换。比如马里奥可以是"小马里奥"、"大马里奥"、"火焰马里奥"等状态，遇到不同事件就会状态转移。
>
> ## 最简单的例子：爬楼梯
>
> 假设你要爬楼梯，每次可以爬1步或2步。
>
> **传统DP思路**：
>
> ```
> dp[i] = dp[i-1] + dp[i-2]  // 到第i阶的方法数
> ```
>
> **状态机DP思路**：
>  我们定义两个状态：
>
> - `state1`: 上一步走了1步到达当前位置
> - `state2`: 上一步走了2步到达当前位置
>
> 状态转移：
>
> ```
> new_state1 = state1 + state2  // 这次走1步，上次可能走1步或2步
> new_state2 = state1           // 这次走2步，上次只能走1步
> ```
>
> 看起来复杂了？别急，这为复杂问题打下基础。
>
> ## 进阶例子：打家劫舍
>
> 你是个小偷，沿街有房子，相邻房子不能同时偷。
>
> **状态定义**：
>
> - `rob`: 偷了当前房子的最大金额
> - `not_rob`: 没偷当前房子的最大金额
>
> **状态转移**：
>
> ```python
> # 对于每个房子 houses[i]
> new_rob = not_rob + houses[i]     # 要偷当前房子，上个房子必须没偷
> new_not_rob = max(rob, not_rob)   # 不偷当前房子，上个房子偷不偷都行
> ```
>
> 这就是状态机！每个房子我们都在两个状态间选择。
>
> ## 状态机DP的核心思想
>
> 1. **状态定义**：把问题抽象成几个关键状态
> 2. **状态转移**：定义状态之间如何切换
> 3. **决策选择**：每一步都在所有可能状态中选最优的
>
> ## 更形象的理解
>
> 想象你在玩一个RPG游戏：
>
> - 每个时刻你都有一个"状态"（比如：生命值、装备状态等）
> - 每次行动都可能改变状态
> - 你要选择行动让最终状态最优
>
> ## 回到股票问题
>
> 股票交易的状态机就是：
>
> ```
> [没操作] → [买入1] → [卖出1] → [买入2] → [卖出2]
> ```
>
> 每天你都在这些状态中，选择是否进行状态转移。
>
> ## 状态机DP vs 传统DP
>
> **传统DP**：关注"到达某个位置的最优值"
>
> ```
> dp[i] = 到第i个位置的最优解
> ```
>
> **状态机DP**：关注"在某个状态下的最优值"
>
> ```
> state[i][j] = 第i个时刻处于状态j的最优解
> ```
>
> 状态机DP更适合处理有"约束条件"或"多种选择状态"的问题，比如：
>
> - 股票交易（买入/卖出状态）
> - 打家劫舍（偷/不偷状态）
> - 染色问题（不同颜色状态）
>
> 关键是要找到问题的"状态"本质，然后设计状态转移方程。这种思维方式一旦掌握，很多复杂问题都能迎刃而解！

#### 买卖股票的最佳时机III

> 最多可以买交易两次，求最大收益

定义四个状态：

- `buy1`：-price_min，就是最小价格的负数
- `sell1`：假设到目前只做一笔交易的最大利润
- `buy2`：记录第二次买入的最佳时机，即前面第一次卖出后，在某处买入手里最多剩多少
- `sell2`：记录第二次卖出最多赚多少，即最终答案



状态转移方程：

```python
buy1 = max(buy1, -price)
sell1 = max(sell1, buy1 + price)
buy2 = max(buy2, sell1 - price)
sell2 = max(sell2, buy2 + price)
```



##### 逐步推导

[1,2,4,2,5,7,2,4,9,0]为例:

**初始状态**：buy1=-∞, sell1=0, buy2=-∞, sell2=0

| 天数 | 价格 | buy1 | sell1 | buy2 | sell2  | 说明                               |
| ---- | ---- | ---- | ----- | ---- | ------ | ---------------------------------- |
| 0    | 1    | -1   | 0     | -1   | 0      | 第一次买入，成本1                  |
| 1    | 2    | -1   | 1     | -1   | 1      | 第一次卖出可获利1                  |
| 2    | 4    | -1   | 3     | -1   | 3      | 第一次卖出可获利3                  |
| 3    | 2    | -1   | 3     | 1    | 3      | **关键**：第二次买入，利用前面利润 |
| 4    | 5    | -1   | 4     | 1    | 6      | 第二次卖出获利更多                 |
| 5    | 7    | -1   | 6     | 1    | 8      | 继续优化                           |
| 6    | 2    | -1   | 6     | 4    | 8      | 第二次买入时机更好                 |
| 7    | 4    | -1   | 6     | 4    | 8      | 保持状态                           |
| 8    | 9    | -1   | 8     | 4    | **13** | **最优解！**                       |
| 9    | 0    | -1   | 8     | 8    | 13     | 最终状态                           |

> ## 状态机的"时空穿越"特性
>
> 状态机允许在同一天进行多次操作，就像：
>
> **第一天的完整思考过程**：
>
> - "如果我只买一次：成本-1"
> - "如果我买了又卖：利润0"
> - "如果我买了又卖，然后再买：成本-1"
> - "如果我买了又卖，再买了又卖：利润0"
>
> 所以前几天buy2=buy1、sell2=sell1是完全正常的！



## HOT100刷题记录

### 哈希







### 双指针







### 滑动窗口





### 子串





### 普通数组






### 矩阵







### 链表

#### 160.相交链表

> 1. 双指针

```C++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* cpA = headA;
        ListNode* cpB = headB;
        while(cpA != nullptr) {
            cpA = cpA->next;
            lenA++;
        }
        while(cpB != nullptr) {
            cpB = cpB->next;
            lenB++;
        }
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
    
        if(lenA > lenB) {
            while(lenA != lenB) {
                ptrA = ptrA->next;
                lenA--;
            }
        }else {
            while(lenA != lenB) {
                ptrB = ptrB->next;
                lenB--;
            }
        }
        while(ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};
```

> 2. 直接保存A链表结点，接着遍历B遇到相同结点就返回

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        while(headA != nullptr) {     // 保存A的所有节点
            visited.insert(headA);
            headA = headA->next;
        }
        while(headB != nullptr) {
            if(visited.count(headB)) return headB;
            headB = headB->next;
        }
        return headB;
    }
};
```



#### 260.反转链表

> pre, cur, next三指针

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* pre = nullptr, * cur = head, * next = head->next;
        
        while(cur != nullptr) {
            cur->next = pre;
            pre = cur;
            cur = next;
            if(next != nullptr) next = next->next;
        }
        return pre;
    }
};
```



#### 234.回文链表

> 将链表后半部分反转，从中间切割后双指针同时读

```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp != nullptr) {     // 计算链表长度
            n++;
            tmp = tmp->next;
        }
        if(n==1) return true;
        ListNode* p1 = head, * p2 = head, * pre = nullptr;
        for(int i = 0; i < n / 2; i++) { // 移动n/2次到后半部分
            pre = p2;
            p2 = p2->next;
        }
        if(n % 2 != 0) p2 = p2->next;   // 奇数忽略最中间结点
        pre->next = nullptr;    // 前半段的最后一个节点
        
        // 反转后半段
        pre = nullptr;
        ListNode* cur = p2;
        while(cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // 双指针同时遍历两个链表
        p2 = pre;
        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
```







### 二叉树

#### [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

> 康复训练

```c++
class Solution {
private:
    vector<int> ans;
public:
    void inOrder(TreeNode* root) {
        if(root == nullptr) return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};
```



#### [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

> 1. 最大高度(自底向上计算)

```C++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;		// 直到遍历到叶子才会返回
        int maxL = maxDepth(root->left);
        int maxR = maxDepth(root->right);
        return max(maxL, maxR) + 1;			// 不断向上返回当前结点最大深度，直到树根
    }
};
```

> 2. 最大深度(自顶向下计算)

```C++
class Solution {
public:
    int maxdepth = 0;
    void dfs(TreeNode* cur, int depth) {
        if(cur == nullptr) return;
        maxdepth = max(depth, maxdepth);	// 向下遍历的过程中直接计算最大深度
        dfs(cur->left, depth+1);
        dfs(cur->right, depth+1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return maxdepth;
    }
};
```



#### [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

> 什么弱智题？自顶向下和自底向上没区别，随便什么时候交换

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```



#### [101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree/)

> 1. 翻转右子树，再判断左右子树是否相同

```C++
class Solution {
public:
    void invert(TreeNode* root) {               // 左右翻转
        if(root == nullptr) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invert(root->left);
        invert(root->right);
    }
    bool is_equal(TreeNode* root1, TreeNode* root2) {   // 判断两个树是否相同
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr && root2 != nullptr) return false;
        if(root1 != nullptr && root2 == nullptr) return false;
        return (root1->val == root2->val) && is_equal(root1->left, root2->left) && is_equal(root1->right, root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        invert(root->right);
        return is_equal(root->left, root->right);
    }
};
```

> 2. 不需要翻转右子树，直接在遍历过程中判断(一个先左后右，一个先右后左)

```C++
class Solution {
public:
    bool isSym(TreeNode* root1, TreeNode* root2) {     // 判断两个树是否对称
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr && root2 != nullptr) return false;
        if(root1 != nullptr && root2 == nullptr) return false;
        return (root1->val == root2->val) && isSym(root1->left, root2->right) && isSym(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }
};
```



#### [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/)

> 求左右子树深度之和最长的结点

```c++
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {    // 自底向上计算每个结点高度
        if(root == nullptr) {
            return -1;
        }
        int maxL = dfs(root->left);
        int maxR = dfs(root->right);
        ans = max(maxL + maxR + 2, ans);    // 得到左右高度后直接更新答案
        return max(maxL, maxR) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {  
        dfs(root);
        return ans;
    }
};
```



#### [102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

> queue康复训练
>
> 难点：如何同时处理一层的所有元素？答：`q.size()`

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;  // 检查空树
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {       // 队列非空时执行
            vector<int> cur;    // 存放本层的所有结点
            int n = q.size();   // 本层结点个数
            while(n--) {        // 一次性弹出本层所有节点
                TreeNode* front = q.front();
                q.pop();
                cur.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
```



#### [108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

> 二分建树

```c++
class Solution {
public:
    TreeNode* create(vector<int>& nums, int L, int R) {
        if(L > R) return nullptr;
        int mid = L + (R-L) / 2;    // 当前子树根
        TreeNode* root = new TreeNode;
        root->val = nums[mid];
        root->left = create(nums, L, mid-1);
        root->right = create(nums, mid+1, R);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};
```



#### [98. 判断BST](https://leetcode.cn/problems/validate-binary-search-tree/)

> 方法一：dfs传入子树的最大最小值，即当前树根必须处于的区间，自顶向下更新区间

```c++
class Solution {
public:
    #define ll long long
    bool dfs(TreeNode* root, ll Min, ll Max) {    // 传入有效区间
        if(root == nullptr) {   // 空结点也算BST
            return true;
        }
        return root->val > Min && root->val < Max   // 当前结点在区间内且左右子树都是BST
        && dfs(root->left, Min, root->val) && dfs(root->right, root->val, Max);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);    // 根结点始终处于有效区间
    }
};
```

> 方法二：dfs返回子树的最大值和最小值，自底向上检查

```c++
class Solution {
public:
    pair<long long, long long> dfs(TreeNode* root) {
        if(root == nullptr) {
            return {LLONG_MAX, LLONG_MIN};  // 最小值置为最大，最大值置为最小，保证上面的节点满足BST
        }
        if(root->left == nullptr && root->right == nullptr) {   // 叶子
            return {root->val, root->val};
        }
        
        // 初始化最大最小值
        long long cur_min = root->val, cur_max = root->val;

        // 拿到左右子树的最大最小值
        auto [Lmin, Lmax] = dfs(root->left);
        auto [Rmin, Rmax] = dfs(root->right);

        if(root->val <= Lmax || root->val >= Rmin) {    // 不是BST
            return {LLONG_MIN, LLONG_MAX};      // 返回无效状态, 使得上面的结点都无效
        }
        
        // 更新最大最小值
        cur_min = min(Lmin, (long long)root->val);  // 如果左子树为空,Lmin为LLONG_MAX, 从而cur_min=当前结点
        cur_max = max(Rmax, (long long)root->val);
        
        return {cur_min, cur_max};
    }
    
    bool isValidBST(TreeNode* root) {
        auto [root_min, root_max] = dfs(root);
        return root_max != LLONG_MAX;  // 检查是否有效
    }
};
```



#### [230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/)

> 中序遍历，外部维护step，step==k时得到答案

```C++
class Solution {
public:
    int ans = 0;
    int step = 0;
    void inOrder(TreeNode* root, int k) {
        if(root == nullptr) return;
        inOrder(root->left, k);
        step++;
        if(step == k) ans = root->val;
        inOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};
```



#### [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

> 层次遍历，每次遍历一整层，记录每层最后一个结点

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()) {
            int size = q.size();	// 当前层的元素个数
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(i == size - 1) ans.push_back(front->val);
                if(front->left != nullptr) q.push(front->left);
                if(front->right != nullptr) q.push(front->right);
            }
        }
        return ans;
    }
};
```



#### [114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

> root是按值传递，不能创建新树再赋值！！！修改root不能同时修改函数外部的根指针（例如叫ROOT)

```c++
class Solution {
public:
    vector<TreeNode*> pre;
    void preOrder(TreeNode* root) {
        if(root == nullptr) return;
        pre.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }
    void flatten(TreeNode* root) {  // root是按值传递, 直接修改root没效果
        if(root == nullptr) return;
        preOrder(root);
        // 原地修改
        for(int i = 1; i < pre.size(); i++) {
            TreeNode* last = pre[i-1];      // 第一轮last==root
            TreeNode* cur = pre[i];
            last->left = nullptr;        // 这两行都是原地修改
            last->right = cur;
        }
    }
};
```



#### [105. 前序+中序建树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

> 模板题，要背

```c++
class Solution {
public:
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if(preL > preR) return nullptr;
        int x = preorder[preL];    // 当前根结点
        int numLeft;        // 左子树元素个数
        for(int i = inL; i <= inR; i++) {
            if(inorder[i] == x) {
                numLeft = i - inL;
                break;
            }
        }
        TreeNode* root = new TreeNode;
        root->val = x;
        root->left = create(preorder, inorder, preL + 1, preL + numLeft, inL, inL + numLeft - 1);
        root->right = create(preorder, inorder, preL + numLeft + 1, preR, inL + numLeft+1, inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
```





### 图

#### 200.岛屿数量

> 常规dfs

```c++
class Solution {
private:
    vector<vector<bool>> is_visited{};      // 列表初始化
public:
    bool is_valid(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(!is_valid(grid, row, col) || grid[row][col] == '0' || is_visited[row][col]) {    // 越界或遇到0或访问过就返回
            return;
        }
        is_visited[row][col] = true;
        dfs(grid, row, col+1);
        dfs(grid, row+1, col);
        dfs(grid, row, col-1);
        dfs(grid, row-1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;    //岛屿数量
        int m = grid.size(), n = grid[0].size();
        // 重新设置大小
        is_visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!is_visited[i][j] && grid[i][j] == '1') {      // 未访问过且为1
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;

    }
};
```







### 回溯







### 二分







### 栈







### 堆







### 贪心

#### [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

> 记录目前股票最低值

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int preMin = prices[0];     // 记录之前的股票最低值
        for(int i = 1; i < n; i++) {
            preMin = min(preMin, prices[i]);
            ans = max(ans, prices[i] - preMin);
        }
        return ans;
    }
};
```



#### [55. 跳跃游戏](https://leetcode.cn/problems/jump-game/)

> 记录当前能到达的最远位置, 大于n-1即成功

```C++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for(int i = 0; i < n; i++) {
            if(i <= maxReach) {     // 当前位置可以到达
                maxReach = max(maxReach, i + nums[i]);  // 更新最远位置
            }
            if(maxReach >= n - 1) {
                return true;
            }
        }
        return false;       // 遍历完发现maxReach没有超过n，说明到达不了
    }
};
```



#### [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

> 构建前驱树，从最后一个位置不断跳到最左边的前驱，直到位置0 —— O(n^2)

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int> >pre;     // 存放每个位置的所有前驱
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= nums[i]; j++) {     // 对每个后序
                if(i+j < n) pre[i+j].push_back(i);    // 从i可以到达j
            }
        }
        int ans = 0;
        int cur = n-1;
        while(cur != 0) {
            cur = pre[cur][0];  // 第一个就是最靠左的位置
            ans++;
        }
        return ans;
    }
};
```







> 正向遍历，在当前跳跃能覆盖的范围内，提前找出下一跳能到达的最远位置，当遍历到当前范围边界时执行跳跃。 ——O(n)
>
> 初始化范围[0,0]
>
> 只需要记录当前范围的右边界，到达右边界时更新下个右边界。
>
> ==**这个思路不能记录跳跃路径！！！**==
>
> ![image-20251016153733055](./../../img/typora-user-images/image-20251016153733055.png)

```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cur_end = 0;    // 当前区间右端点
        int next_end = 0;       // 下一个区间右端点
        for(int i = 0; i < n-1; i++) {
            next_end = max(next_end, i + nums[i]);

            if(i == cur_end) {  // 到达当前右端点
                cur_end = next_end; // 更新为下个区间
                ans++;
            }
        }
        return ans;
    }
};
```



#### [763. 划分字母区间](https://leetcode.cn/problems/partition-labels/)







### dp

#### [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
```



#### [118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> pre(1, 1);
        ans.push_back(pre);
        if(numRows == 1) return ans;
        pre.push_back(1);
        ans.push_back(pre);
        if(numRows == 2) return ans;
        for(int i = 3; i <= numRows; i++) {
            vector<int> cur(i, 1);
            for(int j = 1; j < i-1; j++) {   // 从第二个元素开始
                cur[j] = pre[j-1] + pre[j];
            }
            pre = cur;
            ans.push_back(cur);
        }
        return ans;
    }
};
```



#### [198. 打家劫舍](https://leetcode.cn/problems/house-robber/)



```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        // 每次跳2个或3个
        vector<int> dp(n, 0);     
        // 1. dp[i]表示偷完第i个的最高金额（一定偷第i个）
        // dp[i] = nums[i] + max(dp[i-2], dp[i-3])
        // dp[0] = nums[0], dp[1] = nums[1];
        // dp[2] = nums[2] + nums[0];
        // for(int i = 3; i < n; i++) {
        //     dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        // }

        // 2. dp[i]表示前i个能偷到的最高金额（第i个有偷和不偷两种情况）
        // 偷i: dp[i] = dp[i-2] + nunms[i]
        // 不偷i: dp[i] = dp[i-1]
        // dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};
```



#### [279. 完全平方数](https://leetcode.cn/problems/perfect-squares/)

> 完全背包

```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1; i <= 100; i++) {
            nums.push_back(i*i);
        }
        // 在nums数组中找和为n的最少个数
        const int inf = 0x3fffffff;
        vector<vector<int>> dp(101, vector<int>(n+1, inf));   // dp[i][j]=前i个数和为n的最少个数
        // dp[i][0] = 0, dp[0][i] = inf, dp[i][1] = 1
        for(int i = 0; i <= 100; i++) dp[i][0] = 0;
        for(int i = 1; i <= 100; i++) {
            for(int j = 1; j <= n; j++) {
                if(j >= nums[i-1]) {  // 可以选nums
                    dp[i][j] = min(dp[i][j-nums[i-1]] + 1, dp[i-1][j]);
                }else {     // 不能选
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        } 
        return dp[100][n];
    }
};
```





#### [322. 零钱兑换](https://leetcode.cn/problems/coin-change/)

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int inf = 0x3fffffff;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, inf)); // dp[i][j]: 前i个硬币凑j的最少个数
        // dp[i][0] = 0
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j >= coins[i-1]) {   // 可以选i
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                }else {              // 不能选i
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == inf ? -1 : dp[n][amount];
    }
};
```





#### [139. 单词拆分](https://leetcode.cn/problems/word-break/)

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int L = s.length();
        vector<bool> canSplit(L+1, false);  // canSplit[i]=s[0-i-1]能够被组合
        canSplit[0] = true;
        for(int i = 1; i <= L; i++) {
            for(auto word : wordDict) {     // 枚举每个单词
                if(i >= word.length()) {
                    canSplit[i] = canSplit[i-word.length()] && s.substr(i-word.length(), word.length()) == word;
                    if(canSplit[i]) break;  // 可以组合直接跳到下一个字符，防止被覆盖
                }
            }
        }
        return canSplit[L];
    }
};
```



#### [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

> 子序列：不连续

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);   // dp[i]:i结尾的最大长度
        int ans = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {    // 跟前面所有元素对比
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }

            }
        }
        return ans;
    }
};
```



#### [152. 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/)

> 连续子数组
> 需要同时维护最大最小值，因为有负数

```C++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxdp(n, 0); // maxdp[i]: 以nums[i]结尾的最大乘积
        vector<int> mindp(n, 0); // 最小乘积
        mindp[0] = nums[0], maxdp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] < 0) {
                maxdp[i] = max(nums[i], mindp[i-1] * nums[i]);
                mindp[i] = min(nums[i], maxdp[i-1] * nums[i]);
            }else {
                maxdp[i] = max(nums[i], maxdp[i-1] * nums[i]);
                mindp[i] = min(nums[i], mindp[i-1] * nums[i]);
            }
        }
        int ans = nums[0];
        for(int i = 0; i < n; i++) ans = max(ans, maxdp[i]);
        return ans;
    }
};
```



#### [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)

> 转换成0-1背包，相当于n个数找和为sum/2

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        // n个数找和为k = sum/2的
        int k = sum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, false)); // dp[i][j]=前i个数是否存在和为j的组合
        // dp[i][0] = true,dp[0][j] = 0
        for(int i = 0; i <= n; i++) dp[i][0] = true;    // 全都不选就是和为0
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                if(j >= nums[i-1]) { // 有容量才能选
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];  // 选或不选只要有一个满足
                }else { // 没容量，不能选
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][k];
    }
};
```



#### [32. 最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/)

> `dp[i]=以i结尾的最长有效括号长度`
>
> 以左括号结尾不可能有效（dp[i]=0）
>
> 以右括号结尾分两个情况：
>
> 1. 前一个是"(": 直接转移到dp[i-2]. 
> 2. 前一个是")": 找到前一个未匹配的左括号，接着转移到dp[i-dp[i-1]-2]

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n < 2) return false;
        vector<int> dp(n, 0);   // dp[i]=以s[i]结尾的最长有效括号长度
        for(int i = 1; i < n; i++) {
            if(s[i] == ')') {   // 必须以右括号结尾
                if(s[i-1] == '(') {
                    if(i > 1) dp[i] = dp[i-2] + 2;
                    else dp[i] = 2;
                } else if(dp[i-1] > 0){    // 两个右括号
                    int pos = i - dp[i-1] - 1;  // 前一个没匹配的位置
                    if(pos >= 0 && s[pos] == '(') {     // 必须是左括号才能匹配
                        dp[i] = dp[i-1] + 2;
                        if(pos > 0) dp[i] += dp[pos-1];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```





### 多维dp

#### [62. 不同路径](https://leetcode.cn/problems/unique-paths/)

> 太弱智了

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```



#### [64. 最小路径和](https://leetcode.cn/problems/minimum-path-sum/)

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
```



#### [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)

> 子串：连续
>
> 子序列：不连续
>
> 与最长回文子序列的思路完全不同！！！

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));     // dp[i][j]=闭区间s[i, j]是否是回文串
        string ans = "";
        for(int len = 1; len <= n; len++) {     // 枚举子串长度
            for(int i = 0; i <= n-len; i++) {    // 轮流判断，填dp数组
                int j = i + len - 1;
                if(len == 1) dp[i][j] = true;
                else if(len == 2) dp[i][j] = (s[i] == s[j]);

                else if(s[i] == s[j] && dp[i+1][j-1]) {    // 两端相同且中间回文时，才满足
                    dp[i][j] = true;
                }else dp[i][j] = false;
                
                // 记录最长回文串
                if(dp[i][j] && len > ans.length()) ans = s.substr(i, len);
            }
        }
        return ans;
    }
};
```



#### [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // dp[i][j]: s1前i个和s2前j个的最长公共子序列
        // dp[i][0] = 0, dp[0][j] = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) {  // 当前字符相等
                    dp[i][j] = dp[i-1][j-1] + 1;    // 转移到前一个字符 
                }else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
```



#### [72. 编辑距离](https://leetcode.cn/problems/edit-distance/)

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 和LCS（最长公共子序列）的区别：
        // LCS: 保留相同的字符，忽略不同的
        // 编辑距离: 修复不同的字符，跳过相同的
        /* 从头开始思考：（下面假设下标从1开始）
        当 word1[i] == word2[j] 时: 不需要操作，直接跳过
            dp[i, j] = dp[i-1, j-1] + 0

        当 word1[i] != word2[j] 时，我们有三种选择：
            1. 删除 word1[i] -> dp[i-1, j] + 1
                相当于已经把word1前i-1个字符变成了word2前j个字符基础上再删除一个字符
            2. 插入 word2[j] -> dp[i, j-1] + 1
                相当于已经把word1前i个字符变成了word2前j-1个字符基础上再插入一个字符
            3. 直接替换: dp[i-1, j-1] + 1
                相当于已经把word1前i-1个字符变成了word2前j-1个字符基础上再替换一个字符
            此时dp[i, j] = min(上面三种)
        */
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++ ){
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
```



### 技巧







## LC-training

 
