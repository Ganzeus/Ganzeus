assume cs:code,ss:stack,ds:data
stack segment
    dw 0,0,0,0,0,0,0,0
stack ends

data segment 
    price db 50,10,25,13,90,5,15,24,68,20
data ends


code segment
start:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax   
    mov sp,16
    mov ax,002Ah          ;将*入栈作为出栈终止条件
    push ax    
    mov bx,0           ;bx存总价,初始化为0
    mov cx,10

input:
    mov ah,01h       ;输入字符保存在al中
    int 21H
compare:
    cmp al,0dh
    je switch            ;输入换行则开始进制转换
    jmp save

save:
    mov ah,0
    sub al,30h
    mov si,ax
    mov al,[price+si]   
    add bx,ax
next:
    cmp cx,0
    je blank            ;输入10个字符则换行
    loop input          ;没到10个则输入下一个字符

blank:                 
    mov dx,0dh          ;输出换行
    mov ah,02h
    int 21H

    

    
switch:                  ;十六进制转十进制输出
    mov ax,bx           ;被除数低16位放入ax
s:
    mov bx,10           ;除数放入bx 16位
    div bx             ;商存在ax中，余数存在dx中
    push dx             ;余数进栈
    mov dx,0            ;清空余数
    cmp ax,0
    je output            ;商是0则开始输出
    jmp s          ;商不是0则继续做除法

output:
    pop dx              ;出栈
    cmp dx,002Ah
    je endd             ;到底即中断

    add dl,30h          ;输出栈顶元素
    mov ah,02h
    int 21h
    jmp output          ;继续输出
endd:
    mov ax,4c00h
    int 21h

code ends
end start

    