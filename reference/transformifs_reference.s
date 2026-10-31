.intel_syntax noprefix
.text
.globl _transformifs_reference
_transformifs_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
transformifs_L0:
fld	qword ptr [rdi - 0x58]
transformifs_L3:
fld	qword ptr [rsi - 0x68]
transformifs_L6:
fmul	st, st(1)
transformifs_L8:
fadd	qword ptr [rdi - 0x20]
transformifs_Lb:
fld	qword ptr [rsi - 0x70]
transformifs_Le:
fmul	st, st(2)
transformifs_L10:
fadd	qword ptr [rdi - 0x18]
transformifs_L13:
fld	qword ptr [rsi - 0x78]
transformifs_L16:
fmul	st, st(3)
transformifs_L18:
fadd	qword ptr [rdi - 0x10]
transformifs_L1b:
fld	qword ptr [rsi + 0x70]
transformifs_L1e:
fmul	st, st(4)
transformifs_L20:
fstp	qword ptr [rsi + 0x70]
transformifs_L23:
fld	st(0)
transformifs_L25:
fmul	dword ptr [rdi - 0x3c]
transformifs_L28:
fld	st(2)
transformifs_L2a:
fmul	dword ptr [rdi - 0x40]
transformifs_L2d:
faddp	st(1), st
transformifs_L2f:
fld	st(3)
transformifs_L31:
fmul	dword ptr [rdi - 0x44]
transformifs_L34:
faddp	st(1), st
transformifs_L36:
fld	st(1)
transformifs_L38:
fmul	dword ptr [rdi - 0x24]
transformifs_L3b:
fld	st(3)
transformifs_L3d:
fmul	dword ptr [rdi - 0x28]
transformifs_L40:
faddp	st(1), st
transformifs_L42:
fld	st(4)
transformifs_L44:
fmul	dword ptr [rdi - 0x2c]
transformifs_L47:
faddp	st(1), st
transformifs_L49:
fxch	st(2)
transformifs_L4b:
fmul	dword ptr [rdi - 0x30]
transformifs_L4e:
fxch	st(3)
transformifs_L50:
fmul	dword ptr [rdi - 0x34]
transformifs_L53:
faddp	st(3), st
transformifs_L55:
fxch	st(3)
transformifs_L57:
fmul	dword ptr [rdi - 0x38]
transformifs_L5a:
faddp	st(2), st
transformifs_L5c:
cmp	dword ptr [rdi - 0x48], 0x0
transformifs_L60:
je	transformifs_L64
transformifs_L62:
fabs
transformifs_L64:
fstp	qword ptr [rsi - 0x78]
transformifs_L67:
cmp	dword ptr [rdi - 0x4c], 0x0
transformifs_L6b:
je	transformifs_L6f
transformifs_L6d:
fabs
transformifs_L6f:
fstp	qword ptr [rsi - 0x70]
transformifs_L72:
cmp	dword ptr [rdi - 0x50], 0x0
transformifs_L76:
je	transformifs_L7a
transformifs_L78:
fabs
transformifs_L7a:
fstp	qword ptr [rsi - 0x68]
transformifs_L7d:
fstp	st(0)
transformifs_L7f:
ret
