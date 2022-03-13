郭炜Python mooc学习笔记by以禾

## 基础语法

### 一、Python初探

#####交换a和b的值：`a, b = b, a`

```python
a, b = "he", 12
print(a, b)

a, b = b, a     # 交换a和b的值
print(a, b)     # 12 he

c, a, b = a, b, a
print(a, b, c)  # he 12 12
```

####字符串：用单引号、双引号或三引号括起来

```python
x = "I said: 'hello'"
print(x)        # >>I said: 'hello'
print('I said "hello"')     # >>I said: 'hello'
print('''I said: 'he said "hello"'.''') # >>I said: 'he said "hello"'.

print("this \
is \
good")   # >>this is good（字符串太长时，可以分行写）
```

##### 三双引号字符串中可以包含换行符、制表符以及其他特殊字符

```python
para_str = """多行字符串可以使用制表符
TAB(\t).
也可以使用换行符[\n]
<HTML><HEAD><TITLE>
Friends CGT Demo</TITLE><HEAD>
<BODY></BODY>
</HTML>"""
print(para_str)
```

##### 字符串的下标

有n个字符的字符串，其中每个字符都是长为1的字符串：

​	从左往右依次编号为： 0，1，2，...，n-1

​	从右往左依次编号为：-1，-2，...，-n

```python
a = "ABCD"
print(a[-1])    # >>D
print(a[0])     # >>A
print(a[2])     # >>C
```

**==字符串不可修改==**：

```python
a = "ABCD"
a[2] = 'k';		# 错，字符串中的字符不可修改
```

##### 用in, not in 判断子串

```python
a = "Hello"
b = "Python"
print("el" in a)        # >>True
print("th" not in b)    # >>False
print("lot" in a)       # >>False
c = a + b
print(a in c)           # >>True
```

##### 字符串和数的转换

```python
a = 15
b = "12"
print(a + b)        # 错误
print(a + int(b))   # >>27
print(str(a) + b)   # >>1512
print(eval("a + 3"))    # eval("a+3")计算表达式 a + 3 的值, >>18
```

####Python数据类型

| 标识符  | 含义   | 例子                    |
| ------- | ------ | ----------------------- |
| int     | 整数   | 123456                  |
| float   | 小数   | 3.2                     |
| complex | 复数   | 1+2j                    |
| str     | 字符串 | "hello"                 |
| list    | 列表   | [1, 2, 'ok', 4.3]       |
| tuple   | 元组   | (1, 2, 'ok', 4.3)       |
| bool    | 布尔   | True/False              |
| dict    | 字典   | {"tom": 20, "jack": 30} |
| set     | 集合   | {"tom", 18, 73}         |



#### 输出语句print

1. 连续输出多项，以空格分隔，然后换行

```python
print(x, y, z, ...)
```

2. 连续输出多项，以空格分隔，==不换行==（以end中的内容结尾）

```python
print(x, y, z, ..., end="")
```



#### 输入语句input

格式：`x = input(y)`

+ x是变量
+ y是字符串，或任何值为字符串的表达式
+ 语句功能：**输出y**，并等待输入。==敲回车后==输入的字符串被赋值给x

****

####列表初步

+ 列表可以有0到任意多个元素，元素可以通过下标访问

```python
empty = []
list1 = ['Google', 'Runoob', 1997, 2000]
list2 = [1, 2, 3, 4, 5, 6, 7]
print("list1[0]: " + list1[0])         # >>list1[0]: Google
list1[2] = 2001         # 修改了列表中下标为的元素
a = 2
print("更新后的第三个元素为；", list1[a])  # 变量也能做下标
```

##### 用in判断列表中是否包含某个元素

```python
lst = [1, 2, 3, "4", 5]
print(4 in lst, 3 in lst, "4" in lst)   # >>False True True
```

##### 实例：输入两个整数求和

```python
s = input()
numbers = s.split()
print(int(numbers[0]) + int(numbers[1]))
```

+ ==split()== : 将字符串以***空格、制表符、换行符*** 分割形成若干子串，返回一个列表

  ```python
  print("34\t\t45\n'7'".split())    # >>['34', '45', '7']
  print("abc def 1234 567".split()[2][1])     # >>2 (子串1234下标2的字符)
  ```


****

### 二、基本运算、条件分支和输出格式

####算术运算符

| Python支持以下算数运算 |                                      |
| ---------------------- | ------------------------------------ |
| +                      | 加法                                 |
| -                      | 减法、取相反数                       |
| *                      | 乘法                                 |
| /                      | 除法，结果是小数。即使能整除也是小数 |
| %                      | 取模（求余数）                       |
| //                     | 求商，结果是整数                     |
| **                     | 求幂                                 |

```python
print(10/2)     # >>5.0
print(15/4)     # >>3.75
print(15//4)    # >>3
print(15%4)     # >>3
print(3.4/2.2)  # >>1.5454545454545452
print(3.4//2.2) # >>1.0
print(2**3)     # >>8
print(-9//4)    # >> -3 (往数轴左边取整）
```



==有小数的算术表达式，结果一定是小数==

```python
z = 10.0 - 10
print(z)            # >>0.0
z = 7.5 - 2.5
print(z)            # >>5.0
print(2 + 0 * 4.5)  # >>2.0
print(2 + 10 / 5)   # >>4.0
```



####关系运算符和bool类型

##### 六种关系运算符用于数值的比较：

1. ==
2. !=
3. &gt;
4. &lt;
5. &gt;=
6. &lt;=

##### 比较结果为bool类型：True/False

在python中，True\==1（==只有1与True相等==）, False\==0（==只有0与False相等==）

```python
a = 4
print(2 < a < 6 < 8)    # >>True
print(2 < a == 4 < 6)   # >>True
b = a < 6
print(b)                # >>True
print(b == 1)           # >>True
print(b == 2)          # >>False
```

##### 关系运算符也能比较字符串

+ 按字典序，大小写相关

```python
a = "abc"
b = "abc"
print(a == b)           # >>True
print(a < "Abc")        # >>False
print(a < "abcd")       # >>True
```



####逻辑运算符和逻辑表达式

逻辑运算符有三种：**and  or  not**, 操作结果为**True** 或 **False**

==非0的数、非空的字符串、非空列表等等，都***相当***于True==，但只有***1\==True 和 0\==False*** 为真;

```python
print(5 and True)         # >>True  (5与True相当，但不相等）
print(5 or False)         # >>5
print(1 == True or False) # >>True
print(not 2)              # >>False
print(not 0)              # >>True
print(not "abc")          # >>False
print(not "")             # >>True
print(not [])             # >>True
print([] == False)        # False	(只有0==False为True)
```

#####优先级：not > and > or



#### 各种运算符的优先级： 

+ 算术运算符 > 关系运算符 > 逻辑运算符



****

####条件分支语句

```python
if 逻辑表达式1:
	语句块1
elif 逻辑表达式2:
    语句块2
... 多组elif
else:
    语句块n
```

+ **最后一个else没有逻辑表达式**

+ **可以不写最后一个else**
+ ***==缩进的前一行末尾必须有冒号"："==***



##### 条件分支语句的缩进：

python程序的语句前不能加空格或制表符，除非：

1. 它在if语句的某个"语句块"里面
2. 在for、while等语句的语句块里面
3. 在函数体里面
4. . . . . . .

**if语句的语句块，每条语句左边必须缩进,且需要对齐**

```python
if int(input()) == 5:
    print("a", end = "")
    print("b")
```

##### if语句嵌套：

```python
a = int(input())
if a > 0:
    if a % 2:
        print("odd")
    else:
        print("even")
else:
    print("a < 0")
```



####字符串切片

**若s是个字符串，则：**

+ s[x:y] 是s从==下标x到下标y的左边那个字符==构成的子串（切片）

```python
print("12345"[1:3])     # >>23
a = "abcdef"           
print(a[2:-1])          # >>cde
print(a[0:6])           # >>abcdef
```



#### if语句实例：温度转换程序

```python
tmpStr = input("请输入带有符号的温度值：")
if tmpStr[-1] in ['f', 'F']:        # 若输入华氏温度
    C = ((float(tmpStr[0:-1])) - 32) / 1.8
    print("转换后的温度是" + str(C) + "C")
elif tmpStr[-1] in "Cc":            # 若输入摄氏温度
    F = eval(tmpStr[0:-1]) * 1.8 + 32
    print("转换后的温度是" + str(F) + "F")
else:
    print("输入格式错误")
```

#### 嵌套if实例：

请写一个程序，该程序输入一个年份，根据该年份是否是建国整十周年、建党整十周年以及是否是闰年给出不同的输出

```python
year = int(input())
if year <= 0:
    print("Illegal year")
else:
    print("Legal year")
    if year > 1949 and (year-1949) % 10 == 0:	# 建国整十周年
        print("Lucky year.")
    elif year > 1921 and not((year - 1921)%10):	# 建党整十周年
        print("Good year.")
    elif year % 4 == 0 and year % 100 or year % 400 == 0:	# 闰年：被4且不被100整除 or 被400整除
        print("Leap year.")
    else:
        print("Common year.")
```

****

####输出格式控制

| 字符串中的格式控制符 | ==格式控制符只能出现在字符串中！！==                         |
| -------------------- | ------------------------------------------------------------ |
| %s                   | 表示此处要输出一个字符串                                     |
| %d                   | 表示此处要输出一个整数                                       |
| %f                   | 表示此处要输出一个小数                                       |
| %.nf                 | 表示此处要输出一个小数，保留小数点后n位。四舍六入，五可能入可能舍 |

```python
h = 1.746
print("My name is %s, I am %.2fm tall." % ("tom", h)) # >>My name is tom, I am 1.75m tall.
print("My age is %d." % 18)     # 输出一项不需要加括号 >>My age is 18.
print("%d%s" % (18, "hello"))           # >>18hello
print("%.2f, %.2f" % (5.225, 5.325))    # >>5.22, 5.24
```

****

### 三、循环语句

####for循环

```python
for <variable> in <sequence>:
    <statements 1>
else:
    <statements 2>
```

**依次对sequence中的每个值，执行<statements 1> 然后再执行 <statements 2>.** ==*通常不需要else部分*==

**sequence 可以是range(...)，也可以是字符串、列表、元组、字典、集合。**

`range(5)`:表示[0, 5)

```python
for i in range(0, 10, 3):       # 步长为3
    print(i, end=" ")			# >>0 3 6 9

for i in range(-10, -100, -30):
    print(i, end=" ")           # >> -10 -40 -70 

for i in range(2, 2):			# [2, 2)
    print(i)					# 无输出
```

##### len(): 求字符串长度， 列表、元组、集合、字典元素个数

```python
print(len("abc"))		# >>3
```

##### for循环遍历

```python
a = ["Google", "Baidu", "IBM", "Taobao", "QQ"]
for i in a:
    print(i, end=" ")	 # >>Google Baidu IBM Taobao QQ

for letter in "Taobao":
    print(letter, end=" ")	# >>T a o b a o 
```

##### break、continue语句

```python
sites = ["Google", "Baidu", "IBM", "Taobao"]
for site in sites:
    if site == "IBM":
        print("OK")
        break       # 跳出循环, 不会执行else语句
    if site == "Baidu":
        continue	# 直接跳到下次循环
    print("site: " + site)
else:
    print("No break")
print("Done!")
```

##### 连续输出26个字母：

```python
for i in range(26):
    print(chr(ord("a") + i), end="")	# >>abcdefghijklmnopqrstuvwxyz
```

+ ==ord(x)==: 求字符x的编码
+ ==chr(x):== 求编码为x的字符



##### 多重循环

例题：给定正整数n 和m, 在1至n这n个数中，取出两个不同的数x, y，使得x<y且x+y是m的因子。

要求输出的数对里面，x不重复，且y尽可能小。输出这些取法。

```python
lst = input().split()
n, m = int(lst[0]), int(lst[1])
for i in range(1, n):       # 取第一个数，共n-1种取法
    for j in range(i+1, n+1):   # 第二个数比第一个数大
        if m % (i + j) == 0:    
            print(i, j)
            break   # 后面的j无需再取，直接换下个i
```



****

####while循环

```python
while 逻辑表达式 exp:
    语句组1
else:
    语句组2
```

（1）判断exp是否为真.若为真，转（2）；否则转（3）

（2）执行语句组1，回到 （1）

（3）执行语句组2

（4）继续往下执行 ......



#####用while语句和异常处理进行输入

> 输入若干行（未给定），每行若干整数，求所有整数的最大值

```python
s = input()
lst = s.split()
maxV = int(lst[0])
try:
    while True:
        lst = s.split()
        for x in lst:
            maxV = max(maxV, int(x))
        s = input()     # ctrl + D 表示输入结束
except:			# 遇到任何异常都会进入此处
    pass    # pass语句什么都不做
print(maxV)
```

#### python没有do-while循环！



****

#### 循环例题

##### 例1：求斐波那契额数列第k项

```python
k = int(input())
if k == 1 or k == 2:
    print(1)
else:
    a1 = a2 = 1
    for i in range(k-2):
        a1, a2 = a2, a1+a2      # a1, a2 依次修改为后一项， 一次循环后a2为第三项，则k-2次循环后a2为第k项
    print(a2)
```

##### 例2：求1!+2!+3!+...+n!

```python
n = int(input())
faci = 1
sum = 0
for i in range(1, n+1):
    faci *= i			# 算完i的阶乘后不需要保存，直接放到下一轮继续算
    sum += faci
print(sum)
```

##### 例3：求不大于n(n>=2)的全部质数

笨方法：

```python
n = int(input())
for i in range(2, n+1):
    flag = 0            # flag == 0 表质数
    for j in range(2, i):
        if i % j == 0:
            flag = 1
            break
    if not flag:
        print(i)
```

好方法：

```python
n = int(input())
print(2)
for i in range(3, n+1, 2):  # 步长为2，跳过偶数
    flag = 0
    for j in range(3, i, 2):
        if i % j == 0:
            flag = 1
            break
        if j * j > i:       # j > sqrt(i) 时无需再试
            break
    if not flag:
        print(i)
```



##### 例4：给定整数L, R，求区间[L,R]中的整数中2出现的次数

整数方法：

```python
s = input().split()
l, r = int(s[0]), int(s[1])
cnt = 0
for i in range(l, r + 1):
    while i:
        digit = i % 10
        if digit == 2:
            cnt += 1
        i //= 10
print(cnt)
```

字符串方法:

```python
s = input().split()
l, r = int(s[0]), int(s[1])
cnt = 0
for i in range(l, r + 1):
    i_str = str(i)
    for digit in i_str:
        if digit == '2':
            cnt += 1
print(cnt)
```

****

### 四、函数和递归

#### 函数

##### 定义函数形参不需要写类型

##### return语句的功能

​	==结束函数的执行==，并将返回值作为结果返回。返回值是常量、变量或复杂的表达式均可。

​	如果函数不需要返回值，直接写return。

```python
def factorial(n):
    if n < 2:
        return 1
    else:
        return n * factorial(n-1)


print(factorial(4))		# >>24
```



#### 递归

+ 递归要学会从反方向考虑！！！

##### 例题：上台阶

有n级台阶，每步可以走一级或两级，问有多少不同走法

+ ==斐波那契==

```python
def f(n):
    if n == 1 or n == 0:
        return 1
    return f(n-1) + f(n-2)
```

##### 例题：汉诺塔

将A中所有盘子移动到C，以B做中转，不能大盘子放在小盘子上。

思路：==不用考虑怎么移，让递归函数自己移，只需要考虑递归边界以及如何将任务分解==

```python
def Hanoi(n, src, mid, dest):
    # 递归边界
    if n == 1: # 剩下最后一个盘子
        print(src + '->' + dest)
        return
    # 任务分解
    Hanoi(n-1, src, dest, mid)  # 现将上面 n-1个盘子移到中间
    print(src + "->" + dest)    # 再将剩下的最大的盘子移到dest（此时src已空，问题规模已经变小）
    Hanoi(n-1, mid, src, dest)  # 最后将中间n-1个盘子移到dest,以src中转
```



##### 例题：雪花曲线

雪花曲线的递归定义：

1. 长为size，方向为x的0阶雪花曲线：是方向x上一根长为size的线段
2. 长为size，方向为x的n阶雪花曲线，由以下四部分一次拼接组成：
   1. 长为size/3，方向为x的n-1阶雪花曲线
   2. 长为size/3，方向为x+60的n-1阶雪花曲线
   3. 长为size/3，方向为x-60的n-1阶雪花曲线
   4. 长为size/3，方向为x的n-1阶雪花曲线



```python
import turtle


def snow(n, size):      # n是阶数，size是长度  从当前起点出发，在当前方向画一个长度为 size, 阶为n的雪花曲线
    if n == 0:
        turtle.fd(size)     # 笔沿着当前方向前进size
    else:
        for angle in [0, 60, -120, 60]:     # 对于列表中每个元素angle
            turtle.left(angle)      # 笔左转angle度, turtle.lt(angle)也可
            snow(n-1, size/3)
```



画三段3阶雪花曲线

```python
# 画三段3阶雪花曲线
turtle.setup(800, 800)
# 窗口默认位于屏幕正中间，宽高为 800*800像素，窗口中央坐标 (0, 0)
# 初始笔的前进方向是0度。正东方是 0度，正北是 90度
turtle.speed(1000)
turtle.penup()      # 抬起笔
turtle.goto(-200, 100)  # 将笔移动到 (-200, 100)位置
turtle.pendown()    # 放下笔（开始画）
turtle.pensize(2)   # 笔的粗度是2
level = 3           # 3阶
snow(level, 400)    # 绘制长度为 400，阶为3的雪花曲线，方向水平
turtle.right(120)   # 右拐 120度
snow(level, 400)
turtle.right(120)
snow(level, 400)
turtle.done()       # 保持绘图窗口
```

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220112193848288.png" alt="image-20220112193848288" style="zoom:50%;" />

****

#### Python数据类型

| 基本数据类型 | 组合数据类型 |       |
| ------------ | ------------ | ----- |
| int          | 字符串       | str   |
| float        | 元组         | tuple |
| complex      | 列表         | list  |
|              | 字典         | dict  |
|              | 集合         | set   |



##### isinstance函数

> isinstance(x, y) 函数查询数据x是否是类型y

```python
a = "1233"
print(isinstance(a, str))       # >>True
print(isinstance(a, int))       # >>False

b = (1, 3, )
print(isinstance(b, tuple))     # >>True
```

##### len函数

> 求组合数据类型的元素个数（长度）

```python
print(len([1, 2, 3, 4]))            # >>4   列表元素个数
print(len((1, 2, 3)))               # >>3   元组长度
print(len({1, 2, 3}))               # >>3   集合元素个数
print(len({'tom': 2, 'jack': 3}))   # >>2   字典元素个数
```



#### python变量的指针本质

+ ==python中所有可赋值的东西，即左值，都是指针==
+ 对变量进行赋值的本质，就是让指针指向该变量

##### is和==的区别

+ a is b 为True说明a和b地址及内容相同
+ a == b 为True说明a和b内容相同，不一定指向相同地址
+ ==a=b会使a与b指向同一个地方==,即会使`a is b`为True

```python
a = [1, 2, 3, 4]
b = [1, 2, 3, 4]
print(a == b)       # >>True
print(a is b)       # >>False
a = b   
print(a is b)       # >>True
a[2] = 'ok'
print(b)            # >>[1, 2, 'ok', 4]
```

+ 对于==int, float, complex, str, tuple==类型的变量a，b，只需关注`a==b`是否成立，关注`a is b`无意义。因为这些数据本身具有唯一性，不会更改，因此不会产生a指向的东西更改而b跟着变的情况
+ 对于==list, dict, set==类型的变量，数据本身会改变，改变a的内容，b内容也会变



****

### 五、字符串

#### 字符串切片高级

a[x:y:z]表示，从a[x]取到a[y]（a[y]不算），==每z个字符取一个==，最后拼起来。

z为负数代表倒着取

x, y 可以省略。x, y全省略表示从头取到尾或从尾取到头

```python
print("1234"[3:1:-1])           # >>43
print("abcde"[::-1])            # >>edcba
print("12345678"[1:7:2])        # >>246
print("12345678"[7:1:-2])       # >>864
```



#### 字符串的split函数详解

`s.split(x)`

用字符串==x做分隔符==分隔字符串s，得到分隔后的**列表**

***两个相邻分隔符之间会被分隔出一个空串***



```python
a = "12..34.5346...a"
print(a.split(".."))    # >>['12', '34.5346', '.a']
print(a.split("."))     # >>['12', '', '34', '5346', '', '', 'a']
print(a.split("34"))    # >>['12..', '.5', '6...a']
```

#####正则表达式re包中的split

```python
import re
a = 'Beautiful, is; better*than\nugly'
print(re.split(';| |,|\*|\n', a))     # 分隔符用 | 隔开, 即 ';', ' ', '*','\n'
# >>['Beautiful', '', 'is', '', 'better', 'than', 'ugly']
```



#### 字符串常用函数

| 字符串函数                      | 功能                             | 用法                                                         |
| ------------------------------- | -------------------------------- | ------------------------------------------------------------ |
| count                           | 求子串出现次数                   | `s = 'thisAAbb AA'  s.count('AA')`    >>2(AA出现两次)        |
| len                             | 字符串长度                       | `s = '1234'  len(s)`     >>4                                 |
| upper/lower                     | 转大小写(==不修改字符串本身==)   | `s = 'abc'    print(s.upper())`    >>ABC                     |
| replace                         | 替换                             | `s = "1234abc567abc12" `                                                                                                      `b = s.replace("abc", "FGHI")`    b由把s里==所有==abc换成FGHI而得 |
| isdigit()、islower()、isupper() | 判断是否是数、是否全是小写等     |                                                              |
| startswith(), endwith()         | 判断字符串是否以某子串开头、结尾 |                                                              |

+ find , rfind , index , rindex

  在字符串中查找子串，返回找到的位置（下标）。找不到的话，find返回-1，index引发异常。

  ```python
  s = "1234abc567abc12"
  print(s.find("ab"))     # >>4
  print(s.rfind("ab"))    # >>10
  # find 从头开始找，rfind从尾巴开始找。返回第一个找到的位置
  try:
      s.index("afb")  # 找不到"afb",引发异常
  except Exception as e:
      print(e)        # substring not found
  ```

  指定起点：

  ```python
  s = "1234abc567abc12"
  print(s.find("12", 4))		# >>13	指定从下标4处开始查找
  ```

+ strip() 返回取出头尾**空白字符（空格、'\r'、'\n'）**后的字符串

+ lstrip() 返回除去头部（左端）空白字符后的字符串

+ rstrip() 返回除去尾部（右端）空白字符后的字符串

  ```python
  print(" \t12 34 \n ".strip())       # >>12 34
  print(" \t12 34 5".lstrip())        # >>12 34 5
  ```

+ strip(s), lstrip(s), rstrip(s) 返回除去==两端、左端、右端==**在s中出现的字符**后的字符串

  ```python
  print("takeab \n".strip("ba \n"))       # >>take
  print("cd\t12 34 5".lstrip("d\tc"))     # >>12 34 5
  ```



#### 字符串编码

> 字符串的编码在内存中的编码时unicode的，虽然写入文件时可能是gbk或utf-8的

```python
print(ord("a"))     # >>97
print(ord("好"))     # >>22920
print(chr(22900))   # >>奴
print(chr(97))      # >>a
```



<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220115001040025.png" alt="image-20220115001040025" style="zoom:50%;" />



****

### 六、元组

#### 概述

#####一个元组由数个逗号分隔的值组成，前后可加括号

#####元组不能修改，即不可增删元素，不可对元素赋值，不可修改元素顺序（如排序）

```python
t = 12345, 54321, 'hello!'		# >>t是一个元组
print(t[0])     # >>12345
print(t)        # >>(12345, 54321, 'hello!')
u = t, [1, 2, 3, 4, 5]      
print(u)        # >>((12345, 54321, 'hello!'), [1, 2, 3, 4, 5])
print(u[0][1])  # >>54321
print(u[1][2])  # >>3
u[1][2] = 4     
print(u[1])     # >>[1, 2, 4, 4, 5] 
t[0] = 88888    # 运行错误，元组的元素不能赋值
```

#####单元素的元组

```python
empty = ()      # 空元组
singleton = 'hello',    # 注意末尾的逗号，如果没有，就不是元组而是字符串了
print(len(empty))       # >>0
print(len(singleton))   # >>1
x = ('hello',)          # 无逗号则x为字符串
print(x)                # >>('hello',)
```

#####元组和字符串一样，可以==用下标访问==，可以==切片==

#####可以对元组进行连接组合

```python
tup1 = (12, 34.56)
tup2 = ('abc', 'xyz')

# 创建一个新元组
tup3 = tup1 + tup2
print(tup3)         # >>(12, 34.56, 'abc', 'xyz')
tup3 += (10, 20)    # 新建了一个元组, tup3指向该新元组
print(tup3)         # >>(12, 34.56, 'abc', 'xyz', 10, 20)
```

#####元组运算和迭代

```python
x = (1, 2, 3) * 3
print(x)                # >>(1, 2, 3, 1, 2, 3, 1, 2, 3)
print(3 in (1, 2, 3))   # >>True
for i in (1, 2, 3):
    print(i, end='')    # >>123
```

#####元组赋值

```python
x = (1, 2, 3)
b = x       # b与 x都指向(1, 2, 3)
print(b is x)   # >>True
x += (100,)     # 新建了一个元组，x指向该新元组(原来的元组不能修改！)
print(x)        # >>(1, 2, 3, 100)
print(b)        # >>(1, 2, 3)
```



##### 元组比大小

+ 两个元组比大小，就是逐个元素比大小，直到分出胜负
+ 如果有两个对应元素不可比大小，则出现runtime error

```python
print((1, 'a', 12) < (1, 'b', 7))       # >>True
print((1, 'a') < (1, 'a', 13))          # >>True
print((2, 'a') > (1, 'b', 13))          # >>True
print((2, 'a') < ('ab', 'b', 13))       # runtime error
```



#### 用元组（或列表）取代复杂分支结构

##### 例题：万年历

​	已知2012年1月25日是星期三，编写程序，输入用” 年 月 日“ 表示的2012.1.25之后的日期，输出该日期是星期几

+ 思路：2012年1月22日是星期天。算出给定日期是从该天起过了x天，然后输出x%7

```python
def isleap(year):
    if (year % 4 == 0 and year % 100) or year % 400 == 0:
        return True

monthday = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
weekday = 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'
while(1):
    s = input().split()
    year = int(s[0])
    month = int(s[1])
    day = int(s[2])
    passdays = 0
    for i in range(2012, year):     # 先算经过的整年天数(不算当前年）
        if isleap(i):
            passdays += 366
        else:
            passdays += 365
    if isleap(year):
        monthday[1] = 29
    for i in range(1, month):       # 再算经过的整月天数(不算当前月)
        passdays += monthday[i-1]
    passdays += day - 22
    print(passdays % 7)
```

+ ***下面的方法可以更快算出过掉的整年的总天数***

```python
passdays = 0
passdays += (year-2012) * 365
if(year > 2012):
    passdays += (year-1-2012) // 4 + 1  # 补上闰年多的一天（不算当前年）
passdays -= (year-1-2012) // 100        # 扣掉把100整数倍的年份都当做闰年而多加的天数
passdays += (year-1-2012) // 400        # 加上400整数倍的闰年
```



##### 例题：把一行字符串中所有大小写字母互换

```python
string = input()
newstr = ""
for i in string:
    if ord(i) in range(97, 97+32):		# 小写字母
        newstr += chr(ord(i) - 32)
    elif ord(i) in range(65, 65+32):	# 大写字母
        newstr += chr(ord(i) + 32)
    else:		# 不是字母则不变
        newstr += i
print(newstr)
```



****

### 七、列表

#### 基础操作

##### 列表可以增删元素，列表的元素可以修改，列表元素可以是任何类型

```python
empty = []      # 空表
list1 = ["PKU", 'Huawei', 1997, 2000]
list1[1] = 100  # 列表元素可以赋值
print(list1)    # >>['PKU', 100, 1997, 2000]
del list1[2]    # 删除元素
print(list1)    # >>['PKU', 100, 2000]
list1 += [100, 100]     # 添加另一列表的元素100和110，在list1原地添加，没有新建一个列表
list1.append(200)       # 添加元素 200，append用于添加单个元素
print(list1)    # >>['PKU', 100, 2000, 100, 100, 200]
list1.append(['ok', '123'])     # 添加单个元素
print(list1)    # >>['PKU', 100, 2000, 100, 100, 200, ['ok', '123']]
a = ['a', 'b', 'c']
n = [a, 2, 3]
x = [a, n]      # a若变，x也变
a[0] = 1
print(x)        # >>[[1, 'b', 'c'], [[1, 'b', 'c'], 2, 3]]
print(x[0])     # >>[1, 'b', 'c']
print(x[0][1])  # >>b
```

##### 列表相加

```python
a = [1, 2, 3, 4]
b = [5, 6]
c = a + b       # >>c为新的列表，与a,b无关
print(c)        # >>[1, 2, 3, 4, 5, 6]
a[0] = 100
print(c)        # >>[1, 2, 3, 4, 5, 6]
```

##### 对于列表来说，==a += b 和 a = a + b 不同==

```python
b = a = [1, 2]
a += [3]        # >>b和a指向同一列表，在a末尾添加元素，b也受影响
print(a, b)     # >>[1, 2, 3] [1, 2, 3]
a = a + [4, 5]  # 对a重新赋值，不影响b
print(a)        # >>[1, 2, 3, 4, 5]
print(b)        # >>[1, 2, 3]
```

##### 列表乘法

+ 将列表==中的元素==乘若干遍组成==一个==新的列表

```python
print([True] * 3)
a = [1, 2]

```

##### 列表的切片

+ 列表切片返回新的列表，用法和字符串切片相同

```python
a = [1, 2, 3, 4]
b = a[1:3]
print(b)        # >>[2, 3]
b[0] = 100
print(b)        # >>[100, 3]
print(a)        # >>[1, 2, 3, 4]
print(a[::-1])  # >>[4, 3, 2, 1]
print([1, 2, 3, 4, 5, 6][1:5:2])    # >>[2, 4]
```



####列表的排序

##### 朴素排序算法（选择排序）

```python
def selectionSort(lst):
    n = len(lst)
    for i in range(0, n):
        for j in range(i, n):
            if lst[j] < lst[i]:  # 找到小的就交换
                lst[i], lst[j] = lst[j], lst[i]


lst = [1, 12, 4, 56, 6, 2]
selectionSort(lst)
print(lst)  # >>[1, 2, 4, 6, 12, 56]
```

##### python自带排序函数

+ `a.sort()`可以对列表a从小到大排序
+ `sorted(a)`返回a经过从小到大排序后的新列表，==不改变a的顺序==

```python
a = [1, 12, 4, 56, 6, 2]
a.sort()
print(a)        # >>[1, 2, 4, 6, 12, 56]
a = [1, 12, 4, 56, 6, 2]
b = sorted(a)           # b为a排好序的列表，a不变
print(b)        # >>[1, 2, 4, 6, 12, 56]
print(a)        # >>[1, 12, 4, 56, 6, 2]
a.sort(reverse=True)    # 降序
print(a)        # >>[56, 12, 6, 4, 2, 1]
```

+ 列表元素为元组：

```python
students = [('John', 'A', 15),  # 姓名，成绩，年龄
            ('Mike', 'C', 19),
            ('Mike', 'B', 12),
            ('Mike', 'C', 18),
            ('Bom', 'D', 10)]
students.sort()  # 先按姓名排，再按成绩排，最后按年龄排
print(students)  # >>[('Bom', 'D', 10), ('John', 'A', 15), ('Mike', 'B', 12), ('Mike', 'C', 18), ('Mike', 'C', 19)]
```

+ 自定义比较函数

```python
def myKey(x):  # 按个位数排序
    return x % 10


a = [25, 7, 16, 33, 4, 1, 2]
a.sort(key=myKey)
print(a)  # >>[1, 2, 33, 4, 25, 16, 7]

b = sorted("This is a test string from Andrew".split(), key=str.lower)  # 不区分大小写排序
print(b)  # >>['a', 'Andrew', 'from', 'is', 'string', 'test', 'This']
```



####复杂列表排序

##### lambda表达式：

`lambda x: x[2]`表示一个函数，参数是x，返回值是x[2]

```python
k = lambda x, y: x + y		# k是一个函数 
print(k(4, 5))  # >>9
```

##### 用不同关键字排序

```python
students = [('John', 'A', 15),  # 姓名，成绩，年龄
            ('Mike', 'C', 19),
            ('Mike', 'B', 12),
            ('Mike', 'C', 18),
            ('Bom', 'D', 10)]
students.sort(key=lambda x: x[2])  # 按年龄排序
print(students)  # >>[('Bom', 'D', 10), ('Mike', 'B', 12), ('John', 'A', 15), ('Mike', 'C', 18), ('Mike', 'C', 19)]
students.sort(key=lambda x: x[0])  # 按姓名排序
print(students)  # >>[('Bom', 'D', 10), ('John', 'A', 15), ('Mike', 'B', 12), ('Mike', 'C', 18), ('Mike', 'C', 19)]
```

##### 多级排序

```python
def f(x):
    return (-x[2], x[1], x[0])  # 先x[2]降序，后x[1], x[0]升序


students = [('John', 'A', 15),  # 姓名，成绩，年龄
            ('Mike', 'C', 19),
            ('Mike', 'B', 12), ('Mike', 'B', 12),
            ('Mike', 'C', 12),
            ('Mike', 'C', 18),
            ('Mike', 'D', 10)]

students.sort(key=f)  # 先按年龄降序，再按成绩升序，再按姓名字典序
print(students)
# >>[('Mike', 'C', 19), ('Mike', 'C', 18), ('John', 'A', 15), ('Mike', 'B', 12), ('Mike', 'B', 12), ('Mike', 'C', 12), ('Mike', 'D', 10)]
```



#### 列表相关函数

| 函数         | 功能                                                    |
| ------------ | ------------------------------------------------------- |
| append(x)    | 添加元素到尾部                                          |
| extend(x)    | 添加列表x中所有元素到尾部                               |
| insert(i, x) | 将元素x插入到下标i处                                    |
| remove(x)    | 删除元素x（==只删除第一个==）                           |
| reverse()    | 颠倒整个列表                                            |
| index(x)     | 查找元素x，找到则返回第一次出现的下标，找不到则引发异常 |



#### 列表映射map

#####map(function, sequence)

+ 可用于将一个序列（列表、元组、集合...）映射到另一个序列

+ 返回一个==延时求值对象==(操作还没有被执行），可以转换成list, tuple, set...

```python
def f(x):
    print(x, end="")
    return x*x

a = map(f, [1, 2, 3])   # 对于列表每个元素，调用f函数，并将结果存起来（还未执行）
print(list(a))      # 将a转换成list时，执行上述操作，>>123[1, 4, 9]
print(tuple(a))     # >>()  a操作做完后就不会再做了
a = list(map(lambda x: 2 * x, [2, 3, 4]))
print(a)    # >>[4, 6, 8]
```

##### map用于输入

输入3个整数, 再输出

```python
x, y, z = map(int, input().split())
print(x, y, z)
```



#### 列表过滤

##### filter(function, sequence)

+ ==抽取==序列中令function(x)为True的元素x
+ 返回一个延时求值对象，可以转换成list, tuple, set...

```python
def f(x):
    return x % 2 == 0   # 筛选偶数

lst = tuple(filter(f, [1, 2, 3, 4, 5]))
print(lst)      # >>(2, 4)
```



#### 列表生成式

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220118131413248.png" alt="image-20220118131413248" style="zoom: 33%;" />

#### 元组生成式

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220118131520579.png" alt="image-20220118131520579" style="zoom: 33%;" />



#### 二维列表

```python
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(matrix)   # >>[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(matrix[1][2], matrix[2][2])   # >>6 9
matrix[1][1] = 100
print(matrix)   # >>[[1, 2, 3], [4, 100, 6], [7, 8, 9]]
matrix = [[0 for i in range(3)] for i in range(3)]
print(matrix)   # >>[[0, 0, 0], [0, 0, 0], [0, 0, 0]]
matrix = [[i*3+j for j in range(3)] for i in range(3)]
print(matrix)   # >>[[0, 1, 2], [3, 4, 5], [6, 7, 8]]
```

+ 生成一个3行4列的矩阵，所有元素都是0

```python
lst = []
for i in range(3):
    lst.append([0] * 4)
lst[0][0] = lst[2][3] = 100
for i in range(3):
    for j in range(4):
        print(lst[i][j], end=' ')
    print("")   # 换行
```



##### 定义二维元组

```python
matrix = ((1, 2, 3), (4, 5, 6), (7, 8, 9))
print(matrix)   # >>((1, 2, 3), (4, 5, 6), (7, 8, 9))
matrix = tuple(tuple(0 for i in range(3)) for i in range(3))
print(matrix)   # >>((0, 0, 0), (0, 0, 0), (0, 0, 0))
```



####列表拷贝

```python
a = [1, 2, 3, 4]
b = a[:]  # b是a的拷贝，指向不同对象
print(a)  # >>[1, 2, 3, 4]
b += [10]
print(a)  # >>[1, 2, 3, 4]
print(b)  # >>[1, 2, 3, 4, 10]
```

##### 列表深拷贝

非深拷贝的例子：

```python
a = [1, [2]]
b = a[:]
b.append(4)	
print(b)    # >>[1, [2], 4]
a[1].append(3)	# a[1]和b[1]指向同一列表
print(a)    # >>[1, [2, 3]]
print(b)    # >>[1, [2, 3], 4]
```



深拷贝：

+ 引入copy库。使用deepcopy函数

```python
import copy

a = [1, [2]]
b = copy.deepcopy(a)
b.append(4)     
print(b)        # >>[1, [2], 4]
a[1].append(3)
print(a)        # >>[1, [2, 3]]
print(b)        # >>[1, [2], 4]
```



#####列表元组互转

```python
a = [1, 2, 3]
b = tuple(a)    # b: (1, 2, 3)
c = list(b)     # c: [1, 2, 3]
t = (1, 3, 2)
(a, b, c) = t   # a = 1, b = 3, c = 2
s = [1, 2, 3]
[a, b, c] = s   # a = 1, b = 2, c = 3
```

##### 列表元组字符串互转

```python
print(list("hello"))        # >>['h', 'e', 'l', 'l', 'o']
print("".join(['a', '44', 'c']))    # >>a44c
print(tuple("hello"))       # >>('h', 'e', 'l', 'l', 'o')
print("".join(('a', '44', 'c')))    # >>a44c
```



#####例题：成绩排序

输入学生个数n，再输入n行 `姓名 成绩` ，要求先按成绩降序，后按姓名字典序

```python
n = int(input())
x = []
for i in range(n):
    lst = input().split()
    name, score = lst[0], int(lst[1])
    x.append([name, score])
x.sort(key=lambda a: (-a[1], a[0]))
for i in range(n):
    print(x[i][0], x[i][1])
```

##### 例题：图像模糊处理

n*m 灰度矩阵，外圈灰度值不变，内部灰度值修改为自身+上下左右4个灰度值的平均。

```python
import copy

lst = input().split()
n, m = int(lst[0]), int(lst[1])
x = []
for i in range(n):
    x.append(list(map(int, input().split())))

res = copy.deepcopy(x)		# 新建一个列表，防止对原矩阵修改引起的问题
for i in range(1, n-1):
    for j in range(1, m-1):
        res[i][j] = round((x[i][j] + x[i-1][j] + x[i+1][j] + x[i][j-1] + x[i][j+1])/5)	# 四舍五入

for i in range(n):
    for j in range(m):
        print(res[i][j], end=" ")
    print("")
```

*****

### 八、字典

#### 概述

+ 每个元素由键:值组成，可根据键==快速==查找（***O(1)***）
+ 格式：`d = {key1 : value1, key2 : value2}`
+ 字典的值可赋值，因此也是指针
+ 键不允许重复
+ 键必须是不可变的数据类型，例如字符串、小数、整数、元组

```python
scope = {}  # 空字典
scope['a'] = 3  # 添加元素 'a':3
scope['b'] = 4  # 添加元素 'b':4
print(scope)  # >>{'a': 3, 'b': 4}
print('b' in scope)  # >>True
scope['k'] = scope.get('k', 0) + 1		# 查找同时添加元素 'k':1
# get(k, v): 如果键key存在，返回key对应的值；否则返回v
print(scope['k'])  # >>1
scope['k'] = scope.get('k', 0) + 1
print(scope['k'])  # >>2
```

##### get(key, v):

​	如果key存在，则返回key对应的值；否则返回v。（**避免抛出异常**）

##### 字典的键不可重复，是指键内容不能重复

```python
a = (1, 2, 3)
b = (1, 2, 3)
d = {a:60, b:70, (1, 2, 3):80, (1, 2, 3):50}    # 实际上d中只有一个元素
print(d[a])     # >>50
print(d[b])     # >>50
print(d[(1, 2, 3)])     # >>50
print(d)        # >>{(1, 2, 3): 50}
```



#### 字典的构造

```python
items = [('name', 'Gumby'), ('age', 42)]
d = dict(items)  # 字典的类型名是dict
print(d)        # >>{'name': 'Gumby', 'age': 42}
d = dict(name='Gumby', age=42, height=1.76)
print(d)        # >>{'name': 'Gumby', 'age': 42, 'height': 1.76}
```

#### 字典相关函数

| 函数     | 功能                                |
| -------- | ----------------------------------- |
| clear()  | 清空字典                            |
| keys()   | 取字典的键的序列                    |
| items()  | 取字典的元素的序列，可用于遍历字典  |
| values() | 取字典的值序列                      |
| pop(x)   | 删除键为x的元素，如果不存在则抛异常 |
| copy()   | 浅拷贝                              |

> 上述‘序列’, 不是指list, tuple 或 set

```python
d = {'name': 'Gumby', 'age': 42, 'GPA': 3.5}
if 'age' in d.keys():
    print(d['age'])     # >>42
for x in d.items():     # x为元组
    print(x, end=', ')  # >>('name', 'Gumby'), ('age', 42), ('GPA', 3.5),
for x in d.items():     # 元组第一个元素为键
    print(x[0], end=', ')   # >>name, age, GPA,
for x in d.items():
    print(x[1], end=', ')   # >>Gumby, 42, 3.5,
for k, v in d.items():  # k为键，v为value
    print(k, v, end=', ')   # >>name Gumby, age 42, GPA 3.5,
for x in d.keys():
    print(x, end=', ')      # >>name, age, GPA, 
for x in d.values():
    print(x, end=', ')  # >>Gumby, 42, 3.5, 
```

##### 遍历字典

> items()

```python
x = {'username': 'admin', 'machines': ['foo', 'bar', 'baz'], 'Age': 15}
for i in x.items():
    print(i[0])
    print(i[1])
```



#### 例题：统计单词频率

输入若干行，每行一个单词。

按单词出现次数从高到低打出所有单词。次数相同的，按照字典顺序排。<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220120144403530.png" alt="image-20220120144403530" style="zoom:25%;" />

##### 思路：读入字典元素后，以元组形式放到列表中排序（==字典无法排序==）

```python
d = {}
while 1:
    try:
        word = input()
        d[word] = d.get(word, 0) + 1
    except:
        break
result = []     # 将元素放到列表中排序
for x in d.items():
    result.append(x)
result.sort(key=lambda a: (-a[1], a[0]))	# 次数降序，单词升序
for i in result:
    print(i[1], i[0])
```



****

### 九、集合

####集合（set）的概念同数学上的集合

+ 元素类型可以不同
+ 元素不允许重复
+ 可以增删元素
+ 整数、小数、复数、字符串、元组都可以作为集合的元素。但==列表、字典和集合等可变数据类型不可作为集合元素==
+ 集合的作用是***快速判断某个东西是否在一堆东西里***
+ **集合元素没有顺序，因此不能下标访问**



#### 集合的构造

```python
print(set([]))  # >>set()  集合可由列表转换得到，set([])是空集合
a = {1, 2, 2, 'ok', (1, 3)}
print(a)        # >>{1, 2, (1, 3), 'ok'}
b = (3, 4)
c = (3, 4)
a = set((1, 2, 'ok', 2, b ,c))
for x in a:         # >>1 2 (3, 4) ok 
    print(x, end=' ')
a = set("abc")      # 字符串转集合，每个字符一个元素
print(a)        # >>{'b', 'c', 'a'}
a = set({1: 2, 'ok': 3, (3, 4): 4})     # 字典转集合只取键
print(a)        # >>{1, (3, 4), 'ok'}
```

#### 集合常用函数

| 函数      | 功能                             |
| --------- | -------------------------------- |
| add(x)    | 添加元素x。如果x已存在，则不添加 |
| clear()   | 清空集合                         |
| copy()    | 返回自身的浅拷贝                 |
| remove(x) | 删除元素x。如果不存在x，引发异常 |
| update(x) | 将序列x中的元素加入到集合        |

#### 集合运算

| a, b 是集合 |                           |
| ----------- | ------------------------- |
| x in a      | x是否在集合a中            |
| a\|b        | 求a,b的并                 |
| a&b         | 求a和b的交                |
| a-b         | 求a和b的差                |
| a^b         | 求a和b的对称差(=a\|b-a&b) |
| a==b        | a元素是否和b一样          |
| a!=b        | a元素是否和b不一样        |
| a<=b        | a是否是b的子集            |
| a<b         | a是否是b的真子集          |
| a>=b        | b是否是a的子集            |
| a>b         | b是否是a的真子集          |



####集合例题：统计不重复单词的个数

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220120150821364.png" alt="image-20220120150821364" style="zoom:25%;" />

#####思路

​	将输入的单词添加至集合中（***自动去重***），最后输出len

```python
s = set([])
while 1:
    try:
        word = input()
        if word not in s:	# 这行可以不写
            s.add(word)
    except:
        break
print(len(s))
```

> 用列表做会慢得多！

****

### 十、python中一些操作的时间复杂度总结

| 数量级   | 操作                                                         |
| -------- | ------------------------------------------------------------ |
| O(1)     | 集合、字典增删元素，查找元素，以关键字作下标访问字典元素的值，列表添加元素到末尾（append），列表、字符串、元组根据下标访问元素 |
| O(n)     | 列表、元组查找元素（in, index), 列表插入元素（insert)，删除元素（remove）、计算出现次数 |
| O(nlogn) | python自带排序sort、sorted                                   |
| O(logn)  | 二分查找（需要排好序）                                       |



####例题：出现最少的数

输入若干个整数（不超过20w），每个整数都小于1亿。找出出现次数最小的那个数。次数相同则输出最前面的一个。

#####思路：字典中key记录整数，value用一个列表记录次数和位置`[cnt, index]`。将所有value放到一个列表中`[int, cnt, index]`排序。

```python
d = {}
index = 1   # 记录输入整数的下标
while 1:
    try:
        n = int(input())
        if n not in d:   # 不存在则次数为1
            d[n] = [1, index]
        else:
            d[n][0] += 1     # 字典中存在当前整数，次数加1
    except:
        break
lst = []
for k, v in d.items():
    tmp = [k, v[0], v[1]]
    lst.append(tmp)
lst.sort(key=lambda x: (x[1], x[2]))
print(lst[0][0], lst[0][1])
```


****

###十一、文件读写

#### 概述

+ `open`函数打开一个文件，将==返回值==放入一个变量，例如f
+ 用`f.write`函数写入文件
+ 用`f.readlines`函数读取全部文件内容
+ 用`f.readline`函数读取文件一行
+ 用`f.close()`函数关闭文件
+ 用`f.read()`函数读取文件全部内容。***返回一个字符串，包含文件全部内容。***

#### 创建文件并写入内容

``` python
a = open("c:\\tmp\\t.txt", 'w')  # 'w'表示以写入方式打开文件。若文件存在则会被清空覆盖
a.write("good\n")
a.write("好啊\n")
a.close()
```

##### 运行后文件 c:\tmp\t.txt内容：

```text
good
好啊
```

#### 读取现有文件

```python
f = open("c:\\tmp\\t.txt", 'r')  # 'r'表示以读取方式打开文件，文件不存在抛异常
lines = f.readlines()
f.close()
for x in lines:
    print(x, end="")
```

##### 输出：

```text
good
好啊
```



##### 用readline读文件中的一行

```python
try:
    infile = open("c:\\tmp\\t.txt", 'r')
    while True:
        data1 = infile.readline()   # data1包括结尾的换行符
        if data1 == '':     # 条件满足代表文件结束
            break
        data1 = data1.strip()   # 去掉两头空格，包括'\n'
        print(data1)
    infile.close()
except Exception as e:
    print(e)        # >>[Errno 2] No such file or directory: 'c:\\tmp\\t.txt'
```



#### 添加文件内容

```python
f = open("c:\\tmp\\t.txt", 'a')     # 'a'表示append
f.write("新增行\n")
f.write("ok\n")
f.close()
```



##### ==注==：

***.py文件必须存为utf-8格式才能运行。若存为ansi格式，则应在文件开头写：`#coding = gbk`***

#### 创建文件和读取文件时都可以指定编码

```python
outfile = open("c:\\tmp\\t.txt", 'w', encoding='utf-8')
# 若打开文件用于写入时不指定编码，则使用系统默认编码。win10也可能是Ansi(gbk)
outfile = open("c:\\tmp\\t.txt", 'r', encoding='utf-8')
```



#### open文件名参数的相对路径和绝对路径

> 相对路径（不带盘符）：在当前目录下寻找文件

+ "../readme.txt": 文件在当前目录的上一层目录下
+ "../../readme.txt": 文件在当前目录的上两层目录下
+ "/tmp3/test/readme.txt"：文件在当前盘符根目录下的tmp3/test/里

#####  以命令行方式运行程序时，当前目录就是cmd窗口的当前目录，与程序存放位置无关

##### 程序运行期间可以改变当前文件夹：

```python
import os
print(os.getcwd())		# get current working directory
os.chdir("c:/tmp")
print(os.getcwd())
```



#### 文件夹操作

##### os库和shutil库中有一些函数可以用来操作文件和文件夹（文件夹也称目录）

| 函数                  | 功能                                                         |
| --------------------- | ------------------------------------------------------------ |
| os.chdir(x)           | 将当前目录修改为x                                            |
| os.getcwd()           | 获取当前目录路径                                             |
| os.listdir(x)         | 返回一个列表，里面是目录x中的所有文件和子文件夹的名字        |
| os.mkdir(x)           | 创建目录x                                                    |
| os.path.getsize(x)    | 获取文件x的大小（单位：字节）                                |
| os.path.isfile(x)     | 判断x是否是文件                                              |
| os.remove(x)          | 删除文件x                                                    |
| os.rmdir(x)           | 删除目录x。==x必须是空文件夹才能删除成功==                   |
| os.rename(x, y)       | 将文件或目录x改名为y。不但可以改名还可以起到移动文件或目录的作用。例如：`os.rename("c:/tmp/a", "c:/tmp2/b")可以将文件c:/tmp/a移动到c:/tmp2/下并改名为b |
| shutil.copyfile(x, y) | 拷贝文件x到文件y。若y存在则覆盖y                             |



#### 删除文件夹的递归函数

**！！！危险！！！运行该函数后删除的文件无法找回！！！**

```python
import os


def powerRmdir(path):  # 删除 path目录中所有文件及其所有子目录
    lst = os.listdir(path)
    for x in lst:  # x为文件名（不包括路径），例如a.txt
        actualFileName = path + '/' + x  # 构造x的路径名
        if os.path.isfile(actualFileName):  # 是文件，删除
            os.remove(actualFileName)
        else:  # 是子目录，递归删除
            powerRmdir(actualFileName)
    os.rmdir(path)  # path目录为空时才能删除
```



#### 获取文件夹总大小的递归函数

```python
import os


def getTotalSize(path):  # 获取目录总大小（单位：字节）
    total = 0
    lst = os.listdir(path)
    for x in lst:  # x为文件名（不包括路径），例如a.txt
        actualFileName = path + '/' + x  # 构造x的路径名
        if os.path.isfile(actualFileName):
            total += os.path.getsize(actualFileName)
        else:
            total += getTotalSize(actualFileName)
	return total
```



#### 以命令行方式运行python程序：

每次运行python程序，都要在Pycharm里运行，显然不方便。因此有时需要在命令行中运行

做法：

在命令行窗口敲：(xxx.py在当前目录下)

```cmd
python xxx.py
```



#### 命令行参数

如果编写了一个程序hello.py，功能是合并两个文件，需要在命令行里敲

```cmd
python hello.py a1.txt a2.txt
```

**此时hello.py、a1.txt、a2.txt都是命令行参数。**

##### 在程序内如何获得命令行参数？

```python 
import sys
for x in sys.argv:	# sys.argv为一个字符串列表
    print(x)
```

在命令行敲如下代码`python hello.py this is "hello world"`后，在程序中：

sys.argv[0]就是'hello.py'

sys.argv[1]就是'this'

sys.argv[2]就是'is'

sys.argv[3]就是'hello world'

**！！！强调！！！在命令行中启动时，当前目录是cmd提示的当前目录，而不是python文件的当前目录！！！**



****

### 十一、文件处理实例

####程序1：统计文章中单词词频

以命令行方式启动程序：

​	python countfile.py 源文件 结果文件

将源文件的统计结果写入结果文件中

例如：

​	python countfile.py  a1.txt a2.txt

​	python countfile.py  c:\tmp\a4.txt  d:\tmp\r4.txt

##### 思路：

1. sys.argv[0] 是源文件，sys.argv[1]是结果文件
2. 要从a1.txt中分割出单词，然后用字典记录单词的出现频率
3. 分隔单词时的分隔字符多种多样，因此***非字母的字符都是分隔串***
4. 用`re.split()`来分隔

#####回顾：正则表达式的分隔字符串

```python
import re
re.split(x, s)	# 用x中的分隔串分隔s
```

> x里的分隔串用“|”隔开，形如：
>
> ",|  |, |\\*| \n| \? | ok  | 8 "
>
> 一些特殊字符，例如：`?  !  "  '  (  )  |  *  $  \  [  ]  ^  {  } .  ,  ` 在正正则表达式中出现时，要加 \
>
> ==相邻两个分隔串间会分割出一个空串==



##### 代码：

```python
import sys
import re


def countFile(filename, words):
    # 对filename文件进行词频统计，结果存到字典words里
    try:
        f = open(filename, 'r', encoding='gbk')  # 以读方式打开源文件
    except Exception as e:
        print(e)
        return 0  # 失败
    txt = f.read()  # 将文件全部内容存到字符串txt中
    f.close()

    splitChars = set([])  # 分隔符集合
    # 遍历整个文件，获得所有分隔符
    for c in txt:
        if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):  # 不是字母的都是分隔符
            splitChars.add(c)
    splitStr = ""  # 用于re.split的正则表达式
    # 分隔符间以|分隔，末尾不能为|
    for c in splitChars:
        if c in {'.', '?', '!', '"', "'", '(', ')', '|', '*', '$', '\\', '[', ']', '^', '{', '}'}:
            # 上面的特殊字符在字符串中要加\
            splitStr += "\\" + c + "|"
        else:
            splitStr += c + "|"
    splitStr += " "  # |后必须有东西，因此加一个空格
    lst = re.split(splitStr, txt)  # lst为分隔后的单词列表
    for x in lst:
        if x == "":  # 相邻两个分隔符间会分隔出来一个空串，跳过
            continue
        lx = x.lower()  # 转为小写
        # 记录词频
        words[lx] = words.get(lx, 0) + 1
    return 1  # 成功


result = {}  # 结果字典。格式为 { 'a' : 2, 'about' : 3 ...}
if countFile(sys.argv[1], result) == 0:  # 如果统计失败
    exit()
lst = list(result.items())  # result.items()返回元组，放入列表（字典不可排序）
lst.sort()  # 单词按字典序排序
f = open(sys.argv[2], 'w')  # 以写入方式打开结果文件    
for x in lst:
    f.write("%s\t%d\n" % (x[0], x[1]))  # 统计结果写入结果文件
f.close()
```



####程序2：改进的词频统计

程序名：countfiles.py

用法：python countfiles.py 结果文件

对当前目录（countfiles.py所在文件夹）下全部文件名是字母a开头的txt文件进行词频统计，结果写入结果文件



##### 思路：

1. 找到要统计的所有文件

   ```python
   import os
   os.listdir()	# 获得当前目录下所有文件和文件夹的列表。列表中元素是文件或文件夹名名字，不带路径
   os.path.isfile(x) # 判断x是否是文件
   ```

2. 上面的countfile函数不需要修改，**面对多个文件只需要第二个参数(words)不变，就能将所有单词合并统计**


##### 代码：

```python
# ...省略countfile函数
result = {}  # 结果字典。格式为 { 'a' : 2, 'about' : 3 ...}
lst = os.listdir()  # 列出当前目录下所有文件和目录
for x in lst:
    if os.path.isfile(x):  # 如果是文件
        if x.lower().endswith(".txt") and x.lower().startswith("a"):
            # x以'a'开头，以.txt结尾
            countFile(x, result)	# 记录词频，结果合并到result中
lst = list(result.items())  # result.items()返回元组，放入列表（字典不可排序）
lst.sort()  # 单词按字典序排序
f = open(sys.argv[1], 'w')  # 以写入方式打开结果文件
for x in lst:
    f.write("%s\t%d\n" % (x[0], x[1]))  # 统计结果写入结果文件
f.close()
```



####程序3：准确统计文章中的单词词频

程序名:countfile_novary.py

用法：

​	python countfile_novary.py 源文件 结果文件

对“源文件”进行单词词频**分析**，分析结果写入“结果文件”

**==如果碰到单词的变形，则转换成原型进行统计==**

+ 单词原型-变化表在文件word_varys.txt里，格式：

  ```txt
  act
  	acted|acting|acts
  action
  	actions
  active
  	avtively|avtiveness
  ```

##### 思路

1. 同样需要一个字典统计单词和出现次数

2. **建立变形与原型的映射**：建立字典dt，元素形式为：

   {acting:act, acting: act, acts:act, ...}

3. 对每个源文件中的单词w，查找dt中***键为w***的元素x。如果x不存在，那么x就是原型，统计其词频；

   如果x存在，则x[1]是原型，将x[1]的出现次数+1

##### 代码

```python
import os
import re
import sys


def makeVaryWordsDict():  # 构造变形->原型的映射字典
    vary_words = {}
    f = open("words_varys.txt", "r")
    lines = f.readlines()  # lines是一个列表，每个元素是文件中的一行
    f.close()
    L = len(lines)
    for i in range(0, L, 2):  # 每两行为一个单词原型及变形。lines[i]是原型，lines[i+1]为变形
        word = lines[i].strip()  # 去掉空格及换行符
        varys = lines[i + 1].strip().split('|')  # 以|分隔
        for w in varys:
            vary_words[w] = word  # 添加映射
    return vary_words


def makeSplitStr(txt):
    splitChars = set([])  # 分隔符集合
    # 遍历整个文件，获得所有分隔符
    for c in txt:
        if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):  # 不是字母的都是分隔符
            splitChars.add(c)
    splitStr = ""  # 用于re.split的正则表达式
    # 分隔符间以|分隔，末尾不能为|
    for c in splitChars:
        if c in {'.', '?', '!', '"', "'", '(', ')', '|', '*', '$', '\\', '[', ']', '^', '{', '}'}:
            # 上面的特殊字符在字符串中要加\
            splitStr += "\\" + c + "|"
        else:
            splitStr += c + "|"
    splitStr += " "  # |后必须有东西，因此加一个空格
    return splitStr


def countFile(filename, vary_word_dict):
    # filename为要分析的文件，vary_word_dict为变形->原型的映射字典
    try:
        f = open(filename, 'r')
    except Exception as e:
        print(e)
        return None
    txt = f.read()  # 文件所有内容存入txt
    f.close()
    splitStr = makeSplitStr(txt)
    words = {}
    lst = re.split(splitStr, txt)
    for x in lst:
        lx = x.lower()
        if lx == "":
            continue
        if lx in vary_word_dict:  # 单词在键中能找到，则为变形，转成原型后在统计
            lx = vary_word_dict[lx]
        # 统计词频
        words[lx] = words.get(lx, 0) + 1
    return words


result = countFile(sys.argv[1], makeVaryWordsDict())  # result为词频统计字典
if result is not None and result != {}:
    lst = list(result.items())
    lst.sort()
    f = open(sys.argv[2], 'w')
    for x in lst:
        f.write("%s\t%d\n" % (x[0], x[1]))
    f.close()
```



#### 程序4:countfile_nocet4.py

用法：

​	python countfile_nocet4.py  源文件 结果文件

对源文件进行词频分析，只统计不在四级列表中的单词

+ 四级单词列表在文件cet4words.txt中，单词都是单独一行，以$打头

  $a

  [e?]

  art.一（个）；每一（个）

  $abandon

  [?'b?nd?n]

  vt.遗弃；放弃；放纵（自己）

##### 思路

读取cet4words.txt 中的单词，存放到一个集合里。碰到源文件中的单词，检查是否在集合里。如果在则跳过

##### 代码

```python
import os
import sys
import re


def makeFileterSet():   # 构造四级单词集合
    cet4words = set([])
    f = open("cet4words.txt", 'r')
    lines = f.readlines()   # lines为列表，每个元素为文件的一行
    f.close()
    for line in lines:
        line = line.strip()  # 去掉首尾空格及换行符
        if line == "":
            continue
        if line[0] == '$':   # 是单词   
            cet4words.add(line[1:])  # 下标1到末尾组成单词
    return cet4words


def makeSplitStr(txt):
    splitChars = set([])  # 分隔符集合
    # 遍历整个文件，获得所有分隔符
    for c in txt:
        if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):  # 不是字母的都是分隔符
            splitChars.add(c)
    splitStr = ""  # 用于re.split的正则表达式
    # 分隔符间以|分隔，末尾不能为|
    for c in splitChars:
        if c in {'.', '?', '!', '"', "'", '(', ')', '|', '*', '$', '\\', '[', ']', '^', '{', '}'}:
            # 上面的特殊字符在字符串中要加\
            splitStr += "\\" + c + "|"
        else:
            splitStr += c + "|"
    splitStr += " "  # |后必须有东西，因此加一个空格
    return splitStr


def countFile(filename, filterdict):    # 词频统计，要去掉在filterdict中的单词
    words = {}
    try:
        f = open(filename, 'r')
    except Exception as e:
        print(e)
        return 0
    txt = f.read()
    f.close()
    splitStr = makeSplitStr(txt)
    lst = re.split(splitStr, txt)
    for x in lst:
        lx = x.lower()
        if lx == "" or lx in filterdict:    # 去掉空串和非四级单词
            continue
        # 统计词频
        words[lx] = words.get(lx, 0) + 1
    return words


result = countFile(sys.argv[1], makeFileterSet())
if result != {}:
    lst = list(result.items())
    lst.sort()
    f = open(sys.argv[2], 'w')
    for x in lst:
        f.write("%s\t%d\n" % (x[0], x[1]))
    f.close()
```

****
## Python面向对象程序设计

### 类和对象

#### 为什么需要'类'

+ 列表太长，忘记某元素对应的下标
+ ...

#### 类与对象的概念

+ 类是用来代表事物的。对一种事物，可以设计一个类，概括出该种事物的属性，用成员变量表示；还要概括该种事物能进行的操作 ，用成员函数表示。成员变量也称为类的"属性"，成员函数也称为类的”方法“。
+ 类的实例，成为对象。类代表一种事物的共同特点，对象就是一个具体的事物个体。
+ 生成对象的方法：`类名(参数1, 参数2...)`


#### 类的写法：

```python
class 类名:
    def __init__(self, 参数1，参数2, ...):	// 构造函数，每个类必有
        ......
	def 成员函数1(self, 参数1，参数2, ...):
        ......
	def 成员函数2(self, 参数1，参数2, ...):
        ......
	def 成员函数n(self, 参数1，参数2, ...):
        ......
```

##### 矩形类实例

​	**定义矩形类**

```python
class rectangle:
    def __init__(self, w, h):   # 成员变量只需要写在构造函数里
        self.w, self.h = w, h

    def area(self):     # 面积
        return self.h * self.w

    def perimeter(self):    # 周长
        return 2 * (self.w + self.h)
```

​	**使用矩形类**（**==定义main类函数==**）

```python
def main():
    w, h = map(int, input().split())    # 假设输入2, 3
    rect = rectangle(w, h)      # 生成一个rectangle对象
    print(rect.area(), rect.perimeter())    # >>6 10
    rect.w, rect.h = 10, 20
    print(rect.area(), rect.perimeter())    # >>200 60
    rect2 = rectangle(2, 3)
    print(rect2.area(), rect2.perimeter())  # >>6 10

main()
```



#### 类的作用

​	**将数据和操作数据的函数捆绑在一起，便当做一个整体使用**



#### Python中的类

+ 类型名即是类名：

  float, str, list, dict ...

+ 小数、复数、字符串、元组、列表、集合、字典等组合数据类型的常量，都是对象。函数也是对象，但**整数型常量不是对象**。

+ 各种库都是由类组成：

  matplotlib, turtle, jieba, sqlite3

+ 程序员可以自定义类，如rectangle





### 对象的比较

#### `__eq__`

+ Python中所有的类，包括自定义的类，都有`__eq__`方法

+ `x==y`的值，就是`x.__eq__(y)`的值；如果`x.__eq__(y)`无定义，那么就是`y.__eq__(x)`的值。如果`x.__eq__(y)`和`y.__eq__(x)`都无定义，那么`x==y`也无定义。（x,y都是==整数常量时不适用==）

  ```python
  print(24.5.__eq(24.5))	# >>True
  ```

#### `__ne__`和其他比较方法

+ `a!=b`等价于`a.__ne__(b)`，或`b.__ne__(a)`（若`a.__ne__(b)`无定义）
+ 默认情况下，`a.__ne__(b)`等价于`not a.__eq__(b)`
+ `a < b`等价于`a.__lt__(b)`
+ `a > b`等价于`a.__gt__(b)`
+ `a <= b`等价于`a.__le__(b)`
+ `a >= b`等价于`a.__ge__(b)`



#### 自定义对象的比较

+ 默认情况，一个自定义类的`__eq__`方法，功能是判断两个对象的id是否相同
+ 默认情况，一个自定义类的两个对象a和b，`a==b`和`a is b`的含义一样，都是“a和b指向同一地方”。同理，`a != b`和`not a is b`含义相同
+ 默认情况下，自定义类的对象不能比较大小，因其`__lt__, __gt__, __le__, __ge__`方法都被设置成了None

##### 示例

```python
class point:
    def __init__(self, x, y = 0):
        self.x, self.y = x, y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):    # 使两个对象可以用<比较
        if self.x == other.x:
            return self.y < other.y
        else:
            return self.x < other.x



a, b = point(1, 2), point(1, 2)
print(a == b)   # >>True
print(a != b)   # >>False
print(a < point(0, 1))  # >>False
print(a < point(1, 3))  # >>True
lst = [a, point(-2, 3), point(7, 8), point(5, 9), point(5, 0)]
lst.sort()  # 默认用__lt__排序
for p in lst:
    print(p.x, p.y, end=', ')   # >> -2 3, 1 2, 5 0, 5 9, 7 8,
```



#### 输出对象

​	**自定义类重写`__str__`方法可以将对象转字符串**

```python
class point:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __str__(self):
        return "(%d, %d)" % (self.x, self.y)

print(point(3, 5))          # >>(3, 5)
print(str(point(2, 4)))     # >>(2, 4)
```





### 继承和派生

#### 学生类示例

```python
import datetime

class student:
    def __init__(self, id, name, gender, birthYear):
        self.id, self.name, self.gender, self.birthYear = \
            id, name, gender, birthYear

    def printInfo(self):
        print("Name: ", self.name)
        print("ID: ", self.id)
        print("Birth Year: ", self.birthYear)
        print("Gender: ", self.gender)
        print("Age: ", self.countAge())

    def countAge(self):
        return datetime.datetime.now().year - self.birthYear


class undergraduateStudent(student):    # 本科生类，继承student类
    def __init__(self, id, name, gender, birthYear, department):
        student.__init__(self, id, name, gender, birthYear)
        self.department = department

    def qualifiedForBaoyan(self):   # 给予保研资格
        print("Qualified for baoyan")

    def printInfo(self):
        student.printInfo(self)     # 调用基类的同名方法
        print("Department: ", self.department)

def main():
    s2 = undergraduateStudent("118829212", "Harry Potter", "M", 2000, "Computer Science")
    s2.printInfo()      
    s2.qualifiedForBaoyan()  
    if s2.countAge() > 18:
        print(s2.name, "is older than 18")

main()
# Name:  Harry Potter
# ID:  118829212
# Birth Year:  2000
# Gender:  M
# Age:  22
# Department:  Computer Science
# Qualified for baoyan
# Harry Potter is older than 18
```



#### object类（同Java）

+ 所有类都是object的派生类，因而具有object类的各种属性和方法

```python
class A:
    def func(x):
        pass

print(dir(A))   # 输出A的所有成员函数
```

输出：

```text
['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', 
'__eq__', '__format__', '__ge__','__getattribute__', '__gt__', 
'__hash__', '__init__', '__init_subclass__', '__le__', '__lt__',
'__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__',
'__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__',
'__weakref__', 'func']
```

+ 有的类`__gt__, __lt__`等方法被设置成None,于是对象不可比较大小





### 静态属性和静态方法

#### 概念（同C++和Java）

+ 静态属性被所有对象共享，一共只有一份
+ 静态方法不是作用在具体的某个对象上，不能访问非静态属性
+ 静态属性和静态方法这种机制存在的目的，就是**为了少写全局变量和全局函数**



#### Employee类示例

```python
class employee:
    totalSalary = 0     # 静态属性，记录发给员工的工资总数
    def __init__(self, name, income):
        self.name, self.income = name, income

    def pay(self, salary):
        self.income += salary
        employee.totalSalary += salary

    @staticmethod
    def printTotalSalary():     # 静态方法
        print(employee.totalSalary)


e1 = employee("Jack", 0)
e2 = employee("Tom", 0)
e1.pay(100)
e2.pay(200)
employee.printTotalSalary()     # >>300
e1.printTotalSalary()           # >>300
e2.printTotalSalary()           # >>300
print(employee.totalSalary)     # >>300
```





### 对象作为集合元素或字典的键

#### 可哈希

+ 可哈希的东西，才可作为字典的键和集合的元素

+ `hash(x)`有定义，即为x可哈希

+ `hash(x) = x`（如果x是整形常量）

  `hash(x) = x.__hash__()`（如果x不是整型常量）

+ object类有一个`__hash__()`方法，**返回值是整数**



**列表、集合、字典的`__hash__`成员函数都被设置成None，因此它们都不能成为集合的元素，或者字典的键，因为无法计算哈希值。**

**整数类型变量，小数、字符串、元组的哈希值，是根据他们的值算出来的，只要值相同，哈希值就相同**

```python
x = 23.1
print(x.__hash__(), 23.1.__hash__())
# >>230584300921372695 230584300921372695
x = 23
print(x.__hash__(), hash(23))   # >>23 23
x = (1, 2)
print(x.__hash__(), (1, 2).__hash__(), hash(x))
# >> -3550055125485641917 -3550055125485641917 -3550055125485641917
x = 'ok'
print(x.__hash__(), "ok".__hash__())
# >> -7124967159215549686 -7124967159215549686
```



#### 哈希值与字典、集合的关系

+ 字典和集合都是**“哈希表”的数据结构**，根据元素的哈希值为元素找存放的“槽”， 哈希值可以看做是槽编号。

  一个槽可以放多个哈希值相同的元素

+ 两个对象a, b 若`hash(a) != hash(b)`，则a, b可以处于同一集合（也可以作为同一字典的不同元素的键）

+ **两个对象a, b若`hash(a) == hash(b)`，但`a==b`不成立，则a,b可以处于同一集合（槽）（也可以作为同一字典的不同元素的键）**

##### 若dt是个字典，dt[x]计算过程如下：

1. 根据hash(x)去找x应该在的槽的编号

2. 如果该槽没有元素，则认为dt中没有键为x的元素

3. 如果该槽中有元素，则试图在槽中找一个元素y，使得y的键`==x`。

   如果找到，则dt[x]即为y的值，找不到则dt[x]没定义，即认为dt中不存在键为x的元素

##### 自定义类的对象：

+ **默认情况下哈希值是根据对象id进行计算。所以两个对象，只要`a is b`不成立, a和b的哈希值就不同，就可以同时存在于一个集合内，或作为同一字典的不同元素的键**
+ **可以重写自定义类的`__hash_`函数，使得对象的哈希值和对象的值，而不是id相关，这样值相同的对象，就不能处于同一个集合中，也不能作为同一字典不同元素的键**

##### 示例

```python
class A:
    def __init__(self, x):
        self.x = x


a, b = A(5), A(5)       # a,b为两个不同的对象，因此id不同
dt = {a: 20, A(5): 30, b: 40}   # 三个元素的键id不同，因此在不同槽里
print(len(dt), dt[a], dt[b])    # >>3 20 40
print(dt[A(5)])     # runtime error	 这里的A(5)不是上面任意一个对象
```



#### 自定义类的对象是否可哈希

+ `a==b`等价于`a.__eq__(b)`.自定义类的**默认**`__eq__`函数是判断两个**对象的id**是否相同。自定义类的**默认**`__hash__`函数是**根据对象id**算哈希值的
+ 如果为自定义类重写了`__eq__(self, other)`函数，则其`__hash__`成员函数会被自动设置为None。这种情况下，该类就变成**不可哈希**的( 除非同时重写`__eq__`和`__hash__`)
+ ==自定义类只有重写了`__eq__`却没有重写`__hash__`，才是不可哈希的==



##### 重写hash不重写eq

```python
class A:
    def __init__(self, x):
        self.x = x

    def __hash__(self):
        return hash(self.x)

c = A(1)
dt = {A(1): 2, A(1): 3, c: 4}
# 三个元素哈希值相同，但id不同，因此在同一个槽内
print(len(dt))  # >>3
for a in dt.items():
    print(a[0].x, a[1], end=", ")   # >>1 2, 1 3, 1 4,
print(dt[c])    # >>4
print(dt[A(1)])	 # runtime error 没有元素x使得x==A(1)
```

##### 同时重写hash和eq

```python
class A:
    def __init__(self, x):
        self.x = x

    def __hash__(self):
        return hash(self.x)

    def __eq__(self, other):
        if isinstance(other, A):    # 判断other是否是类A的对象
            return self.x == other.x    # 成员变量是否相同， hash值就相同
        elif isinstance(other, int):    # 如果other是整数
            return self.x == other
        else:
            return False

a = A(3)
print(3 == a)       # >>True
b = A(3)
d = {A(5): 10, A(3): 20, a: 30}
print(len(d), d[a], d[b], d[3])     # >>2 30 30 30
```




****

## 正则表达式

### 一、正则表达式的概念与组成

#### 作用

+ 可以用来判断某个字符是否符合某种模式，比如判断某个字符串是不是邮箱地址，网址，电话号码，身份证号. . .
+ 可以用来在文本中寻找并抽取符合某种模式的字符串，比如电子邮件地址，电话号码，网址，身份证号. . .，找出三国演义中所有孔明提到曹操的场合都说了些啥

#### 概念

正则表达式是某些字符有特殊含义的字符串，表示一种字符串的模式（格式），如：

```RE
"abc"	// 匹配 "abc"
"b.?p.*k"	//  匹配 "bapk", "bxypabk"  . . .
"\d{3}[a-zA-Z]+.(\d{2}|N/A)\s\1"	// 匹配????
```

可以用相关函数求给定字符串和正则表达式的匹配情况



#### 正则表达式中的功能字符

| 字符/组合 | 匹配的模式                                                   | 正则表达式 | 匹配的字符串             |
| --------- | ------------------------------------------------------------ | ---------- | ------------------------ |
| .         | 除'\n'外的任意一个字符，包括汉字（多行匹配方式下也能匹配'\n'） | 'a.b'      | 'acb'、'adb'、'a(b'、... |
| *         | 量词。表示左边的字符可出现0次或任意次                        | 'a*b'      | 'b'、'aaaaaaab'          |
| ?         | 量词。表示左边的字符必须出现0次或1次                         | 'ka?b'     | 'kb'、'kab'              |
| +         | 量词。表示左边的字符必须出现1次或更多次                      | 'ka+b'     | 'kab'、'kaaaaab'         |
| {m}       | 量词。m是整数。表示左边的字符必须且只能出现m次               | 'ka{3}a'   | 'kaaaa'                  |
| {m,n}     | 量词。m,n是整数。表示左边的字符必须出现至少m次，最多n次。n也可不写，表示无上限 | 'ka{1,3}b' | 'kab'、'kaab'、'kaaab'   |
| \d        | 一个数字字符，等价于[0-9]                                    | 'a\db'     | 'a2b'、'a3b'\...         |
| \D        | 一个非数字字符，等价于\[^\d], \[^0-9]                        | 'a\Db'     | 'acb'...                 |
| \s        | 一个空白字符，如空格，\t,\r,\n等                             | 'a\sb'     | 'a b'、'a\nb'......      |
| \S        | 一个非空白字符                                               | 'a\Sb'     | 'akb' . . .              |
| \w        | 一个单词字符。包括汉字或大小写英文字母，数字、下划线或其他语言 | 'a\wb'     | 'a_b'、'a中b'            |
| \W        | 一个不是单词字符的字符                                       | 'a\Wb'     | 'a?b'...                 |
| \|        | 或。A\|B表示匹配A或匹配B均算成功匹配                         | 'ab\|c'    | 'ab'、'c'                |

> print("\\\s\s\S\w\W\d\D")	# python字符串中，\s等不是转义字符，都是两个字符



#### 正则表达式中的特殊字符

正则表达式中常见的字符有以下几个：

​	`. + ? * $ [ ] ( ) ^ { } \`

如果要在正则表达式中表示这几个字符本身，就应在前加 \

| 正则表达式   | 匹配的字符串                                        |
| ------------ | --------------------------------------------------- |
| 'a\$b'       | 'a$b'                                               |
| 'a\\*b'      | 'a*b'                                               |
| 'a\\[\\]b'   | 'a[]b'                                              |
| 'a\\.*b'     | 'ab'、'a.b'、'a..b'. . .                            |
| 'a\\\\\\\\b' | 'a\\\\b'（注意：此字符串在python中长度为3，即r'a\b' |
| r'a\\\\b'    | r'a\b'（r'a\b'等价于'a\\\\b'                        |

> print("\\*\\$\\.\\+\\[\\]\\(\\)\\?\\^\\{\\}")	# 这些都不是转义字符，都是两个字符





### 二、范围符号[ ]和量词

#### [XXX]的用法

**用以表示“此处必须出现某某范围内的字符”，或“此处必须出现一个字符，但不可以是某某范围内的字符”**

| [XXX]           | 匹配模式                                            | 正则表达式    | 匹配的字符串                                      |
| --------------- | --------------------------------------------------- | ------------- | ------------------------------------------------- |
| [a2c]           | 匹配'a','2','c'之一                                 | 's[a2c]k'     | 'sak'、's2k'、'sck'                               |
| [a-zA-Z]        | 匹配任意英文字母                                    | 'b[a-zA-Z]k'  | 'bak'、'bUk'、. . .                               |
| [\da-z\?]       | 匹配一个数字或小写字母或？                          | 'b[\da-z\?]k' | 'b0k', 'bck', 'b?k', . . .                        |
| [^abc]          | 匹配除了'a', 'b', 'c'以外的任意一个字符             | 'b[\^abc]k'   | 匹配所有'b.k'的字符串。*除了* 'bak', 'bbk', 'bck' |
| [^a-f0-3]       | 匹配一个非英文字母'a'-'f', ***也非*** 数字0-3的字符 | 略            | 略                                                |
| [\u4e00-\u9fa5] | 匹配一个汉字                                        |               | 汉字的Unicode编码范围是4e00-9fa5                  |

> python可以直接用\u4e00-\u9af5表示一个汉字
>
> ```python
> print('\u4e00\u4e01\u4e88\u9fa5')	# >>一丁予龥
> ```

#### 量词的用法

| 量词      | 匹配模式                                                     |
| --------- | ------------------------------------------------------------ |
| '.+'      | 匹配任意长度不为0且不含'\n'的字符串。**'+'表示**左边的***'.'代表任意字符***出现**一次或多次**。不要求出现的字符都必须一样 |
| '.*'      | 匹配任意不含'\n'的字符串，包括空串.**'*'表示0次或任意次**。  |
| '[\dac]+' | 匹配长度不为0的由数字或'a', 'c'构成的串，如'451a', 'a21c78ca' |
| '\w{5}'   | 匹配长度为5的由字母或数字或汉字构成的串，如'高大abc'， '33我a1' |



#### 正则表达式示例

|                                                      |                                             |
| ---------------------------------------------------- | ------------------------------------------- |
| [1-9]\d*                                             | 一切正整数（以1-9打头，后面任意数量的数字） |
| -[1-9]\d*                                            | 一切负整数                                  |
| -?[1-9]\d*\|0                                        | 一切整数（或上0）（**'?'表示一次或0次**）   |
| [1-9]\d*\|0                                          | 一切非负整数                                |
| -?([1-9]\d\*\\.\\d\*\\[1-9]\|0\\.\\d\*[1-9]\|0)      | 左右都没有多余0的小数                       |
| \w+([-+.]\\w+)\*@\\w+([-.]\\w+)\*\\.\\w+([-.]\\w+)\* | 邮箱                                        |

邮箱示例：**a.b.c.ddef+sfd@pku.edu.cn**





### 三、正则表达式的函数（Python）

**使用正则表达式要：**

```python
import re	# python自带
```

#### re.match函数

**`re.match(pattern, string, flags=0)`**

+ 从字符串string的**起始位置匹配**一个模式pattern。***只要从起始开始符合即匹配成功，不用管后面的子串***

+ flags标志位，用于控制模式串的匹配方式，如：是否区分大小写，多行匹配等等。

  如re.M|re.l表示忽略大小写，且多行匹配。
  
+ 成功则返回一个**匹配对象**，否则返回None

```python
import re
def match(pattern, string):
    x = re.match(pattern, string)
    if x is not None:
        print(x.group())  # x.group是匹配上的字符串
    else:
        print("None")

match("a  c", "a  cdkgh")    # >>a c
match("abc", "kabc")        # >>None (虽然有abc，但不在起始位置)
match("a\tb*c", "a\tbbcde") # >>a   bbc (b出现0次或任意次，然后跟c)
match("ab*c", "ac")         # >>ac
match("a\d+c", "ac")        # >>None
match("a\d{2}c", "a34c")    # >>a34c
match("a\d{2,}c", "a3474884c")  # >>a3474884c
match(".{2}bc", "cbcd")     # >>None (bc前面要有两个字符)
```



#### re.search 函数

`re.search(pattern, string, flags=0)`

+ 查找字符串中可以匹配成功的**子串**
+ 若匹配成功，则返回**匹配对象**；若无法匹配，则返回None。

```python
import re
def search(pattern, string):
    x = re.search(pattern, string)
    if x is not None:
        print(x.group(), x.span())  # 输出子串及起止位置
    else:
        print("None")

search("a.+bc*", "dbaegsfbcef")  # >>aegsfbc (2, 9)
search("a.+bc*", "bcdbaegsfbccc")  # >>aegsfbccc (4, 13)
search("a.?bc*d", "dabccdc")  # >>abccd (1, 6)
search("aa", "baaaa")  # >>aa (1, 3)
search("\([1-9]+\)", "ab123(0456)(789)45ab")  # >>(789) (11, 16)
search("[1-9]\d+", "ab01203d45")  # >>1203 (3, 7)
```



#### re.findall函数

`re.findall(pattern, string, flags=0)`

+ 查找字符串中所有和模式匹配的子串（==**不重叠**==)放入列表。
+ 一个子串都找不到返回空表[]

```python
import re

print(re.findall('\d+', "this is 334 what me 7734gw"))  # >>['334', '7734']
print(re.findall('[a-zA-Z]+', "A dog has 4 legs.这是true"))  # >>['A', 'dog', 'has', 'legs', 'true']
print(re.findall('\d+', "this is good."))  # >>[]
print(re.findall("aaa", "baaaa"))  # >>['aaa']
```



#### re.finditer函数

`re.finditer(pattern, string, flags = 0)`

+ 查找字符串中所有和模式匹配的子串（不重叠），每个子串对应于一个**匹配对象**，返回一个匹配对象的序列

  准确说是“可调用迭代器”

```python
import re

s = '233[32]88ab<433>(21)'
m = '\[\d+\]|<\d+>'  # | 表示或
for x in re.finditer(m, s):  # x是匹配对象
    print(x.group(), x.span())
i = 0
for y in re.finditer(m, "aaaaa"):
    i += 1  # 不会被执行
    
# 输出：
# [32] (3, 7)
# <433> (11, 16)
```



#### re.sub替换匹配的字串

`re.sub(模式，替换串，母串)`

+ 用于替换匹配的子串

```python
import re
str = re.sub('\d+', '...', 'abc13de4fg')
print(str)  # >>abc...de...fg
print(re.sub('\d+', "", "abc13de4fg"))  # >>abcdefg
print(re.sub('gone', 'go', "I gone hegone me"))  # >>I go hego me
```





### 四、边界符号

| 边界符号 | 功能                                                       |
| -------- | ---------------------------------------------------------- |
| \A       | 表示字符串的**左边界**，即要求从此往左边不能有任何字符     |
| \Z       | 表示字符串的**右边界**，即要求从此往右边不能有任何字符     |
| ^        | 与\A同。但**多行匹配**模式下还可以表示一行文字的**左边界** |
| $        | 与\Z同。但**多行匹配**模式下还可以表示一行文字的**右边界** |
| \b       | 表示此处应为单词的左边界或右边界，即**不可是单词**字符     |
| \B       | 表示此处不允许是单词的左边界或右边界，即**必须是单词**字符 |

==**边界符号本身不会和任何字符匹配,只是作为一个判断条件**==

+ python字符串`'\Z'`, `'\A'`都是两个字符，而不是像`'\n'`那样的字符。

  ```python
  print('\A\Z')	# >>\A\Z
  ```
  
+ 正则表达式的边界符号`'\b'`是两个字符。但是在python字符串中，`'\b'`和`'\t'`，`'\n'`类似，是***一个字符***（Backspace）。因此**在python正则表达式中使用边界符号`\b`，要写`'\\b'`。**如果写`'\\\\b'`，则连续的两个`\'`被看做是一个普通的`'\'`，不会和后面的`'b'`一起被当做字符组合，变成边界符号`'\b'`。

  ```python
  print("\\b")	# >>\b
  ```

+ python字符串`'\B'`是两个字符



```python
import re


def search(pattern, string):
    x = re.search(pattern, string)
    if x is not None:
        print(x.group(), x.span())  # 输出子串及起止位置
    else:
        print("None")

pt = "ka\\b.*"
search(pt, "ka")    # >>ka (0, 2)
search(pt, "kax")   # >>None
search(pt, "ka?d")  # >>ka?d (0, 4)
pt = ".*\\bka\\b"
search(pt, "ka")    # >>ka (0, 2)
search(pt, "ska?")  # >>None
search(pt, "b?ka?") # >>b?ka (0, 4)

m = r"\bA.*N\b T"   # >>等价于 m = "\\bA.*N\\b T"
search(m, "Ass$NC TK")  # >>None
search(m, "this Ass$N TK")  # >>Ass$N T (5, 12)
m = "\BA.*N\B\w T"
search(m, "this Ass$N TK")  # >>None
search(m, "thisAss$NM TK")  # >>Ass$NM T (4, 12)
search(m, "Ass$NM TK")   # >>None
search(m, "xAss$NM TK")  # >>Ass$NM T (1, 9)
pt = "\\b高兴"
search(pt, "我高兴")   # >>None
search(pt, "我 高兴")  # >>高兴 (2, 4)
```





### 五、分组

#### （...)

##### 括号中的表达式是一个分组。多个分组按==*左括号*==从左到右==*从1开始*==依次编号

```python
import re
x = re.search('[a-z]+(\d+)[a-z]+', "ab 123d hello553world47")
print(x.group(1))           # >>553
m = "(((ab*)c)d)e"   # 分组1:(((ab*)c)d) 分组2: ((ab*)c) 分组3:(ab*)
r = re.match(m, "abcdefg")
print(r.group(0))           # >>abcde   group(0) 等价于 group()
print(r.group(1))           # >>abcd
print(r.group(2))           # >>abc
print(r.group(3))           # >>ab
print(r.groups())           # >>('abcd', 'abc', 'ab')	元组
```

+ `group(0)`直接返回匹配的字符串，`group(i)`返回匹配字符串中的第i个分组的内容
+ `groups()`返回所有分组组成的元组

```python
import re
m = "(ab*)(c(d))e"
r = re.match(m, "abcdefg")
print(r.groups())   # >>('ab', 'cd', 'd')
print(r.group(0))   # >>abcde
print(r.group(1))   # >>ab
print(r.group(2))   # >>cd
print(r.group(3))   # >>d
```



##### 在分组的右边可以通过分组的编号引用==该分组匹配的字符串==

```python
import re
m = r'(((ab*)c)d)e\3'   # \3表示ab*cde后面要跟着一个3号分组本次匹配中匹配上的子串
r = re.match(m, "abbbcdeabbb")
# group(3)为abbb，因此abbbcde后面要跟上abbb，整个串才能匹配成功，少一个b都不行
print(r.group(3))       # >>abbb
print(r.group())        # >>abbbcdeabbb

pt = 'a(.)\\1*b'    # 或pt = r'a(.)\1*b)  \1表示1号分组出现0到任意次
print(re.search(pt, 'kacccccb').group())    # >>acccccb
print(re.search(pt, 'kaxxxxb').group())     # >>axxxxb
print(re.search(pt, 'kaxb').group())        # >>axb
x = re.search(pt, 'kaxyb')  # 匹配不上 x后必须出现字母x
if x is not None:
    print(x.group())
```



##### 分组作为一个整体，后面可以跟量词

```python
import re
m = "(((ab*)+c)d)e"     # +表示(ab*)可出现1到任意次，不要求每次都一样
r = re.match(m, "ababbcdefg")
print(r.groups())   # >>('ababbcd', 'ababbc', 'abb')
print(r.group())    # >>ababbcde

r = re.match(m, "abacdefg")
print(r.groups())   # >>('abacd', 'abac', 'a')  3号分组最后一次配的是'a'
```

+ 不要求每次出现都相同



#### re.findall和分组

+ 在正则表达式中没有分组时，`re.findall`返回所有**匹配子串构成的列表**。

+ ***有且只有一个分组***时，`re.findall`返回的是一个子串的列表，每个元素是一个匹配子串中分组对应的内容。

```python
import re
m = '[a-z]+(\d+)[a-z]+'     # 两边被字母夹着的数
x = re.findall(m, "13 bc12de ab11 cd320ef")
print(x)    # >>['12', '320']
```

+ ***超过一个分组***时，`re.findall`返回的是一个**元组的列表**，每个元组对应一个匹配的子串，元组里的元素，依次是1号分组、2号分组、...匹配的内容

```python
import re
m = '(\w+) (\w+)'   # 两个单词，中间空格
r = re.match(m, "hello world")
print(r.groups())   # >>('hello', 'world')
print(r.group(1))   # >>hello
print(r.group(2))   # >>world
r = re.findall(m, 'hello world, this is very good')
print(r)    # >>[('hello', 'world'), ('this', 'is'), ('very', 'good')]
```



### 六、| 的用法

**表示‘或‘，如果没有放在“()"中，则其作用范围是直到整个正则表达式开头或结尾或另一个“|”**

`\w{4}ce|c|d{3}|p\w`可以匹配：

+ `"c773"`
+ `"ab12ce"`
+ `"pk"`

##### 从左到右短路匹配

> 匹配上一个后就不计算是否还能匹配后面的

```python
import re
pt = "\d+\.\d+|\d+" # 小数或整数（正）
print(re.findall(pt, "12.34 this is 125"))  # >>['12.34', '125']
pt = "aa|aab"
print(re.findall(pt, "aabcdeaa12aab"))  # >>['aa', 'aa', 'aa'] (不会匹配到aab)
```

##### |也可以用于分组中，其作用范围仅限于分组内

```python
import re

m = "(((ab*)+c|12)d)e"
print(re.findall(m, 'ababcdefgKK12deK'))
# >>[('ababcd', 'ababc', 'ab'), ('12d', '12', '')]
for x in re.finditer(m, "ababcdefgKK12deK"):
    print(x.groups())
# >>('ababcd', 'ababc', 'ab')
# >>('12d', '12', None)
m = '\[(\d+)\]|<(\d+)>'
for x in re.finditer(m, '233[32]88ab<433>'):
    print(x.group(), x.groups())
# >>[32] ('32', None)
# >><433> (None, '433')
```



### 七、贪婪模式和懒惰模式

#### 量词的贪婪模式

**量词`+, *, ?, {m, n}`默认匹配尽可能长的子串**

```python
import re
print(re.match("ab*", "abbbbk").group())    # >> abbbb
print(re.findall("<h3>(.*)</h3>", "<h3>abd</h3><h3>bcd</h3>"))  # 本意是匹配 abd和 bcd
# >>['abd</h3><h3>bcd']
print(re.findall('\(.+\)', "A dog has(have a).这(哈哈) true()me"))
```



#### 量词的懒惰模式

**在量词`+, *, ?, {m, n}`后面加`?`则匹配尽可能短的字符串。**

```python
import re

m = "a.*?b"
for k in re.finditer(m, "aabab"):
    print(k.group(), end=" ")   # >>aab ab
m = "<h3>.*?</h3>"
a = re.match(m, "<h3>abd</h3><h3>bcd</h3>")
print(a.group())    # >><h3>abd</h3>
m = "<h3>.*?[M|K]</h3>"
a = re.match(m, "<h3>abd</h3><h3>bcK</h3>")
print(a.group())    # >><h3>abd</h3><h3>bcK</h3>

print(re.findall('\d+?', "this is 334 what me 774gw"))
# >>['3', '3', '4', '7', '7', '4']
print(re.findall('[a-zA-Z]+?', "A dog has 4 legs.这是true"))
# >>['A', 'd', 'o', 'g', 'h', 'a', 's', 'l', 'e', 'g', 's', 't', 'r', 'u', 'e']
print(re.findall('\(.*?\)', "A dog has(have).这(哈哈)true()me"))
# >>['(have)', '(哈哈)', '()']
```



### 八、匹配对象（匹配成功时的返回结果）

#### 匹配对象的属性

+ string：匹配时使用的母串
+ ***lastindex***:最后一个被匹配的分组的编号（**不是最大编号**）。如果没有被匹配的分组，将为None。



#### 匹配对象的函数

##### `group([n1, n2, ...])`

+ 获得一个或多个分组匹配的字符串；**指定多个参数时将以元组形式返回**。n1, n2...可以使用编号也可以使用名字;
+ 编号0代表整个匹配的子串（与模式里的`()`无关）；
+ **`group()`等价于`group(0)`**
+ 没有匹配字符串的组返回None;
+ 匹配了多次的组返回最后一次匹配的子串

##### `groups[default]`

+ 以元组形式返回全部分组匹配的字符串。相当于调用group(1, 2, ..., last)。**default表示没有匹配字符串的组以这个值替代**，默认为None。

##### `groupdict[default]`

+ 返回**以有名字的组的名字为键，以该组匹配的子串为值**的字典，没有名字的组不包含在内。default含义如上

##### `start([group])`

+ 返回指定的组匹配的子串在string中的起始位置。group默认值为0.

##### `end([group])`

+ 返回指定的组匹配的子串在string中的结束位置（子串最后一个字符的位置+1）。group默认值为0。

##### `span([group])`

+ 返回（start(group), end(group)）。
+ group可以是组编号，也可以是组名字，默认为0

```python
import re

m = re.match(r'(\w+) (\w+)(.)', 'hello world!ss')
print(m.string)  # >>hello world!ss
print(m.lastindex)  # >>3
print(m.group(0, 1, 2, 3))  # >>('hello world!', 'hello', 'world', '!')
print(m.groups())   # >>('hello', 'world', '!')
print(m.start(2))   # >>6
print(m.end(2))     # >>11
print(m.span(2))    # >>(6, 11)
```



### 九、应用实例

####诸葛亮口中的曹操

找出三国演义中，诸葛亮提到曹操的所有场景，他是怎么说的

##### 模式：

孔明曰：“倘曹操引兵来到，当如之何？”

孔明曰：“公瑾主意预降操，甚为合理。”

孔明答曰：“曹操乃汉贼也，又何必问?”

孔明笑曰：“今操引百万之众，...”

> ：“都是中文的



##### 代码

```python
import re

f = open("三国演义utf8.txt", "r", encoding="utf-8")
txt = f.read()
f.close()
pt = "(孔明.{0,2}曰：“[^”]*(曹操|曹贼|操贼|曹阿瞒|操).*?”)"	# 曰和曹操之间不能出现”
a = re.findall(pt, txt)
print(len(a))	# >>58
for x in a:		# x形如：('孔明答曰：“曹操乃汉贼也，又何必问?”', '操')
    print(x[0])
```



#### 抽取IP地址、邮箱、网址

```python
import re

ipadr = r"\b((25[0-5]|2[0-4]\d|((1\d{2})|([1-9]?\d)))\.){3}(25[0-5]|2[0-4]\d|((1\d{2})|([1-9]?\d)))\b"
mailbox = r"\b[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+\b"
url = r'http://[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(\.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+(/[-a-zA-Z0-9]+)*\b'

s = 'My ip is 223.44.3.4, this is' \
    'http://www.pku.edu.cn/python/new, http://www.sohu.com' \
    'my mailbox is guo_wei@pku.edu.cn. ok?'

m = re.search(ipadr, s)
if m is not None:
    print(m.group())    # >>223.44.3.4
```





###十、简化正则表达式的编写

一般来说，要写一个精确的正则表达式，比如写一个正则表达式来匹配IP地址，要做要匹配它的字符串一定是IP地址，且凡是IP地址一定能匹配它，是比较困难的。

正则表达式可以写的宽容一些，即IP地址一定能匹配它，但是能匹配它的不一定是IP地址。对匹配的字符串，另外再做一些额外的判断排除掉非IP地址，这样做比写精确的正则表达式容易。

例如：`\d+\.(\d{1,3}\.){2}\d+`

然后再split以后手动判断每一段是不是小于255




****
## Python数据库编程

### 一、数据库和SQL语言简介

#### 数据库的概念

+ 数据库可以用来存放大量数据，并且提供了方便的快速检索手段
+ 便于快速找出符合某种条件的数据。比如：工作年限超过三年，工资超过10000元的北京员工
+ 一个数据库可以是一个文件，比如：`c:/tmp/students.db`

#### 数据库中的表

+ 一个数据库文件里可以有多张表。比如`students.db`里包含“学生信息表”和“课程信息表”
+ 表由记录构成，比如“学生信息表”里的每个记录，代表一个学生的信息
+ 记录由字段构成，描述一个事物的多个属性。比如学生记录，可以由name, id, age, gender, gpa等字段构成

#### 字段

+ 字段是有类型的。比如：

  | 字段名        | 数据类型 |                             |
  | ------------- | -------- | --------------------------- |
  | name          | text     | 字符串                      |
  | gpa           | real     | 小数                        |
  | age           | integer  | 整数                        |
  | profile       | text     | 字符串                      |
  | photo         | blob     | 二进制数据（如图片）        |
  | birthday      | date     | 日期（本质上就是text）      |
  | register time | datetime | 日期+时间（本质上也是text） |

#### SQL数据库查询语句

SQL命令：用于进行数据库操作的标准语句

| 语句         | 功能           |
| ------------ | -------------- |
| CREATE TABLE | 创建表         |
| INSERT INTO  | 在表中插入记录 |
| UPDATE       | 在表中更新记录 |
| SELECT       | 在表中进行查询 |
| DELETE       | 从表中删除记录 |

> 不许分大小写

##### CREATE

```sql
create table if not exists students(
id integer primary key,
name text,
gpa real,
birthday date,
age integer,
picture blob)
```

创建了一张名为students的表，有6个字段。

##### INSERT

```sql
insert into students values(1000, '张三', 3.81, '2000-09-12', 18, null)
```

在表students中插入了一条记录，该记录暂无照片（null）

`values(每个字段的值)`



### 二、创建sqlite3数据库

#### 创建数据库并写入数据

```python
import sqlite3
db = sqlite3.connect('test2.db')    # 连接数据库，若不存在则自动创建
cur = db.cursor()   # 获取光标，要操作数据库一般要通过光标进行
sql = '''create table if not exists students (
id integer primary key,
name text,
gpa real,
birthday date,
age integer,
picture blob)'''
cur.execute(sql)    # 执行sql命令
cur.execute("insert into students values(1600, '张三', 3.81, '2000-09-12', 18, null)")    # 插入一个记录
# 以列表方式插入记录
mylist = [(1700, '李四', "3.25", '2001-12-01', 17, None),
          (1800, '王五', "3.35", '1999-01-01', 19, None)]
for s in mylist:    # 依次插入mylist中的每个记录
    cur.execute('insert into students values(?, ?, ?, ?, ?, ?)',
                (s[0], s[1], s[2], s[3], s[4], s[5]))
db.commit()     # 真正写入，对数据库进行修改操作都需要这条语句
cur.close()     # 关闭光标
db.close()      # 关闭数据库
```



### 三、数据库的查询和修改

#### SELECT

1. 检索students表中全部记录

   ```sql
   select * from students
   ```

2. 检索students表中全部记录，并按年龄排序

   ```sql
   select * from students order by age
   ```

3. 检索students表中全部记录，但每个记录只取name和age字段

   ```sql
   select name, age from students
   ```

4. 检索students表中全部***name为张三***的记录。

   ==where表示检索条件==

   ```sql
   select * from students where name = '张三'
   ```

5. 检索students表中全部***名为张三***且***年龄大于20***的人，结果按***年龄降序***排列

   ```sql
   select * from students where name = '张三' and age > 20 order by age desc
   ```



#### 检索数据库

##### 例1

```python
import sqlite3

db = sqlite3.connect("test2.db")
cur = db.cursor()
sql = 'select * from students'  # 检索全部记录
cur.execute(sql)
x = cur.fetchone()      # fetchone取满足条件的第一条记录（返回元组）
print(x)        # >>(1600, '张三', 3.81, '2000-09-12', 18, None)
print(x[1])     # >>张三
for x in cur.fetchall():  # fetchall取得满足条件的所有记录
    print(x[:-2])   # age,picture字段不打出
cur.execute("select * from students where name = 'Jack'")
x = cur.fetchone()
if x is None:
    print("can't find Jack")
cur.close()
db.close()
```

输出：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220123144850839.png" alt="image-20220123144850839" style="zoom: 50%;" />

##### 例2

```python
import sqlite3
db = sqlite3.connect("test2.db")
cur = db.cursor()
sql = 'select name, gpa, age from students where gpa > 3.3 order by age desc'
# 查找gpa>3.3的学生中的三个字段，按年龄降序
cur.execute(sql)
x = cur.fetchall()  # 返回所有记录（元组）的列表
if x != []:     # 能查到记录
    print("total: ", len(x))    # >>total: 2
    for r in x:  # 遍历列表，打印所有记录
        print(r)    # >>('王五', 3.35, 19) \n ('张三', 3.81, 18)
cur.close()
db.close()

```



#### UPDATE

1. 将所有记录的gpa设置成3.9

   ```sql
   update students set gpa = 3.9
   ```

2. 修改李四的gpa和年龄

   ```sql
   update students set gpa = 3.9, age = 18 where name = '李四'
   ```

#### 更新数据库

```python
import sqlite3

db = sqlite3.connect("test2.db")
cur = db.cursor()
sql = 'update students set gpa = ?, age = ? where name = ?'
cur.execute(sql, (4.0, 20, '李四'))  # 元组的三个元素分别对应 3个？
# 修改李四的gpa和年龄。若李四不存在，则无效果
db.commit()  # 此语句不可忽略
sql = "select * from students"
cur.execute(sql)
for x in cur.fetchall():
    print(x)
cur.close()
db.close()
```

输出：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220123150837597.png" alt="image-20220123150837597" style="zoom:50%;" />



#### DELETE

1. 删除年龄小于18的记录

   ```sql
   delete from students where age < 18
   ```

2. 删除全部记录

   ```sql
   delete from students
   ```

3. ==别忘了最后的`db.commit()`==



#### DROP TABLE

+ 删除整个students表

  ```sql
  drop table if exists students
  ```

+ `db.commit()`

```python
import sqlite3
db = sqlite3.connect("test2.db")
cur = db.cursor()
cur.execute("drop table if exists students")
db.commit()
try:
    cur.execute("select * from students")
    x = cur.fetchall()
    for r in x:
        print(r[:-1])
except:
    print("No table")       # >>No table
cur.close()
db.close()
```



#### 注意事项：

1. 对于修改表的操作，如插入、删除、更新，关闭数据库前不要忘了`commit`，否则操作无效
2. 必要时用`try...except`语句来避免数据库不存在，否则可能出现runtime error



### 四、处理二进制字段

#### 设置blob字段（二进制字段的值）

##### 添加本地图片

```python
import sqlite3
f = open('balloons.jpg', 'rb')  # 以二进制方式打开图片
img = f.read()
f.close()
db = sqlite3.connect("test2.db")
cur = db.cursor()
sql = "update students set picture = ? where name = '李四'"
cur.execute(sql, (img,))    # 设置李四的照片。img对应？
```

##### 从网络上获取图片

```python
import sqlite3
import requests

db = sqlite3.connect("test2.db")
cur = db.cursor()
# 从网络获取图片
imgUrl = "http://img5.duitang.com/uploads/item/201605/19/20150519224441_VfMWR.jpeg"
imgStream = requests.get(imgUrl, stream=True)
sql = "update students set picture = ? where name = '张三'"
cur.execute(sql, (imgStream.content, ))  # 设置张三的照片。img对应于？

db.commit()
cur.close()
db.close()
```



#### 读取blob字段（二进制字段）的值：

```python
import sqlite3
import requests

db = sqlite3.connect("test2.db")
cur = db.cursor()
sql = "select name, picture from students where name = '张三' or name = '李四'"
cur.execute(sql)
x = cur.fetchall()
for r in x:     # r[0]是姓名，r[1]是图片文件数据
    f = open(r[0] + '.jpg', 'wb')   # 照片写入 张三.jpg 和 李四.jpg
    f.write(r[1])
    f.close()
cur.close()
db.close()
```



****

## 玩转Python生态

### 一、Python库的使用

#### import 的用法

```python
import turtle        # turtle是一个类

import turtle as tt  # 此后tt等价于turtle

import PIL.Image    # PIL.Image是类中的类

from PIL import Image   # 从PIL库导入Image类进行图像处理

import PIL.Image, PIL.ImageDraw, PIL.ImageFont  # 同时引入多个类

from PIL import Image, ImageDraw, ImageFont

from openpyxl.styles import Font, colors, Alignment
```



### 二、datetime库处理日期、时间

> 能处理的时间，年份是公元0001年至9999年

#### 处理日期

+ 日期对象date的成员：year，month，day
+ 时间差对象timedalta

+ `datetime.date.weekday()`：返回日期对象对应星期几（***0代表星期一***）
+ `datetime.date.today()`：返回今天的日期对象
+ `datetime.date.strftime(r'%m/%d/%Y')`：指明日期的格式
+ `datetime.date.strptime("2020.08.05", "%Y.%m.%d")`:  **将日期转成日期对象**

```python
import datetime

dtBirth = datetime.date(2000, 9, 27)    # 创建日期对象，日期为2000年9月17日
print(dtBirth.weekday())    # >>2  输出dtBirth代表的日期是星期几。0表示星期一

dtNow = datetime.date.today()   # 取今天日期（2022-2-2）
print(dtBirth < dtNow)      # >>True    日期可以比大小

life = dtNow - dtBirth      # 取两个日期的时间差
print(life.days, life.total_seconds())  # >>7798 673747200.0

delta = datetime.timedelta(days=-10)     # 构造时间差对象，时间差为-10天
newDate = dtNow + delta     # newDate代表的日期是dtNow的日期往前数10天
print(newDate.year, newDate.month, newDate.day, newDate.weekday())  # >>2022 1 23 6 （2022年1月23日 星期日）

print(newDate.strftime(r'%m/%d/%Y'))    # >>01/23/2022
newDate = datetime.datetime.strptime("2000.08.05", "%Y.%m.%d")
print(newDate.strftime("%Y%m%d"))   # >>20000805
```

#### 处理时刻

+ 时刻对象datetime的成员：year，month，day，hour，minute，second，microsecond

+ `datetime.datetime.now()`: 取当前时刻，精确到微秒

```python
import datetime

tm = datetime.datetime.now()    # 取当前时刻，精确到微秒
print(tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second, tm.microsecond)
# >>2022 2 2 21 42 12 136760    当前时刻是 2022年 8月 15日 21时 42分 12秒 136760微秒
tm = datetime.datetime(2017, 8, 10, 15, 56, 10, 0)
# 构造一个时刻，2017年8月10日15时56分10秒0微秒
print(tm.strftime("%Y%m%d %H:%M:%S"))   # >>20170810 15:56:10
print(tm.strftime("%Y%m%d %I:%M:%S %p"))    # >>20170810 03:56:10 PM

tm2 = datetime.datetime.strptime("2013.08.10 22:31:24", "%Y.%m.%d %H:%M:%S")    # 由字符串生成一个时间对象
delta = tm - tm2    # 求两个时刻的时间差
print(delta.days, delta.seconds, delta.total_seconds())
# >>1460 62686 126206686.0  时间差是1460天62686秒，总共126206686.0秒
delta = tm2 - tm
print(delta.days, delta.seconds, delta.total_seconds())
# >> -1461 23714 -126206686.0

delta = datetime.timedelta(days=10, hours=10, minutes=30, seconds=20)
# 构造一个时间差，10天10小时30分20秒
tm2 = tm + delta
print(tm2.strftime("%Y%m%d %H:%M:%S"))  # >>20170821 02:26:30
```





### 三、random库处理随机数相关事务

#### random库中的函数

| 函数                      | 功能                                                        |
| ------------------------- | ----------------------------------------------------------- |
| random.random()           | 随机生成一个[0,1]之间的数                                   |
| random.uniform(x, y)      | 随机生成一个[x, y]时间的数（含两端，下同）。x, y可以是小数  |
| random.randint(x, y)      | 随机生成一个[x, y]之间的整数。x, y 都是整数                 |
| random.randrange(x, y, z) | 在`range(x, y, x)`中随机取一个数                            |
| random.choice(x)          | 从序列x中随机取一个元素。x可以是为列表、元组、字符串        |
| random.shuffle(x)         | 将列表x的元素顺序随机打乱                                   |
| random.sample(x, n)       | 从序列x中随机取一个长度为n的子序列。x可以是元组、列表、集合 |
| random.seed(x)            | 设置随机种子为x。x可以是个数、元组、字符串                  |

##### 代码示例

```python
import random

print(random.random())      # >>0.2513304445557907
print(random.uniform(1.2, 7.8))  # >>1.7099692554739307
print(random.randint(-20, 70))      # >>-19
print(random.randrange(2, 30, 3))   # >>8
print(random.choice("hello,world"))  # >>l

lst = [1, 2, 3, 4, 5, 6]
random.shuffle(lst)
print(lst)  # >>[5, 4, 6, 1, 2, 3]
print(random.sample(lst, 3))  # >>[5, 4, 6]
```



#### 设置随机种子

**随机数种子为伪随机算法设置的初始条件（==*默认以当前时间为种子*==），随机种子一样的随机函数运行结果都是一样的**

```python
import random

random.seed(2)  # 或random.seed("ok")...种子可以是任意数、字符串...

# 此时下面程序运行结果每次都一样
print(random.random())      # >>0.2513304445557907
print(random.uniform(1.2, 7.8))  # >>1.7099692554739307
print(random.randint(-20, 70))      # >>-19
print(random.randrange(2, 30, 3))   # >>8
print(random.choice("hello,world"))  # >>l

lst = [1, 2, 3, 4, 5, 6]
random.shuffle(lst)
print(lst)  # >>[5, 4, 6, 1, 2, 3]
print(random.sample(lst, 3))  # >>[5, 4, 6]
```



#### 实现4人玩牌的发牌模拟

```python
import random

cards = [str(i) for i in range(2, 11)]
cards.extend(list("JQKA"))
# cards是 ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
allCards = []   # 一副牌
for s in "♣◇♠♥":    # 梅花、菱形、黑桃、红桃
    for c in cards:
        allCards.append(s+c)    # allCards元素形式如：'♣3'
random.shuffle(allCards)    # 随机打乱52张牌
for i in range(4):
    onePlayer = allCards[i::4]  # 每个玩家都是隔三张牌取一张
    onePlayer.sort()    # 扑克牌排序规则略复杂，这个排序不完美
    print(onePlayer)    # 打印该玩家的牌
```





### 四、jieba库进行分词

中文的分词是个问题。例如：

“买马上战场”应该分成”买 马 上 战场“还是“买 马上 战场”？

即使结巴库也不总是能解决

#### jieba分词示例

```python
import jieba

s = "我们热爱中华人民共和国"
lst = jieba.lcut(s)     # 分词的结果是个列表
# 默认用精确模式分词，分出的结果正好拼成原文
print(lst)  # >>['我们', '热爱', '中华人民共和国']
print(jieba.lcut(s, cut_all=True))  # 全模式分词，输出所有可能组成的词
# >>['我们', '热爱', '中华', '中华人民', '中华人民共和国', '华人', '人民', '人民共和国', '共和', '共和国']
print(jieba.lcut_for_search(s))  # 搜索引擎模式分词
# >>['我们', '热爱', '中华', '华人', '人民', '共和', '共和国', '中华人民共和国']
s = "拼多多是个网站"
print(jieba.lcut(s))    # >>['拼', '多多', '是', '个', '网站']
jieba.add_word("拼多多")   # 往词典里添加新词
print(jieba.lcut(s))    # >>['拼多多', '是', '个', '网站']
```

##### 使用外部词典库

+ tmpdict.txt文件内容如下：

  高克

  丝马

  微中

```python
s = "高克丝马微中"
print(jieba.lcut(s))    # >>['高克丝', '马微', '中']
jieba.load_userdict("tmpdict.txt")
print(jieba.lcut(s))    # >>['高克', '丝马', '微中']
print(jieba.lcut("显微中，容不得一丝马虎"))    # >>['显微', '中', '，', '容不得', '一丝', '马虎']
```



#### 用jieba库找出三国演义中出场次数最多的几个人

**分词后对所有词进行频率统计并输出出现最多的15个词（单个字的词去掉）**

曹操 929， 孔明 825， 将军 756，却说 646，玄德 556，关公 508，丞相 484，二人 459，不可 432，荆州 417，孔明曰 383，不能 380，玄德曰 380，如此 375，张飞 349

```python
import jieba

f = open("三国演义.txt", 'r', encoding="utf-8")
text = f.read()
f.close()
words = jieba.lcut(text)
result = {}		# 集合
for word in words:
    if len(word) == 1:
        continue
    elif word in ("诸葛亮", "孔明曰"):
        word = "孔明"
    elif word in ("关公", "关云长", "云长"):
        word = "关羽"
    elif word in ("玄德", "玄德曰"):
        word = "刘备"
    elif word in ("孟德", "操贼", "曹阿瞒"):
        word = "曹操"
    result[word] = result.get(word, 0) + 1
noneNames = {'将军', '却说', '荆州', '二人', '不可', '不能', '如此',
             '丞相', '商议', '如何', '主公', '军士', '左右', '军马',
             '引兵', '次日'}    # 用集合比列表快
for word in noneNames:  # 删除noneNames中的词
    result.pop(word)
items = list(result.items())	# 集合转列表
items.sort(key=lambda x: -x[1])     # 按出现次数降序
for i in range(15):
    print(items[i][0], items[i][1], end=',')    # 输出 人名 出现次数
```





### 五、openpyxl处理excel文档

#### excel文档相关库

office 2010前.xls文件

+ 用xlrd读取
+ 用xlwt库创建和修改

office 2010及之后的.xlsx文件

+ 用openpyxl读写（官网：openpyxl.readthedocs.io)



#### openpyxl读取excel文件内容

##### 获取工作表

```python
sheet = book.active		# 取活跃的工作表（默认第0张）
sheet = book["price"]	# 取名为“price”的工作表
```

##### 遍历所有工作表，并打出其名字

```python
for sheet in book.worksheets:	# worksheets是工作表构成的列表
    print(sheet.title)
```

##### 单元格属性

|                    |                                                |
| ------------------ | ---------------------------------------------- |
| type(cell.value)   | int/float/str/datetime.datetime                |
| cell.coordinate    | 'A2', 'E3'                                     |
| cell.col_idx       | 单元格列号                                     |
| cell.number_format | 数的显示格式，"General", "0.00%", "0.00E+00"等 |



##### 代码示例

```python
import openpyxl as pxl

book = pxl.load_workbook("test.xlsx")   # book就是整个excel文件
sheet = book.worksheets[0]      # 取第0张工作表
print(sheet.title)              # 输出工作表名字（显示于工作表下方标签）
print(sheet.min_row, sheet.max_row)     # 输出最小有效行号、最大有效行号（有效指非空）
print(sheet.min_column, sheet.max_column)   # 输出最小有效列号、最大有效列号
for row in sheet.rows:  # 按行遍历整个工作表，从第一行到sheet.max_row行（含）
    for cell in row:    # 遍历一行的每个单元格。cell是一个单元格
        print(cell.value, end=' ')   # cell.value是单元格的值。空单元格值是None
    print('')
for cell in sheet['G']:  # 遍历名为'G'的那一列
    print(cell.value, end=' ')
for cell in sheet[3]:   # 遍历第三行
    print(cell.value, type(cell.value), cell.coordinate, cell.col_idx, cell.number_format)
    
    
print(pxl.utils.get_column_letter(5))               # >>E 根据列号求列名
print(pxl.utils.column_index_from_string('D'))      # >>4 根据列名求列号
print(pxl.utils.column_index_from_string('AC'))     # >>29

colRange = sheet['C:F']         # colRange代表从第C列到第F列（含F列）
for col in colRange:            # 按列遍历第C列到第F列，col代表一列
    for cell in col:            # cell是一个单元格
        print(cell.value, end=' ')
    print('')
rowRange = sheet[5:10]          # rowRange代表第5行到第10行（含第10行）
for row in sheet['A1':'D2']:    # 按行遍历 左上角是A1 右下角是D2 的子表
    for cell in row:
        print(cell.value, end=' ')
    print('')
print(sheet['C9'].value)        # 输出C9单元格的值
print(sheet.cell(row=8, column=4).value)    # 输出第8行第4列单元格的值
```



##### 读取公式的计算结果

```python
wb = openpyxl.load_workbook('style.xlsx', data_only=True)	# 将单元格的公式计算出来
```



#### openpyxl创建excel文件

```python
import openpyxl
import datetime

book = openpyxl.Workbook()  # 在内存中创建一个excel文档，注意W是大写
sheet = book.active      # 取第 0个工作表
sheet.title = "sample1"  # 工作表取名为 sample1
dataRows = ((10, 20, 30, 40.5),
            (100, 200, '=sum(A1:B2)'),
            [],
            ['1000', datetime.datetime.now(), 'ok'])
for row in dataRows:
    sheet.append(row)   # 在工作表中添加一行
sheet.column_dimensions['B'].width = len(str(sheet['B4'].value))
# 设置B列宽度，使其能完整显示B4单元格里的时间
sheet['E1'].value = "=sum(A1:D1)"    # 单元格值为公式
sheet['E2'].value = 12.5             # 单元格值为小数
sheet["E2"].number_format = "0.00%"  # 单元格显示格式是百分比形式
sheet['F1'].value = 3500             # 单元格值类型为int
sheet['F2'].value = "35.00"          # 单元格值类型为str（不能做求和等操作）
sheet['F3'].value = datetime.datetime.today().date()
sheet.column_dimensions['F'].width = len(str(sheet['F3'].value))
sheet.row_dimensions[2].height = 48  # 设置第2行高度为48points
sheet2 = book.create_sheet("Sample2")  # 添加名为Sample2的工作表
sheet2['A1'] = 50
sheet2 = book.create_sheet("Sample0", 0)  # 添加名为Sample0的工作表
sheet3 = book.copy_worksheet(sheet)       # 添加一张新工作表，为sheet的拷贝
book.remove_sheet(book['Sample2'])        # 删除名为Sample2的工作表
book.save('sample.xlsx')    # 保存文件
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205022451299.png" alt="image-20220205022451299" style="zoom: 25%;" />



#### 将所有文本形式的数转换为真正的数

```python
import openpyxl as pxl

book = pxl.load_workbook('sample.xlsx')
for sheet in book.worksheets:
    for row in sheet.rows:
        for cell in row:
            v = cell.value
            if type(v) == str:
                if v.isdigit():     # 如果v全部由数字组成
                    cell.value = int(v)
                else:
                    try:
                        cell.value = float(v)   # 如果不是小数格式，转换为引发异常
                    except: pass
book.save('excel1.xlsx')
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205022349825.png" alt="image-20220205022349825" style="zoom:33%;" />



#### 将真正的数转换为文本形式

```python
import openpyxl as pxl

book = pxl.load_workbook('excel1.xlsx')
for sheet in book:
    for row in sheet.rows:
        for cell in row:
            if type(cell.value) == int or type(cell.value) == float:
                cell.value = str(cell.value)
book.save('tmp/excel2.xlsx')
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205022430997.png" alt="image-20220205022430997" style="zoom:33%;" />



#### openpyxl指定单元格的样式

```python
import openpyxl as pxl
from openpyxl.styles import Font, colors, PatternFill, Alignment, Side, Border

book = pxl.Workbook()   # 在内存中创建一个excel文档，注意W是大写
sheet = book.active     # 取第0个工作表
for i in range(4):      # 添加4行5列数据
    sheet.append([i*5 + j for j in range(5)])
side = Side(style='thin')   # 边线类型，还可以是‘thick’，‘medium’，‘dotted'等
border = Border(left=side, right=side, top=side, bottom=side)   # 边框类型
for row in sheet.rows:
    for cell in row:
        cell.border = border    # 为单元格设置边框类型
sheet['A1'].fill = PatternFill(patternType='solid', start_color="006600")   # 单元格底色设置为绿色
a1 = sheet['A1']
italicRedFont = Font(size=18, name='Times New Roman', bold=True, color="660000")
color = "770000"
a1.font = italicRedFont     # 设置单元格字体
sheet['A2'].font = sheet['A1'].font.copy(italic=True)
# A2的字体和A1的字体一样，但是是斜体
sheet.merge_cells('C2:D3')  # 从C2到D3合并为一个单元格，此后名为C2
sheet['C2'].alignment = Alignment(horizontal='left', vertical='center')
# C2文字水平左对齐，垂直居中
book.save("tmp/style.xlsx")
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205024031224.png" alt="image-20220205024031224" style="zoom:33%;" />





### 六、Pillow处理图像

#### 图像的常识

##### 图像由像素构成

屏幕上每个像素由3个距离非常近的点构成（人眼分辨不出来），分别显示红绿蓝三种颜色，每个像素可以由一个元组(r, g, b)表示，r,g,b通常是不超过255的整数

##### 图像模式

+ RGB: 一个像素有红绿蓝三个分量
+ RGBA：红绿蓝以及透明度
+ CYMK：青色（Cyan）、洋红色（Magenta）、黄色（Yellow）、黑色（K)四个分量，即每个像素用元组(c, y, m, k)表示，**对应于彩色打印机或印刷机的四种颜色的墨水**。
+ L:灰度图。每个像素为一个整数，表示灰度

#### 图像缩放

```python
from PIL import Image

img = Image.open('tmp/balloons.jpg')    # 将图像文件载入对象img
w, h = img.size     # 获取图像的宽和高（单位：像素），img.size是个元组
newSize = (w//2, h//2)  # 生成一个新的图像尺寸
newImg = img.resize(newSize)    # 得到一张原图像一半(bushi)大小的新图像
newImg.save('tmp/balloons_half.jpg')    # 保存新图像文件
newImg.thumbnail((128, 128))    # 变成宽高个128像素的缩略图
newImg.save('tmp/balloons_thumb.png', "PNG")    # 保存为.png文件
newImg.show()   # 显示图像
```

balloons.jpg:                                                                                               balloons_half.jpg

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205025715549.png" alt="image-20220205025715549" style="zoom:25%;" /><img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205025750942.png" alt="image-20220205025750942" style="zoom:25%;" />
balloons_thumb.png
<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205025807976.png" alt="image-20220205025807976" style="zoom:25%;" />



#### 图像旋转、翻转图像和滤镜效果

```python
from PIL import Image
from PIL import ImageFilter     # 实现滤镜效果需要

img = Image.open('tmp/balloons_half.jpg')
print(img.format, img.mode)     # >>JPEG RGB
newImg = img.rotate(90, expand=True)    # 图像逆时针旋转90度
newImg.show()
newImg = img.transpose(Image.FLIP_LEFT_RIGHT)   # 左右翻转
newImg.show()
newImg = img.transpose(Image.FLIP_TOP_BOTTOM)   # 上下翻转（颠倒）
newImg.show()
newImg = img.filter(ImageFilter.BLUR)   # 模糊效果
newImg.show()
```

##### 滤镜效果

+ 轮廓效果

  ```python
  ImageFilter.CONTOUR
  ```

+ 边缘增强

  ```python
  ImageFilter.EDGE_ENHANCE
  ```

+ 浮雕

  ```python
  ImageFilter.EMBOSS
  ```

+ 平滑

  ```python
  ImageFilter.SMOOTH
  ```

+ 锐化

  ```python
  ImageFilter.SHARPEN
  ```



#### 图像裁剪

```python
from PIL import Image

img = Image.open('tmp/balloons.jpg')
w, h = img.size[0]//3, img.size[1]//3
gap = 10        # 九宫图中相邻两幅子图间的空白宽10像素
newImg = Image.new("RGB", (w*3 + gap*2, h*3 + gap*2), 'white')
for i in range(0, 3):
    for j in range(0, 3):
        clipImg = img.crop((j*w, i*h, (j+1)*w, (i+1)*h))    # 四个参数为左上角和右下角的坐标
        clipImg.save('tmp/balloons%d%d.jpg' % (i, j))
        newImg.paste(clipImg, (j*(w+gap), i*(h+gap)))   # 往newImg上贴9张图
newImg.save('tmp/balloons9.jpg')    # 保存九宫图
newImg.show()
```

效果：

balloon9.jpg:<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205124355638.png" alt="image-20220205124355638" style="zoom:25%;" />



#### 图像素描化

```python
from PIL import Image

def makeSketch(img, threshold):
    w, h = img.size
    img = img.convert('L')      # 图像转换成灰度模式
    pix = img.load()            # 获取像素矩阵
    for x in range(w-1):
        for y in range(h-1):
            if abs(pix[x, y] - pix[x+1, y+1]) >= threshold:  # 相邻像素灰度差大于threshold，说明找到边界，将pix[x,y]变成黑色
                pix[x, y] = 0
            else:
                pix[x, y] = 255     # 灰度值差距不大，全部变白
    return img

img = Image.open('tmp/balloons_half.jpg')
img = makeSketch(img, 15)   # 阈值threshold为15
img.show()
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205125834976.png" alt="image-20220205125834976" style="zoom:25%;" />



#### 图像加水印

##### 原理：`imgSrc.paste(img, (x, y), mask = msk)`

+ paste函数可以用“掩膜”指定img的每个像素粘贴过去的透明度。如果透明度为0，则完全透明；透明度为255，则完全遮盖imgSrc原来的像素
+ mask参数即为“掩膜”，是个模式为’L'的图像（Image对象）

```python
from PIL import Image

def getMask(img, isTransparent, alpha):  # img为水印图，isTransparent为判断透明度的函数，alpha为透明度
    if img.mode != 'RGBA':
        img = img.convert('RGBA')   # 转换成RGBA模式的图像
        w, h = img.size
        pixels = img.load()         # 获取像素矩阵
        for x in range(w):
            for y in range(h):
                p = pixels[x, y]    # p是一个四元元组(r,g,b,a)
                if(isTransparent(p[0], p[1], p[2])):    # 判断p是否应该变成透明像素
                    # p[0], p[1], p[2] 分别是红绿蓝分量
                    pixels[x, y] = (p[0], p[1], p[2], 0)
                else:
                    pixels[x, y] = (p[0], p[1], p[2], alpha)
    r, g, b, a = img.split()    # 分离出img中的四个分量，a就是掩膜
    return a    # 返回由img变出来的掩膜


img = Image.open('tmp/balloons01.jpg')  # 水印图片
msk = getMask(img, lambda r, g, b: r > 245 and g > 245 and b > 245, 130)
# lambda表达式说明接近白色的像素被判定成透明
imgSrc = Image.open('tmp/balloons_half.jpg')
imgSrc.paste(img, (imgSrc.size[0] - img.size[0] - 30,
                   imgSrc.size[1] - img.size[1] - 30), mask=msk)
# 水印位于imgSrc的右下角，用a做掩膜
imgSrc.show()
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205131510881.png" alt="image-20220205131510881" style="zoom:25%;" />


#### 图像上绘图和文字

##### 照片的exif信息：包含图片的属性和个人信息.Pillow库提供了函数获取这些信息

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220205132114008.png" alt="image-20220205132114008" style="zoom:25%;" />：

```python
from PIL import Image, ImageDraw, ImageFont, ExifTags

def correctOrientation(img):
# 根据exif判断，img里的图像若有颠倒或旋转则生成一副将其摆正的图返回
    if hasattr(img, "_getexif"):    # 判断img有没有_getexif函数
        exif = img._getexif()       # 获取图像exif信息，返回值是个字典
        if exif is not None:
            orientation = exif[getExifKeyCode('Orientation')]
            if orientation == 3:    # 手机顶部朝右拍
                img = img.rotate(180, expand=True)
            elif orientation == 6:  # 手机正常竖着拍（顶部朝上）
                img = img.rotate(170, expand=True)
            elif orientation == 8:  # 手机顶部朝下拍
                img = img.rotate(90, expand=True)
    return img

def getExifKeyCode(keyStr):     # 根据属性名称求字符串求属性代号
    for x in ExifTags.TAGS.items():
        if x[1] == keyStr:
            return x[0]
    return None

def writeTextToImage(img, text, myFont):
    # 在img中以字体myFont在右下角写入字符串text
    # 会改变img中的图像
    w, h = img.size
    fw, fh = myFont.getsize(text)       # 求text显示出来的高度，宽度
    draw = ImageDraw.Draw(img)          # 以后就可以通过draw在img上画图、写字
    x, y = w - fw - 30, h - fh - 30     # 计算text的左上角的位置
    draw.rectangle((x-5, y-5, x + fw + 5, y + fh + 5), outline='white')
    draw.text((x, y), text, (255, 255, 255), font=myFont)
```



*****

## Python数据分析

### 一、多维数组库numpy

#### numpy简介

+ 多维数组库，创建多维数组很方便，可以替代多维列表
+ 速度比多维列表快
+ 支持向量和矩阵的各种数学运算
+ 所有元素类型必须相同

#### numpy创建数组的函数

| 函数                    | 功能                                                  |
| ----------------------- | ----------------------------------------------------- |
| array(x)                | 根据列表或元组x创建数组                               |
| arange(x, y, i)         | 创建一维数组，元素等价于`range(x, y, i)`              |
| ==linspace(x, y, n)==   | 创建一个由区间[x, y]的n等分点构成的一维数组，包含x和y |
| ==random.randint(...)== | 创建一个元素为随机整数的数组                          |
| zeros(n)                | 创建一个元素全为0.0的长度为n的数组                    |
| ones(n)                 | 创建一个元素全为1.0的长度为n的数组                    |

##### numpy创建数组示例

```python
import numpy as np

print(np.array([1, 2, 3]))      # >>[1 2 3]
print(np.arange(1, 9, 2))       # >>[1 3 5 7]
print(np.linspace(1, 10, 4))    # >>[ 1.  4.  7. 10.]
print(np.random.randint(10, 20, [2, 3]))    # [10,20) 2行3列
# >>[[14 12 15]
# >> [16 16 14]]
print(np.random.randint(10, 20, 5))  # >>[19 10 15 12 13]
a = np.zeros(3)
print(a)        # >>[0. 0. 0.]
print(list(a))  # >>[0.0, 0.0, 0.0]
a = np.zeros((2, 3), dtype=int)  # 创建一个2行3列全为整数0的数组
```



#### numpy数组常用属性和函数

| 属性或函数    | 含义或功能       |
| ------------- | ---------------- |
| dtype         | 数组元素的类型   |
| ndim          | 数组维数         |
| shape         | 数组每一维的长度 |
| size          | 数组元素个数     |
| argwhere(...) | 查找元素         |
| tolist()      | 转换为list       |
| min()         | 求最小元素       |
| max()         | 求最大元素       |
| reshape(...)  | 改变数组的形状   |
| flatten()     | 转换成一维数组   |

##### numpy属性和函数示例

```python
import numpy as np

b = np.array([i for i in range(12)])
# b是[ 0  1  2  3  4  5  6  7  8  9 10 11]
a = b.reshape((3, 4))   # 转换成3行4列的数组，b不变
print(len(a))   # >>3   a有3行
print(a.size)   # >>12  a的元素个数是12
print(a.ndim)   # >>2   a是2维的
print(a.shape)  # >>(3, 4)  a是3行4列
print(a.dtype)  # >>int32   a的元素类型是32位的整数
L = a.tolist()  # 转换成列表，a不变
print(L)        
# >>[[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11]]
b = a.flatten()  # 转换成一维数组
print(b)        # >>[ 0  1  2  3  4  5  6  7  8  9 10 11]
```



#### numpy数组元素增删

| 函数             | 功能                                                    |
| ---------------- | ------------------------------------------------------- |
| append(x, y)     | 若y是数组、列表或元组，就将y的元素添加进数组x得到新数组 |
| concatenate(...) | 拼接多个数组或列表                                      |
| delete(...)      | 删除数组元素得到新数组                                  |

##### numpy数组一旦生成，元素就不能增删。上述函数都是==返回新数组==

##### numpy添加数组元素示例

```python
import numpy as np

a = np.array((1, 2, 3))  # a是[1 2 3]
b = np.append(a, 10)    # a不变
print(b)    # >>[ 1  2  3 10]
print(np.append(a, [10, 20]))   # >>[ 1  2  3 10 20]
c = np.zeros((2, 3,), dtype=int)    # c是2行3列全为0的数组
print(np.append(a, c))  # >>[1 2 3 0 0 0 0 0 0]
print(np.concatenate((a, [10, 20], a)))
# >>[ 1  2  3 10 20  1  2  3]
print(np.concatenate((c, np.array([[10, 20, 30]]))))  # c拼接一行[10, 20, 30]得到新数组 
# >>[[ 0  0  0]
#  [ 0  0  0]
#  [10 20 30]]
print(np.concatenate((c, np.array([[1, 2], [10, 20]])), axis=1))    # axis=1表明拼接在列上，行数不变
# c的第0行拼接了1, 2两个元素，第一行拼接了10, 20两个元素，得到新数组
# >>[[ 0  0  0  1  2]
#  [ 0  0  0 10 20]]
```

##### numpy删除数组元素示例

```python
import numpy as np

a = np.array((1, 2, 3, 4))
b = np.delete(a, 1)     # 删除a中下标为1的元素，a不变
print(b)    # >>[1 3 4]
b = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
print(np.delete(b, 1, axis=0))  # 删除b的第一行得到的新数组
# >>[[ 1  2  3  4]
#  [ 9 10 11 12]]
print(np.delete(b, 1, axis=1))  # 删除b的第一列得到的新数组
# >>[[ 1  3  4]
#  [ 5  7  8]
#  [ 9 11 12]]
print(np.delete(b, [1, 2], axis=0))  # 删除b的第1行和第2行得到的新数组
# >>[[1 2 3 4]]
print(np.delete(b, [1, 3], axis=1))  # 删除b的第1和3列得到的新数组
# >>[[ 1  3]
#  [ 5  7]
#  [ 9 11]]
```



#### 在numpy数组中查找元素

```python
import numpy as np

a = np.array((1, 2, 3, 5, 3, 4))
pos = np.argwhere(a == 3)   # pos是[[2] [4]]
a = np.array([[1, 2, 3], [4, 5, 2]])
print(2 in a)   # >>True
pos = np.argwhere(a == 2)   # pos是[[0 1] [1 2]]
b = a[a > 2]    # 抽取a中大于2的元素形成一个一维数组
print(b)        # >>[3 4 5]
a[a > 2] = -1   # 将a中大于2的元素改为-1
```



#### numpy数组的数学运算

```python
import numpy as np

a = np.array((1, 2, 3, 4))
b = a + 1   # b的元素为a的每个元素加1
print(b)        # >>[2 3 4 5]
print(a * b)    # >>[ 2  6 12 20]
print(a + b)    # >>[ 2  6 12 20]   a和b对应元素相加
c = np.sqrt(a * 10)  # a*10是[10, 20, 30, 40]
print(c)        # >>[3.16227766 4.47213595 5.47722558 6.32455532]
```



#### numpy数组的切片

==**numpy数组的切片是“视图”，是原数组的一部分（会修改原数组），而非一部分的拷贝**==

```python
import numpy as np

a = np.arange(8)    # a是[0 1 2 3 4 5 6 7]
b = a[3:6]          # b是a的一部分
print(b)            # >>[3 4 5]
c = np.copy(a[3:6])  # c是a的一部分的拷贝
b[0] = 100          # 会修改a
print(a)            # >>[  0   1   2 100   4   5   6   7]
print(c)            # >>[3 4 5] c不受b影响
a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
b = a[1:3, 1:4]     # 行为[1,3), 列为[1, 4)
# b是[[ 6  7  8]
#     [10 11 12]]
```



### 二、数据分析库pandas

#### pandas简介

+ 核心功能是在二维**表格**上做各种操作，如增删改、求一列数据的和、方差、中位数、平均数等
+ 需要numpy支持
+ 如果有openpyxl或xlrd或xlwt支持，还可以读写excel文档
+ 最关键的类**DataFrame, 表示二维表格**



#### pandas的重要类：Series

+ Series是一维==表格==，每个元素带标签且有下标，兼具列表和字典的访问形式

```python
import pandas as pd

s = pd.Series(data=[80, 90, 100], index=['语文', '数学', '英语'])  # data为元素，index为标签
for x in s:         # >>80 90 100
    print(x, end=' ')
print("")
print(s['语文'], s[1])    # >>80 90 标签和序号都可以作为下标来访问元素
print(s[0:2]['数学'])     # >>90  s[0:2]是切片（视图）
print(s['数学':'英语'][1])  # >>100  标签做切片为闭区间
for i in range(len(s.index)):       # >>语文 数学 英语
    print(s.index[i], end=' ')
s['体育'] = 110       # 在尾部添加元素，标签为体育，值为110
s.pop('数学')         # 删除标签为'数学'的元素
s2 = s.append(pd.Series(120, index=['政治']))  # 不改变s
print(s2['语文'], s2['政治'])   # >>80 120
print(list(s2))     # >>[80, 100, 110, 120]
print(s.sum(), s.min(), s.mean(), s.median())   # 总和、最小值、平均值、中位数
# >>290 80 96.66666666666667 100.0
print(s.idxmax(), s.argmax())   # >>体育 2  输出最大元素的标签和下标

```



#### DataFrame的构造和访问

+ DataFrame是==**带行列标签的二维表格，每一列都是一个Series**==

```python
import pandas as pd

# 构造
pd.set_option('display.unicode.east_asian_width', True)
# 输出对其方面的设置
scores = [['男', 108, 115, 97], ['女', 115, 87, 105], ['女', 100, 60, 130],
          ['男', 112, 80, 50]]
names = ['刘一哥', '王二姐', '张三妹', '李四弟']
courses = ['性别', '语文', '数学', '英语']
df = pd.DataFrame(data=scores, index=names, columns=courses)    # 数据、行标签、列标签
print(df)
#        性别  语文  数学  英语
# 刘一哥   男   108   115    97
# 王二姐   女   115    87   105
# 张三妹   女   100    60   130
# 李四弟   男   112    80    50

# 访问
print(df.values[0][1], type(df.values))  # >>108 <class 'numpy.ndarray'>
print(list(df.index))       # >>['刘一哥', '王二姐', '张三妹', '李四弟']   （行标签）
print(list(df.columns))     # >>['性别', '语文', '数学', '英语']    （列标签）
print(df.index[2], df.columns[2])   # >>张三妹 数学
s1 = df['语文']       # s1是个Series，代表’语文‘那一列
print(s1['刘一哥'], s1[0])     # >>108 108     # 刘一哥语文成绩
print(df['语文']['刘一哥'])     # >>108         # 列索引先写
s2 = df.loc['王二姐']  # s2也是一个Series，代表’王二姐‘哪一行
print(s2['性别'], s2['语文'], s2[2])
# >>女 115 87    王二姐的性别、语文和数学分数
```



#### DataFrame的切片

| DataFrame的切片          | ==DataFrame的切片是视图== |
| ------------------------ | ------------------------- |
| iloc[行选择器, 列选择器] | 用下标做切片              |
| loc[行选择器, 列选择器]  | 用标签做切片              |

```python
df2 = df.iloc[1:3]      # 行切片，选1，2两行。 列切片省略说明全取
df2 = df.loc['王二姐':'张三妹']  # 和上一行等价
print(df2)
#        性别  语文  数学  英语
# 王二姐   女   115    87   105
# 张三妹   女   100    60   130

df3 = df.iloc[:, 0:3]   # 列切片，选0,1,2三列。 行切片省略说明全取
df3 = df.loc[:, '性别':'数学']  # 和上一行等价
print(df3)
#        性别  语文  数学
# 刘一哥   男   108   115
# 王二姐   女   115    87
# 张三妹   女   100    60
# 李四弟   男   112    80

df4 = df.iloc[:2, [1, 3]]   # 行列切片，取0，1行，1和3列
df4 = df.loc[:'王二姐', ['语文', '英语']]  # 与上一行等价
print(df4)
#         语文  英语
# 刘一哥   108    97
# 王二姐   115   105

df5 = df.iloc[[1, 3], 2:4]  # 1，3行；2,3列
df5 = df.loc[['王二姐', '李四弟'], '数学':'英语']  # 与上一行等价
print(df5)
#         数学  英语
# 王二姐    87   105
# 李四弟    80    50
```



#### DataFrame的分析统计

+ `sort_values(... inplace=True, axis=1...)`:原地排序（改变原表格），将各列排序

```python
print(df.T)     # df的转置矩阵
#      刘一哥 王二姐 张三妹 李四弟
# 性别     男     女     女     男
# 语文    108    115    100    112
# 数学    115     87     60     80
# 英语     97    105    130     50
print(df.sort_values('语文', ascending=False))    # 按语文成绩降序    不会改变原表格
#        性别  语文  数学  英语
# 王二姐   女   115    87   105
# 李四弟   男   112    80    50
# 刘一哥   男   108   115    97
# 张三妹   女   100    60   130
print(df.sum()['语文'], df.mean()['数学'], df.median()['英语'])
# >>435 85.5 101.0      语文分数之和，数学平均分，英语中位数
print(df.min()['语文'], df.max()['数学'])
# >>100 115     语文最低分，数学最高分
print(df.max(axis=1)['王二姐'])    # >>115   王二姐的最高分科目的分数
print(df['语文'].idxmax())        # >>王二姐  语文最高分所在行的标签
print(df['数学'].argmin())        # >>2      数学最低分所在行的行号
print(df.loc[(df['语文'] > 100) & (df['数学'] >= 85)])  # 行选择器，选择语文成绩>100, 数学>=85的行。列选择器忽略
#        性别  语文  数学  英语
# 刘一哥   男   108   115    97
# 王二姐   女   115    87   105
```



#### DataFrame的增删改

```python
# 初始的df:
#        性别  语文  数学  英语
# 刘一哥   男   108   115    97
# 王二姐   女   115    87   105
# 张三妹   女   100    60   130
# 李四弟   男   112    80    50
df.loc['王二姐', '英语'] = df.iloc[0, 1] = 150   # 修改王二姐英语和刘一哥语文成绩
df['物理'] = [80, 70, 90, 100]        # 为所有人添加物理成绩这一列
df.insert(1, '体育', [89, 77, 76, 45])    # 为所有人插入体育成绩到第一列
df.loc['李四弟'] = ['男', 100, 100, 100, 100, 100]  # 修改李四弟全部信息
df.loc[:, '语文'] = [20, 20, 20, 20]      # 修改所有人语文成绩
df.loc['钱五叔'] = ['男', 100, 100, 100, 100, 100]  # 加一行
df.loc[:, '英语'] += 10           # 为所有人英语加10分
df.columns = ['性别', '体育', '语文', '数学', 'English', '物理']  # 改列标签
print(df)
#        性别  体育  语文  数学  English  物理
# 刘一哥   男    89    20   115      107    80
# 王二姐   女    77    20    87      160    70
# 张三妹   女    76    20    60      140    90
# 李四弟   男   100    20   100      110   100
# 钱五叔   男   100   100   100      110   100


# 删除
df.drop(['体育', '物理'], axis=1, inplace=True)  # 删除体育和物理成绩
df.drop('王二姐', axis=0, inplace=True)        # 删除王二姐那一行
print(df)
#        性别  语文  数学  English
# 刘一哥   男    20   115      107
# 张三妹   女    20    60      140
# 李四弟   男    20   100      110
# 钱五叔   男   100   100      110
df.drop([df.index[i] for i in range(1, 3)], axis=0, inplace=True)   # 删除1,2行
df.drop([df.columns[i] for i in range(3)], axis=1, inplace=True)    # 删除0到2列
print(df)
#         English
# 刘一哥      107
# 钱五叔      110
```



#### pandas读写excel和csv文档

##### pandas读excel

+ 需要openpyxl（对.xlsx)和xlrd或xlwt支持（老的.xls)
+ 读取的每一张工作表都是一个DataFrame

excel_sample.xlsx：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220206160458221.png" alt="image-20220206160458221" style="zoom: 25%;" />

```python
import pandas as pd

pd.set_option('display.unicode.east_asian_width', True)
dt = pd.read_excel("tmp/excel_sample.xlsx", sheet_name=['销售情况', 1], index_col=0)    # 读取第0张和第一张工作表
df = dt['销售情况']     # dt是字典，df是DataFrame
print(df.iloc[0, 0], df.loc['睡袋', '数量'])    # >>12124 12124
print(df)   
#            数量   销售额   成本      利润
# 产品类别                                 
# 睡袋      12124  4323.54     54   6666.00
# 彩盒        234   123.99  54353   4444.00
# 宠物用品    234  1233.67    234   3333.24
# 警告标     1234   885.78    234   2222.99
# 总计      13826  6566.98  54875  16666.23
print(pd.isnull(df.loc['彩盒', '销售额']))   # >>False
df.fillna(0, inplace=True)      # 将所有NaN替换为0
print(df.loc['彩盒', '销售额'], df.iloc[2, 2])   # >>123.99 234
```



##### pandas写excel

`df.to_excel(filename, sheet_name="Sheet1", na_rep='', ... )`

+ 将DataFrame对象df中的数据写入excel文档filename中的’sheet1'工作表，NaN用`''`（空串） 代替
+ 会覆盖原有的filename文件
+ 如果要在一个excel文档中写入多个工作表，需要用 `ExcelWrite`

```python
writer = pd.ExcelWriter("new.xlsx")     # 创建ExcelWriter对象
df.to_excel(writer, sheet_name="S1")
df.T.to_excel(writer, sheet_name="S2")  # 转置矩阵写入
df.sort_values('销售额', ascending=False).to_excel(writer, sheet_name="S3")
# 按销售额排序的新DataFrame写入工作表S3
df['销售额'].to_excel(writer, sheet_name="S4")  # 只写入一列
writer.save()
```

new.xlsx:<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220206160558816.png" alt="image-20220206160558816" style="zoom:25%;" />

##### pandas写csv文件

```python
df.to_csv("result.csv", sep=',', na_rep='NA', float_format="%.2f", encoding='gbk')
# ','分隔，未定义的各自用‘NA', 小数保留小数点后两位，gbk编码
```

##### pandas读csv

```python
df = pd.read_csv("result.csv")
```





### 三、matplotlib

#### 绘制直方图

```python
import matplotlib.pyplot as plt
from matplotlib import rcParams

rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'
# 设置中文支持，中文字体为简体黑体
ax = plt.figure().add_subplot()     # 建图，获取子图对象
ax.bar(x=(0.2, 0.6, 0.8, 1.2), height=(1, 2, 3, 0.5), width=0.1)
# x表示4个柱子中心横坐标分别是0.2， 0.6， 0.8， 1
# height表示4个柱子高度分别是1，2，3，0.5
# width表示柱子宽度0.1
ax.set_title('我的直方图')
plt.show()
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207193455546.png" alt="image-20220207193455546" style="zoom: 33%;" />

##### 绘制横向直方图

+ 纵向

  ```python
  ax.bar(x=(0.2, 0.6, 0.8, 1.2), height=(1, 2, 3, 0.5), width=0.1)
  ```

  

+ 横向

  ```python
  ax.barh(y=(0.2, 0.6, 0.8, 1.2), width=(1, 2, 3, 0.5), height=0.1)
  ```

  效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207193752921.png" alt="image-20220207193752921" style="zoom:33%;" />





#### 绘制堆叠直方图

```python
import matplotlib.pyplot as plt

ax = plt.figure().add_subplot()
labels = ['Jan', 'Feb', 'Mar', 'Apr']
num1 = [20, 30, 15, 35]     # Dept1的数据
num2 = [15, 30, 40, 20]     # Dept2的数据
cordx = range(len(num1))    # x轴刻度位置
rects1 = ax.bar(x=cordx, height=num1, width=0.5, color='red', label="Dept1")
rects2 = ax.bar(x=cordx, height=num2, width=0.5, color='green', label="Dept2", bottom=num1)
ax.set_ylim(0, 100)         # y轴坐标范围
ax.set_ylabel("Profit")     # y轴含义
ax.set_xticks(cordx)        # 设置x轴刻度位置
ax.set_xticklabels(labels)  # 设置x轴刻度下方文字
ax.set_xlabel("In year 2020")   # x轴标签
ax.set_title("My Company")
ax.legend()     # 在右上角显示图例说明
plt.show()
```

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207211352324.png" alt="image-20220207211352324" style="zoom: 50%;" />





#### 绘制对比直方图（多组数据）

```python
import matplotlib.pyplot as plt

ax = plt.figure(figsize=(10, 5)).add_subplot()
ax.set_ylim(0, 400)     # y轴坐标范围
ax.set_xlim(0, 80)      # x轴坐标范围
# 以下是3组直方图的数据
x1 = [7, 17, 27, 37, 47, 57]    # 第一组直方图每个柱子中心点的横坐标
x2 = [13, 23, 33, 43, 53, 63]   # 第二组直方图每个柱子中心点的横坐标
x3 = [10, 20, 30, 40, 50, 60]
y1 = [41, 39, 13, 69, 39, 14]   # 第一组直方图每个柱子的高度
y2 = [123, 15, 20, 105, 79, 37]
y3 = [124, 91, 204, 264, 221, 175]
rects1 = ax.bar(x1, y1, facecolor='red', width=3, label='Iphone')
rects2 = ax.bar(x2, y2, facecolor='green', width=3, label='Huawei')
rects3 = ax.bar(x3, y3, facecolor='blue', width=3, label='Xiaomi')
ax.set_xticks(x3)   # x轴在x3中的个坐标点下面加刻度
ax.set_xticklabels(('A1', 'A2', 'A3', 'A4', 'A5', 'A6'))
# 指定x轴每一刻度下方的文字
ax.legend()     # 显示右上角三组图的标注

def label(ax, rects):   # 该函数在rects每个柱子顶端标注数字
    for rect in rects:
        height = rect.get_height()
        ax.text(rect.get_x() - 0.05 + rect.get_width()/2.0,
                height + 34, str(height), rotation=90)  # 文字旋转90度

label(ax, rects1)
label(ax, rects2)
label(ax, rects3)
plt.show()
```

+ `rect.get_x()`：获取rect柱子左侧的横坐标，加上`rect.get_width()/2`后得到柱子中点的横坐标

效果：<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207212616152.png" alt="image-20220207212616152" style="zoom: 33%;" />





#### 折线图和散点图

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207214325603.png" alt="image-20220207214325603" style="zoom: 33%;" />

+ **蓝色部分不是一张图，是由折线图和散点图拼接而成**
+ **红色曲线也是折线图，由于点非常密集因此看成一条曲线**

```python
import matplotlib.pyplot as plt
import math, random

def drawPlot(ax):
    xs = [i / 100 for i in range(1500)]     # 1500个点的横坐标，间隔0.01
    ys = [10 * math.sin(x) for x in xs]     # 对应曲线y=10*sin(x)上的1500个点的纵坐标
    ax.plot(xs, ys, "red", label="Beijing")  # 画曲线y=10*sin(x)

    ys = list(range(-18, 18))
    random.shuffle(ys)  # 随机打乱y坐标
    ax.scatter(range(16), ys[:16], c='blue')    # 画散点，横坐标为[0,15], 纵坐标为ys的前 16个元素

    ax.plot(range(16), ys[:16], 'blue', label="Shanghai")  # 画折线
    ax.legend()     # 显示右上角的各条折线标注,右上角位置不够python自动调整到左下
    ax.set_xticks(range(16))    # x轴在坐标0, 1...15处加刻度
    ax.set_xticklabels(range(16))   # 指定x轴每个刻度下方显示的文字

ax = plt.figure(figsize=(10, 4), dpi=100).add_subplot()  # 图像长宽和清晰度
drawPlot(ax)
plt.show()
```





#### 饼图

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207215044430.png" alt="image-20220207215044430" style="zoom: 33%;" />

```python
import matplotlib.pyplot as plt

def drawPie(ax):
    lbs = ('A', 'B', 'C', 'D')          # 四个扇区的标签
    sectors = [16, 29.55, 44.45, 10]    # 四个扇区的份额（百分比）
    expl = [0, 0.1, 0, 0]               # 四个扇区的突出程度（0.1表示半径的0.1倍）
    ax.pie(x=sectors, labels=lbs, explode=expl,
           autopct='%.2f', shadow=True, labeldistance=1.1,  # labeldistance表示外部标注距离圆心的距离(半径的倍数）
           pctdistance=0.6, startangle=90)  
    # pctdistande表示每小块中间的标注距离圆心的距离；startangle表示饼图从90度开始画
    ax.set_title("pie sample")

ax = plt.figure().add_subplot()
drawPie(ax)
plt.show()
```





#### 热力图

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207222832920.png" alt="image-20220207222832920" style="zoom:33%;" />



```python
import numpy as np
from matplotlib import pyplot as plt

data = np.random.randint(0, 100, 30).reshape(5, 6)
# 生成一个五行六列，元素[0,100]内的随机矩阵
xlabels = ['Beijing', 'Shanghai', 'Chengdu', 'Guangzhou', 'Hangzhou', 'Wuhan']
ylabels = ['2016', '2017', '2018', '2019', '2020']
ax = plt.figure(figsize=(10, 8)).add_subplot()
ax.set_yticks(range(len(ylabels)))  # y轴在坐标[0, len(ylabels))处夏克苏
ax.set_yticklabels(ylabels)     # 设置y轴刻度文字
ax.set_xticks(range(len(xlabels)))
ax.set_xticklabels(xlabels)
heatMp = ax.imshow(data, cmap=plt.cm.hot, aspect='auto', vmin=0, vmax=100)
# 最小值vmin为黑色，最大值vmax为白色

for i in range(len(xlabels)):   # 在每个格子上写文字
    for j in range(len(ylabels)):
        ax.text(i, j, data[j][i], ha='center', va='center',  # ha、va:水平、竖直对齐方式
                color='blue', size=26)

plt.colorbar(heatMp)        # 绘制右边的颜色-数值对照柱
plt.xticks(rotation=45, ha='right')     # 将x轴刻度文字旋转，水平方向右对齐
plt.title("Sales Volumn(ton)")
plt.show()
```





#### 雷达图

##### 单层雷达图

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207224210442.png" alt="image-20220207224210442" style="zoom:33%;" />

```python
import matplotlib.pyplot as plt
from matplotlib import rcParams     # 处理汉字的库

def drawRadar(ax):
    pi = 3.1415926
    labels = ['EQ', 'IQ', '人缘', '魅力', '财富', '体力']   # 六个属性的名称
    attrNum = len(labels)       # attrNum是属性种类数，此处等于6
    data = [7, 6, 8, 9, 8, 2]   # 六个属性的值
    angles = [2*pi*i/attrNum for i in range(attrNum)]
    # angles是以弧度为单位的6个属性对应的6条半径线的角度（平均分6份）
    angles2 = [x*180/pi for x in angles]    # 弧度转角度
    # angles2是以角度为单位的6个属性对应的半径线的角度
    ax.set_ylim(0, 10)  # 限定半径线上的坐标范围
    ax.set_thetagrids(angles2, labels, fontproperties='SimHei')
    # 绘制六个属性对应的六条半径
    ax.fill(angles, data, facecolor='g', alpha=0.25)    # 填充。alpha为透明度

rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'    # 处理汉字
ax = plt.figure().add_subplot(projection='polar')   # 生成极坐标形式的子图
drawRadar(ax)
plt.show()
```



##### 多层雷达图

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207225457128.png" alt="image-20220207225457128" style="zoom:33%;" />

```python
import matplotlib.pyplot as plt
from matplotlib import rcParams

rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'
pi = 3.1415926
labels = ['EQ', 'IQ', '人缘', '魅力', '财富', '体力']   # 六个属性的名称
attrNum = len(labels)
names = ('张三', '李四', '王五')
data = [[0.40, 0.32, 0.35], [0.85, 0.35, 0.30],
        [0.40, 0.32, 0.35], [0.40, 0.82, 0.75],
        [0.14, 0.12, 0.35], [0.80, 0.92, 0.35]]     # 三个人的数据
angles = [2*pi*i/attrNum for i in range(attrNum)]
angles2 = [x * 180/pi for x in angles]
ax = plt.figure().add_subplot(projection='polar')
ax.fill(angles, data, alpha=0.25)
ax.set_thetagrids(angles2, labels)
ax.set_title('三巨头人格分析', y=1.05)     # y指明标题垂直位置（高出半径0.05倍）
ax.legend(names, loc=(0.95, 0.9))       # 画出右上角不同人的颜色说明
plt.show()
```





#### 一个窗口画多幅图

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220207230432876.png" alt="image-20220207230432876" style="zoom:33%;" />

```python
# import以及drawRadar, drawPie,drawPlot函数略
fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(2, 2, 1)       # 窗口分割成 2 * 2, 取位于第一个方格的子图
# 1 | 2
# 3 | 4
drawPie(ax)
ax = fig.add_subplot(2, 2, 2, projection='polar')
drawRadar(ax)
ax = plt.subplot2grid((2, 2), (1, 0), colspan=2)	# 2行2列，从(1, 0)格开始占两列
# 或写成 ax = fig.add_subplot(2, 1, 2) # 2行1列，取第二行
# (0, 0) | (0, 1)
# (1, 0) | (1, 1)
drawPlot(ax)
plt.figtext(0.05, 0.05, 'subplot sample')
plt.show()
```



****

## Python爬虫

### 一、爬虫的用途和原理

#### 爬虫的用途

+ 在网络上搜集数据（比如搜索引擎）
+ 模拟浏览器快速操作（抢票、抢课、抢挂号......)
+ 模拟浏览器操作，替代填表等重复操作

#### 最基本的爬虫写法

​	**数据获取型爬虫的本质就是自动获取网页并抽取其中的内容**

1. 手工找出合适的url
2. 用浏览器手工查看url对应的网页，并查看源代码，找出包含想要的内容（文件名、链接等）字符串的模式。
3. 程序中获取url对应的网页
4. 程序中用正则表达式或BeautifulSoup库抽取网页中想要的内容



#### 示例：获取Bing图片的搜索结果图片

```python
import re
import requests     # requests库用于获取网络资源

def getHtml(url):   # 获取网址为url的网页
# 暂时省略

def getBingPictures(word, n):  # 下载 n张 bing图片搜来的关于word的图片保存到本地
    url = "https://cn.bing.com/images/search?q="
    url += word
    html = getHtml(url)
    pt = 'src=\"(.*?pid=1.7)\"'    # 正则表达式，用于寻找图片网址
    i = 0   # 记录已经取到的图片数
    for x in re.findall(pt, html):
        try:    # 通过url获取图片
            print(x)
            r = requests.get(x, stream=True)    # 获取x对应的网络资源
            f = open('tmp/{0}{1}.jpg'.format(word, i), "wb")    # 二进制写
            f.write(r.content)
            f.close()
        except Exception as e:
            pass
        i += 1
        if i >= n:
            break
           
getBingPictures('熊猫', 5)
```





### 二、用requests库获取网页

#### 此函数无效

```python
def getHtml(url):   # 获取网址为url的网页
    import requests
    fakeHeaders = {'User-Agent':
                   'Mozilla/5.0 (Windows NT 10.0; Win64; x64)' 
                   'AppleWebKit/537.36 (KHTML, like Gecko)'
                   'Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77',
                   'Accept': 'text/html, application/xhtml+xml,*/*'}
    # 用于伪装浏览器发送请求
    try:
        r = requests.get(url, headers=fakeHeaders)
        r.encoding = r.apparent_encoding    # 确保网页编码正确
        return r.text   # 返回值是字符串，包含整个网页内容
    except Exception as e:
        print(e)
        return ""
```

#### 编码识别加密

```python
# def getHtml(url):   # 获取网址为url的网页
#     import requests
    import chardet  # 编码处理库
#     fakeHeaders = {'User-Agent':
#                    'Mozilla/5.0 (Windows NT 10.0; Win64; x64)' 
#                    'AppleWebKit/537.36 (KHTML, like Gecko)'
#                    'Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77',
#					 'Accept': 'text/html, application/xhtml+xml,*/*'}
#     # 用于伪装浏览器发送请求
#     try:
        r = requests.get(url, headers=fakeHeaders)
        ecd = chardet.detect(r.content)['encoding']  # ecd是个字符串
        if ecd.lower() != sys.getdefaultencoding().lower()
            r.encoding = ecd        # 修改r中文本的编码
        else:
            r.encoding = r.apparent_encoding
        return r.text   # 返回值是字符串，包含整个网页内容
    # except Exception as e:
    #     print(e)
    #     return ""

```

#### 用requests库获取网页的优势和局限

##### 优势

+ 相比其他方法，速度快几倍
+ 安装简单，分发容易

##### 局限

+ 容易被反爬虫手段屏蔽
+ 不能获取包含JavaScript生成的动态网页

**==用上面的`getHtml函数`,不能得到Bing图片搜索结果网页，得到的是空网页（被反爬了）==**



####弥补requests不足的其他获取网页的办法

+ 使用selenium库（慢，且很容易被反爬，已经被许多网站反爬，网上各种对付反爬的解决办法基本不管用，不推荐）
+ 使用pyppeteer库（快，暂未被许多网站反爬，强烈推荐）





### 三、用pyppeteer库获取网页

#### pyppeteer来历

+ puppeteer是谷歌公司推出的可以控制Chrome浏览器的一套编程工具。一个日本工程师以此为基础推出了python版本，叫pyppeteer。
+ [pyppeteer官网](https://pypi.org/project/pyppeteer)

#### pyppeteer工作原理

+ 启动一个浏览器Chromium，用浏览器装入网页。浏览器可以用**无头模式(headless)**, 即隐藏模式启动，也可以显示启动。

+ 从浏览器可以获取网页源代码，若网页有JavaScript程序，获取的是JavaScript被浏览器执行后的网页源代码
+ 可以向浏览器发送命令，模拟用户在浏览器上键盘输入、鼠标点击等操作，让浏览器转到其他网页
+ selenium原理及功能和pyppeteer一样



#### 预备知识：协程

+ 协程就是前面加了'async'的函数（>=python3.6)

  ```python
  async def f():
      return 0
  ```

+ 调用协程时，必须在函数名前面加'await'

  ```python
  await f()
  ```

+ 协程只能在协程里面调用，即await语句只能出现在协程里

+ 协程是一种特殊函数，多个协程可以并行

+ **pyppeteer所有函数都是协程，调用时前面都要加'await'，且只能在协程中调用**

  ​	初用协程，经常因为调用XXXX时忘了加await导致下面错误：

  ​	`Runtime Warning: coroutine 'XXXX' was never awaited`

#### 实现

```python
def getHtml(url):  # 暂时适用于Bing图片搜索

    import asyncio  # Python 3.6之后自带的协程库
    import pyppeteer as pyp

    async def asGetHtml(url):  # 获取url对应网页的源代码

        browser = await pyp.launch(headless=False)	
        # 启动Chromium,browser即为Chromium浏览器，非隐藏启动（表示能看见浏览器）
		# 没有chromium会自动下载
        
        page = await browser.newPage()  # 在浏览器中打开一个新页面（标签）
        await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; \
                                Win64; \
                                x64) AppleWebKit/537.36 (KHTML, \
                                like Gecko) \
                                Chrome/78.0.3904.70 Safari/537.36')	# 反反爬措施
        await page.evaluateOnNewDocument(
            '() =>{ Object.defineProperties(navigator, '
            '{ webdriver:{ get: () => false } }) }' )   # 反反爬措施

        await page.goto(url)  # 装入url对应的网页
        text = await page.content()  # page.coutent就是网页源代码字符串
        await browser.close()  # 关闭浏览器
        return text
        # 速度大约比用requests.get慢5,6倍

    m = asyncio.ensure_future(asGetHtml(url))  # 协程外启动协程
    asyncio.get_event_loop().run_until_complete(m)  # 等待协程结束
    return m.result()  # 返回的就是asGetHtml的返回值 text
```

+ **可以改进程序，只需启动一次浏览器，==生成一个page对象即可，以后获取不同网页都用相同page对象==，所有事情完成后菜关闭浏览器**

##### launch的其他参数

```python
browser = await pyp.launch(headless=False,
                          executablePath = 'c:/tmp/chrome-win32/chrome.exe',
                          userdataDir = 'c:/tmp')
```

+ **executablePath**: 如果Chromium没有安装在默认文件夹下面，则需要指定其位置
+ **userdataDir**: userdataDir指明用来存放浏览器工作期间存放临时文件的文件夹。不是必须，能够防止可能出现的莫名错误。

#### 获取Bing图片的完整代码

```python
import re
import requests

def getHtml(url):  # 暂时适用于Bing图片搜索

    import asyncio  # Python 3.6之后自带的协程库
    import pyppeteer as pyp

    async def asGetHtml(url):  # 获取url对应网页的源代码

        browser = await pyp.launch(headless=False)	
        # 启动Chromium,browser即为Chromium浏览器，非隐藏启动（表示能看见浏览器）
		# 没有chromium会自动下载
        
        page = await browser.newPage()  # 在浏览器中打开一个新页面（标签）
        await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; \
                                Win64; \
                                x64) AppleWebKit/537.36 (KHTML, \
                                like Gecko) \
                                Chrome/78.0.3904.70 Safari/537.36')	# 反反爬措施
        await page.evaluateOnNewDocument(
            '() =>{ Object.defineProperties(navigator, '
            '{ webdriver:{ get: () => false } }) }' )   # 反反爬措施

        await page.goto(url)  # 装入url对应的网页
        text = await page.content()  # page.content就是网页源代码字符串
        await browser.close()  # 关闭浏览器
        return text
        # 速度大约比用requests.get慢5,6倍

    m = asyncio.ensure_future(asGetHtml(url))  # 协程外启动协程
    asyncio.get_event_loop().run_until_complete(m)  # 等待协程结束
    return m.result()  # 返回的就是asGetHtml的返回值 text


def getBingPictures(word, n):  # 下载 n张 bing图片搜来的关于word的图片保存到本地
    url = "https://cn.bing.com/images/search?q="
    url += word
    html = getHtml(url)
    pt = 'src=\"(https://.*?pid=1.7)\"'  # 正则表达式，用于寻找图片网址
    i = 0  # 记录已经取到的图片数
    for x in re.findall(pt, html):
        try:  # 通过url获取图片
            print(x)
            r = requests.get(x, stream=True)  # 获取x对应的网络资源
            f = open('tmp/{0}{1}.jpg'.format(word, i), "wb")  # 二进制写
            f.write(r.content)
            f.close()
        except Exception as e:
            pass
        i += 1
        if i >= n:
            break


getBingPictures('熊猫', 5)
```

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213132517157.png" alt="image-20220213132517157" style="zoom:50%;" />





### 四、其他分析提取网页的方式（BeautifulSoup库）

#### 分析并提取网页的3种方式

1. 正则表达式（速度最快，但适应变化略差）
2. BeautifulSoup库（速度是正则表达式的约几分之一）
3. selenium或pyppeteer中的浏览器对象的查找元素函数（速度是正则表达式的约百分之一，用在需要模拟在网页中进行输入，点击按钮等操作的时候）

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213135215644.png" alt="image-20220213135215644" style="zoom:33%;" />

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213135236279.png" alt="image-20220213135236279" style="zoom:50%;" />

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213135256522.png" alt="image-20220213135256522" style="zoom:50%;" />

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213135309203.png" alt="image-20220213135309203" style="zoom:50%;" />



#### 使用BeautifulSoup库分析html的步骤

1. 将html文档装入一个BeautifulSoup对象x
2. 用x对象的find, find_all等函数去**找想要的tag对象**
3. 对找到的tag对象，还可以用其find, find_all函数去**找它内部包含（嵌套）的tag对象**
4. tag对象的text就是该对象里的正文（text)，tag对象也可以看做是一个字典，里面包含各种属性(attr)及其值



#### 将html文档载入BeautifulSoup对象

##### 方法1：html文档来自字符串

```python
import bs4

string = '''
    <div id="siteHeader" class="wrapper">
        <h1 class="logo">
        <div id="topsearch">
            <ul id="userMenu">
            <li ><a href="http://openjudge.cn/">首页</a></li>
        </div>
    </div>
'''
# 带href的 <a>都是链接，上面“首页”是链接文字 ,href后面http://openjudge.cn是链接地址

soup = bs4.BeautifulSoup(string, "html.parser")
print(soup.find("li").text)  # >>首页
```

##### 方法2：html文档来自于文件

```python
soup = bs4.BeautifulSoup(
    open("tmp\\Homepage.html", 'r', encoding='utf-8'),
    "html.parser")
```

##### 方法3：html文档来自于给定网址

```python
def getHtml(url):   # 获得 html文本
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""

html = getHtml("https://cn.bing.com/dict/search?q=new")
soup = bs4.BeautifulSoup(html, 'html.parser')
```



#### 分析示例

#####tmp/test.html:

```html
<!DOCTYPE HTML>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>title</title>
</head>
<body>
<div id="synoid" style="display:block;">
    <div class="df_div2">
        <div class="de_title1">adj.</div>
        <div class="col_fl">
            <a h="ID=Dictionary,5237.1"
               href="https://cn.bing.com/dict/search?q=novel">
                <span class="p1-4">novel</span>
            </a>
            <p>
                <a h="ID=Dictionary,5238.1"
                   href="https://cn.bing.com/dict/search?q=newfangled">
                    <span class="p1-4">newfangled</span>
                </a>
        </div>
        <a href="http://www.baidu.com" id="searchlink1" class="sh1">百度</a>
        <a href="http://www.google.com" id="searchlink1" class="sh2">谷歌</a>
    </div>
</div>
</body>
</html>
```

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213143112124.png" alt="image-20220213143112124" style="zoom: 33%;" />

##### 用BeautifulSoup对象寻找想要的tag

```python
import bs4

soup = bs4.BeautifulSoup(open("tmp/test.html",
                              encoding="utf-8"), "html.parser")
diva = soup.find("div", attrs={"id": "synoid"})
# 寻找名为"div"，且具有 值为"synoid"的属性"id"的tag
if diva is not None:  # 如果找到
    for x in diva.find_all("span", attrs={"class": "p1-4"}):
        print(x.text)  # 在diva内部继续找
for x in diva.find_all("a", attrs={"id": "searchlink1"}):
        print(x.text)
x = diva.find("a", attrs={"id": "searchlink1", "class": "sh2"})
if x is not None:
    print(x.text)
    print(x["href"])
    print(x["id"])
```

+ 如果别处没有和`<div id = "synoid" style="isplay:block;">`内部的模式相似的东西，也可以不用先找这个"synoid"tag

输出：

```txt
novel
newfangled
百度
谷歌
谷歌
http://www.google.com
searchlink1
```





### 五、实例：爬取每日股票交易信息

#### 需要的网址

创业板股票交易代码大全：https://www.banban.cn/gupiao/list_cyb.html

深圳股票交易代码大全：https://www.banban.cn/gupiao/list_sz.html

上证股票交易代码大全：https://www.banban.cn/gupiao/list_sh.html



#### 实现

```python
import re
import asyncio  # Python 3.6之后自带的协程库
import pyppeteer as pyp
import bs4


async def antiAntiCrawler(page):  # 为page添加反反爬虫手段
    await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; \
    Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) \
    Chrome/78.0.3904.70 Safari/537.36')
    await page.evaluateOnNewDocument(
        '() =>{ Object.defineProperties(navigator, \
        { webdriver:{ get: () => false } }) }')


async def getStockCodes(page):  # 用正则表达式获取股票名称和代码
    # 从"https://www.banban.cn/gupiao/list_sh.html"对应的page获取所有股票名称和代码
    codes = []  # 最终内容：["四川路桥(600039)","包钢股份(600010)"......]
    html = await page.content()
    pt = '<a href="/gupiao/[^"]*">([^<]*\(\d+\))</a>'
    # 对应 <li><a href="/gupiao/600151/">航天机电(600151)</a></li>
    for x in re.findall(pt, html):
        codes.append(x)
    return codes  # 耗时：0: 00:00.033943


async def getStockInfo(url):
    browser = await pyp.launch(headless=False)
    # 启动Chromium,browser即为Chromium浏览器，非隐藏启动
    page = await browser.newPage()  # 在浏览器中打开一个新页面（标签）
    await antiAntiCrawler(page)  # 新页面生成后一律调用此来反反爬
    await page.goto(url)  # 装入url对应的网页
    codes = await getStockCodes(page)

    for x in codes[:3]:  # 只取前三个股票信息
        print("-----", x)  # x形如 "四川路桥(600039)"
        pos1, pos2 = x.index("("), x.index(")")
        code = x[pos1 + 1:pos2]  # 取股票代码,如600039
        url = "https://quote.eastmoney.com/sh" + code + ".html"
        await page.goto(url)
        html = await page.content()  # 往下编程前可以先print(html)看一看
        pt = '<td>([^<]*)</td>.*?<td[^>]*id="gt\d*?"[^>]*>([^<]*)</td>'
        for x1 in re.findall(pt, html, re.DOTALL):
            print(x1[0], x1[1])
            
    await browser.close()  # 关闭浏览器


url = "https://www.banban.cn/gupiao/list_sh.html"
loop = asyncio.get_event_loop()
loop.run_until_complete(getStockInfo(url))
```

+ 正则表达式对应：

  ```txt
  <td>今开：</td>
  <td id="gt1" class="txtl" data-bind="46">1.22</td>
  ```

+ 输出结果

   <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220213171652778.png" alt="image-20220213171652778" style="zoom:25%;" />

  

##### 用BeautifulSoup获取股票名称和代码

```python
async def getStockCodes(page):
    codes = []
    html = await page.content()
    soup = bs4.BeautifulSoup(html, "html.parser")
    for x in soup.find_all("li"):
        # 对应 <li><a href="/gupiao/600151/">航天机电(600151)</a></li>
        a = x.find("a")
        if "(" in a.text and ")" in a.text:
            codes.append(a.text)
    return codes  # 耗时：0: 00:00.193480
```

##### 用浏览器自身的查找元素功能获取股票名称和代码

```python
async def getStockCodes(page):
    codes = []
    elements = await page.querySelectorAll("li")  # 根据tag name找元素
    # 对应 <li><a href="/gupiao/600151/">航天机电(600151)</a></li>
    for e in elements:
        a = await e.querySelector("a")  # 根据tag name找元素
        obj = await a.getProperty("text")  # 还可以 a.getProperty("href")
        # 上面这句不行就改成: obj = await a.getProperty("innerText")
        text = await obj.jsonValue()  # 固定写法
        if "(" in text and ")" in text:
            codes.append(text)
    return codes  # 耗时： 0:00:04.421178
```



### 六、需要登录的爬虫

#### 概述

+ 许多网站需要登录后才能访问其内容

  京东、淘宝需要登录才能访问交易记录

  openjudge.cn需要登录才能看提交过的源代码

+ 登录操作无法用一个url表示出来

+ 解决办法之一：用浏览器模拟登录过程，输入用户名密码、点登陆按钮。

  或者程序启动浏览器，等待手工登录后，程序再继续爬虫操作（对有验证码的情况）



#### 爬取OpenJudge上ac的所有代码

#####原理

登录网址：http://openjudge.cn/auth/login/

个人首页网址：http://openjudge.cn/user/XXXX

Accpeted所在标签：

```html
<a href="http://cxsjsxmooc.openjudge.cn/2020t1fallall2/solution/25212869/" class="result-right">Accepted</a> 
```

+ 每个Accpeted链接都有`class="result-right"`属性

点进Accepted链接后，找到源代码所在标签：

```html
<pre class="sh_python">
n = int(input())
lst = []
for i in range(n):
s = input().split()
lst.append((s[0], int(s[1])))
lst.sort(key= lambda x : (-x[1], x[0]))
for x in lst:
print(x[0], x[1])
</pre>
```



#####实现

```python
import asyncio
import pyppeteer as pyp


async def antiAntiCrawler(page):  # 为page添加反反爬虫手段
    await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; Win64; x64) \ '
                            'AppleWebKit/537.36 (KHTML, like Gecko) '
                            'Chrome/78.0.3904.70 Safari/537.36')
    await page.evaluateOnNewDocument(
        '() =>{ Object.defineProperties(navigator,'
        '{ webdriver:{ get: () => false } }) }')


async def getOjSourceCode(loginUrl):
    width, height = 1400, 800  # 网页宽高
    browser = await pyp.launch(headless=False,
                               userdataDir="c:/tmp",
                               args=[f'--window-size={width},{height}'])
    page = await browser.newPage()
    await antiAntiCrawler(page)
    await page.setViewport({'width': width, 'height': height})
    await page.goto(loginUrl)

    # 登录 （若手动登录，则以下若干行可以去掉）
    element = await page.querySelector("#email")  # 找到账户输入框
    await element.type("1822011278@qq.com")  # 输入邮箱
    element = await page.querySelector("#password")  # 找到密码输入框
    await element.type("Zg115588")  # 输入密码
    element = await page.querySelector("#main > form > div.user-login >"
                                       "p:nth-child(2) > button")  # 找到登录按钮
    await element.click()  # 点击登录按钮
    # 若手动登录，则以上若干行可以去掉

    # 点击登录按钮后要等待操作完成才能继续往下操作（time.sleep(10)）
    await page.waitForSelector("#main>h2",
                               timeout=30000)  # 等待“正在进行的比赛...."标题出现，最多等30秒

    element = await page.querySelector("#userMenu>li:nth-child(2)>a")
    # 找"个人首页”链接
    await element.click()  # 点击个人首页链接
    await page.waitForNavigation()  # 等新网页装入完毕
    elements = await page.querySelectorAll(".result-right")
    # 找所有"Accepted"链接, 其有属性 class="result-right"

    page2 = await browser.newPage()  # 新开一个页面 (标签)
    await antiAntiCrawler(page2)  # 反反爬
    for element in elements[:2]:  # 只打印前两个程序
        obj = await element.getProperty("href")  # 获取href属性
        url = await obj.jsonValue()
        await page2.goto(url)  # 在新页面(标签)中装入新网页
        element = await page2.querySelector("pre")  # 查找pre tag
        obj = await element.getProperty("innerText")  # 取源代码
        text = await obj.jsonValue()  # 转为字符串
        print(text)
        print("-------------------------")
    await browser.close()


def main():
    url = "http://openjudge.cn/auth/login/"
    asyncio.get_event_loop().run_until_complete(getOjSourceCode(url))


main()
```







### 七、pyppeteer+requests编写高速爬虫

#### 概述

+ requests要对付登录比较麻烦（要用到抓包等技巧）

+ pyppeteer没有requests快（因为要浏览器渲染网页）

+ 对于需要登录，且登录后的网页都不是JavaScript生成的动态网页的情况，

  可以**使用pyppeteer登录后，再用requests做剩下的事情**

##### 例如：

​	个人主页的网址http://openjudge.cn/user/XXXX需要登陆以后才能进入，若直接进入此网址，会跳回到登录页面。

​	浏览器如何知道输入此网址后是否是已经登陆的状态呢？



#### 预备知识：cookie和session

+ 登陆成功后，服务器向浏览器发送一些身份标识数据，称为cookie。浏览器每次向服务器发送请求，都带上cookie，服务器就能知道请求来自前面那个登录的浏览器了
+ 服务器在内存为浏览器维护一个session，每个浏览器对应不同的session，里面存放着该浏览器的状态（比如一系列的填表等步骤已经进行到什么程度）。不同的session有不同的session id，浏览器发送请求的时候，如果带上session id，服务器也能知道是哪个浏览器在请求。
+ 在客户计算机上由cookie可以生成标识同一个浏览器的session。



#### 工作原理

+ pyppeteer的浏览器的页面有cookies()函数可以获得cookie

+ `requests.Session()`可以生成一个空session

+ session的`cookies.update(cookies)`函数可以根据cookies生成相应的session

+ session的`get(url)`函数，可以向服务器发送带session的请求

+ 获得cookie，生成相应的session以后，爬取网页都用session的get函数进行。

  （前提：网页不是JavaScript生成的。如果是，依然用pyppeteer的浏览器爬取）



#### 用pyppeteer+requests爬取OpenJudge(上面的改进)

```python
import asyncio
import pyppeteer as pyp
import bs4
import requests


def sessionGetHtml(session, url):  # 发送带session的网页请求,获取网页源码
    fakeHeaders = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
    AppleWebKit/537.36 (KHTML, like Gecko) \
    Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77'
    }  # 伪装浏览器用的请求头
    try:
        result = session.get(url, headers=fakeHeaders)
        result.encoding = result.apparent_encoding
        return result.text
    except Exception as e:
        print(e)
        return ""


async def makeSession(page):
    # 返回一个session,将其内部cookies修改成pypeteer浏览器页面对象中的cookies
    cookies = await page.cookies()  # cookies是一个列表，每个元素都是一个字典
    cookies1 = {}
    for cookie in cookies:  # requests中的cookies只要 "name"属性
        cookies1[cookie['name']] = cookie['value']
    session = requests.Session()
    session.cookies.update(cookies1)
    return session


async def antiAntiCrawler(page):
    # 为page添加反反爬虫手段
    await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; Win64; x64) \ '
                            'AppleWebKit/537.36 (KHTML, like Gecko) '
                            'Chrome/78.0.3904.70 Safari/537.36')
    await page.evaluateOnNewDocument(
        '() =>{ Object.defineProperties(navigator,'
        '{ webdriver:{ get: () => false } }) }')


async def getOjSourceCode(loginUrl):
    width, height = 1400, 800  # 网页宽高
    browser = await pyp.launch(headless=False,
                               userdataDir="c:/tmp",
                               args=[f'--window-size={width},{height}'])
    page = await browser.newPage()
    await antiAntiCrawler(page)
    await page.setViewport({'width': width, 'height': height})
    await page.goto(loginUrl)

    await page.waitForSelector("#main>h2",
                               timeout=30000)  # 等待手动登录后，“正在进行的比赛...."标题出现

    element = await page.querySelector("#userMenu>li:nth-child(2)>a")
    # 找"个人首页”链接
    await element.click()  # 点击个人首页链接
    await page.waitForNavigation()  # 等新网页装入完毕

    elements = await page.querySelectorAll(".result-right")
    # 找所有"Accepted"链接, 其有属性 class="result-right"

    session = await makeSession(page)   # 由page创造一个session,以后向服务器发送请求都通过session进行
    for element in elements[:2]:
        obj = await element.getProperty("href")
        url = await obj.jsonValue()
        html = sessionGetHtml(session, url)
        soup = bs4.BeautifulSoup(html, "html.parser")
        element = soup.find("pre")
        print(element.text)
        print("-------------------------")
    await browser.close()


def main():
    url = "http://openjudge.cn/auth/login/"
    asyncio.get_event_loop().run_until_complete(getOjSourceCode(url))


main()
```





### 八、重要补充

#### 绝对网址和相对网址

> 绝对网址以http://或https://开头，相对网址无这两种开头

如果当前网址是：http://www.pku.edu.cn/education/index.htm

而网页中有一个链接，其中网址是相对的，形如:

`<a href = "dict/word.htm">词典单词</a>`

则该链接绝对网址是：http://www.pku.edu.cn/education/dict/word.htm



##### 使用requests库是，获得当前网页网址：

```python
r = requests.get("http://openjudge.cn")
print(r.url)  # >>http://openjudge.cn
```

或：

```python
session = requests.session()
r = session.get("http://openjudge.cn")
print(r.url)
```



##### 使用pyppeteer库时，获取当前网页网址：

```python
browser = await pyp.launch(headless=False)
page = await browser.newPage()
await page.goto("http://openjudge.cn")
print(page.url)  # >>http://openjudge.cn
```





#### 反反爬技巧

**连续两个操作之间，加入适当延时，模拟人的动作，以免因动作太快被识破**

```python
import time
time.sleep(2)	# 暂停两秒，什么都不做
```



****

## tkinter图形界面程序设计

### 一、控件概述

#### 图形界面编程要点

+ 使用Python自带tkinter库，简单，但是简陋
+ 使用PyQT，精美，但是难学

##### 控件

+ 按钮、列表框、单选框、多选框、编辑框...

##### 布局

​	如何将控件摆放在窗口上合适的位置

##### 事件响应

​	对鼠标点击、键盘敲击、控件被点击等操作进行响应

##### 对话框

​	弹出一个和用户交互的窗口，接收一些输入



#### tkingter常用控件

| 控件            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| **Button**      | 按钮                                                         |
| Canvas          | 画布，显示图形如线条或文本                                   |
| **Checkbutton** | 多选框（方形）                                               |
| **Entry**       | 单行编辑框（输入框）                                         |
| **Frame**       | 框架，上面可以摆放多个控件                                   |
| **Label**       | 标签，可以显示文本或图像                                     |
| **Listbox**     | 列表框                                                       |
| Menubutton      | 带菜单的按钮                                                 |
| **Menu**        | 菜单                                                         |
| Message         | 消息，显示多行文本                                           |
| **OptionMenu**  | 带下拉菜单的按钮                                             |
| **Radiobutton** | 单选框（圆形）                                               |
| Scale           | 滑块标尺，可以做一定范围内的数值选择                         |
| Srollbar        | 卷滚条，使内容在显示区域内上下滚动                           |
| **Text**        | 多行编辑框（输入框）                                         |
| Toplevel        | 顶层窗口，可以用于弹出自定义对话框                           |
| **Spinbox**     | 微调输入框。可以输入数值，也可以用上下箭头微调数值           |
| panedWindow     | 滑动分割窗口。可以将一个窗口分成几块，交界处可以拖动，改变各块大小 |
| **LabelFrame**  | 带文字标签的框架，上面可以摆放多个控件                       |

##### 用法

```python
import tkinter as tk

win = tk.Tk()       # 生成一个窗口
tk.Label(win, . . .)    # 在窗口win上生成一个Label，该Label的母体是win
ckb = tk.Checkbutton(win, . . .)    # 在窗口上生成一个Checkbutton
frm = tk.Frame(win, . . .)      # 在窗口上生成一个Frame
bt = tk.Button(frm, . . .)      # 在frm上生成一个Button
```



#### tkinter的扩展控件

```python
from tkinter import ttk
```

​	tk中的控件ttk中都有，且更美观，用法基本和tk一样，且ttk多出几个控件

| 控件             | 描述             |
| ---------------- | ---------------- |
| **TreeView**     | 树形列表         |
| ProgressBar      | 进度条           |
| **Notebook**     | 多页标签         |
| **LabeledScale** | 带文字的滑块标尺 |

```python
tree = ttk.TreeView(win, . . .)
```





### 二、布局基础

#### 用grid进行布局

+ pack布局，place布局（略）

+ grid布局: 在窗口上布置网格(grid)，控件放在网格单元里

  

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220211235820054.png" alt="image-20220211235820054" style="zoom: 50%;" />:

```python
import tkinter as tk

win = tk.Tk()       # 创建窗口
win.title("Hello")  # 指定窗口标题
label1 = tk.Label(win, text='用户名：')  # 创建属于win上的图文标签控件
label2 = tk.Label(win, text='密码：')
etUsername = tk.Entry(win)      # 创建属于win的单行编辑框控件，用于输入用户名
etPassword = tk.Entry(win)      # 创建密码编辑框
label1.grid(row=0, column=0, padx=5, pady=5)    # label1放在第0行第0列，上下左右都留白5像素
label2.grid(row=1, column=0, padx=5, pady=5)    # 第1行第0列
etUsername.grid(row=0, column=1, padx=5, pady=5)    # 用户名输入框放在第0行第1列
etPassword.grid(row=1, column=1, padx=5, pady=5)    # 密码输入框放在第1行第1列
btLogin = tk.Button(win, text='登录')     # 创建属于win的按钮控件
btLogin.grid(row=2, column=0, columnspan=2, padx=5, pady=5)     # btLogin在第2行第0列，跨两列

win.mainloop()      # 显示窗口
```



#### 默认情况下的grid规则

+ 一个单元格只能放一个控件，控件在单元格中居中摆放

+ 不同控件高宽可以不同，因此网格不同行可以不一样高，不同列也可以不一样宽。

  但**同一行的单元格高度相等，同一列的单元格宽度相等**。

+ **一行的高度，以该行最高的单元格为准。**单元格的高度，等于该单元格中摆放的控件的高度（如果控件上下有留白，还要加上留白的高度）。

  列宽度类似。

+ 若不指定窗口的大小和显示位置，则窗口大小和网格大小一样，即恰好能包裹所有控件；显示位置有Python自行决定。

+ 如果指定了窗口大小，或者用户拖拽窗口边缘将窗口变大，就会发生网格小于窗口大小的情况

+ `win.geometry("800x500+200+100")` ：字母x设定窗口宽800像素，高500，左上角位于(200, 100)

##### 控件均匀分布实现

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212003601838.png" alt="image-20220212003601838" style="zoom: 25%;" />

```python
win.columnconfigure(0, weight=1)    # 指定第0列增量分配权重为1
win.columnconfigure(1, weight=1)    # 指定第1列增量分配权重为1
win.rowconfigure(0, weight=1)       # 指定第0行权重为1
win.rowconfigure(1, weight=1)
```



#### grid函数中的sticky参数

​	**sticky指明控件在单元格中的“贴边方式”，即是否要贴着单元格的四条边。该参数可以是个字符串，包含"E", "W", "S", "N"四个字符中的一个或多个**

```python
label2.grid(row=1, column=0, padx=5, pady=5, sticky="NE")   # 东北，即贴着右上角
etUsername.grid(row=0, column=1, padx=5, pady=5, sticky="E")    # 靠右
etPassword.grid(row=1, column=1, padx=5, pady=5, sticky="EWSN")  # 占满单元格
btLogin.grid(row=2, column=0, columnspan=2, padx=5, pady=5, sticky="SW")  # 西南，即左下角
```

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212004741566.png" alt="image-20220212004741566" style="zoom: 25%;" />



### 三、使用Frame控件进行布局

#### 概述

+ 控件多了，要算每个控件行、列、rowspan, columnspan很麻烦
+ Frame控件上还可以摆放控件，可以当多底板使用
+ 可以在Frame控件上面设置网格进行Grid布局，摆放多个控件



#### 示例

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212194523385.png" alt="image-20220212194523385" style="zoom:33%;" />

```python
import tkinter as tk

win = tk.Tk()
win.title('人事系统')
frm01Red = tk.Frame(win, bg="red", highlightthickness=2)  # 背景红色，边框宽度2
frm01Red.grid(row=0, column=1, sticky="WE")
tk.Label(frm01Red, text="姓名：").grid(row=0, column=0, padx=6, pady=6)
tk.Entry(frm01Red).grid(row=0, column=1, padx=6, pady=6)
tk.Label(frm01Red, text="手机号：").grid(row=0, column=2, padx=6, pady=6)
tk.Entry(frm01Red).grid(row=0, column=3, padx=6, pady=6)
tk.Button(frm01Red, text="更新").grid(row=0, column=4, padx=6, pady=6)
frm00Blue = tk.Frame(win, bg="blue", highlightthickness=2)
frm00Blue.grid(row=0, column=0, rowspan=2, sticky="NS")
frm00Blue.rowconfigure(5, weight=1)
tk.Label(frm00Blue, text="筛选条件：").grid(row=0,
                                       padx=6, pady=6, sticky="W")
tk.Checkbutton(frm00Blue, text="男性").grid(row=1, padx=6, pady=6)
tk.Checkbutton(frm00Blue, text="女性").grid(row=2, padx=6, pady=6)
tk.Checkbutton(frm00Blue, text="博士").grid(row=3, padx=6, pady=6)
tk.Label(frm00Blue, text="符合条件的名单：").grid(row=4,
                                          padx=6, sticky="W")
nameList = tk.Listbox(frm00Blue)
nameList.grid(row=5, padx=6, pady=6, sticky="NS")
for x in ['张三', '李四', '王五', '李丽', '刘娟']:
    nameList.insert(tk.END, x)  # 将x插入到列表框尾部。
frm21Green = tk.Frame(win, bg='green', highlightthickness=2)
frm21Green.grid(row=2, column=0, columnspan=2, sticky="WE")
tk.Label(frm21Green, text="提示：目前一切正常").grid(row=0, padx=6, pady=6)
frm11Yellow = tk.Frame(win, bg='yellow', highlightthickness=2)
frm11Yellow.grid(row=1, column=1, sticky="NSWE")  # 要贴住单元格四条边
frm11Yellow.rowconfigure(1, weight=1)  # 使得frm11Yellow中第1行高度会自动伸缩
frm11Yellow.columnconfigure(0, weight=1)
tk.Label(frm11Yellow, text="简历：").grid(row=0,
                                       padx=6, pady=6, sticky="W")
tk.Text(frm11Yellow).grid(row=1, padx=15, pady=15, sticky="NSWE")
# sticky="NSWE"使得该多行编辑框会自动保持填满整个单元格
win.rowconfigure(1, weight=1)
win.columnconfigure(1, weight=1)

win.mainloop()
```





### 四、控件属性和事件响应

#### 控件属性概述

+ 有的控件有函数可以用来设置和获取其属性，或以**字典下标的形式**获取和设置其属性

```python
lbHint = tk.Label(win, text='请登录')
lbHint['text'] = '登陆成功！'	# 修改lbHint的文字
```

+ 多行编辑框Text获取文字：

```python
txt = tk.Text(win)
txt.get(0.0, tk.END)	# 由第0行0列一直到最后，即取全部文字
```

+ 有的控件必须和一个变量相关联，取变量值或设置变量值，就是取或设置该控件的属性

```python
s = tk.StringVar()
s.set("sin(x)")		# 赋值
tk.Entry(win, textvariable=s)
print(s.get())
```



#### 事件响应概述

+ 创建有些控件时，可以用command参数指定控件的事件响应函数

```python
tk.Button(win, text='显示函数图', command=myfunc)    # myfunc是函数名
tk.Checkbutton(win, text='显示函数图', command=lambda:print('hello'))
```

+ 可以用控件的bind函数指定事件响应函数

```python
lb = tk.Label(win, text='something')
lb.bind("<ButtonPress-1>", mouse_down)  # 鼠标左键按下事件
```





#### 示例：用户登录

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212202022446.png" alt="image-20220212202022446" style="zoom:33%;" />

```python
import tkinter as tk


def btLogin_click():  # 登录按钮的事件响应函数，点击该按钮时被调用
    if username.get() == "pku" and password.get() == "123":  # 正确的用户名和密码
        lbHint["text"] = "登录成功!"  # 修改lbHint的文字
        lbHint["fg"] = "black"  # 文字变成黑色，"fg"表示前景色,"bg"表示背景色
    else:
        username.set("")  # 将用户名输入框清空
        password.set("")  # 将密码输入框清空
        lbHint["fg"] = "red"  # 文字变成红色
        lbHint["text"] = "用户名密码错误，请重新输入!"


def cbPassword_click():  # “显示密码”单选框的事件响应函数，点击该单选框时被调用
    if showPassword.get():  # showPassword是和cbPassword绑定的tkinter布尔变量
        etPassword["show"] = ""  # 使得密码输入框能正常显示密码。Entry有show属性
    else:
        etPassword["show"] = "*"  # 使得密码输入框只显示'*'字符


win = tk.Tk()
win.title("登录")
username, password = tk.StringVar(), tk.StringVar()
# 两个字符串类型变量，分别用于关联用户名输入框和密码输入框
lbHint = tk.Label(win, text="请登录")
lbHint.grid(row=0, column=0, columnspan=2)
lbUsername = tk.Label(win, text="用户名：")
lbUsername.grid(row=1, column=0, padx=5, pady=5)
lbPassword = tk.Label(win, text="密码：")
lbPassword.grid(row=2, column=0, padx=5, pady=5)
etUsername = tk.Entry(win, textvariable=username)
# 输入框etUsername和变量username关联
etUsername.grid(row=1, column=1, padx=5, pady=5)
etPassword = tk.Entry(win, textvariable=password, show="*")
# Entry的属性show="*"表示该输入框不论内容是啥，只显示'*'字符，为""则正常显示
etPassword.grid(row=2, column=1, padx=5, pady=5)
showPassword = tk.BooleanVar()  # 用于关联“显示密码”单选框
showPassword.set(False)  # 使得cbPassowrd开始就是非选中状态
cbPassword = tk.Checkbutton(win, text="显示密码",
                            variable=showPassword, command=cbPassword_click)
# cbPassword关联变量showPassword，其事件响应函数是cbPassword_click，即点击它时
# 会调用 cbPassword_click() （点击时showPassword值会改变）
cbPassword.grid(row=3, column=0, padx=5, pady=5)
btLogin = tk.Button(win, text="登录", command=btLogin_click)
# 点击btLogin按钮会执行btLogin_click()
btLogin.grid(row=4, column=0, pady=5)
btQuit = tk.Button(win, text="退出", command=win.quit)
# 点击btQuit会执行win.quit()，win.quit()导致窗口关闭，于是整个程序结束
btQuit.grid(row=4, column=1, pady=5)
win.mainloop()
```





#### 实例：Python火锅店点菜系统

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212210414130.png" alt="image-20220212210414130" style="zoom:50%;" />

```python
import tkinter as tk
from tkinter import ttk  # ttk中有更多控件

gWin = None  # 表示窗口
gDishes = (("清汤(20元)", "滋补(40元)", "鸳鸯(60元)"),  # 锅底
           ("香菜(10元)", "麻酱(20元)", "韭花(20元)"),  # 佐料
           ("羊肉(30元)", "肥牛(40元)", "白菜(10元)", "茼蒿(20元)"))  # 菜品


def addToListbox(listbox, lst):
    for x in lst:
        listbox.insert(tk.END, x)  # 将x添加到列表框尾部


def doDiscount():
    gWin.discount = [1, 0.9, 0.8][gWin.custom.get()]
    gWin.lbHint["text"] = "饭菜总价：" + str(int(gWin.totalCost * gWin.discount)) \
                          + "元"
    gWin.lbHint["fg"] = "black"


def categoryChanged(event):  # gWin.cbxCategory选项变化时被调用
    gWin.lsbDishes.delete(0, tk.END)  # 删除全部内容,delete(x,y)删除第x项到第y项
    idx = gWin.cbxCategory.current()  # gWin.cbxCategory当前选中的是第idx项
    addToListbox(gWin.lsbDishes, gDishes[idx])  # 装入相应菜单
    gWin.lsbDishes.select_set(0, 0)


def btAdd_click():
    # btAdd["state"] = tk.DISABLED  tk.NORMAL
    sel = gWin.lsbDishes.curselection()  # sel形如 (1,2,3)
    if sel == ():
        gWin.lbHint["text"] = "您还没有选中要添加的菜"
        gWin.lbHint["fg"] = "red"
    else:
        dish = gWin.lsbDishes.get(sel)
        price, num = int(dish[3:5]), gWin.dishNum.get()
        gWin.lsbTable.insert(tk.END, "[" + gWin.category.get() + "]" + dish + " X" + num)
        gWin.totalCost += price * int(num)
        gWin.lbHint["text"] = "饭菜总价：" + str(int(gWin.totalCost * gWin.discount)) + "元"
        gWin.lbHint["fg"] = "black"


def btDelete_click():
    sel = gWin.lsbTable.curselection()
    if sel == ():
        gWin.lbHint["text"] = "您还没有选中要删除的菜"
        gWin.lbHint["fg"] = "red"
    else:
        for i in sel:
            dish = gWin.lsbTable.get(i)
            price = int(dish[7:9])
            price *= int(dish[dish.index("X") + 1:])
            gWin.totalCost -= price
        gWin.lbHint["text"] = "饭菜总价：" + str(int(gWin.totalCost * gWin.discount)) + "元"
        gWin.lbHint["fg"] = "black"
        for i in sel[::-1]:
            gWin.lsbTable.delete(i)


def main():
    global gWin
    gWin = tk.Tk()
    gWin.title("Python火锅店")
    gWin.geometry("520x300")
    gWin.totalCost, gWin.discount = 0, 1  # 总价和折扣
    gWin.resizable(False, False)  # gWin不可改变大小
    lb = tk.Label(gWin, text="欢迎光临Python火锅店", bg="red", fg="white", font=('黑体', 20, 'bold'))
    lb.grid(row=0, column=0, columnspan=4, sticky="EW")
    gWin.category = tk.StringVar()  # 对应组合框gWin.cbxCategory收起状态显示的文字
    gWin.cbxCategory = ttk.Combobox(gWin, textvariable=gWin.category)
    gWin.cbxCategory["values"] = ("锅底", "佐料", "菜品")  # 下拉时显示的表象
    gWin.cbxCategory["state"] = "readonly"  # 将gWin.cbxCategory设置为不可输入，只能选择
    gWin.cbxCategory.current(0)  # 选中第0项
    gWin.cbxCategory.grid(row=1, column=0, sticky="EW")
    gWin.lsbDishes = tk.Listbox(gWin, selectmode=tk.SINGLE, exportselection=False)
    # exportselection使得列表框失去输入焦点也能保持选中项目
    gWin.lsbDishes.bind("<Double-Button-1>", lambda e: btAdd_click())
    gWin.lsbDishes.bind("<<ListboxSelect>>", lambda e: gWin.dishNum.set("1"))
    addToListbox(gWin.lsbDishes, gDishes[0])  # 装入锅底菜单
    gWin.lsbDishes.select_set(0, 0)  # select_set(x,y)可以选中第x项到第y项(包括y)
    gWin.lsbDishes.grid(row=2, column=0, sticky="EWNS")
    gWin.cbxCategory.bind("<<ComboboxSelected>>", categoryChanged)
    # 当组合框下拉后有表现被选中时，会发生ComboboxSelected事件。
    # 此处指定该事件发生时，会调用gWin.categoryChanged函数
    # 指定"<<ComboboxSelected>>"事件的响应函数是gWin.categoryChanged
    gWin.lsbTable = tk.Listbox(gWin, selectmode=tk.EXTENDED, exportselection=False)
    gWin.lsbTable.grid(row=2, column=2, sticky="EWNS")
    tk.Label(gWin, text="我的餐桌").grid(row=1, column=2)
    gWin.lbHint = tk.Label(gWin, text="饭菜总价：0元")
    gWin.lbHint.grid(row=3, column=0, columnspan=3, sticky="W")

    scrollbar = tk.Scrollbar(gWin, width=20, orient="vertical",
                             command=gWin.lsbTable.yview)
    gWin.lsbTable.configure(yscrollcommand=scrollbar.set)  # 绑定listbox和scrollbar
    scrollbar.grid(row=2, column=3, sticky="NS")
    frm = tk.Frame(gWin)
    frm.grid(row=2, column=1)
    tk.Label(frm, text="数量：").grid(row=0, column=0)
    gWin.dishNum = tk.StringVar(value="1")
    gWin.spNum = tk.Spinbox(frm, width=5, from_=1, to=1000,
                            textvariable=gWin.dishNum)
    gWin.spNum.grid(row=0, column=1)
    btAdd = tk.Button(frm, text="添加", command=btAdd_click)
    btAdd.grid(row=1, column=0, columnspan=2, sticky="EW")
    btDelete = tk.Button(frm, text="删除", command=btDelete_click)
    btDelete.grid(row=2, column=0, columnspan=2, sticky="EW")
    lbfDiscount = tk.LabelFrame(frm, text="价格")
    lbfDiscount.grid(row=3, column=0, columnspan=2)
    gWin.custom = tk.IntVar()  # 如果写 gWin.custom = tk.IntVar(value=0)就不用下一行了
    gWin.custom.set(0)
    rb = tk.Radiobutton(lbfDiscount, text="普通价", value=0,
                        variable=gWin.custom, command=doDiscount)
    rb.grid(row=0, column=0, sticky="W")
    rb = tk.Radiobutton(lbfDiscount, text="会员价(九折)",
                        value=1, variable=gWin.custom, command=doDiscount)
    rb.grid(row=1, column=0, sticky="W")
    rb = tk.Radiobutton(lbfDiscount, text="VIP价(八折)",
                        value=2, variable=gWin.custom, command=doDiscount)
    rb.grid(row=2, column=0, sticky="W")
    gWin.columnconfigure(0, weight=1)
    gWin.columnconfigure(2, weight=1)
    gWin.rowconfigure(2, weight=1)
    gWin.mainloop()


main()
```





#### 实例：菜单和编辑框

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212220009177.png" alt="image-20220212220009177" style="zoom: 33%;" />

```python
import tkinter as tk
from tkinter import filedialog

gWin = None


def muCut_click():
    gWin.txtFile.event_generate("<<Cut>>")


def muCopy_click():
    gWin.txtFile.event_generate("<<Copy>>")


def muPaste_click():
    gWin.txtFile.event_generate('<<Paste>>')


def saveTextFile(fileName):
    f = open(fileName, "w", encoding="utf-8")
    f.write(gWin.txtFile.get(0.0, tk.END))
    f.close()


def muSaveAs_click():
    fileName = filedialog.asksaveasfilename(title='Save File',
                                            initialdir='c:/tmp', initialfile='untitled.txt',
                                            filetypes=[('Text File', '*.txt')], defaultextension=".txt")
    if fileName != "":
        saveTextFile(fileName)
        gWin.title(fileName)
        gWin.curFileName = fileName


def muSave_click():
    if gWin.curFileName.lower() == "untitled.txt":
        muSaveAs_click()
    else:
        saveTextFile(gWin.curFileName)


def muOpen_click():
    global gWin
    fileName = filedialog.askopenfilename(title='Open File',
                                          filetypes=[('Text Files', '*.txt'), ('All Files', '*')])
    if fileName != "":
        gWin.curFileName = fileName
        gWin.title(fileName)
        f = open(fileName, "r")
        text = f.read()
        f.close()
        gWin.txtFile.delete(0.0, tk.END)
        gWin.txtFile.insert("insert", text)  # gWin.txtFile.insert(tk.END, text)加在最后


def muBigFont_click():
    if gWin.isBigFont.get() == 1:
        gWin.txtFile.configure(font=("SimHei", 18, "bold"))
    else:
        gWin.txtFile.configure(font=("", 10))


def muNew_click():
    global gWin
    gWin.txtFile.delete(0.0, tk.END)
    gWin.title("untitled.txt")
    gWin.curFileName = "untitled.txt"


def muPrintSelection_click():
    if gWin.txtFile.tag_ranges(tk.SEL):
        print(gWin.txtFile.selection_get())


def main():
    global gWin
    gWin = tk.Tk()
    gWin.title("untitled.txt")
    gWin.menubar = tk.Menu(gWin)
    gWin.fileMenu = tk.Menu(gWin.menubar, tearoff=0)  # 去掉顶端横线
    gWin.menubar.add_cascade(label='File', menu=gWin.fileMenu)  # 添加一个子菜单 File
    gWin.fileMenu.add_command(label='New', command=muNew_click)
    gWin.fileMenu.add_command(label='Open', command=muOpen_click)
    gWin.fileMenu.add_command(label='Save', command=muSave_click,
                              accelerator="Ctrl+S")
    gWin.fileMenu.add_command(label='Save As', command=muSaveAs_click)
    gWin.fileMenu.add_separator()  # 加分割线
    gWin.fileMenu.add_command(label='Exit', command=gWin.quit)
    editMenu = tk.Menu(gWin.menubar, tearoff=0)
    gWin.menubar.add_cascade(label='Edit', menu=editMenu)
    editMenu.add_command(label='Cut', command=muCut_click)
    editMenu.add_command(label='Copy', command=muCopy_click)
    editMenu.add_command(label='Paste', command=muPaste_click)
    settingsMenu = tk.Menu(editMenu, tearoff=0)
    editMenu.add_cascade(label='Settings', menu=settingsMenu)
    gWin.isBigFont = tk.IntVar()
    settingsMenu.add_checkbutton(label="Big Font",
                                 command=muBigFont_click, variable=gWin.isBigFont)
    settingsMenu.add_command(label="Print Selection",
                             command=muPrintSelection_click)
    gWin.config(menu=gWin.menubar)
    gWin.txtFile = tk.Text(gWin)
    gWin.txtFile.grid(row=0, column=0, sticky="NWSE")
    gWin.curFileName = "untitled.txt"
    gWin.rowconfigure(0, weight=1)
    gWin.columnconfigure(0, weight=1)
    gWin.bind_all("<Control-s>", lambda event: muSave_click())
    gWin.mainloop()


main()
```





### 五、对话框

**作用**：弹出小窗口和用户进行交互，或者显示信息

自定义对话框：用于复杂一点的交互



#### 示例

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222000293.png" alt="image-20220212222000293" style="zoom:33%;" /> <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222021102.png" alt="image-20220212222021102" style="zoom:33%;" /> <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222038018.png" alt="image-20220212222038018" style="zoom:33%;" />

<img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222244491.png" alt="image-20220212222244491" style="zoom: 33%;" /> <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222056779.png" alt="image-20220212222056779" style="zoom:33%;" /><img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222112540.png" alt="image-20220212222112540" style="zoom:33%;" /><img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222134064.png" alt="image-20220212222134064" style="zoom:33%;" /><img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222228385.png" alt="image-20220212222228385" style="zoom:33%;" />

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212222159337.png" alt="image-20220212222159337" style="zoom:33%;" />

```python
import tkinter as tk
from tkinter import messagebox
from tkinter import simpledialog
from tkinter import filedialog

gWin = None


def cmd(n):
    def innerCmd():  # innerCmd是个闭包
        # if n <= 4:
        # 	func = eval("messagebox." + gWin.titles[n])
        # 	value = func("Dialog", gWin.titles[n])
        # elif n <= 7:
        # 	func = eval("simpledialog." + gWin.titles[n])
        # 	value = func("Dialog", gWin.titles[n])
        if n == 0:
            value = messagebox.askokcancel("Dialog", gWin.titles[n])
        elif n == 1:
            value = messagebox.askyesno("Dialog", gWin.titles[n])
        elif n == 2:
            value = messagebox.showerror("Dialog", "抱歉，您的账户余额不足!")
        elif n == 3:
            value = messagebox.showinfo("Dialog", gWin.titles[n])
        elif n == 4:
            value = messagebox.showwarning("Dialog", gWin.titles[n])
        elif n == 5:
            value = simpledialog.askfloat("Dialog", "请输入支付金额:")
        elif n == 6:
            value = simpledialog.askinteger("Dialog", gWin.titles[n])
        elif n == 7:
            value = simpledialog.askstring("Dialog", gWin.titles[n])
        elif n == 8:
            value = filedialog.askopenfilename(title='打开文件',
                                               filetypes=[('images', '*.jpg *.png'), ('text', '*.txt'),
                                                          ('All Files', '*')])
        elif n == 9:
            value = filedialog.asksaveasfilename(title='保存文件',
                                                 initialdir='c:/tmp', initialfile='hello.py')
        elif n == 10:
            value = filedialog.askopenfilenames(title='打开文件',
                                                filetypes=[('images', '*.jpg *.png'), ('All Files', '*')])
        elif n == 11:
            value = filedialog.askdirectory(title='打开文件',
                                            initialdir='c:/tmp2')
        print(n, value, type(value))

    return innerCmd


def main():
    global gWin
    gWin = tk.Tk()
    gWin.titles = ["askokcancel", "askyesno", "showerror",
                   "showinfo", "showwarning", "askfloat", "askinteger",
                   "askstring", "askopenfilename", "asksaveasfilename",
                   "askopenfilenames", "askdirectory"]
    for i in range(12):
        button = tk.Button(gWin, text=gWin.titles[i], command=cmd(i))	# 利用闭包简化代码
        button.grid(row=i // 4, column=i % 4, padx=5, pady=5)
    gWin.columnconfigure(0, weight=1)
    gWin.mainloop()


main()
```



#### 自定义对话框要点

1. 自定义对话框是个Toplevel窗口，控件布局方式、事件响应方式和普通窗口一样

   ```python
   dialog = tk.Toplevel(gWin)	# gWin是主窗口，创建对话框窗口
   dialog.grab_set()	# 显示对话框，并独占输入焦点
   ```

2. 关闭自定义对话框

   ```python
   dialog.destroy()
   ```

   

 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212224429875.png" alt="image-20220212224429875" style="zoom:33%;" />

```python
import tkinter as tk
from tkinter import messagebox

gDialog = gWin = None  # 全局变量以g打头，一看就知道是全局变量


def btOk_click():
    username = gDialog.etUsername.get()
    password = gDialog.etPassword.get()
    gDialog.destroy()  # 关闭对话框
    messagebox.showinfo("消息", "您的用户名是：" +
                        username + ",密码是：" + password)


def passwordDialog():
    global gDialog
    gDialog = tk.Toplevel(gWin)  # 创建对话框窗口
    gDialog.grab_set()  # 显示对话框，并独占输入焦点
    gDialog.title("请输入用户名和密码")
    gDialog.resizable(False, False)
    label1 = tk.Label(gDialog, text="用户名：")
    label2 = tk.Label(gDialog, text="密码：")
    gDialog.etUsername = tk.Entry(gDialog)
    gDialog.etPassword = tk.Entry(gDialog)
    label1.grid(row=0, column=0, padx=5, pady=5)
    label2.grid(row=1, column=0, padx=5, pady=5)
    gDialog.etUsername.grid(row=0, column=1, padx=5, pady=5)
    gDialog.etPassword.grid(row=1, column=1, padx=5, pady=5)
    btOk = tk.Button(gDialog, text="确定", command=btOk_click)
    btOk.grid(row=2, column=0, padx=5, pady=5)
    btCancel = tk.Button(gDialog, text="取消", command=gDialog.destroy)
    btCancel.grid(row=2, column=1, padx=5, pady=5)


gWin = tk.Tk()  # 创建窗口
gWin.geometry("300x300")
tk.Button(gWin, text="登录", command=passwordDialog).grid(row=0, column=0)
gWin.columnconfigure(0, weight=1)
gWin.rowconfigure(0, weight=1)
gWin.mainloop()  # 显示窗口
```





### 六、在图形界面上显示图像、用matplotlib绘图

#### tkinter界面上matplotlib绘图要点

1. 创建一个matplotlib.pyplot.Figure对象fig

2. 在fig对象上用add_subplot()创建一个子图ax

3. `canvas= FigureCanvasTkAgg(fig, master=win)`

   得到一个将fig绑定在win上面的FigureCanvasTkAgg对象canvas

   win可以是窗口，也可以是Frame、LabelFrame

4. `canvas.get_tk_widget().grid(...)`将canvas布局到win的合适位置

5. 子图ax画完图后，还要`canvas.draw()`才能刷新显示



#### 用Label显示图像要点

1. `aLabel.config(image=tkinter.PhotoImage(file='xxx.gif'))`可以显示gif图像

2. 要显示jpg, png需要用到PIL库里的Image和ImageTk

   ```python
   from PIL import Image, ImageTk
   img = ImageTk.PhotoImage(Image.open('XXX.jpg'))
   aLabel.config(image=img)
   ```

   注意此处img必须不是局部变量(bug)



#### 两个组件重叠，只显示一个的要点

​	两个组件本就可以放在同一个单元格里

​	`ctrl.grid_forget()` 可以让ctrl组件消失

​	`ctrl.grid(...)`又将其恢复



 <img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212224658607.png" alt="image-20220212224658607" style="zoom:33%;" /><img src="C:\Users\Ganzeus\AppData\Roaming\Typora\typora-user-images\image-20220212224923501.png" alt="image-20220212224923501" style="zoom:33%;" />

```python
import numpy as np
from PIL import Image, ImageTk
from math import *
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
from tkinter import filedialog

gWin = None


def mouse_down(event):
    gWin.mouseDown = True


def mouse_up(event):
    gWin.mouseDown = False
    gWin.lbMsg["text"] = "按住鼠标键移动，会显示鼠标位置"


def mouse_move(event):
    if gWin.mouseDown:
        gWin.lbMsg["text"] = "鼠标位置：(%d,%d)" % (event.x, event.y)


def showImage():
    fileName = filedialog.askopenfilename(title='打开文件',
                                          initialdir="c:/tmp2/", filetypes=[('images', '*.jpg *.png')])
    if fileName != "":
        gWin.geometry("")
        gWin.frmPlot.grid_forget()
        gWin.frmImg.grid(row=1, column=0, sticky="ESWN")
        gWin.img = ImageTk.PhotoImage(Image.open(fileName))  # 用PIL模块的PhotoImage打开
        # and keep a reference。如果 仅img = ImageTk.....然后 lbImage.config(image=img),则显示不出来
        gWin.lbImg.config(image=gWin.img)


def showPlot():
    gWin.geometry("")
    gWin.frmImg.grid_forget()
    gWin.frmPlot.grid(row=1, column=0, sticky="ESWN")
    gWin.ax.clear()  # gWin.fig.clear()
    xs = np.linspace(-3, 3, 100)
    y = [eval(gWin.fstr.get()) for x in xs]
    gWin.ax.plot(xs, y, color='red', linewidth=1.0, linestyle='--')
    gWin.canvas.draw()


def main():
    global gWin
    gWin = tk.Tk()
    frm = tk.Frame(gWin)
    frm.grid(row=0, column=0, sticky="EW")
    tk.Label(frm, text="y =").grid(row=0, column=0, padx=5, pady=5)
    gWin.fstr = tk.StringVar()
    gWin.fstr.set("sin(x)")
    tk.Entry(frm, textvariable=gWin.fstr).grid(row=0, column=1, padx=5, pady=5)
    tk.Button(frm, text="显示函数图", command=showPlot).grid(row=0, column=2, padx=5, pady=5)
    tk.Button(frm, text="显示图像文件", command=showImage).grid(row=0, column=3, padx=5, pady=5)
    gWin.frmImg = tk.Frame(gWin)
    gWin.lbImg = tk.Label(gWin.frmImg)
    gWin.lbImg.grid(row=0, column=0, sticky="NSWE")
    gWin.lbMsg = tk.Label(gWin.frmImg, fg="white", bg="red",
                          text="按住鼠标键移动，会显示鼠标位置")
    gWin.lbMsg.grid(row=1, column=0, sticky="EW")
    gWin.mouseDown = False
    gWin.lbImg.bind("<Motion>", mouse_move)
    gWin.lbImg.bind("<ButtonPress-1>", mouse_down)
    gWin.lbImg.bind("<ButtonRelease-1>", mouse_up)
    gWin.frmPlot = tk.Frame(gWin)
    gWin.fig = plt.Figure(figsize=(5, 4), dpi=100)
    gWin.ax = gWin.fig.add_subplot()
    gWin.canvas = FigureCanvasTkAgg(gWin.fig, master=gWin.frmPlot)
    gWin.canvas.get_tk_widget().grid(row=0, column=0, sticky="ESNW")
    gWin.frmPlot.grid(row=1, column=0, sticky="ESWN")
    showPlot()
    gWin.rowconfigure(1, weight=1)
    gWin.columnconfigure(0, weight=1)
    gWin.mainloop()


main()
```
