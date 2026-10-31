.intel_syntax noprefix
.text
.globl _torus_reference
_torus_reference:
mov rax,rdi
lea rdx,[rdi+8]
lea rcx,[rdi+16]
fld	qword ptr [rcx]
fld	qword ptr [rdx]
fld	qword ptr [rax]
fadd	qword ptr [rsi - 0x10]
fstp	qword ptr [rax]
fadd	qword ptr [rsi - 0x18]
fstp	qword ptr [rdx]
fadd	qword ptr [rsi - 0x20]
fstp	qword ptr [rcx]
fld	qword ptr [rax]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
faddp	st(1), st
fchs
fadd	qword ptr [rsi - 0x30]
fmul	st, st(0)
fld	qword ptr [rcx]
fmul	st, st(0)
faddp	st(1), st
fnop
fld	qword ptr [rax]
fabs
fdiv	st, st(1)
fld	qword ptr [rsi - 0x28]
fmulp	st(1), st
fsub	qword ptr [rsi - 0x10]
fstp	qword ptr [rax]
fld	qword ptr [rdx]
fabs
fdiv	st, st(1)
fld	qword ptr [rsi - 0x28]
fmulp	st(1), st
fsub	qword ptr [rsi - 0x18]
fstp	qword ptr [rdx]
fld	qword ptr [rcx]
fabs
fxch	st(1)
fmulp	st(1), st
fld	qword ptr [rsi - 0x28]
fmulp	st(1), st
fsub	qword ptr [rsi - 0x20]
fstp	qword ptr [rcx]
ret
