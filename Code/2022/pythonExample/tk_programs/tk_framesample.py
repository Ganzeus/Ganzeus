# 作者：郭炜  版权所有
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
