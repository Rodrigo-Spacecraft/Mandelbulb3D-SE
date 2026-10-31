.intel_syntax noprefix
.text
.globl _sierp_reference
_sierp_reference:
push rbx
mov rbx,rdi
lea rcx,[rdi+16]
lea rdx,[rdi+8]
sierp_reference_Ld:
fld	qword ptr [rcx]
sierp_reference_Lf:
fld	qword ptr [rdx]
sierp_reference_L11:
fld	qword ptr [rbx]
sierp_reference_L13:
fld	st(0)
sierp_reference_L15:
fmul	dword ptr [rsi - 68]
sierp_reference_L18:
fld	st(2)
sierp_reference_L1a:
fmul	dword ptr [rsi - 72]
sierp_reference_L1d:
faddp	st(1), st
sierp_reference_L1f:
fld	st(3)
sierp_reference_L21:
fmul	dword ptr [rsi - 76]
sierp_reference_L24:
faddp	st(1), st
sierp_reference_L26:
fld	st(1)
sierp_reference_L28:
fmul	dword ptr [rsi - 44]
sierp_reference_L2b:
fld	st(3)
sierp_reference_L2d:
fmul	dword ptr [rsi - 48]
sierp_reference_L30:
faddp	st(1), st
sierp_reference_L32:
fld	st(4)
sierp_reference_L34:
fmul	dword ptr [rsi - 52]
sierp_reference_L37:
faddp	st(1), st
sierp_reference_L39:
fxch	st(2)
sierp_reference_L3b:
fmul	dword ptr [rsi - 56]
sierp_reference_L3e:
fxch	st(3)
sierp_reference_L40:
fmul	dword ptr [rsi - 60]
sierp_reference_L43:
faddp	st(3), st
sierp_reference_L45:
fxch	st(3)
sierp_reference_L47:
fmul	dword ptr [rsi - 64]
sierp_reference_L4a:
faddp	st(2), st
sierp_reference_L4c:
cmp	dword ptr [rsi - 132], 0
sierp_reference_L53:
jne	sierp_reference_La6
sierp_reference_L59:
nop
sierp_reference_L5a:
fxch	st(1)
sierp_reference_L5c:
fcom	st(1)
sierp_reference_L5e:
fnstsw	ax
sierp_reference_L60:
shr	ah
sierp_reference_L62:
jae	sierp_reference_L66
sierp_reference_L64:
fxch	st(1)
sierp_reference_L66:
fcom	st(2)
sierp_reference_L68:
fnstsw	ax
sierp_reference_L6a:
shr	ah
sierp_reference_L6c:
jae	sierp_reference_L70
sierp_reference_L6e:
fxch	st(2)
sierp_reference_L70:
fxch	st(1)
sierp_reference_L72:
fcom	st(2)
sierp_reference_L74:
fnstsw	ax
sierp_reference_L76:
shr	ah
sierp_reference_L78:
jae	sierp_reference_L7c
sierp_reference_L7a:
fxch	st(2)
sierp_reference_L7c:
fchs
sierp_reference_L7e:
fcom	st(1)
sierp_reference_L80:
fnstsw	ax
sierp_reference_L82:
shr	ah
sierp_reference_L84:
jb	sierp_reference_L88
sierp_reference_L86:
fxch	st(1)
sierp_reference_L88:
fcom	st(2)
sierp_reference_L8a:
fnstsw	ax
sierp_reference_L8c:
shr	ah
sierp_reference_L8e:
jb	sierp_reference_L92
sierp_reference_L90:
fxch	st(2)
sierp_reference_L92:
fchs
sierp_reference_L94:
fxch	st(1)
sierp_reference_L96:
fchs
sierp_reference_L98:
fcom	st(2)
sierp_reference_L9a:
fnstsw	ax
sierp_reference_L9c:
shr	ah
sierp_reference_L9e:
jb	sierp_reference_La2
sierp_reference_La0:
fxch	st(2)
sierp_reference_La2:
fchs
sierp_reference_La4:
jmp	sierp_reference_Lf1
sierp_reference_La6:
fchs
sierp_reference_La8:
fcom	st(1)
sierp_reference_Laa:
fnstsw	ax
sierp_reference_Lac:
shr	ah
sierp_reference_Lae:
jb	sierp_reference_Lb2
sierp_reference_Lb0:
fxch	st(1)
sierp_reference_Lb2:
fcom	st(2)
sierp_reference_Lb4:
fnstsw	ax
sierp_reference_Lb6:
shr	ah
sierp_reference_Lb8:
jb	sierp_reference_Lbc
sierp_reference_Lba:
fxch	st(2)
sierp_reference_Lbc:
fchs
sierp_reference_Lbe:
fxch	st(1)
sierp_reference_Lc0:
fchs
sierp_reference_Lc2:
fcom	st(2)
sierp_reference_Lc4:
fnstsw	ax
sierp_reference_Lc6:
shr	ah
sierp_reference_Lc8:
jb	sierp_reference_Lcc
sierp_reference_Lca:
fxch	st(2)
sierp_reference_Lcc:
fchs
sierp_reference_Lce:
fxch	st(1)
sierp_reference_Ld0:
fcom	st(1)
sierp_reference_Ld2:
fnstsw	ax
sierp_reference_Ld4:
shr	ah
sierp_reference_Ld6:
jae	sierp_reference_Lda
sierp_reference_Ld8:
fxch	st(1)
sierp_reference_Lda:
fcom	st(2)
sierp_reference_Ldc:
fnstsw	ax
sierp_reference_Lde:
shr	ah
sierp_reference_Le0:
jae	sierp_reference_Le4
sierp_reference_Le2:
fxch	st(2)
sierp_reference_Le4:
fxch	st(1)
sierp_reference_Le6:
fcom	st(2)
sierp_reference_Le8:
fnstsw	ax
sierp_reference_Lea:
shr	ah
sierp_reference_Lec:
jae	sierp_reference_Lf0
sierp_reference_Lee:
fxch	st(2)
sierp_reference_Lf0:
nop
sierp_reference_Lf1:
fld	qword ptr [rsi - 120]
sierp_reference_Lf4:
fldz
sierp_reference_Lf6:
fcomp	st(1)
sierp_reference_Lf8:
fnstsw	ax
sierp_reference_Lfa:
shr	ah
sierp_reference_Lfc:
jae	sierp_reference_L109
sierp_reference_Lfe:
fsub	st, st(2)
sierp_reference_L100:
fabs
sierp_reference_L102:
fchs
sierp_reference_L104:
fadd	qword ptr [rsi - 120]
sierp_reference_L107:
fxch	st(2)
sierp_reference_L109:
fstp	st(0)
sierp_reference_L10b:
nop
sierp_reference_L10c:
nop
sierp_reference_L10d:
fld	qword ptr [rsi - 128]
sierp_reference_L110:
fldz
sierp_reference_L112:
fcomp	st(1)
sierp_reference_L114:
fnstsw	ax
sierp_reference_L116:
shr	ah
sierp_reference_L118:
jae	sierp_reference_L125
sierp_reference_L11a:
fsub	st, st(1)
sierp_reference_L11c:
fabs
sierp_reference_L11e:
fchs
sierp_reference_L120:
fadd	qword ptr [rsi - 128]
sierp_reference_L123:
fxch	st(1)
sierp_reference_L125:
fstp	st(0)
sierp_reference_L127:
nop
sierp_reference_L128:
fld	st(0)
sierp_reference_L12a:
fmul	dword ptr [rsi - 104]
sierp_reference_L12d:
fld	st(2)
sierp_reference_L12f:
fmul	dword ptr [rsi - 108]
sierp_reference_L132:
faddp	st(1), st
sierp_reference_L134:
fld	st(3)
sierp_reference_L136:
fmul	dword ptr [rsi - 112]
sierp_reference_L139:
faddp	st(1), st
sierp_reference_L13b:
fld	st(1)
sierp_reference_L13d:
fmul	dword ptr [rsi - 80]
sierp_reference_L140:
fld	st(3)
sierp_reference_L142:
fmul	dword ptr [rsi - 84]
sierp_reference_L145:
faddp	st(1), st
sierp_reference_L147:
fld	st(4)
sierp_reference_L149:
fmul	dword ptr [rsi - 88]
sierp_reference_L14c:
faddp	st(1), st
sierp_reference_L14e:
fxch	st(2)
sierp_reference_L150:
fmul	dword ptr [rsi - 92]
sierp_reference_L153:
fxch	st(3)
sierp_reference_L155:
fmul	dword ptr [rsi - 96]
sierp_reference_L158:
faddp	st(3), st
sierp_reference_L15a:
fxch	st(3)
sierp_reference_L15c:
fmul	dword ptr [rsi - 100]
sierp_reference_L15f:
faddp	st(2), st
sierp_reference_L161:
fld	qword ptr [rsi - 16]
sierp_reference_L164:
fld	qword ptr [rcx + 8]
sierp_reference_L167:
fmul	st, st(1)
sierp_reference_L169:
fstp	qword ptr [rcx + 8]
sierp_reference_L16c:
fmul	st(3), st
sierp_reference_L16e:
fmul	st(2), st
sierp_reference_L170:
fmul	st(1), st
sierp_reference_L172:
fld1
sierp_reference_L174:
fsubp	st(1), st
sierp_reference_L176:
fld	st(0)
sierp_reference_L178:
fmul	qword ptr [rsi - 40]
sierp_reference_L17b:
fsubp	st(4), st
sierp_reference_L17d:
fld	st(0)
sierp_reference_L17f:
fmul	qword ptr [rsi - 32]
sierp_reference_L182:
fsubp	st(3), st
sierp_reference_L184:
fmul	qword ptr [rsi - 24]
sierp_reference_L187:
fsubp	st(1), st
sierp_reference_L189:
fstp	qword ptr [rbx]
sierp_reference_L18b:
fstp	qword ptr [rdx]
sierp_reference_L18d:
fstp	qword ptr [rcx]
pop rbx
ret
.globl _transform_reference
_transform_reference:
mov r8,rdx
mov rax,rdi
lea rcx,[rdi+16]
lea rdx,[rdi+8]
mov rdi,rsi
mov rsi,r8
transform_reference_Lb:
fld	qword ptr [rcx]
transform_reference_Ld:
fadd	qword ptr [rdi - 40]
transform_reference_L10:
fld	qword ptr [rdx]
transform_reference_L12:
fadd	qword ptr [rdi - 32]
transform_reference_L15:
fld	qword ptr [rax]
transform_reference_L17:
fadd	qword ptr [rdi - 24]
transform_reference_L1a:
fld	st(0)
transform_reference_L1c:
fmul	qword ptr [rdi - 96]
transform_reference_L1f:
fld	st(2)
transform_reference_L21:
fmul	qword ptr [rdi - 104]
transform_reference_L24:
faddp	st(1), st
transform_reference_L26:
fld	st(3)
transform_reference_L28:
fmul	qword ptr [rdi - 112]
transform_reference_L2b:
faddp	st(1), st
transform_reference_L2d:
fld	st(1)
transform_reference_L2f:
fmul	qword ptr [rdi - 48]
transform_reference_L32:
fld	st(3)
transform_reference_L34:
fmul	qword ptr [rdi - 56]
transform_reference_L37:
faddp	st(1), st
transform_reference_L39:
fld	st(4)
transform_reference_L3b:
fmul	qword ptr [rdi - 64]
transform_reference_L3e:
faddp	st(1), st
transform_reference_L40:
fxch	st(2)
transform_reference_L42:
fmul	qword ptr [rdi - 72]
transform_reference_L45:
fxch	st(3)
transform_reference_L47:
fmul	qword ptr [rdi - 80]
transform_reference_L4a:
faddp	st(3), st
transform_reference_L4c:
fxch	st(3)
transform_reference_L4e:
fmul	qword ptr [rdi - 88]
transform_reference_L51:
faddp	st(2), st
transform_reference_L53:
fld	qword ptr [rcx + 8]
transform_reference_L56:
fld	qword ptr [rsi + 232]
transform_reference_L5c:
fld	qword ptr [rdi - 16]
transform_reference_L5f:
fmul	st(5), st
transform_reference_L61:
fmul	st(4), st
transform_reference_L63:
fmul	st(3), st
transform_reference_L65:
fmul	st(2), st
transform_reference_L67:
fmulp	st(1), st
transform_reference_L69:
fstp	qword ptr [rsi + 232]
transform_reference_L6f:
fstp	qword ptr [rcx + 8]
transform_reference_L72:
cmp	dword ptr [rsi + 152], 0
transform_reference_L79:
jne	transform_reference_L8e
transform_reference_L7b:
cmp	dword ptr [rdi - 116], 0
transform_reference_L7f:
je	transform_reference_L8e
transform_reference_L81:
fst	qword ptr [rsi + 24]
transform_reference_L84:
fld	st(1)
transform_reference_L86:
fstp	qword ptr [rsi + 32]
transform_reference_L89:
fld	st(2)
transform_reference_L8b:
fstp	qword ptr [rsi + 40]
transform_reference_L8e:
fstp	qword ptr [rax]
transform_reference_L90:
fstp	qword ptr [rdx]
transform_reference_L92:
fstp	qword ptr [rcx]
ret
.globl _sin_reference
_sin_reference:
mov rax,rdi
mov rdi,rsi
mov esi,dword ptr [rdi-12]
and esi,3
push rax
push rdx
sin_reference_L13:
fld	qword ptr [rax + 8*rsi]
sin_reference_L16:
xor	edx, edx
sin_reference_L18:
fsub	dword ptr [rdi - 16]
sin_reference_L1b:
fmul	dword ptr [rdi - 20]
sin_reference_L1e:
fmul	qword ptr [rdi]
sin_reference_L20:
fld	st(0)
sin_reference_L22:
fsub	qword ptr [rdi - 8]
sin_reference_L25:
frndint
sin_reference_L27:
fsubp	st(1), st
sin_reference_L29:
fadd	st, st(0)
sin_reference_L2b:
fld1
sin_reference_L2d:
fcomp	st(1)
sin_reference_L2f:
fnstsw	ax
sin_reference_L31:
shr	ah
sin_reference_L33:
jae	sin_reference_L41
sin_reference_L35:
fld1
sin_reference_L37:
fadd	st, st(0)
sin_reference_L39:
fsubrp	st(1), st
sin_reference_L3b:
xor	edx, 2147483648
sin_reference_L41:
fldpi
sin_reference_L43:
fmulp	st(1), st
sin_reference_L45:
fcom	qword ptr [rdi + 8]
sin_reference_L48:
fnstsw	ax
sin_reference_L4a:
shr	ah
sin_reference_L4c:
jb	sin_reference_L58
sin_reference_L4e:
fldpi
sin_reference_L50:
fsubp	st(1), st
sin_reference_L52:
xor	edx, 2147483648
sin_reference_L58:
fld	st(0)
sin_reference_L5a:
fmul	st, st(0)
sin_reference_L5c:
fmul	st, st(1)
sin_reference_L5e:
fmul	qword ptr [rdi + 16]
sin_reference_L61:
fsubp	st(1), st
sin_reference_L63:
test	edx, 2147483648
sin_reference_L69:
jns	sin_reference_L6d
sin_reference_L6b:
fchs
sin_reference_L6d:
pop	rdx
sin_reference_L6e:
pop	rax
sin_reference_L6f:
fmul	dword ptr [rdi - 24]
sin_reference_L72:
fadd	dword ptr [rdi - 28]
sin_reference_L75:
fstp	qword ptr [rax + 8*rsi]
ret
