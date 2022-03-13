# 作者：郭炜 版权所有
import tkinter as tk
from tkinter import ttk
import tkinter
from tkinter import ttk  # 导入内部包

# 定义列的名称

win = tk.Tk()
win.geometry("800x600")
paneWin = ttk.Panedwindow(win, orient=tk.HORIZONTAL)  # 添加水平方向的推拉窗组件
paneWin.grid(row=0, column=0, sticky=tk.NSEW)  # 向四个方向拉伸填满MWindow帧

frmleft = ttk.Frame(paneWin, relief=tk.SUNKEN, padding=0)  # 左侧Frame帧用于放置播放列表
frmleft.grid(row=0, column=0, sticky=tk.NS)  # 左侧Frame帧拉伸填充
frmleft.rowconfigure(0, weight=1)
frmleft.columnconfigure(0, weight=1)
paneWin.add(frmleft, weight=1)  # 将左侧Frame帧添加到推拉窗控件，左侧权重1

frmRight = ttk.Frame(paneWin, relief=tk.SUNKEN)  # 右侧Frame帧用于放置视频区域和控制按钮
frmRight.grid(row=0, column=0, sticky=tk.NSEW)  # 右侧Frame帧四个方向拉伸
frmRight.rowconfigure(0, weight=1)
frmRight.columnconfigure(0, weight=1)

paneWin.add(frmRight, weight=1)  # 将左侧Frame帧添加到推拉窗控件，左侧权重1

tabControl = ttk.Notebook(frmRight)  # 创建Notebook
tab1 = tk.Frame(tabControl, bg='blue')  # 增加新选项卡
tabControl.add(tab1, text='气候')  # 把新选项卡增加到Notebook
tab2 = tk.Frame(tabControl, bg='yellow')
tabControl.add(tab2, text='面积')
tab3 = tk.Frame(tabControl)
tabControl.add(tab3, text='人口')
tab4 = tk.Frame(tabControl, bg='blue')
tabControl.add(tab4, text='GDP')
tabControl.pack(expand=1, fill="both")
tabControl.select(tab1)  # 选择tab1

tree = ttk.Treeview(frmleft, selectmode='browse', show='tree', padding=[0, 0, 0, 0])
tree.grid(row=0, column=0, sticky=tk.NSEW)  # 树状视图填充左侧Frame帧
tree.column('#0', width=150)  # 设置图标列的宽度，视图的宽度由所有列的宽决定 width是整个treeview宽度（像素)
# 一级节点parent='',index=第几个节点,iid=None则自动生成并返回，text为图标右侧显示文字
# values值与columns给定的值对应
tr_root2 = tree.insert("", 0, None, open=True, text='美国')  # 树视图添加根节点
node1 = tree.insert(tr_root2, 0, None, open=True, text='加州')  # 根节点下添加一级节点
node2 = tree.insert(tr_root2, 1, None, open=True, text='纽约')  # 根节点下添加一级节点

tr_root = tree.insert("", 0, None, open=True, text='中国')  # 树视图添加根节点
node1 = tree.insert(tr_root, 0, None, open=True, text='浙江省')  # 根节点下添加一级节点
node11 = tree.insert(node1, 0, None, text='杭州市')  # 添加二级节点
node12 = tree.insert(node1, 1, None, text='温州市')  # 添加二级节点
node2 = tree.insert(tr_root, 1, None, open=True, text='福建省')  # 根节点下添加一级节点
node21 = tree.insert(node2, 0, None, text='福州市')  # 添加二级节点
node22 = tree.insert(node2, 1, None, text='厦门市')  # 添加二级节点

columns = ("name", "gender", "age")
tree = ttk.Treeview(tab3, show="headings", columns=columns, selectmode=tk.BROWSE)

# 设置表格文字居中
tree.column("name", anchor="center")
tree.column("gender", anchor="center")
tree.column("age", anchor="center")

# 设置表格头部标题
tree.heading("name", text="姓名")
tree.heading("gender", text="性别")
tree.heading("age", text="年龄")

# 设置表格内容
lists = [{"name": "张三", "gender": "男", "age": "18"}, {"name": "王丽", "gender": "女", "age": "25"},
         {"name": "李四", "gender": "男", "age": "15"}]
i = 0
for v in lists:
    tree.insert('', i, values=(v.get("name"), v.get("gender"), v.get("age")))
    i += 1
tab3.columnconfigure(0, weight=1)
tab3.rowconfigure(0, weight=1)
tree.grid(row=0, column=0, padx=5, pady=5, sticky="NWES")

menubar = tk.Menu(win)
fileMenu = tk.Menu(menubar, tearoff=0)  # 去掉顶端横线
menubar.add_cascade(label='File', menu=fileMenu)  # 添加一个子菜单 File
fileMenu.add_command(label='New')
fileMenu.add_command(label='Open')
fileMenu.add_command(label='Save', accelerator="Ctrl+S")
fileMenu.add_command(label='Save As')
fileMenu.add_separator()  # 加分割线
fileMenu.add_command(label='Exit', command=quit)
editMenu = tk.Menu(menubar, tearoff=0)
menubar.add_cascade(label='Edit', menu=editMenu)
editMenu.add_command(label='Cut')
editMenu.add_command(label='Copy')
editMenu.add_command(label='Paste')
settingsMenu = tk.Menu(editMenu, tearoff=0)
editMenu.add_cascade(label='Settings', menu=settingsMenu)
win.config(menu=menubar)
win.rowconfigure(0, weight=1)
win.columnconfigure(0, weight=1)

win.mainloop()
