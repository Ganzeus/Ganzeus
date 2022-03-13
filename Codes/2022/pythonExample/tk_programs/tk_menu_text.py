# 作者：郭炜 版权所有
import tkinter as tk
from tkinter import filedialog

gWin = None


def muCut_click():
    gWin.txtFile.event_generate("<<Cut>>")


def muCopy_click():
    gWin.txtFile.event_generate("<<Copy>>")


def muPaste_click():
    gWin.txtFile.event_generate('<<Paste>>')


def saveTextFile(fileName):
    f = open(fileName, "w", encoding="utf-8")
    f.write(gWin.txtFile.get(0.0, tk.END))
    f.close()


def muSaveAs_click():
    fileName = filedialog.asksaveasfilename(title='Save File',
                                            initialdir='c:/tmp', initialfile='untitled.txt',
                                            filetypes=[('Text File', '*.txt')], defaultextension=".txt")
    if fileName != "":
        saveTextFile(fileName)
        gWin.title(fileName)
        gWin.curFileName = fileName


def muSave_click():
    if gWin.curFileName.lower() == "untitled.txt":
        muSaveAs_click()
    else:
        saveTextFile(gWin.curFileName)


def muOpen_click():
    global gWin
    fileName = filedialog.askopenfilename(title='Open File',
                                          filetypes=[('Text Files', '*.txt'), ('All Files', '*')])
    if fileName != "":
        gWin.curFileName = fileName
        gWin.title(fileName)
        f = open(fileName, "r")
        text = f.read()
        f.close()
        gWin.txtFile.delete(0.0, tk.END)
        gWin.txtFile.insert("insert", text)  # gWin.txtFile.insert(tk.END, text)加在最后


def muBigFont_click():
    if gWin.isBigFont.get() == 1:
        gWin.txtFile.configure(font=("SimHei", 18, "bold"))
    else:
        gWin.txtFile.configure(font=("", 10))


def muNew_click():
    global gWin
    gWin.txtFile.delete(0.0, tk.END)
    gWin.title("untitled.txt")
    gWin.curFileName = "untitled.txt"


def muPrintSelection_click():
    if gWin.txtFile.tag_ranges(tk.SEL):
        print(gWin.txtFile.selection_get())


def main():
    global gWin
    gWin = tk.Tk()
    gWin.title("untitled.txt")
    gWin.menubar = tk.Menu(gWin)
    gWin.fileMenu = tk.Menu(gWin.menubar, tearoff=0)  # 去掉顶端横线
    gWin.menubar.add_cascade(label='File', menu=gWin.fileMenu)  # 添加一个子菜单 File
    gWin.fileMenu.add_command(label='New', command=muNew_click)
    gWin.fileMenu.add_command(label='Open', command=muOpen_click)
    gWin.fileMenu.add_command(label='Save', command=muSave_click,
                              accelerator="Ctrl+S")
    gWin.fileMenu.add_command(label='Save As', command=muSaveAs_click)
    gWin.fileMenu.add_separator()  # 加分割线
    gWin.fileMenu.add_command(label='Exit', command=gWin.quit)
    editMenu = tk.Menu(gWin.menubar, tearoff=0)
    gWin.menubar.add_cascade(label='Edit', menu=editMenu)
    editMenu.add_command(label='Cut', command=muCut_click)
    editMenu.add_command(label='Copy', command=muCopy_click)
    editMenu.add_command(label='Paste', command=muPaste_click)
    settingsMenu = tk.Menu(editMenu, tearoff=0)
    editMenu.add_cascade(label='Settings', menu=settingsMenu)
    gWin.isBigFont = tk.IntVar()
    settingsMenu.add_checkbutton(label="Big Font",
                                 command=muBigFont_click, variable=gWin.isBigFont)
    settingsMenu.add_command(label="Print Selection",
                             command=muPrintSelection_click)
    gWin.config(menu=gWin.menubar)
    gWin.txtFile = tk.Text(gWin)
    gWin.txtFile.grid(row=0, column=0, sticky="NWSE")
    gWin.curFileName = "untitled.txt"
    gWin.rowconfigure(0, weight=1)
    gWin.columnconfigure(0, weight=1)
    gWin.bind_all("<Control-s>", lambda event: muSave_click())
    gWin.mainloop()


main()
