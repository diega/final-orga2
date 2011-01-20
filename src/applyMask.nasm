; extern void applyMaskFilter(uchar* data, int width, int height, int channels, int step, uchar mask);

section .data
 primeraPorcion: dd 0xFF000000 ;solo deja pasar los 1 8 bits
 segundaPorcion: dd 0x00FF0000 ;solo deja pasar la 2 tanda de ochos

section .text

global applyMaskFilter

%define data	 ebp+8
%define width	 ebp+12
%define height   ebp+16
%define channels ebp+20
%define step     ebp+24
%define mask     ebp+28

applyMaskFilter:
    ; Stack frame
    push ebp
    mov ebp, esp

    ; Convecion C, hay que salvar estos registros
    push ebx
    push edi
    push esi

    mov esi, [data]
    mov ecx, [height]
    row:
        mov ebx, [step]
        column:
            mov edi, 255
            sub edi, [esi]
            mov [esi], edi
            inc esi
            dec ebx
        jnz column
    loop row

    pop esi
    pop edi
    pop ebx

    pop ebp
ret 
