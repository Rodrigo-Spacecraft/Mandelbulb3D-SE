"""Translate the bundled, ahead-of-time numerical formula functions into C.
No Rust compiler or runtime is involved. The input is checked-in generated source.
Reject unknown syntax rather than silently falling back to an interpreter.
"""
import re,pathlib,json
ROOT=pathlib.Path(__file__).resolve().parent.parent
TYPES={'u64':'uint64_t','u32':'uint32_t','u16':'uint16_t','u8':'uint8_t','i64':'int64_t','i32':'int32_t','i16':'int16_t','i8':'int8_t','usize':'size_t','f64':'double','f32':'float','bool':'bool'}
TOK=re.compile(r'\s+|//[^\n]*|"(?:\\.|[^"\\])*"|0x[0-9a-fA-F_]+(?:u64|u32|u16|u8|i32)?|\d[\d_]*(?:\.\d+)?(?:[eE][+-]?\d+)?(?:f64|f32|u64|u32|u16|u8|i32|usize)?|\'[A-Za-z_]\w*|[A-Za-z_]\w*|::|->|=>|\.\.=|\.\.|<<=|>>=|<<|>>|==|!=|<=|>=|&&|\|\||[+*/%&|^!<>=-]=?|[^\s]')
class Parser:
 def __init__(self,s):
  self.t=[x for x in TOK.findall(s) if not x.isspace() and not x.startswith('//')];self.i=0;self.labels=[];self.types={};self.closures={}
 def peek(self,x=None):return self.t[self.i] if x is None else self.t[self.i]==x
 def pop(self,x=None):
  t=self.t[self.i];self.i+=1
  if x is not None and t!=x:raise ValueError(('expected',x,'got',t,self.t[max(0,self.i-8):self.i+8]))
  return t
 def ty(self):
  if self.peek('['):
   self.pop();t=self.ty();self.pop(';');n=self.pop();self.pop(']');return 'CN_U2' if t=='uint64_t' and n=='2' else ('CN_U8' if t=='uint32_t' else 'CN_D8')
  return TYPES[self.pop()]
 def args(self,end=')'):
  a=[]
  while not self.peek(end):
   a.append(self.expr())
   if self.peek(','):self.pop()
   else:break
  self.pop(end);return a
 def expr(self,minp=0):
  t=self.pop()
  if t in ('!','-','&','*'):
   if t=='&' and self.peek('mut'):self.pop()
   v=self.expr(95);v=(('!' if any(x in v for x in ('>=','<=','==','!=','&&','||','isnan(','fl.')) else '~')+v if t=='!' else '-'+v if t=='-' else ('(*'+v+')' if t=='*' else v)) # refs are value handles in this generated dialect
  elif t=='(':
   a=self.args();v=a[0] if len(a)==1 else ('TUP',a)
   if isinstance(v,str):v='('+v+')'
  elif t=='[':
   a=[self.expr()]
   if self.peek(';'):
    self.pop();n=self.pop();self.pop(']');v='(CN_D8){0}' if not a[0].endswith('U') else '(CN_U8){0}'
   else:
    while self.peek(','):self.pop();a.append(self.expr())
    self.pop(']');v='('+('CN_U2' if len(a)==2 else 'CN_D8' if len(a)==8 else 'CN_D3')+'){'+','.join(a)+'}'
  elif t=='if':
   c=self.expr();a=self.block_expr();self.pop('else');b=self.expr() if self.peek('if') else self.block_expr();v=('TUP',['(('+c+')?('+x+'):('+y+'))' for x,y in zip(a[1],b[1])]) if isinstance(a,tuple) else '(('+c+')?('+a+'):('+b+'))'
  elif t=='{':
   self.i-=1;v=self.block_expr()
  elif t=='match':
   selector=self.expr();self.pop('{');arms=[]
   while not self.peek('}'):
    key=self.pop();self.pop('=>');val=self.expr();arms.append((key,val))
    if self.peek(','):self.pop()
   self.pop('}');v=arms[-1][1]
   for key,val in reversed(arms[:-1]):v='(('+selector+'=='+self.literal(key)+')?('+val+'):('+v+'))'
  else:
   v=self.literal(t)
   if self.peek('::'):
    self.pop();v+='::'+self.pop();v=v.replace('Alu::','Alu_').replace('Shift::','Shift_').replace('FKind::','FKind_')
  prec={'=':1,'+=':1,'-=':1,'|=':1,'&=':1,'^=':1,'<<=':1,'>>=':1,'||':5,'&&':6,'==':10,'!=':10,'<':10,'>':10,'<=':10,'>=':10,'|':15,'^':16,'&':17,'<<':20,'>>':20,'+':30,'-':30,'*=':1,'/=':1,'*':40,'/':40,'%':40,'as':50,'..=':3}
  while self.i<len(self.t):
   op=self.peek()
   if op=='?':self.pop();continue
   if op=='(':
    self.pop();a=self.args();v=self.call(v,a);continue
   if op=='[':
    self.pop();a=self.expr();self.pop(']');v=v+'['+a+']';continue
   if op=='.':
    self.pop();method=self.pop()
    if self.peek('::'):
     self.pop();self.pop('<');n=self.pop();self.pop('>')
    if self.peek('('):self.pop();a=self.args();v=self.method(v,method,a)
    else:v=v+('->' if v=='m' else '.')+method
    continue
   p=prec.get(op,-1)
   if p<minp:break
   self.pop()
   if op=='as':v='(('+self.ty()+')('+v+'))';continue
   r=self.expr(p if p==1 else p+1)
   if op=='..=':v=('RANGE',v,r);continue
   v=('fmod('+v+','+r+')') if op=='%' and v=='x' and r=='y' else '('+v+op+r+')'
  return v
 def literal(self,t):
  if t in ('true','false'):return t
  if re.match(r'^\d',t):
   t=t.replace('_','');
   if t.endswith(('f64','f32')) and '.' not in t:t=t[:-3]+'.0'+t[-3:]
   t=re.sub(r'(?:f64|f32)$','',t);t=re.sub(r'u64$','ULL',t);t=re.sub(r'(?:u32|u16|u8|usize)$','U',t);t=re.sub(r'i32$','',t)
  return t
 def call(self,v,a):
  if v in self.closures:
   param,body=self.closures[v];return '({__auto_type cn_arg='+a[0]+'; '+re.sub(r'\b'+param+r'\b','cn_arg',body)+';})'
  if v=='f64::from_bits':return 'cn_double('+a[0]+')'
  if v=='f32::from_bits':return 'cn_float('+a[0]+')'
  if v=='Flags::default':return '(CN_Flags){0}'
  if v=='rec_get':return 'cn_rd64(m,CN_REC+8*('+a[-1]+'))'
  if v=='rec_set':return 'cn_wr64(m,CN_REC+8*('+a[-2]+'),'+a[-1]+')'
  if v=='cell':return 'cn_cell('+','.join(a)+')'
  if v=='direct_regs':return '(*regs)'
  if v=='Ok':return '0'
  if v=='Err':return '1'
  if v=='fcompare_cc':return 'cn_compare('+','.join(a)+')'
  if v in ('push_l','pop_l'):v+='u'
  if v in ('shift_reg_l','reg_get','reg_set','push_lu','pop_lu'):return 'cn_'+v+'('+','.join(('&fl' if x=='fl' else x) for x in a)+')'
  if v=='atan2_bracket':return ('TUP',['atan2('+','.join(a)+')']*2)
  if v=='crate::custom':raise ValueError('custom path')
  v=v.replace('::','_');return v+'('+','.join(a)+')'
 def method(self,v,n,a):
  if n in ('wrapping_add','wrapping_sub','wrapping_mul'):return '((uint32_t)('+v+{'wrapping_add':'+','wrapping_sub':'-','wrapping_mul':'*'}[n]+a[0]+'))'
  if n=='to_bits':return 'cn_bits('+v+')'
  if n in ('abs','sqrt','exp2','log2','trunc','sin','cos','tan','is_nan','round_ties_even'):return {'abs':'fabs','is_nan':'isnan','round_ties_even':'nearbyint'}.get(n,n)+'('+v+')'
  if n=='atan2':return 'atan2('+v+','+a[0]+')'
  if n=='contains':
   assert isinstance(v,tuple) and v[0]=='RANGE',v
   return '('+a[0]+'>='+v[1]+'&&'+a[0]+'<='+v[2]+')'
  if n in ('sin_cos','sin_cos_cached'):return ('TUP',['sin('+ (v if n=='sin_cos' else a[0])+')','cos('+(v if n=='sin_cos' else a[0])+')'])
  if n=='alu':return 'cn_alu(&'+v+','+','.join(a)+')'
  if n=='cond':return 'cn_cond('+v+','+a[0]+')'
  if n=='round_int':return 'cn_round(m,'+a[0]+')'
  if n=='bytes_at':return 'cn_ptr(m,'+a[0]+')'
  if n=='swap':return 'cn_swap('+v+','+','.join(a)+')'
  if n in ('fstoreu','rd8u','wr8u','rd16u','wr16u','rd64u','wr64u','rd32u','wr32u','rd32','wr32','rdf64u','wrf64u','rdf64','floadu'):return 'cn_'+n+'('+','.join([v]+a)+')'
  if n=='wrf64':return 'cn_wrf64u('+','.join([v]+a)+')'
  if n=='into':return v
  if n=='is_ok':return '('+v+'==0)'
  raise ValueError(('method',n,v,a))
 def block_expr(self):
  self.pop('{');out=[]
  while not self.peek('}'):
   if self.peek('let') or self.peek('return'):
    out.append(self.statement());continue
   e=self.expr()
   if self.peek(';'):self.pop();out.append(e+';')
   else:
    if isinstance(e,tuple):
     self.pop('}');return ('TUP',['({'+ ' '.join(out)+x+';})' for x in e[1]])
    out.append(e+';');break
  self.pop('}');return '({'+' '.join(out)+'})'
 def block(self):
  self.pop('{');out=['{']
  while not self.peek('}'):out.append(self.statement())
  self.pop('}');out.append('}');return '\n'.join(out)
 def statement(self):
  t=self.peek()
  if t==';':self.pop();return ';'
  if t=='let':
   self.pop()
   if self.peek('mut'):self.pop()
   if self.peek('('):
    self.pop();names=[]
    while not self.peek(')'):
     names.append(self.pop())
     if self.peek(','):self.pop()
    self.pop();self.pop('=');v=self.expr();self.pop(';');assert v[0]=='TUP',v
    temps=['cn_tuple_'+str(self.i)+'_'+str(i) for i in range(len(names))];return '\n'.join('__auto_type '+n+' = '+x+';' for n,x in zip(temps,v[1]))+'\n'+'\n'.join('__auto_type '+n+' = '+x+';' for n,x in zip(names,temps))
   name=self.pop();ty=None
   if self.peek(':'):self.pop();ty=self.ty()
   self.pop('=')
   if self.peek('|'):
    self.pop()
    if self.peek('mut'):self.pop()
    param=self.pop();self.pop(':');self.ty();self.pop('|');self.pop('->');self.ty();body=self.block_expr();self.pop(';');self.closures[name]=(param,body);return ''
   if name=='_':
    while not self.peek(';'):self.pop()
    self.pop();return ''
   v=self.expr();self.pop(';')
   if name=='vm':ty='unsigned char *'
   temp='cn_init_'+str(self.i);return '__auto_type '+temp+' = '+v+'; '+(ty or '__auto_type')+' '+name+' = '+temp+';'
  if t.startswith("'"):
   label=self.pop()[1:];self.pop(':');loop=self.peek('loop')
   if loop:self.pop()
   self.labels.append((label,loop));b=self.block();self.labels.pop();return ('cn_continue_'+label+':;\n' if loop else '')+b+('\ngoto cn_continue_'+label+';' if loop else '')+'\ncn_break_'+label+':;'
  if t=='if':
   self.pop();c=self.expr();b=self.block();s='if('+c+')'+b
   if self.peek('else'):self.pop();s+='else '+(self.statement() if self.peek('if') else self.block())
   return s
  if t in ('break','continue'):
   op=self.pop();label=self.pop()[1:] if self.peek().startswith("'") else None;self.pop(';')
   return 'goto cn_'+op+'_'+label+';' if label else op+';'
  if t=='return':
   self.pop();v=self.expr();
   if self.peek(';'):self.pop()
   return 'return '+v+';'
  if t=='{':return self.block()
  if t=='loop':self.pop();return 'for(;;)'+self.block()
  if t=='match':
   self.pop();v=self.expr();self.pop('{');out=['switch('+v+'){']
   while not self.peek('}'):
    cases=[]
    while not self.peek('=>'):cases.append(self.pop())
    self.pop();out.append('default:' if cases==['_'] else ''.join('case '+self.literal(x)+':' for x in cases if x!='|'))
    if self.peek('{'):out.append(self.block())
    else:out.append(self.statement())
    if self.peek(','):self.pop()
    out.append('break;')
   self.pop();return '\n'.join(out+['}'])
  e=self.expr()
  if self.peek(';'):self.pop();return e+';'
  if self.peek('}'):return 'return '+e+';'
  raise ValueError(('statement end',self.t[self.i:self.i+12],e))

def special_line(match):
 line,op=match[0],match[1]
 if op.startswith('Setcc'):
  cc,reg=map(int,re.findall(r'\d+',op));return f'reg_set(&mut rg,{reg},1,fl.cond({cc}) as u32);'
 if op=='Leave':return 'rg[4] = rg[5]; rg[5] = pop_lu(m, &mut rg);'
 if op.startswith('IMul2'):
  reg,src=map(int,re.findall(r'\d+',op.split('{',1)[1]));return f'{{ let product = (rg[{reg}] as i32 as i64) * (rg[{src}] as i32 as i64); rg[{reg}] = product as u32; fl.cf = product != (product as i32 as i64); fl.of = fl.cf; }}'
 if op.startswith('Cmovcc'):
  cc,reg,src=map(int,re.findall(r'\d+',op));return f'if fl.cond({cc}) {{ rg[{reg}] = rg[{src}]; }}'
 if op.startswith('FnstcwMem'):
  base,disp=map(int,re.findall(r'\d+',op));return f'm.wr16u(rg[{base}].wrapping_add({disp}), m.cw);'
 if op.startswith('FldcwMem'):
  base,disp=map(int,re.findall(r'\d+',op));return f'm.cw = m.rd16u(rg[{base}].wrapping_add({disp}));'
 if op.startswith('Movzx'):
  reg,base,disp,size=map(int,re.findall(r'\d+',op));assert size in (1,2);return f'rg[{reg}] = m.rd{size*8}u(rg[{base}].wrapping_add({disp})) as u32;'
 if op.startswith('FComi'):
  a,b=map(int,re.findall(r'\d+',op));return f'fl.cf = f[{a}] < f[{b}] || f[{a}].is_nan() || f[{b}].is_nan(); fl.zf = f[{a}] == f[{b}] || f[{a}].is_nan() || f[{b}].is_nan(); fl.pf = f[{a}].is_nan() || f[{b}].is_nan(); fl.of = false; fl.sf = false; fl.af = false;'
 if op.startswith('FCmov'):
  cc,dst,src=map(int,re.findall(r'\d+',op));return f'if fl.cond({cc}) {{ f[{dst}] = f[{src}]; }}'
 if op.startswith('FPrem'):
  a,b=map(int,re.findall(r'\d+',op));return f'f[{a}] = cn_remainder(f[{a}],f[{b}]); fsw = fsw & !0x0400;'
 if op.startswith('CallHost'):return 'cn_height_host(m, rg, f);'
 raise ValueError(('untranslated static operation',op))

def prepare(s):
 s=re.sub(r'^[^\n]*(?:if let Op::Gen|m\.exec_op)[^\n]*// ([^\n]+)',special_line,s,flags=re.M)
 # Statically known call returns in these already-inlined call sites.
 s=re.sub(r'match &p\.ops\[\d+\] \{ Op::Call \{ ret, \.\. \} \| Op::CallRot \{ ret, \.\. \} => \*ret, _ => (0x[0-9a-fA-F]+) \}',r'\1u32',s)
 s=re.sub(r'let res = \(\|\| -> R<\(\)> \{', '{', s)
 s=re.sub(r'\}\)\(\);[\s\S]*?if res.is_ok\(\) \{[\s\S]*?\}\s*res\s*\}', '} return Ok(()); }', s)
 s=re.sub(r'if r != RETURN_SENTINEL \{ match p.rets[^\n]*?\} \}', '', s)
 s=s.replace('u64::MAX','0xffffffffffffffffu64')
 s=s.replace('crate::custom::map_px','cn_map_px')
 s=re.sub(r'm\.exec_op\(&p\.ops\[87\], &mut f\)', 'cn_height_host(m, rg, f)', s)
 # Byte loader's const generic is consumed by method parser.
 s=s.replace('let mut rg = *regs;', 'let mut rg = cn_initial_regs;')
 s=s.replace('m.fcw', 'm.cw')
 return s

def main():
 outdir=ROOT/'native-c';outdir.mkdir(exist_ok=True);good=[];bad=[];reset_info={}
 for path in sorted((ROOT/'native-c/reference').glob('part*.rs')):
  raw=path.read_text();matches=list(re.finditer(r'pub\(super\) fn (f_\w+)\([^\n]+\{',raw));out=['/* Generated native C formula calculations. See tools/generate-native-c.py. */','#include "runtime.h"']
  for i,ma in enumerate(matches):
   name=ma[1];s=raw[ma.end()-1:matches[i+1].start() if i+1<len(matches) else len(raw)];s=s[:s.rfind('}')+1]
   dynamic=bool(re.search(r'm\.(?:exec|exec_op|rd32|wr32|rd8u|rd16u|wr16u|floadu|fstoreu|rdf64|wrf64|rd64u|wr64u|rd32u|wr32u)\((?!0x)',s))
   addresses=[int(x,16)&65535 for x in re.findall(r'0x(1000[0-9a-fA-F]{4})',s)]
   stack=[x for x in addresses if 0x4000<=x<0x7f00]
   reset_info[name]=(int(dynamic),min(stack,default=0x7f00))
   try:
    p=Parser(prepare(s));b=p.block();assert p.i==len(p.t),(p.t[p.i:p.i+20]);b=b.replace('return 0;', '(*regs)=rg; m->regs=rg; return 0;');body='int cn_'+name+'(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000; '+b[1:];out.append(body);good.append(name)
    if name in ('f_170d88a7063dc19f','f_6405c0b3abe12770'):
     clone=name+'_fast';out.append(re.sub(r'\b(sin|cos)\(',r'cn_fast_\1(',body.replace('cn_'+name+'(', 'cn_'+clone+'(')));good.append(clone)
   except Exception as e:bad.append((name,str(e),s[:150]))
  (outdir/(path.stem+'.c')).write_text('\n'.join(line.rstrip() for line in '\n'.join(out).splitlines())+'\n')
 mod=(ROOT/'native-c/reference/mod.rs').read_text();table=['#include \"runtime.h\"','#include <strings.h>']
 for name in good:table.append('extern int cn_'+name+'(CN_Machine *,CN_U8 *,uint32_t);')
 table.append('CN_Function cn_lookup(const char *name){')
 for name,names in re.findall(r'=> \(\d+, (f_\w+)\), // ([^\n]+)',mod):
  for alias in names.split(', '):table.append('if(!strcasecmp(name,'+json.dumps(alias)+'))return cn_'+name+';')
 table+=['if(!strcasecmp(name,\"_dynamicfast\"))return cn_f_170d88a7063dc19f_fast;','if(!strcasecmp(name,\"_gnarl2D_2fast\"))return cn_f_6405c0b3abe12770_fast;','return 0;}'];table.append('CN_ResetInfo cn_reset_info(const char *name){')
 for name,names in re.findall(r'=> \(\d+, (f_\w+)\), // ([^\n]+)',mod):
  full,low=reset_info[name]
  for alias in names.split(', '):table.append('if(!strcasecmp(name,'+json.dumps(alias)+'))return (CN_ResetInfo){%d,%d};'%(full,low))
 table.append('return (CN_ResetInfo){1,0x4000};}')
 (outdir/'lookup.c').write_text('\n'.join(table)+'\n')
 (outdir/'translation-report.json').write_text(json.dumps({'translated':good,'failed':bad},indent=2)+'\n')
 print('Translated',len(good),'failed',len(bad));print('\n'.join(str(b[:2]) for b in bad[:12]));
 if bad:raise SystemExit('Native C generation failed; no interpreter fallback is allowed.')
if __name__=='__main__':main()
