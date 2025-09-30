**PAT刷题笔记**by以禾

****

#### 题目给的每个案例都要仔细研究！！！

#### 想到一种能够实现的方法，先写下来再说（即使复杂度很高）！！！先提交一遍，若超时，则再进行优化！！

#### 注意题目要求的数据类型，没说是整数的就用double存(A1070)



## 注意点

#### 全局变量（`int`、`bool`、`string`、`double`)、数组初始化为0

#### BST中序是递增序列！！！（非常有用）

#### 输入整数时可以带上正负号，会自动将正负号转换为对应整数

#### 结构体不会自动初始化给定的值，需要另外单独初始化！！！

#### 读入字符用string！！！不要用char，否则会读入空格

+ `stoi`将字符串转整数

#### 浮点数向上舍入为整数：只需要+0.5在转int

#### upper_bound和lower_bound用法

+ upper_bound和lower_bound都**返回迭代器（数组指针）**

```C++
int a[maxn];
int i = upper_bound(a, a + maxn, x) - a;	// 在[a, a + maxn)中寻找第一个>x的位置
int j = lower_bound(a, a + maxn, x) - a;	// 在[a, a + maxn)中寻找第一个>=x的位置
```

#### STL函数

##### 查找最大元素

```C++
vector<int> a;
int max = *max_element(a.begin(), a.end());
string s;
char max = *max_element(s.begin(), s.end());
```



****

## 排序

#### vector内元素排序：

```C++
bool cmp(int a, int b) { return a > b};	// 递增排序
vector<int> v;
sort(v.begin(), v.end(), cmp);
```

#### 二维vector数组排序：

```C++
vector<vector<int> > v;
sort(v.begin(), v.end());
```

例：

<img src="..\..\img\typora-user-images\image-20211215213821535.png" alt="image-20211215213821535" style="zoom: 50%;" />



#### 排好序后记录排名（重要！！！！！！！！！！！！！！）

+ 相同分数排名相同。

  例如**排名1, 2, 3, 3, 5不应算作1, 2, 3, 3, 4**

```C++
struct Node {
    int score;  // 分数（按此标准排名）
    int rank;   // 排名（排好序后记录）
};
vector<Node> students;
int main() {
    sort(students.begin(), students.end());	// 排序（具体怎么排看题目要求）
    // 记录排名
    for(int i = 0; i < students.size(); i++) {
        if(i >= 1 && students[i].score == students[i-1].score) {    // 分数与前一个相同，排名也应相同
            students[i].rank = students[i-1].rank;
        }else{
            students[i].rank = i+1;
        }
    }
    return 0;
}
```

#### 以字符串为索引时，可以用map将字符串映射为int下标

#### 复杂的排序思路

##### 1. 查询某一个排序元素在某一区间内的排序结果（输出年龄在某一区间的财富值排名A1055）

​	**==可以先排名，输出时再判断年龄是否符合要求！！==**

​	复杂度++做法：每次都找到年龄在给定区间的人进行排序

​	**进一步降低复杂度**：根据题目要求的输出量，可以直接把某一年龄的最多可能输出个数放到新数组里，减少最后遍历个数，输出时直接根据新数组。（**能够显著降低复杂度！！**）



****

## 错误原因

#### 格式错误

+ 字符串多输出了空格
+ **只有一个测试点出现莫名其妙的格式错误：可能需要多输出一行空行（A1101)**

#### 段错误

+ 递归没写终止条件
+ for循环中 `i++` 写成 `i--`
+ 嵌套循环变量冲突
+ 下标越界
+ 邻接矩阵只初始化了一部分

#### 答案错误

+ 实在找不到原因可能因为题目数据超过`int`范围，试试用`long long`.(A1058)




****

## 字符串相关
#### 读入字符串
读入一行字符串，==包含空格==，**以回车结束**：

```C++
  string str;
  getline(cin, str);
```
读入字符串，**以空格结束**：`cin>>str;`
或：

```C++
  char s[50];
  scanf("%s",s);
```
若`getline(cin,str)`前有一行其他输入，必须要先用`getchar()`==接收上一行的回车==，否则`getline()`会读入回车

string类型转字符数组：`str.c_str()`

`getchar()`有返回值，不能空用；

#### 字符串转换

##### 字符串转换成数字

```C++
string str;
getline(cin,str);
int num = 0;	//存放转换后的数字
for(int i = 0; i < str.length(); i++){
	num = num*10 + (str[i]-'0');
}
```

##### string转换函数

<img src="..\..\img\\typora-user-images\image-20220303154343022.png" alt="image-20220303154343022" style="zoom:50%;" /> 

##### 数字等其他类型转字符串

```C++
string str = to_string(100);
```

##### 字符串转字符数组

```C++
str.c_str();
```

##### 字符数组转各种数据类型（重要！！！！！！！）

+ sscanf和sprintf
+ sscanf从左往右(**字符数组转其他**）；sprintf从右往左（**其他转字符数组**）。

##### 例：读入字符串，检查是否是实数。若是实数，检查小数点后是否不超过两位

```C++
int main() {
    char a[50];
    double tmp;
    scanf("%s", a);
    sscanf(a, "%lf", &tmp);  // 将a以double格式存入tmp，若格式不匹配则不修改tmp
    sprintf(b, "%.2f", tmp);  // 将tmp以2位小数格式存入字符数组b
    bool flag = true;	// flag = true表明是小数点后小于两位的实数
    for(int i = 0; i < strlen(a); i++){
        if(a[i] != b[i]) flag = false;  // 如果a和b不严格相等，说明a小数点后位数超过2个
    }
    cout << flag << endl;
    return 0;
}
```



#### 提取一行中以一个空格分隔的若干字符串：

使用`cin`读入单个字符串，然后用`getchar()`接收这个字符串后面的字符。如果是空格，继续读入；如果是换行符，结束读入；

```C++
string str;
vector<string> s;	//string数组
char c;		//判断回车的字符
  while(cin>>str){
  	s.push_back(str);
  	c = getchar();
  	if(c == '\n') break;
  }
```

#### 读入一行数字，求各位的和（==n < 1e100==)

```C++
ll sum = 0;
while(1) {	//一直循环，直到换行符结束
    char c = getchar();
    if(c == '\n') break;	// 读入的是换行符，结束循环
    sum += (c - '0');
}
// cout << sum;
```

#### **字符串或整数输出时一定要注意开头是否要补0！！！**

####  C++string 转 C语言字符数组：

+ string类中的`c_str()`： 生成一个==const char*== 指针，指向一空字符终止的数组。
+ 由于返回const类型，因此调用此函数后字符串内容不能修改。要想得到非const，可采用如下`strcpy`方法：

```C++
int main() {
    
    string s = "1234";
    char* c = new char[20];
    strcpy(c, s.c_str());	
    cout << c << endl;
    c[2] = 'a';			// c指向的字符数组可修改
    cout << c << endl;
    
   return 0;
}

```

#### 一个字符转字符串（字符串添加一个字符）

```C++
char c = '1';
string s = " ";		// 该字符串为一个空格
s[0] = c;	// 将空格改成想要添加的字符
ans.insert(0, s);	// 在下标0处添加字符串
```

#### 字符串去除前导0

```C++
while(str[0] == '0' && str.size() != 0){
    str.erase(ans.begin());
}
```



#### 反转字符串

```C++
string rev(string s) {
    reverse(s.begin(), s.end());
    return s; 
}
```

+ 判断回文串

  ```c++
  bool isPalin(string s) {
      if(s == rev(s)) return true;
      return false;
  }
  ```

  

## 链表

#### 解题步骤

1. 定义静态链表

   ```C++
   struct Node {
       int address;    // 结点地址
       int data;       // 结点数据域
       int next;       // 指针域
       XXX         // 结点的某个性质（视题目而定）
   }node[maxn];
   ```

2. 程序的开始，对静态链表初始化。

   下面假设XXX表示结点是否在链表上，初始化为0

   ```C++
   for(int i = 0; i < maxn; i++) {
       node[i].XXX = 0;
   }
   ```

3. 根据题目所给的首结点地址，遍历整个链表。同时对XXX标记和统计有效结点个数

   ```C++
   int p = begin, count = 0;
   while(p != -1) {    // -1代表链表结束
       XXX = 1;
       count++;    // 记录链表有效结点个数
       p = node[p].next;
   }
   ```

4. 排序，将有效结点移至静态链表前面。同时根据题目要求进行二级排序。

   ```C++
   bool cmp(Node a, Node b) {
       if(a.XXX == -1 || b.XXX == -1) {    // 只要有一个无效结点，就把它放到数组后面
           return a.XXX > b.XXX;   // 无效结点的XXX更小
       }else {
           // 第二级排序
       }
   }
   ```




#### 要注意特判题目数据全为无效结点的情况！！！





## 图论
+ Dijkstra外层循环n(顶点数)次不能用`while(n--)`,只能用`for(int i = 0; i < n; i++)`！！！ _(调试五小时的教训)_

​		**原因**：==内层循环需要用到顶点数n==

+ **邻接矩阵一定要记得初始化！！！**（调试2h）
+ **看见level用BFS**
+ **BFS 判断`if(!inq[v])`括号内记得`inq[v] = true`,否则程序会死机无输出！！！**

+ ==**题目给的图有可能不连通，要先用DFS判断连通性！！！！！！！**==(A1126)

****

## 树

#### 后序+中序建二叉树

<img src="..\..\img\typora-user-images\image-20211214144725375.png" alt="image-20211214144725375" style="zoom: 50%;" />

```C++
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

+ 要输出结点权值递减的树根到叶子的序列，可以在==读入结点时就对孩子结点递减排序==。（A1053 Path of Equal Weight)



#### 统计最深层的叶子个数

+ 由于不需要考虑结点的点权，因此直接用`vector<int> children[maxn]`来存储
+ 设置叶子个数`num`和`maxLevel`，均初始化为0

**以DFS为例**：

+ 递归边界：当当前结点id的子结点个数为0，表示到达叶结点。此时判断层数是否大于最大深度`maxLevel`.若大于，更新`maxLevel`**==并重置`num`为1==**;若不大于，判断是否等于`maxLevel`：若等于，`num++`. 判断结束返回。
+ 递归式：对当前结点id的所有子结点进行递归

```C++
int num = 0;		// 最深叶子个数
int maxLevel = 0;	// 最大深度
vector<int> children[maxn];

void DFS(int id, int level) {
    if(children[id].size() == 0) {
        if(level > maxLevel) {	// 此结点层数更大，更新最大层数，并值num为1
            maxLevel = level;
            num = 1;
        }
        else if(level == maxLevel) num++;	// 层数与最大层数一致，num++
        return;
    }
    for(int i = 0; i < children[id].size(); i++) {	// 对所有子结点递归
        DFS(children[id][i], level + 1);
    }
}
```



#### 找到树中结点个数最大的一层，输出个数和层号

+ 由于不需要考虑结点的点权，因此直接用`vector<int> children[maxn]`来存储

+ 用一个map记录每层结点个数

  ```C++
  map<int, int> mp;	(层数，个数)
  ```

+ 使用DFS，参数为当前结点和层数，每次递归将当前层号的结点个数+1。

```C++
map<int, int> mp;   // （层数，个数）
void DFS(int id, int level) {
    mp[level]++;
    for(int i = 0; i < children[id].size(); i++) {
        DFS(children[id][i], level + 1);
    }
}

int main() {
    DFS(1, 1);	// 根结点为1，层数为1
   	int maxnum = 0, ansLevel;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if(it->second > maxnum){	// 找到结点最多的一层
            maxnum = it->second;	// 记录结点数量
            ansLevel = it->first;	// 记录层号
        }
    }
    cout << maxnum << " " << ansLevel << endl;
}
```



#### 判断是否是完全二叉树

1. 柳神

<img src="..\..\img\typora-user-images\image-20220223232427998.png" alt="image-20220223232427998" style="zoom:33%;" />

```C++
int n, maxOrder = -1;    
int last;   // 树的最后一个结点
void dfs(int root, int index) {  // 层序遍历,同时与对应完全二叉树序号比较
    if(index > maxOrder) {
        maxOrder = index;
        last = root;
    }
    if(node[root].lchild != -1) dfs(node[root].lchild, index*2);
    if(node[root].rchild != -1) dfs(node[root].rchild, index*2 + 1);
}

dfs(root, 1);
if(maxOrder == n) {
    cout << "YES " << last << endl;
}else cout << "NO " << root << endl;
```

2. 晴神

   <img src="..\..\img\typora-user-images\image-20220227154023019.png" alt="image-20220227154023019" style="zoom: 67%;" /> 

   <img src="..\..\img\typora-user-images\image-20220227154059064.png" alt="image-20220227154059064" style="zoom: 50%;" /> 

   

   ```C++
   bool BFS(int root, int& last, int n) {  // n为非空结点个数
       queue<int> q;
       q.push(root);
       while(n) {  // 只要n不为0，即还没有访问完全部非空结点
           int front = q.front();
           q.pop();
           if(front == -1) return false;   // 遍历到空结点，一定不是完全二叉树
           n--;    // 不是空结点，n--
           last = front;   // 每次遍历到非空结点就更新last
           q.push(node[front].lchild); // 左右结点入队（包括空结点）
           q.push(node[front].rchild);    
       }
       return true;    // 连续访问完所有非空结点，即为完全二叉树
   }
   ```




#### BST建树只需要知道前序接着一个个插入就行！！！



## 英语

| 单词               | 翻译        |
| ------------------ | ----------- |
| radix              | 进制        |
| Quadratic Probing  | 二次探测法  |
| Palindromic Number | 回文数      |
| Polynomial         | 多项式      |
| Parenthesis        | 圆括号 `()` |
| interval           | 区间        |
| invert             | 反转        |

