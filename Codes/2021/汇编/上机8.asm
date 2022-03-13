assume cs :code

code segment
start:
	mov ax,cs
	mov ds,ax
	mov si,offset do0	;设置ds:si指向源地址
	
	mov ax,0
	mov es,ax
	mov di,200h			;设置es:di指向目的地址
	
	mov cx,do0end-do0
	
	cld					;设置正向传输
	rep movsb			;复制do0的代码到指定内存中
	
	mov ax,0			;设置中断向量表的表项
	mov es,ax
	mov word ptr es:[0],200h
	mov word ptr es:[2],0
	
	mov ax,4c00h
	int 21h
	
do0:jmp short do0start
	db"Divided by Zero"	;存储字符串
do0start:
	mov ax,cs
	mov ds,ax
	mov si,202h			;设置ds:si指向字符串
	
	mov ax,0b800h
	mov es,ax
	mov di,12*160+36*2	;设置es:di指向显存空间的中间位置
	
	mov cx,15			;输出字符串长度为15
s:
	mov al,[si]
	mov es:[di],al
	inc si
	add di,2
	loop s
	
	mov ax,4c00h
	int 21h
do0end:nop
code ends 
end start