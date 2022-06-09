assume cs:code,ss:stack
stack segment

stack ends

code segment
start:
    mov bx,002Ah
    push bx          ;*入栈作为栈底

    mov ah,01h       ;输入字符保存在al中
    int 21H          
    sub al,30h
    mov ah,0         ;此时ax为输入的数
    mov bl,10
    mul bl
    mov cx,ax

    mov ah,01h
    int 21H
    sub al,30h
    mov ah,0
    add ax,cx
    push ax
    mov ah,01h
    int 21h
    pop ax
next:   
    call FIB             ;运行前ax为n,运行后ax为f(n)中
    
    mov bx,002Ah            
    push bx             ;*入栈作为栈底
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

FIB proc
    cmp ax,1
    je return
    cmp ax,2
    je return       ;n=1或2时返回1

    push ax
    sub ax,1
    call FIB      
    mov bx,ax       ;bx=f(n-1)

    pop ax
    push bx
    sub ax,2
    call FIB
    mov cx,ax        ;cx=f(n-2)

    pop bx
    mov ax,bx
    add ax,cx        ;ax=bx+cx=f(n-1)+f(n-2)

    ret
return:
    mov ax,1
    ret
FIB endp

code ends
end start