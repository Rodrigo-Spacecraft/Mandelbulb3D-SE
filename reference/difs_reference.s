.intel_syntax noprefix
.text
.globl _trifoliumIFS_reference
_trifoliumIFS_reference:
trifoliumIFS_L0:
add	rsp, -0x30
trifoliumIFS_L3:
movupd	xmm0, xmmword ptr [rsi - 0x78]
trifoliumIFS_L8:
movsd	xmm1, qword ptr [rsi - 0x68]
trifoliumIFS_Ld:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
trifoliumIFS_L12:
mulsd	xmm1, qword ptr [rdi - 0x20]
trifoliumIFS_L17:
addpd	xmm0, xmmword ptr [rdi - 0x40]
trifoliumIFS_L1c:
addsd	xmm1, qword ptr [rdi - 0x30]
trifoliumIFS_L21:
cmp	dword ptr [rdi - 0x4c], 0x0
trifoliumIFS_L25:
je	trifoliumIFS_L40
trifoliumIFS_L27:
movsd	xmm5, qword ptr [rsi + 0x70]
trifoliumIFS_L2c:
mulsd	xmm5, qword ptr [rdi - 0x20]
trifoliumIFS_L31:
movupd	xmmword ptr [rsi - 0x78], xmm0
trifoliumIFS_L36:
movsd	qword ptr [rsi - 0x68], xmm1
trifoliumIFS_L3b:
movsd	qword ptr [rsi + 0x70], xmm5
trifoliumIFS_L40:
movupd	xmmword ptr [rsp], xmm0
trifoliumIFS_L45:
movsd	qword ptr [rsp + 0x10], xmm1
trifoliumIFS_L4b:
fldz
trifoliumIFS_L4d:
fst	qword ptr [rsp + 0x18]
trifoliumIFS_L51:
fstp	qword ptr [rsp + 0x20]
trifoliumIFS_L55:
add	rdi, -0x2c
trifoliumIFS_L58:
fld	qword ptr [rsp + 0x10]
trifoliumIFS_L5c:
fld	qword ptr [rsp + 0x8]
trifoliumIFS_L60:
fld	qword ptr [rsp]
trifoliumIFS_L63:
fld	st(0)
trifoliumIFS_L65:
fmul	dword ptr [rdi - 0x3c]
trifoliumIFS_L68:
fld	st(2)
trifoliumIFS_L6a:
fmul	dword ptr [rdi - 0x40]
trifoliumIFS_L6d:
faddp	st(1), st
trifoliumIFS_L6f:
fld	st(3)
trifoliumIFS_L71:
fmul	dword ptr [rdi - 0x44]
trifoliumIFS_L74:
faddp	st(1), st
trifoliumIFS_L76:
fld	st(1)
trifoliumIFS_L78:
fmul	dword ptr [rdi - 0x24]
trifoliumIFS_L7b:
fld	st(3)
trifoliumIFS_L7d:
fmul	dword ptr [rdi - 0x28]
trifoliumIFS_L80:
faddp	st(1), st
trifoliumIFS_L82:
fld	st(4)
trifoliumIFS_L84:
fmul	dword ptr [rdi - 0x2c]
trifoliumIFS_L87:
faddp	st(1), st
trifoliumIFS_L89:
fxch	st(2)
trifoliumIFS_L8b:
fmul	dword ptr [rdi - 0x30]
trifoliumIFS_L8e:
fxch	st(3)
trifoliumIFS_L90:
fmul	dword ptr [rdi - 0x34]
trifoliumIFS_L93:
faddp	st(3), st
trifoliumIFS_L95:
fxch	st(3)
trifoliumIFS_L97:
fmul	dword ptr [rdi - 0x38]
trifoliumIFS_L9a:
faddp	st(2), st
trifoliumIFS_L9c:
fstp	qword ptr [rsp]
trifoliumIFS_L9f:
fstp	qword ptr [rsp + 0x8]
trifoliumIFS_La3:
fstp	qword ptr [rsp + 0x10]
trifoliumIFS_La7:
add	rdi, 0x2c
trifoliumIFS_Laa:
fld	qword ptr [rsp]
trifoliumIFS_Lad:
fmul	st, st(0)
trifoliumIFS_Laf:
fld	qword ptr [rsp + 0x8]
trifoliumIFS_Lb3:
fmul	st, st(0)
trifoliumIFS_Lb5:
faddp	st(1), st
trifoliumIFS_Lb7:
fmul	st, st(0)
trifoliumIFS_Lb9:
fld	qword ptr [rsp + 0x10]
trifoliumIFS_Lbd:
fmul	st, st(0)
trifoliumIFS_Lbf:
fmul	qword ptr [rsp + 0x10]
trifoliumIFS_Lc3:
fmul	qword ptr [rdi - 0x10]
trifoliumIFS_Lc6:
fabs
trifoliumIFS_Lc8:
faddp	st(1), st
trifoliumIFS_Lca:
fstp	qword ptr [rsp + 0x20]
trifoliumIFS_Lce:
nop
trifoliumIFS_Lcf:
fld	qword ptr [rsp]
trifoliumIFS_Ld2:
fld	st(0)
trifoliumIFS_Ld4:
fmul	st, st(0)
trifoliumIFS_Ld6:
fld	qword ptr [rsp + 0x8]
trifoliumIFS_Lda:
fmul	st, st(0)
trifoliumIFS_Ldc:
fmul	qword ptr [rdi]
trifoliumIFS_Lde:
faddp	st(1), st
trifoliumIFS_Le0:
fmulp	st(1), st
trifoliumIFS_Le2:
fmul	qword ptr [rdi - 0x48]
trifoliumIFS_Le5:
ftst
trifoliumIFS_Le7:
wait
trifoliumIFS_Le8:
fnstsw	ax
trifoliumIFS_Lea:
shr	ah
trifoliumIFS_Lec:
jbe	trifoliumIFS_Lf8
trifoliumIFS_Lee:
fadd	qword ptr [rsp + 0x20]
trifoliumIFS_Lf2:
fstp	qword ptr [rsp + 0x20]
trifoliumIFS_Lf6:
jmp	trifoliumIFS_L100
trifoliumIFS_Lf8:
fsubr	qword ptr [rsp + 0x18]
trifoliumIFS_Lfc:
fstp	qword ptr [rsp + 0x18]
trifoliumIFS_L100:
fld	qword ptr [rsp + 0x20]
trifoliumIFS_L104:
fsqrt
trifoliumIFS_L106:
fsqrt
trifoliumIFS_L108:
fld	qword ptr [rsp + 0x18]
trifoliumIFS_L10c:
fsqrt
trifoliumIFS_L10e:
fsqrt
trifoliumIFS_L110:
fchs
trifoliumIFS_L112:
faddp	st(1), st
trifoliumIFS_L114:
fmul	qword ptr [rdi + 0x8]
trifoliumIFS_L117:
fld	qword ptr [rsp + 0x10]
trifoliumIFS_L11b:
fabs
trifoliumIFS_L11d:
fsub	qword ptr [rdi + 0x10]
trifoliumIFS_L120:
fcom	st(1)
trifoliumIFS_L122:
wait
trifoliumIFS_L123:
fnstsw	ax
trifoliumIFS_L125:
shr	ah
trifoliumIFS_L127:
jae	trifoliumIFS_L12d
trifoliumIFS_L129:
fstp	st(0)
trifoliumIFS_L12b:
jmp	trifoliumIFS_L12f
trifoliumIFS_L12d:
fstp	st(1)
trifoliumIFS_L12f:
cmp	dword ptr [rdi - 0x4c], 0x0
trifoliumIFS_L133:
jne	trifoliumIFS_L138
trifoliumIFS_L135:
fdiv	qword ptr [rdi - 0x20]
trifoliumIFS_L138:
fstp	qword ptr [rsi - 0x20]
trifoliumIFS_L13b:
fld	qword ptr [rsp]
trifoliumIFS_L13e:
fmul	st, st(0)
trifoliumIFS_L140:
fld	qword ptr [rsp + 0x8]
trifoliumIFS_L144:
fmul	st, st(0)
trifoliumIFS_L146:
faddp	st(1), st
trifoliumIFS_L148:
fld	qword ptr [rsp + 0x10]
trifoliumIFS_L14c:
fmul	st, st(0)
trifoliumIFS_L14e:
faddp	st(1), st
trifoliumIFS_L150:
fsqrt
trifoliumIFS_L152:
fmul	qword ptr [rdi - 0x78]
trifoliumIFS_L155:
fild	dword ptr [rsi - 0x18]
trifoliumIFS_L158:
fmul	qword ptr [rdi - 0x80]
trifoliumIFS_L15b:
faddp	st(1), st
trifoliumIFS_L15d:
fadd	qword ptr [rdi - 0x88]
trifoliumIFS_L163:
fabs
trifoliumIFS_L165:
fstp	qword ptr [rsi + 0x80]
trifoliumIFS_L16b:
add	rsp, 0x30
trifoliumIFS_L16e:
ret
.globl _helistairsIFS_reference
_helistairsIFS_reference:
helistairsIFS_L0:
add	rsp, -0x50
helistairsIFS_L3:
movupd	xmm0, xmmword ptr [rsi - 0x78]
helistairsIFS_L8:
movsd	xmm1, qword ptr [rsi - 0x68]
helistairsIFS_Ld:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
helistairsIFS_L12:
mulsd	xmm1, qword ptr [rdi - 0x20]
helistairsIFS_L17:
addpd	xmm0, xmmword ptr [rdi - 0x40]
helistairsIFS_L1c:
addsd	xmm1, qword ptr [rdi - 0x30]
helistairsIFS_L21:
cmp	dword ptr [rdi - 0x44], 0x0
helistairsIFS_L25:
je	helistairsIFS_L40
helistairsIFS_L27:
movsd	xmm5, qword ptr [rsi + 0x70]
helistairsIFS_L2c:
mulsd	xmm5, qword ptr [rdi - 0x20]
helistairsIFS_L31:
movupd	xmmword ptr [rsi - 0x78], xmm0
helistairsIFS_L36:
movsd	qword ptr [rsi - 0x68], xmm1
helistairsIFS_L3b:
movsd	qword ptr [rsi + 0x70], xmm5
helistairsIFS_L40:
movupd	xmmword ptr [rsp], xmm0
helistairsIFS_L45:
movsd	qword ptr [rsp + 0x10], xmm1
helistairsIFS_L4b:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L4f:
fld	qword ptr [rsp + 0x8]
helistairsIFS_L53:
fld	qword ptr [rsp]
helistairsIFS_L56:
fld	st(0)
helistairsIFS_L58:
fmul	dword ptr [rdi - 0x68]
helistairsIFS_L5b:
fld	st(2)
helistairsIFS_L5d:
fmul	dword ptr [rdi - 0x6c]
helistairsIFS_L60:
faddp	st(1), st
helistairsIFS_L62:
fld	st(3)
helistairsIFS_L64:
fmul	dword ptr [rdi - 0x70]
helistairsIFS_L67:
faddp	st(1), st
helistairsIFS_L69:
fld	st(1)
helistairsIFS_L6b:
fmul	dword ptr [rdi - 0x50]
helistairsIFS_L6e:
fld	st(3)
helistairsIFS_L70:
fmul	dword ptr [rdi - 0x54]
helistairsIFS_L73:
faddp	st(1), st
helistairsIFS_L75:
fld	st(4)
helistairsIFS_L77:
fmul	dword ptr [rdi - 0x58]
helistairsIFS_L7a:
faddp	st(1), st
helistairsIFS_L7c:
fxch	st(2)
helistairsIFS_L7e:
fmul	dword ptr [rdi - 0x5c]
helistairsIFS_L81:
fxch	st(3)
helistairsIFS_L83:
fmul	dword ptr [rdi - 0x60]
helistairsIFS_L86:
faddp	st(3), st
helistairsIFS_L88:
fxch	st(3)
helistairsIFS_L8a:
fmul	dword ptr [rdi - 0x64]
helistairsIFS_L8d:
faddp	st(2), st
helistairsIFS_L8f:
fstp	qword ptr [rsp]
helistairsIFS_L92:
fstp	qword ptr [rsp + 0x8]
helistairsIFS_L96:
fstp	qword ptr [rsp + 0x10]
helistairsIFS_L9a:
fld	qword ptr [rdi - 0x8c]
helistairsIFS_La0:
ftst
helistairsIFS_La2:
wait
helistairsIFS_La3:
fnstsw	ax
helistairsIFS_La5:
and	ah, 0x41
helistairsIFS_La8:
jne	helistairsIFS_Lbb
helistairsIFS_Laa:
fld	qword ptr [rsp]
helistairsIFS_Lad:
fmul	st, st(0)
helistairsIFS_Laf:
fld	qword ptr [rsp + 0x8]
helistairsIFS_Lb3:
fmul	st, st(0)
helistairsIFS_Lb5:
faddp	st(1), st
helistairsIFS_Lb7:
fsqrt
helistairsIFS_Lb9:
jmp	helistairsIFS_Ld6
helistairsIFS_Lbb:
fld	qword ptr [rsp]
helistairsIFS_Lbe:
fabs
helistairsIFS_Lc0:
fld	qword ptr [rsp + 0x8]
helistairsIFS_Lc4:
fabs
helistairsIFS_Lc6:
fcom	st(1)
helistairsIFS_Lc8:
wait
helistairsIFS_Lc9:
fnstsw	ax
helistairsIFS_Lcb:
and	ah, 0x41
helistairsIFS_Lce:
jne	helistairsIFS_Ld4
helistairsIFS_Ld0:
fstp	st(1)
helistairsIFS_Ld2:
jmp	helistairsIFS_Ld6
helistairsIFS_Ld4:
fstp	st(0)
helistairsIFS_Ld6:
fstp	st(1)
helistairsIFS_Ld8:
fld	qword ptr [rsp + 0x8]
helistairsIFS_Ldc:
fld	qword ptr [rsp]
helistairsIFS_Ldf:
fpatan
helistairsIFS_Le1:
fmul	qword ptr [rdi + 0x8]
helistairsIFS_Le4:
fimul	dword ptr [rdi - 0x74]
helistairsIFS_Le7:
fist	dword ptr [rsp + 0x18]
helistairsIFS_Leb:
fild	dword ptr [rsp + 0x18]
helistairsIFS_Lef:
fsubp	st(1), st
helistairsIFS_Lf1:
fmul	qword ptr [rdi + 0x10]
helistairsIFS_Lf4:
fidiv	dword ptr [rdi - 0x74]
helistairsIFS_Lf7:
fstp	qword ptr [rsp + 0x8]
helistairsIFS_Lfb:
fstp	qword ptr [rsp]
helistairsIFS_Lfe:
fld	qword ptr [rdi - 0x7c]
helistairsIFS_L101:
fabs
helistairsIFS_L103:
fchs
helistairsIFS_L105:
fld	st(0)
helistairsIFS_L107:
fmul	qword ptr [rdi + 0x18]
helistairsIFS_L10a:
fstp	qword ptr [rsp + 0x28]
helistairsIFS_L10e:
fimul	dword ptr [rdi - 0x74]
helistairsIFS_L111:
fabs
helistairsIFS_L113:
fstp	qword ptr [rsp + 0x20]
helistairsIFS_L117:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L11b:
fild	dword ptr [rsp + 0x18]
helistairsIFS_L11f:
fld	qword ptr [rdi - 0x7c]
helistairsIFS_L122:
fabs
helistairsIFS_L124:
fchs
helistairsIFS_L126:
fmulp	st(1), st
helistairsIFS_L128:
faddp	st(1), st
helistairsIFS_L12a:
fld	st(0)
helistairsIFS_L12c:
fdiv	qword ptr [rsp + 0x20]
helistairsIFS_L130:
frndint
helistairsIFS_L132:
fmul	qword ptr [rsp + 0x20]
helistairsIFS_L136:
fsubp	st(1), st
helistairsIFS_L138:
fstp	qword ptr [rsp + 0x10]
helistairsIFS_L13c:
mov	eax, dword ptr [rdi - 0x78]
helistairsIFS_L13f:
and	eax, 0x80000000
helistairsIFS_L144:
je	helistairsIFS_L192
helistairsIFS_L146:
fld	qword ptr [rsp + 0x8]
helistairsIFS_L14a:
fsub	qword ptr [rsp + 0x28]
helistairsIFS_L14e:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L152:
fchs
helistairsIFS_L154:
fcompp
helistairsIFS_L156:
wait
helistairsIFS_L157:
fnstsw	ax
helistairsIFS_L159:
and	ah, 0x41
helistairsIFS_L15c:
jne	helistairsIFS_L168
helistairsIFS_L15e:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L162:
fsub	qword ptr [rsp + 0x28]
helistairsIFS_L166:
jmp	helistairsIFS_L190
helistairsIFS_L168:
fld	qword ptr [rsp + 0x8]
helistairsIFS_L16c:
fadd	qword ptr [rsp + 0x28]
helistairsIFS_L170:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L174:
fchs
helistairsIFS_L176:
fcompp
helistairsIFS_L178:
wait
helistairsIFS_L179:
fnstsw	ax
helistairsIFS_L17b:
and	ah, 0x41
helistairsIFS_L17e:
je	helistairsIFS_L18a
helistairsIFS_L180:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L184:
fadd	qword ptr [rsp + 0x28]
helistairsIFS_L188:
jmp	helistairsIFS_L190
helistairsIFS_L18a:
fld	qword ptr [rsp + 0x8]
helistairsIFS_L18e:
fchs
helistairsIFS_L190:
jmp	helistairsIFS_L208
helistairsIFS_L192:
mov	eax, dword ptr [rsp + 0x14]
helistairsIFS_L196:
and	eax, 0x80000000
helistairsIFS_L19b:
fld	qword ptr [rsp + 0x10]
helistairsIFS_L19f:
fabs
helistairsIFS_L1a1:
fadd	qword ptr [rsp + 0x28]
helistairsIFS_L1a5:
fabs
helistairsIFS_L1a7:
fld	qword ptr [rsp + 0x8]
helistairsIFS_L1ab:
test	eax, eax
helistairsIFS_L1ad:
jne	helistairsIFS_L1b1
helistairsIFS_L1af:
fchs
helistairsIFS_L1b1:
fcom	st(1)
helistairsIFS_L1b3:
wait
helistairsIFS_L1b4:
fnstsw	ax
helistairsIFS_L1b6:
and	ah, 0x41
helistairsIFS_L1b9:
jne	helistairsIFS_L1bf
helistairsIFS_L1bb:
fstp	st(1)
helistairsIFS_L1bd:
jmp	helistairsIFS_L1c1
helistairsIFS_L1bf:
fstp	st(0)
helistairsIFS_L1c1:
fsub	qword ptr [rdi - 0x84]
helistairsIFS_L1c7:
fld	qword ptr [rsp]
helistairsIFS_L1ca:
fld	qword ptr [rdi - 0x8c]
helistairsIFS_L1d0:
fabs
helistairsIFS_L1d2:
fsubp	st(1), st
helistairsIFS_L1d4:
fst	qword ptr [rsi - 0x20]
helistairsIFS_L1d7:
fsub	qword ptr [rdi - 0x94]
helistairsIFS_L1dd:
fcom	st(1)
helistairsIFS_L1df:
wait
helistairsIFS_L1e0:
fnstsw	ax
helistairsIFS_L1e2:
and	ah, 0x41
helistairsIFS_L1e5:
jne	helistairsIFS_L1eb
helistairsIFS_L1e7:
fstp	st(1)
helistairsIFS_L1e9:
jmp	helistairsIFS_L1ed
helistairsIFS_L1eb:
fstp	st(0)
helistairsIFS_L1ed:
fld	qword ptr [rsi - 0x20]
helistairsIFS_L1f0:
fadd	qword ptr [rdi - 0x94]
helistairsIFS_L1f6:
fcom	st(1)
helistairsIFS_L1f8:
wait
helistairsIFS_L1f9:
fnstsw	ax
helistairsIFS_L1fb:
and	ah, 0x41
helistairsIFS_L1fe:
je	helistairsIFS_L204
helistairsIFS_L200:
fstp	st(1)
helistairsIFS_L202:
jmp	helistairsIFS_L206
helistairsIFS_L204:
fstp	st(0)
helistairsIFS_L206:
jmp	helistairsIFS_L235
helistairsIFS_L208:
fabs
helistairsIFS_L20a:
fsub	qword ptr [rdi - 0x84]
helistairsIFS_L210:
fld	qword ptr [rsp]
helistairsIFS_L213:
fld	qword ptr [rdi - 0x8c]
helistairsIFS_L219:
fabs
helistairsIFS_L21b:
fsubp	st(1), st
helistairsIFS_L21d:
fabs
helistairsIFS_L21f:
fsub	qword ptr [rdi - 0x94]
helistairsIFS_L225:
fcom	st(1)
helistairsIFS_L227:
wait
helistairsIFS_L228:
fnstsw	ax
helistairsIFS_L22a:
and	ah, 0x41
helistairsIFS_L22d:
jne	helistairsIFS_L233
helistairsIFS_L22f:
fstp	st(1)
helistairsIFS_L231:
jmp	helistairsIFS_L235
helistairsIFS_L233:
fstp	st(0)
helistairsIFS_L235:
cmp	dword ptr [rdi - 0x44], 0x0
helistairsIFS_L239:
jne	helistairsIFS_L23e
helistairsIFS_L23b:
fdiv	qword ptr [rdi - 0x20]
helistairsIFS_L23e:
fstp	qword ptr [rsi - 0x20]
helistairsIFS_L241:
fld	qword ptr [rdi - 0x10]
helistairsIFS_L244:
fild	dword ptr [rsi - 0x18]
helistairsIFS_L247:
fmul	qword ptr [rdi - 0x4c]
helistairsIFS_L24a:
faddp	st(1), st
helistairsIFS_L24c:
fabs
helistairsIFS_L24e:
fstp	qword ptr [rsi + 0x80]
helistairsIFS_L254:
add	rsp, 0x50
helistairsIFS_L257:
ret
.globl _hextgrid2IFS_reference
_hextgrid2IFS_reference:
hextgrid2IFS_L0:
add	rsp, -0x32
hextgrid2IFS_L3:
movupd	xmm0, xmmword ptr [rsi - 0x78]
hextgrid2IFS_L8:
movsd	xmm1, qword ptr [rsi - 0x68]
hextgrid2IFS_Ld:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
hextgrid2IFS_L12:
mulsd	xmm1, qword ptr [rdi - 0x20]
hextgrid2IFS_L17:
addpd	xmm0, xmmword ptr [rdi - 0x40]
hextgrid2IFS_L1c:
addsd	xmm1, qword ptr [rdi - 0x30]
hextgrid2IFS_L21:
cmp	dword ptr [rdi - 0x4c], 0x0
hextgrid2IFS_L25:
je	hextgrid2IFS_L40
hextgrid2IFS_L27:
movsd	xmm5, qword ptr [rsi + 0x70]
hextgrid2IFS_L2c:
mulsd	xmm5, qword ptr [rdi - 0x20]
hextgrid2IFS_L31:
movupd	xmmword ptr [rsi - 0x78], xmm0
hextgrid2IFS_L36:
movsd	qword ptr [rsi - 0x68], xmm1
hextgrid2IFS_L3b:
movsd	qword ptr [rsi + 0x70], xmm5
hextgrid2IFS_L40:
movupd	xmmword ptr [rsp], xmm0
hextgrid2IFS_L45:
movsd	qword ptr [rsp + 0x10], xmm1
hextgrid2IFS_L4b:
fldz
hextgrid2IFS_L4d:
fstp	qword ptr [rsp + 0x20]
hextgrid2IFS_L51:
add	rdi, -0x2c
hextgrid2IFS_L54:
fld	qword ptr [rsp + 0x10]
hextgrid2IFS_L58:
fld	qword ptr [rsp + 0x8]
hextgrid2IFS_L5c:
fld	qword ptr [rsp]
hextgrid2IFS_L5f:
fld	st(0)
hextgrid2IFS_L61:
fmul	dword ptr [rdi - 0x3c]
hextgrid2IFS_L64:
fld	st(2)
hextgrid2IFS_L66:
fmul	dword ptr [rdi - 0x40]
hextgrid2IFS_L69:
faddp	st(1), st
hextgrid2IFS_L6b:
fld	st(3)
hextgrid2IFS_L6d:
fmul	dword ptr [rdi - 0x44]
hextgrid2IFS_L70:
faddp	st(1), st
hextgrid2IFS_L72:
fld	st(1)
hextgrid2IFS_L74:
fmul	dword ptr [rdi - 0x24]
hextgrid2IFS_L77:
fld	st(3)
hextgrid2IFS_L79:
fmul	dword ptr [rdi - 0x28]
hextgrid2IFS_L7c:
faddp	st(1), st
hextgrid2IFS_L7e:
fld	st(4)
hextgrid2IFS_L80:
fmul	dword ptr [rdi - 0x2c]
hextgrid2IFS_L83:
faddp	st(1), st
hextgrid2IFS_L85:
fxch	st(2)
hextgrid2IFS_L87:
fmul	dword ptr [rdi - 0x30]
hextgrid2IFS_L8a:
fxch	st(3)
hextgrid2IFS_L8c:
fmul	dword ptr [rdi - 0x34]
hextgrid2IFS_L8f:
faddp	st(3), st
hextgrid2IFS_L91:
fxch	st(3)
hextgrid2IFS_L93:
fmul	dword ptr [rdi - 0x38]
hextgrid2IFS_L96:
faddp	st(2), st
hextgrid2IFS_L98:
fstp	qword ptr [rsp]
hextgrid2IFS_L9b:
fstp	qword ptr [rsp + 0x8]
hextgrid2IFS_L9f:
fstp	qword ptr [rsp + 0x10]
hextgrid2IFS_La3:
add	rdi, 0x2c
hextgrid2IFS_La6:
fld	qword ptr [rsp + 0x8]
hextgrid2IFS_Laa:
fmul	qword ptr [rdi + 0x8]
hextgrid2IFS_Lad:
frndint
hextgrid2IFS_Laf:
fmul	qword ptr [rdi]
hextgrid2IFS_Lb1:
fadd	qword ptr [rsp + 0x8]
hextgrid2IFS_Lb5:
fabs
hextgrid2IFS_Lb7:
fst	qword ptr [rsp + 0x18]
hextgrid2IFS_Lbb:
fmul	qword ptr [rdi + 0x8]
hextgrid2IFS_Lbe:
fld	qword ptr [rsp]
hextgrid2IFS_Lc1:
fmul	qword ptr [rdi + 0x20]
hextgrid2IFS_Lc4:
frndint
hextgrid2IFS_Lc6:
fmul	qword ptr [rdi + 0x18]
hextgrid2IFS_Lc9:
fld	qword ptr [rsp]
hextgrid2IFS_Lcc:
fmul	qword ptr [rdi + 0x10]
hextgrid2IFS_Lcf:
faddp	st(1), st
hextgrid2IFS_Ld1:
fabs
hextgrid2IFS_Ld3:
faddp	st(1), st
hextgrid2IFS_Ld5:
fld	qword ptr [rsp + 0x18]
hextgrid2IFS_Ld9:
fcom	st(1)
hextgrid2IFS_Ldb:
wait
hextgrid2IFS_Ldc:
fnstsw	ax
hextgrid2IFS_Lde:
shr	ah
hextgrid2IFS_Le0:
jae	hextgrid2IFS_Le6
hextgrid2IFS_Le2:
fstp	st(0)
hextgrid2IFS_Le4:
jmp	hextgrid2IFS_Le8
hextgrid2IFS_Le6:
fstp	st(1)
hextgrid2IFS_Le8:
fsub	qword ptr [rdi - 0x48]
hextgrid2IFS_Leb:
nop
hextgrid2IFS_Lec:
nop
hextgrid2IFS_Led:
nop
hextgrid2IFS_Lee:
fld	qword ptr [rsp + 0x18]
hextgrid2IFS_Lf2:
fcom	st(1)
hextgrid2IFS_Lf4:
wait
hextgrid2IFS_Lf5:
fnstsw	ax
hextgrid2IFS_Lf7:
shr	ah
hextgrid2IFS_Lf9:
jbe	hextgrid2IFS_Lff
hextgrid2IFS_Lfb:
fstp	st(0)
hextgrid2IFS_Lfd:
jmp	hextgrid2IFS_L101
hextgrid2IFS_Lff:
fstp	st(1)
hextgrid2IFS_L101:
fmul	st, st(0)
hextgrid2IFS_L103:
fld	qword ptr [rsp + 0x10]
hextgrid2IFS_L107:
fmul	st, st(0)
hextgrid2IFS_L109:
faddp	st(1), st
hextgrid2IFS_L10b:
fsqrt
hextgrid2IFS_L10d:
fsub	qword ptr [rdi - 0x10]
hextgrid2IFS_L110:
cmp	dword ptr [rdi - 0x4c], 0x0
hextgrid2IFS_L114:
jne	hextgrid2IFS_L119
hextgrid2IFS_L116:
fdiv	qword ptr [rdi - 0x20]
hextgrid2IFS_L119:
fstp	qword ptr [rsi - 0x20]
hextgrid2IFS_L11c:
add	rsp, 0x32
hextgrid2IFS_L11f:
ret
.globl _boardIFS_reference
_boardIFS_reference:
boardIFS_L0:
add	rsp, -0x2c
boardIFS_L3:
movupd	xmm0, xmmword ptr [rsi - 0x78]
boardIFS_L8:
movsd	xmm1, qword ptr [rsi - 0x68]
boardIFS_Ld:
mulpd	xmm0, xmmword ptr [rdi - 0x20]
boardIFS_L12:
mulsd	xmm1, qword ptr [rdi - 0x20]
boardIFS_L17:
addpd	xmm0, xmmword ptr [rdi - 0x40]
boardIFS_L1c:
addsd	xmm1, qword ptr [rdi - 0x30]
boardIFS_L21:
cmp	dword ptr [rdi - 0x4c], 0x0
boardIFS_L25:
je	boardIFS_L40
boardIFS_L27:
movsd	xmm5, qword ptr [rsi + 0x70]
boardIFS_L2c:
mulsd	xmm5, qword ptr [rdi - 0x20]
boardIFS_L31:
movupd	xmmword ptr [rsi - 0x78], xmm0
boardIFS_L36:
movsd	qword ptr [rsi - 0x68], xmm1
boardIFS_L3b:
movsd	qword ptr [rsi + 0x70], xmm5
boardIFS_L40:
movupd	xmmword ptr [rsp], xmm0
boardIFS_L45:
movsd	qword ptr [rsp + 0x10], xmm1
boardIFS_L4b:
nop
boardIFS_L4c:
add	rdi, -0x2c
boardIFS_L4f:
fld	qword ptr [rsp + 0x10]
boardIFS_L53:
fld	qword ptr [rsp + 0x8]
boardIFS_L57:
fld	qword ptr [rsp]
boardIFS_L5a:
fld	st(0)
boardIFS_L5c:
fmul	dword ptr [rdi - 0x3c]
boardIFS_L5f:
fld	st(2)
boardIFS_L61:
fmul	dword ptr [rdi - 0x40]
boardIFS_L64:
faddp	st(1), st
boardIFS_L66:
fld	st(3)
boardIFS_L68:
fmul	dword ptr [rdi - 0x44]
boardIFS_L6b:
faddp	st(1), st
boardIFS_L6d:
fld	st(1)
boardIFS_L6f:
fmul	dword ptr [rdi - 0x24]
boardIFS_L72:
fld	st(3)
boardIFS_L74:
fmul	dword ptr [rdi - 0x28]
boardIFS_L77:
faddp	st(1), st
boardIFS_L79:
fld	st(4)
boardIFS_L7b:
fmul	dword ptr [rdi - 0x2c]
boardIFS_L7e:
faddp	st(1), st
boardIFS_L80:
fxch	st(2)
boardIFS_L82:
fmul	dword ptr [rdi - 0x30]
boardIFS_L85:
fxch	st(3)
boardIFS_L87:
fmul	dword ptr [rdi - 0x34]
boardIFS_L8a:
faddp	st(3), st
boardIFS_L8c:
fxch	st(3)
boardIFS_L8e:
fmul	dword ptr [rdi - 0x38]
boardIFS_L91:
faddp	st(2), st
boardIFS_L93:
fstp	qword ptr [rsp]
boardIFS_L96:
fstp	qword ptr [rsp + 0x8]
boardIFS_L9a:
fstp	qword ptr [rsp + 0x10]
boardIFS_L9e:
add	rdi, 0x2c
boardIFS_La1:
nop
boardIFS_La2:
cmp	dword ptr [rdi - 0x74], 0x1
boardIFS_La6:
jne	boardIFS_Lc9
boardIFS_La8:
fld	qword ptr [rsp]
boardIFS_Lab:
fmul	st, st(0)
boardIFS_Lad:
fld	qword ptr [rsp + 0x8]
boardIFS_Lb1:
fmul	st, st(0)
boardIFS_Lb3:
faddp	st(1), st
boardIFS_Lb5:
fld1
boardIFS_Lb7:
fdivrp	st(1), st
boardIFS_Lb9:
fld	st(0)
boardIFS_Lbb:
fmul	qword ptr [rsp]
boardIFS_Lbe:
fstp	qword ptr [rsp]
boardIFS_Lc1:
fmul	qword ptr [rsp + 0x8]
boardIFS_Lc5:
fstp	qword ptr [rsp + 0x8]
boardIFS_Lc9:
nop
boardIFS_Lca:
cmp	dword ptr [rdi - 0x74], 0x2
boardIFS_Lce:
jne	boardIFS_L10c
boardIFS_Ld0:
fld	qword ptr [rsp]
boardIFS_Ld3:
fmul	st, st(0)
boardIFS_Ld5:
fld	qword ptr [rsp + 0x8]
boardIFS_Ld9:
fld1
boardIFS_Ldb:
faddp	st(1), st
boardIFS_Ldd:
fmul	st, st(0)
boardIFS_Ldf:
faddp	st(1), st
boardIFS_Le1:
fld1
boardIFS_Le3:
fdivrp	st(1), st
boardIFS_Le5:
fld	qword ptr [rsp]
boardIFS_Le8:
fmul	st, st(0)
boardIFS_Lea:
fld	qword ptr [rsp + 0x8]
boardIFS_Lee:
fmul	st, st(0)
boardIFS_Lf0:
faddp	st(1), st
boardIFS_Lf2:
fld1
boardIFS_Lf4:
fsubp	st(1), st
boardIFS_Lf6:
fmul	st, st(1)
boardIFS_Lf8:
fnop
boardIFS_Lfa:
fld	qword ptr [rsp]
boardIFS_Lfd:
fadd	st, st(0)
boardIFS_Lff:
fchs
boardIFS_L101:
fmul	st, st(2)
boardIFS_L103:
fstp	qword ptr [rsp + 0x8]
boardIFS_L107:
fstp	qword ptr [rsp]
boardIFS_L10a:
fstp	st(0)
boardIFS_L10c:
nop
boardIFS_L10d:
cmp	dword ptr [rdi - 0x74], 0x3
boardIFS_L111:
jne	boardIFS_L13a
boardIFS_L113:
fld	qword ptr [rsp]
boardIFS_L116:
fmul	st, st(0)
boardIFS_L118:
fld	qword ptr [rsp + 0x8]
boardIFS_L11c:
fmul	st, st(0)
boardIFS_L11e:
faddp	st(1), st
boardIFS_L120:
fld1
boardIFS_L122:
fxch	st(1)
boardIFS_L124:
fyl2x
boardIFS_L126:
fld1
boardIFS_L128:
fdivrp	st(1), st
boardIFS_L12a:
fld	st(0)
boardIFS_L12c:
fmul	qword ptr [rsp]
boardIFS_L12f:
fstp	qword ptr [rsp]
boardIFS_L132:
fmul	qword ptr [rsp + 0x8]
boardIFS_L136:
fstp	qword ptr [rsp + 0x8]
boardIFS_L13a:
nop
boardIFS_L13b:
cmp	dword ptr [rdi - 0x74], 0x4
boardIFS_L13f:
jne	boardIFS_L162
boardIFS_L141:
fld	qword ptr [rsp]
boardIFS_L144:
fmul	st, st(0)
boardIFS_L146:
fld	qword ptr [rsp + 0x8]
boardIFS_L14a:
fmul	st, st(0)
boardIFS_L14c:
faddp	st(1), st
boardIFS_L14e:
fsqrt
boardIFS_L150:
nop
boardIFS_L151:
nop
boardIFS_L152:
fld	qword ptr [rsp + 0x8]
boardIFS_L156:
fld	qword ptr [rsp]
boardIFS_L159:
fpatan
boardIFS_L15b:
fstp	qword ptr [rsp + 0x8]
boardIFS_L15f:
fstp	qword ptr [rsp]
boardIFS_L162:
fld	qword ptr [rsp]
boardIFS_L165:
fmul	qword ptr [rdi - 0x48]
boardIFS_L168:
fsin
boardIFS_L16a:
fld	qword ptr [rsp + 0x8]
boardIFS_L16e:
fmul	qword ptr [rdi - 0x48]
boardIFS_L171:
fsin
boardIFS_L173:
fmulp	st(1), st
boardIFS_L175:
nop
boardIFS_L176:
ftst
boardIFS_L178:
wait
boardIFS_L179:
fnstsw	ax
boardIFS_L17b:
shr	ah
boardIFS_L17d:
jae	boardIFS_L184
boardIFS_L17f:
fld	qword ptr [rdi - 0x7c]
boardIFS_L182:
jmp	boardIFS_L18a
boardIFS_L184:
fld	qword ptr [rdi - 0x84]
boardIFS_L18a:
fild	dword ptr [rsi - 0x18]
boardIFS_L18d:
fmul	qword ptr [rdi - 0x8c]
boardIFS_L193:
faddp	st(1), st
boardIFS_L195:
fstp	qword ptr [rsi + 0x80]
boardIFS_L19b:
fmul	qword ptr [rdi]
boardIFS_L19d:
fdiv	qword ptr [rdi - 0x48]
boardIFS_L1a0:
nop
boardIFS_L1a1:
fld	qword ptr [rsp + 0x10]
boardIFS_L1a5:
fchs
boardIFS_L1a7:
fst	qword ptr [rsp + 0x10]
boardIFS_L1ab:
fadd	qword ptr [rdi - 0x10]
boardIFS_L1ae:
fcom	st(1)
boardIFS_L1b0:
wait
boardIFS_L1b1:
fnstsw	ax
boardIFS_L1b3:
shr	ah
boardIFS_L1b5:
jae	boardIFS_L1bb
boardIFS_L1b7:
fstp	st(1)
boardIFS_L1b9:
jmp	boardIFS_L1bd
boardIFS_L1bb:
fstp	st(0)
boardIFS_L1bd:
fld	qword ptr [rsp + 0x10]
boardIFS_L1c1:
fcom	st(1)
boardIFS_L1c3:
wait
boardIFS_L1c4:
fnstsw	ax
boardIFS_L1c6:
shr	ah
boardIFS_L1c8:
jae	boardIFS_L1ce
boardIFS_L1ca:
fstp	st(0)
boardIFS_L1cc:
jmp	boardIFS_L1d0
boardIFS_L1ce:
fstp	st(1)
boardIFS_L1d0:
cmp	dword ptr [rdi - 0x4c], 0x0
boardIFS_L1d4:
jne	boardIFS_L1d9
boardIFS_L1d6:
fdiv	qword ptr [rdi - 0x20]
boardIFS_L1d9:
fstp	qword ptr [rsi - 0x20]
boardIFS_L1dc:
add	rsp, 0x2c
boardIFS_L1df:
ret
