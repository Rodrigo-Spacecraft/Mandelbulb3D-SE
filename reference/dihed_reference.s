.intel_syntax noprefix
.text
.globl _dihed_reference
_dihed_reference:
push rbp
mov rbp,rsp
sub rsp,96
push rbx
mov r8,rdx
mov rbx,rdi
lea rcx,[rdi+16]
lea rdx,[rdi+8]
mov rdi,rsi
mov rsi,r8
xor eax,eax
dihed_L14:
fnop
dihed_L16:
mov	ah, byte ptr [rdi - 0xc]
dihed_L19:
and	ah, 0x7
dihed_L1c:
fld	qword ptr [rbx]
dihed_L1e:
fmul	st, st(0)
dihed_L20:
fld	qword ptr [rdx]
dihed_L22:
fmul	st, st(0)
dihed_L24:
faddp	st(1), st
dihed_L26:
fld	st(0)
dihed_L28:
fld	qword ptr [rcx]
dihed_L2a:
fmul	st, st(0)
dihed_L2c:
faddp	st(1), st
dihed_L2e:
shl	eax, 0x10
dihed_L31:
fcom	qword ptr [rdi + 0x30]
dihed_L34:
wait
dihed_L35:
fnstsw	ax
dihed_L37:
shr	ah
dihed_L39:
jae	dihed_L203
dihed_L3f:
shr	eax, 0x10
dihed_L42:
fsqrt
dihed_L44:
fst	qword ptr [rbp - 0x48]
dihed_L47:
fld	qword ptr [rcx]
dihed_L49:
fdivrp	st(1), st
dihed_L4b:
fstp	qword ptr [rbp - 0x8]
dihed_L4e:
fsqrt
dihed_L50:
fsub	qword ptr [rdx]
dihed_L52:
fdiv	qword ptr [rbx]
dihed_L54:
fst	qword ptr [rbp - 0x10]
dihed_L57:
fmul	st, st(0)
dihed_L59:
fst	qword ptr [rbp - 0x28]
dihed_L5c:
fld1
dihed_L5e:
faddp	st(1), st
dihed_L60:
fld1
dihed_L62:
fdivrp	st(1), st
dihed_L64:
nop
dihed_L65:
fld1
dihed_L67:
fadd	qword ptr [rbp - 0x8]
dihed_L6a:
fld1
dihed_L6c:
fsub	qword ptr [rbp - 0x8]
dihed_L6f:
fdivrp	st(1), st
dihed_L71:
fsqrt
dihed_L73:
nop
dihed_L74:
fmulp	st(1), st
dihed_L76:
fld	st(0)
dihed_L78:
fadd	st, st(0)
dihed_L7a:
fmul	qword ptr [rbp - 0x10]
dihed_L7d:
fstp	qword ptr [rbx]
dihed_L7f:
nop
dihed_L80:
fld1
dihed_L82:
fsub	qword ptr [rbp - 0x28]
dihed_L85:
fmulp	st(1), st
dihed_L87:
fstp	qword ptr [rdx]
dihed_L89:
fnop
dihed_L8b:
mov	al, byte ptr [rdi - 0x10]
dihed_L8e:
and	al, 0x7
dihed_L90:
nop
dihed_L91:
fld	qword ptr [rbx]
dihed_L93:
fmul	st, st(0)
dihed_L95:
fld	qword ptr [rdx]
dihed_L97:
fmul	st, st(0)
dihed_L99:
faddp	st(1), st
dihed_L9b:
shl	eax, 0x10
dihed_L9e:
fcom	qword ptr [rdi + 0x30]
dihed_La1:
wait
dihed_La2:
fnstsw	ax
dihed_La4:
shr	ah
dihed_La6:
jae	dihed_L205
dihed_Lac:
shr	eax, 0x10
dihed_Laf:
fstp	qword ptr [rbp - 0x18]
dihed_Lb2:
nop
dihed_Lb3:
fld	qword ptr [rdx]
dihed_Lb5:
fchs
dihed_Lb7:
fld	qword ptr [rbp - 0x18]
dihed_Lba:
fld1
dihed_Lbc:
faddp	st(1), st
dihed_Lbe:
fmulp	st(1), st
dihed_Lc0:
fld	qword ptr [rbp - 0x18]
dihed_Lc3:
fld	qword ptr [rbx]
dihed_Lc5:
fmul	qword ptr [rdi + 0x28]
dihed_Lc8:
fsubp	st(1), st
dihed_Lca:
fld1
dihed_Lcc:
fsubp	st(1), st
dihed_Lce:
fmulp	st(1), st
dihed_Ld0:
fld	qword ptr [rbp - 0x18]
dihed_Ld3:
fld	qword ptr [rbx]
dihed_Ld5:
fmul	qword ptr [rdi + 0x28]
dihed_Ld8:
faddp	st(1), st
dihed_Lda:
fld1
dihed_Ldc:
fsubp	st(1), st
dihed_Lde:
fmulp	st(1), st
dihed_Le0:
fstp	qword ptr [rbp - 0x8]
dihed_Le3:
fld	qword ptr [rbx]
dihed_Le5:
fld	qword ptr [rbp - 0x18]
dihed_Le8:
fld1
dihed_Lea:
fsubp	st(1), st
dihed_Lec:
fmulp	st(1), st
dihed_Lee:
fld	qword ptr [rbp - 0x18]
dihed_Lf1:
fmul	st, st(0)
dihed_Lf3:
fld	qword ptr [rbp - 0x18]
dihed_Lf6:
fmul	qword ptr [rdi + 0x28]
dihed_Lf9:
faddp	st(1), st
dihed_Lfb:
fld	qword ptr [rdx]
dihed_Lfd:
fmul	qword ptr [rdi + 0x28]
dihed_L100:
fmul	st, st(0)
dihed_L102:
faddp	st(1), st
dihed_L104:
fld1
dihed_L106:
faddp	st(1), st
dihed_L108:
fmulp	st(1), st
dihed_L10a:
fstp	qword ptr [rbp - 0x10]
dihed_L10d:
fld	qword ptr [rbp - 0x18]
dihed_L110:
fld	qword ptr [rdx]
dihed_L112:
fmul	qword ptr [rdi + 0x28]
dihed_L115:
fsubp	st(1), st
dihed_L117:
fld1
dihed_L119:
faddp	st(1), st
dihed_L11b:
fld	qword ptr [rbp - 0x18]
dihed_L11e:
fld	qword ptr [rdx]
dihed_L120:
fmul	qword ptr [rdi + 0x28]
dihed_L123:
faddp	st(1), st
dihed_L125:
fld1
dihed_L127:
faddp	st(1), st
dihed_L129:
fmulp	st(1), st
dihed_L12b:
fmul	st, st(0)
dihed_L12d:
fld	qword ptr [rdi + 0x28]
dihed_L130:
fdivrp	st(1), st
dihed_L132:
fld	st(0)
dihed_L134:
fmul	qword ptr [rbp - 0x10]
dihed_L137:
fstp	qword ptr [rbx]
dihed_L139:
fmul	qword ptr [rbp - 0x8]
dihed_L13c:
fstp	qword ptr [rdx]
dihed_L13e:
fld	qword ptr [rbp - 0x48]
dihed_L141:
fmul	st, st(0)
dihed_L143:
fstp	qword ptr [rbp - 0x48]
dihed_L146:
nop
dihed_L147:
nop
dihed_L148:
dec	al
dihed_L14a:
jg	dihed_L91
dihed_L150:
nop
dihed_L151:
nop
dihed_L152:
nop
dihed_L153:
nop
dihed_L154:
nop
dihed_L155:
nop
dihed_L156:
nop
dihed_L157:
nop
dihed_L158:
fnop
dihed_L15a:
fld	qword ptr [rbx]
dihed_L15c:
fmul	st, st(0)
dihed_L15e:
fld	qword ptr [rdx]
dihed_L160:
fmul	st, st(0)
dihed_L162:
faddp	st(1), st
dihed_L164:
fst	qword ptr [rbp - 0x40]
dihed_L167:
fsqrt
dihed_L169:
fst	qword ptr [rbp - 0x18]
dihed_L16c:
fsub	qword ptr [rdx]
dihed_L16e:
fdiv	qword ptr [rbx]
dihed_L170:
fst	qword ptr [rbp - 0x10]
dihed_L173:
fmul	st, st(0)
dihed_L175:
fst	qword ptr [rbp - 0x28]
dihed_L178:
fld1
dihed_L17a:
faddp	st(1), st
dihed_L17c:
fld1
dihed_L17e:
fdivrp	st(1), st
dihed_L180:
fst	qword ptr [rbp - 0x20]
dihed_L183:
fld1
dihed_L185:
fsub	qword ptr [rbp - 0x28]
dihed_L188:
fmulp	st(1), st
dihed_L18a:
fstp	qword ptr [rbp - 0x38]
dihed_L18d:
nop
dihed_L18e:
fld	qword ptr [rbp - 0x10]
dihed_L191:
fadd	st, st(0)
dihed_L193:
fmul	qword ptr [rbp - 0x20]
dihed_L196:
fstp	qword ptr [rbp - 0x30]
dihed_L199:
nop
dihed_L19a:
fld1
dihed_L19c:
fadd	qword ptr [rbp - 0x40]
dihed_L19f:
fld	qword ptr [rdi + 0x28]
dihed_L1a2:
fdivrp	st(1), st
dihed_L1a4:
fst	qword ptr [rbp - 0x28]
dihed_L1a7:
fmul	qword ptr [rbp - 0x18]
dihed_L1aa:
fstp	qword ptr [rbp - 0x20]
dihed_L1ad:
nop
dihed_L1ae:
nop
dihed_L1af:
fld	qword ptr [rbp - 0x48]
dihed_L1b2:
fmul	qword ptr [rbp - 0x30]
dihed_L1b5:
fmul	qword ptr [rbp - 0x20]
dihed_L1b8:
nop
dihed_L1b9:
fld	qword ptr [rbp - 0x48]
dihed_L1bc:
fmul	qword ptr [rbp - 0x38]
dihed_L1bf:
fmul	qword ptr [rbp - 0x20]
dihed_L1c2:
nop
dihed_L1c3:
fld	qword ptr [rbp - 0x28]
dihed_L1c6:
fld1
dihed_L1c8:
fsubp	st(1), st
dihed_L1ca:
fmul	qword ptr [rbp - 0x48]
dihed_L1cd:
nop
dihed_L1ce:
nop
dihed_L1cf:
fstp	qword ptr [rcx]
dihed_L1d1:
fstp	qword ptr [rdx]
dihed_L1d3:
fstp	qword ptr [rbx]
dihed_L1d5:
fnop
dihed_L1d7:
dec	ah
dihed_L1d9:
cmp	ah, 0x0
dihed_L1dc:
jg	dihed_L1c
dihed_L1e2:
fld	qword ptr [rbx]
dihed_L1e4:
fadd	qword ptr [rsi + 0x18]
dihed_L1e7:
fld	qword ptr [rdx]
dihed_L1e9:
fadd	qword ptr [rsi + 0x20]
dihed_L1ec:
fld	qword ptr [rcx]
dihed_L1ee:
fadd	qword ptr [rsi + 0x28]
dihed_L1f1:
fstp	qword ptr [rcx]
dihed_L1f3:
fstp	qword ptr [rdx]
dihed_L1f5:
fstp	qword ptr [rbx]
dihed_L1f7:
nop
pop rbx
add rsp,96
pop rbp
ret
dihed_L203:
fstp	st(0)
dihed_L205:
fstp	st(0)
dihed_L207:
fld	qword ptr [rdi + 0x30]
dihed_L20a:
fld	st(0)
dihed_L20c:
fld	st(0)
dihed_L20e:
jmp	dihed_L1f1
