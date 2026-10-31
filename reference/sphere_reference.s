.intel_syntax noprefix
.text
.globl _sphere_reference
_sphere_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
sphere_L0:
movupd	xmm0, xmmword ptr [rsi - 0x78]
sphere_L5:
movsd	xmm1, qword ptr [rsi - 0x68]
sphere_La:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
sphere_Lf:
mulsd	xmm1, qword ptr [rdi - 0x20]
sphere_L14:
addpd	xmm0, xmmword ptr [rdi - 0x40]
sphere_L19:
addsd	xmm1, qword ptr [rdi - 0x30]
sphere_L1e:
cmp	dword ptr [rdi - 0x64], 0x0
sphere_L22:
je	sphere_L3d
sphere_L24:
movsd	xmm5, qword ptr [rsi + 0x70]
sphere_L29:
mulsd	xmm5, qword ptr [rdi - 0x20]
sphere_L2e:
movupd	xmmword ptr [rsi - 0x78], xmm0
sphere_L33:
movsd	qword ptr [rsi - 0x68], xmm1
sphere_L38:
movsd	qword ptr [rsi + 0x70], xmm5
sphere_L3d:
movapd	xmm3, xmmword ptr [rdi - 0x60]
sphere_L42:
movsd	xmm4, qword ptr [rdi - 0x50]
sphere_L47:
mulpd	xmm0, xmm3
sphere_L4b:
mulsd	xmm1, xmm4
sphere_L4f:
mulpd	xmm0, xmm0
sphere_L53:
mulsd	xmm1, xmm1
sphere_L57:
addsd	xmm1, xmm0
sphere_L5b:
unpckhpd	xmm0, xmm0              
sphere_L5f:
addsd	xmm1, xmm0
sphere_L63:
sqrtsd	xmm1, xmm1
sphere_L67:
movsd	xmm2, qword ptr [rdi - 0x78]
sphere_L6c:
subsd	xmm2, xmm1
sphere_L70:
subsd	xmm1, qword ptr [rdi - 0x10]
sphere_L75:
maxsd	xmm1, xmm2
sphere_L79:
andpd	xmm3, xmmword ptr [rdi]
sphere_L7d:
andpd	xmm4, xmmword ptr [rdi]
sphere_L81:
maxsd	xmm4, xmm3
sphere_L85:
unpckhpd	xmm3, xmm3              
sphere_L89:
maxsd	xmm4, xmm3
sphere_L8d:
divsd	xmm1, xmm4
sphere_L91:
cmp	dword ptr [rdi - 0x64], 0x0
sphere_L95:
jne	sphere_L9c
sphere_L97:
divsd	xmm1, qword ptr [rdi - 0x20]
sphere_L9c:
mov	eax, dword ptr [rdi - 0x68]
sphere_L9f:
movsd	qword ptr [rsi - 0x20], xmm1
sphere_La4:
and	eax, 0x3
sphere_La7:
fld	qword ptr [rsi + 8*rax - 0x80]
sphere_Lab:
fmul	dword ptr [rdi - 0x70]
sphere_Lae:
fadd	dword ptr [rdi - 0x6c]
sphere_Lb1:
fstp	qword ptr [rsi + 0x80]
sphere_Lb7:
ret
