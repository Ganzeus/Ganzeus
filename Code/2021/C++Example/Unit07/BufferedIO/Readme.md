#### 本部分要展示的内容如下：

1. 键盘输入一个字母后回车，实际进入缓冲区的是2个字符

2. 使用cin输入信息后，有换行字符残留在缓冲区，从而导致return语句前的 cin.get() 不起作用
