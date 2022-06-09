# 作者：郭炜  版权所有
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
# cbPassword关联变量showPassword，其事件响应函数是cbPassword_click，即点击它时，
# 会调用 cbPassword_click()
cbPassword.grid(row=3, column=0, padx=5, pady=5)
btLogin = tk.Button(win, text="登录", command=btLogin_click)
# 点击btLogin按钮会执行btLogin_click()
btLogin.grid(row=4, column=0, pady=5)
btQuit = tk.Button(win, text="退出", command=win.quit)
# 点击btQuit会执行win.quit()，win.quit()导致窗口关闭，于是整个程序结束
btQuit.grid(row=4, column=1, pady=5)
win.mainloop()
