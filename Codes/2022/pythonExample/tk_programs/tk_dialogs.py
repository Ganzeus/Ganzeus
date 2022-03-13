# 作者：郭炜  版权所有
import tkinter as tk
from tkinter import messagebox
from tkinter import simpledialog
from tkinter import filedialog

gWin = None


def cmd(n):
    def innerCmd():  # innerCmd是个闭包
        # if n <= 4:
        # 	func = eval("messagebox." + gWin.titles[n])
        # 	value = func("Dialog", gWin.titles[n])
        # elif n <= 7:
        # 	func = eval("simpledialog." + gWin.titles[n])
        # 	value = func("Dialog", gWin.titles[n])
        if n == 0:
            value = messagebox.askokcancel("Dialog", gWin.titles[n])
        elif n == 1:
            value = messagebox.askyesno("Dialog", gWin.titles[n])
        elif n == 2:
            value = messagebox.showerror("Dialog", "抱歉，您的账户余额不足!")
        elif n == 3:
            value = messagebox.showinfo("Dialog", gWin.titles[n])
        elif n == 4:
            value = messagebox.showwarning("Dialog", gWin.titles[n])
        elif n == 5:
            value = simpledialog.askfloat("Dialog", "请输入支付金额:")
        elif n == 6:
            value = simpledialog.askinteger("Dialog", gWin.titles[n])
        elif n == 7:
            value = simpledialog.askstring("Dialog", gWin.titles[n])
        elif n == 8:
            value = filedialog.askopenfilename(title='打开文件',
                                               filetypes=[('images', '*.jpg *.png'), ('text', '*.txt'),
                                                          ('All Files', '*')])
        elif n == 9:
            value = filedialog.asksaveasfilename(title='保存文件',
                                                 initialdir='c:/tmp', initialfile='hello.py')
        elif n == 10:
            value = filedialog.askopenfilenames(title='打开文件',
                                                filetypes=[('images', '*.jpg *.png'), ('All Files', '*')])
        elif n == 11:
            value = filedialog.askdirectory(title='打开文件',
                                            initialdir='c:/tmp2')
        print(n, value, type(value))

    return innerCmd


def main():
    global gWin
    gWin = tk.Tk()
    gWin.titles = ["askokcancel", "askyesno", "showerror",
                   "showinfo", "showwarning", "askfloat", "askinteger",
                   "askstring", "askopenfilename", "asksaveasfilename",
                   "askopenfilenames", "askdirectory"]
    for i in range(12):
        button = tk.Button(gWin, text=gWin.titles[i], command=cmd(i))
        button.grid(row=i // 4, column=i % 4, padx=5, pady=5)
    gWin.columnconfigure(0, weight=1)
    gWin.mainloop()


main()
