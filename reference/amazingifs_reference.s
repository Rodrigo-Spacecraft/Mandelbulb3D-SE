.intel_syntax noprefix
.text
.globl _amazingifs_reference
_amazingifs_reference:
mov rax,rdi
mov rdi,rsi
mov rsi,rax
amazingifs_reference_L0:
fld	qword ptr [rdi - 0x4c]
amazingifs_reference_L3:
fld	qword ptr [rsi - 0x68]
amazingifs_reference_L6:
fld	st(0)
amazingifs_reference_L8:
fsub	st, st(2)
amazingifs_reference_La:
fabs
amazingifs_reference_Lc:
fadd	st, st(1)
amazingifs_reference_Le:
fxch	st(1)
amazingifs_reference_L10:
fadd	st, st(2)
amazingifs_reference_L12:
fabs
amazingifs_reference_L14:
fsubrp	st(1), st
amazingifs_reference_L16:
fstp	qword ptr [rsi - 0x68]
amazingifs_reference_L19:
fstp	st(0)
amazingifs_reference_L1b:
fld	qword ptr [rdi - 0x54]
amazingifs_reference_L1e:
fld	qword ptr [rsi - 0x70]
amazingifs_reference_L21:
fld	st(0)
amazingifs_reference_L23:
fsub	st, st(2)
amazingifs_reference_L25:
fabs
amazingifs_reference_L27:
fadd	st, st(1)
amazingifs_reference_L29:
fxch	st(1)
amazingifs_reference_L2b:
fadd	st, st(2)
amazingifs_reference_L2d:
fabs
amazingifs_reference_L2f:
fsubrp	st(1), st
amazingifs_reference_L31:
fstp	qword ptr [rsi - 0x70]
amazingifs_reference_L34:
fstp	st(0)
amazingifs_reference_L36:
fld	qword ptr [rdi - 0x5c]
amazingifs_reference_L39:
fld	qword ptr [rsi - 0x78]
amazingifs_reference_L3c:
fld	st(0)
amazingifs_reference_L3e:
fsub	st, st(2)
amazingifs_reference_L40:
fabs
amazingifs_reference_L42:
fadd	st, st(1)
amazingifs_reference_L44:
fxch	st(1)
amazingifs_reference_L46:
fadd	st, st(2)
amazingifs_reference_L48:
fabs
amazingifs_reference_L4a:
fsubrp	st(1), st
amazingifs_reference_L4c:
fstp	qword ptr [rsi - 0x78]
amazingifs_reference_L4f:
fstp	st(0)
amazingifs_reference_L51:
fld	qword ptr [rsi - 0x68]
amazingifs_reference_L54:
fadd	qword ptr [rdi - 0x20]
amazingifs_reference_L57:
fld	qword ptr [rsi - 0x70]
amazingifs_reference_L5a:
fadd	qword ptr [rdi - 0x18]
amazingifs_reference_L5d:
fld	qword ptr [rsi - 0x78]
amazingifs_reference_L60:
fadd	qword ptr [rdi - 0x10]
amazingifs_reference_L63:
fld	st(0)
amazingifs_reference_L65:
fmul	dword ptr [rdi - 0x3c]
amazingifs_reference_L68:
fld	st(2)
amazingifs_reference_L6a:
fmul	dword ptr [rdi - 0x40]
amazingifs_reference_L6d:
faddp	st(1), st
amazingifs_reference_L6f:
fld	st(3)
amazingifs_reference_L71:
fmul	dword ptr [rdi - 0x44]
amazingifs_reference_L74:
faddp	st(1), st
amazingifs_reference_L76:
fld	st(1)
amazingifs_reference_L78:
fmul	dword ptr [rdi - 0x24]
amazingifs_reference_L7b:
fld	st(3)
amazingifs_reference_L7d:
fmul	dword ptr [rdi - 0x28]
amazingifs_reference_L80:
faddp	st(1), st
amazingifs_reference_L82:
fld	st(4)
amazingifs_reference_L84:
fmul	dword ptr [rdi - 0x2c]
amazingifs_reference_L87:
faddp	st(1), st
amazingifs_reference_L89:
fxch	st(2)
amazingifs_reference_L8b:
fmul	dword ptr [rdi - 0x30]
amazingifs_reference_L8e:
fxch	st(3)
amazingifs_reference_L90:
fmul	dword ptr [rdi - 0x34]
amazingifs_reference_L93:
faddp	st(3), st
amazingifs_reference_L95:
fxch	st(3)
amazingifs_reference_L97:
fmul	dword ptr [rdi - 0x38]
amazingifs_reference_L9a:
faddp	st(2), st
amazingifs_reference_L9c:
fld	st(0)
amazingifs_reference_L9e:
fmul	st, st(0)
amazingifs_reference_La0:
fld	st(2)
amazingifs_reference_La2:
fmul	st, st(0)
amazingifs_reference_La4:
faddp	st(1), st
amazingifs_reference_La6:
fld	st(3)
amazingifs_reference_La8:
fmul	st, st(0)
amazingifs_reference_Laa:
faddp	st(1), st
amazingifs_reference_Lac:
fld1
amazingifs_reference_Lae:
fdivrp	st(1), st
amazingifs_reference_Lb0:
fld1
amazingifs_reference_Lb2:
fcomp	st(1)
amazingifs_reference_Lb4:
wait
amazingifs_reference_Lb5:
fnstsw	ax
amazingifs_reference_Lb7:
shr	ah
amazingifs_reference_Lb9:
jae	amazingifs_reference_Lce
amazingifs_reference_Lbb:
fcom	qword ptr [rdi - 0x64]
amazingifs_reference_Lbe:
wait
amazingifs_reference_Lbf:
fnstsw	ax
amazingifs_reference_Lc1:
shr	ah
amazingifs_reference_Lc3:
jbe	amazingifs_reference_Lda
amazingifs_reference_Lc5:
fstp	st(0)
amazingifs_reference_Lc7:
fld	qword ptr [rdi - 0x64]
amazingifs_reference_Lca:
jmp	amazingifs_reference_Lda
amazingifs_reference_Lcc:
nop
amazingifs_reference_Lcd:
nop
amazingifs_reference_Lce:
fstp	st(0)
amazingifs_reference_Ld0:
fstp	qword ptr [rsi - 0x78]
amazingifs_reference_Ld3:
fstp	qword ptr [rsi - 0x70]
amazingifs_reference_Ld6:
fstp	qword ptr [rsi - 0x68]
amazingifs_reference_Ld9:
ret
amazingifs_reference_Lda:
fmul	st(1), st
amazingifs_reference_Ldc:
fmul	st(2), st
amazingifs_reference_Lde:
fmul	st(3), st
amazingifs_reference_Le0:
fld	qword ptr [rsi + 0x70]
amazingifs_reference_Le3:
fmul	st, st(1)
amazingifs_reference_Le5:
fabs
amazingifs_reference_Le7:
fstp	qword ptr [rsi + 0x70]
amazingifs_reference_Lea:
jmp	amazingifs_reference_Lce
