.intel_syntax noprefix
.text
.globl _mixpinski_reference
_mixpinski_reference:
push rbx
mov r8,rdi
mov r9,rsi
mov rsi,rdx
mov rdi,r9
mov rbx,r8
lea rdx,[r8+8]
lea rcx,[r8+16]
mixpinski_reference_Le:
fld	qword ptr [rcx + 0x8]
mixpinski_reference_L11:
fld	qword ptr [rcx]
mixpinski_reference_L13:
fld	qword ptr [rdx]
mixpinski_reference_L15:
fld	qword ptr [rbx]
mixpinski_reference_L17:
nop
mixpinski_reference_L18:
fchs
mixpinski_reference_L1a:
fcom	st(1)
mixpinski_reference_L1c:
fnstsw	ax
mixpinski_reference_L1e:
shr	ah
mixpinski_reference_L20:
jb	mixpinski_reference_L24
mixpinski_reference_L22:
fxch	st(1)
mixpinski_reference_L24:
fcom	st(2)
mixpinski_reference_L26:
fnstsw	ax
mixpinski_reference_L28:
shr	ah
mixpinski_reference_L2a:
jb	mixpinski_reference_L2e
mixpinski_reference_L2c:
fxch	st(2)
mixpinski_reference_L2e:
fchs
mixpinski_reference_L30:
fxch	st(1)
mixpinski_reference_L32:
fchs
mixpinski_reference_L34:
fcom	st(2)
mixpinski_reference_L36:
fnstsw	ax
mixpinski_reference_L38:
shr	ah
mixpinski_reference_L3a:
jb	mixpinski_reference_L3e
mixpinski_reference_L3c:
fxch	st(2)
mixpinski_reference_L3e:
fchs
mixpinski_reference_L40:
fxch	st(1)
mixpinski_reference_L42:
nop
mixpinski_reference_L43:
fchs
mixpinski_reference_L45:
fcom	st(3)
mixpinski_reference_L47:
fnstsw	ax
mixpinski_reference_L49:
shr	ah
mixpinski_reference_L4b:
jb	mixpinski_reference_L4f
mixpinski_reference_L4d:
fxch	st(3)
mixpinski_reference_L4f:
fchs
mixpinski_reference_L51:
fxch	st(1)
mixpinski_reference_L53:
fchs
mixpinski_reference_L55:
fcom	st(3)
mixpinski_reference_L57:
fnstsw	ax
mixpinski_reference_L59:
shr	ah
mixpinski_reference_L5b:
jb	mixpinski_reference_L5f
mixpinski_reference_L5d:
fxch	st(3)
mixpinski_reference_L5f:
fchs
mixpinski_reference_L61:
fxch	st(1)
mixpinski_reference_L63:
fxch	st(2)
mixpinski_reference_L65:
fchs
mixpinski_reference_L67:
fcom	st(3)
mixpinski_reference_L69:
fnstsw	ax
mixpinski_reference_L6b:
shr	ah
mixpinski_reference_L6d:
jb	mixpinski_reference_L71
mixpinski_reference_L6f:
fxch	st(3)
mixpinski_reference_L71:
fchs
mixpinski_reference_L73:
fxch	st(2)
mixpinski_reference_L75:
fld	qword ptr [rdi - 0x80]
mixpinski_reference_L78:
faddp	st(1), st
mixpinski_reference_L7a:
fld	qword ptr [rdi - 0x78]
mixpinski_reference_L7d:
faddp	st(2), st
mixpinski_reference_L7f:
fld	qword ptr [rdi - 0x88]
mixpinski_reference_L85:
faddp	st(3), st
mixpinski_reference_L87:
fld	qword ptr [rdi - 0x90]
mixpinski_reference_L8d:
faddp	st(4), st
mixpinski_reference_L8f:
nop
mixpinski_reference_L90:
sub	rdi, 0x28
mixpinski_reference_L93:
fld	st(0)
mixpinski_reference_L95:
fmul	dword ptr [rdi - 0xc]
mixpinski_reference_L98:
fld	st(2)
mixpinski_reference_L9a:
fmul	dword ptr [rdi - 0x10]
mixpinski_reference_L9d:
faddp	st(1), st
mixpinski_reference_L9f:
fld	st(3)
mixpinski_reference_La1:
fmul	dword ptr [rdi - 0x14]
mixpinski_reference_La4:
faddp	st(1), st
mixpinski_reference_La6:
fld	st(4)
mixpinski_reference_La8:
fmul	dword ptr [rdi - 0x18]
mixpinski_reference_Lab:
faddp	st(1), st
mixpinski_reference_Lad:
fstp	qword ptr [rbx]
mixpinski_reference_Laf:
fld	st(0)
mixpinski_reference_Lb1:
fmul	dword ptr [rdi - 0x1c]
mixpinski_reference_Lb4:
fld	st(2)
mixpinski_reference_Lb6:
fmul	dword ptr [rdi - 0x20]
mixpinski_reference_Lb9:
faddp	st(1), st
mixpinski_reference_Lbb:
fld	st(3)
mixpinski_reference_Lbd:
fmul	dword ptr [rdi - 0x24]
mixpinski_reference_Lc0:
faddp	st(1), st
mixpinski_reference_Lc2:
fld	st(4)
mixpinski_reference_Lc4:
fmul	dword ptr [rdi - 0x28]
mixpinski_reference_Lc7:
faddp	st(1), st
mixpinski_reference_Lc9:
fstp	qword ptr [rdx]
mixpinski_reference_Lcb:
fld	st(0)
mixpinski_reference_Lcd:
fmul	dword ptr [rdi - 0x2c]
mixpinski_reference_Ld0:
fld	st(2)
mixpinski_reference_Ld2:
fmul	dword ptr [rdi - 0x30]
mixpinski_reference_Ld5:
faddp	st(1), st
mixpinski_reference_Ld7:
fld	st(3)
mixpinski_reference_Ld9:
fmul	dword ptr [rdi - 0x34]
mixpinski_reference_Ldc:
faddp	st(1), st
mixpinski_reference_Lde:
fld	st(4)
mixpinski_reference_Le0:
fmul	dword ptr [rdi - 0x38]
mixpinski_reference_Le3:
faddp	st(1), st
mixpinski_reference_Le5:
fstp	qword ptr [rcx]
mixpinski_reference_Le7:
fmul	dword ptr [rdi - 0x3c]
mixpinski_reference_Lea:
fxch	st(1)
mixpinski_reference_Lec:
fmul	dword ptr [rdi - 0x40]
mixpinski_reference_Lef:
faddp	st(1), st
mixpinski_reference_Lf1:
fxch	st(1)
mixpinski_reference_Lf3:
fmul	dword ptr [rdi - 0x44]
mixpinski_reference_Lf6:
faddp	st(1), st
mixpinski_reference_Lf8:
fxch	st(1)
mixpinski_reference_Lfa:
fmul	dword ptr [rdi - 0x48]
mixpinski_reference_Lfd:
faddp	st(1), st
mixpinski_reference_Lff:
add	rdi, 0x28
mixpinski_reference_L102:
fld	qword ptr [rdi - 0x90]
mixpinski_reference_L108:
fsubp	st(1), st
mixpinski_reference_L10a:
fld	qword ptr [rdi - 0x10]
mixpinski_reference_L10d:
fmul	st(1), st
mixpinski_reference_L10f:
fld1
mixpinski_reference_L111:
fsubp	st(1), st
mixpinski_reference_L113:
fmul	qword ptr [rdi - 0x30]
mixpinski_reference_L116:
fsubp	st(1), st
mixpinski_reference_L118:
fstp	qword ptr [rcx + 0x8]
mixpinski_reference_L11b:
fld	qword ptr [rcx]
mixpinski_reference_L11d:
fsub	qword ptr [rdi - 0x88]
mixpinski_reference_L123:
fld	qword ptr [rdx]
mixpinski_reference_L125:
fsub	qword ptr [rdi - 0x78]
mixpinski_reference_L128:
fld	qword ptr [rbx]
mixpinski_reference_L12a:
fsub	qword ptr [rdi - 0x80]
mixpinski_reference_L12d:
nop
mixpinski_reference_L12e:
fld	qword ptr [rdi - 0x10]
mixpinski_reference_L131:
fld	qword ptr [rsi + 0xe8]
mixpinski_reference_L137:
fmul	st, st(1)
mixpinski_reference_L139:
fstp	qword ptr [rsi + 0xe8]
mixpinski_reference_L13f:
nop
mixpinski_reference_L140:
nop
mixpinski_reference_L141:
fmul	st(2), st
mixpinski_reference_L143:
fmul	st(1), st
mixpinski_reference_L145:
fld	st(0)
mixpinski_reference_L147:
fld1
mixpinski_reference_L149:
fsubp	st(1), st
mixpinski_reference_L14b:
fld	st(0)
mixpinski_reference_L14d:
fld	st(0)
mixpinski_reference_L14f:
fmul	qword ptr [rdi - 0x18]
mixpinski_reference_L152:
fsubp	st(5), st
mixpinski_reference_L154:
fmul	qword ptr [rdi - 0x20]
mixpinski_reference_L157:
fsubp	st(3), st
mixpinski_reference_L159:
fdiv	st, st(1)
mixpinski_reference_L15b:
fmul	qword ptr [rdi - 0x28]
mixpinski_reference_L15e:
fsub	st(4), st
mixpinski_reference_L160:
fxch	st(4)
mixpinski_reference_L162:
fabs
mixpinski_reference_L164:
fsubp	st(4), st
mixpinski_reference_L166:
fmulp	st(3), st
mixpinski_reference_L168:
fstp	qword ptr [rdx]
mixpinski_reference_L16a:
fstp	qword ptr [rbx]
mixpinski_reference_L16c:
fstp	qword ptr [rcx]
mixpinski_reference_L16e:
nop
mixpinski_reference_L16f:
nop
mixpinski_reference_L170:
nop
pop rbx
ret
.globl _lincombine_reference
_lincombine_reference:
mov rax,rdi
lea rdx,[rdi+8]
lea rcx,[rdi+16]
lincombine_reference_La:
fld	qword ptr [rcx]
lincombine_reference_Lc:
fld	qword ptr [rdx]
lincombine_reference_Le:
fld	qword ptr [rax]
lincombine_reference_L10:
fld	st(0)
lincombine_reference_L12:
fmul	qword ptr [rsi - 0x10]
lincombine_reference_L15:
fld	st(2)
lincombine_reference_L17:
fmul	qword ptr [rsi - 0x18]
lincombine_reference_L1a:
faddp	st(1), st
lincombine_reference_L1c:
fld	st(3)
lincombine_reference_L1e:
fmul	qword ptr [rsi - 0x20]
lincombine_reference_L21:
faddp	st(1), st
lincombine_reference_L23:
fstp	qword ptr [rax]
lincombine_reference_L25:
fld	st(0)
lincombine_reference_L27:
fmul	qword ptr [rsi - 0x28]
lincombine_reference_L2a:
fld	st(2)
lincombine_reference_L2c:
fmul	qword ptr [rsi - 0x30]
lincombine_reference_L2f:
faddp	st(1), st
lincombine_reference_L31:
fld	st(3)
lincombine_reference_L33:
fmul	qword ptr [rsi - 0x38]
lincombine_reference_L36:
faddp	st(1), st
lincombine_reference_L38:
fstp	qword ptr [rdx]
lincombine_reference_L3a:
fmul	qword ptr [rsi - 0x40]
lincombine_reference_L3d:
fxch	st(1)
lincombine_reference_L3f:
fmul	qword ptr [rsi - 0x48]
lincombine_reference_L42:
faddp	st(1), st
lincombine_reference_L44:
fxch	st(1)
lincombine_reference_L46:
fmul	qword ptr [rsi - 0x50]
lincombine_reference_L49:
faddp	st(1), st
lincombine_reference_L4b:
fstp	qword ptr [rcx]

ret
