// aa.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdio.h>
#pragma data_seg("hehe")
int gg=1;

#pragma data_seg(".data")

int main()
{

	char i=50;
	char i1,i2,i3,i4,i5,i6,i7,i8;
	//i=getchar();
	i++;

	__asm {

_here:
	mov  eax, _step1
	mov byte ptr[i1],al
	mov byte ptr[i2],ah
	shr eax ,16

	mov byte ptr[i3],al
	mov byte ptr[i4],ah
	mov eax,0
	call mm

	mov al,0x37
	call pp1

	mov  eax, _step1
	push bl
mov  bl, byte ptr[eax]
mov byte ptr[i1],bl
add eax,1
mov  bl, byte ptr[eax]
mov byte ptr[i2],bl
add eax,1
mov  bl, byte ptr[eax]
mov byte ptr[i3],bl
add eax,1
mov  bl, byte ptr[eax]
mov byte ptr[i4],bl
pop bl
call mm

	jmp _ov
mm:
	mov al,0x39
	call pp1
call _step1
mov  al,byte ptr[i2]
	mov byte ptr[i1],al
		mov al,0x39
		call pp1
call _step1
mov  al,byte ptr[i3]
	mov byte ptr[i1],al
		mov al,0x39
		call pp1
		call _step1
		mov  al,byte ptr[i4]
	mov byte ptr[i1],al
		mov al,0x39
		call pp1
		call _step1
		ret

_step1:
	mov al,byte ptr[i1]
	shr al ,7
	call _pp
	mov al,byte ptr[i1]
	shr al ,6
		call _pp

		mov al,byte ptr[i1]
	shr al ,5
		call _pp
		mov al,byte ptr[i1]
	shr al ,4
		call _pp
		mov al,byte ptr[i1]
	shr al ,3
		call _pp
		mov al,byte ptr[i1]
	shr al ,2
		call _pp
		mov al,byte ptr[i1]
	shr al ,1
		call _pp
		mov al,byte ptr[i1]
		call _pp
		ret

_pp:
	and al,00000001b
		add al,0x30
		mov esi,esp
		push eax
		call dword ptr [putchar]
	add esp,4
		ret

	pp1:
	mov esi,esp
		push eax
		call dword ptr [putchar]
	add esp,4
		ret

_ov:

	}
	return 9;
}

