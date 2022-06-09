# 作者：郭炜  版权所有
import tkinter as tk
from tkinter import ttk

win = tk.Tk()
tk.Button(win, text="Button").grid(row=0, column=0, padx=5, pady=5)
tk.Label(win, text="Label").grid(row=0, column=1, padx=5, pady=5)
tk.Checkbutton(win, text="Checkbutton").grid(row=0, column=2, padx=5, pady=5)
tk.Radiobutton(win, text="Radiobutton").grid(row=0, column=3, padx=5, pady=5)
s = tk.StringVar()
s.set("Entry")
tk.Entry(win, textvariable=s).grid(row=0, column=4, padx=5, pady=5)
frm = tk.LabelFrame(win, text="LabelFrame")
frm.grid(row=1, column=0, padx=5, pady=5)
tk.Label(frm, text="Spinbox:").grid(row=0, column=0, padx=5)
dishNum = tk.StringVar(value="1")
tk.Spinbox(frm, width=5, from_=1, to=1000, textvariable=dishNum).grid(row=1, column=0, padx=5, pady=5)
s2 = tk.StringVar()
edt = tk.Text(win, width=20, height=10)
edt.grid(row=1, column=1, padx=5, pady=5)
edt.insert("insert", "this is a\nText")

scale = tk.Scale(win,  # Scale是滑动条
                 label='Scale',
                 from_=0,  # 滑动范围最小值
                 to=20,  # 滑动范围最大值
                 orient=tk.HORIZONTAL,  # 水平方向
                 length=200,  # 像素
                 showvalue=1,  # 是否显示当前滑块位置值
                 tickinterval=5,  # 刻度间隔
                 resolution=1,  # 最小变化量
                 ).grid(row=1, column=2)

myList = tk.StringVar()
myList.set(['This is a Listbox', 'item1', 'item2'])
tk.Listbox(win,
           listvariable=myList,  # myList变化，listbox内容也变化
           height=6,  # 字符
           ).grid(row=1, column=3, padx=5, pady=5)

frm2 = tk.Frame

Options = ['OptionMenu', 'Banana', 'Coconut']
op_var = tk.StringVar()
op_var.set(Options[0])
optionmenu = tk.OptionMenu(win,
                           op_var,
                           *Options,  # 代替可变个数个参数，等价于写   'Apple','banana','coconut'
                           )
optionmenu.grid(row=1, column=4, padx=5, pady=5)
category = tk.StringVar()  # 对应组合框gWin.cbxCategory收起状态显示的文字
cbxCategory = ttk.Combobox(win, textvariable=category)
cbxCategory["values"] = ("Combobox", "佐料", "菜品")  # 下拉时显示的表象
cbxCategory["state"] = "readonly"  # 将gWin.cbxCategory设置为不可输入，只能选择
cbxCategory.current(0)  # 选中第0项
cbxCategory.grid(row=2, column=0, rowspan=2, padx=5, pady=5)
tk.Label(win, text="ProgressBar:").grid(row=2, column=1, padx=5)
prog = ttk.Progressbar(win, mode='indeterminate')
prog.grid(row=3, column=1, padx=5, pady=5)

tk.Label(win, text="LabeledScale:").grid(row=2, column=2, padx=5)
labeledscale = ttk.LabeledScale(win,
                                from_=-100,  # 设置最大值
                                to=100,  # 设置最小值
                                compound=tk.TOP  # 显示数值在滑动条下方
                                )
labeledscale.value = -20
labeledscale.grid(row=3, column=2, padx=5, pady=5)
tk.Message(win, text="This is a \nMessage.\nHello!").grid(row=2, column=3, rowspan=2, padx=5, pady=5)
win.mainloop()
