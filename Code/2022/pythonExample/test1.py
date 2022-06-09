# import turtle        # turtle是一个类
#
# import turtle as tt  # 此后tt等价于turtle
#
# import PIL.Image    # PIL.Image是类中的类
#
# from PIL import Image   # 从PIL库导入Image类进行图像处理
#
# img = PIL.Image.open("balloons.jpg")
# img.show()

# import PIL.Image, PIL.ImageDraw, PIL.ImageFont  # 同时引入多个类
#
# from PIL import Image, ImageDraw, ImageFont
#
# from openpyxl.styles import Font, colors, Alignment


# import datetime
#
# dtBirth = datetime.date(2000, 9, 27)    # 创建日期对象，日期为2000年9月17日
# print(dtBirth.weekday())    # >>2  输出dtBirth代表的日期是星期几。0表示星期一
#
# dtNow = datetime.date.today()   # 取今天日期（2022-2-2）
# print(dtBirth < dtNow)      # >>True    日期可以比大小
#
# life = dtNow - dtBirth      # 取两个日期的时间差
# print(life.days, life.total_seconds())  # >>7798 673747200.0
#
# delta = datetime.timedelta(days=-10)     # 构造时间差对象，时间差为-10天
# newDate = dtNow + delta     # newDate代表的日期是dtNow的日期往前数10天
# print(newDate.year, newDate.month, newDate.day, newDate.weekday())  # >>2022 1 23 6 （2022年1月23日 星期日）
#
# print(newDate.strftime(r'%m/%d/%Y'))    # >>01/23/2022
# newDate = datetime.datetime.strptime("2000.08.05", "%Y.%m.%d")
# print(newDate.strftime("%Y%m%d"))   # >>20000805


# import datetime
#
# tm = datetime.datetime.now()    # 取当前时刻，精确到微秒
# print(tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second, tm.microsecond)
# # >>2022 2 2 21 42 12 136760    当前时刻是 2022年 8月 15日 21时 42分 12秒 136760微秒
# tm = datetime.datetime(2017, 8, 10, 15, 56, 10, 0)
# # 构造一个时刻，2017年8月10日15时56分10秒0微秒
# print(tm.strftime("%Y%m%d %H:%M:%S"))   # >>20170810 15:56:10
# print(tm.strftime("%Y%m%d %I:%M:%S %p"))    # >>20170810 03:56:10 PM
#
# tm2 = datetime.datetime.strptime("2013.08.10 22:31:24", "%Y.%m.%d %H:%M:%S")    # 由字符串生成一个时间对象
# delta = tm - tm2    # 求两个时刻的时间差
# print(delta.days, delta.seconds, delta.total_seconds())
# # >>1460 62686 126206686.0  时间差是1460天62686秒，总共126206686.0秒
# delta = tm2 - tm
# print(delta.days, delta.seconds, delta.total_seconds())
# # >> -1461 23714 -126206686.0
#
# delta = datetime.timedelta(days=10, hours=10, minutes=30, seconds=20)
# # 构造一个时间差，10天10小时30分20秒
# tm2 = tm + delta
# print(tm2.strftime("%Y%m%d %H:%M:%S"))  # >>20170821 02:26:30


# import random
#
# print(random.random())      # >>0.2513304445557907
# print(random.uniform(1.2, 7.8))  # >>1.7099692554739307
# print(random.randint(-20, 70))      # >>-19
# print(random.randrange(2, 30, 3))   # >>8
# print(random.choice("hello,world"))  # >>l
#
# lst = [1, 2, 3, 4, 5, 6]
# random.shuffle(lst)
# print(lst)  # >>[5, 4, 6, 1, 2, 3]
# print(random.sample(lst, 3))  # >>[5, 4, 6]


# import random
# random.seed(2)  # 或random.seed("ok")...种子可以是任意数、字符串...
# # 此时下面程序运行结果每次都一样
# print(random.random())      # >>0.2513304445557907
# print(random.uniform(1.2, 7.8))  # >>1.7099692554739307
# print(random.randint(-20, 70))      # >>-19
# print(random.randrange(2, 30, 3))   # >>8
# print(random.choice("hello,world"))  # >>l
#
# lst = [1, 2, 3, 4, 5, 6]
# random.shuffle(lst)
# print(lst)  # >>[5, 4, 6, 1, 2, 3]
# print(random.sample(lst, 3))  # >>[5, 4, 6]


# import random
#
# cards = [str(i) for i in range(2, 11)]
# cards.extend(list("JQKA"))
# # cards是 ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
# allCards = []   # 一副牌
# for s in "♣◇♠♥":    # 梅花、菱形、黑桃、红桃
#     for c in cards:
#         allCards.append(s+c)    # allCards元素形式如：'♣3'
# random.shuffle(allCards)    # 随机打乱52张牌
# for i in range(4):
#     onePlayer = allCards[i::4]  # 每个玩家都是隔三张牌取一张
#     onePlayer.sort()    # 扑克牌排序规则略复杂，这个排序不完美
#     print(onePlayer)    # 打印该玩家的牌


# import jieba
#
# s = "我们热爱中华人民共和国"
# lst = jieba.lcut(s)     # 分词的结果是个列表
# # 默认用精确模式分词，分出的结果正好拼成原文
# print(lst)  # >>['我们', '热爱', '中华人民共和国']
# print(jieba.lcut(s, cut_all=True))  # 全模式分词，输出所有可能组成的词
# # >>['我们', '热爱', '中华', '中华人民', '中华人民共和国', '华人', '人民', '人民共和国', '共和', '共和国']
# print(jieba.lcut_for_search(s))  # 搜索引擎模式分词
# # >>['我们', '热爱', '中华', '华人', '人民', '共和', '共和国', '中华人民共和国']
# s = "拼多多是个网站"
# print(jieba.lcut(s))    # >>['拼', '多多', '是', '个', '网站']
# jieba.add_word("拼多多")   # 往词典里添加新词
# print(jieba.lcut(s))    # >>['拼多多', '是', '个', '网站']


# import jieba
#
# s = "高克丝马微中"
# print(jieba.lcut(s))    # >>['高克丝', '马微', '中']
# jieba.load_userdict("tmpdict.txt")
# print(jieba.lcut(s))    # >>['高克', '丝马', '微中']
# print(jieba.lcut("显微中，容不得一丝马虎"))    # >>['显微', '中', '，', '容不得', '一丝', '马虎']


# import jieba
#
# f = open("三国演义.txt", 'r', encoding="utf-8")
# text = f.read()
# f.close()
# words = jieba.lcut(text)
# result = {}
# for word in words:
#     if len(word) == 1:
#         continue
#     elif word in ("诸葛亮", "孔明曰"):
#         word = "孔明"
#     elif word in ("关公", "关云长", "云长"):
#         word = "关羽"
#     elif word in ("玄德", "玄德曰"):
#         word = "刘备"
#     elif word in ("孟德", "操贼", "曹阿瞒"):
#         word = "曹操"
#     result[word] = result.get(word, 0) + 1
# noneNames = {'将军', '却说', '荆州', '二人', '不可', '不能', '如此',
#              '丞相', '商议', '如何', '主公', '军士', '左右', '军马',
#              '引兵', '次日'}    # 用集合比列表快
# for word in noneNames:  # 删除noneNames中的词
#     result.pop(word)
# items = list(result.items())
# items.sort(key=lambda x: -x[1])     # 按出现次数降序
# for i in range(15):
#     print(items[i][0], items[i][1], end=',')    # 输出 人名 出现次数


# import openpyxl as pxl
#
# book = pxl.load_workbook("test.xlsx")   # book就是整个excel文件
# sheet = book.worksheets[0]      # 取第0张工作表
# print(sheet.title)              # 输出工作表名字（显示于工作表下方标签）
# print(sheet.min_row, sheet.max_row)     # 输出最小有效行号、最大有效行号（有效指非空）
# print(sheet.min_column, sheet.max_column)   # 输出最小有效列号、最大有效列号
# for row in sheet.rows:  # 按行遍历整个工作表，从第一行到sheet.max_row行（含）
#     for cell in row:    # 遍历一行的每个单元格。cell是一个单元格
#         print(cell.value, end=' ')   # cell.value是单元格的值。空单元格值是None
#     print('')
# for cell in sheet['G']:  # 遍历名为'G'的那一列
#     print(cell.value, end=' ')
# for cell in sheet[3]:   # 遍历第三行
#     print(cell.value, type(cell.value), cell.coordinate, cell.col_idx, cell.number_format)
#
#
# print(pxl.utils.get_column_letter(5))               # >>E 根据列号求列名
# print(pxl.utils.column_index_from_string('D'))      # >>4 根据列名求列号
# print(pxl.utils.column_index_from_string('AC'))     # >>29
#
# colRange = sheet['C:F']         # colRange代表从第C列到第F列（含F列）
# for col in colRange:            # 按列遍历第C列到第F列，col代表一列
#     for cell in col:            # cell是一个单元格
#         print(cell.value, end=' ')
#     print('')
# rowRange = sheet[5:10]          # rowRange代表第5行到第10行（含第10行）
# for row in sheet['A1':'D2']:    # 按行遍历 左上角是A1 右下角是D2 的子表
#     for cell in row:
#         print(cell.value, end=' ')
#     print('')
# print(sheet['C9'].value)        # 输出C9单元格的值
# print(sheet.cell(row=8, column=4).value)    # 输出第8行第4列单元格的值


# import openpyxl
# wb = openpyxl.load_workbook('style.xlsx', data_only=True)


# import openpyxl
# import datetime
#
# book = openpyxl.Workbook()  # 在内存中创建一个excel文档，注意W是大写
# sheet = book.active      # 取第 0个工作表
# sheet.title = "sample1"  # 工作表取名为 sample1
# dataRows = ((10, 20, 30, 40.5),
#             (100, 200, '=sum(A1:B2)'),
#             [],
#             ['1000', datetime.datetime.now(), 'ok'])
# for row in dataRows:
#     sheet.append(row)   # 在工作表中添加一行
# sheet.column_dimensions['B'].width = len(str(sheet['B4'].value))
# # 设置B列宽度，使其能完整显示B4单元格里的时间
# sheet['E1'].value = "=sum(A1:D1)"    # 单元格值为公式
# sheet['E2'].value = 12.5             # 单元格值为小数
# sheet["E2"].number_format = "0.00%"  # 单元格显示格式是百分比形式
# sheet['F1'].value = 3500             # 单元格值类型为int
# sheet['F2'].value = "35.00"          # 单元格值类型为str（不能做求和等操作）
# sheet['F3'].value = datetime.datetime.today().date()
# sheet.column_dimensions['F'].width = len(str(sheet['F3'].value))
# sheet.row_dimensions[2].height = 48  # 设置第2行高度为48points
# sheet2 = book.create_sheet("Sample2")  # 添加名为Sample2的工作表
# sheet2['A1'] = 50
# sheet2 = book.create_sheet("Sample0", 0)  # 添加名为Sample0的工作表
# sheet3 = book.copy_worksheet(sheet)       # 添加一张新工作表，为sheet的拷贝
# book.remove_sheet(book['Sample2'])        # 删除名为Sample2的工作表
# book.save('sample.xlsx')    # 保存文件


# import openpyxl as pxl
# book = pxl.load_workbook('sample.xlsx')
# for sheet in book.worksheets:
#     for row in sheet.rows:
#         for cell in row:
#             v = cell.value
#             if type(v) == str:
#                 if v.isdigit():     # 如果v全部由数字组成
#                     cell.value = int(v)
#                 else:
#                     try:
#                         cell.value = float(v)   # 如果不是小数格式，转换为引发异常
#                     except: pass
# book.save('excel1.xlsx')


# import openpyxl as pxl
#
# book = pxl.load_workbook('excel1.xlsx')
# for sheet in book:
#     for row in sheet.rows:
#         for cell in row:
#             if type(cell.value) == int or type(cell.value) == float:
#                 cell.value = str(cell.value)
# book.save('tmp/excel2.xlsx')

# import openpyxl as pxl
# from openpyxl.styles import Font, colors, PatternFill, Alignment, Side, Border
#
# book = pxl.Workbook()   # 在内存中创建一个excel文档，注意W是大写
# sheet = book.active     # 取第0个工作表
# for i in range(4):      # 添加4行5列数据
#     sheet.append([i*5 + j for j in range(5)])
# side = Side(style='thin')   # 边线类型，还可以是‘thick’，‘medium’，‘dotted'等
# border = Border(left=side, right=side, top=side, bottom=side)   # 边框类型
# for row in sheet.rows:
#     for cell in row:
#         cell.border = border    # 为单元格设置边框类型
# sheet['A1'].fill = PatternFill(patternType='solid', start_color="006600")   # 单元格底色设置为绿色
# a1 = sheet['A1']
# italicRedFont = Font(size=18, name='Times New Roman', bold=True, color="660000")
# color = "770000"
# a1.font = italicRedFont     # 设置单元格字体
# sheet['A2'].font = sheet['A1'].font.copy(italic=True)
# # A2的字体和A1的字体一样，但是是斜体
# sheet.merge_cells('C2:D3')  # 从C2到D3合并为一个单元格，此后名为C2
# sheet['C2'].alignment = Alignment(horizontal='left', vertical='center')
# # C2文字水平左对齐，垂直居中
# book.save("tmp/style.xlsx")

# from PIL import Image
#
# img = Image.open('tmp/balloons.jpg')    # 将图像文件载入对象img
# w, h = img.size     # 获取图像的宽和高（单位：像素），img.size是个元组
# newSize = (w//2, h//2)  # 生成一个新的图像尺寸
# newImg = img.resize(newSize)    # 得到一张原图像一半(bushi)大小的新图像
# newImg.save('tmp/balloons_half.jpg')    # 保存新图像文件
# newImg.thumbnail((128, 128))    # 变成宽高个128像素的缩略图
# newImg.save('tmp/balloons_thumb.png', "PNG")    # 保存为.png文件
# newImg.show()   # 显示图像


# from PIL import Image
# from PIL import ImageFilter     # 实现滤镜效果需要
#
# img = Image.open('tmp/balloons_half.jpg')
# print(img.format, img.mode)     # >>JPEG RGB
# newImg = img.rotate(90, expand=True)    # 图像逆时针旋转90度
# newImg.show()
# newImg = img.transpose(Image.FLIP_LEFT_RIGHT)   # 左右翻转
# newImg.show()
# newImg = img.transpose(Image.FLIP_TOP_BOTTOM)   # 上下翻转（颠倒）
# newImg.show()
# newImg = img.filter(ImageFilter.BLUR)   # 模糊效果
# newImg.show()


# from PIL import Image
#
# img = Image.open('tmp/balloons.jpg')
# w, h = img.size[0]//3, img.size[1]//3
# gap = 10        # 九宫图中相邻两幅子图间的空白宽10像素
# newImg = Image.new("RGB", (w*3 + gap*2, h*3 + gap*2), 'white')
# for i in range(0, 3):
#     for j in range(0, 3):
#         clipImg = img.crop((j*w, i*h, (j+1)*w, (i+1)*h))    # 四个参数为左上角和右下角的坐标
#         clipImg.save('tmp/balloons%d%d.jpg' % (i, j))
#         newImg.paste(clipImg, (j*(w+gap), i*(h+gap)))   # 往newImg上贴9张图
# newImg.save('tmp/balloons9.jpg')    # 保存九宫图
# newImg.show()


#
# from PIL import Image
# def makeSketch(img, threshold):
#     w, h = img.size
#     img = img.convert('L')      # 图像转换成灰度模式
#     pix = img.load()            # 获取像素矩阵
#     for x in range(w-1):
#         for y in range(h-1):
#             if abs(pix[x, y] - pix[x+1, y+1]) >= threshold:  # 相邻像素灰度差大于threshold，说明找到边界，将pix[x,y]变成黑色
#                 pix[x, y] = 0
#             else:
#                 pix[x, y] = 255     # 灰度值差距不大，全部变白
#     return img
#
# img = Image.open('tmp/balloons_half.jpg')
# img = makeSketch(img, 15)   # 阈值threshold为15
# img.show()


# from PIL import Image
#
# def getMask(img, isTransparent, alpha):  # img为水印图，isTransparent为判断透明度的函数，alpha为透明度
#     if img.mode != 'RGBA':
#         img = img.convert('RGBA')   # 转换成RGBA模式的图像
#         w, h = img.size
#         pixels = img.load()         # 获取像素矩阵
#         for x in range(w):
#             for y in range(h):
#                 p = pixels[x, y]    # p是一个四元元组(r,g,b,a)
#                 if(isTransparent(p[0], p[1], p[2])):    # 判断p是否应该变成透明像素
#                     # p[0], p[1], p[2] 分别是红绿蓝分量
#                     pixels[x, y] = (p[0], p[1], p[2], 0)
#                 else:
#                     pixels[x, y] = (p[0], p[1], p[2], alpha)
#     r, g, b, a = img.split()    # 分离出img中的四个分量，a就是掩膜
#     return a    # 返回由img变出来的掩膜
#
#
# img = Image.open('tmp/balloons01.jpg')  # 水印图片
# msk = getMask(img, lambda r, g, b: r > 245 and g > 245 and b > 245, 130)
# # lambda表达式说明接近白色的像素被判定成透明
# imgSrc = Image.open('tmp/balloons_half.jpg')
# imgSrc.paste(img, (imgSrc.size[0] - img.size[0] - 30,
#                    imgSrc.size[1] - img.size[1] - 30), mask=msk)
# # 水印位于imgSrc的右下角，用a做掩膜
# imgSrc.show()


# from PIL import Image, ImageDraw, ImageFont, ExifTags
#
# def correctOrientation(img):
# # 根据exif判断，img里的图像若有颠倒或旋转则生成一副将其摆正的图返回
#     if hasattr(img, "_getexif"):    # 判断img有没有_getexif函数
#         exif = img._getexif()       # 获取图像exif信息，返回值是个字典
#         if exif is not None:
#             orientation = exif[getExifKeyCode('Orientation')]
#             if orientation == 3:    # 手机顶部朝右拍
#                 img = img.rotate(180, expand=True)
#             elif orientation == 6:  # 手机正常竖着拍（顶部朝上）
#                 img = img.rotate(170, expand=True)
#             elif orientation == 8:  # 手机顶部朝下拍
#                 img = img.rotate(90, expand=True)
#     return img
#
# def getExifKeyCode(keyStr):     # 根据属性名称求字符串求属性代号
#     for x in ExifTags.TAGS.items():
#         if x[1] == keyStr:
#             return x[0]
#     return None
#
# def writeTextToImage(img, text, myFont):
#     # 在img中以字体myFont在右下角写入字符串text
#     # 会改变img中的图像
#     w, h = img.size
#     fw, fh = myFont.getsize(text)       # 求text显示出来的高度，宽度
#     draw = ImageDraw.Draw(img)          # 以后就可以通过draw在img上画图、写字
#     x, y = w - fw - 30, h - fh - 30     # 计算text的左上角的位置
#     draw.rectangle((x-5, y-5, x + fw + 5, y + fh + 5), outline='white')
#     draw.text((x, y), text, (255, 255, 255), font=myFont)


# import numpy as np
#
# print(np.array([1, 2, 3]))      # >>[1 2 3]
# print(np.arange(1, 9, 2))       # >>[1 3 5 7]
# print(np.linspace(1, 10, 4))    # >>[ 1.  4.  7. 10.]
# print(np.random.randint(10, 20, [2, 3]))    # [10,20) 2行3列
# # >>[[14 12 15]
# # >> [16 16 14]]
# print(np.random.randint(10, 20, 5))  # >>[19 10 15 12 13]
# a = np.zeros(3)
# print(a)        # >>[0. 0. 0.]
# print(list(a))  # >>[0.0, 0.0, 0.0]
# a = np.zeros((2, 3), dtype=int)  # 创建一个2行3列全为整数0的数组


# import numpy as np
#
# b = np.array([i for i in range(12)])
# # b是[ 0  1  2  3  4  5  6  7  8  9 10 11]
# a = b.reshape((3, 4))   # 转换成3行4列的数组，b不变
# print(len(a))   # >>3   a有3行
# print(a.size)   # >>12  a的元素个数是12
# print(a.ndim)   # >>2   a是2维的
# print(a.shape)  # >>(3, 4)  a是3行4列
# print(a.dtype)  # >>int32   a的元素类型是32位的整数
# L = a.tolist()  # 转换成列表，a不变
# print(L)
# # >>[[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11]]
# b = a.flatten()  # 转换成一维数组
# print(b)        # >>[ 0  1  2  3  4  5  6  7  8  9 10 11]


# import numpy as np
#
# a = np.array((1, 2, 3))  # a是[1 2 3]
# b = np.append(a, 10)    # a不变
# print(b)    # >>[ 1  2  3 10]
# print(np.append(a, [10, 20]))   # >>[ 1  2  3 10 20]
# c = np.zeros((2, 3,), dtype=int)    # c是2行3列全为0的数组
# print(np.append(a, c))  # >>[1 2 3 0 0 0 0 0 0]
# print(np.concatenate((a, [10, 20], a)))
# # >>[ 1  2  3 10 20  1  2  3]
# print(np.concatenate((c, np.array([[10, 20, 30]]))))  # c拼接一行[10, 20, 30]得到新数组
# # >>[[ 0  0  0]
# #  [ 0  0  0]
# #  [10 20 30]]
# print(np.concatenate((c, np.array([[1, 2], [10, 20]])), axis=1))    # axis=1表明拼接在列上，行数不变
# # c的第0行拼接了1, 2两个元素，第一行拼接了10, 20两个元素，得到新数组
# # >>[[ 0  0  0  1  2]
# #  [ 0  0  0 10 20]]

# import numpy as np
#
# a = np.array((1, 2, 3, 4))
# b = np.delete(a, 1)     # 删除a中下标为1的元素，a不变
# print(b)    # >>[1 3 4]
# b = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
# print(np.delete(b, 1, axis=0))  # 删除b的第一行得到的新数组
# # >>[[ 1  2  3  4]
# #  [ 9 10 11 12]]
# print(np.delete(b, 1, axis=1))  # 删除b的第一列得到的新数组
# # >>[[ 1  3  4]
# #  [ 5  7  8]
# #  [ 9 11 12]]
# print(np.delete(b, [1, 2], axis=0))  # 删除b的第1行和第2行得到的新数组
# # >>[[1 2 3 4]]
# print(np.delete(b, [1, 3], axis=1))  # 删除b的第1和3列得到的新数组
# # >>[[ 1  3]
# #  [ 5  7]
# #  [ 9 11]]


# import numpy as np
#
# a = np.array((1, 2, 3, 5, 3, 4))
# pos = np.argwhere(a == 3)   # pos是[[2] [4]]
# a = np.array([[1, 2, 3], [4, 5, 2]])
# print(2 in a)   # >>True
# pos = np.argwhere(a == 2)   # pos是[[0 1] [1 2]]
# b = a[a > 2]    # 抽取a中大于2的元素形成一个一维数组
# print(b)        # >>[3 4 5]
# a[a > 2] = -1   # 将a中大于2的元素改为-1

# import numpy as np
#
# a = np.array((1, 2, 3, 4))
# b = a + 1   # b的元素为a的每个元素加1
# print(b)        # >>[2 3 4 5]
# print(a * b)    # >>[ 2  6 12 20]
# print(a + b)    # >>[ 2  6 12 20]   a和b对应元素相加
# c = np.sqrt(a * 10)  # a*10是[10, 20, 30, 40]
# print(c)        # >>[3.16227766 4.47213595 5.47722558 6.32455532]


# import numpy as np
#
# a = np.arange(8)    # a是[0 1 2 3 4 5 6 7]
# b = a[3:6]          # b是a的一部分
# print(b)            # >>[3 4 5]
# c = np.copy(a[3:6])  # c是a的一部分的拷贝
# b[0] = 100          # 会修改a
# print(a)            # >>[  0   1   2 100   4   5   6   7]
# print(c)            # >>[3 4 5] c不受b影响
# a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
# b = a[1:3, 1:4]     # 行为[1,3), 列为[1, 4)
# # b是[[ 6  7  8]
# #     [10 11 12]]


# import pandas as pd
#
# s = pd.Series(data=[80, 90, 100], index=['语文', '数学', '英语'])  # data为元素，index为标签
# for x in s:         # >>80 90 100
#     print(x, end=' ')
# print("")
# print(s['语文'], s[1])    # >>80 90 标签和序号都可以作为下标来访问元素
# print(s[0:2]['数学'])     # >>90  s[0:2]是切片（视图）
# print(s['数学':'英语'][1])  # >>100  标签做切片为闭区间
# for i in range(len(s.index)):       # >>语文 数学 英语
#     print(s.index[i], end=' ')
# s['体育'] = 110       # 在尾部添加元素，标签为体育，值为110
# s.pop('数学')         # 删除标签为'数学'的元素
# s2 = s.append(pd.Series(120, index=['政治']))  # 不改变s
# print(s2['语文'], s2['政治'])   # >>80 120
# print(list(s2))     # >>[80, 100, 110, 120]
# print(s.sum(), s.min(), s.mean(), s.median())   # 总和、最小值、平均值、中位数
# # >>290 80 96.66666666666667 100.0
# print(s.idxmax(), s.argmax())   # >>体育 2  输出最大元素的标签和下标


# import pandas as pd
#
# # 构造
# pd.set_option('display.unicode.east_asian_width', True)
# # 输出对其方面的设置
# scores = [['男', 108, 115, 97], ['女', 115, 87, 105], ['女', 100, 60, 130],
#           ['男', 112, 80, 50]]
# names = ['刘一哥', '王二姐', '张三妹', '李四弟']
# courses = ['性别', '语文', '数学', '英语']
# df = pd.DataFrame(data=scores, index=names, columns=courses)    # 数据、行标签、列标签
# print(df)
#        性别  语文  数学  英语
# 刘一哥   男   108   115    97
# 王二姐   女   115    87   105
# 张三妹   女   100    60   130
# 李四弟   男   112    80    50
#
# # 访问
# print(df.values[0][1], type(df.values))  # >>108 <class 'numpy.ndarray'>
# print(list(df.index))       # >>['刘一哥', '王二姐', '张三妹', '李四弟']   （行标签）
# print(list(df.columns))     # >>['性别', '语文', '数学', '英语']    （列标签）
# print(df.index[2], df.columns[2])   # >>张三妹 数学
# s1 = df['语文']       # s1是个Series，代表’语文‘那一列
# print(s1['刘一哥'], s1[0])     # >>108 108     # 刘一哥语文成绩
# print(df['语文']['刘一哥'])     # >>108         # 列索引先写
# s2 = df.loc['王二姐']  # s2也是一个Series，代表’王二姐‘哪一行
# print(s2['性别'], s2['语文'], s2[2])
# # >>女 115 87    王二姐的性别、语文和数学分数
#
#
# df2 = df.iloc[1:3]      # 行切片，选1，2两行。 列切片省略说明全取
# df2 = df.loc['王二姐':'张三妹']  # 和上一行等价
# print(df2)
# #        性别  语文  数学  英语
# # 王二姐   女   115    87   105
# # 张三妹   女   100    60   130
#
# df3 = df.iloc[:, 0:3]   # 列切片，选0,1,2三列。 行切片省略说明全取
# df3 = df.loc[:, '性别':'数学']  # 和上一行等价
# print(df3)
# #        性别  语文  数学
# # 刘一哥   男   108   115
# # 王二姐   女   115    87
# # 张三妹   女   100    60
# # 李四弟   男   112    80
#
# df4 = df.iloc[:2, [1, 3]]   # 行列切片，取0，1行，1和3列
# df4 = df.loc[:'王二姐', ['语文', '英语']]  # 与上一行等价
# print(df4)
# #         语文  英语
# # 刘一哥   108    97
# # 王二姐   115   105
#
# df5 = df.iloc[[1, 3], 2:4]  # 1，3行；2,3列
# df5 = df.loc[['王二姐', '李四弟'], '数学':'英语']  # 与上一行等价
# print(df5)
# #         数学  英语
# # 王二姐    87   105
# # 李四弟    80    50


# print(df.T)     # df的转置矩阵
# #      刘一哥 王二姐 张三妹 李四弟
# # 性别     男     女     女     男
# # 语文    108    115    100    112
# # 数学    115     87     60     80
# # 英语     97    105    130     50
# print(df.sort_values('语文', ascending=False))    # 按语文成绩降序    不会改变原表格
# #        性别  语文  数学  英语
# # 王二姐   女   115    87   105
# # 李四弟   男   112    80    50
# # 刘一哥   男   108   115    97
# # 张三妹   女   100    60   130
# print(df.sum()['语文'], df.mean()['数学'], df.median()['英语'])
# # >>435 85.5 101.0      语文分数之和，数学平均分，英语中位数
# print(df.min()['语文'], df.max()['数学'])
# # >>100 115     语文最低分，数学最高分
# print(df.max(axis=1)['王二姐'])    # >>115   王二姐的最高分科目的分数
# print(df['语文'].idxmax())        # >>王二姐  语文最高分所在行的标签
# print(df['数学'].argmin())        # >>2      数学最低分所在行的行号
# print(df.loc[(df['语文'] > 100) & (df['数学'] >= 85)])  # 行选择器，选择语文成绩>100, 数学>=85的行。列选择器忽略
# #        性别  语文  数学  英语
# # 刘一哥   男   108   115    97
# # 王二姐   女   115    87   105

# 初始的df:
#        性别  语文  数学  英语
# 刘一哥   男   108   115    97
# 王二姐   女   115    87   105
# 张三妹   女   100    60   130
# 李四弟   男   112    80    50
# df.loc['王二姐', '英语'] = df.iloc[0, 1] = 150   # 修改王二姐英语和刘一哥语文成绩
# df['物理'] = [80, 70, 90, 100]        # 为所有人添加物理成绩这一列
# df.insert(1, '体育', [89, 77, 76, 45])    # 为所有人插入体育成绩到第一列
# df.loc['李四弟'] = ['男', 100, 100, 100, 100, 100]  # 修改李四弟全部信息
# df.loc[:, '语文'] = [20, 20, 20, 20]      # 修改所有人语文成绩
# df.loc['钱五叔'] = ['男', 100, 100, 100, 100, 100]  # 加一行
# df.loc[:, '英语'] += 10           # 为所有人英语加10分
# df.columns = ['性别', '体育', '语文', '数学', 'English', '物理']  # 改列标签
# print(df)
# #        性别  体育  语文  数学  English  物理
# # 刘一哥   男    89    20   115      107    80
# # 王二姐   女    77    20    87      160    70
# # 张三妹   女    76    20    60      140    90
# # 李四弟   男   100    20   100      110   100
# # 钱五叔   男   100   100   100      110   100
#
#
# # 删除
# df.drop(['体育', '物理'], axis=1, inplace=True)  # 删除体育和物理成绩
# df.drop('王二姐', axis=0, inplace=True)        # 删除王二姐那一行
# print(df)
# #        性别  语文  数学  English
# # 刘一哥   男    20   115      107
# # 张三妹   女    20    60      140
# # 李四弟   男    20   100      110
# # 钱五叔   男   100   100      110
# df.drop([df.index[i] for i in range(1, 3)], axis=0, inplace=True)   # 删除1,2行
# df.drop([df.columns[i] for i in range(3)], axis=1, inplace=True)    # 删除0到2列
# print(df)
# #         English
# # 刘一哥      107
# # 钱五叔      110
# import pandas as pd
#
# pd.set_option('display.unicode.east_asian_width', True)
# dt = pd.read_excel("tmp/excel_sample.xlsx", sheet_name=['销售情况', 1], index_col=0)
# # 读取第0张和第一张工作表。index_col=0表示将第0列作为行标签。dt为字典，两个元素都是DataFrame对象
# df = dt['销售情况']     # dt是字典，df是DataFrame
# print(df.iloc[0, 0], df.loc['睡袋', '数量'])    # >>12124 12124
# print(df)
# #            数量   销售额   成本      利润
# # 产品类别
# # 睡袋      12124  4323.54     54   6666.00
# # 彩盒        234   123.99  54353   4444.00
# # 宠物用品    234  1233.67    234   3333.24
# # 警告标     1234   885.78    234   2222.99
# # 总计      13826  6566.98  54875  16666.23
# print(pd.isnull(df.loc['彩盒', '销售额']))   # >>False
# df.fillna(0, inplace=True)      # 将所有NaN替换为0
# print(df.loc['彩盒', '销售额'], df.iloc[2, 2])   # >>123.99 234
#
#
# writer = pd.ExcelWriter("new.xlsx")     # 创建ExcelWriter对象
# df.to_excel(writer, sheet_name="S1")
# df.T.to_excel(writer, sheet_name="S2")  # 转置矩阵写入
# df.sort_values('销售额', ascending=False).to_excel(writer, sheet_name="S3")
# # 按销售额排序的新DataFrame写入工作表S3
# df['销售额'].to_excel(writer, sheet_name="S4")  # 只写入一列
# writer.save()

# df.to_csv("result.csv", sep=',', na_rep='NA', float_format="%.2f", encoding='gbk')
# # ','分隔，未定义的各自用‘NA', 小数保留小数点后两位，gbk编码
#
# df = pd.read_csv("result.csv")


# import matplotlib.pyplot as plt
# from matplotlib import rcParams
#
# rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'
# # 设置中文支持，中文字体为简体黑体
# ax = plt.figure().add_subplot()     # 建图，获取子图对象
# ax.barh(y=(0.2, 0.6, 0.8, 1.2), width=(1, 2, 3, 0.5), height=0.1)
# # x表示4个柱子中心横坐标分别是0.2， 0.6， 0.8， 1
# # height表示4个柱子高度分别是1，2，3，0.5
# # width表示柱子宽度0.1
# ax.set_title('我的直方图')
# plt.show()

#
# import matplotlib.pyplot as plt
#
# ax = plt.figure().add_subplot()
# labels = ['Jan', 'Feb', 'Mar', 'Apr']
# num1 = [20, 30, 15, 35]     # Dept1的数据
# num2 = [15, 30, 40, 20]     # Dept2的数据
# cordx = range(len(num1))    # x轴刻度位置
# rects1 = ax.bar(x=cordx, height=num1, width=0.5, color='red', label="Dept1")
# rects2 = ax.bar(x=cordx, height=num2, width=0.5, color='green', label="Dept2", bottom=num1)
# ax.set_ylim(0, 100)         # y轴坐标范围
# ax.set_ylabel("Profit")     # y轴含义
# ax.set_xticks(cordx)        # 设置x轴刻度位置
# ax.set_xticklabels(labels)  # 设置x轴刻度下方文字
# ax.set_xlabel("In year 2020")   # x轴标签
# ax.set_title("My Company")
# ax.legend()     # 在右上角显示图例说明
# plt.show()

# import matplotlib.pyplot as plt
#
# ax = plt.figure(figsize=(10, 5)).add_subplot()
# ax.set_ylim(0, 400)     # y轴坐标范围
# ax.set_xlim(0, 80)      # x轴坐标范围
# # 以下是3组直方图的数据
# x1 = [7, 17, 27, 37, 47, 57]    # 第一组直方图每个柱子中心点的横坐标
# x2 = [13, 23, 33, 43, 53, 63]   # 第二组直方图每个柱子中心点的横坐标
# x3 = [10, 20, 30, 40, 50, 60]
# y1 = [41, 39, 13, 69, 39, 14]   # 第一组直方图每个柱子的高度
# y2 = [123, 15, 20, 105, 79, 37]
# y3 = [124, 91, 204, 264, 221, 175]
# rects1 = ax.bar(x1, y1, facecolor='red', width=3, label='Iphone')
# rects2 = ax.bar(x2, y2, facecolor='green', width=3, label='Huawei')
# rects3 = ax.bar(x3, y3, facecolor='blue', width=3, label='Xiaomi')
# ax.set_xticks(x3)   # x轴在x3中的个坐标点下面加刻度
# ax.set_xticklabels(('A1', 'A2', 'A3', 'A4', 'A5', 'A6'))
# # 指定x轴每一刻度下方的文字
# ax.legend()     # 显示右上角三组图的标注
#
# def label(ax, rects):   # 该函数在rects每个柱子顶端标注数字
#     for rect in rects:
#         height = rect.get_height()
#         ax.text(rect.get_x() - 0.05 + rect.get_width()/2.0,
#                 height + 34, str(height), rotation=90)  # 文字旋转90度
#
# label(ax, rects1)
# label(ax, rects2)
# label(ax, rects3)
# plt.show()


# import math
# import random
#
# import matplotlib.pyplot as plt
#
#
# def drawPlot(ax):
#     xs = [i / 100 for i in range(1500)]  # 1500个点的横坐标，间隔0.01
#     ys = [10 * math.sin(x) for x in xs]  # 对应曲线y=10*sin(x)上的1500个点的纵坐标
#     ax.plot(xs, ys, "red", label="Beijing")  # 画曲线y=10*sin(x)
#
#     ys = list(range(-18, 18))
#     random.shuffle(ys)  # 随机打乱y坐标
#     ax.scatter(range(16), ys[:16], c='blue')  # 画散点，横坐标为[0,15], 纵坐标为ys的前 16个元素
#
#     ax.plot(range(16), ys[:16], 'blue', label="Shanghai")  # 画折线
#     ax.legend()  # 显示右上角的各条折线标注,右上角位置不够python自动调整到左下
#     ax.set_xticks(range(16))  # x轴在坐标0, 1...15处加刻度
#     ax.set_xticklabels(range(16))  # 指定x轴每个刻度下方显示的文字
#
#
# ax = plt.figure(figsize=(10, 4), dpi=100).add_subplot()  # 图像长宽和清晰度
# drawPlot(ax)
# plt.show()


# import matplotlib.pyplot as plt
#
# def drawPie(ax):
#     lbs = ('A', 'B', 'C', 'D')          # 四个扇区的标签
#     sectors = [16, 29.55, 44.45, 10]    # 四个扇区的份额（百分比）
#     expl = [0, 0.1, 0, 0]               # 四个扇区的突出程度（0.1表示半径的0.1倍）
#     ax.pie(x=sectors, labels=lbs, explode=expl,
#            autopct='%.2f', shadow=True, labeldistance=1.1,  # labeldistance表示外部标注距离圆心的距离(半径的倍数）
#            pctdistance=0.6, startangle=90)
#     # pctdistande表示每小块中间的标注距离圆心的距离；startangle表示饼图从90度开始画
#     ax.set_title("pie sample")
#
# ax = plt.figure().add_subplot()
# drawPie(ax)
# plt.show()


# import numpy as np
# from matplotlib import pyplot as plt
#
# data = np.random.randint(0, 100, 30).reshape(5, 6)
# # 生成一个五行六列，元素[0,100]内的随机矩阵
# xlabels = ['Beijing', 'Shanghai', 'Chengdu', 'Guangzhou', 'Hangzhou', 'Wuhan']
# ylabels = ['2016', '2017', '2018', '2019', '2020']
# ax = plt.figure(figsize=(10, 8)).add_subplot()
# ax.set_yticks(range(len(ylabels)))  # y轴在坐标[0, len(ylabels))处夏克苏
# ax.set_yticklabels(ylabels)     # 设置y轴刻度文字
# ax.set_xticks(range(len(xlabels)))
# ax.set_xticklabels(xlabels)
# heatMp = ax.imshow(data, cmap=plt.cm.hot, aspect='auto', vmin=0, vmax=100)
# # 最小值vmin为黑色，最大值vmax为白色
#
# for i in range(len(xlabels)):   # 在每个格子上写文字
#     for j in range(len(ylabels)):
#         ax.text(i, j, data[j][i], ha='center', va='center',  # ha、va:水平、竖直对齐方式
#                 color='blue', size=26)
#
# plt.colorbar(heatMp)        # 绘制右边的颜色-数值对照柱
# plt.xticks(rotation=45, ha='right')     # 将x轴刻度文字旋转，水平方向右对齐
# plt.title("Sales Volumn(ton)")
# plt.show()


# import matplotlib.pyplot as plt
# from matplotlib import rcParams     # 处理汉字的库

# def drawRadar(ax):
#     pi = 3.1415926
#     labels = ['EQ', 'IQ', '人缘', '魅力', '财富', '体力']   # 六个属性的名称
#     attrNum = len(labels)       # attrNum是属性种类数，此处等于6
#     data = [7, 6, 8, 9, 8, 2]   # 六个属性的值
#     angles = [2*pi*i/attrNum for i in range(attrNum)]
#     # angles是以弧度为单位的6个属性对应的6条半径线的角度（平均分6份）
#     angles2 = [x*180/pi for x in angles]    # 弧度转角度
#     # angles2是以角度为单位的6个属性对应的半径线的角度
#     ax.set_ylim(0, 10)  # 限定半径线上的坐标范围
#     ax.set_thetagrids(angles2, labels, fontproperties='SimHei')
#     # 绘制六个属性对应的六条半径
#     ax.fill(angles, data, facecolor='g', alpha=0.25)    # 填充。alpha为透明度
#
# rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'    # 处理汉字
# ax = plt.figure().add_subplot(projection='polar')   # 生成极坐标形式的子图
# drawRadar(ax)
# plt.show()


# import matplotlib.pyplot as plt
# from matplotlib import rcParams
#
# rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'
# pi = 3.1415926
# labels = ['EQ', 'IQ', '人缘', '魅力', '财富', '体力']   # 六个属性的名称
# attrNum = len(labels)
# names = ('张三', '李四', '王五')
# data = [[0.40, 0.32, 0.35], [0.85, 0.35, 0.30],
#         [0.40, 0.32, 0.35], [0.40, 0.82, 0.75],
#         [0.14, 0.12, 0.35], [0.80, 0.92, 0.35]]     # 三个人的数据
# angles = [2*pi*i/attrNum for i in range(attrNum)]
# angles2 = [x * 180/pi for x in angles]
# ax = plt.figure().add_subplot(projection='polar')
# ax.fill(angles, data, alpha=0.25)
# ax.set_thetagrids(angles2, labels)
# ax.set_title('三巨头人格分析', y=1.05)     # y指明标题垂直位置（高出半径0.05倍）
# ax.legend(names, loc=(0.95, 0.9))       # 画出右上角不同人的颜色说明
# plt.show()

# import matplotlib.pyplot as plt
# from matplotlib import rcParams

# import以及drawRadar, drawPie,drawPlot函数略
# fig = plt.figure(figsize=(8, 8))
# ax = fig.add_subplot(2, 2, 1)       # 窗口分割成 2 * 2, 取位于第一个方格的子图
# drawPie(ax)
# ax = fig.add_subplot(2, 2, 2, projection='polar')
# drawRadar(ax)
# ax = plt.subplot2grid((2, 2), (1, 0), colspan=2)
# drawPlot(ax)
# plt.figtext(0.05, 0.05, 'subplot sample')   # 显示左下角的图像标题
# plt.show()


# import re
# import requests     # requests库用于获取网络资源
#
# def getHtml(url):   # 获取网址为url的网页
#     # import requests
#     fakeHeaders = {'User-Agent':
#                    'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'
#                    'AppleWebKit/537.36 (KHTML, like Gecko)'
#                    'Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77',
#                    'Accept': 'text/html, application/xhtml+xml,*/*'}
#     # 用于伪装浏览器发送请求
#     try:
#         r = requests.get(url, headers=fakeHeaders)
#         r.encoding = r.apparent_encoding    # 确保网页编码正确
#         return r.text   # 返回值是字符串，包含整个网页内容
#     except Exception as e:
#         print(e)
#         return ""
#
# def getBingPictures(word, n):  # 下载 n张 bing图片搜来的关于word的图片保存到本地
#     url = "https://cn.bing.com/images/search?q="
#     url += word
#     html = getHtml(url)
#     pt = 'src=\"(.*?pid=1.7)\"'    # 正则表达式，用于寻找图片网址
#     i = 0   # 记录已经取到的图片数
#     for x in re.findall(pt, html):
#         try:    # 通过url获取图片
#             print(x)
#             r = requests.get(x, stream=True)    # 获取x对应的网络资源
#             f = open('tmp/{0}{1}.jpg'.format(word, i), "wb")    # 二进制写
#             f.write(r.content)
#             f.close()
#         except Exception as e:
#             pass
#         i += 1
#         if i >= n:
#             break

# getBingPictures('熊猫', 5)
# url = "https://cn.bing.com/images/search?q=熊猫"
# html = getHtml(url)
# pt = 'src=\"(.*?)\"'
# print(re.findall(pt, html))
# import sys


# # def getHtml(url):   # 获取网址为url的网页
# #     import requests
#     import chardet  # 编码处理库
# #     fakeHeaders = {'User-Agent':
# #                    'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'
# #                    'AppleWebKit/537.36 (KHTML, like Gecko)'
# #                    'Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77'}
# #     # 用于伪装浏览器发送请求
# #     try:
#         r = requests.get(url, headers=fakeHeaders)
#         ecd = chardet.detect(r.content)['encoding']  # ecd是个字符串
#         if ecd.lower() != sys.getdefaultencoding().lower()
#             r.encoding = ecd        # 修改r中文本的编码
#         else:
#             r.encoding = r.apparent_encoding
#         return r.text   # 返回值是字符串，包含整个网页内容
#     # except Exception as e:
#     #     print(e)
#     #     return ""


# class rectangle:
#     def __init__(self, w, h):   # 成员变量只需要写在构造函数里
#         self.w, self.h = w, h
#
#     def area(self):     # 面积
#         return self.h * self.w
#
#     def perimeter(self):    # 周长
#         return 2 * (self.w + self.h)
#
#
# def main():
#     w, h = map(int, input().split())    # 假设输入2, 3
#     rect = rectangle(w, h)      # 生成一个rectangle对象
#     print(rect.area(), rect.perimeter())    # >>6 10
#     rect.w, rect.h = 10, 20
#     print(rect.area(), rect.perimeter())    # >>200 60
#     rect2 = rectangle(2, 3)
#     print(rect2.area(), rect2.perimeter())  # >>6 10
#
# main()

#
# class point:
#     def __init__(self, x, y = 0):
#         self.x, self.y = x, y
#
#     def __eq__(self, other):
#         return self.x == other.x and self.y == other.y
#
#     def __lt__(self, other):    # 使两个对象可以用<比较
#         if self.x == other.x:
#             return self.y < other.y
#         else:
#             return self.x < other.x
#
#
#
# a, b = point(1, 2), point(1, 2)
# print(a == b)   # >>True
# print(a != b)   # >>False
# print(a < point(0, 1))  # >>False
# print(a < point(1, 3))  # >>True
# lst = [a, point(-2, 3), point(7, 8), point(5, 9), point(5, 0)]
# lst.sort()  # 默认用__lt__排序
# for p in lst:
#     print(p.x, p.y, end=', ')   # >> -2 3, 1 2, 5 0, 5 9, 7 8,


# class point:
#     def __init__(self, x, y):
#         self.x, self.y = x, y
#
#     def __str__(self):
#         return "(%d, %d)" % (self.x, self.y)
#
# print(point(3, 5))          # >>(3, 5)
# print(str(point(2, 4)))     # >>(2, 4)


# import datetime
#
# class student:
#     def __init__(self, id, name, gender, birthYear):
#         self.id, self.name, self.gender, self.birthYear = \
#             id, name, gender, birthYear
#
#     def printInfo(self):
#         print("Name: ", self.name)
#         print("ID: ", self.id)
#         print("Birth Year: ", self.birthYear)
#         print("Gender: ", self.gender)
#         print("Age: ", self.countAge())
#
#     def countAge(self):
#         return datetime.datetime.now().year - self.birthYear
#
#
# class undergraduateStudent(student):    # 本科生类，继承student类
#     def __init__(self, id, name, gender, birthYear, department):
#         student.__init__(self, id, name, gender, birthYear)
#         self.department = department
#
#     def qualifiedForBaoyan(self):   # 给予保研资格
#         print("Qualified for baoyan")
#
#     def printInfo(self):
#         student.printInfo(self)     # 调用基类的同名方法
#         print("Department: ", self.department)
#
# def main():
#     s2 = undergraduateStudent("118829212", "Harry Potter", "M", 2000, "Computer Science")
#     s2.printInfo()
#     s2.qualifiedForBaoyan()
#     if s2.countAge() > 18:
#         print(s2.name, "is older than 18")
#
# main()
# # Name:  Harry Potter
# # ID:  118829212
# # Birth Year:  2000
# # Gender:  M
# # Age:  22
# # Department:  Computer Science
# # Qualified for baoyan
# # Harry Potter is older than 18


# class A:
#     def func(x):
#         pass
#
# print(dir(A))   # 输出A的所有成员函数


# class employee:
#     totalSalary = 0     # 静态属性，记录发给员工的工资总数
#     def __init__(self, name, income):
#         self.name, self.income = name, income
#
#     def pay(self, salary):
#         self.income += salary
#         employee.totalSalary += salary
#
#     @staticmethod
#     def printTotalSalary():     # 静态方法
#         print(employee.totalSalary)
#
#
# e1 = employee("Jack", 0)
# e2 = employee("Tom", 0)
# e1.pay(100)
# e2.pay(200)
# employee.printTotalSalary()     # >>300
# e1.printTotalSalary()           # >>300
# e2.printTotalSalary()           # >>300
# print(employee.totalSalary)     # >>300


# x = 23.1
# print(x.__hash__(), 23.1.__hash__())
# # >>230584300921372695 230584300921372695
# x = 23
# print(x.__hash__(), hash(23))   # >>23 23
# x = (1, 2)
# print(x.__hash__(), (1, 2).__hash__(), hash(x))
# # >> -3550055125485641917 -3550055125485641917 -3550055125485641917
# x = 'ok'
# print(x.__hash__(), "ok".__hash__())
# # >> -7124967159215549686 -7124967159215549686

# class A:
#     def __init__(self, x):
#         self.x = x
#
#
# a, b = A(5), A(5)       # a,b为两个不同的对象，因此id不同
# dt = {a: 20, A(5): 30, b: 40}   # 三个元素的键id不同，因此在不同槽里
# print(len(dt), dt[a], dt[b])    # >>3 20 40
# print(dt[A(5)])     # runtime error

# class A:
#     def __init__(self, x):
#         self.x = x
#
#     def __hash__(self):
#         return hash(self.x)
#
#     def __eq__(self, other):
#         if isinstance(other, A):    # 判断other是否是类A的对象
#             return self.x == other.x    # 成员变量是否相同， hash值就相同
#         elif isinstance(other, int):    # 如果other是整数
#             return self.x == other
#         else:
#             return False
#
# a = A(3)
# print(3 == a)       # >>True
# b = A(3)
# d = {A(5): 10, A(3): 20, a: 30}
# print(len(d), d[a], d[b], d[3])     # >>2 30 30 30
# c = A(1)
# dt = {A(1): 2, A(1): 3, c: 4}
# # 三个元素哈希值相同，但id不同，因此在同一个槽内
# print(len(dt))  # >>3
# for a in dt.items():
#     print(a[0].x, a[1], end=", ")   # >>1 2, 1 3, 1 4,
# print(dt[c])    # >>4


# import tkinter as tk
#
# win = tk.Tk()       # 生成一个窗口
# tk.Label(win)    # 在窗口win上生成一个Label，该Label的母体是win
# ckb = tk.Checkbutton(win)    # 在窗口上生成一个Checkbutton
# frm = tk.Frame(win)      # 在窗口上生成一个Frame
# bt = tk.Button(frm)      # 在frm上生成一个Button
#
# win.mainloop()


# import tkinter as tk
#
# win = tk.Tk()       # 创建窗口
# win.title("Hello")  # 指定窗口标题
# label1 = tk.Label(win, text='用户名：')  # 创建属于win上的图文标签控件
# label2 = tk.Label(win, text='密码：')
# etUsername = tk.Entry(win)      # 创建属于win的单行编辑框控件，用于输入用户名
# etPassword = tk.Entry(win)      # 创建密码编辑框
# label1.grid(row=0, column=0, padx=5, pady=5)    # label1放在第0行第0列，上下左右都留白5像素
# label2.grid(row=1, column=0, padx=5, pady=5)    # 第1行第0列
# etUsername.grid(row=0, column=1, padx=5, pady=5)    # 用户名输入框放在第0行第1列
# etPassword.grid(row=1, column=1, padx=5, pady=5)    # 密码输入框放在第1行第1列
# btLogin = tk.Button(win, text='登录')     # 创建属于win的按钮控件
# btLogin.grid(row=2, column=0, columnspan=2, padx=5, pady=5)     # btLogin在第2行第0列，跨两列
# # win.geometry("800x500+200+100")
# win.columnconfigure(0, weight=1)    # 指定第0列增量分配权重为1
# win.columnconfigure(1, weight=1)    # 指定第1列增量分配权重为1
# win.rowconfigure(0, weight=1)       # 指定第0行权重为1
# win.rowconfigure(1, weight=1)
# win.rowconfigure(2, weight=1)
#
# label2.grid(row=1, column=0, padx=5, pady=5, sticky="NE")   # 东北，即贴着右上角
# etUsername.grid(row=0, column=1, padx=5, pady=5, sticky="E")    # 靠右
# etPassword.grid(row=1, column=1, padx=5, pady=5, sticky="EWSN")  # 占满单元格
# btLogin.grid(row=2, column=0, columnspan=2, padx=5, pady=5, sticky="SW")  # 西南，即左下角
#
# win.mainloop()      # 显示窗口


# import tkinter as tk
#
# win = tk.Tk()

# s = tk.StringVar()
# s.set("sin(x)")
# tk.Entry(win, textvariable=s)
# print(s.get())

# tk.Button(win, text='显示函数图', command=myfunc)    # myfunc是函数名
# tk.Checkbutton(win, text='显示函数图', command=lambda:print('hello'))

# lb = tk.Label(win, text='something')
# lb.bind("<ButtonPress-1>", mouse_down)  # 鼠标左键按下事件


import re

import bs4
import requests


# def getHtml(url):  # 暂时适用于百度图片搜索
#
#     import asyncio  # Python 3.6之后自带的协程库
#     import pyppeteer as pyp
#
#     async def asGetHtml(url):  # 获取url对应网页的源代码
#
#         browser = await pyp.launch(headless=False)
#         # 启动Chromium,browser即为Chromium浏览器，非隐藏启动（表示能看见浏览器）
#         # 没有chromium会自动下载
#
#         page = await browser.newPage()  # 在浏览器中打开一个新页面（标签）
#         await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; \
#                                 Win64; \
#                                 x64) AppleWebKit/537.36 (KHTML, \
#                                 like Gecko) \
#                                 Chrome/78.0.3904.70 Safari/537.36')  # 反反爬措施
#         await page.evaluateOnNewDocument(
#             '() =>{ Object.defineProperties(navigator, '
#             '{ webdriver:{ get: () => false } }) }')  # 反反爬措施
#
#         await page.goto(url)  # 装入url对应的网页
#         text = await page.content()  # page.content就是网页源代码字符串
#         await browser.close()  # 关闭浏览器
#         return text
#         # 速度大约比用requests.get慢5,6倍
#
#     m = asyncio.ensure_future(asGetHtml(url))  # 协程外启动协程
#     asyncio.get_event_loop().run_until_complete(m)  # 等待协程结束
#     return m.result()  # 返回的就是asGetHtml的返回值 text
#
#
# def getBingPictures(word, n):  # 下载 n张 bing图片搜来的关于word的图片保存到本地
#     url = "https://cn.bing.com/images/search?q="
#     url += word
#     html = getHtml(url)
#     pt = 'src=\"(https://.*?pid=1.7)\"'  # 正则表达式，用于寻找图片网址
#     i = 0  # 记录已经取到的图片数
#     for x in re.findall(pt, html):
#         try:  # 通过url获取图片
#             print(x)
#             r = requests.get(x, stream=True)  # 获取x对应的网络资源
#             f = open('tmp/{0}{1}.jpg'.format(word, i), "wb")  # 二进制写
#             f.write(r.content)
#             f.close()
#         except Exception as e:
#             pass
#         i += 1
#         if i >= n:
#             break
#
#
# getBingPictures('熊猫', 5)


# import bs4
#
# string = '''
#     <div id="siteHeader" class="wrapper">
#         <h1 class="logo">
#         <div id="topsearch">
#             <ul id="userMenu">
#             <li ><a href="http://openjudge.cn/">首页</a></li>
#         </div>
#     </div>
# '''
# # 带href的 <a>都是链接，上面“首页”是链接文字 ,href后面http://openjudge.cn是链接地址
#
# soup = bs4.BeautifulSoup(string, "html.parser")
# print(soup.find("li").text)  # >>首页

# import bs4
#
# soup = bs4.BeautifulSoup(
#     open("tmp\\Homepage.html", 'r', encoding='utf-8'),
#     "html.parser")

# import requests
# import re
#
# def getHtml(url):   # 获得 html文本
#     try:
#         r = requests.get(url)
#         r.raise_for_status()
#         r.encoding = r.apparent_encoding
#         return r.text
#     except:
#         return ""
#
# html = getHtml("https://cn.bing.com/dict/search?q=new")
# soup = bs4.BeautifulSoup(html, 'html.parser')


# import bs4
#
# soup = bs4.BeautifulSoup(open("tmp/test.html",
#                               encoding="utf-8"), "html.parser")
# diva = soup.find("div", attrs={"id": "synoid"})
# # 寻找名为"div"，且具有 值为"synoid"的属性"id"的tag
# if diva is not None:  # 如果找到
#     for x in diva.find_all("span", attrs={"class": "p1-4"}):
#         print(x.text)  # 在diva内部继续找
# for x in diva.find_all("a", attrs={"id": "searchlink1"}):
#         print(x.text)
# x = diva.find("a", attrs={"id": "searchlink1", "class": "sh2"})
# if x is not None:
#     print(x.text)
#     print(x["href"])
#     print(x["id"])
# lst = input().split()
# print(lst[1])

# lst = input().split()
# a, b, c = int(lst[0]), int(lst[1]), int(lst[2])
# print((a+b)*c)

# import asyncio
# import pyppeteer as pyp
#
#
# async def antiAntiCrawler(page):  # 为page添加反反爬虫手段
#     await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; Win64; x64) \ '
#                             'AppleWebKit/537.36 (KHTML, like Gecko) '
#                             'Chrome/78.0.3904.70 Safari/537.36')
#     await page.evaluateOnNewDocument(
#         '() =>{ Object.defineProperties(navigator,'
#         '{ webdriver:{ get: () => false } }) }')
#
#
# async def getOjSourceCode(loginUrl):
#     width, height = 1400, 800  # 网页宽高
#     browser = await pyp.launch(headless=False,
#                                userdataDir="c:/tmp",
#                                args=[f'--window-size={width},{height}'])
#     page = await browser.newPage()
#     await antiAntiCrawler(page)
#     await page.setViewport({'width': width, 'height': height})
#     await page.goto(loginUrl)
#
#     # 登录 （若手动登录，则以下若干行可以去掉）
#     element = await page.querySelector("#email")  # 找到账户输入框
#     await element.type("1822011278@qq.com")  # 输入邮箱
#     element = await page.querySelector("#password")  # 找到密码输入框
#     await element.type("Zg115588")  # 输入密码
#     element = await page.querySelector("#main > form > div.user-login >"
#                                        "p:nth-child(2) > button")  # 找到登录按钮
#     await element.click()  # 点击登录按钮
#     # 若手动登录，则以上若干行可以去掉
#
#     # 点击登录按钮后要等待操作完成才能继续往下操作（time.sleep(10)）
#     await page.waitForSelector("#main>h2",
#                                timeout=30000)  # 等待“正在进行的比赛...."标题出现，最多等30秒
#
#     element = await page.querySelector("#userMenu>li:nth-child(2)>a")
#     # 找"个人首页”链接
#     await element.click()  # 点击个人首页链接
#     await page.waitForNavigation()  # 等新网页装入完毕
#     elements = await page.querySelectorAll(".result-right")
#     # 找所有"Accepted"链接, 其有属性 class="result-right"
#
#     page2 = await browser.newPage()  # 新开一个页面 (标签)
#     await antiAntiCrawler(page2)  # 反反爬
#     for element in elements[:2]:  # 只打印前两个程序
#         obj = await element.getProperty("href")  # 获取href属性
#         url = await obj.jsonValue()
#         await page2.goto(url)  # 在新页面(标签)中装入新网页
#         element = await page2.querySelector("pre")  # 查找pre tag
#         obj = await element.getProperty("innerText")  # 取源代码
#         text = await obj.jsonValue()  # 转为字符串
#         print(text)
#         print("-------------------------")
#     await browser.close()
#
#
# def main():
#     url = "http://openjudge.cn/auth/login/"
#     asyncio.get_event_loop().run_until_complete(getOjSourceCode(url))
#
#
# main()


# import asyncio
# import pyppeteer as pyp
# import bs4
# import requests
#
#
# def sessionGetHtml(session, url):  # 发送带session的网页请求,获取网页源码
#     fakeHeaders = {
#         'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
#     AppleWebKit/537.36 (KHTML, like Gecko) \
#     Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77'
#     }  # 伪装浏览器用的请求头
#     try:
#         result = session.get(url, headers=fakeHeaders)
#         result.encoding = result.apparent_encoding
#         return result.text
#     except Exception as e:
#         print(e)
#         return ""
#
#
# async def makeSession(page):
#     # 返回一个session,将其内部cookies修改成pypeteer浏览器页面对象中的cookies
#     cookies = await page.cookies()  # cookies是一个列表，每个元素都是一个字典
#     cookies1 = {}
#     for cookie in cookies:  # requests中的cookies只要 "name"属性
#         cookies1[cookie['name']] = cookie['value']
#     session = requests.Session()
#     session.cookies.update(cookies1)
#     return session
#
#
# async def antiAntiCrawler(page):
#     # 为page添加反反爬虫手段
#     await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; Win64; x64) \ '
#                             'AppleWebKit/537.36 (KHTML, like Gecko) '
#                             'Chrome/78.0.3904.70 Safari/537.36')
#     await page.evaluateOnNewDocument(
#         '() =>{ Object.defineProperties(navigator,'
#         '{ webdriver:{ get: () => false } }) }')
#
#
# async def getOjSourceCode(loginUrl):
#     width, height = 1400, 800  # 网页宽高
#     browser = await pyp.launch(headless=False,
#                                userdataDir="c:/tmp",
#                                args=[f'--window-size={width},{height}'])
#     page = await browser.newPage()
#     await antiAntiCrawler(page)
#     await page.setViewport({'width': width, 'height': height})
#     await page.goto(loginUrl)
#
#     await page.waitForSelector("#main>h2",
#                                timeout=30000)  # 等待手动登录后，“正在进行的比赛...."标题出现
#
#     element = await page.querySelector("#userMenu>li:nth-child(2)>a")
#     # 找"个人首页”链接
#     await element.click()  # 点击个人首页链接
#     await page.waitForNavigation()  # 等新网页装入完毕
#
#     elements = await page.querySelectorAll(".result-right")
#     # 找所有"Accepted"链接, 其有属性 class="result-right"
#
#     session = await makeSession(page)   # 由page创造一个session,以后向服务器发送请求都通过session进行
#     for element in elements[:2]:
#         obj = await element.getProperty("href")
#         url = await obj.jsonValue()
#         html = sessionGetHtml(session, url)
#         soup = bs4.BeautifulSoup(html, "html.parser")
#         element = soup.find("pre")
#         print(element.text)
#         print("-------------------------")
#     await browser.close()
#
#
# def main():
#     url = "http://openjudge.cn/auth/login/"
#     asyncio.get_event_loop().run_until_complete(getOjSourceCode(url))
#
#
# main()

# r = requests.get("http://openjudge.cn")
# print(r.url)  # >>http://openjudge.cn
# 或：
# session = requests.session()
# r = session.get("http://openjudge.cn")
# print(r.url)
#
# browser = await pyp.launch(headless=False)
# page = await browser.newPage()
# await page.goto("http://openjudge.cn")
# print(page.url)  # >>http://openjudge.cn


# import re
# import asyncio  # Python 3.6之后自带的协程库
# import pyppeteer as pyp
# import bs4
#
#
# async def antiAntiCrawler(page):  # 为page添加反反爬虫手段
#     await page.setUserAgent('Mozilla/5.0 (Windows NT 6.1; \
#     Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) \
#     Chrome/78.0.3904.70 Safari/537.36')
#     await page.evaluateOnNewDocument(
#         '() =>{ Object.defineProperties(navigator, \
#         { webdriver:{ get: () => false } }) }')
#
#
# async def getStockCodes(page):  # 用正则表达式获取股票名称和代码
#     # 从"https://www.banban.cn/gupiao/list_sh.html"对应的page获取所有股票名称和代码
#     codes = []  # 最终内容：["四川路桥(600039)","包钢股份(600010)"......]
#     html = await page.content()
#     pt = '<a href="/gupiao/[^"]*">([^<]*\(\d+\))</a>'
#     # 对应 <li><a href="/gupiao/600151/">航天机电(600151)</a></li>
#     for x in re.findall(pt, html):
#         codes.append(x)
#     return codes  # 耗时：0: 00:00.033943
#
#
# async def getStockInfo(url):
#     browser = await pyp.launch(headless=False)
#     # 启动Chromium,browser即为Chromium浏览器，非隐藏启动
#     page = await browser.newPage()  # 在浏览器中打开一个新页面（标签）
#     await antiAntiCrawler(page)  # 新页面生成后一律调用此来反反爬
#     await page.goto(url)  # 装入url对应的网页
#     codes = await getStockCodes(page)
#
#     for x in codes[:3]:  # 只取前三个股票信息
#         print("-----", x)  # x形如 "四川路桥(600039)"
#         pos1, pos2 = x.index("("), x.index(")")
#         code = x[pos1 + 1:pos2]  # 取股票代码,如600039
#         url = "https://quote.eastmoney.com/sh" + code + ".html"
#         await page.goto(url)
#         html = await page.content()  # 往下编程前可以先print(html)看一看
#         pt = '<td>([^<]*)</td>.*?<td[^>]*id="gt\d*?"[^>]*>([^<]*)</td>'
#         for x1 in re.findall(pt, html, re.DOTALL):
#             print(x1[0], x1[1])
#
#     await browser.close()  # 关闭浏览器
#
#
# url = "https://www.banban.cn/gupiao/list_sh.html"
# loop = asyncio.get_event_loop()
# loop.run_until_complete(getStockInfo(url))


# async def getStockCodes(page):
#     codes = []
#     html = await page.content()
#     soup = bs4.BeautifulSoup(html, "html.parser")
#     for x in soup.find_all("li"):
#         # 对应 <li><a href="/gupiao/600151/">航天机电(600151)</a></li>
#         a = x.find("a")
#         if "(" in a.text and ")" in a.text:
#             codes.append(a.text)
#     return codes  # 耗时：0: 00:00.193480

# # 用浏览器自身的查找元素功能获取股票名称和代码
# async def getStockCodes(page):
#     codes = []
#     elements = await page.querySelectorAll("li")  # 根据tag name找元素
#     # 对应 <li><a href="/gupiao/600151/">航天机电(600151)</a></li>
#     for e in elements:
#         a = await e.querySelector("a")  # 根据tag name找元素
#         obj = await a.getProperty("text")  # 还可以 a.getProperty("href")
#         # 上面这句不行就改成: obj = await a.getProperty("innerText")
#         text = await obj.jsonValue()  # 固定写法
#         if "(" in text and ")" in text:
#             codes.append(text)
#     return codes  # 耗时： 0:00:04.421178
