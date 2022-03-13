data segment
x dw 30
y dw 15
z1 dw ?
z2 dw ?
z3 dw ?
data ends

code segment
	assume cs:code,ds:data

start: 
	mov ax,data
	mov ds,ax
	
	mov ax,x
	add ax,y
	mov z1,ax

	mov ax,x
	sub ax,y
	mov z2,ax

	mov ax,x
	mul y
	mov z3,ax

	mov ax,4c00h
	int 21h
code ends
	end start