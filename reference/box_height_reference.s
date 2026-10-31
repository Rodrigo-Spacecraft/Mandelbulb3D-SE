.intel_syntax noprefix
.text
.globl _BoxIFS_reference
_BoxIFS_reference:
BoxIFS_L0:
movupd	xmm0, xmmword ptr [rsi - 0x78]
BoxIFS_L5:
movsd	xmm1, qword ptr [rsi - 0x68]
BoxIFS_La:
mulpd	xmm0, xmmword ptr [rdi - 0x30]
BoxIFS_Lf:
mulsd	xmm1, qword ptr [rdi - 0x30]
BoxIFS_L14:
addpd	xmm0, xmmword ptr [rdi - 0x50]
BoxIFS_L19:
addsd	xmm1, qword ptr [rdi - 0x40]
BoxIFS_L1e:
cmp	dword ptr [rdi - 0x60], 0x0
BoxIFS_L22:
je	BoxIFS_L3d
BoxIFS_L24:
movsd	xmm5, qword ptr [rsi + 0x70]
BoxIFS_L29:
mulsd	xmm5, qword ptr [rdi - 0x30]
BoxIFS_L2e:
movupd	xmmword ptr [rsi - 0x78], xmm0
BoxIFS_L33:
movsd	qword ptr [rsi - 0x68], xmm1
BoxIFS_L38:
movsd	qword ptr [rsi + 0x70], xmm5
BoxIFS_L3d:
cmp	dword ptr [rdi - 0x5c], 0x0
BoxIFS_L41:
je	BoxIFS_L80
BoxIFS_L43:
add	rsp, -0x18
BoxIFS_L46:
movupd	xmmword ptr [rsp], xmm0
BoxIFS_L4b:
movsd	qword ptr [rsp + 0x10], xmm1
BoxIFS_L51:
fld	dword ptr [rdi - 0x5c]
BoxIFS_L54:
fmul	qword ptr [rsp + 0x10]
BoxIFS_L58:
fsincos
BoxIFS_L5a:
fld	qword ptr [rsp + 0x8]
BoxIFS_L5e:
fld	qword ptr [rsp]
BoxIFS_L61:
fld	st(3)
BoxIFS_L63:
fmul	st, st(1)
BoxIFS_L65:
fld	st(2)
BoxIFS_L67:
fmul	st, st(4)
BoxIFS_L69:
faddp	st(1), st
BoxIFS_L6b:
fstp	qword ptr [rsp]
BoxIFS_L6e:
fmulp	st(2), st
BoxIFS_L70:
fmulp	st(2), st
BoxIFS_L72:
fsubrp	st(1), st
BoxIFS_L74:
fstp	qword ptr [rsp + 0x8]
BoxIFS_L78:
movupd	xmm0, xmmword ptr [rsp]
BoxIFS_L7d:
add	rsp, 0x18
BoxIFS_L80:
movsd	xmm3, xmm1              ## xmm3 = xmm1[0],xmm3[1]
BoxIFS_L84:
andpd	xmm0, xmmword ptr [rdi]
BoxIFS_L88:
andpd	xmm1, xmmword ptr [rdi]
BoxIFS_L8c:
mulsd	xmm3, qword ptr [rdi - 0x58]
BoxIFS_L91:
subpd	xmm0, xmmword ptr [rdi - 0x20]
BoxIFS_L96:
subsd	xmm1, qword ptr [rdi - 0x10]
BoxIFS_L9b:
subsd	xmm0, xmm3
BoxIFS_L9f:
maxsd	xmm1, xmm0
BoxIFS_La3:
unpckhpd	xmm0, xmm0              ## xmm0 = xmm0[1,1]
BoxIFS_La7:
maxsd	xmm1, xmm0
BoxIFS_Lab:
cmp	dword ptr [rdi - 0x60], 0x0
BoxIFS_Laf:
jne	BoxIFS_Lb6
BoxIFS_Lb1:
divsd	xmm1, qword ptr [rdi - 0x30]
BoxIFS_Lb6:
mov	eax, dword ptr [rdi - 0x64]
BoxIFS_Lb9:
movsd	qword ptr [rsi - 0x20], xmm1
BoxIFS_Lbe:
and	eax, 0x3
BoxIFS_Lc1:
fld	qword ptr [rsi + 8*rax - 0x80]
BoxIFS_Lc5:
fmul	dword ptr [rdi - 0x6c]
BoxIFS_Lc8:
fadd	dword ptr [rdi - 0x68]
BoxIFS_Lcb:
fstp	qword ptr [rsi + 0x80]
BoxIFS_Ld1:
ret
.globl _HeightMapIFS_reference
_HeightMapIFS_reference:
HeightMapIFS_L0:
push	rcx
HeightMapIFS_L1:
add	rsp, -0x20
HeightMapIFS_L4:
fld	qword ptr [rsi - 0x68]
HeightMapIFS_L7:
fld	qword ptr [rsi - 0x70]
HeightMapIFS_La:
fld	qword ptr [rsi - 0x78]
HeightMapIFS_Ld:
fld	st(0)
HeightMapIFS_Lf:
fmul	dword ptr [rdi - 0x40]
HeightMapIFS_L12:
fld	st(2)
HeightMapIFS_L14:
fmul	dword ptr [rdi - 0x44]
HeightMapIFS_L17:
faddp	st(1), st
HeightMapIFS_L19:
fld	st(3)
HeightMapIFS_L1b:
fmul	dword ptr [rdi - 0x48]
HeightMapIFS_L1e:
faddp	st(1), st
HeightMapIFS_L20:
fld	st(1)
HeightMapIFS_L22:
fmul	dword ptr [rdi - 0x28]
HeightMapIFS_L25:
fld	st(3)
HeightMapIFS_L27:
fmul	dword ptr [rdi - 0x2c]
HeightMapIFS_L2a:
faddp	st(1), st
HeightMapIFS_L2c:
fld	st(4)
HeightMapIFS_L2e:
fmul	dword ptr [rdi - 0x30]
HeightMapIFS_L31:
faddp	st(1), st
HeightMapIFS_L33:
fxch	st(2)
HeightMapIFS_L35:
fmul	dword ptr [rdi - 0x34]
HeightMapIFS_L38:
fxch	st(3)
HeightMapIFS_L3a:
fmul	dword ptr [rdi - 0x38]
HeightMapIFS_L3d:
faddp	st(3), st
HeightMapIFS_L3f:
fxch	st(3)
HeightMapIFS_L41:
fmul	dword ptr [rdi - 0x3c]
HeightMapIFS_L44:
faddp	st(2), st
HeightMapIFS_L46:
fld	st(2)
HeightMapIFS_L48:
fadd	dword ptr [rdi - 0x18]
HeightMapIFS_L4b:
fld	dword ptr [rdi - 0x24]
HeightMapIFS_L4e:
fmul	qword ptr [rdi - 0x8]
HeightMapIFS_L51:
fsubp	st(1), st
HeightMapIFS_L53:
fabs
HeightMapIFS_L55:
fld	dword ptr [rdi - 0x24]
HeightMapIFS_L58:
fabs
HeightMapIFS_L5a:
fadd	qword ptr [rsi - 0x88]
HeightMapIFS_L60:
fcompp
HeightMapIFS_L62:
fnstsw	ax
HeightMapIFS_L64:
shr	ah
HeightMapIFS_L66:
jae	HeightMapIFS_L7d
HeightMapIFS_L68:
fcompp
HeightMapIFS_L6a:
fld	qword ptr [rdi - 0x8]
HeightMapIFS_L6d:
fmul	dword ptr [rdi - 0x24]
HeightMapIFS_L70:
fsub	dword ptr [rdi - 0x18]
HeightMapIFS_L73:
fsubrp	st(1), st
HeightMapIFS_L75:
fstp	qword ptr [rsi - 0x20]
HeightMapIFS_L78:
add	rsp, 0x20
HeightMapIFS_L7b:
pop	rcx
HeightMapIFS_L7c:
ret
HeightMapIFS_L7d:
fmul	dword ptr [rdi - 0x1c]
HeightMapIFS_L80:
fsub	dword ptr [rdi - 0x10]
HeightMapIFS_L83:
fstp	qword ptr [rsp]
HeightMapIFS_L86:
fmul	dword ptr [rdi - 0x20]
HeightMapIFS_L89:
fsub	dword ptr [rdi - 0x14]
HeightMapIFS_L8c:
fstp	qword ptr [rsp + 0x8]
HeightMapIFS_L90:
fstp	qword ptr [rsp + 0x18]
HeightMapIFS_L94:
mov rax,rsp
HeightMapIFS_L96:
mov	edx, dword ptr [rdi - 0xc]
HeightMapIFS_L99:
mov	rcx, rsp
HeightMapIFS_L9b:
movsd xmm0,qword ptr [rsp]
movsd qword ptr [rsi+144],xmm0
movsd xmm0,qword ptr [rsp+8]
movsd qword ptr [rsi+152],xmm0
movsd xmm0,qword ptr [rip+height_r]
movsd qword ptr [rsp],xmm0
movsd xmm0,qword ptr [rip+height_g]
movsd qword ptr [rsp+8],xmm0
movsd xmm0,qword ptr [rip+height_b]
movsd qword ptr [rsp+16],xmm0
HeightMapIFS_La1:
mov	ecx, dword ptr [rdi - 0x4c]
HeightMapIFS_La4:
and	rcx, 0x3
HeightMapIFS_La7:
fld	qword ptr [rsp + 8*rcx]
HeightMapIFS_Laa:
fmul	dword ptr [rdi - 0x24]
HeightMapIFS_Lad:
fsub	dword ptr [rdi - 0x18]
HeightMapIFS_Lb0:
fsub	qword ptr [rsp + 0x18]
HeightMapIFS_Lb4:
fstp	qword ptr [rsi - 0x20]
HeightMapIFS_Lb7:
mov	ecx, dword ptr [rdi - 0x50]
HeightMapIFS_Lba:
and	rcx, 0x3
HeightMapIFS_Lbd:
fld	qword ptr [rsp + 8*rcx]
HeightMapIFS_Lc0:
fadd	dword ptr [rdi - 0x54]
HeightMapIFS_Lc3:
fmul	dword ptr [rdi - 0x58]
HeightMapIFS_Lc6:
fstp	qword ptr [rsi + 0x80]
HeightMapIFS_Lcc:
add	rsp, 0x20
HeightMapIFS_Lcf:
pop	rcx
HeightMapIFS_Ld0:
ret
.p2align 3
height_r: .double 0.2
height_g: .double 0.4
height_b: .double 0.8
