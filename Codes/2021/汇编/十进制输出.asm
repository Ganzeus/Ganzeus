assume cs:code,ss:stack
stack segment 
stack ends

code segment
start:
    mov ax,65535
    mov bx,002Ah
    push bx
switch:                  ;十六进制转十进制输出
    mov bx,10           ;除数放入bx 16位
    div bx             ;商存在ax中，余数存在dx中
    push dx             ;余数进栈
    mov dx,0            ;清空余数
    cmp ax,0
    je output            ;商是0则开始输出
    jmp switch          ;商不是0则继续做除法

output:
    pop dx              ;出栈
    cmp dl,2Ah
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