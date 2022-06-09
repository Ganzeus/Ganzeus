data segment
	array db 45,98,63,78,88,101,89,65,100
	str1 db ' max is $'
	str2 db ' min is $'
data ends

code segment
	assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov cx,9
	mov bh,[si]			;存放最大值
	mov bl,[si]			;存放最小值
	lea si,array  ;地址指针si指向array储存区首地址

compare:
	mov al,[si]
	cmp al,bh
	ja bigger
	cmp al,bl
	jb less
	jmp next

bigger:
	mov bh,al
	jmp next

less:
	mov bl,al
	jmp next

next:		inc si             ;转向下一个字
		loop compare

	mov dx,offset str1  ;输出字符串
    mov ah,9
    int 21h

	mov dl,bh					;输出最大值
    add dl,30h			;0的ASCII码为30h
    mov ah,02h
    int 21h

	mov ah,2                     ;输出换行
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov dx,offset str2  ;输出字符串
    mov ah,9
    int 21h

	mov dl,bl					;输出最小值
	add dl,30h			;0的ASCII码为30h
    mov ah,02h
    int 21h

	mov ah,2                     ;输出换行
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 
	
	mov ax,4c00h
	int 21h
code ends
	end start