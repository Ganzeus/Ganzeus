# a, b = "he", 12
# print(a, b)
#
# a, b = b, a     # 交换a和b的值
# print(a, b)     # 12 he
#
# c, a, b = a, b, a
# print(a, b, c)  # he 12 12

# x = "I said: 'hello'"
# print(x)        # >>I said: 'hello'
# print('I said "hello"')     # >>I said: 'hello'
# print('''I said: 'he said "hello"'.''') # >>I said: 'he said "hello"'.
#
# print("this \
# is \
# good")   # >>this is good（字符串太长时，可以分行写）

# para_str = """多行字符串可以使用制表符
# TAB(\t).
# 也可以使用换行符[\n]
# <HTML><HEAD><TITLE>
# Friends CGT Demo</TITLE><HEAD>
# <BODY></BODY>
# </HTML>"""
# print(para_str)

# a = "ABCD"
# print(a[-1])    # >>D
# print(a[0])     # >>A
# print(a[2])     # >>C

# a = "Hello"
# b = "Python"
# print("el" in a)        # >>True
# print("th" not in b)    # >>False
# print("lot" in a)       # >>False
# c = a + b
# print(a in c)           # >>True

# a = 15
# b = "12"
# print(a + b)        # 错误
# print(a + int(b))   # >>27
# print(str(a) + b)   # >>1512
# print(eval("a + 3"))    # eval("a+3")计算表达式 a + 3 的值, >>18

# x, y, z = 12, "abc", "100"
# print(x, y, z)
# print(x, y, z, end="?")
# print("next")

# y = "please input:\n"
# x = input(y)
# print(x)

# empty = []
# list1 = ['Google', 'Runoob', 1997, 2000]
# list2 = [1, 2, 3, 4, 5, 6, 7]
# print("list1[0]: " + list1[0])         # >>list1[0]: Google
# list1[2] = 2001         # 修改了列表中下标为的元素
# a = 2
# print("更新后的第三个元素为；", list1[a])  # 变量也能做下标

# lst = [1, 2, 3, "4", 5]
# print(4 in lst, 3 in lst, "4" in lst)   # >>False True True

# s = input()
# numbers = s.split()
# print(int(numbers[0]) + int(numbers[1]))

# print("34\t\t45\n'7'".split())    # >>['34', '45', '7']
# print("abc def 1234 567".split()[2][1])     # >>2

# lst = input().split()
# print((int(lst[0]) + int(lst[1])) * int(lst[2]))

# str = input()
# print(str[-1] + str[-2] + str[-3])

# a, b, c = 1, 2, 3
# a, b, c = c, a, b
# c, a, b = a, b, a
# print(a, b, c)

# print(10/2)     # >>5.0
# print(15/4)     # >>3.75
# print(15//4)    # >>3
# print(15%4)     # >>3
# print(3.4/2.2)  # >>1.5454545454545452
# print(3.4//2.2) # >>1.0
# print(2**3)     # >>8
# print(-9//4)    # >> -3 (往数轴左边取整）

# z = 10.0 - 10
# print(z)            # >>0.0
# z = 7.5 - 2.5
# print(z)            # >>5.0
# print(2 + 0 * 4.5)  # >>2.0
# print(2 + 10 / 5)   # >>4.0

# a = 4
# print(2 < a < 6 < 8)    # >>True
# print(2 < a == 4 < 6)   # >>True
# b = a < 6
# print(b)                # >>True
# print(b == 1)           # >>True
# print(b == 2)          # >>False

# a = "abc"
# b = "abc"
# print(a == b)           # >>True
# print(a < "Abc")        # >>False
# print(a < "abcd")       # >>True

# print(5 and True)         # >>True  (5与True相当，但不相等）
# print(5 or False)         # >>5
# print(1 == True or False) # >>True
# print(not 2)              # >>False
# print(not 0)              # >>True
# print(not "abc")          # >>False
# print(not "")             # >>True
# print(not [])             # >>True
# print([] == False)        # False

# a = 10
# if a > 8:
#     print("a > 8")
# elif a < 12:
#     print("a < 12")

# a = int(input())
# if a > 0:
#     if a % 2:
#         print("odd")
#     else:
#         print("even")
# else:
#     print("a <= 0")

# print("12345"[1:3])     # >>23
# a = "abcdef"
# print(a[2:-1])          # >>cde
# print(a[0:6])           # >>abcdef

# tmpStr = input("请输入带有符号的温度值：")
# if tmpStr[-1] in ['f', 'F']:        # 若输入华氏温度
#     C = ((float(tmpStr[0:-1])) - 32) / 1.8
#     print("转换后的温度是" + str(C) + "C")
# elif tmpStr[-1] in "Cc":            # 若输入摄氏温度
#     F = eval(tmpStr[0:-1]) * 1.8 + 32
#     print("转换后的温度是" + str(F) + "F")
# else:
#     print("输入格式错误")

# year = int(input())
# if year <= 0:
#     print("Illegal year")
# else:
#     print("Legal year")
#     if year > 1949 and (year-1949) % 10 == 0:
#         print("Lucky year.")
#     elif year > 1921 and not((year - 1921)%10):
#         print("Good year.")
#     elif year % 4 == 0 and year % 100 or year % 400 == 0:
#         print("Leap year.")
#     else:
#         print("Common year.")

# h = 1.746
# print("My name is %s, I am %.2fm tall." % ("tom", h)) # >>My name is tom, I am 1.75m tall.
# print("My age is %d." % 18)     # 输出一项不需要加括号 >>My age is 18.
# print("%d%s" % (18, "hello"))           # >>18hello
# print("%.2f, %.2f" % (5.225, 5.325))    # >>5.22, 5.24

# s = input().split()
# if s[2] not in ["+", "-", "*", "/"]:
#     print("Invalid operator!")
# elif s[2] == "/" and int(s[1]) == 0:
#     print("Divided by zero!")
# else:
#     print(int(eval(s[0] + s[2] + s[1])))

# for i in range(10):
#     print("loop")
# else:
#     print("end")

# for i in range(0, 10, 3):       # 步长为3， >>0 3 6 9
#     print(i, end=" ")

# for i in range(-10, -100, -30):
#     print(i, end=" ")           # >> -10 -40 -70

# a = ["Google", "Baidu", "IBM", "Taobao", "QQ"]
# for i in a:
#     print(i, end=" ")	 # >>Google Baidu IBM Taobao QQ
#
# for letter in "Taobao":
#     print(letter, end=" ")	# >>T a o b a o

# sites = ["Google", "Baidu", "IBM", "Taobao"]
# for site in sites:
#     if site == "IBM":
#         print("OK")
#         break       # 跳出循环
#     print("site: " + site)
# else:
#     print("No break")
# print("Done!")

# n = int(input())
# sum = 0
# for i in range(n):
#     sum += int(input())
# print(sum)

# lst = input().split()
# n, m = int(lst[0]), int(lst[1])
# for i in range(1, n):       # 取第一个数，共n-1种取法
#     for j in range(i+1, n+1):   # 第二个数比第一个数大
#         if m % (i + j) == 0:
#             print(i, j)
#             break   # 后面的j无需再取，直接换下个i

# s = input()
# lst = s.split()
# maxV = int(lst[0])
# try:
#     while True:
#         lst = s.split()
#         for x in lst:
#             maxV = max(maxV, int(x))
#         s = input()     # ctrl + D 表示输入结束
# except:
#     pass    # pass语句什么都不做
# print(maxV)

# k = int(input())
# if k == 1 or k == 2:
#     print(1)
# else:
#     a1 = a2 = 1
#     for i in range(k-2):
#         a1, a2 = a2, a1+a2      # a1, a2 依次修改为后一项， 一次循环后a2为第三项，则k-2次循环后a2为第k项
#     print(a2)

# n = int(input())
# faci = 1
# sum = 0
# for i in range(1, n+1):
#     faci *= i
#     sum += faci
# print(sum)

# n = int(input())
# for i in range(2, n+1):
#     flag = 0            # flag == 0 表质数
#     for j in range(2, i):
#         if i % j == 0:
#             flag = 1
#             break
#     if not flag:
#         print(i)

# n = int(input())
# print(2)
# for i in range(3, n+1, 2):  # 步长为2，跳过偶数
#     flag = 0
#     for j in range(3, i, 2):
#         if i % j == 0:
#             flag = 1
#             break
#         if j * j > i:       # j > sqrt(i) 时无需再试
#             break
#     if not flag:
#         print(i)

# n = input()
# lst = input().split()
# maxV = minV = int(lst[0])
# for i in lst:
#     i = int(i)
#     if i > maxV:
#         maxV = i
#     minV = min(i, minV)        # python自带函数
# print(maxV - minV)

# s = input().split()
# l, r = int(s[0]), int(s[1])
# cnt = 0
# for i in range(l, r + 1):
#     while i:
#         digit = i % 10
#         if digit == 2:
#             cnt = cnt + 1
#         i //= 10
# print(cnt)

# s = input().split()
# l, r = int(s[0]), int(s[1])
# cnt = 0
# for i in range(l, r + 1):
#     i_str = str(i)
#     for digit in i_str:
#         if digit == '2':
#             cnt += 1
# print(cnt)

# x = 2
#
#
# def f():
#     print(x)
#     # x = 3
#     return
#
#
# f()

# def factorial(n):
#     if n < 2:
#         return 1
#     else:
#         return n * factorial(n-1)
#
#
# print(factorial(4))

# def f(n):
#     if n == 1 or n == 0:
#         return 1
#     return f(n-1) + f(n-2)

# def Hanoi(n, src, mid, dest):
#     # 递归边界
#     if n == 1: # 剩下最后一个盘子
#         print(src + '->' + dest)
#         return
#     # 任务分解
#     Hanoi(n-1, src, dest, mid)  # 现将上面 n-1个盘子移到中间
#     print(src + "->" + dest)    # 再将剩下的最大的盘子移到dest（此时src已空，问题规模已经变小）
#     Hanoi(n-1, mid, src, dest)  # 最后将中间n-1个盘子移到dest,以src中转
#
#
# print(Hanoi(64, 'A', 'B', 'C'))

# import turtle
#
#
# def snow(n, size):      # n是阶数，size是长度  从当前起点出发，在当前方向画一个长度为 size, 阶为n的雪花曲线
#     if n == 0:
#         turtle.fd(size)     # 笔沿着当前方向前进size
#     else:
#         for angle in [0, 60, -120, 60]:     # 对于列表中每个元素angle
#             turtle.left(angle)      # 笔左转angle度, turtle.lt(angle)也可
#             snow(n-1, size/3)
#
#
# # 画三段3阶雪花曲线
# turtle.setup(800, 800)
# # 窗口默认位于屏幕正中间，宽高为 800*800像素，窗口中央坐标 (0, 0)
# # 初始笔的前进方向是0度。正东方是 0度，正北是 90度
# turtle.speed(1000)
# turtle.penup()      # 抬起笔
# turtle.goto(-200, 100)  # 将笔移动到 (-200, 100)位置
# turtle.pendown()    # 放下笔（开始画）
# turtle.pensize(2)   # 笔的粗度是2
# level = 3           # 3阶
# snow(level, 400)    # 绘制长度为 400，阶为3的雪花曲线，方向水平
# turtle.right(120)   # 右拐 120度
# snow(level, 400)
# turtle.right(120)
# snow(level, 400)
# turtle.done()       # 保持绘图窗口

# a = "1233"
# print(isinstance(a, str))       # >>True
# print(isinstance(a, int))       # >>False
#
# b = (1, 3, )
# print(isinstance(b, tuple))     # >>True

# print(len([1, 2, 3, 4]))            # >>4   列表元素个数
# print(len((1, 2, 3)))               # >>3   元组长度
# print(len({1, 2, 3}))               # >>3   集合元素个数
# print(len({'tom': 2, 'jack': 3}))   # >>2   字典元素个数

# a = [1, 2, 3, 4]
# b = [1, 2, 3, 4]
# print(a == b)       # >>True
# print(a is b)       # >>False
# a = b
# print(a is b)       # >>True
# a[2] = 'ok'
# print(b)            # >>[1, 2, 'ok', 4]

# a = "abcd"
# print(a[0:-1])
# print("1234"[3:1:-1])           # >>43
# print("abcde"[::-1])            # >>edcba
# print("12345678"[1:7:2])        # >>246
# print("12345678"[7:1:-2])       # >>864

# a = "12..34.5346...a"
# print(a.split(".."))    # >>['12', '34.5346', '.a']
# print(a.split("."))     # >>['12', '', '34', '5346', '', '', 'a']
# print(a.split("34"))    # >>['12..', '.5', '6...a']

# import re
# a = 'Beautiful, is; better*than\nugly'
# print(re.split(';| |,|\*|\n', a))     # 分隔符用 | 隔开, 即 ';', ' ', '*','\n'
# # >>['Beautiful', '', 'is', '', 'better', 'than', 'ugly']

# s = "1234abc567abc12"
# print(s.find("ab"))     # >>4
# print(s.rfind("ab"))    # >>10
# # find 从头开始找，rfind从尾巴开始找。返回第一个找到的位置
# try:
#     s.index("afb")  # 找不到"afb",引发异常
# except Exception as e:
#     print(e)        # substring not found
#
# print(s.find("12", 4))

# print(" \t12 34 \n ".strip())       # >>12 34
# print(" \t12 34 5".lstrip())        # >>12 34 5

# print("takeab \n".strip("ba \n"))       # >>take
# print("cd\t12 34 5".lstrip("d\tc"))     # >>12 34 5

# print(ord("a"))     # >>97
# print(ord("好"))     # >>22920
# print(chr(22900))   # >>奴
# print(chr(97))      # >>a

# t = 12345, 54321, 'hello!'
# print(t[0])     # >>12345
# print(t)        # >>(12345, 54321, 'hello!')
# u = t, [1, 2, 3, 4, 5]
# print(u)        # >>((12345, 54321, 'hello!'), [1, 2, 3, 4, 5])
# print(u[0][1])  # >>54321
# print(u[1][2])  # >>3
# u[1][2] = 4
# print(u[1])     # >>[1, 2, 4, 4, 5]
# t[0] = 88888    # 运行错误，元组的元素不能赋值

# empty = ()      # 空元组
# singleton = 'hello',    # 注意末尾的逗号，如果没有，就不是元组而是字符串了
# print(len(empty))       # >>0
# print(len(singleton))   # >>1
# x = ('hello',)          # 无逗号则x为字符串
# print(x)                # >>('hello',)


# tup1 = (12, 34.56)
# tup2 = ('abc', 'xyz')
#
# # 创建一个新元组
# tup3 = tup1 + tup2
# print(tup3)         # >>(12, 34.56, 'abc', 'xyz')
# tup3 += (10, 20)    # 新建了一个元组, tup3指向该新元组
# print(tup3)         # >>(12, 34.56, 'abc', 'xyz', 10, 20)


# x = (1, 2, 3) * 3
# print(x)                # >>(1, 2, 3, 1, 2, 3, 1, 2, 3)
# print(3 in (1, 2, 3))   # >>True
# for i in (1, 2, 3):
#     print(i, end='')    # >>123

# x = (1, 2, 3)
# b = x       # b与 x都指向(1, 2, 3)
# print(b is x)   # >>True
# x += (100,)     # 新建了一个元组，x指向该新元组
# print(x)        # >>(1, 2, 3, 100)
# print(b)        # >>(1, 2, 3)


# print((1, 'a', 12) < (1, 'b', 7))       # >>True
# print((1, 'a') < (1, 'a', 13))          # >>True
# print((2, 'a') > (1, 'b', 13))          # >>True
# print((2, 'a') < ('ab', 'b', 13))       # runtime error

# def isleap(year):
#     if (year % 4 == 0 and year % 100) or year % 400 == 0:
#         return True
#
#
# monthday = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
# weekday = 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'
# while(1):
#     s = input().split()
#     year = int(s[0])
#     month = int(s[1])
#     day = int(s[2])
#     passdays = 0
#     passdays += (year-2012) * 365
#     if(year > 2012):
#         passdays += (year-1-2012) // 4 + 1  # 补上闰年多的一天（不算当前年）
#     passdays -= (year-1-2012) // 100        # 扣掉把100整数倍的年份都当做闰年而多加的天数
#     passdays += (year-1-2012) // 400        # 加上400整数倍的闰年
#
#     if isleap(year):
#         monthday[1] = 29
#     for i in range(1, month):       # 再算经过的整月天数(不算当前月)
#         passdays += monthday[i-1]
#     passdays += day - 22
#     print(passdays % 7)

# string = input()
# newstr = ""
# for i in string:
#     if ord(i) in range(97, 97+32):
#         newstr += chr(ord(i) - 32)
#     elif ord(i) in range(65, 65+32):
#         newstr += chr(ord(i) + 32)
#     else:
#         newstr += i
# print(newstr)

# s = input()
# s1 = s[0] + s[1] + s[2]
# s2 = s[1] + s[2] + s[0]
# s3 = s[2] + s[0] + s[1]
# print(eval(s1 + "+" + s2 + "+" + s3))


# empty = []      # 空表
# list1 = ["PKU", 'Huawei', 1997, 2000]
# list1[1] = 100  # 列表元素可以赋值
# print(list1)    # >>['PKU', 100, 1997, 2000]
# del list1[2]    # 删除元素
# print(list1)    # >>['PKU', 100, 2000]
# list1 += [100, 100]     # 添加另一列表的元素100和110，在list1原地添加，没有新建一个列表
# list1.append(200)       # 添加元素 200，append用于添加单个元素
# print(list1)    # >>['PKU', 100, 2000, 100, 100, 200]
# list1.append(['ok', '123'])     # 添加单个元素
# print(list1)    # >>['PKU', 100, 2000, 100, 100, 200, ['ok', '123']]
# a = ['a', 'b', 'c']
# n = [a, 2, 3]
# x = [a, n]      # a若变，x也变
# a[0] = 1
# print(x)        # >>[[1, 'b', 'c'], [[1, 'b', 'c'], 2, 3]]
# print(x[0])     # >>[1, 'b', 'c']
# print(x[0][1])  # >>b

# a = [1, 2, 3, 4]
# b = [5, 6]
# c = a + b       # >>c为新的列表，与a,b无关
# print(c)        # >>[1, 2, 3, 4, 5, 6]
# a[0] = 100
# print(c)        # >>[1, 2, 3, 4, 5, 6]

# b = a = [1, 2]
# a += [3]        # >>b和a指向同一列表，在a末尾添加元素，b也受影响
# print(a, b)     # >>[1, 2, 3] [1, 2, 3]
# a = a + [4, 5]  # 对a重新赋值，不影响b
# print(a)        # >>[1, 2, 3, 4, 5]
# print(b)        # >>[1, 2, 3]

# print([True] * 3)   # >>[True, True, True]
# a = [1, 2]
# b = a * 3       # a列表中的元素为 1, 2，乘3遍变成 1,2,1,2,1,2
# print(b)        # >>[1, 2, 1, 2, 1, 2]
# print([a*3])    # >>[[1, 2, 1, 2, 1, 2]] ,a*3外面加个[]
# c = [a] * 3     # [a]列表中的元素为[1,2] , 乘3遍变成[1,2], [1,2], [1,2]
# print(c)        # >>[[1, 2], [1, 2], [1, 2]], c中的每个元素都与a指向同一列表
# a.append(3)
# print(c)        # >>[[1, 2, 3], [1, 2, 3], [1, 2, 3]]
# print(b)        # >>[1, 2, 1, 2, 1, 2]

# a = [1, 2, 3, 4]
# b = a[1:3]
# print(b)        # >>[2, 3]
# b[0] = 100
# print(b)        # >>[100, 3]
# print(a)        # >>[1, 2, 3, 4]
# print(a[::-1])  # >>[4, 3, 2, 1]
# print([1, 2, 3, 4, 5, 6][1:5:2])    # >>[2, 4]

# lst = [1, 2, 3, 4]
# for x in lst:
#     print(x, end=' ')
#     x = 100     # 不会修改列表元素
# print(lst)      # >>[1, 2, 3, 4]

# def selectionSort(lst):
#     n = len(lst)
#     for i in range(0, n):
#         for j in range(i, n):
#             if lst[j] < lst[i]:  # 找到小的就交换
#                 lst[i], lst[j] = lst[j], lst[i]
#
#
# a = [1, 12, 4, 56, 6, 2]
# a.sort()
# print(a)        # >>[1, 2, 4, 6, 12, 56]
# a = [1, 12, 4, 56, 6, 2]
# b = sorted(a)           # b为a排好序的列表，a不变
# print(b)        # >>[1, 2, 4, 6, 12, 56]
# print(a)        # >>[1, 12, 4, 56, 6, 2]
# a.sort(reverse=True)    # 降序
# print(a)        # >>[56, 12, 6, 4, 2, 1]

# students = [('John', 'A', 15),  # 姓名，成绩，年龄
#             ('Mike', 'C', 19),
#             ('Mike', 'B', 12),
#             ('Mike', 'C', 18),
#             ('Bom', 'D', 10)]
# students.sort()  # 先按姓名排，再按成绩排，最后按年龄排
# print(students)  # >>[('Bom', 'D', 10), ('John', 'A', 15), ('Mike', 'B', 12), ('Mike', 'C', 18), ('Mike', 'C', 19)]

# def myKey(x):  # 按个位数排序
#     return x % 10
#
#
# a = [25, 7, 16, 33, 4, 1, 2]
# a.sort(key=myKey)
# print(a)  # >>[1, 2, 33, 4, 25, 16, 7]
#
# b = sorted("This is a test string from Andrew".split(), key=str.lower)  # 不区分大小写排序
# print(b)  # >>['a', 'Andrew', 'from', 'is', 'string', 'test', 'This']

# k = lambda x, y: x + y
# print(k(4, 5))  # >>9

# students = [('Mike', 'A', 15),  # 姓名，成绩，年龄
#             ('Mike', 'C', 19),
#             ('Mike', 'B', 12),
#             ('Mike', 'C', 18),
#             ('Mike', 'D', 10)]
# # students.sort(key=lambda x: x[2])  # 按年龄排序
# # print(students)  # >>[('Bom', 'D', 10), ('Mike', 'B', 12), ('John', 'A', 15), ('Mike', 'C', 18), ('Mike', 'C', 19)]
# students.sort(key=lambda x: x[0])  # 按姓名排序
# print(students)  # >>[('Bom', 'D', 10), ('John', 'A', 15), ('Mike', 'B', 12), ('Mike', 'C', 18), ('Mike', 'C', 19)]

# def f(x):
#     return (-x[2], x[1], x[0])  # 先x[2]降序，后x[1], x[0]升序
#
#
# students = [('John', 'A', 15),  # 姓名，成绩，年龄
#             ('Mike', 'C', 19),
#             ('Mike', 'B', 12), ('Mike', 'B', 12),
#             ('Mike', 'C', 12),
#             ('Mike', 'C', 18),
#             ('Mike', 'D', 10)]
#
# students.sort(key=f)  # 先按年龄降序，再按成绩升序，再按姓名字典序
# print(
#     students)  # >>[('Mike', 'C', 19), ('Mike', 'C', 18), ('John', 'A', 15), ('Mike', 'B', 12), ('Mike', 'B', 12),
# # ('Mike', 'C', 12), ('Mike', 'D', 10)]
#
#
# def f(x):
#     print(x, end="")
#     return x * x
#
#
# a = map(f, [1, 2, 3])  # 对于列表每个元素，调用f函数，并将结果存起来（还未执行）
# print(list(a))  # 将a转换成list时，执行上述操作，>>123[1, 4, 9]
# print(tuple(a))  # >>()  a操作做完后就不会再做了
# a = list(map(lambda x: 2 * x, [2, 3, 4]))
# print(a)  # >>[4, 6, 8]


# x, y, z = map(int, input().split())
# print(x, y, z)

# def f(x):
#     return x % 2 == 0   # 筛选偶数
#
# lst = tuple(filter(f, [1, 2, 3, 4, 5]))
# print(lst)      # >>(2, 4)

# matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# print(matrix)   # >>[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# print(matrix[1][2], matrix[2][2])   # >>6 9
# matrix[1][1] = 100
# print(matrix)   # >>[[1, 2, 3], [4, 100, 6], [7, 8, 9]]
# matrix = [[0 for i in range(3)] for i in range(3)]
# print(matrix)   # >>[[0, 0, 0], [0, 0, 0], [0, 0, 0]]
# matrix = [[i*3+j for j in range(3)] for i in range(3)]
# print(matrix)   # >>[[0, 1, 2], [3, 4, 5], [6, 7, 8]]

# lst = []
# for i in range(3):
#     lst.append([0] * 4)
# lst[0][0] = lst[2][3] = 100
# for i in range(3):
#     for j in range(4):
#         print(lst[i][j], end=' ')
#     print("")   # 换行

# matrix = ((1, 2, 3), (4, 5, 6), (7, 8, 9))
# print(matrix)   # >>((1, 2, 3), (4, 5, 6), (7, 8, 9))
# matrix = tuple(tuple(0 for i in range(3)) for i in range(3))
# print(matrix)   # >>((0, 0, 0), (0, 0, 0), (0, 0, 0))


# a = [1, 2, 3, 4]
# b = a[:]  # b是a的拷贝，指向不同对象
# print(a)  # >>[1, 2, 3, 4]
# b += [10]
# print(a)  # >>[1, 2, 3, 4]
# print(b)  # >>[1, 2, 3, 4, 10]

# a = [1, [2]]
# b = a[:]
# b.append(4)
# print(b)    # >>[1, [2], 4]
# a[1].append(3)
# print(a)    # >>[1, [2, 3]]
# print(b)    # >>[1, [2, 3], 4]

# import copy
# a = [1, [2]]
# b = copy.deepcopy(a)
# b.append(4)
# print(b)        # >>[1, [2], 4]
# a[1].append(3)
# print(a)        # >>[1, [2, 3]]
# print(b)        # >>[1, [2], 4]


# a = [1, 2, 3]
# b = tuple(a)    # b: (1, 2, 3)
# c = list(b)     # c: [1, 2, 3]
# t = (1, 3, 2)
# (a, b, c) = t   # a = 1, b = 3, c = 2
# s = [1, 2, 3]
# [a, b, c] = s   # a = 1, b = 2, c = 3

# print(list("hello"))        # >>['h', 'e', 'l', 'l', 'o']
# print("".join(['a', '44', 'c']))    # >>a44c
# print(tuple("hello"))       # >>('h', 'e', 'l', 'l', 'o')
# print("".join(('a', '44', 'c')))    # >>a44c

# n = int(input())
# x = []
# for i in range(n):
#     lst = input().split()
#     name, score = lst[0], int(lst[1])
#     x.append([name, score])
# x.sort(key=lambda a: (-a[1], a[0]))
# for i in range(n):
#     print(x[i][0], x[i][1])
# import copy
#
# lst = input().split()
# n, m = int(lst[0]), int(lst[1])
# x = []
# for i in range(n):
#     x.append(list(map(int, input().split())))
#
# res = copy.deepcopy(x)
# for i in range(1, n-1):
#     for j in range(1, m-1):
#         res[i][j] = round((x[i][j] + x[i-1][j] + x[i+1][j] + x[i][j-1] + x[i][j+1])/5)
#
# for i in range(n):
#     for j in range(m):
#         print(res[i][j], end=" ")
#     print("")

# s = input()
# if s == '6174':
#     print("7641 - 1467 = 6174")
# else:
#     while s != '6174':
#         lst = []
#         for i in s:
#             lst += [i]
#         lst.sort()  # 升序
#         op2 = int(''.join(lst))
#         a = lst[::-1]   # 降序
#         op1 = int(''.join(a))
#         if op1 == op2:
#             print("%04d - %04d = 0" % (int(op1), int(op2)))
#             break
#         else:
#             s = str(eval("op1 - op2"))
#             print("%04d - %04d = %04d" % (int(op1), int(op2), int(s)))

# scope = {}  # 空字典
# scope['a'] = 3  # 添加元素 'a':3
# scope['b'] = 4  # 添加元素 'b':4
# print(scope)  # >>{'a': 3, 'b': 4}
# print('b' in scope)  # >>True
# scope['k'] = scope.get('k', 0) + 1
# # get(k, v): 如果键key存在，返回key对应的值；否则返回v
# print(scope['k'])  # >>1
# scope['k'] = scope.get('k', 0) + 1
# print(scope['k'])  # >>2

# a = (1, 2, 3)
# b = (1, 2, 3)
# d = {a:60, b:70, (1, 2, 3):80, (1, 2, 3):50}    # 实际上d中只有一个元素
# print(d[a])     # >>50
# print(d[b])     # >>50
# print(d[(1, 2, 3)])     # >>50
# print(d)        # >>{(1, 2, 3): 50}

# items = [('name', 'Gumby'), ('age', 42)]
# d = dict(items)  # 字典的类型名是dict
# print(d)        # >>{'name': 'Gumby', 'age': 42}
# d = dict(name='Gumby', age=42, height=1.76)
# print(d)        # >>{'name': 'Gumby', 'age': 42, 'height': 1.76}


# d = {'name': 'Gumby', 'age': 42, 'GPA': 3.5}
# if 'age' in d.keys():
#     print(d['age'])     # >>42
# for x in d.items():     # x为元组
#     print(x, end=', ')  # >>('name', 'Gumby'), ('age', 42), ('GPA', 3.5),
# for x in d.items():     # 元组第一个元素为键
#     print(x[0], end=', ')   # >>name, age, GPA,
# for x in d.items():
#     print(x[1], end=', ')   # >>Gumby, 42, 3.5,
# for k, v in d.items():  # k为键，v为value
#     print(k, v, end=', ')   # >>name Gumby, age 42, GPA 3.5,
# for x in d.keys():
#     print(x, end=', ')      # >>name, age, GPA,
# for x in d.values():
#     print(x, end=', ')  # >>Gumby, 42, 3.5,


# x = {'username': 'admin', 'machines': ['foo', 'bar', 'baz'], 'Age': 15}
# for i in x.items():
#     print(i[0])
#     print(i[1])

# d = {}
# while 1:
#     try:
#         word = input()
#         d[word] = d.get(word, 0) + 1
#     except:
#         break
# result = []     # 将元素放到列表中排序
# for x in d.items():
#     result.append(x)
# result.sort(key=lambda a: (-a[1], a[0]))
# for i in result:
#     print(i[1], i[0])


# print(set([]))  # >>set()  集合可由列表转换得到，set([])是空集合
# a = {1, 2, 2, 'ok', (1, 3)}
# print(a)        # >>{1, 2, (1, 3), 'ok'}
# b = (3, 4)
# c = (3, 4)
# a = set((1, 2, 'ok', 2, b ,c))
# for x in a:         # >>1 2 (3, 4) ok
#     print(x, end=' ')
# a = set("abc")      # 字符串转集合，每个字符一个元素
# print(a)        # >>{'b', 'c', 'a'}
# a = set({1: 2, 'ok': 3, (3, 4): 4})     # 字典转集合只取键
# print(a)        # >>{1, (3, 4), 'ok'}

# s = set([])
# while 1:
#     try:
#         word = input()
#         if word not in s:
#             s.add(word)
#     except:
#         break
# print(len(s))


# d = {}
# index = 1   # 记录输入整数的下标
# while 1:
#     try:
#         n = int(input())
#         if n not in d:   # 不存在则次数为1
#             d[n] = [1, index]
#         else:
#             d[n][0] += 1     # 字典中存在当前整数，次数加1
#     except:
#         break
# lst = []
# for k, v in d.items():
#     tmp = [k, v[0], v[1]]
#     lst.append(tmp)
# lst.sort(key=lambda x: (x[1], x[2]))    # 先按次数排序，再按下标排序
# print(lst[0][0], lst[0][1])     # 输出整数和次数


# a = open("c:\\tmp\\t.txt", 'w')  # 'w'表示以写入方式打开文件。若文件存在则会被清空覆盖
# a.write("good\n")
# a.write("好啊\n")
# a.close()

# f = open("c:\\tmp\\t.txt", 'r')  # 'r'表示以读取方式打开文件
# lines = f.readlines()
# f.close()
# for x in lines:
#     print(x, end="")

# try:
#     infile = open("c:\\tmp\\t.txt", 'r')
#     while True:
#         data1 = infile.readline()   # data1包括结尾的换行符
#         if data1 == '':     # 条件满足代表文件结束
#             break
#         data1 = data1.strip()   # 去掉两头空格，包括'\n'
#         print(data1)
#     infile.close()
# except Exception as e:
#     print(e)        # >>[Errno 2] No such file or directory: 'c:\\tmp\\t.txt'

# f = open("c:\\tmp\\t.txt", 'a')     # 'a'表示append
# f.write("新增行\n")
# f.write("ok\n")
# f.close()

# outfile = open("c:\\tmp\\t.txt", 'w', encoding='utf-8')
# # 若打开文件用于写入时不指定编码，则使用系统默认编码。win10也可能是Ansi(gbk)


# import os
#
#
# def powerRmdir(path):  # 删除 path目录中所有文件及其所有子目录
#     lst = os.listdir(path)
#     for x in lst:  # x为文件名（不包括路径），例如a.txt
#         actualFileName = path + '/' + x  # 构造x的路径名
#         if os.path.isfile(actualFileName):  # 是文件，删除
#             os.remove(actualFileName)
#         else:  # 是子目录，递归删除
#             powerRmdir(actualFileName)
#     os.rmdir(path)  # path目录为空时才能删除


# import os
#
#
# def getTotalSize(path):  # 获取目录总大小（单位：字节）
#     total = 0
#     lst = os.listdir(path)
#     for x in lst:
#         actualFileName = path + '/' + x
#         if os.path.isfile(actualFileName):
#             total += os.path.getsize(actualFileName)
#         else:
#             total += getTotalSize(actualFileName)
#     return total

# import sys
#
# for x in sys.argv:
#     print(x)

# import sys
# import re
#
#
# def countFile(filename, words):
#     # 对filename文件进行词频统计，结果存到字典words里
#     try:
#         f = open(filename, 'r', encoding='gbk')  # 以读方式打开源文件
#     except Exception as e:
#         print(e)
#         return 0  # 失败
#     txt = f.read()  # 将文件全部内容存到字符串txt中
#     f.close()
#
#     splitChars = set([])  # 分隔符集合
#     # 遍历整个文件，获得所有分隔符
#     for c in txt:
#         if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):  # 不是字母的都是分隔符
#             splitChars.add(c)
#     splitStr = ""  # 用于re.split的正则表达式
#     # 分隔符间以|分隔，末尾不能为|
#     for c in splitChars:
#         if c in {'.', '?', '!', '"', "'", '(', ')', '|', '*', '$', '\\', '[', ']', '^', '{', '}'}:
#             # 上面的特殊字符在字符串中要加\
#             splitStr += "\\" + c + "|"
#         else:
#             splitStr += c + "|"
#     splitStr += " "  # |后必须有东西，因此加一个空格
#     lst = re.split(splitStr, txt)  # lst为分隔后的单词列表
#     for x in lst:
#         if x == "":  # 相邻两个分隔符间会分隔出来一个空串，跳过
#             continue
#         lx = x.lower()  # 转为小写
#         # 记录词频
#         words[lx] = words.get(lx, 0) + 1
#     return 1  # 成功
#
#
# result = {}  # 结果字典。格式为 { 'a' : 2, 'about' : 3 ...}
# if countFile(sys.argv[1], result) == 0:  # 如果统计失败
#     exit()
# lst = list(result.items())  # result.items()返回元组，放入列表（字典不可排序）
# lst.sort()  # 单词按字典序排序
# f = open(sys.argv[2], 'w')  # 以写入方式打开结果文件
# for x in lst:
#     f.write("%s\t%d\n" % (x[0], x[1]))  # 统计结果写入结果文件
# f.close()
# import os
#
# result = {}  # 结果字典。格式为 { 'a' : 2, 'about' : 3 ...}
# lst = os.listdir()  # 列出当前目录下所有文件和目录
# for x in lst:
#     if os.path.isfile(x):  # 如果是文件
#         if x.lower().endswith(".txt") and x.lower().startswith("a"):
#             # x以'a'开头，以.txt结尾
#             countFile(x, result)
# lst = list(result.items())  # result.items()返回元组，放入列表（字典不可排序）
# lst.sort()  # 单词按字典序排序
# f = open(sys.argv[1], 'w')  # 以写入方式打开结果文件
# for x in lst:
#     f.write("%s\t%d\n" % (x[0], x[1]))  # 统计结果写入结果文件
# f.close()


# import os
# import re
# import sys
#
#
# def makeVaryWordsDict():  # 构造变形->原型的映射字典
#     vary_words = {}
#     f = open("words_varys.txt", "r")
#     lines = f.readlines()  # lines是一个列表，每个元素是文件中的一行
#     f.close()
#     L = len(lines)
#     for i in range(0, L, 2):  # 每两行为一个单词原型及变形。lines[i]是原型，lines[i+1]为变形
#         word = lines[i].strip()  # 去掉空格及换行符
#         varys = lines[i + 1].strip().split('|')  # 以|分隔
#         for w in varys:
#             vary_words[w] = word  # 添加映射
#     return vary_words
#
#
# def makeSplitStr(txt):
#     splitChars = set([])  # 分隔符集合
#     # 遍历整个文件，获得所有分隔符
#     for c in txt:
#         if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):  # 不是字母的都是分隔符
#             splitChars.add(c)
#     splitStr = ""  # 用于re.split的正则表达式
#     # 分隔符间以|分隔，末尾不能为|
#     for c in splitChars:
#         if c in {'.', '?', '!', '"', "'", '(', ')', '|', '*', '$', '\\', '[', ']', '^', '{', '}'}:
#             # 上面的特殊字符在字符串中要加\
#             splitStr += "\\" + c + "|"
#         else:
#             splitStr += c + "|"
#     splitStr += " "  # |后必须有东西，因此加一个空格
#     return splitStr
#
#
# def countFile(filename, vary_word_dict):
#     # filename为要分析的文件，vary_word_dict为变形->原型的映射字典
#     try:
#         f = open(filename, 'r')
#     except Exception as e:
#         print(e)
#         return None
#     txt = f.read()  # 文件所有内容存入txt
#     f.close()
#     splitStr = makeSplitStr(txt)
#     words = {}
#     lst = re.split(splitStr, txt)
#     for x in lst:
#         lx = x.lower()
#         if lx == "":
#             continue
#         if lx in vary_word_dict:  # 单词在键中能找到，则为变形，转成原型后在统计
#             lx = vary_word_dict[lx]
#         # 统计词频
#         words[lx] = words.get(lx, 0) + 1
#     return words
#
#
# result = countFile(sys.argv[1], makeVaryWordsDict())  # result为词频统计字典
# if result is not None and result != {}:
#     lst = list(result.items())
#     lst.sort()
#     f = open(sys.argv[2], 'w')
#     for x in lst:
#         f.write("%s\t%d\n" % (x[0], x[1]))
#     f.close()
#
#
# import os
# import sys
# import re
#
#
# def makeFileterSet():   # 构造四级单词集合
#     cet4words = set([])
#     f = open("cet4words.txt", 'r')
#     lines = f.readlines()   # lines为列表，每个元素为文件的一行
#     f.close()
#     for line in lines:
#         line = line.strip()  # 去掉首尾空格及换行符
#         if line == "":
#             continue
#         if line[0] == '$':   # 是单词
#             cet4words.add(line[1:])  # 下标1到末尾组成单词
#     return cet4words
#
#
# def makeSplitStr(txt):
#     splitChars = set([])  # 分隔符集合
#     # 遍历整个文件，获得所有分隔符
#     for c in txt:
#         if not ('a' <= c <= 'z' or 'A' <= c <= 'Z'):  # 不是字母的都是分隔符
#             splitChars.add(c)
#     splitStr = ""  # 用于re.split的正则表达式
#     # 分隔符间以|分隔，末尾不能为|
#     for c in splitChars:
#         if c in {'.', '?', '!', '"', "'", '(', ')', '|', '*', '$', '\\', '[', ']', '^', '{', '}'}:
#             # 上面的特殊字符在字符串中要加\
#             splitStr += "\\" + c + "|"
#         else:
#             splitStr += c + "|"
#     splitStr += " "  # |后必须有东西，因此加一个空格
#     return splitStr
#
#
# def countFile(filename, filterdict):    # 词频统计，要去掉在filterdict中的单词
#     words = {}
#     try:
#         f = open(filename, 'r')
#     except Exception as e:
#         print(e)
#         return 0
#     txt = f.read()
#     f.close()
#     splitStr = makeSplitStr(txt)
#     lst = re.split(splitStr, txt)
#     for x in lst:
#         lx = x.lower()
#         if lx == "" or lx in filterdict:    # 去掉空串和非四级单词
#             continue
#         # 统计词频
#         words[lx] = words.get(lx, 0) + 1
#     return words
#
#
# result = countFile(sys.argv[1], makeFileterSet())
# if result != {}:
#     lst = list(result.items())
#     lst.sort()
#     f = open(sys.argv[2], 'w')
#     for x in lst:
#         f.write("%s\t%d\n" % (x[0], x[1]))
#     f.close()

# print('\u4e00\u4e01\u4e88\u9fa5')	# >>一丁予龥


# import re
#
#
# def match(pattern, string):
#     x = re.match(pattern, string)
#     if x is not None:
#         print(x.group())  # x.group是匹配上的字符串
#     else:
#         print("None")
#
#
# match("a  c", "a  cdkgh")    # >>a c
# match("abc", "kabc")        # >>None (虽然有abc，但不在起始位置)
# match("a\tb*c", "a\tbbcde") # >>a   bbc (b出现0次或任意次，然后跟c)
# match("ab*c", "ac")         # >>ac
# match("a\d+c", "ac")        # >>None
# match("a\d{2}c", "a34c")    # >>a34c
# match("a\d{2,}c", "a3474884c")  # >>a3474884c
# match(".{2}bc", "cbcd")     # >>None (bc前面要有两个字符)


# import re
#
#
# def search(pattern, string):
#     x = re.search(pattern, string)
#     if x is not None:
#         print(x.group(), x.span())  # 输出子串及起止位置
#     else:
#         print("None")
#
#
# search("a.+bc*", "dbaegsfbcef")  # >>aegsfbc (2, 9)
# search("a.+bc*", "bcdbaegsfbccc")  # >>aegsfbccc (4, 13)
# search("a.?bc*d", "dabccdc")  # >>abccd (1, 6)
# search("aa", "baaaa")  # >>aa (1, 3)
# search("\([1-9]+\)", "ab123(0456)(789)45ab")  # >>(789) (11, 16)
# search("[1-9]\d+", "ab01203d45")  # >>1203 (3, 7)


# import re
#
# print(re.findall('\d+', "this is 334 what me 7734gw"))  # >>['334', '7734']
# print(re.findall('[a-zA-Z]+', "A dog has 4 legs.这是true"))  # >>['A', 'dog', 'has', 'legs', 'true']
# print(re.findall('\d+', "this is good."))  # >>[]
# print(re.findall("aaa", "baaaa"))  # >>['aaa']


# import re
#
# s = '233[32]88ab<433>(21)'
# m = '\[\d+\]|<\d+>'  # | 表示或
# for x in re.finditer(m, s):  # x是匹配对象
#     print(x.group(), x.span())
# i = 0
# for y in re.finditer(m, "aaaaa"):
#     i += 1  # 不会被执行

# import re
# str = re.sub('\d+', '...', 'abc13de4fg')
# print(str)  # >>abc...de...fg
# print(re.sub('\d+', "", "abc13de4fg"))  # >>abcdefg
# print(re.sub('gone', 'go', "I gone hegone me"))  # >>I go hego me


# import re
#
#
# def search(pattern, string):
#     x = re.search(pattern, string)
#     if x is not None:
#         print(x.group(), x.span())  # 输出子串及起止位置
#     else:
#         print("None")
#
# pt = "ka\\b.*"
# search(pt, "ka")    # >>ka (0, 2)
# search(pt, "kax")   # >>None
# search(pt, "ka?d")  # >>ka?d (0, 4)
# pt = ".*\\bka\\b"
# search(pt, "ka")    # >>ka (0, 2)
# search(pt, "ska?")  # >>None
# search(pt, "b?ka?") # >>b?ka (0, 4)
# m = r"\bA.*N\b T"   # >>等价于 m = "\\bA.*N\\b T"
# search(m, "Ass$NC TK")  # >>None
# search(m, "this Ass$N TK")  # >>Ass$N T (5, 12)
# m = "\BA.*N\B\w T"
# search(m, "this Ass$N TK")  # >>None
# search(m, "thisAss$NM TK")  # >>Ass$NM T (4, 12)
# search(m, "Ass$NM TK")   # >>None
# search(m, "xAss$NM TK")  # >>Ass$NM T (1, 9)
# pt = "\\b高兴"
# search(pt, "我高兴")   # >>None
# search(pt, "我 高兴")  # >>高兴 (2, 4)


# import re
# x = re.search('[a-z]+(\d+)[a-z]+', "ab 123d hello553world47")
# print(x.group(1))           # >>553
# m = "(((ab*)c)d)e"   # 分组1: (ab*) 分组2: ((ab*(c) 分组3:(((ab*)c)d)
# r = re.match(m, "abcdefg")
# print(r.group(0))           # >>abcde   group(0) 等价于 group()
# print(r.group(1))           # >>abcd
# print(r.group(2))           # >>abc
# print(r.group(3))           # >>ab
# print(r.groups())           # >>('abcd', 'abc', 'ab')

# import re
# m = "(ab*)(c(d))e"
# r = re.match(m, "abcdefg")
# print(r.groups())   # >>('ab', 'cd', 'd')
# print(r.group(0))   # >>abcde
# print(r.group(1))   # >>ab
# print(r.group(2))   # >>cd
# print(r.group(3))   # >>d


# import re
# m = r'(((ab*)c)d)e\3'   # \3表示ab*cde后面要跟着一个3号分组本次匹配中匹配上的子串
# r = re.match(m, "abbbcdeabbb")
# # group(3)为abbb，因此abbbcde后面要跟上abbb，整个串才能匹配成功，少一个b都不行
# print(r.group(3))       # >>abbb
# print(r.group())        # >>abbbcdeabbb
#
# pt = 'a(.)\\1*b'    # 或pt = r'a(.)\1*b)  \1表示1号分组出现0到任意次
# print(re.search(pt, 'kacccccb').group())    # >>acccccb
# print(re.search(pt, 'kaxxxxb').group())     # >>axxxxb
# print(re.search(pt, 'kaxb').group())        # >>axb
# x = re.search(pt, 'kaxyb')  # 匹配不上 x后必须出现字母x
# if x is not None:
#     print(x.group())


# import re
# m = "(((ab*)+c)d)e"     # +表示(ab*)可出现1到任意次，不要求每次都一样
# r = re.match(m, "ababbcdefg")
# print(r.groups())   # >>('ababbcd', 'ababbc', 'abb')
# print(r.group())    # >>ababbcde
#
# r = re.match(m, "abacdefg")
# print(r.groups())   # >>('abacd', 'abac', 'a')  3号分组最后一次配的是'a'


# import re
# m = '[a-z]+(\d+)[a-z]+'     # 两边被字母夹着的数
# x = re.findall(m, "13 bc12de ab11 cd320ef")
# print(x)    # >>['12', '320']

# import re
# m = '(\w+) (\w+)'   # 两个单词，中间空格
# r = re.match(m, "hello world")
# print(r.groups())   # >>('hello', 'world')
# print(r.group(1))   # >>hello
# print(r.group(2))   # >>world
# r = re.findall(m, 'hello world, this is very good')
# print(r)    # >>[('hello', 'world'), ('this', 'is'), ('very', 'good')]


# import re
# pt = "\d+\.\d+|\d+" # 小数或整数（正）
# print(re.findall(pt, "12.34 this is 125"))  # >>['12.34', '125']
# pt = "aa|aab"
# print(re.findall(pt, "aabcdeaa12aab"))  # >>['aa', 'aa', 'aa'] (不会匹配到aab)


# import re
#
# m = "(((ab*)+c|12)d)e"
# print(re.findall(m, 'ababcdefgKK12deK'))
# # >>[('ababcd', 'ababc', 'ab'), ('12d', '12', '')]
# for x in re.finditer(m, "ababcdefgKK12deK"):
#     print(x.groups())
# # >>('ababcd', 'ababc', 'ab')
# # >>('12d', '12', None)
# m = '\[(\d+)\]|<(\d+)>'
# for x in re.finditer(m, '233[32]88ab<433>'):
#     print(x.group(), x.groups())
# # >>[32] ('32', None)
# # >><433> (None, '433')


# import re
# print(re.match("ab*", "abbbbk").group())    # >> abbbb
# print(re.findall("<h3>(.*)</h3>", "<h3>abd</h3><h3>bcd</h3>"))  # 本意是匹配 abd和 bcd
# # >>['abd</h3><h3>bcd']
# print(re.findall('\(.+\)', "A dog has(have a).这(哈哈) true()me"))
# # >>['(have a).这(哈哈) true()']

# import re
# m = "a.*?b"
# for k in re.finditer(m, "aabab"):
#     print(k.group(), end=" ")   # >>aab ab
# m = "<h3>.*?</h3>"
# a = re.match(m, "<h3>abd</h3><h3>bcd</h3>")
# print(a.group())    # >><h3>abd</h3>
# m = "<h3>.*?[M|K]</h3>"
# a = re.match(m, "<h3>abd</h3><h3>bcK</h3>")
# print(a.group())    # >><h3>abd</h3><h3>bcK</h3>
#
# print(re.findall('\d+?', "this is 334 what me 774gw"))
# # >>['3', '3', '4', '7', '7', '4']
# print(re.findall('[a-zA-Z]+?', "A dog has 4 legs.这是true"))
# # >>['A', 'd', 'o', 'g', 'h', 'a', 's', 'l', 'e', 'g', 's', 't', 'r', 'u', 'e']
# print(re.findall('\(.*?\)', "A dog has(have).这(哈哈)true()me"))
# # >>['(have)', '(哈哈)', '()']


# import re
#
# m = re.match(r'(\w+) (\w+)(.)', 'hello world!ss')
# print(m.string)  # >>hello world!ss
# print(m.lastindex)  # >>3
# print(m.group(0, 1, 2, 3))  # >>('hello world!', 'hello', 'world', '!')
# print(m.groups())   # >>('hello', 'world', '!')
# print(m.start(2))   # >>6
# print(m.end(2))     # >>11
# print(m.span(2))    # >>(6, 11)

# import re
#
# f = open("三国演义utf8.txt", "r", encoding="utf-8")
# txt = f.read()
# f.close()
# pt = "(孔明.{0,2}曰：“[^“]*(曹操|曹贼|操贼|曹阿瞒|操).*?“)"
# a = re.findall(pt, txt)
# print(len(a))
# for x in a:
#     print(x[0])


# import re
#
# ipadr = r"\b((25[0-5]|2[0-4]\d|((1\d{2})|([1-9]?\d)))\.){3}(25[0-5]|2[0-4]\d|((1\d{2})|([1-9]?\d)))\b"
# mailbox = r"\b[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+\b"
# url = r'http://[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(\.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+(/[-a-zA-Z0-9]+)*\b'
#
# s = 'My ip is 223.44.3.4, this is' \
#     'http://www.pku.edu.cn/python/new, http://www.sohu.com' \
#     'my mailbox is guo_wei@pku.edu.cn. ok?'
#
# m = re.search(ipadr, s)
# if m is not None:
#     print(m.group())    # >>223.44.3.4
