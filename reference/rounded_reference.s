.intel_syntax noprefix
.text
.globl _rounded_reference
_rounded_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
rounded_reference_L0:
movupd	xmm0, xmmword ptr [rsi - 0x78]
rounded_reference_L5:
movsd	xmm1, qword ptr [rsi - 0x68]
rounded_reference_La:
mulpd	xmm0, xmmword ptr [rdi - 0x30]
rounded_reference_Lf:
mulsd	xmm1, qword ptr [rdi - 0x30]
rounded_reference_L14:
addpd	xmm0, xmmword ptr [rdi - 0x50]
rounded_reference_L19:
addsd	xmm1, qword ptr [rdi - 0x40]
rounded_reference_L1e:
xorpd	xmm4, xmm4
rounded_reference_L22:
cmp	dword ptr [rdi - 0x64], 0x0
rounded_reference_L26:
je	rounded_reference_L41
rounded_reference_L28:
movsd	xmm5, qword ptr [rsi + 0x70]
rounded_reference_L2d:
mulsd	xmm5, qword ptr [rdi - 0x30]
rounded_reference_L32:
movupd	xmmword ptr [rsi - 0x78], xmm0
rounded_reference_L37:
movsd	qword ptr [rsi - 0x68], xmm1
rounded_reference_L3c:
movsd	qword ptr [rsi + 0x70], xmm5
rounded_reference_L41:
andpd	xmm0, xmmword ptr [rdi]
rounded_reference_L45:
andpd	xmm1, xmmword ptr [rdi]
rounded_reference_L49:
subpd	xmm0, xmmword ptr [rdi - 0x20]
rounded_reference_L4e:
subsd	xmm1, qword ptr [rdi - 0x10]
rounded_reference_L53:
addpd	xmm0, xmmword ptr [rdi - 0x60]
rounded_reference_L58:
addsd	xmm1, qword ptr [rdi - 0x60]
rounded_reference_L5d:
maxpd	xmm0, xmm4
rounded_reference_L61:
maxsd	xmm1, xmm4
rounded_reference_L65:
mulpd	xmm0, xmm0
rounded_reference_L69:
mulsd	xmm1, xmm1
rounded_reference_L6d:
addsd	xmm1, xmm0
rounded_reference_L71:
shufpd	xmm0, xmm0, 0x1         
rounded_reference_L76:
addsd	xmm1, xmm0
rounded_reference_L7a:
sqrtsd	xmm1, xmm1
rounded_reference_L7e:
subsd	xmm1, qword ptr [rdi - 0x60]
rounded_reference_L83:
cmp	dword ptr [rdi - 0x64], 0x0
rounded_reference_L87:
jne	rounded_reference_L8e
rounded_reference_L89:
divsd	xmm1, qword ptr [rdi - 0x30]
rounded_reference_L8e:
mov	eax, dword ptr [rdi - 0x68]
rounded_reference_L91:
movsd	qword ptr [rsi - 0x20], xmm1
rounded_reference_L96:
and	eax, 0x3
rounded_reference_L99:
fld	qword ptr [rsi + 8*rax - 0x80]
rounded_reference_L9d:
fmul	dword ptr [rdi - 0x70]
rounded_reference_La0:
fadd	dword ptr [rdi - 0x6c]
rounded_reference_La3:
fstp	qword ptr [rsi + 0x80]
rounded_reference_La9:
ret
