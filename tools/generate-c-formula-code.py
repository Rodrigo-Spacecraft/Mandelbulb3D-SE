"""Embed M3F constants and metadata for the native C formulas."""
from pathlib import Path
import struct,re
root=Path(__file__).resolve().parent.parent
out=['/* Generated from bundled M3F files; original author credits remain in those files. */','typedef struct {const char *name;const unsigned char *constants;size_t code_size,constant_size;double de_scale,ade_scale,si_pow;} CFormulaCode;']
rows=[]
for n,p in enumerate(sorted((root/'rust-assets/M3Formulas').glob('*.m3f'),key=lambda p:p.name.lower())):
    sections={};sec=''
    for line in p.read_text(errors='replace').splitlines():
        line=line.strip()
        if line.startswith('['):sec=line.upper();continue
        sections.setdefault(sec,[]).append(line)
    raw=''.join(re.sub(r'[^0-9a-fA-F]','',line) for line in sections.get('[CODE]',[]) if line and not line.startswith('//'))
    code=bytes.fromhex(raw) if raw else b'';const=bytearray()
    for line in sections.get('[CONSTANTS]',[]):
        if '=' not in line:continue
        ty,value=line.split('=',1);ty=ty.strip().lower().lstrip('.').split()[0];value=value.strip().split()[0].replace(',','.')
        slot=bytearray(8)
        if ty=='integer':continue # Original type table recognises Int, not Integer, in constants.
        if ty in ('int64','int'):
            try:v=int(value.replace('$','0x'),0 if value.startswith(('$','0x')) else 10)
            except ValueError:v=0
            slot[:8 if ty=='int64' else 4]=(v&((1<<(64 if ty=='int64' else 32))-1)).to_bytes(8 if ty=='int64' else 4,'little')
        elif ty in ('double','single'):
            try:v=float(value)
            except ValueError:v=0
            slot[:8 if ty=='double' else 4]=struct.pack('<d' if ty=='double' else '<f',v)
        else:raise ValueError((p,line))
        const+=slot
    for kind,b in [('constants',const)]:out.append('static const unsigned char cf_%s_%d[]={%s};'%(kind,n,','.join(str(v) for v in b) or '0'))
    meta={}
    for l in sections.get('[OPTIONS]',[]):
        if '=' in l:
            k,v=l.split('=',1)
            try:meta[k.strip().lower()]=float(v.strip())
            except ValueError:pass
    rows.append('{"%s",cf_constants_%d,%d,%d,%.17g,%.17g,%.17g}'%(p.stem,n,len(code),len(const),meta.get('.descale',1),meta.get('.adescale',1),next((v for k,v in meta.items() if k.startswith('.sipow')),0)))
out+=['static const CFormulaCode c_formula_codes[]={',',\n'.join(rows),'};']
(root/'c_formula_code.h').write_text('\n'.join(out)+'\n');print(len(rows),'formula files embedded')
