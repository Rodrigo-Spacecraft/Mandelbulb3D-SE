.intel_syntax noprefix
.text
.globl _surf_reference
_surf_reference:
push rbx
mov r8,rdx
mov rbx,rdi
lea rcx,[rdi+16]
lea rdx,[rdi+8]
lea rdi,[r8+128]
surf_L14:
cmp	dword ptr [rdi + 0x50], 0x0
surf_L18:
jg	surf_L23
surf_L1a:
inc	dword ptr [rdi + 0x50]
surf_L1d:
fld	qword ptr [rsi - 0x10]
surf_L20:
fstp	qword ptr [rdi + 0x48]
surf_L23:
fld	qword ptr [rdi + 0x48]
surf_L26:
fld1
surf_L28:
fld	st(1)
surf_L2a:
fabs
surf_L2c:
fsubrp	st(1), st
surf_L2e:
fmul	qword ptr [rsi - 0x54]
surf_L31:
faddp	st(1), st
surf_L33:
fstp	qword ptr [rdi + 0x48]
surf_L36:
fld	qword ptr [rsi - 0x28]
surf_L39:
fld	qword ptr [rbx]
surf_L3b:
fld	st(0)
surf_L3d:
fsub	st, st(2)
surf_L3f:
fabs
surf_L41:
fadd	st, st(1)
surf_L43:
fxch	st(1)
surf_L45:
fadd	st, st(2)
surf_L47:
fabs
surf_L49:
fsubrp	st(1), st
surf_L4b:
fld	qword ptr [rdx]
surf_L4d:
fld	st(0)
surf_L4f:
fsub	st, st(3)
surf_L51:
fabs
surf_L53:
fadd	st, st(1)
surf_L55:
fxch	st(1)
surf_L57:
fadd	st, st(3)
surf_L59:
fabs
surf_L5b:
fsubrp	st(1), st
surf_L5d:
fst	qword ptr [rdx]
surf_L5f:
fmul	st, st(0)
surf_L61:
fxch	st(1)
surf_L63:
fst	qword ptr [rbx]
surf_L65:
fmul	st, st(0)
surf_L67:
faddp	st(1), st
surf_L69:
fstp	st(1)
surf_L6b:
cmp	dword ptr [rsi - 0x58], 0x0
surf_L6f:
jne	surf_L77
surf_L71:
fld	qword ptr [rcx]
surf_L73:
fmul	st, st(0)
surf_L75:
faddp	st(1), st
surf_L77:
fcom	qword ptr [rsi - 0x20]
surf_L7a:
fnstsw	ax
surf_L7c:
shr	ah
surf_L7e:
jae	surf_L87
surf_L80:
fstp	st(0)
surf_L82:
fld	qword ptr [rsi - 0x18]
surf_L85:
jmp	surf_L9d
surf_L87:
fld1
surf_L89:
fcom	st(1)
surf_L8b:
fnstsw	ax
surf_L8d:
shr	ah
surf_L8f:
jb	surf_L98
surf_L91:
fstp	st(0)
surf_L93:
fdivr	qword ptr [rdi + 0x48]
surf_L96:
jmp	surf_L9d
surf_L98:
fcompp
surf_L9a:
fld	qword ptr [rdi + 0x48]
surf_L9d:
fld	qword ptr [rcx + 0x8]
surf_La0:
fmul	st, st(1)
surf_La2:
fstp	qword ptr [rcx + 0x8]
surf_La5:
fld	qword ptr [rcx]
surf_La7:
fmul	st, st(1)
surf_La9:
fadd	qword ptr [rdi - 0x58]
surf_Lac:
fld	qword ptr [rdx]
surf_Lae:
fmul	st, st(2)
surf_Lb0:
fadd	qword ptr [rdi - 0x60]
surf_Lb3:
fld	qword ptr [rbx]
surf_Lb5:
fmul	st, st(3)
surf_Lb7:
fadd	qword ptr [rdi - 0x68]
surf_Lba:
fld	st(0)
surf_Lbc:
fmul	dword ptr [rsi - 0x44]
surf_Lbf:
fld	st(2)
surf_Lc1:
fmul	dword ptr [rsi - 0x48]
surf_Lc4:
faddp	st(1), st
surf_Lc6:
fld	st(3)
surf_Lc8:
fmul	dword ptr [rsi - 0x4c]
surf_Lcb:
faddp	st(1), st
surf_Lcd:
fld	st(1)
surf_Lcf:
fmul	dword ptr [rsi - 0x2c]
surf_Ld2:
fld	st(3)
surf_Ld4:
fmul	dword ptr [rsi - 0x30]
surf_Ld7:
faddp	st(1), st
surf_Ld9:
fld	st(4)
surf_Ldb:
fmul	dword ptr [rsi - 0x34]
surf_Lde:
faddp	st(1), st
surf_Le0:
fxch	st(2)
surf_Le2:
fmul	dword ptr [rsi - 0x38]
surf_Le5:
fxch	st(3)
surf_Le7:
fmul	dword ptr [rsi - 0x3c]
surf_Lea:
faddp	st(3), st
surf_Lec:
fxch	st(3)
surf_Lee:
fmul	dword ptr [rsi - 0x40]
surf_Lf1:
faddp	st(2), st
surf_Lf3:
fstp	qword ptr [rbx]
surf_Lf5:
fstp	qword ptr [rdx]
surf_Lf7:
fstp	qword ptr [rcx]
surf_Lf9:
fstp	st(0)
pop rbx
ret
