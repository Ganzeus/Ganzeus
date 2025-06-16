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
| vector                                | `<vector> `                                                  |                                              |
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
| string                                | `<string>`                                                   |                                              |
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
|                                       | s = s1 + s2                                                  | **字符串加法（合并）**                       |
|                                       |                                                              |                                              |
| deque                                 | `<deque>`                                                    |                                              |
|                                       | dq.push_front(val), dq.push_back(val)                        | 头尾插入                                     |
|                                       | dq.pop_front(), dq.pop_back()                                | 头尾删除                                     |
|                                       | dq.front(), dq.back()                                        | 头尾访问                                     |
|                                       | 其他操作类似vector                                           |                                              |
|                                       |                                                              |                                              |
|                                       |                                                              |                                              |
| set                                   | `<set>`                                                      |                                              |
| multiset(允许重复)                    | `<set>`                                                      |                                              |
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
| map                                   | `<map>`                                                      |                                              |
| multimap(key可重复)                   | `<map>`                                                      |                                              |
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
|                                       | `priority_queue<int, vector<int>, greater<int>> pq;`         | 小顶堆                                       |
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

### 背包问题

#### 0-1背包

> capacity: 背包体积
>
> w[i]: 第i个物品体积
>
> v[i]: 第i个物品价值
>
> 返回物品总体积不超过背包容量情况下的最大总价值

```c++
int zero_one_backpack(int capacity, int& w, int& v) {
    
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

### 二分查找

```python
# 在递增序列nums的[left，right]区间进行二分，找x返回下标，找不到返回-1
def binarySearch(nums, left, right, target):
    while(left <= right):		# 条件不成立说明找不到
        mid = left + (right-left) // 2
        if nums[mid] < target:		# 中点在目标值左边，往右找（[]
            left = mid + 1
        elif nums[mid] > target:		# 中点在目标值右边，往左找
            right = mid - 1
        else return mid
   	return -1		# 找不到返回-1

def lowerBound(nums, target):	# 返回>=k的最小下标
	l = 0, r = len(nums) - 1
    while(l < r):		# 退出循环时l=r说明已经找到
        mid = l + (r-l) // 2
        if mid < target:	# 中点<目标值时，答案一定在右边
            l = mid + 1
        else r = mid		# 中点大于或等于目标值时，答案要么是此处，要么在左边
    return l

def upperBound(nums, target):	# 返回>k的最小下标
    l = 0, r = len(nums) - 1
    while(l < r):		# 退出循环时l=r说明已经找到
        mid = l + (r-l) // 2
        if mid <= target:	# 中点<=目标值时，答案一定在右边
            l = mid + 1
        else r = mid		# 中点大于目标值时，答案要么是此处，要么在左边
    return l
```



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



#### 二叉树求高度

```c++
int maxDepth(TreeNode* root) {			// 自底向上求高度
    if(root == nullptr) return 0;		// 直到遍历到叶子才会返回
    int maxL = maxDepth(root->left);
    int maxR = maxDepth(root->right);
    return max(maxL, maxR) + 1;			// 不断向上返回当前结点最大深度，直到树根
}
```



### 二叉树层序遍历（BFS)

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

        
def levelOrder(self, root: Optional[TreeNode]) ->List[List[int]];	# 传入根节点，返回一个列表，列表每个元素是每层的所有结点组成的子列表
	if root = None: 
        return []
    ans = []
    q = deque([root])		# deque是python中的双向队列
    while(q):
        vals = []		# 存放当前层的所有结点
        for _ in range(len(q)):		# 遍历次数为当前层的节点个数
            node = q.popleft()
            vals.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        ans.append(vals)
	return ans
            
```



## 灵神视频

#### 209.长度最小的子数组

思考

+ 先判断没有答案的情况：计算sum, <target返回0
+ 枚举子数组长度（1~n), 轮流计算
+ $时间O(n^2), 空间O(1)$
+ 改为二分子数组长度，空间复杂度为$O(n\sqrt n)$



灵神

+ 枚举右端点，收缩左端点
  + 右端点0~n-1,左端点从0开始，都只会一直右移，不会回头，因此共享$O(n)$复杂度——**滑动窗口**
  + 设置一个变量(s)作为当前的总和，而不是每次都从左加到右（右端点右移时s加上右端点元素值，左端点右移时s减去左端点元素值）
  + 右移右端点，直到总和>=target,记录答案，然后开始不断右移左端点，直到总和<target，接着枚举下一个右端点。
+ 时间：$O(n)$
  空间：$O(1)$
+ 为什么左端点只会右移不会回头？
  因为数组元素都为正，如果当前总和大于target，右端点右移后总和一定大于target，因此左端点一定会右移



#### 713.乘积小于K的子数组

思考

+ 暴力：两个for循环枚举所有子数组，每次都计算乘积并判断
+ 双指针：不会

灵神

+ 同向双指针（滑动窗口），设置变量记录当前的累乘
+ 先右移右指针，若当前[l,r]累乘<k，则添加答案:
  [l, r], [l+1, r], ..., [r, r]\(即[r])。（**这些子数组的个数为r-l+1**)
  若当前累乘>=k, 停止移动右指针，开始移动左指针
+ 移动左指针直到[l,r]累乘<k，添加答案后立刻继续移动右指针
+ 要点：**每次添加答案要严格保持右端点不变，这样才不会重复**
+ 时间：$O(n)$
  空间：$O(1)$



#### 3.无重复字符的最长子串

思考

+ 不会判断子串有没有重复字符（c++可以用map，但python不会)
+ 右移右指针，直到发现有重复字符，此时更新答案，并移动左指针直到没有重复字符为止

灵神

+ 方法一样
+ **python判断字符串重复字符————Counter类**
  + 只需要每次记录右端点元素的出现次数（因为重复元素必定是右端点）
+ 时间：$O(n)$
  空间：$O(128)$(字符的所有可能)



#### 162.寻找峰值

思考：

题目要求O(logn)，只能用二分，但是数组不是有序的，该如何判断往左还是往右？没思路

灵神：

红蓝染色法（红表示小，蓝表示大）->**即定义新的大小判定，把无序数组当成有序数组来看**

> 注意二分之前并不知道哪些元素是红，哪些是蓝，染色是在二分查找过程中进行的——即每次查找的区间为未染色的区间

+ 假设要找的**目标元素是某一个峰值（不能确定找的是哪一个，但一定能找到一个）**，定义红色为目标元素左边的元素，蓝色为目标元素或目标右边的元素
+ 只需要比较mid元素和其右边的大小，就可以判断目标峰值在左边还是右边：
  + 对于mid，若右边的元素(mid+1)更大，则**右边一定有峰值！极端情况是右边是递增序列，那么峰值就是最后一个元素**，即mid是某一个峰值的左侧，可以直接往右找，排除左边所有元素（即使左边也有峰值）；
  + 若右边的元素更小，则**左边一定有峰值！极端情况是左边是递减序列，那么峰值就是第一个元素**，即mid要么是峰值，要么在峰值右边，可以直接往左找，排除右边所有元素（即使右边也有峰值）
+ 数组最右边(n-1)一定是蓝色（若nums[n-2] > nums[n-1], n-1就是峰值右边；反之n-1就是峰值）



#### 206.反转链表

> 反转整个链表

思考：
遍历一次记录所有数值，接着重新创建链表（时空都是O(n))

灵神:

+ 原地修改链表——**三个指针pre, cur(当前结点）, next(防止丢失下一个结点)**

+ 每次将cur->next改为pre, 接着pre=cur, cur=next, next=next->next

+ 直到cur=null结束
+ 时间O(n), 空间O(1)



#### 92.反转链表II

> 反转中间部分链表

思考：
保存反转部分的前一个结点，反转结束后将这个结点的next改为已反转部分的第一个结点



灵神：

+ 特殊情况：反转部分没有前一个结点
+ 可以添加一个空结点dummy作为前一个结点
+ 反转链表的循环次数为right-left+1次



#### 25.K个一组翻转链表

> 每k个结点反转一次

思考：
反转n/k次

灵神：

+ 每段反转要修改p0为上一段的第一个结点
+ 不需要计算反转的段数，只需要每次反转判断剩余结点是否>=k



#### 876.链表中间结点

思考：

快慢指针,每次慢的移动一格，快的移动两格，快指针==n或null时结束，等于n是返回slow->next，等于null时返回slow

灵神

+ 不需要链表长度，只需要每次保证快指针的next不为空，就能继续移动
+ 若快指针的next为空，即可说明快指针==n



#### 142.环形链表II

> 判断链表是否有环,输出环的起点

思考：

快慢指针不停移动，指针相同时说明有环 
（如果有环快慢指针一定会相遇）

快指针为null时说明无环

如何找到环的入口？

灵神：

+ 慢指针从相遇点开始，和head指针同步走，一定会相遇，相遇点就是环入口
+ a(入口与head距离) = 若干倍环长 + c(快慢相遇点到入口的距离)



#### 143.重排链表

> 改为0->n->1->n-1->2->...

思考：
只会重建链表，不会原地修改

灵神：

+ 将中点到末尾的链表反转，接着把两个链表合并



#### 237.删除链表中的节点

> 只知道要删除的节点，不知道上一个节点

思考：

不知道前一个结点怎么删除？无法修改前一个节点的next

灵神：

+ 脑筋急转弯
+ **删除下一个节点，保留当前结点**（要先把下一个结点的数值复制到当前节点）



#### 19.删除链表的倒数第N个结点

思考：
双指针，左右指针相差n步，右指针走到头时，删除左指针

灵神：

+ 需要一个dummy node作为头节点，防止删除第一个结点的情况

#### 83.删除排序链表中的重复元素

> 已排序的链表去重

思考：
每个结点判断下一个结点元素值是不是和当前相等，相等就删掉



#### 82.删除排序链表中的重复元素II

> 删除全部重复元素，一个都不保留

思考：
下个结点值与当前相等时，记录当前结点，去重之后再删掉这个结点

灵神：

+ 需要创建dummy node，作为初始当前结点（当前节点一定时不重复的结点）
+ 判断next和next->next是否相同，相同就不断循环删除





100.相同的树

> 判断两个树是否相同

思考：

+ 层序遍历转成数组后直接判断(带null)
+ 同时dfs，只要不同就跳出



灵神：

+ 递归思想，转为子问题：
  + 根节点相同
  + 递归判断左子树相同
  + 递归判断右子树相同

+ 递归边界：有一个为空时返回false，两个都为空时返回true

101.对称二叉树

> 判断二叉树是否轴对称

思考

+ 相当于判断根节点的左右子树是否对称

灵神

+ 对称的判定：对于每个节点，左子树==右子树



110.平衡二叉树

> 判断每个结点左右子树高度差<=1

思考：

+ 递归判断
+ 先计算当前结点高度，再比较左右子树的高度差



#### 199.二叉树的右视图

思考

+ 层序遍历，保存每层的最后一个结点即可

灵神：

+ dfs，传入结点当前深度
+ 优先递归右子树，每层碰到的第一个结点就是本层最右边的结点



#### 98.验证二叉搜索树

> 判断BST

思考：

+ 前序遍历，得到严格递增序列就是BST
+ dfs, 返回子树的最大值，每个结点判断左子树最大值比当前小，右子树最大值比当前大

灵神：

1. 第一种：前序遍历，传入当前结点取值范围，满足取值范围即可
2. 第二种：前序遍历判断严格递增序列
   + 不需要遍历完后保存数组
   + 只需要一个pre变量，保存上一次访问的结点
3. 第三种：dfs，但**必须同时返回子树的最大和最小值**



#### 236.二叉树的最近公共祖先

思考：

+ 先dfs得到每个结点的父亲和每个结点的层数
+ 接着看成链表题，双指针，层数更深的结点先移动，直到层数相同时，一起移动，直到找到相同的father

灵神：

+ dfs过程中找p和q（传入p和q），返回找到的结点（p或q或None），左右子树依次递归
+ 分类讨论dfs的当前节点：
  1. p和q分别在左右两个子树中，那当前结点就是最近公共祖先
  2. 左右子树只有一边找到（即p和q在同一边），那么先遍历到谁，谁就是答案



#### 235.二叉搜索树的最近公共祖先

思考：

+ BST左小右大的性质怎么用？

灵神：

+ 已知p和q的值，只需要将p和q与dfs当前结点值比大小，
  就能知道p和q在左子树还是右子树中，不需要递归查找pq
  + p和q在左右两边，那当前结点就是答案
  + p和q在同一边，只需要递归那一边，继续判断大小即可，先遍历到的就是答案（即当前节点为p或q时返回）



#### 103.二叉树的锯齿形层序遍历

思考：每层先左->右，再右->左

灵神：

+ 只需要设置一个bool变量，层序遍历时每层反转一下
+ bool变量反转时，当前层的结点数组也要翻转后加入答案（python可以直接用切片）



#### 78.子集

> 求出一个集合的所有子集

思考：枚举子集长度(0~n),每次用dfs求出当前长度的所有可能，只往右走不往左走就能保证不重复——$O(n * 2^n)$

灵神：

1. 从输入角度思考：对于每个元素，根据选还是不选构建二叉树，叶子就是所有的子集——$O(n*2^n)$

<img src="./../../img/typora-user-images/image-20250528162302905.png" alt="image-20250528162302905" style="zoom:25%;" />

2. 从答案角度思考：枚举第一个选谁，第二个选谁..., 并且只往右不往左保证不重复，此时每个结点都是答案——$O(n*2^n)$

<img src="./../../img/typora-user-images/image-20250528163736805.png" alt="image-20250528163736805" style="zoom:25%;" />



#### 131.分割回文串

思考：根据每个分割位置是否要切来构建二叉树，得到所有的分割可能，再判断每种可能是不是满足要求

灵神：

+ 对每个分割位置枚举切还是不切，相当于从答案角度思考的子串问题，为确保不重复必须往右枚举



#### 77.组合

> 给定了子集长度求所有子集

思考：直接dfs，比求所有子集简单







## 灵神题单

> [LC-Rating & Training](https://huxulm.github.io/lc-rating/list/dynamic_programming)







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

#### 94.二叉树的中序遍历

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



#### 104.二叉树的最大深度

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



#### 226.翻转二叉树

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



#### 101.对称二叉树

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



#### 543.二叉树的直径

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



#### 102. 二叉树的层序遍历

> queue康复训练

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;  // 检查空树
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {       // 队列非空时执行
            vector<int> tmp;    // 存放本层的所有结点
            int n = q.size();   // 本层结点个数
            while(n--) {        // 一次性弹出本层所有节点
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(tmp);
        }
        return ans;
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




### dp



### 多维dp





### 技巧







## 华为机试题库

| 序号 | 题目                                                         | 通过率 | 难度 | 一刷                | 二刷 |
| ---- | ------------------------------------------------------------ | ------ | ---- | ------------------- | ---- |
| 1    | [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/description/) | 43.60% | 中等 | 看了题解才过(40min) |      |
| 2    | [1190. 反转每对括号间的子串](https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/description/) | 65.10% | 中等 | 没看题解过（1h)     |      |
| 3    | 781. 森林中的兔子                                            | 61.30% | 中等 |                     |      |
| 4    | 739. 每日温度                                                | 68.30% | 中等 |                     |      |
| 5    | 3. 无重复字符的最长子串                                      | 38.30% | 中等 |                     |      |
| 6    | 46. 全排列                                                   | 78.40% | 中等 |                     |      |
| 7    | 475. 供暖器                                                  | 40.20% | 中等 |                     |      |
| 8    | 20. 有效的括号                                               | 44.60% | 简单 |                     |      |
| 9    | 394. 字符串解码                                              | 55.50% | 中等 |                     |      |
| 10   | 179. 最大数                                                  | 41.00% | 中等 |                     |      |
| 11   | LCP 09. 最小跳跃次数                                         | 28.00% | 困难 |                     |      |
| 12   | 135. 分发糖果                                                | 48.70% | 困难 |                     |      |
| 13   | 面试题 17.24. 最大子矩阵                                     | 52.20% | 困难 |                     |      |
| 14   | 1. 两数之和                                                  | 52.20% | 简单 |                     |      |
| 15   | 2. 两数相加                                                  | 41.20% | 中等 |                     |      |
| 16   | 42. 接雨水                                                   | 59.10% | 困难 |                     |      |
| 17   | 22. 括号生成                                                 | 77.30% | 中等 |                     |      |
| 18   | 554. 砖墙                                                    | 50.40% | 中等 |                     |      |
| 19   | 547. 省份数量                                                | 61.90% | 中等 |                     |      |
| 20   | 55. 跳跃游戏                                                 | 43.40% | 中等 |                     |      |
| 21   | 621. 任务调度器                                              | 57.50% | 中等 |                     |      |
| 22   | 1047. 删除字符串中的所有相邻重复项                           | 72.50% | 简单 |                     |      |
| 23   | 514. 自由之路                                                | 49.90% | 困难 |                     |      |
| 24   | 5. 最长回文子串                                              | 36.00% | 中等 |                     |      |
| 25   | 14. 最长公共前缀                                             | 41.50% | 简单 |                     |      |
| 26   | 300. 最长递增子序列                                          | 52.20% | 中等 |                     |      |
| 27   | 56. 合并区间                                                 | 47.50% | 中等 |                     |      |
| 28   | 200. 岛屿数量                                                | 56.40% | 中等 |                     |      |
| 29   | 11. 盛最多水的容器                                           | 62.20% | 中等 |                     |      |
| 30   | 799. 香槟塔                                                  | 41.40% | 中等 |                     |      |
| 31   | 316. 去除重复字母                                            | 47.70% | 中等 |                     |      |
| 32   | 392. 判断子序列                                              | 51.70% | 简单 |                     |      |
| 33   | 85. 最大矩形                                                 | 51.90% | 困难 |                     |      |
| 34   | 206. 反转链表                                                | 72.50% | 简单 |                     |      |
| 35   | 221. 最大正方形                                              | 48.00% | 中等 |                     |      |
| 36   | 32. 最长有效括号                                             | 35.80% | 困难 |                     |      |
| 37   | 62. 不同路径                                                 | 66.60% | 中等 |                     |      |
| 38   | 146. LRU 缓存                                                | 52.40% | 中等 |                     |      |
| 39   | 130. 被围绕的区域                                            | 44.90% | 中等 |                     |      |
| 40   | 679. 24 点游戏                                               | 54.00% | 困难 |                     |      |
| 41   | 70. 爬楼梯                                                   | 53.30% | 简单 |                     |      |
| 42   | 17. 电话号码的字母组合                                       | 57.50% | 中等 |                     |      |
| 43   | 19. 删除链表的倒数第 N 个结点                                | 43.30% | 中等 |                     |      |
| 44   | 15. 三数之和                                                 | 34.20% | 中等 |                     |      |
| 45   | 151. 翻转字符串里的单词                                      | 49.10% | 中等 |                     |      |
| 46   | 957. N 天后的牢房                                            | 36.10% | 中等 |                     |      |
| 47   | 518. 零钱兑换 II                                             | 66.50% | 中等 |                     |      |
| 48   | 139. 单词拆分                                                | 52.00% | 中等 |                     |      |
| 49   | 剑指 Offer 45. 把数组排成最小的数                            | 55.80% | 中等 |                     |      |
| 50   | 410. 分割数组的最大值                                        | 57.00% | 困难 |                     |      |
| 51   | 47. 全排列 II                                                | 64.20% | 中等 |                     |      |
| 52   | 860. 柠檬水找零                                              | 58.60% | 简单 |                     |      |
| 53   | 90. 子集 II                                                  | 63.40% | 中等 |                     |      |
| 54   | 980. 不同路径 III                                            | 73.50% | 困难 |                     |      |
| 55   | 471. 编码最短长度的字符串                                    | 60.40% | 困难 |                     |      |
| 57   | 93. 复原 IP 地址                                             | 54.80% | 中等 |                     |      |
| 58   | 224. 基本计算器                                              | 41.80% | 困难 |                     |      |
| 59   | 4. 寻找两个正序数组的中位数                                  | 41.10% | 困难 |                     |      |
| 60   | 88. 合并两个有序数组                                         | 51.90% | 简单 |                     |      |
| 61   | 692. 前K个高频单词                                           | 57.40% | 中等 |                     |      |
| 62   | 38. 外观数列                                                 | 59.70% | 中等 |                     |      |
| 63   | 64. 最小路径和                                               | 69.00% | 中等 |                     |      |
| 64   | 30. 串联所有单词的子串                                       | 36.30% | 困难 |                     |      |
| 65   | 735. 行星碰撞                                                | 41.10% | 中等 |                     |      |
| 66   | 165. 比较版本号                                              | 52.10% | 中等 |                     |      |
| 67   | 354. 俄罗斯套娃信封问题                                      | 45.90% | 困难 |                     |      |
| 68   | 1160. 拼写单词                                               | 68.70% | 简单 |                     |      |
| 69   | 678. 有效的括号字符串                                        | 38.60% | 中等 |                     |      |
| 70   | 102. 二叉树的层序遍历                                        | 64.20% | 中等 |                     |      |
| 71   | 287. 寻找重复数                                              | 65.50% | 中等 |                     |      |
| 72   | 16. 最接近的三数之和                                         | 45.80% | 中等 |                     |      |
| 73   | 264. 丑数 II                                                 | 58.10% | 中等 |                     |      |
| 74   | 1293. 网格中的最短路径                                       | 36.50% | 困难 |                     |      |
| 75   | 剑指 Offer 38. 字符串的排列                                  | 58.00% | 中等 |                     |      |
| 76   | 40. 组合总和 II                                              | 61.50% | 中等 |                     |      |
| 77   | 746. 使用最小花费爬楼梯                                      | 59.90% | 简单 |                     |      |
| 78   | 974. 和可被 K 整除的子数组                                   | 46.70% | 中等 |                     |      |
| 79   | 685. 冗余连接 II                                             | 42.80% | 困难 |                     |      |
| 80   | 260. 只出现一次的数字 III                                    | 74.00% | 中等 |                     |      |
| 81   | 37. 解数独                                                   | 67.00% | 困难 |                     |      |
| 82   | 72. 编辑距离                                                 | 61.60% | 困难 |                     |      |
| 83   | 695. 岛屿的最大面积                                          | 66.80% | 中等 |                     |      |
| 84   | 36. 有效的数独                                               | 63.80% | 中等 |                     |      |
| 85   | 84. 柱状图中最大的矩形                                       | 43.50% | 困难 |                     |      |
| 86   | 148. 排序链表                                                | 66.60% | 中等 |                     |      |
| 87   | 199. 二叉树的右视图                                          | 65.30% | 中等 |                     |      |
| 88   | 121. 买卖股票的最佳时机                                      | 57.40% | 简单 |                     |      |
| 89   | 322. 零钱兑换                                                | 44.80% | 中等 |                     |      |
| 90   | 741. 摘樱桃                                                  | 37.10% | 困难 |                     |      |
| 91   | 214. 最短回文串                                              | 37.50% | 困难 |                     |      |
| 92   | 406. 根据身高重建队列                                        | 74.00% | 中等 |                     |      |
| 93   | 1162. 地图分析                                               | 47.10% | 中等 |                     |      |
| 94   | 402. 移掉 K 位数字                                           | 32.70% | 中等 |                     |      |
| 95   | 343. 整数拆分                                                | 61.00% | 中等 |                     |      |
| 96   | 617. 合并二叉树                                              | 78.70% | 简单 |                     |      |
| 97   | 387. 字符串中的第一个唯一字符                                | 53.90% | 简单 |                     |      |
| 98   | 76. 最小覆盖子串                                             | 43.10% | 困难 |                     |      |
| 99   | 34. 在排序数组中查找元素的第一个和最后一个位置               | 42.30% | 中等 |                     |      |
| 100  | 29. 两数相除                                                 | 22.00% | 中等 |                     |      |
| 101  | 105. 从前序与中序遍历序列构造二叉树                          | 70.70% | 中等 |                     |      |
| 102  | 451. 根据字符出现频率排序                                    | 71.20% | 中等 |                     |      |
| 103  | 1109. 航班预订统计                                           | 58.50% | 中等 |                     |      |
| 104  | 166. 分数到小数                                              | 33.10% | 中等 |                     |      |
| 105  | 278. 第一个错误的版本                                        | 45.20% | 简单 |                     |      |
| 106  | 207. 课程表                                                  | 54.10% | 中等 |                     |      |
| 107  | 875. 爱吃香蕉的珂珂                                          | 48.20% | 中等 |                     |      |
| 108  | 134. 加油站                                                  | 56.60% | 中等 |                     |      |
| 109  | 剑指 Offer 22. 链表中倒数第k个节点                           | 79.90% | 简单 |                     |      |
| 110  | 611. 有效三角形的个数                                        | 53.30% | 中等 |                     |      |
| 111  | 剑指 Offer 58 - II. 左旋转字符串                             | 85.90% | 简单 |                     |      |
| 112  | 面试题 02.05. 链表求和                                       | 46.70% | 中等 |                     |      |
| 113  | 面试题 01.06. 字符串压缩                                     | 47.10% | 简单 |                     |      |
| 114  | 剑指 Offer 59 - I. 滑动窗口的最大值                          | 44.50% | 困难 |                     |      |
| 115  | 155. 最小栈                                                  | 57.60% | 简单 |                     |      |
| 116  | 剑指 Offer 03. 数组中重复的数字                              | 67.90% | 简单 |                     |      |
| 117  | 面试题 08.11. 硬币                                           | 49.50% | 中等 |                     |      |
| 118  | 剑指 Offer 50. 第一个只出现一次的字符                        | 61.80% | 简单 |                     |      |
| 119  | 994. 腐烂的橘子                                              | 51.10% | 中等 |                     |      |
| 120  | 剑指 Offer 10- II. 青蛙跳台阶问题                            | 44.70% | 简单 |                     |      |
| 121  | 剑指 Offer 13. 机器人的运动范围                              | 52.90% | 中等 |                     |      |
| 122  | 1004. 最大连续1的个数 III                                    | 59.60% | 中等 |                     |      |
| 123  | 1494. 并行课程 II                                            | 37.30% | 困难 |                     |      |
| 124  | 1386. 安排电影院座位                                         | 31.80% | 中等 |                     |      |
| 125  | 349. 两个数组的交集                                          | 73.90% | 简单 |                     |      |
| 126  | 397. 整数替换                                                | 43.20% | 中等 |                     |      |
| 127  | 63. 不同路径 II                                              | 39.60% | 中等 |                     |      |
| 128  | 371. 两整数之和                                              | 61.30% | 中等 |                     |      |
| 129  | 373. 查找和最小的K对数字                                     | 40.70% | 中等 |                     |      |
| 130  | 面试题 17.21. 直方图的水量                                   | 63.60% | 困难 |                     |      |
| 131  | 847. 访问所有节点的最短路径                                  | 67.90% | 困难 |                     |      |
| 132  | 面试题 04.01. 节点间通路                                     | 53.10% | 中等 |                     |      |
| 133  | 剑指 Offer 05. 替换空格                                      | 76.00% | 简单 |                     |      |
| 134  | 面试题 16.19. 水域大小                                       | 61.50% | 中等 |                     |      |
| 135  | 1723. 完成所有工作的最短时间                                 | 50.50% | 困难 |                     |      |
| 136  | 874. 模拟行走机器人                                          | 42.00% | 中等 |                     |      |
| 137  | 263. 丑数                                                    | 51.40% | 简单 |                     |      |
| 138  | 934. 最短的桥                                                | 47.10% | 中等 |                     |      |
| 139  | 1497. 检查数组对是否可以被 k 整除                            | 39.40% | 中等 |                     |      |
| 140  | 1755. 最接近目标值的子序列和                                 | 42.00% | 困难 |                     |      |
| 141  | 1100. 长度为 K 的无重复字符子串                              | 69.90% | 中等 |                     |      |
| 142  | 7. 整数反转                                                  | 35.10% | 中等 |                     |      |
| 143  | 43. 字符串相乘                                               | 45.00% | 中等 |                     |      |
| 144  | 203. 移除链表元素                                            | 52.30% | 简单 |                     |      |
| 145  | 242. 有效的字母异位词                                        | 64.80% | 简单 |                     |      |
| 146  | 13. 罗马数字转整数                                           | 63.00% | 简单 |                     |      |
| 147  | 41. 缺失的第一个正数                                         | 42.00% | 困难 |                     |      |
| 148  | 58. 最后一个单词的长度                                       | 38.60% | 简单 |                     |      |
| 149  | 198. 打家劫舍                                                | 52.10% | 中等 |                     |      |
| 150  | 235. 二叉搜索树的最近公共祖先                                | 66.80% | 简单 |                     |      |
| 151  | 279. 完全平方数                                              | 63.70% | 中等 |                     |      |
| 152  | 403. 青蛙过河                                                | 45.50% | 困难 |                     |      |
| 153  | 415. 字符串相加                                              | 54.20% | 简单 |                     |      |
| 154  | 442. 数组中重复的数据                                        | 69.80% | 中等 |                     |      |
| 155  | 593. 有效的正方形                                            | 44.30% | 中等 |                     |      |
| 156  | 94. 二叉树的中序遍历                                         | 75.60% | 简单 |                     |      |
| 157  | 227. 基本计算器 II                                           | 43.70% | 中等 |                     |      |
| 158  | 647. 回文子串                                                | 65.90% | 中等 |                     |      |
| 159  | 204. 计数质数                                                | 37.70% | 中等 |                     |      |
| 160  | 48. 旋转图像                                                 | 73.70% | 中等 |                     |      |
| 161  | 171. Excel 表列序号                                          | 71.70% | 简单 |                     |      |
| 162  | 301. 删除无效的括号                                          | 54.80% | 困难 |                     |      |
| 163  | 208. 实现 Trie (前缀树)                                      | 71.90% | 中等 |                     |      |
| 164  | 1013. 将数组分成和相等的三个部分                             | 39.40% | 简单 |                     |      |
| 165  | 445. 两数相加 II                                             | 59.10% | 中等 |                     |      |
| 166  | 350. 两个数组的交集 II                                       | 55.30% | 简单 |                     |      |
| 167  | 870. 优势洗牌                                                | 43.90% | 中等 |                     |      |
| 168  | 77. 组合                                                     | 76.90% | 中等 |                     |      |
| 169  | 539. 最小时间差                                              | 60.10% | 中等 |                     |      |
| 170  | 881. 救生艇                                                  | 53.80% | 中等 |                     |      |
| 171  | 98. 验证二叉搜索树                                           | 35.30% | 中等 |                     |      |
| 172  | 75. 颜色分类                                                 | 60.00% | 中等 |                     |      |
| 173  | 210. 课程表 II                                               | 54.70% | 中等 |                     |      |
| 174  | 976. 三角形的最大周长                                        | 59.80% | 简单 |                     |      |
| 175  | 850. 矩形面积 II                                             | 44.90% | 困难 |                     |      |
| 176  | 605. 种花问题                                                | 33.20% | 简单 |                     |      |
| 177  | 78. 子集                                                     | 80.20% | 中等 |                     |      |
| 178  | 560. 和为 K 的子数组                                         | 44.60% | 中等 |                     |      |
| 179  | 234. 回文链表                                                | 50.30% | 简单 |                     |      |
| 180  | 6. Z 字形变换                                                | 51.00% | 中等 |                     |      |
| 181  | 44. 通配符匹配                                               | 32.90% | 困难 |                     |      |
| 182  | 233. 数字 1 的个数                                           | 47.70% | 困难 |                     |      |
| 183  | 1044. 最长重复子串                                           | 34.80% | 困难 |                     |      |
| 184  | 820. 单词的压缩编码                                          | 51.00% | 中等 |                     |      |
| 185  | 315. 计算右侧小于当前元素的个数                              | 41.80% | 困难 |                     |      |
| 186  | 172. 阶乘后的零                                              | 44.60% | 中等 |                     |      |
| 187  | 39. 组合总和                                                 | 72.70% | 中等 |                     |      |
| 188  | 79. 单词搜索                                                 | 46.00% | 中等 |                     |      |
| 189  | 160. 相交链表                                                | 61.90% | 简单 |                     |      |
| 190  | 223. 矩形面积                                                | 52.60% | 中等 |                     |      |
| 191  | 338. 比特位计数                                              | 78.70% | 简单 |                     |      |
| 192  | 468. 验证IP地址                                              | 25.40% | 中等 |                     |      |
| 193  | 136. 只出现一次的数字                                        | 71.90% | 简单 |                     |      |
| 194  | 142. 环形链表 II                                             | 55.50% | 中等 |                     |      |
| 195  | 169. 多数元素                                                | 66.50% | 简单 |                     |      |
| 196  | 188. 买卖股票的最佳时机 IV                                   | 39.90% | 困难 |                     |      |
| 197  | 231. 2 的幂                                                  | 50.50% | 简单 |                     |      |
| 198  | 459. 重复的子字符串                                          | 50.90% | 简单 |                     |      |
| 199  | 652. 寻找重复的子树                                          | 57.10% | 中等 |                     |      |
| 200  | 97. 交错字符串                                               | 45.40% | 中等 |                     |      |
