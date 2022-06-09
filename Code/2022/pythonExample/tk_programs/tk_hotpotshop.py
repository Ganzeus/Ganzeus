# 作者：郭炜 版权所有
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
    gWin.totalCost, gWin.discount = 0, 1  # 总价和折扣   Python可以随时给对象添加成员变量
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
