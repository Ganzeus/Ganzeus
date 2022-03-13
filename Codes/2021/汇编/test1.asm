data segment
	rank dw 10 dup (1)   ;起始地址为0
	score dw 80,60,49,86,100,79,85,86,99,59
data ends

stack segment
	dw 10 dup (1)
stack ends


code segment 
	assume cs:code,ds:data,ss:stack
start: 
	mov ax,data
	mov ds,ax
	mov cx,10
	mov si,0

L1:	mov ax,[score+si]
	push ax
	add si,2
	loop L1         ;数组内容依次入栈

	mov cx,10
L2:	mov si,0
	pop ax			;从数组最后一个依次排名，ax为当前成绩
L3:	mov dx,[si + score]
	cmp ax,dx
	jae L4			;jump if above or equal,大于等于则跳转至L4
	mov bx,cx
	add bx,bx 
	sub bx,2
	inc [bx+rank]
L4:	add si,2
	cmp si,20
	jb L3
	loop L2

	mov ax,4c00h
	int 21h
code ends
	end start