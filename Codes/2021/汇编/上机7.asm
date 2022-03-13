assume cs:code,ds:data
data segment
    N EQU 25
    AA db 'ABCDEFGHIJKLMN01234567890'
    BB db N dup(?)
data ends
MOVE macro a,b,c
    mov si,0
    mov cx,b
s:
    mov al,[a+si]
    mov [c+si],al
    inc si
    loop s
    endm 
code segment
start:
    mov ax,data
    mov ds,ax

    MOVE AA,N,BB

    mov ax,4c00h
    int 21H
code ends
end start