global assembleval
assembleval:

mov rax,0x002b                             ;x002b = + = 43
cmp rdi, rax			
je addition
mov rax,0x002d				   ;0x002d = - = 45
cmp rdi, rax
je subtraction
mov rax,0x002a				   ;x002a = * = 42 
cmp rdi, rax
je multiplication
mov rax, 0x002f                            ;0x002f = /  47
cmp rdi, rax
je division 


addition:
	addss xmm0, xmm1
	ret
subtraction:
	subss xmm0,xmm1
	ret
multiplication: 
	mulss xmm0,xmm1
	ret
division:
	divss xmm0,xmm1 
	ret	
