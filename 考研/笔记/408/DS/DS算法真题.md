#### 2009

![image-20221003154013996](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154013996.png)

##### 草稿

1. 先遍历一遍链表得到总长度n
   再遍历一遍，直到第n-k+1个结点，即为倒数第k个结点

2. 步骤：

   第一轮遍历：n存放链表长度，初始为0，每经过一个结点+1，
   p存放当前结点指针，p->link==null时表示当前是最后一个结点

   第二轮遍历：num存放查找次数，初始为n-k+1，每经过一个结点-1，
   减为0时即找到；若遍历到最后一个结点时，num!=0,说明查找失败

3. ```C++
   int FindK(node* list, int k) {
       // 第一轮
       int n = 0;
       node* p = list;
       while(p->next != null) { n++; p = p -> next;}
       int num = n-k+1;
       p = list;
       // 第二轮
       while(p->next != null) { 
           num--;
           if(num == 0) {cout << p -> data; return 1;}
           p = p->next;
       }
       return 0;
   }
   ```



##### 订正

+ two-pointers: 同一个链表中两个指针间隔k，再同时后移直到末尾，前面的指针就是所求结点



#### 2010

![image-20221003154029002](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154029002.png)

##### 草稿

1. 每次循环左移一个位置，循环p次

2. ```C++
   void LL(int& a[], int p) {
       while(p--) {	// 循环p次
           int tmp = a[0];	// 暂存第一个元素
           for(int i = 1; i < n; i++) {
               a[i-1] = a[i];	// 1~n-1元素全部左移
           }
           a[n-1]=tmp;	// a[0]移到n-1位置
       }
   }
   ```

3. 每次循环时间复杂度为$O(n)$,p次循环，总复杂度为$O(np)$，

   而0<p<n，因此时间复杂度为$o(n^2)$

   只用了一个额外空间，于是空间复杂度$O(1)$



##### 订正

1. 暴力：另建一个等长数组B，将p到n-1和0到p依次填入
2. 翻转数组：先将前n-p个元素翻转，再将后p和元素翻转，最后将整个数组翻转



#### 2011

![image-20221003154039830](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154039830.png)

##### 草稿

1. 合并两个升序序列（下标1~n），最后直接访问下标$\frac{n-1}{2}+1$号元素即中位数

2. ```C++
   int merge(int a[], int b[], int L) { // 两数组下标都是1~L
       int temp[10000], index = 0;
       int i = 1, j = 1;
       while(i <= L && j <= L) {	// 两个数组都没到头
           if(a[i] <= b[j]) temp[index++] = a[i++];
           else temp[index++] = b[j++];
       }
       while(i <= L) temp[index++] = a[i++];	// b数组到头，就把a数组全部放进temp
       while(j <= L) temp[index++] = a[j++];
       return temp[n-1/2 + 1];
   }
   ```

3. 时间复杂度：$O(n)$
   空间复杂度：$O(n)$

##### 订正

1. 归并只需要归到一半即可（只需要输出合并后数组的下标n元素）
2. 更优解：不需要temp数组，只要设置计数器，比较到第n个元素时直接输出
   空间复杂度优化到$O(1)$



#### 2012

![image-20221003154049620](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154049620.png)

##### 草稿

1. 设置两个结点栈存放两个单词的每个结点，每遍历一个结点就将结点入栈，遍历完后栈中的内容自顶向下就是单词所有结点的倒序；接着用两个栈顶指针分别指向两个栈顶，对比两个栈顶元素，相同则出栈；对比下一个元素，直到两栈顶结点的data域不同，上一个出栈的结点就是所求。

2. ```C++
   struct Node {
       int data;
       Node* next;
   };
   Node suffix(Node str1, Node str2) {
       stack<Node> s1, s2;
       Node p = str1->next;	// p指向str1的第一个字母
       while(p->next != null) {s1.push(p); p = p->next;}
       p = str2->next;		// str2的第一个字母
       while(p->next != null) {s2.push(p); p = p->next;}
       // 下面比较两个栈顶
       Node ans;	// 存放上一个出栈元素
       while(!s1.empty() && !s2.empty()) {	// 其中一个栈空时退出
           Node top1 = s1.top(), top2 = s2.top();
           if(top1->data == top2->data) {	// 栈顶元素相同，表明是共同后缀的一部分
               ans = top1;		// 暂存当前结点
           }else return ans;	// 两栈顶不相同时直接返回上一次存放的结点
           s1.pop();	// 访问完栈顶后出栈
           s2.pop();	
       }
       // 其中一个栈空时，共同后缀已存放在ans中，直接返回
       return ans;
   }
   ```

3. $O(n)$

##### 订正

+ **不需要判断后续结点！！！！！（元素已经存放在了链表中，而链表元素唯一，则遇到了相同元素，后继必相同）**
+ 优化：不需要用栈存，**直接用数组存！！！**，数组保存结点地址，有了地址就可以直接访问内容
+ **遍历一次得到两链表的长度，再直接将长的部分剪掉，变成两个等长链表，此时就能挨个比较，直到链表元素相同即为所求**

#### 2013

![image-20221003154059057](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154059057.png)

##### 草稿

1. 排序+二分

2. ```C++
   void quickSort(int a[], int st, int ed) {
       st = 0, ed = n;
   }
   ```

3. 排序$O(nlogn)$，二分$O(logn)$

   空间$O(1)$

##### 订正

1. 上述算法错误（不知道二分谁）
2. 考试可以用哈希！！！**数组大小直接设置为n**，统计每个数出现的次数



#### 2014

![image-20221003154107817](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154107817.png)

##### 草稿

1. 层序遍历，每层计算各结点的层次*权值并累加，遍历完所有结点后就得到WPL

2. ```C++
   struct node {
       int weight;
       node* left, * right;
   };
   node* root = new node;
   ```

3. ```C++
   ```







#### 2015

![image-20221003154120391](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154120391.png)

##### 草稿

1. 设置一个很大的bool类型的hash数组，hash[i]==true表示元素i出现过；遍历链表时查看结点的data是否出现过，
   若未出现过则设置hash[i]=true；出现过则删除当前结点，遍历一遍链表就能处理完毕

2. ```C++
   struct Node {
   	int data;
       Node* next;
   };
   ```



##### 订正

1. 数据结构定义模板：

   ```C++
   typedef struct Node {
       int data;
       struct Node* next;
   }Node;
   ```

2. 题目说了$data\le n$，直接暗示哈希，hash数组大小就设为n



#### 2016

![image-20221003154130315](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154130315.png)



##### 草稿

1. 将数组排序，前n/2个元素即为A1，后n-n/2个元素即为A2
2. 

#### 2017

![image-20221003154138821](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154138821.png)

##### 草稿

1. 中序递归遍历，根据左右子树是否非空添加括号：

   1. 左右都空：直接输出data
   2. 左空右不空：输出`(+data+右`
   3. 左右都不空：输出`(左+data+右)`
   4. 左不空右空：没有这种情况

2. ```C++
   void DFS(BTree* node) {
       if(node->left == node->right == null) cout << node->data;
       if(node->left == null && node->right != null) {
           cout << "(" + DFS(node->right);
       }
       if(node->left != null && node->right != null) {
           cout << "(";
   		DFS(node->left);
           cout << data;
           DFS(node->right);
           cout << ")";
       }
       return;
   }
   ```



#### 2018

![image-20221003154148538](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154148538.png)

##### 草稿

1. 建一个尽可能大的bool类型的数组hash，hash[i]==true，表示出现过；
   遍历一遍数组，将出现过的数字都设为true；
   接着遍历一遍hash数组，输出第一个false下标

##### 订正

1. 哈希即为最优解
2. **数组长度可以直接设为n！！！**（这题应该设为n+2）



#### 2019

![image-20221003154155790](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154155790.png)

##### 草稿

1. 将最后一个结点插到第2、4、....位置，插入n/2次



##### 订正

1. 最优解：将后半段逆置（利用头插法），接着两个链表轮流插入，构造新链表

#### 2020

![image-20221003154202218](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154202218.png)

##### 草稿

1. 不会

##### 订正

+ 暴力：三个数组循环枚举——$O(n^3)$
+ 优化：只枚举第一个数组，后面两个数组用two-pointers
+ 最优解：**易知距离D为三个元素中最大的两个距离的2倍**，因此只需要找到差距最小的一组
  3-pointers：每次只将最小的那个指针后移，如果移动之后比之前的D要大，说明已经找到答案

#### 2021

![image-20221003154209510](D:\Git\GitRepos\Ganzeus\img\typora-user-images\image-20221003154209510.png)

##### 草稿

1. 遍历邻接矩阵，统计度为奇数的顶点个数，个数为不大于2的偶数时，存在EL路径。
   邻接矩阵中两点不邻接记为-1，顶点的度为每行的非-1的个数



#### 2022

