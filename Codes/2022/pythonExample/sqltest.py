# import sqlite3
# db = sqlite3.connect('test2.db')    # 连接数据库，若不存在则自动创建
# cur = db.cursor()   # 获取光标，要操作数据库一般要通过光标进行
# sql = '''create table if not exists students (
# id integer primary key,
# name text,
# gpa real,
# birthday date,
# age integer,
# picture blob)'''
# cur.execute(sql)    # 执行sql命令
# cur.execute("insert into students values(1600, '张三', 3.81, '2000-09-12', 18, null)")    # 插入一个记录
# # 以列表方式插入记录
# mylist = [(1700, '李四', "3.25", '2001-12-01', 17, None),
#           (1800, '王五', "3.35", '1999-01-01', 19, None)]
# for s in mylist:    # 依次插入mylist中的每个记录
#     cur.execute('insert into students values(?, ?, ?, ?, ?, ?)',
#                 (s[0], s[1], s[2], s[3], s[4], s[5]))
# db.commit()     # 真正写入，对数据库进行修改操作都需要这条语句
# cur.close()     # 关闭光标
# db.close()      # 关闭数据库


# import sqlite3
#
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# sql = 'select * from students'  # 检索全部记录
# cur.execute(sql)
# x = cur.fetchone()      # fetchone取满足条件的第一条记录（返回元组）
# print(x)        # >>(1600, '张三', 3.81, '2000-09-12', 18, None)
# print(x[1])     # >>张三
# for x in cur.fetchall():  # fetchall取得满足条件的所有记录
#     print(x[:-2])   # age,picture字段不打出
# cur.execute("select * from students where name = 'Jack'")
# x = cur.fetchone()
# if x is None:
#     print("can't find Jack")
# cur.close()
# db.close()


# import sqlite3
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# sql = 'select name, gpa, age from students where gpa > 3.3 order by age desc'
# # 查找gpa>3.3的学生中的三个字段，按年龄降序
# cur.execute(sql)
# x = cur.fetchall()  # 返回所有记录（元组）的列表
# if x != []:     # 能查到记录
#     print("total: ", len(x))    # >>total: 2
#     for r in x:  # 遍历列表，打印所有记录
#         print(r)    # >>('王五', 3.35, 19) \n ('张三', 3.81, 18)
# cur.close()
# db.close()


# import sqlite3
#
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# sql = 'update students set gpa = ?, age = ? where name = ?'
# cur.execute(sql, (4.0, 20, '李四'))  # 元组的三个元素分别对应 3个？
# # 修改李四的gpa和年龄。若李四不存在，则无效果
# db.commit()  # 此语句不可忽略
# sql = "select * from students"
# cur.execute(sql)
# for x in cur.fetchall():
#     print(x)
# cur.close()
# db.close()

# import sqlite3
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# cur.execute("drop table if exists students")
# db.commit()
# try:
#     cur.execute("select * from students")
#     x = cur.fetchall()
#     for r in x:
#         print(r[:-1])
# except:
#     print("No table")       # >>No table
# cur.close()
# db.close()


# import sqlite3
# import requests
# f = open('balloons.jpg', 'rb')  # 以二进制方式打开图片
# img = f.read()
# f.close()
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# sql = "update students set picture = ? where name = '张三'"
# cur.execute(sql, (img,))    # 设置李四的照片。img对应？


# import sqlite3
# import requests
#
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# # 从网络获取图片
# imgUrl = "http://img5.duitang.com/uploads/item/201605/19/20150519224441_VfMWR.jpeg"
# imgStream = requests.get(imgUrl, stream=True)
# sql = "update students set picture = ? where name = '张三'"
# cur.execute(sql, (imgStream.content, ))  # 设置张三的照片。img对应于？
#
# db.commit()
# cur.close()
# db.close()

# import sqlite3
# import requests
#
# db = sqlite3.connect("test2.db")
# cur = db.cursor()
# sql = "select name, picture from students where name = '张三' or name = '李四'"
# cur.execute(sql)
# x = cur.fetchall()
# for r in x:     # r[0]是姓名，r[1]是图片文件数据
#     f = open(r[0] + '.jpg', 'wb')   # 照片写入 张三.jpg 和 李四.jpg
#     f.write(r[1])
#     f.close()
# cur.close()
# db.close()

