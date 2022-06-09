data segment
	grade dw 46,68,88,87,76,89,99,65,100,80
	s5 db 30h          
	s6 db 30h
	s7 db 30h
	s8 db 30h
	s9 db 30h
	s10 db 30h
	string1 db 'The number of students who failed: $'
	string2 db 'The number of ssgrades between 60 and 69:$'
	string3 db 'The number of grades between 70 and 79: $'
	string4 db 'The number of grades between 80 and 89: $'
	string5 db 'The number of grades between 90 and 99: $'
	string6 db 'The number of students who got 100: $'
data ends
code segment 
	assume cs:code,ds:data
start: 
	mov ax,data
	mov ds,ax
	mov cx,10           
	mov bx ,offset grade

;ѭ���жϷ���
compare:		
		mov ax,[bx+si]
		cmp ax,60 
		jl fail                
	
		cmp ax,70
		jl pass             
	
		cmp ax,80
		jl good                

		cmp ax,90
		jl great                

		cmp ax,100
		jne excellent              
	
		inc s10                  
		jmp next
fail:		inc s5
			jmp next
pass:	inc s6
			jmp next
good:	inc s7
			jmp next
great:	inc s8
			jmp next
excellent: inc s9
				jmp next
next:		add si,2            
			loop compare
    
	mov dx,offset string1  
    mov ah,9
    int 21h
	
	mov dl,s5						
    mov ah,2
    int 21h
	
	mov ah,2                     
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov dx,offset string2
    mov ah,9
    int 21h
	mov dl,s6
    mov ah,2
    int 21h
	mov ah,2
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov dx,offset string3
    mov ah,9
    int 21h
	mov dl,s7
    mov ah,2
    int 21h
	mov ah,2
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov dx,offset string4
    mov ah,9
    int 21h
	mov dl,s8
    mov ah,2
    int 21h
	mov ah,2
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov dx,offset string5
    mov ah,9
    int 21h
	mov dl,s9
    mov ah,2
    int 21h
	mov ah,2
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov dx,offset string6
    mov ah,9
    int 21h
	mov dl,s10
    mov ah,2
    int 21h
	mov ah,2
	mov dl,0DH
	int 21h
	mov dl,0AH
	int 21H 

	mov ax,4c00h
	int 21h
code ends
	end start

