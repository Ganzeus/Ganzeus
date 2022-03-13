assume cs:code,ds:data
data segment
    array dw 2,4,0,1,3,5
data ends

code segment
start:
    mov ax,data
    mov ds,ax
    mov cx,6
    mov ax,100
    mov si,0    
s:  ;逐个判断奇偶
    mov bx,[array+si]
    mov dx,bx           ;用dx暂存当前值
    and bx,01B
    cmp bx,0            ;是偶数
    je compare
    jmp next
compare:                ;判断是否最小
    cmp dx,ax
    jb ok               ;比当前最小值小
    jmp next
ok:
    mov ax,dx           ;更新最小值
    jmp next
next:                   ;循环控制
    add si,2
    loop s

    mov ax,4c00h
    int 21H
code ends
end start