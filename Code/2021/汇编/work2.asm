data segment
data ends

code segment 
	assume cs:code,ds:data
start: 
	mov ax,data
	mov ds,ax

	mov ax,0100h			 
	int 21h

	cmp al,'a'
	ja compare				
	
	mov ax,4c00h			
	int 21h

compare:
	cmp al,'z'
	jb output					

output:
	sub al,32					 
	mov dl,al
	mov ah,02h
	int 21h

	mov ax,4c00h			
	int 21h
code ends
	end start

