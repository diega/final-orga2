section .data
 primeraPorcion: dd 0xFF000000 ;solo deja pasar los 1 8 bits
 segundaPorcion: dd 0x00FF0000 ;solo deja pasar la 2 tanda de ochos

section .text
; Declaracion de "restar"
; int restar(int a, int b);
; queda el resultado en eax

global restar

%define img_o	ebp+8
%define img_c	ebp+12

restar:
	; Stack frame
	push ebp
	mov ebp, esp

	; Convecion C, hay que salvar estos registros
	push ebx
	push edi
	push esi

	mov ebx, [img_o]
	mov ecx, [img_c]
	xor eax, eax	; inicializo el acumulador
	clc

	sub cl, bl	;resta el 1byte menos significativo
	adc al, cl
	sub ch, bh	;resta el 2byte menos significativo
	adc ah, ch
	push ebx	;me quede sin registros y sino pierdo los datos para el byte q me falta restar
	push ecx	;me quede sin registros y sino pierdo los datos para el byte q me falta restar	
	and ebx, segundaPorcion
	and ecx, segundaPorcion
	sub ecx, ebx
	adc eax, ecx
	pop ecx
	pop ebx
	and ebx, primeraPorcion
	and ecx, segundaPorcion
	sub ecx, ebx
	;aca termino lo mio

	pop esi
	pop edi
	pop ebx

	pop ebp
ret 
