section .text
global _start
_start:
 
;clear out the registers we are going to need
xor eax,eax
xor ebx,ebx
xor ecx,ecx
xor edx,edx
 
; write(int fd, char *msg, unsigned int len)
mov al,4
mov bl,1
; Owned!!!=0x4F,0x77,0x6E,0x65,0x64,0x21,0x21
push 0x21212164
push 0x656E774F
mov ecx,esp
mov dl,8
int 0x80
 
; exit(int ret)
mov al,1
xor ebx,ebx
int 0x80
