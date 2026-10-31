.intel_syntax noprefix
.text
.globl _menger_reference
_menger_reference:
push rbp
mov rbp,rsp
sub rsp,48
push rbx
mov rax,rdi
mov rbx,rdi
lea rdx,[rdi+8]
lea rcx,[rdi+16]
mov rdi,rsi
menger_reference_L14:
fnop
menger_reference_L16:
fld	qword ptr [rdi - 0x54]
menger_reference_L19:
fabs
menger_reference_L1b:
fstp	qword ptr [rbp - 0x8]
menger_reference_L1e:
fld	qword ptr [rdi - 0x5c]
menger_reference_L21:
fabs
menger_reference_L23:
fstp	qword ptr [rbp - 0x18]
menger_reference_L26:
fld	qword ptr [rdi - 0x54]
menger_reference_L29:
fldz
menger_reference_L2b:
fcompp
menger_reference_L2d:
wait
menger_reference_L2e:
fnstsw	ax
menger_reference_L30:
and	ah, 0x41
menger_reference_L33:
jne	menger_reference_L7e
menger_reference_L39:
fld	qword ptr [rbx]
menger_reference_L3b:
fabs
menger_reference_L3d:
fld	st(0)
menger_reference_L3f:
fmul	st, st(0)
menger_reference_L41:
fst	qword ptr [rbp - 0x10]
menger_reference_L44:
fmulp	st(1), st
menger_reference_L46:
fld	qword ptr [rbp - 0x10]
menger_reference_L49:
fadd	qword ptr [rbp - 0x8]
menger_reference_L4c:
fdivp	st(1), st
menger_reference_L4e:
fld	qword ptr [rdx]
menger_reference_L50:
fabs
menger_reference_L52:
fld	st(0)
menger_reference_L54:
fmul	st, st(0)
menger_reference_L56:
fst	qword ptr [rbp - 0x10]
menger_reference_L59:
fmulp	st(1), st
menger_reference_L5b:
fld	qword ptr [rbp - 0x10]
menger_reference_L5e:
fadd	qword ptr [rbp - 0x8]
menger_reference_L61:
fdivp	st(1), st
menger_reference_L63:
fld	qword ptr [rcx]
menger_reference_L65:
fabs
menger_reference_L67:
fld	st(0)
menger_reference_L69:
fmul	st, st(0)
menger_reference_L6b:
fst	qword ptr [rbp - 0x10]
menger_reference_L6e:
fmulp	st(1), st
menger_reference_L70:
fld	qword ptr [rbp - 0x10]
menger_reference_L73:
fadd	qword ptr [rbp - 0x8]
menger_reference_L76:
fdivp	st(1), st
menger_reference_L78:
jmp	menger_reference_L99
menger_reference_L7d:
nop
menger_reference_L7e:
fld	qword ptr [rbx]
menger_reference_L80:
fmul	st, st(0)
menger_reference_L82:
fadd	qword ptr [rbp - 0x8]
menger_reference_L85:
fsqrt
menger_reference_L87:
fld	qword ptr [rdx]
menger_reference_L89:
fmul	st, st(0)
menger_reference_L8b:
fadd	qword ptr [rbp - 0x8]
menger_reference_L8e:
fsqrt
menger_reference_L90:
fld	qword ptr [rcx]
menger_reference_L92:
fmul	st, st(0)
menger_reference_L94:
fadd	qword ptr [rbp - 0x8]
menger_reference_L97:
fsqrt
menger_reference_L99:
fstp	qword ptr [rcx]
menger_reference_L9b:
fstp	qword ptr [rdx]
menger_reference_L9d:
fstp	qword ptr [rbx]
menger_reference_L9f:
fnop
menger_reference_La1:
fld	qword ptr [rdi - 0x5c]
menger_reference_La4:
fldz
menger_reference_La6:
fcompp
menger_reference_La8:
wait
menger_reference_La9:
fnstsw	ax
menger_reference_Lab:
and	ah, 0x41
menger_reference_Lae:
jne	menger_reference_L156
menger_reference_Lb4:
fld	qword ptr [rbx]
menger_reference_Lb6:
fsub	qword ptr [rdx]
menger_reference_Lb8:
fld	st(0)
menger_reference_Lba:
fabs
menger_reference_Lbc:
fld	st(0)
menger_reference_Lbe:
fmul	st, st(0)
menger_reference_Lc0:
fst	qword ptr [rbp - 0x10]
menger_reference_Lc3:
fmulp	st(1), st
menger_reference_Lc5:
fld	qword ptr [rbp - 0x10]
menger_reference_Lc8:
fadd	qword ptr [rbp - 0x18]
menger_reference_Lcb:
fdivp	st(1), st
menger_reference_Lcd:
fchs
menger_reference_Lcf:
faddp	st(1), st
menger_reference_Ld1:
fmul	qword ptr [rdi]
menger_reference_Ld3:
fstp	qword ptr [rbp - 0x10]
menger_reference_Ld6:
nop
menger_reference_Ld7:
fld	qword ptr [rbx]
menger_reference_Ld9:
fsub	qword ptr [rbp - 0x10]
menger_reference_Ldc:
nop
menger_reference_Ldd:
fld	qword ptr [rdx]
menger_reference_Ldf:
fadd	qword ptr [rbp - 0x10]
menger_reference_Le2:
nop
menger_reference_Le3:
fstp	qword ptr [rdx]
menger_reference_Le5:
fstp	qword ptr [rbx]
menger_reference_Le7:
fnop
menger_reference_Le9:
fld	qword ptr [rbx]
menger_reference_Leb:
fsub	qword ptr [rcx]
menger_reference_Led:
fld	st(0)
menger_reference_Lef:
fabs
menger_reference_Lf1:
fld	st(0)
menger_reference_Lf3:
fmul	st, st(0)
menger_reference_Lf5:
fst	qword ptr [rbp - 0x10]
menger_reference_Lf8:
fmulp	st(1), st
menger_reference_Lfa:
fld	qword ptr [rbp - 0x10]
menger_reference_Lfd:
fadd	qword ptr [rbp - 0x18]
menger_reference_L100:
fdivp	st(1), st
menger_reference_L102:
fchs
menger_reference_L104:
faddp	st(1), st
menger_reference_L106:
fmul	qword ptr [rdi]
menger_reference_L108:
fstp	qword ptr [rbp - 0x10]
menger_reference_L10b:
nop
menger_reference_L10c:
fld	qword ptr [rbx]
menger_reference_L10e:
fsub	qword ptr [rbp - 0x10]
menger_reference_L111:
nop
menger_reference_L112:
fld	qword ptr [rcx]
menger_reference_L114:
fadd	qword ptr [rbp - 0x10]
menger_reference_L117:
nop
menger_reference_L118:
fstp	qword ptr [rcx]
menger_reference_L11a:
fstp	qword ptr [rbx]
menger_reference_L11c:
fnop
menger_reference_L11e:
fld	qword ptr [rdx]
menger_reference_L120:
fsub	qword ptr [rcx]
menger_reference_L122:
fld	st(0)
menger_reference_L124:
fabs
menger_reference_L126:
fld	st(0)
menger_reference_L128:
fmul	st, st(0)
menger_reference_L12a:
fst	qword ptr [rbp - 0x10]
menger_reference_L12d:
fmulp	st(1), st
menger_reference_L12f:
fld	qword ptr [rbp - 0x10]
menger_reference_L132:
fadd	qword ptr [rbp - 0x18]
menger_reference_L135:
fdivp	st(1), st
menger_reference_L137:
fchs
menger_reference_L139:
faddp	st(1), st
menger_reference_L13b:
fmul	qword ptr [rdi]
menger_reference_L13d:
fstp	qword ptr [rbp - 0x10]
menger_reference_L140:
nop
menger_reference_L141:
fld	qword ptr [rdx]
menger_reference_L143:
fsub	qword ptr [rbp - 0x10]
menger_reference_L146:
nop
menger_reference_L147:
fld	qword ptr [rcx]
menger_reference_L149:
fadd	qword ptr [rbp - 0x10]
menger_reference_L14c:
nop
menger_reference_L14d:
fstp	qword ptr [rcx]
menger_reference_L14f:
fstp	qword ptr [rdx]
menger_reference_L151:
jmp	menger_reference_L1d1
menger_reference_L156:
fld	qword ptr [rbx]
menger_reference_L158:
fsub	qword ptr [rdx]
menger_reference_L15a:
fld	st(0)
menger_reference_L15c:
fmul	st, st(0)
menger_reference_L15e:
fadd	qword ptr [rbp - 0x18]
menger_reference_L161:
fsqrt
menger_reference_L163:
fchs
menger_reference_L165:
faddp	st(1), st
menger_reference_L167:
fmul	qword ptr [rdi]
menger_reference_L169:
fstp	qword ptr [rbp - 0x10]
menger_reference_L16c:
nop
menger_reference_L16d:
fld	qword ptr [rbx]
menger_reference_L16f:
fsub	qword ptr [rbp - 0x10]
menger_reference_L172:
nop
menger_reference_L173:
fld	qword ptr [rdx]
menger_reference_L175:
fadd	qword ptr [rbp - 0x10]
menger_reference_L178:
nop
menger_reference_L179:
fstp	qword ptr [rdx]
menger_reference_L17b:
fstp	qword ptr [rbx]
menger_reference_L17d:
fnop
menger_reference_L17f:
fld	qword ptr [rbx]
menger_reference_L181:
fsub	qword ptr [rcx]
menger_reference_L183:
fld	st(0)
menger_reference_L185:
fmul	st, st(0)
menger_reference_L187:
fadd	qword ptr [rbp - 0x18]
menger_reference_L18a:
fsqrt
menger_reference_L18c:
fchs
menger_reference_L18e:
faddp	st(1), st
menger_reference_L190:
fmul	qword ptr [rdi]
menger_reference_L192:
fstp	qword ptr [rbp - 0x10]
menger_reference_L195:
nop
menger_reference_L196:
fld	qword ptr [rbx]
menger_reference_L198:
fsub	qword ptr [rbp - 0x10]
menger_reference_L19b:
nop
menger_reference_L19c:
fld	qword ptr [rcx]
menger_reference_L19e:
fadd	qword ptr [rbp - 0x10]
menger_reference_L1a1:
nop
menger_reference_L1a2:
fstp	qword ptr [rcx]
menger_reference_L1a4:
fstp	qword ptr [rbx]
menger_reference_L1a6:
fnop
menger_reference_L1a8:
fld	qword ptr [rdx]
menger_reference_L1aa:
fsub	qword ptr [rcx]
menger_reference_L1ac:
fld	st(0)
menger_reference_L1ae:
fmul	st, st(0)
menger_reference_L1b0:
fadd	qword ptr [rbp - 0x18]
menger_reference_L1b3:
fsqrt
menger_reference_L1b5:
fchs
menger_reference_L1b7:
faddp	st(1), st
menger_reference_L1b9:
fmul	qword ptr [rdi]
menger_reference_L1bb:
fstp	qword ptr [rbp - 0x10]
menger_reference_L1be:
nop
menger_reference_L1bf:
fld	qword ptr [rdx]
menger_reference_L1c1:
fsub	qword ptr [rbp - 0x10]
menger_reference_L1c4:
nop
menger_reference_L1c5:
fld	qword ptr [rcx]
menger_reference_L1c7:
fadd	qword ptr [rbp - 0x10]
menger_reference_L1ca:
nop
menger_reference_L1cb:
fstp	qword ptr [rcx]
menger_reference_L1cd:
fstp	qword ptr [rdx]
menger_reference_L1cf:
fnop
menger_reference_L1d1:
fld	qword ptr [rcx]
menger_reference_L1d3:
fld	qword ptr [rbx]
menger_reference_L1d5:
fld	qword ptr [rdx]
menger_reference_L1d7:
fld	st(1)
menger_reference_L1d9:
fmul	dword ptr [rdi - 0x44]
menger_reference_L1dc:
fld	st(1)
menger_reference_L1de:
fmul	dword ptr [rdi - 0x48]
menger_reference_L1e1:
faddp	st(1), st
menger_reference_L1e3:
fld	st(3)
menger_reference_L1e5:
fmul	dword ptr [rdi - 0x4c]
menger_reference_L1e8:
faddp	st(1), st
menger_reference_L1ea:
fld	st(2)
menger_reference_L1ec:
fmul	dword ptr [rdi - 0x2c]
menger_reference_L1ef:
fld	st(2)
menger_reference_L1f1:
fmul	dword ptr [rdi - 0x30]
menger_reference_L1f4:
faddp	st(1), st
menger_reference_L1f6:
fld	st(4)
menger_reference_L1f8:
fmul	dword ptr [rdi - 0x34]
menger_reference_L1fb:
faddp	st(1), st
menger_reference_L1fd:
fxch	st(3)
menger_reference_L1ff:
fmul	dword ptr [rdi - 0x38]
menger_reference_L202:
fxch	st(2)
menger_reference_L204:
fmul	dword ptr [rdi - 0x3c]
menger_reference_L207:
faddp	st(2), st
menger_reference_L209:
fxch	st(3)
menger_reference_L20b:
fmul	dword ptr [rdi - 0x40]
menger_reference_L20e:
faddp	st(1), st
menger_reference_L210:
fld	qword ptr [rdi - 0x10]
menger_reference_L213:
fld	qword ptr [rcx + 0x8]
menger_reference_L216:
fmul	st, st(1)
menger_reference_L218:
fstp	qword ptr [rcx + 0x8]
menger_reference_L21b:
fmul	st(2), st
menger_reference_L21d:
fmul	st(1), st
menger_reference_L21f:
fld	st(0)
menger_reference_L221:
fld1
menger_reference_L223:
fsubp	st(1), st
menger_reference_L225:
fld	st(0)
menger_reference_L227:
fld	st(0)
menger_reference_L229:
fmul	qword ptr [rdi - 0x18]
menger_reference_L22c:
fsubp	st(5), st
menger_reference_L22e:
fmul	qword ptr [rdi - 0x20]
menger_reference_L231:
fsubp	st(3), st
menger_reference_L233:
fdiv	st, st(1)
menger_reference_L235:
fmul	qword ptr [rdi - 0x28]
menger_reference_L238:
fsub	st(4), st
menger_reference_L23a:
fxch	st(4)
menger_reference_L23c:
fld	qword ptr [rdi - 0x54]
menger_reference_L23f:
fldz
menger_reference_L241:
fcompp
menger_reference_L243:
wait
menger_reference_L244:
fnstsw	ax
menger_reference_L246:
and	ah, 0x41
menger_reference_L249:
jne	menger_reference_L268
menger_reference_L24f:
fabs
menger_reference_L251:
fld	st(0)
menger_reference_L253:
fmul	st, st(0)
menger_reference_L255:
fst	qword ptr [rbp - 0x10]
menger_reference_L258:
fmulp	st(1), st
menger_reference_L25a:
fld	qword ptr [rbp - 0x10]
menger_reference_L25d:
fadd	qword ptr [rbp - 0x8]
menger_reference_L260:
fdivp	st(1), st
menger_reference_L262:
jmp	menger_reference_L26f
menger_reference_L267:
nop
menger_reference_L268:
fmul	st, st(0)
menger_reference_L26a:
fadd	qword ptr [rbp - 0x8]
menger_reference_L26d:
fsqrt
menger_reference_L26f:
fsubp	st(4), st
menger_reference_L271:
fmulp	st(3), st
menger_reference_L273:
fstp	qword ptr [rdx]
menger_reference_L275:
fstp	qword ptr [rbx]
menger_reference_L277:
fstp	qword ptr [rcx]
menger_reference_L279:
fnop
pop rbx
mov rsp,rbp
pop rbp
ret
.globl _reciprocal_reference
_reciprocal_reference:
push rbp
mov rbp,rsp
sub rsp,48
push rbx
mov rax,rdi
mov rbx,rdi
lea rdx,[rdi+8]
lea rcx,[rdi+16]
mov rdi,rsi
reciprocal_reference_L5:
fld	qword ptr [rdx]
reciprocal_reference_La:
mov	cl, byte ptr [rdx + 0x7]
reciprocal_reference_L10:
fmul	qword ptr [rsi - 0x30]
reciprocal_reference_L13:
fabs
reciprocal_reference_L15:
fadd	qword ptr [rsi - 0x10]
reciprocal_reference_L18:
fld1
reciprocal_reference_L1a:
fdivrp	st(1), st
reciprocal_reference_L1c:
fchs
reciprocal_reference_L1e:
fadd	qword ptr [rsi - 0x18]
reciprocal_reference_L21:
fld	qword ptr [rdx]
reciprocal_reference_L23:
fmul	st, st(0)
reciprocal_reference_L25:
fmul	qword ptr [rsi - 0x38]
reciprocal_reference_L28:
fabs
reciprocal_reference_L2a:
fadd	qword ptr [rsi - 0x20]
reciprocal_reference_L2d:
and	cl, -0x80
reciprocal_reference_L30:
fld1
reciprocal_reference_L32:
fdivrp	st(1), st
reciprocal_reference_L34:
fchs
reciprocal_reference_L36:
fadd	qword ptr [rsi - 0x28]
reciprocal_reference_L39:
faddp	st(1), st
reciprocal_reference_L3b:
fstp	qword ptr [rdx]
reciprocal_reference_L3d:
xor	byte ptr [rdx + 0x7], cl
pop rbx
mov rsp,rbp
pop rbp
ret
