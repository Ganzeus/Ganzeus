assume ds:data,cs:code
data segment 
    db 'welcome to masm!'
data ends
data2 segment
    db 2h,24h,71h ;黑底绿字，绿底红字，白底蓝字
data2 ends

code segment
start:
    mov ax,0b800h   ;向B8000H~BFFFFH中写入数据，写入的内容将立刻出现在显示器上
    mov ds,ax
    mov bx,0
    mov cx,19h      ;外层循环25次
s:  push cx
    mov cx,50h      ;内层循环80次
s1: mov word ptr [bx],0 ;一页80x25个字符，一个字符两个字节，全部设为0
    add bx,2
    loop s1
    pop cx
    loop s
    
    mov cx,3        ;输出三行
    mov di,0h 
    mov bx,720h
s2: push cx
    mov cx,10h
    mov si,0

s3: mov ax,data
    mov es,ax
    mov al,es:[si]
    mov [bx],al     ;先放字符ASCII码
    inc bx
    inc si
    mov ax,data2
    mov es,ax
    mov al,es:[di]
    mov [bx],al     ;再放字符属性
    inc bx
    loop s3

    add bx,80h
    inc di
    pop cx
    loop s2

    mov ax,4c00h
    int 21H
code ends
end start