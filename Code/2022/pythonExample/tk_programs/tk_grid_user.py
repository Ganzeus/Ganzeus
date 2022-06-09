# 作者：郭炜  版权所有
import tkinter as tk

win = tk.Tk()  # 创建窗口
win.title("Hello")  # 指定窗口标题
label1 = tk.Label(win, text="用户名：")  # 创建属于win上的图文标签控件
label2 = tk.Label(win, text="密码：")
etUsername = tk.Entry(win)  # 创建属于win的单行编辑框控件，用于输入用户名
etPassword = tk.Entry(win)  # 创建密码编辑框
label1.grid(row=0, column=0, padx=5, pady=5)
# label1放在第0行第0列，上下左右都留白5像素
label2.grid(row=1, column=0, padx=5, pady=5)
etUsername.grid(row=0, column=1, padx=5, pady=5)  # 用户名输入框放在第0行第1列
etPassword.grid(row=1, column=1, padx=5, pady=5)  # 密码输入框放在第1行第1列
btLogin = tk.Button(win, text="登录")  # 创建属于win的按钮控件
btLogin.grid(row=2, column=0, columnspan=2, padx=5, pady=5)
# btLogin放在第2行第0列，跨2列
win.columnconfigure(0, weight=1)
# 指定第0列增量分配权重为1
win.columnconfigure(1, weight=1)
win.rowconfigure(0, weight=1)
# 指定第0行增量分配权重为1
win.rowconfigure(1, weight=1)
win.rowconfigure(2, weight=1)

win.mainloop()  # 显示窗口
