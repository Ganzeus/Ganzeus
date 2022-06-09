assume cs:code,ds:data,ss:stack

stack segment
    dw 0,0,0,0,0,0,0,0  ;定义一个段，作为栈段，容量为16个字节
stack ends

data segment 
    rank dw 1,1,1,1,1,1,1,1,1,1  ;默认排名第一
    grade dw 80,60,49,86,100,79,85,86,99,59
data ends


code segment 
start:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    mov sp,16           ;栈底

    mov cx,10           ;外层循环10次
    mov si,0
;外层循环
s:  push cx             ;将cx压栈暂存       
    mov di,0
    mov ax,[grade+si]      ;当前成绩
    mov cx,10           ;设置内层循环的次数
;内层循环
s0: mov bx,[grade+di]      ;要比较的成绩
    cmp ax,bx
    jb set
    jmp next              ;存在比当前大的成绩跳转至set
set:                    ;将排名加1
    mov dx,[rank+si]
    inc dx
    mov [rank+si],dx
    jmp next
next:   
    add di,2              ;与下一个比较
    loop s0

    pop cx              ;从栈顶弹出原cx的值，回复cx
    add si,2              ;比较下一个成绩
    loop s              ;外层循环loop指令将cx中的计数值减1
    
    mov ax,4c00h        ;循环结束则中断程序
    int 21H
code ends
end start