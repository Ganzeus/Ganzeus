# 作者：郭炜  版权所有
import numpy as np
from PIL import Image, ImageTk
from math import *
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
from tkinter import filedialog

gWin = None


def mouse_down(event):
    gWin.mouseDown = True


def mouse_up(event):
    gWin.mouseDown = False
    gWin.lbMsg["text"] = "按住鼠标键移动，会显示鼠标位置"


def mouse_move(event):
    if gWin.mouseDown:
        gWin.lbMsg["text"] = "鼠标位置：(%d,%d)" % (event.x, event.y)


def showImage():
    fileName = filedialog.askopenfilename(title='打开文件',
                                          initialdir="c:/tmp2/", filetypes=[('images', '*.jpg *.png')])
    if fileName != "":
        gWin.geometry("")
        gWin.frmPlot.grid_forget()
        gWin.frmImg.grid(row=1, column=0, sticky="ESWN")
        gWin.img = ImageTk.PhotoImage(Image.open(fileName))  # 用PIL模块的PhotoImage打开
        # and keep a reference。如果 仅img = ImageTk.....然后 lbImage.config(image=img),则显示不出来
        gWin.lbImg.config(image=gWin.img)


def showPlot():
    gWin.geometry("")
    gWin.frmImg.grid_forget()
    gWin.frmPlot.grid(row=1, column=0, sticky="ESWN")
    gWin.ax.clear()  # gWin.fig.clear()
    xs = np.linspace(-3, 3, 100)
    y = [eval(gWin.fstr.get()) for x in xs]
    gWin.ax.plot(xs, y, color='red', linewidth=1.0, linestyle='--')
    gWin.canvas.draw()


def main():
    global gWin
    gWin = tk.Tk()
    frm = tk.Frame(gWin)
    frm.grid(row=0, column=0, sticky="EW")
    tk.Label(frm, text="y =").grid(row=0, column=0, padx=5, pady=5)
    gWin.fstr = tk.StringVar()
    gWin.fstr.set("sin(x)")
    tk.Entry(frm, textvariable=gWin.fstr).grid(row=0, column=1, padx=5, pady=5)
    tk.Button(frm, text="显示函数图", command=showPlot).grid(row=0, column=2, padx=5, pady=5)
    tk.Button(frm, text="显示图像文件", command=showImage).grid(row=0, column=3, padx=5, pady=5)
    gWin.frmImg = tk.Frame(gWin)
    gWin.lbImg = tk.Label(gWin.frmImg)
    gWin.lbImg.grid(row=0, column=0, sticky="NSWE")
    gWin.lbMsg = tk.Label(gWin.frmImg, fg="white", bg="red",
                          text="按住鼠标键移动，会显示鼠标位置")
    gWin.lbMsg.grid(row=1, column=0, sticky="EW")
    gWin.mouseDown = False
    gWin.lbImg.bind("<Motion>", mouse_move)
    gWin.lbImg.bind("<ButtonPress-1>", mouse_down)
    gWin.lbImg.bind("<ButtonRelease-1>", mouse_up)
    gWin.frmPlot = tk.Frame(gWin)
    gWin.fig = plt.Figure(figsize=(5, 4), dpi=100)
    gWin.ax = gWin.fig.add_subplot()
    gWin.canvas = FigureCanvasTkAgg(gWin.fig, master=gWin.frmPlot)
    gWin.canvas.get_tk_widget().grid(row=0, column=0, sticky="ESNW")
    gWin.frmPlot.grid(row=1, column=0, sticky="ESWN")
    showPlot()
    gWin.rowconfigure(1, weight=1)
    gWin.columnconfigure(0, weight=1)
    gWin.mainloop()


main()
