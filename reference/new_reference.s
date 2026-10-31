.intel_syntax noprefix
.text
.globl _addc_reference
_addc_reference:
mov r8,rdx
mov rax,rdi
lea rcx,[rdi+16]
lea rdx,[rdi+8]
mov rdi,rsi
mov rsi,r8
addc_reference_Lb:
fld	qword ptr [rcx]
addc_reference_Ld:
fld	qword ptr [rdx]
addc_reference_Lf:
fld	qword ptr [rax]
addc_reference_L11:
fld	qword ptr [rsi + 0x18]
addc_reference_L14:
fmul	qword ptr [rdi - 0x10]
addc_reference_L17:
faddp	st(1), st
addc_reference_L19:
fstp	qword ptr [rax]
addc_reference_L1b:
fld	qword ptr [rsi + 0x20]
addc_reference_L1e:
fmul	qword ptr [rdi - 0x18]
addc_reference_L21:
faddp	st(1), st
addc_reference_L23:
fstp	qword ptr [rdx]
addc_reference_L25:
fld	qword ptr [rsi + 0x28]
addc_reference_L28:
fmul	qword ptr [rdi - 0x20]
addc_reference_L2b:
faddp	st(1), st
addc_reference_L2d:
fstp	qword ptr [rcx]
ret
.globl _siny_reference
_siny_reference:
mov rax,rdi
mov rdi,rsi
mov esi,dword ptr [rdi-12]
and esi,3
siny_reference_L11:
fld	qword ptr [rax + 8*rsi]
siny_reference_L14:
fsub	dword ptr [rdi - 0x10]
siny_reference_L17:
fmul	dword ptr [rdi - 0x14]
siny_reference_L1a:
fsin
siny_reference_L1c:
fmul	dword ptr [rdi - 0x18]
siny_reference_L1f:
fadd	dword ptr [rdi - 0x1c]
siny_reference_L22:
fstp	qword ptr [rax + 8*rsi]
ret
.globl _benesi_reference
_benesi_reference:
mov r8,rdx
mov rax,rdi
lea rcx,[rdi+16]
lea rdx,[rdi+8]
mov rsi,r8
benesi_reference_L8:
fld	qword ptr [rcx]
benesi_reference_La:
fld	qword ptr [rdx]
benesi_reference_Lc:
fld	qword ptr [rax]
benesi_reference_Le:
fld	st(2)
benesi_reference_L10:
fmul	st, st(0)
benesi_reference_L12:
fld	st(2)
benesi_reference_L14:
fmul	st, st(0)
benesi_reference_L16:
fld	st(2)
benesi_reference_L18:
fmul	st, st(0)
benesi_reference_L1a:
fld	st(2)
benesi_reference_L1c:
fadd	st, st(2)
benesi_reference_L1e:
fld	st(0)
benesi_reference_L20:
fsqrt
benesi_reference_L22:
fcom	st(5)
benesi_reference_L24:
fnstsw	ax
benesi_reference_L26:
fxch	st(2)
benesi_reference_L28:
fsubrp	st(1), st
benesi_reference_L2a:
shr	ah
benesi_reference_L2c:
jae	benesi_reference_L37
benesi_reference_L2e:
mov	al, byte ptr [rsi + 0x1f]
benesi_reference_L31:
shl	al
benesi_reference_L33:
jb	benesi_reference_L37
benesi_reference_L35:
fchs
benesi_reference_L37:
fadd	qword ptr [rsi + 0x18]
benesi_reference_L3a:
fstp	qword ptr [rdx - 0x8]
benesi_reference_L3d:
fld1
benesi_reference_L3f:
fadd	st, st(0)
benesi_reference_L41:
fchs
benesi_reference_L43:
fdivrp	st(1), st
benesi_reference_L45:
fxch	st(3)
benesi_reference_L47:
fabs
benesi_reference_L49:
fmulp	st(3), st
benesi_reference_L4b:
fsubrp	st(1), st
benesi_reference_L4d:
fmul	st, st(1)
benesi_reference_L4f:
fadd	qword ptr [rsi + 0x20]
benesi_reference_L52:
fstp	qword ptr [rdx]
benesi_reference_L54:
fmulp	st(1), st
benesi_reference_L56:
fmulp	st(1), st
benesi_reference_L58:
fadd	st, st(0)
benesi_reference_L5a:
fadd	qword ptr [rsi + 0x28]
benesi_reference_L5d:
fstp	qword ptr [rcx]
ret
