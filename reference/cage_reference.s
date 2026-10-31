.intel_syntax noprefix
.text
.globl _cage_reference
_cage_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
cage_L0:
add	rsp, -0x3c
cage_L3:
movupd	xmm0, xmmword ptr [rsi - 0x78]
cage_L8:
movsd	xmm1, qword ptr [rsi - 0x68]
cage_Ld:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
cage_L12:
mulsd	xmm1, qword ptr [rdi - 0x20]
cage_L17:
addpd	xmm0, xmmword ptr [rdi - 0x40]
cage_L1c:
addsd	xmm1, qword ptr [rdi - 0x30]
cage_L21:
cmp	dword ptr [rdi - 0x4c], 0x0
cage_L25:
je	cage_L40
cage_L27:
movsd	xmm5, qword ptr [rsi + 0x70]
cage_L2c:
mulsd	xmm5, qword ptr [rdi - 0x20]
cage_L31:
movupd	xmmword ptr [rsi - 0x78], xmm0
cage_L36:
movsd	qword ptr [rsi - 0x68], xmm1
cage_L3b:
movsd	qword ptr [rsi + 0x70], xmm5
cage_L40:
movupd	xmmword ptr [rsp], xmm0
cage_L45:
movsd	qword ptr [rsp + 0x10], xmm1
cage_L4b:
mov	edx, dword ptr [rdi - 0x50]
cage_L4e:
cmp	edx, 0x2
cage_L51:
jge	cage_L58
cage_L53:
mov	edx, 0x2
cage_L58:
cmp	edx, 0x3e8
cage_L5e:
jle	cage_L65
cage_L60:
mov	edx, 0x3e8
cage_L65:
mov	dword ptr [rsp + 0x34], edx
cage_L69:
fld	qword ptr [rdi - 0x10]
cage_L6c:
fld	st(0)
cage_L6e:
fchs
cage_L70:
fstp	qword ptr [rsp + 0x20]
cage_L74:
fidiv	dword ptr [rsp + 0x34]
cage_L78:
fmul	qword ptr [rdi + 0x18]
cage_L7b:
fstp	qword ptr [rsp + 0x18]
cage_L7f:
shr	edx
cage_L81:
fld	qword ptr [rsp]
cage_L84:
fld	qword ptr [rsp + 0x8]
cage_L88:
fpatan
cage_L8a:
fsubr	qword ptr [rdi + 0x10]
cage_L8d:
fmul	qword ptr [rdi]
cage_L8f:
fimul	dword ptr [rdi - 0x54]
cage_L92:
frndint
cage_L94:
fidiv	dword ptr [rdi - 0x54]
cage_L97:
fmul	qword ptr [rdi + 0x8]
cage_L9a:
fsincos
cage_L9c:
fstp	qword ptr [rsp + 0x28]
cage_La0:
fstp	qword ptr [rsp + 0x30]
cage_La4:
fld	qword ptr [rsp]
cage_La7:
fmul	qword ptr [rsp + 0x28]
cage_Lab:
fld	qword ptr [rsp + 0x8]
cage_Laf:
fmul	qword ptr [rsp + 0x30]
cage_Lb3:
faddp	st(1), st
cage_Lb5:
fmul	st, st(0)
cage_Lb7:
fld	qword ptr [rsp + 0x10]
cage_Lbb:
fmul	st, st(0)
cage_Lbd:
faddp	st(1), st
cage_Lbf:
fsqrt
cage_Lc1:
fsub	qword ptr [rdi - 0x10]
cage_Lc4:
fmul	st, st(0)
cage_Lc6:
fld	qword ptr [rsp]
cage_Lc9:
fmul	qword ptr [rsp + 0x30]
cage_Lcd:
fld	qword ptr [rsp + 0x8]
cage_Ld1:
fmul	qword ptr [rsp + 0x28]
cage_Ld5:
fchs
cage_Ld7:
faddp	st(1), st
cage_Ld9:
fmul	st, st(0)
cage_Ldb:
faddp	st(1), st
cage_Ldd:
fsqrt
cage_Ldf:
fsub	qword ptr [rdi - 0x48]
cage_Le2:
fld	qword ptr [rsp + 0x10]
cage_Le6:
fabs
cage_Le8:
fsub	qword ptr [rdi - 0x10]
cage_Leb:
fstp	qword ptr [rsp + 0x10]
cage_Lef:
fstp	qword ptr [rsi - 0x20]
cage_Lf2:
dec	edx
cage_Lf3:
fld	qword ptr [rsp + 0x18]
cage_Lf7:
fld	st(0)
cage_Lf9:
fadd	qword ptr [rsp + 0x10]
cage_Lfd:
fstp	qword ptr [rsp + 0x10]
cage_L101:
fadd	qword ptr [rsp + 0x20]
cage_L105:
fstp	qword ptr [rsp + 0x20]
cage_L109:
fld	qword ptr [rsp]
cage_L10c:
fmul	st, st(0)
cage_L10e:
fld	qword ptr [rsp + 0x8]
cage_L112:
fmul	st, st(0)
cage_L114:
faddp	st(1), st
cage_L116:
fsqrt
cage_L118:
fld	qword ptr [rdi - 0x10]
cage_L11b:
fmul	st, st(0)
cage_L11d:
fld	qword ptr [rsp + 0x20]
cage_L121:
fmul	st, st(0)
cage_L123:
fchs
cage_L125:
faddp	st(1), st
cage_L127:
fsqrt
cage_L129:
fchs
cage_L12b:
faddp	st(1), st
cage_L12d:
fmul	st, st(0)
cage_L12f:
fld	qword ptr [rsp + 0x10]
cage_L133:
fmul	st, st(0)
cage_L135:
faddp	st(1), st
cage_L137:
fsqrt
cage_L139:
fsub	qword ptr [rdi - 0x48]
cage_L13c:
fld	qword ptr [rsi - 0x20]
cage_L13f:
fcom	st(1)
cage_L141:
wait
cage_L142:
fnstsw	ax
cage_L144:
shr	ah
cage_L146:
jae	cage_L14c
cage_L148:
fstp	st(1)
cage_L14a:
jmp	cage_L14e
cage_L14c:
fstp	st(0)
cage_L14e:
cmp	edx, 0x0
cage_L151:
jg	cage_Lef
cage_L153:
cmp	dword ptr [rdi - 0x4c], 0x0
cage_L157:
jne	cage_L15c
cage_L159:
fdiv	qword ptr [rdi - 0x20]
cage_L15c:
fstp	qword ptr [rsi - 0x20]
cage_L15f:
add	rsp, 0x3c
cage_L162:
ret
