/* Native parameter limits shared by rendering, imports and editors.
 * These are port-specific limits, NOT ranges declared by the original .m3f
 * files (which usually declare only types/defaults). Do not infer Boolean
 * limits from names or zero/nonzero tests. User-specified ranges include
 * SierpinskiFull Reversed fold 0..6 and _Transform Copy to C -4..2.
 */
/* Additional formula metadata is shared by the independent C and Rust engines.
 * Stable name-derived IDs preserve native scene/animation files as the catalog grows. */
typedef struct {int kind;const char *name;int builtin,category,de;double rstop;int count;FormulaParameter parameters[16];unsigned char types[16];} RustFormula;
#if defined(USE_RUST_ENGINE) || defined(USE_C_FORMULA_VM)
#include "rust_formula_catalog.h"
#endif
static const RustFormula *rust_formula(int kind){
    if(kind<1000)return NULL;
#if defined(USE_RUST_ENGINE) || defined(USE_C_FORMULA_VM)
    static _Thread_local int keys[16];static _Thread_local const RustFormula *values[16];static _Thread_local unsigned cursor;
    for(int i=0;i<16;i++)if(keys[i]==kind)return values[i];
    for(size_t i=0;i<RUST_FORMULA_COUNT;i++)if(rust_formulas[i].kind==kind){unsigned slot=cursor++%16;keys[slot]=kind;values[slot]=rust_formulas+i;return rust_formulas+i;}
#else
    (void)kind;
#endif
    return NULL;
}
static int formula_serial_id(int kind){if(kind==-1)return 0;const RustFormula *f=rust_formula(kind);return f?f->builtin:kind>=100?20:kind;}
const char *formula_name(int kind){if(kind==-1)return "";const RustFormula *f=rust_formula(kind);if(f)return f->name;switch(kind){case 0:return "Integer Power";case 2:return "Quaternion";case 105:return "_addC";case 106:return "_SinY";case 107:return "Benesi3Pow2";case 108:return "_toruspinv3";case 109:return "Amazing Surf";case 110:return "TgladDihed";case 111:return "trifoliumIFS";case 112:return "helistairsIFS";case 113:return "hextgrid2IFS";case 114:return "boardIFS";case 115:return "BoxIFS";case 116:return "HeightMapIFS";case 117:return "_Rotate";case 118:return "Makin4D p4b";case 119:return "CubicQuat";case 120:return "Lambda4Dc";case 121:return "MengerSmt";case 122:return "_reciprocalY3b";case 123:return "diniIFS";case 124:return "Apollo2D-IFS";case 125:return "SphereIFS";case 126:return "RoundedBox";case 127:return "amazingIFS";case 128:return "SphCageIFS";case 129:return "transformIFS";case 130:return "MixPinski4ex";case 131:return "_LinCombineXYZ";case 132:return "_PolyFold-sym";case 133:return "MixPinski4";case 4:return "Amazing Box";case 100:return "_AmazingBox";case 101:return "RandCubesIFS";case 102:return "SierpinskiFull";case 103:return "_SinApprox";case 104:return "_Transform";case 6:return "Folding Int Pow";default:return "Unsupported";}}
static const FormulaParameter mixpinski_parameters[]={
 {"Scale",-100,100,2,0},{"CScale X",-1000000,1000000,1,0},{"CScale Y",-1000000,1000000,1,0},{"CScale Z",-1000000,1000000,.5,0},{"CScale W",-1000000,1000000,.5,0},
 {"Rotation YZ",-36000,36000,0,0},{"Rotation XZ",-36000,36000,0,0},{"Rotation XY",-36000,36000,0,0},{"Rotation XW",-36000,36000,0,0},{"Rotation YW",-36000,36000,0,0},{"Rotation ZW",-36000,36000,0,0},
 {"Rot X-off",-1000000,1000000,.5,0},{"Rot Y-off",-1000000,1000000,.5,0},{"Rot Z-off",-1000000,1000000,.5,0},{"Rot W-off",-1000000,1000000,.5,0}};
static const FormulaParameter polyfoldsym_parameters[]={{"Order",-1000000,1000000,4,0},{"Shift (deg)",-36000,36000,0,0},{"Shift x",-1000000,1000000,0,0},{"Shift y",-1000000,1000000,0,0},{"Skew (deg)",-36000,36000,0,0}};
static const FormulaParameter lincombine_parameters[]={
 {"Xx mul",-1000000,1000000,1,0},{"Xy mul",-1000000,1000000,0,0},{"Xz mul",-1000000,1000000,0,0},{"Yx mul",-1000000,1000000,0,0},{"Yy mul",-1000000,1000000,1,0},{"Yz mul",-1000000,1000000,0,0},{"Zx mul",-1000000,1000000,0,0},{"Zy mul",-1000000,1000000,0,0},{"Zz mul",-1000000,1000000,1,0}};
static const FormulaParameter transformifs_parameters[]={{"Add X",-1000000,1000000,0,0},{"Add Y",-1000000,1000000,0,0},{"Add Z",-1000000,1000000,0,0},{"Rotation X",-36000,36000,0,0},{"Rotation Y",-36000,36000,0,0},{"Rotation Z",-36000,36000,0,0},{"Abs X",-2147483648,2147483647,0,1},{"Abs Y",-2147483648,2147483647,1,1},{"Abs Z",-2147483648,2147483647,0,1},{"Scale",-1000000,1000000,1,0}};
static const FormulaParameter sphcage_parameters[]={{"SphRadius",-1000000,1000000,0.5,0},{"Scale",-1000000,1000000,1,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,0,0},{"CageRadius",-1000000,1000000,0.01,0},{"Apply scale+add",-2147483648,2147483647,1,1},{"Parals (2 to 1000)",2,1000,8,1},{"Merids",1,1000000,20,1}};
static const FormulaParameter roundedbox_parameters[]={{"Z halfwidth",-1000000,1000000,1,0},{"Y halfwidth",-1000000,1000000,1,0},{"X halfwidth",-1000000,1000000,1,0},{"Scale",-1000000,1000000,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,2,0},{"Border",-1000000,1000000,0.1,0},{"apply scale+add",-2147483648,2147483647,1,1},{"OTrap option (0..3)",0,3,0,1},{"OTrap offset",-1000000,1000000,1,0},{"OTrap scale",-1000000,1000000,1,0}};
static const FormulaParameter amazingifs_parameters[]={{"Add X",-1000000,1000000,0,0},{"Add Y",-1000000,1000000,0,0},{"Add Z",-1000000,1000000,0,0},{"Rotation X",-36000,36000,5,0},{"Rotation Y",-36000,36000,5,0},{"Rotation Z",-36000,36000,5,0},{"Fold X",-1000000,1000000,0.5,0},{"Fold Y",-1000000,1000000,0.5,0},{"Fold Z",-1000000,1000000,0,0},{"1/Min R (gt or eq 1)",-1000000,1000000,31,0}};
static const FormulaParameter sphereifs_parameters[]={{"Radius",-1000000,1000000,1,0},{"Scale",-100,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,3,0},{"Z size",-1000000,1000000,1,0},{"Y size",-1000000,1000000,1,0},{"X size",-1000000,1000000,1,0},{"Apply scale+add",-2147483648,2147483647,1,1},{"OTrap option (0..3)",0,3,0,1},{"OTrap offset",-1000000,1000000,1,0},{"OTrap scale",-1000000,1000000,1,0},{"Inside radius",-1000000,1000000,-1,0}};
static const FormulaParameter apollo_parameters[]={{"Add X 1",-1000000,1000000,0,0},{"Add X 2",-1000000,1000000,0,0},{"Mul Z",-1000000,1000000,1.2,0},{"Rotation X",-36000,36000,0,0},{"Rotation Y",-36000,36000,0,0},{"Rotation Z",-36000,36000,0,0},{"PolyFold Order",1,10000,5,1},{"Global XY-scale",-1000000,1000000,.05,0},{"Final add X",-1000000,1000000,15,0}};
static const FormulaParameter dini_parameters[]={{"Pseudo Radius",-1000000,1000000,3,0},{"Scale",-100,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,0,0},{"Max Radius",-1000000,1000000,2.85,0},{"Apply scale+add",-2147483648,2147483647,1,1},{"Thickness",-1000000,1000000,0.001,0},{"Min Radius",-1000000,1000000,0.1,0},{"Flip XZ / YZ",-2147483648,2147483647,0,1},{"Upside down",-2147483648,2147483647,0,1},{"Spiral tightness",-1000000,1000000,0.2,0}};
static const FormulaParameter menger_parameters[]={{"Scale",-100,100,3,0},{"CScale X",-1000000,1000000,1,0},{"CScale Y",-1000000,1000000,1,0},{"CScale Z",-1000000,1000000,.5,0},{"Rotation X",-36000,36000,0,0},{"Rotation Y",-36000,36000,0,0},{"Rotation Z",-36000,36000,0,0},{"LSmoothing (+-)",-1000000,1000000,.005,0},{"ESmoothing (+-)",-1000000,1000000,.005,0}};
static const FormulaParameter reciprocal_parameters[]={{"Limiter1",-1000000,1000000,.67,0},{"Limiter2",-1000000,1000000,.67,0},{"mul1",-1000000,1000000,1,0},{"mul2",-1000000,1000000,1,0}};
static const FormulaParameter makin4_parameters[]={{"w add",-1000000,1000000,0,0}};
static const FormulaParameter cubicquat_parameters[]={{"X mul",-1000000,1000000,1,0},{"Y mul",-1000000,1000000,1,0},{"Z mul",-1000000,1000000,1,0},{"W mul",-1000000,1000000,1,0},{"W add",-1000000,1000000,0,0},{"X twist",-1000000,1000000,0,0},{"Y twist",-1000000,1000000,0,0}};
static const FormulaParameter lambda4_parameters[]={{"dx",-1000000,1000000,1,0},{"dy",-1000000,1000000,0,0},{"dz",-1000000,1000000,0,0},{"dw",-1000000,1000000,0,0}};
static int formula_four_d(int k){const RustFormula *f=rust_formula(k);if(f)return f->de==4||f->de==5||f->de==6;return k==133||k==130||k==2||(k>=118&&k<=120);}
static const FormulaParameter rotate_parameters[]={{"Rotation1 X",-36000,36000,0,0},{"Rotation1 Y",-36000,36000,0,0},{"Rotation1 Z",-36000,36000,0,0}};
static const FormulaParameter integer_parameters[]={{"Power",2,8,8,1},{"Z multiplier",-100,100,-1,0}};
static const FormulaParameter box_parameters[]={{"Scale",-100,100,2,0},{"Min R",-100,100,.5,0},{"Fold",-100,100,1,0}};
static const FormulaParameter rand_parameters[]={
 {"XVtn (0-1)",0,4,.8,0},{"Scale",.000001,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,0,0},{"YVtn (0-1)",0,4,.8,0},{"Apply scale+add",-2147483648.,2147483647.,1,1},{"ZMaxSz",0,100,2,0},{"RandomizerX",-2147483648.,2147483647.,127,1},{"RandomizerY",-2147483648.,2147483647.,172,1},{"ShapeType 1",0,6,0,1},{"ShapeType 2",0,6,0,1},{"ZFlight",-1000000,1000000,0,0}};
static const FormulaParameter sierpinski_parameters[]={
 {"Scale",-100,100,2,0},{"CScale X",-1000000,1000000,1,0},{"CScale Y",-1000000,1000000,1,0},{"CScale Z",-1000000,1000000,1,0},
 {"Rotation1 X",-36000,36000,0,0},{"Rotation1 Y",-36000,36000,0,0},{"Rotation1 Z",-36000,36000,0,0},
 {"Rotation2 X",-36000,36000,0,0},{"Rotation2 Y",-36000,36000,0,0},{"Rotation2 Z",-36000,36000,0,0},
 {"Edge1",-1000000,1000000,0,0},{"Edge2",-1000000,1000000,0,0},{"Reversed fold",0,6,0,1}};
static const FormulaParameter sin_parameters[]={{"Index (X/Y/Z/W)",0,3,1,1},{"Offset 1",-1000000,1000000,0,0},{"Scale 1",-1000000,1000000,1,0},{"Scale 2",-1000000,1000000,1,0},{"Offset 2",-1000000,1000000,0,0}};
static const FormulaParameter transform_parameters[]={{"Scale",-100,100,1,0},{"X add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"Z add",-1000000,1000000,0,0},{"Rotate X",-36000,36000,0,0},{"Rotate Y",-36000,36000,0,0},{"Rotate Z",-36000,36000,0,0},{"Copy to C",-4,2,1,1}};
static const FormulaParameter folding_parameters[]={{"Power",2,8,2,1},{"Z multiplier",-100,100,-1,0},{"R fold",-100,100,2,0}};
static const FormulaParameter quaternion_parameters[]={{"YW multiplier",-1000000,1000000,-1,0},{"W add",-1000000,1000000,0,0}};
static const FormulaParameter addc_parameters[]={{"Cx multiplier",-1000000,1000000,1,0},{"Cy multiplier",-1000000,1000000,1,0},{"Cz multiplier",-1000000,1000000,1,0}};
static const FormulaParameter torus_parameters[]={{"X center",-1000000,1000000,0,0},{"Y center",-1000000,1000000,0,0},{"Z center",-1000000,1000000,0,0},{"Radius",-1000000,1000000,1,0},{"R",-1000000,1000000,1,0}};
static const FormulaParameter surf_parameters[]={{"Scale",-100,100,1.5,0},{"Min R",-100,100,.5,0},{"Fold",-100,100,1,0},{"Rotation1 X",-36000,36000,5,0},{"Rotation1 Y",-36000,36000,0,0},{"Rotation1 Z",-36000,36000,0,0},{"Scale vary",-100,100,0,0},{"Sphere or Cylinder",-2147483648.,2147483647.,1,1}};
static const FormulaParameter dihed_parameters[]={{"Log2Power (0 to 7)",0,7,0,1},{"Log2MapPower (0 to 7)",0,7,0,1}};
static const FormulaParameter trifolium_parameters[]={
 {"Petal fix 1",-1000000,1000000,16,0},{"Scale",-100,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,3,0},{"Petal fix 2",-1000000,1000000,1,0},{"Apply scale+add",-2147483648.,2147483647.,1,1},{"TFRot X",-36000,36000,0,0},{"TFRot Y",-36000,36000,0,0},{"TFRot Z",-36000,36000,0,0},{"OTrapOnDist",-1000000,1000000,.1,0},{"OTrapOnIts",-1000000,1000000,.1,0},{"OTrapOffset",-1000000,1000000,-1,0}};
static const FormulaParameter helistairs_parameters[]={
 {"OTrapOffset",-1000000,1000000,0,0},{"Scale",-100,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,0,0},{"Apply scale+add",-2147483648.,2147483647.,0,1},{"OTrapOnIts",-1000000,1000000,.25,0},{"Rotate X",-36000,36000,0,0},{"Rotate Y",-36000,36000,0,0},{"Rotate Z",-36000,36000,0,0},{"Stair N",-10000,10000,9,1},{"Hstep/Style",-1000000,1000000,-.35,0},{"Thick",-1000000,1000000,.05,0},{"Position/Squarry",-1000000,1000000,1,0},{"Wstep",-1000000,1000000,.45,0}};
static const FormulaParameter hextgrid_parameters[]={
 {"RadiusMod",-1000000,1000000,.2,0},{"Scale",-100,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,0,0},{"Grid styling",-1000000,1000000,1,0},{"Apply scale+add",-2147483648.,2147483647.,1,1},{"PlaneRot X",-36000,36000,0,0},{"PlaneRot Y",-36000,36000,0,0},{"PlaneRot Z",-36000,36000,0,0}};
static const FormulaParameter board_parameters[]={
 {"Bump",-1000000,1000000,.1,0},{"Scale",-100,100,1,0},{"Z add",-1000000,1000000,-.1,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,0,0},{"Checker scale",-1000000,1000000,2,0},{"Apply scale+add",-2147483648.,2147483647.,0,1},{"Rotate X",-36000,36000,0,0},{"Rotate Y",-36000,36000,0,0},{"Rotate Z",-36000,36000,0,0},{"Variation",0,4,0,1},{"OTrapClr 1",-1000000,1000000,1,0},{"OTrapClr 2",-1000000,1000000,0,0},{"OTrapOnIts",-1000000,1000000,.1,0}};
static const FormulaParameter boxifs_parameters[]={
 {"Z halfwidth",-1000000,1000000,1,0},{"Y halfwidth",-1000000,1000000,1,0},{"X halfwidth",-1000000,1000000,1,0},{"Scale",-100,100,2,0},{"Z add",-1000000,1000000,0,0},{"Y add",-1000000,1000000,0,0},{"X add",-1000000,1000000,2,0},{"Trapez",-1000000,1000000,0,0},{"Twist",-1000000,1000000,0,0},{"apply scale+add",-2147483648.,2147483647.,1,1},{"OTrap option (0..3)",0,3,0,1},{"OTrap offset",-1000000,1000000,1,0},{"OTrap scale",-1000000,1000000,1,0}};
static const FormulaParameter heightmap_parameters[]={
 {"Map nr",0,65535,10,1},{"X offset",-1000000,1000000,0,0},{"Y offset",-1000000,1000000,0,0},{"H offset",-1000000,1000000,0,0},{"X scale",-1000000,1000000,.2,0},{"Y scale",-1000000,1000000,.2,0},{"H scale",-1000000,1000000,-.1,0},{"Rotation X",-36000,36000,0,0},{"Rotation Y",-36000,36000,0,0},{"Rotation Z",-36000,36000,0,0},{"Map channel (0..2)",0,2,0,1},{"OTrap channel (0..2)",0,2,1,1},{"OTrap offset",-1000000,1000000,0,0},{"OTrap multiplier",-1000000,1000000,1,0}};
static int formula_difs(int k){const RustFormula *f=rust_formula(k);if(f)return f->de==20;return k==128||k==126||k==125||k==123||k==101||(k>=111&&k<=116);}
static int formula_supported(int k){if(rust_formula(k))return 1;return k==0||k==2||k==4||k==6||(k>=100&&k<=133);}
static int formula_generic(int k){return k==2||k==6||k>=101;}
static int formula_modifier(int k){const RustFormula *f=rust_formula(k);if(f)return f->de==-1||f->de==-2||f->de==21||f->de==22;return k==132||k==131||k==129||k==127||k==124||k==122||k==117||k==103||k==104||k==105||k==106||k==108;}
static int formula_linear(int k){const RustFormula *f=rust_formula(k);if(f)return f->de==2||f->de==11||f->de==5||f->de==6;return k==133||k==130||k==4||k==100||k==102||k==109||k==121;}
static int formula_kind_from_name(const char *name){
#if defined(USE_RUST_ENGINE) || defined(USE_C_FORMULA_VM)
 for(size_t i=0;i<RUST_FORMULA_COUNT;i++)if(!strcasecmp(name,rust_formulas[i].name))return rust_formulas[i].kind;
#endif
if(!strcasecmp(name,"_LinCombXYZ"))return 131;if(!strcasecmp(name,"AmazingSurf"))return 109;const int kinds[]={0,4,6,100,101,102,103,104,2,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133};for(int i=0;i<38;i++)if(!strcasecmp(name,formula_name(kinds[i])))return kinds[i];return -1;}
int formula_parameter_count(int kind){if(kind==-1)return 0;const RustFormula *f=rust_formula(kind);if(f)return f->count;switch(kind){case 132:return 5;case 133:return 11;case 130:return 15;case 131:return 9;case 129:return 10;case 128:return 9;case 126:return 12;case 127:return 10;case 125:return 13;case 124:return 9;case 123:return 12;case 121:return 9;case 122:return 4;case 118:return 1;case 119:return 7;case 120:return 4;case 117:return 3;case 115:return 13;case 116:return 14;case 111:return 13;case 112:return 15;case 113:return 10;case 114:return 14;case 110:return 2;case 109:return 8;case 108:return 5;case 107:return 0;case 105:return 3;case 106:return 5;case 101:case 102:return 13;case 103:return 5;case 104:return 8;case 4:case 6:return 3;default:return 2;}}
const FormulaParameter *formula_parameter(int kind,int index){const RustFormula *f=rust_formula(kind);if(f)return index>=0&&index<f->count?f->parameters+index:NULL;if(index<0||index>=formula_parameter_count(kind))return NULL;switch(kind){case 132:return polyfoldsym_parameters+index;case 133:case 130:return mixpinski_parameters+index;case 131:return lincombine_parameters+index;case 129:return transformifs_parameters+index;case 128:return sphcage_parameters+index;case 126:return roundedbox_parameters+index;case 127:return amazingifs_parameters+index;case 125:return sphereifs_parameters+index;case 124:return apollo_parameters+index;case 123:return dini_parameters+index;case 121:return menger_parameters+index;case 122:return reciprocal_parameters+index;case 118:return makin4_parameters+index;case 119:return cubicquat_parameters+index;case 120:return lambda4_parameters+index;case 117:return rotate_parameters+index;case 115:return boxifs_parameters+index;case 116:return heightmap_parameters+index;case 111:return trifolium_parameters+index;case 112:return helistairs_parameters+index;case 113:return hextgrid_parameters+index;case 114:return board_parameters+index;case 110:return dihed_parameters+index;case 109:return surf_parameters+index;case 108:return torus_parameters+index;case 2:return quaternion_parameters+index;case 105:return addc_parameters+index;case 106:return sin_parameters+index;case 101:return rand_parameters+index;case 102:return sierpinski_parameters+index;case 103:return sin_parameters+index;case 104:return transform_parameters+index;case 6:return folding_parameters+index;case 4:case 100:return box_parameters+index;default:return integer_parameters+index;}}
FormulaSlot formula_slot_default(int kind){FormulaSlot f={.kind=kind,.power=kind==6?2:8,.z_multiplier=-1,.scale=2,.min_radius=.5,.fold=kind==6?2:1};for(int i=0;i<formula_parameter_count(kind);i++)formula_slot_set_value(&f,i,formula_parameter(kind,i)->default_value);return f;}
/* Values 13..15 reuse otherwise-unused legacy box fields for generic formulas.
 * This preserves the established scene trailer and animation binary layout. */
double formula_slot_value(FormulaSlot f,int i){if(formula_generic(f.kind)&&i>=13)return i==13?f.scale:i==14?f.min_radius:f.fold;if(f.kind==2||f.kind>=101)return f.parameters[i];if(f.kind==4||f.kind==100)return i==0?f.scale:i==1?f.min_radius:f.fold;return i==0?f.power:i==1?f.z_multiplier:f.fold;}
void formula_slot_set_value(FormulaSlot *f,int i,double value){if(formula_generic(f->kind)&&i>=13){if(i==13)f->scale=value;else if(i==14)f->min_radius=value;else f->fold=value;return;}if(f->kind==2||f->kind>=101)f->parameters[i]=value;else if(f->kind==4||f->kind==100){if(i==0)f->scale=value;else if(i==1)f->min_radius=value;else f->fold=value;}else if(i==0)f->power=(int)value;else if(i==1)f->z_multiplier=value;else f->fold=value;}
/* MB3D option encodings include matrix triples and expanded constants. */
static int formula_option_type(int k,int i){const RustFormula *f=rust_formula(k);if(f)return i>=0&&i<f->count?f->types[i]:0;if((k==130||k==133)&&i>=5&&i<=10)return 12;if(k==129&&i>=3&&i<=5)return 6;if(k==128&&(i==1||i==2))return 14;if(k==126){if(i==3||i==4||i==7)return 14;if(i>=10)return 1;}if(k==127&&i>=3&&i<=5)return 6;if(k==125){if(i==1||i==2||i==4)return 14;if(i>=5&&i<=7)return 13;if(i==10||i==11)return 1;}if(k==124&&i>=3&&i<=5)return 6;if(k==123&&(i==1||i==2))return 14;if(k==122&&i<2)return 22;if(k==121&&i>=4&&i<=6)return 6;if(k==117)return 6;if(k==115){if(i==3||i==4)return 14;if(i==8||i>=11)return 1;}if(k==116){if(i>=7&&i<=9)return 6;if((i>=1&&i<=6)||i>=12)return 1;}if(k>=111&&k<=114){if(i==1||i==2)return 14;if(i>=7&&i<=9)return 6;}if(k==109){if(i==1)return 7;if(i>=3&&i<=5)return 6;}if(k==0||k==6){if(i==0)return 10;if(k==6&&i==2)return 8;}if(k==4&&i==1)return 7;if(k==4&&i==2)return 11;if(k==100&&i==1)return 7;if(k==101&&(i==1||i==2))return 14;if(k==102){if(i>=4&&i<=9)return 6;}if(k==104){if(i>=4&&i<=6)return 5;}if((k==103||k==106)&&i)return 1;return formula_parameter(k,i)->integer?2:0;}

static const int legacy_formula_menu[]={0,4,100,101,102,103,104,6,2,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133};
int formula_menu_count(void){
#if defined(USE_RUST_ENGINE) || defined(USE_C_FORMULA_VM)
 return 38+(int)RUST_FORMULA_COUNT;
#else
 return 38;
#endif
}
int formula_menu_kind(int index){if(index<0||index>=formula_menu_count())return 0;
 if(index<38)return legacy_formula_menu[index];
#if defined(USE_RUST_ENGINE) || defined(USE_C_FORMULA_VM)
 return rust_formulas[index-38].kind;
#else
 return 0;
#endif
}
int formula_catalog_category(int kind){const RustFormula *f=rust_formula(kind);return f?f->category:-1;}
double formula_catalog_bailout(int kind){const RustFormula *f=rust_formula(kind);return f?f->rstop:16;}

static int formula_map_parameter(int kind){if(kind==116)return 0;const RustFormula *f=rust_formula(kind);if(f)for(int i=0;i<f->count;i++)if(!strcasecmp(f->parameters[i].name,"Map nr")||!strcasecmp(f->parameters[i].name,"Map number"))return i;return -1;}

int formula_parameter_is_angle(int kind,int index){
 int t=formula_option_type(kind,index);return (t>=3&&t<=6)||t==12;
}
