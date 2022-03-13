data segment
	array db 45,98,63,78,88,101,89,65,100
data ends

code segment
	assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov cx,9
	mov bh,[si]			;
	mov bl,[si]			
	lea si,array  

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

next:		inc si             
		loop compare
	mov ax,4c00h
	int 21h
code ends
	end start