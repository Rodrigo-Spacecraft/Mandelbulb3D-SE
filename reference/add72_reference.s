.intel_syntax noprefix
.text
.globl _poly_reference
_poly_reference:
push rbx
mov r8,rdi
mov r9,rsi
mov rsi,rdx
mov rdi,r9
mov rbx,r8
lea rdx,[r8+8]
lea rcx,[r8+16]
poly_reference_Le:
fld	qword ptr [rdx]
poly_reference_L10:
fadd	qword ptr [rdi - 0x28]
poly_reference_L13:
fst	qword ptr [rdx]
poly_reference_L15:
fld	qword ptr [rbx]
poly_reference_L17:
fadd	qword ptr [rdi - 0x20]
poly_reference_L1a:
fst	qword ptr [rbx]
poly_reference_L1c:
fpatan
poly_reference_L1e:
fld	qword ptr [rdi - 0x30]
poly_reference_L21:
fadd	qword ptr [rdi - 0x18]
poly_reference_L24:
fmul	qword ptr [rdi + 0x8]
poly_reference_L27:
faddp	st(1), st
poly_reference_L29:
fdiv	qword ptr [rdi]
poly_reference_L2b:
fmul	qword ptr [rdi - 0x10]
poly_reference_L2e:
add	rsp, -0x10
poly_reference_L31:
nop
poly_reference_L32:
fistp	dword ptr [rsp]
poly_reference_L35:
fild	dword ptr [rsp]
poly_reference_L38:
fchs
poly_reference_L3a:
fdiv	qword ptr [rdi - 0x10]
poly_reference_L3d:
fmul	qword ptr [rdi]
poly_reference_L3f:
fld	qword ptr [rdi - 0x18]
poly_reference_L42:
fmul	qword ptr [rdi + 0x8]
poly_reference_L45:
faddp	st(1), st
poly_reference_L47:
fsincos
poly_reference_L49:
fnop
poly_reference_L4b:
fld	qword ptr [rbx]
poly_reference_L4d:
fmul	st, st(1)
poly_reference_L4f:
fld	qword ptr [rdx]
poly_reference_L51:
fmul	st, st(3)
poly_reference_L53:
fsubrp	st(1), st
poly_reference_L55:
fnop
poly_reference_L57:
fld	qword ptr [rbx]
poly_reference_L59:
fmul	st, st(3)
poly_reference_L5b:
fld	qword ptr [rdx]
poly_reference_L5d:
fmul	st, st(3)
poly_reference_L5f:
faddp	st(1), st
poly_reference_L61:
mov	eax, dword ptr [rsp]
poly_reference_L64:
and	eax, 0x1
poly_reference_L67:
jne	poly_reference_L6b
poly_reference_L69:
fchs
poly_reference_L6b:
add	rsp, 0x10
poly_reference_L6e:
fsub	qword ptr [rdi - 0x28]
poly_reference_L71:
fstp	qword ptr [rdx]
poly_reference_L73:
fsub	qword ptr [rdi - 0x20]
poly_reference_L76:
fstp	qword ptr [rbx]
poly_reference_L78:
fstp	st(0)
poly_reference_L7a:
fstp	st(0)
pop rbx
ret
.globl _mix4_reference
_mix4_reference:
push rbx
mov r8,rdi
mov r9,rsi
mov rsi,rdx
mov rdi,r9
mov rbx,r8
lea rdx,[r8+8]
lea rcx,[r8+16]
mix4_reference_Le:
fld	qword ptr [rcx + 0x8]
mix4_reference_L11:
fld	qword ptr [rcx]
mix4_reference_L13:
fld	qword ptr [rdx]
mix4_reference_L15:
fld	qword ptr [rbx]
mix4_reference_L17:
nop
mix4_reference_L18:
fchs
mix4_reference_L1a:
fcom	st(1)
mix4_reference_L1c:
fnstsw	ax
mix4_reference_L1e:
shr	ah
mix4_reference_L20:
jb	mix4_reference_L24
mix4_reference_L22:
fxch	st(1)
mix4_reference_L24:
fcom	st(2)
mix4_reference_L26:
fnstsw	ax
mix4_reference_L28:
shr	ah
mix4_reference_L2a:
jb	mix4_reference_L2e
mix4_reference_L2c:
fxch	st(2)
mix4_reference_L2e:
fchs
mix4_reference_L30:
fxch	st(1)
mix4_reference_L32:
fchs
mix4_reference_L34:
fcom	st(2)
mix4_reference_L36:
fnstsw	ax
mix4_reference_L38:
shr	ah
mix4_reference_L3a:
jb	mix4_reference_L3e
mix4_reference_L3c:
fxch	st(2)
mix4_reference_L3e:
fchs
mix4_reference_L40:
fxch	st(1)
mix4_reference_L42:
nop
mix4_reference_L43:
fchs
mix4_reference_L45:
fcom	st(3)
mix4_reference_L47:
fnstsw	ax
mix4_reference_L49:
shr	ah
mix4_reference_L4b:
jb	mix4_reference_L4f
mix4_reference_L4d:
fxch	st(3)
mix4_reference_L4f:
fchs
mix4_reference_L51:
fxch	st(1)
mix4_reference_L53:
fchs
mix4_reference_L55:
fcom	st(3)
mix4_reference_L57:
fnstsw	ax
mix4_reference_L59:
shr	ah
mix4_reference_L5b:
jb	mix4_reference_L5f
mix4_reference_L5d:
fxch	st(3)
mix4_reference_L5f:
fchs
mix4_reference_L61:
fxch	st(1)
mix4_reference_L63:
fxch	st(2)
mix4_reference_L65:
fchs
mix4_reference_L67:
fcom	st(3)
mix4_reference_L69:
fnstsw	ax
mix4_reference_L6b:
shr	ah
mix4_reference_L6d:
jb	mix4_reference_L71
mix4_reference_L6f:
fxch	st(3)
mix4_reference_L71:
fchs
mix4_reference_L73:
fxch	st(2)
mix4_reference_L75:
nop
mix4_reference_L76:
sub	rdi, 0x28
mix4_reference_L79:
fld	st(0)
mix4_reference_L7b:
fmul	dword ptr [rdi - 0xc]
mix4_reference_L7e:
fld	st(2)
mix4_reference_L80:
fmul	dword ptr [rdi - 0x10]
mix4_reference_L83:
faddp	st(1), st
mix4_reference_L85:
fld	st(3)
mix4_reference_L87:
fmul	dword ptr [rdi - 0x14]
mix4_reference_L8a:
faddp	st(1), st
mix4_reference_L8c:
fld	st(4)
mix4_reference_L8e:
fmul	dword ptr [rdi - 0x18]
mix4_reference_L91:
faddp	st(1), st
mix4_reference_L93:
fstp	qword ptr [rbx]
mix4_reference_L95:
fld	st(0)
mix4_reference_L97:
fmul	dword ptr [rdi - 0x1c]
mix4_reference_L9a:
fld	st(2)
mix4_reference_L9c:
fmul	dword ptr [rdi - 0x20]
mix4_reference_L9f:
faddp	st(1), st
mix4_reference_La1:
fld	st(3)
mix4_reference_La3:
fmul	dword ptr [rdi - 0x24]
mix4_reference_La6:
faddp	st(1), st
mix4_reference_La8:
fld	st(4)
mix4_reference_Laa:
fmul	dword ptr [rdi - 0x28]
mix4_reference_Lad:
faddp	st(1), st
mix4_reference_Laf:
fstp	qword ptr [rdx]
mix4_reference_Lb1:
fld	st(0)
mix4_reference_Lb3:
fmul	dword ptr [rdi - 0x2c]
mix4_reference_Lb6:
fld	st(2)
mix4_reference_Lb8:
fmul	dword ptr [rdi - 0x30]
mix4_reference_Lbb:
faddp	st(1), st
mix4_reference_Lbd:
fld	st(3)
mix4_reference_Lbf:
fmul	dword ptr [rdi - 0x34]
mix4_reference_Lc2:
faddp	st(1), st
mix4_reference_Lc4:
fld	st(4)
mix4_reference_Lc6:
fmul	dword ptr [rdi - 0x38]
mix4_reference_Lc9:
faddp	st(1), st
mix4_reference_Lcb:
fstp	qword ptr [rcx]
mix4_reference_Lcd:
fmul	dword ptr [rdi - 0x3c]
mix4_reference_Ld0:
fxch	st(1)
mix4_reference_Ld2:
fmul	dword ptr [rdi - 0x40]
mix4_reference_Ld5:
faddp	st(1), st
mix4_reference_Ld7:
fxch	st(1)
mix4_reference_Ld9:
fmul	dword ptr [rdi - 0x44]
mix4_reference_Ldc:
faddp	st(1), st
mix4_reference_Lde:
fxch	st(1)
mix4_reference_Le0:
fmul	dword ptr [rdi - 0x48]
mix4_reference_Le3:
faddp	st(1), st
mix4_reference_Le5:
add	rdi, 0x28
mix4_reference_Le8:
fld	qword ptr [rdi - 0x10]
mix4_reference_Leb:
fmul	st(1), st
mix4_reference_Led:
fld1
mix4_reference_Lef:
fsubp	st(1), st
mix4_reference_Lf1:
fmul	qword ptr [rdi - 0x30]
mix4_reference_Lf4:
fsubp	st(1), st
mix4_reference_Lf6:
fstp	qword ptr [rcx + 0x8]
mix4_reference_Lf9:
fld	qword ptr [rcx]
mix4_reference_Lfb:
fld	qword ptr [rdx]
mix4_reference_Lfd:
fld	qword ptr [rbx]
mix4_reference_Lff:
fld	qword ptr [rdi - 0x10]
mix4_reference_L102:
fld	qword ptr [rsi + 0xe8]
mix4_reference_L108:
fmul	st, st(1)
mix4_reference_L10a:
fstp	qword ptr [rsi + 0xe8]
mix4_reference_L110:
nop
mix4_reference_L111:
nop
mix4_reference_L112:
fmul	st(2), st
mix4_reference_L114:
fmul	st(1), st
mix4_reference_L116:
fld	st(0)
mix4_reference_L118:
fld1
mix4_reference_L11a:
fsubp	st(1), st
mix4_reference_L11c:
fld	st(0)
mix4_reference_L11e:
fld	st(0)
mix4_reference_L120:
fmul	qword ptr [rdi - 0x18]
mix4_reference_L123:
fsubp	st(5), st
mix4_reference_L125:
fmul	qword ptr [rdi - 0x20]
mix4_reference_L128:
fsubp	st(3), st
mix4_reference_L12a:
fdiv	st, st(1)
mix4_reference_L12c:
fmul	qword ptr [rdi - 0x28]
mix4_reference_L12f:
fsub	st(4), st
mix4_reference_L131:
fxch	st(4)
mix4_reference_L133:
fabs
mix4_reference_L135:
fsubp	st(4), st
mix4_reference_L137:
fmulp	st(3), st
mix4_reference_L139:
fstp	qword ptr [rdx]
mix4_reference_L13b:
fstp	qword ptr [rbx]
mix4_reference_L13d:
fstp	qword ptr [rcx]
mix4_reference_L13f:
nop
mix4_reference_L140:
nop
mix4_reference_L141:
nop
pop rbx
ret
