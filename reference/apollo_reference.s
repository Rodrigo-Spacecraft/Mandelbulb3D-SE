.intel_syntax noprefix
.text
.globl _apollo_reference
_apollo_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
apollo_L0:
add	rsp, -0x8
apollo_L3:
fld	qword ptr [rdi - 0x50]
apollo_L6:
fld	qword ptr [rsi - 0x70]
apollo_L9:
fmul	st, st(1)
apollo_Lb:
fld	qword ptr [rsi - 0x78]
apollo_Le:
fmul	st, st(2)
apollo_L10:
fadd	qword ptr [rdi - 0x10]
apollo_L13:
fld	st(1)
apollo_L15:
fld	st(1)
apollo_L17:
fpatan
apollo_L19:
fchs
apollo_L1b:
fmul	qword ptr [rdi]
apollo_L1d:
fild	dword ptr [rdi - 0x48]
apollo_L20:
fxch	st(1)
apollo_L22:
fmul	st, st(1)
apollo_L24:
frndint
apollo_L26:
fist	dword ptr [rsp]
apollo_L29:
fdivrp	st(1), st
apollo_L2b:
fmul	qword ptr [rdi + 0x8]
apollo_L2e:
fsincos
apollo_L30:
fld	st(3)
apollo_L32:
fmul	st, st(1)
apollo_L34:
fld	st(3)
apollo_L36:
fmul	st, st(3)
apollo_L38:
faddp	st(1), st
apollo_L3a:
and	dword ptr [rsp], 0x1
apollo_L3e:
jne	apollo_L42
apollo_L40:
fchs
apollo_L42:
fxch	st(4)
apollo_L44:
fmulp	st(2), st
apollo_L46:
fmulp	st(2), st
apollo_L48:
fsubp	st(1), st
apollo_L4a:
fxch	st(1)
apollo_L4c:
fld	qword ptr [rsi - 0x68]
apollo_L50:
fxch	st(2)
apollo_L52:
fadd	qword ptr [rdi - 0x18]
apollo_L56:
fld	st(0)
apollo_L58:
fmul	dword ptr [rdi - 0x3c]
apollo_L5c:
fld	st(2)
apollo_L5e:
fmul	dword ptr [rdi - 0x40]
apollo_L62:
faddp	st(1), st
apollo_L64:
fld	st(3)
apollo_L66:
fmul	dword ptr [rdi - 0x44]
apollo_L6a:
faddp	st(1), st
apollo_L6c:
fld	st(1)
apollo_L6e:
fmul	dword ptr [rdi - 0x24]
apollo_L72:
fld	st(3)
apollo_L74:
fmul	dword ptr [rdi - 0x28]
apollo_L78:
faddp	st(1), st
apollo_L7a:
fld	st(4)
apollo_L7c:
fmul	dword ptr [rdi - 0x2c]
apollo_L80:
faddp	st(1), st
apollo_L82:
fxch	st(2)
apollo_L84:
fmul	dword ptr [rdi - 0x30]
apollo_L88:
fxch	st(3)
apollo_L8a:
fmul	dword ptr [rdi - 0x34]
apollo_L8e:
faddp	st(3), st
apollo_L90:
fxch	st(3)
apollo_L92:
fmul	dword ptr [rdi - 0x38]
apollo_L96:
faddp	st(2), st
apollo_L98:
fstp	qword ptr [rsi - 0x70]
apollo_L9c:
fchs
apollo_L9e:
fxch	st(1)
apollo_La0:
fmul	qword ptr [rdi - 0x20]
apollo_La4:
fstp	qword ptr [rsi - 0x68]
apollo_La8:
fld	st(0)
apollo_Laa:
fmul	st, st(0)
apollo_Lac:
fld	qword ptr [rsi - 0x70]
apollo_Lb0:
fmul	st, st(0)
apollo_Lb2:
faddp	st(1), st
apollo_Lb4:
fld	st(0)
apollo_Lb6:
fld1
apollo_Lb8:
fsubp	st(1), st
apollo_Lba:
fxch	st(1)
apollo_Lbc:
fld1
apollo_Lbe:
faddp	st(1), st
apollo_Lc0:
fld	qword ptr [rsi - 0x70]
apollo_Lc4:
fadd	st, st(0)
apollo_Lc6:
faddp	st(1), st
apollo_Lc8:
fmulp	st(3), st
apollo_Lca:
fxch	st(2)
apollo_Lcc:
fld1
apollo_Lce:
fdivrp	st(1), st
apollo_Ld0:
fxch	st(2)
apollo_Ld2:
fmul	st, st(2)
apollo_Ld4:
fadd	qword ptr [rdi - 0x58]
apollo_Ld8:
fstp	qword ptr [rsi - 0x78]
apollo_Ldc:
fadd	st, st(0)
apollo_Lde:
fchs
apollo_Le0:
fmulp	st(1), st
apollo_Le2:
fstp	qword ptr [rsi - 0x70]
apollo_Le6:
fld	qword ptr [rsi + 0x70]
apollo_Le9:
fld	qword ptr [rdi - 0x20]
apollo_Lec:
fabs
apollo_Lee:
fmulp	st(1), st
apollo_Lf0:
fstp	qword ptr [rsi + 0x70]
apollo_Lf3:
add	rsp, 0x8
apollo_Lf6:
ret
