from pathlib import Path
import struct
import subprocess
import tempfile
root=Path(__file__).resolve().parent
base=bytearray((root/'example.m3i').read_bytes())
a=len(base)-1136
base[a+5]=1  # end at slot 2, repeat from slot 1
first=a+8
struct.pack_into('<dd',base,first+60,2,-1)
second=first+188
base[second:second+188]=base[first:first+188]
struct.pack_into('<dd',base,second+60,3,.7)
with tempfile.TemporaryDirectory() as d:
    path=Path(d)/'pair.m3i'
    def check(data,mode):
        path.write_bytes(data)
        r=subprocess.run([str(root/'test-pair-loader'),str(path),str(mode)],capture_output=True)
        assert r.returncode==0,r.stderr.decode()
        assert path.read_bytes()==data
    check(base,0)
    inactive=base.copy();inactive[432+68+4*32]=17;check(inactive,0) # disabled light retains visible-source flags
    shadowed=base.copy();shadowed[133]=1|2|(33<<2);shadowed[139]=1;shadowed[149]=1|(3<<2)|(2<<4)
    shadowed[224]=30;shadowed[225]=0
    struct.pack_into('<f',shadowed,226,2);struct.pack_into('<f',shadowed,374,.5)
    check(shadowed,'shadows')
    for mode,slots in [('box-first',[first]),('box-second',[second]),('boxes',[first,second])]:
        boxed=base.copy()
        for slot in slots:
            struct.pack_into('<ii',boxed,slot+4,4,3)
            struct.pack_into('<ddd',boxed,slot+60,2,.5,1)
        check(boxed,mode)
        struct.pack_into('<d',boxed,slots[0]+68,-101);check(boxed,'reject')
    tail=base.copy();tail[a+5]=17;check(tail,1)
    for off,fmt,value in [(a+1,'B',3),(a+2,'B',6),(second+4,'I',4),
                           (second,'i',-1),(second+60,'d',9),(a+5,'B',33),
                           (second+188,'I',1)]:
        bad=base.copy();struct.pack_into('<'+fmt,bad,off,value);check(bad,'reject')
print('Two-formula .m3i loading, repeat points, direct-render equivalence, invalid scenes and input preservation passed.')
