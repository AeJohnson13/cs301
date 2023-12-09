; rpn.asm
; Version 3 
; Alexander E. Johnson
; Started: 2023-12-02
; Updated: 2023-12-09

; For CS 301 Fall 2023
; Contains assembly implementation for function 
; assembleval, for rpncalc_2.cpp



; assembleval
; see header rpncalc_2.hpp for info
global assembleval
assembleval:

sub rdi, 42
mov rcx, QWORD[tableOfFunctions + 8 * rdi]
jmp rcx



tableOfFunctions:
	dq multiplication   ; rdi was x002a aka 42 multiply
	dq addition         ; rdi was x002b aka 43 add
	dq 3		    ; rdi was x002c aka 44 comma shouldn't occur
	dq subtraction      ; rdi was x002d aka 45 subtract
	dq 5                ; rdi was x002e aka 46 decimal shouldn't occur
	dq division         ; rdi was x002f aka 47 divide

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
