.intel_syntax noprefix
.text
.globl _makin4_reference
_makin4_reference:
push rbx
mov r8,rdi
mov r9,rsi
mov rsi,rdx
mov rdi,r9
mov rax,r8
mov rbx,r8
lea rdx,[r8+8]
lea rcx,[r8+16]
fld	qword ptr [rbx]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
faddp	st(1), st
nop
nop
fld	qword ptr [rcx]
fmul	st, st(0)
fld	qword ptr [rcx + 0x8]
fmul	st, st(0)
faddp	st(1), st
nop
nop
faddp	st(1), st
nop
fld	qword ptr [rbx]
fmul	qword ptr [rcx]
fld	qword ptr [rdx]
fmul	qword ptr [rcx + 0x8]
fsubp	st(1), st
fadd	st, st(0)
nop
fld	qword ptr [rbx]
fmul	qword ptr [rcx + 0x8]
fld	qword ptr [rdx]
fmul	qword ptr [rcx]
faddp	st(1), st
fadd	st, st(0)
nop
fld	qword ptr [rbx]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
fsubp	st(1), st
fadd	st, st(0)
nop
fld	qword ptr [rbx]
fmul	qword ptr [rdx]
fadd	st, st(0)
fadd	st, st(0)
fstp	qword ptr [rdx]
fstp	qword ptr [rbx]
fld	qword ptr [rbx]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
faddp	st(1), st
fsqrt
fdivr	st, st(3)
fchs
fld1
faddp	st(1), st
fld	qword ptr [rbx]
fmul	st, st(1)
fstp	qword ptr [rbx]
fld	qword ptr [rdx]
fmulp	st(1), st
fstp	qword ptr [rdx]
fstp	qword ptr [rcx + 0x8]
fstp	qword ptr [rcx]
fstp	st(0)
fnop
fld	qword ptr [rbx]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
faddp	st(1), st
nop
nop
fld	qword ptr [rcx]
fmul	st, st(0)
fld	qword ptr [rcx + 0x8]
fmul	st, st(0)
faddp	st(1), st
nop
nop
faddp	st(1), st
nop
fld	qword ptr [rbx]
fmul	qword ptr [rcx]
fld	qword ptr [rdx]
fmul	qword ptr [rcx + 0x8]
fsubp	st(1), st
fadd	st, st(0)
nop
fld	qword ptr [rbx]
fmul	qword ptr [rcx + 0x8]
fld	qword ptr [rdx]
fmul	qword ptr [rcx]
faddp	st(1), st
fadd	st, st(0)
nop
fld	qword ptr [rbx]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
fsubp	st(1), st
fadd	st, st(0)
nop
fld	qword ptr [rbx]
fmul	qword ptr [rdx]
fadd	st, st(0)
fadd	st, st(0)
fstp	qword ptr [rdx]
fstp	qword ptr [rbx]
fld	qword ptr [rbx]
fmul	st, st(0)
fld	qword ptr [rdx]
fmul	st, st(0)
faddp	st(1), st
fsqrt
fdivr	st, st(3)
fchs
fld1
faddp	st(1), st
fld	qword ptr [rbx]
fmul	st, st(1)
fstp	qword ptr [rbx]
fld	qword ptr [rdx]
fmulp	st(1), st
fstp	qword ptr [rdx]
fstp	qword ptr [rcx + 0x8]
fstp	qword ptr [rcx]
fstp	st(0)
fnop
fld	qword ptr [rsi + 0x18]
fadd	qword ptr [rbx]
fstp	qword ptr [rbx]
fld	qword ptr [rsi + 0x20]
fadd	qword ptr [rdx]
fstp	qword ptr [rdx]
fld	qword ptr [rsi + 0x28]
fadd	qword ptr [rcx]
fstp	qword ptr [rcx]
fld	qword ptr [rsi - 0x38]
fadd	qword ptr [rdi - 0x10]
fadd	qword ptr [rcx + 0x8]
fstp	qword ptr [rcx + 0x8]
fnop
pop rbx
ret
.globl _cubicquat_reference
_cubicquat_reference:
push rbx
mov r8,rdi
mov r9,rsi
mov rsi,rdx
mov rdi,r9
mov rax,r8
mov rbx,r8
lea rdx,[r8+8]
lea rcx,[r8+16]
fld	qword ptr [rdx]
fmul	st, st(0)
fmul	qword ptr [rdi - 0x18]
fld	qword ptr [rcx]
fmul	st, st(0)
fmul	qword ptr [rdi - 0x20]
fld	qword ptr [rcx + 0x8]
fmul	st, st(0)
fmul	qword ptr [rdi - 0x28]
faddp	st(1), st
faddp	st(1), st
fchs
fld	qword ptr [rax]
fmul	st, st(0)
fmul	qword ptr [rdi - 0x10]
faddp	st(1), st
fadd	qword ptr [rsi + 0x18]
fld	qword ptr [rsi + 0x20]
fmul	qword ptr [rdi - 0x38]
faddp	st(1), st
fnop
fld	qword ptr [rax]
fmul	qword ptr [rdx]
fmul	qword ptr [rdi - 0x18]
fadd	st, st(0)
fadd	qword ptr [rsi + 0x20]
fld	qword ptr [rsi + 0x18]
fmul	qword ptr [rdi - 0x40]
faddp	st(1), st
fnop
fld	qword ptr [rax]
fmul	qword ptr [rcx]
fmul	qword ptr [rdi - 0x20]
fadd	st, st(0)
fadd	qword ptr [rsi + 0x28]
fnop
fld	qword ptr [rax]
fmul	qword ptr [rcx + 0x8]
fmul	qword ptr [rdi - 0x28]
fadd	st, st(0)
fadd	qword ptr [rdi - 0x30]
fadd	qword ptr [rsi - 0x38]
fnop
fstp	qword ptr [rcx + 0x8]
fstp	qword ptr [rcx]
fstp	qword ptr [rdx]
fstp	qword ptr [rax]
fnop
pop rbx
ret
.globl _lambda4_reference
_lambda4_reference:
push rbx
mov r8,rdi
mov r9,rsi
mov rsi,rdx
mov rdi,r9
mov rax,r8
mov rbx,r8
lea rdx,[r8+8]
lea rcx,[r8+16]
fld	qword ptr [rbx]
nop
fmul	qword ptr [rbx]
fchs
nop
fld	qword ptr [rdx]
nop
fmul	qword ptr [rdx]
nop
nop
nop
faddp	st(1), st
fld	qword ptr [rcx]
nop
fmul	qword ptr [rcx]
nop
nop
nop
faddp	st(1), st
fld	qword ptr [rcx + 0x8]
fmul	qword ptr [rcx + 0x8]
fchs
faddp	st(1), st
fadd	qword ptr [rdi - 0x10]
fnop
fld	qword ptr [rbx]
nop
fmul	qword ptr [rdx]
fchs
nop
fadd	st, st(0)
fld	qword ptr [rcx]
nop
fmul	qword ptr [rcx + 0x8]
nop
nop
fadd	st, st(0)
faddp	st(1), st
fadd	qword ptr [rdi - 0x18]
fnop
fld	qword ptr [rbx]
nop
fmul	qword ptr [rcx]
fchs
nop
fadd	st, st(0)
fld	qword ptr [rdx]
nop
fmul	qword ptr [rcx + 0x8]
nop
nop
fadd	st, st(0)
faddp	st(1), st
fadd	qword ptr [rdi - 0x20]
fnop
fld	qword ptr [rbx]
nop
fmul	qword ptr [rcx + 0x8]
fchs
fadd	st, st(0)
fld	qword ptr [rdx]
nop
fmul	qword ptr [rcx]
fchs
nop
fadd	st, st(0)
faddp	st(1), st
fadd	qword ptr [rdi - 0x28]
fnop
fstp	qword ptr [rcx + 0x8]
fstp	qword ptr [rcx]
fstp	qword ptr [rdx]
fstp	qword ptr [rbx]
fld	qword ptr [rbx]
nop
fmul	qword ptr [rsi + 0x18]
nop
nop
fld	qword ptr [rdx]
nop
fmul	qword ptr [rsi + 0x20]
fchs
faddp	st(1), st
fld	qword ptr [rcx]
nop
fmul	qword ptr [rsi + 0x28]
fchs
faddp	st(1), st
fld	qword ptr [rcx + 0x8]
fmul	qword ptr [rsi - 0x38]
nop
nop
faddp	st(1), st
fnop
fld	qword ptr [rdx]
nop
fmul	qword ptr [rsi + 0x18]
nop
nop
fld	qword ptr [rbx]
nop
fmul	qword ptr [rsi + 0x20]
nop
nop
faddp	st(1), st
fld	qword ptr [rcx + 0x8]
fmul	qword ptr [rsi + 0x28]
fchs
faddp	st(1), st
fld	qword ptr [rcx]
nop
fmul	qword ptr [rsi - 0x38]
fchs
faddp	st(1), st
fnop
fld	qword ptr [rcx]
nop
fmul	qword ptr [rsi + 0x18]
nop
nop
fld	qword ptr [rcx + 0x8]
fmul	qword ptr [rsi + 0x20]
fchs
faddp	st(1), st
fld	qword ptr [rbx]
nop
fmul	qword ptr [rsi + 0x28]
nop
nop
faddp	st(1), st
fld	qword ptr [rdx]
nop
fmul	qword ptr [rsi - 0x38]
fchs
faddp	st(1), st
fnop
fld	qword ptr [rcx + 0x8]
fmul	qword ptr [rsi + 0x18]
nop
nop
fld	qword ptr [rcx]
nop
fmul	qword ptr [rsi + 0x20]
nop
nop
faddp	st(1), st
fld	qword ptr [rdx]
nop
fmul	qword ptr [rsi + 0x28]
nop
nop
faddp	st(1), st
fld	qword ptr [rbx]
nop
fmul	qword ptr [rsi - 0x38]
nop
nop
faddp	st(1), st
fnop
nop
fstp	qword ptr [rcx + 0x8]
fstp	qword ptr [rcx]
fstp	qword ptr [rdx]
fstp	qword ptr [rbx]
nop
pop rbx
ret
