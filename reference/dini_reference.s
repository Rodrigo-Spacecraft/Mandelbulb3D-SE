.intel_syntax noprefix
.text
.globl _dini_reference
_dini_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
dini_L0:
add	rsp, -0x46
dini_L3:
movupd	xmm0, xmmword ptr [rsi - 0x78]
dini_L8:
movsd	xmm1, qword ptr [rsi - 0x68]
dini_Ld:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
dini_L12:
mulsd	xmm1, qword ptr [rdi - 0x20]
dini_L17:
addpd	xmm0, xmmword ptr [rdi - 0x40]
dini_L1c:
addsd	xmm1, qword ptr [rdi - 0x30]
dini_L21:
cmp	dword ptr [rdi - 0x4c], 0x0
dini_L25:
je	dini_L40
dini_L27:
movsd	xmm5, qword ptr [rsi + 0x70]
dini_L2c:
mulsd	xmm5, qword ptr [rdi - 0x20]
dini_L31:
movupd	xmmword ptr [rsi - 0x78], xmm0
dini_L36:
movsd	qword ptr [rsi - 0x68], xmm1
dini_L3b:
movsd	qword ptr [rsi + 0x70], xmm5
dini_L40:
movupd	xmmword ptr [rsp], xmm0
dini_L45:
movsd	qword ptr [rsp + 0x10], xmm1
dini_L4b:
fld	qword ptr [rdi + 0x10]
dini_L4e:
fstp	qword ptr [rsp + 0x28]
dini_L52:
cmp	dword ptr [rdi - 0x60], 0x1
dini_L56:
jne	dini_L66
dini_L58:
fld	qword ptr [rsp]
dini_L5b:
fld	qword ptr [rsp + 0x10]
dini_L5f:
fstp	qword ptr [rsp]
dini_L62:
fstp	qword ptr [rsp + 0x10]
dini_L66:
cmp	dword ptr [rdi - 0x60], -0x1
dini_L6a:
jne	dini_L7c
dini_L6c:
fld	qword ptr [rsp + 0x8]
dini_L70:
fld	qword ptr [rsp + 0x10]
dini_L74:
fstp	qword ptr [rsp + 0x8]
dini_L78:
fstp	qword ptr [rsp + 0x10]
dini_L7c:
cmp	dword ptr [rdi - 0x64], 0x0
dini_L80:
je	dini_L8c
dini_L82:
fld	qword ptr [rsp + 0x10]
dini_L86:
fchs
dini_L88:
fstp	qword ptr [rsp + 0x10]
dini_L8c:
mov	edx, 0x3
dini_L91:
fld	qword ptr [rsp + 0x8]
dini_L95:
fchs
dini_L97:
fstp	qword ptr [rsp + 0x20]
dini_L9b:
fld	qword ptr [rsp]
dini_L9e:
fchs
dini_La0:
fstp	qword ptr [rsp + 0x30]
dini_La4:
fld	qword ptr [rsp + 0x8]
dini_La8:
fsub	qword ptr [rsp]
dini_Lab:
fld	qword ptr [rsp + 0x8]
dini_Laf:
fadd	qword ptr [rsp]
dini_Lb2:
fpatan
dini_Lb4:
fmul	qword ptr [rdi - 0x6c]
dini_Lb7:
fstp	qword ptr [rsp + 0x18]
dini_Lbb:
fld	qword ptr [rsp]
dini_Lbe:
fmul	st, st(0)
dini_Lc0:
fld	qword ptr [rsp + 0x8]
dini_Lc4:
fmul	st, st(0)
dini_Lc6:
faddp	st(1), st
dini_Lc8:
fst	qword ptr [rsp + 0x8]
dini_Lcc:
fsqrt
dini_Lce:
fstp	qword ptr [rsp]
dini_Ld1:
fld	qword ptr [rdi - 0x10]
dini_Ld4:
fmul	st, st(0)
dini_Ld6:
fsub	qword ptr [rsp + 0x8]
dini_Lda:
fld	st(0)
dini_Ldc:
fabs
dini_Lde:
faddp	st(1), st
dini_Le0:
fsqrt
dini_Le2:
fld	st(0)
dini_Le4:
fadd	qword ptr [rdi - 0x10]
dini_Le7:
fdiv	qword ptr [rsp]
dini_Lea:
fldln2
dini_Lec:
fxch	st(1)
dini_Lee:
fyl2x
dini_Lf0:
fmul	qword ptr [rdi - 0x10]
dini_Lf3:
fxch	st(1)
dini_Lf5:
fchs
dini_Lf7:
faddp	st(1), st
dini_Lf9:
fsub	qword ptr [rsp + 0x18]
dini_Lfd:
fsub	qword ptr [rsp + 0x10]
dini_L101:
fabs
dini_L103:
fsub	qword ptr [rdi - 0x54]
dini_L106:
fld	qword ptr [rsp]
dini_L109:
fmul	qword ptr [rdi]
dini_L10b:
fadd	qword ptr [rdi + 0x8]
dini_L10e:
fabs
dini_L110:
fmulp	st(1), st
dini_L112:
fld	qword ptr [rsp]
dini_L115:
fsub	qword ptr [rdi - 0x48]
dini_L118:
fcom	st(1)
dini_L11a:
wait
dini_L11b:
fnstsw	ax
dini_L11d:
shr	ah
dini_L11f:
jae	dini_L125
dini_L121:
fstp	st(0)
dini_L123:
jmp	dini_L127
dini_L125:
fstp	st(1)
dini_L127:
fld	qword ptr [rsp]
dini_L12a:
fsubr	qword ptr [rdi - 0x5c]
dini_L12d:
fcom	st(1)
dini_L12f:
wait
dini_L130:
fnstsw	ax
dini_L132:
shr	ah
dini_L134:
jae	dini_L13a
dini_L136:
fstp	st(0)
dini_L138:
jmp	dini_L13c
dini_L13a:
fstp	st(1)
dini_L13c:
fld	qword ptr [rsp + 0x20]
dini_L140:
fcom	st(1)
dini_L142:
wait
dini_L143:
fnstsw	ax
dini_L145:
shr	ah
dini_L147:
jae	dini_L14d
dini_L149:
fstp	st(0)
dini_L14b:
jmp	dini_L14f
dini_L14d:
fstp	st(1)
dini_L14f:
fcom	qword ptr [rsp + 0x28]
dini_L153:
wait
dini_L154:
fnstsw	ax
dini_L156:
shr	ah
dini_L158:
jae	dini_L160
dini_L15a:
fstp	qword ptr [rsp + 0x28]
dini_L15e:
jmp	dini_L162
dini_L160:
fstp	st(0)
dini_L162:
fld	qword ptr [rsp + 0x30]
dini_L166:
fstp	qword ptr [rsp]
dini_L169:
fld	qword ptr [rsp + 0x20]
dini_L16d:
fstp	qword ptr [rsp + 0x8]
dini_L171:
fld	qword ptr [rsp + 0x10]
dini_L175:
fld	qword ptr [rdi - 0x6c]
dini_L178:
fldpi
dini_L17a:
fmulp	st(1), st
dini_L17c:
faddp	st(1), st
dini_L17e:
fstp	qword ptr [rsp + 0x10]
dini_L182:
dec	edx
dini_L183:
jg	dini_L91
dini_L189:
fld	qword ptr [rsp + 0x28]
dini_L18d:
cmp	dword ptr [rdi - 0x4c], 0x0
dini_L191:
jne	dini_L196
dini_L193:
fdiv	qword ptr [rdi - 0x20]
dini_L196:
fstp	qword ptr [rsi - 0x20]
dini_L199:
add	rsp, 0x46
dini_L19c:
ret
