"""Generate direct XYZ/fourth-component kernels from audited register-only C.

Reject side effects, extra orbit records, callbacks and unknown memory helpers.
The broader prepared-context generator handles the remaining formulas. The
catalog and randomized multi-step tests compare this path to full native C.
LGPL-2.1-or-later, following the bundled native numerical translations.
"""
from pathlib import Path
import os,re,json
os.chdir(Path(__file__).resolve().parent.parent)
allowed={'cn_alu','cn_bits','cn_cell','cn_compare','cn_cond','cn_double','cn_float','cn_reg_get','cn_reg_set','cn_shift_reg_l','cn_swap','cn_fast_sin','cn_fast_cos','cn_remainder'}
selected={}
for source in sorted(Path('native-c').glob('part*.c')):
 for original in re.split(r'(?=\nint cn_f_)',source.read_text()):
  match=re.match(r'\s*int (cn_f_\w+)\(',original)
  if not match or 'cn_break_body:;' not in original:continue
  start=original.find('\n{\n');end=original.index('cn_break_body:;');pre=original[:start];body=original[start:end];epi=original[end:]
  if set(re.findall(r'\bcn_\w+(?=\()',body))-allowed or 'm->' in body or re.search(r'\b(return|steps|limit|max_steps)\b',body):continue
  records={int(n) for n in re.findall(r'CN_REC\+8\*\((\d+)\)',pre+epi)}
  if records- {3,4,5,6,13}:continue
  # Dynamic/unrecognized addressing or option writes must keep the native path.
  stores=re.findall(r'cn_wr\w*\(m,([^,]+),[^;]+;',epi)
  if any(not re.fullmatch(r'CN_REC\+8\*\([3456]\)|0x10007[0-9a-f]{3}U',address) for address in stores):continue
  if 'cn_rd64u(m,0x10001' in pre or 'cn_rd64(m,0x10001' in pre:continue
  vm=re.search(r'cn_ptr\(m,\(\(uint32_t\)\(vb\+(\d+)\)\)\)',pre)
  if not vm and re.search(r'\bvm\b',body):continue
  offset=int(vm[1]) if vm else 0
  selected[match[1]]=(pre,body,records,offset)
# Preserve the first three identifiers for compatibility with diagnostics.
first=['cn_f_6ad79cbb14959655','cn_f_09c020b05d5686d9','cn_f_d696fec44725d3b1']
order=first+sorted(set(selected)-set(first));indices={name:i+1 for i,name in enumerate(order)}
out=['/* Generated direct C kernels; LGPL-2.1-or-later. */','#pragma clang diagnostic push']+['#pragma clang diagnostic ignored '+json.dumps(w) for w in ['-Wgnu-auto-type','-Wgnu-statement-expression','-Wunused-variable','-Wunused-parameter']]
for name in order:
 pre,body,records,offset=selected[name]
 out.append('static inline Vec cf_pure_'+name[5:]+'(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){\n#pragma clang fp contract(off)\nCN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;')
 for variable in sorted(set(re.findall(r'uint64_t (r\d+|s\d+) =',pre))):
  value={'r3':'cn_bits(z.x)','r4':'cn_bits(z.y)','r5':'cn_bits(z.z)','r6':'cn_bits(*fourth)','r13':'pvar','s2015':'UINT64_C(0x1000103010001038)','s2014':'UINT64_C(0xfffffff000000000)'}.get(variable,'0')
  out.append('uint64_t '+variable+'='+value+';')
 for off,variable in re.findall(r'cn_cell\(vm,(\d+)\); uint64_t (v\d+)',pre):out.append('uint64_t '+variable+'=cn_cell(vm,'+off+');')
 out.append(body+'\ncn_break_body:;\n'+('*fourth=cn_double(r6);' if 6 in records else '')+'return (Vec){'+','.join('cn_double(r'+str(i)+')' if i in records else 'z.'+'xyz'[i-3] for i in [3,4,5])+'};\n}')
out.append('static unsigned cf_pure_index(const char *name){')
for alias,function in re.findall(r'if\(!strcasecmp\(name,"([^"]+)"\)\)return (cn_f_\w+);',Path('native-c/lookup.c').read_text()):
 if function in indices:out.append('if(!strcasecmp(name,'+json.dumps(alias)+'))return '+str(indices[function])+';')
out.append('return 0;}')
out.append('static inline __attribute__((always_inline)) Vec cf_pure_dispatch(unsigned index,Vec z,double *fourth,const unsigned char *variables,uint32_t pvar){switch(index){')
for name in order:out.append('case '+str(indices[name])+':return cf_pure_'+name[5:]+'(z,fourth,variables+'+str(selected[name][3])+',pvar);')
out.append('default:return z;}}')
out.append('#pragma clang diagnostic pop')
target=Path('c_formula_compact.h');text='\n'.join(out)+'\n'
if not target.exists() or target.read_text()!=text:target.write_text(text)
print('Direct XYZ/fourth-component kernels:',len(order))
