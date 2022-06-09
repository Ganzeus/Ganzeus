# 作者：郭炜 版权所有
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
