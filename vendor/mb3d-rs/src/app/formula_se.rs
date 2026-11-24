//! SE formula program editor.
use super::*;
use crate::vcl::control::Control;
use crate::vcl::form::Form;
use super::super::main_se::place;

fn add(form: &mut Form, parent: usize, name: &str, class: &str, text: &str, bounds: (i32,i32,i32,i32)) -> usize {
    let mut c=Control::new(name,class);
    c.caption=text.into();
    c.set_bounds(bounds.0,bounds.1,bounds.2,bounds.3);
    form.add_control(parent,c)
}
fn label(form:&mut Form,parent:usize,name:&str,text:&str,x:i32,y:i32,w:i32) {
    add(form,parent,name,"TLabel",text,(x,y,w,20));
}
fn menu(form:&mut Form,name:&str,choices:Vec<String>,x:i32,y:i32) {
    let id=add(form,0,name,"TComboBox","",(x,y,174,27));
    let c=&mut form.ctl[id];
    c.items=choices;
    c.style="csDropDownList".into();
    c.events.insert("OnChange".into(),name.into());
}
fn button(form:&mut Form,name:&str,title:&str,x:i32,y:i32,w:i32) {
    let id=add(form,0,name,"TButton",title,(x,y,w,28));
    form.ctl[id].events.insert("OnClick".into(),name.into());
}
pub(super) fn configure(ui:&mut Ui) {
    ui.set_client_size(F,640,740);
    let f=ui.fm(F);
    f.stay_on_top=false;
    for id in f.ctl[0].children.clone() { f.ctl[id].visible=false; }
    for (name,title,choices,x,y) in [
        ("SeMode","Formula mode",vec!["Alternate","Interpolate","DEcombinate"].into_iter().map(str::to_string).collect(),16,14),
        ("SeRepeat","Repeat from",(1..=6).map(|i|format!("Formula {i}")).collect(),16,52),
        ("SeRender","Render",vec!["Outside","Inside","In and outside"].into_iter().map(str::to_string).collect(),330,14),
        ("SeSplit","Part 2 starts",(2..=6).map(|i|format!("Formula {i}")).collect(),330,52),
        ("SeRepeat2","Part 2 repeats",(1..=6).map(|i|format!("Formula {i}")).collect(),330,90),
    ] {
        label(f,0,&format!("{name}Label"),title,x,y+5,120);
        menu(f,name,choices,x+122,y);
    }
    label(f,0,"SeCombineLabel","DE combination",16,95,120);
    place(f,0,"DECombineCmb",(138,90,174,27));
    f.c_mut("DECombineCmb").visible=true;
    for (name,title,x,w) in [
        ("ExchangeFormulaLeftBtn","< Move Left",16,124),("ExchangeFormulaRightBtn","Move Right >",146,124),
        ("SeCopySlot","Copy",276,124),("SePasteSlot","Paste",406,124),("SeInfo","Info",536,84),
    ] {
        if f.has(name) { place(f,0,name,(x,130,w,28));f.c_mut(name).visible=true;f.c_mut(name).caption=title.into();f.c_mut(name).glyph=None; }
        else { button(f,name,title,x,130,w); }
    }
    f.c_mut("SeCopySlot").events.insert("OnMouseDown".into(),"SeCopySlotMouseDown".into());
    place(f,0,"TabControl1",(12,172,616,346));
    f.c_mut("TabControl1").visible=true;
    let tabs=f.id("TabControl1").unwrap();
    for id in f.ctl[tabs].children.clone(){ f.ctl[id].visible=false; }
    let id=add(f,tabs,"SeFormula","TButton","Choose Formula",(10,34,570,28));
    f.ctl[id].events.insert("OnClick".into(),"SeFormula".into());
    f.ctl[id].popup_button=true;
    super::super::navi_se::add_formula_menu(f);
    let pane=add(f,tabs,"SeFormulaPane","TScrollBox","",(0,72,594,190));
    for i in 0..16 {
        let y=i*34;
        let l=format!("Label{}",i+1);
        let e=format!("Edit{}",i+1);
        place(f,pane,&l,(10,y+5,240,22));
        f.c_mut(&l).alignment=crate::vcl::canvas::HAlign::Left;
        place(f,pane,&e,(260,y,290,26));
    }
    place(f,tabs,"LabelItCount",(10,280,215,20));
    place(f,tabs,"EditItCount",(260,276,150,26));
    f.c_mut("LabelItCount").visible=true;
    f.c_mut("EditItCount").visible=true;
    place(f,tabs,"RichEdit1",(0,72,594,190));
    for (i,(field,title)) in [
        ("MinIterEdit","Min iterations"),("MaxIterEdit","Max iterations"),("RBailoutEdit","R bailout"),
        ("MaxIterHybridPart2Edit","Maxits part 2"),("Edit23","Smooth DEcomb"),("Edit25","Fpow")
    ].into_iter().enumerate() {
        let x=16+(i%3)as i32*208;
        let y=538+(i/3)as i32*40;
        label(f,0,&format!("SeGlobalLabel{i}"),title,x,y+5,112);
        place(f,0,field,(x+114,y,80,26));
        f.c_mut(field).visible=true;
    }
    f.c_mut("Edit23").events.insert("OnChange".into(),"SeSmoothDecomb".into());
    place(f,0,"CheckBox2",(16,620,600,26));
    f.c_mut("CheckBox2").visible=true;
    f.c_mut("CheckBox2").caption="Disable analytical DE (use numerical DE)".into();
    f.c_mut("CheckBox2").props.retain(|(k,_)|k!="Alignment");
    label(f,0,"SeFormulaStatus","Zero iterations disables a slot.",16,659,604);
    button(f,"SeResetProgram","Reset formulas",16,692,180);
    button(f,"SeApplyProgram","Apply && Render",440,692,180);
    f.c_mut("SeApplyProgram").default=true;
}
pub(super) fn sync(app:&Mb3d,ui:&mut Ui) {
    for index in 1..=12 {
        let name=format!("SpeedButtonEx{index}");
        if ui.f(F).has(&name) { ui.set_visible(F,&name,false); }
    }
    let st=&app.formula;
    let t=tab(ui);
    let combined=st.hybrid==2;
    let labels: Vec<String> = (0..if st.hybrid==1 {2}else{6}).map(|i| {
        let name = st.slots[i].as_ref().map_or(String::new(), |formula| formula.name());
        let active = st.slots[i].is_some() && if st.hybrid==1 { st.weights[i]>0.0 } else { st.its[i]>0 };
        format!("{}{}{}{}", i+1, if active {"*"}else{""}, if name.is_empty(){""}else{" "}, name)
    }).collect();
    let available = ui.f(super::super::MAIN).client_size().0.max(640).min(1600);
    let width = {
        let form = ui.f(F);
        let font = form.font(form.id("TabControl1").unwrap());
        (labels.iter().map(|label| form.measure(&font,label)+18).sum::<i32>()+28).clamp(640,available)
    };
    ui.set_client_size(F,width,740);
    let tabs = ui.cm(F,"TabControl1");
    tabs.width = width-24;
    tabs.multi_line = true;
    tabs.tabs = labels;
    let (rows, row_height) = {
        let form = ui.f(F);
        let control = form.c("TabControl1");
        let font = form.font(form.id("TabControl1").unwrap());
        let mut x=2;
        let mut rows=1;
        for title in &control.tabs {
            let width=form.measure(&font,title)+12;
            if x>2 && x+width>control.width-4 { rows+=1; x=2; }
            x+=width;
        }
        (rows,crate::vcl::canvas::line_height(&font)+7)
    };
    let extra=(rows-1)*row_height;
    ui.cm(F,"SeFormula").top=34+extra;
    ui.cm(F,"SeFormulaPane").top=72+extra;
    ui.cm(F,"SeFormulaPane").height=(190-extra).max(70);
    ui.cm(F,"RichEdit1").top=72+extra;
    ui.cm(F,"RichEdit1").height=(190-extra).max(70);
    for name in ["Edit23","Edit25","MaxIterHybridPart2Edit"] { ui.set_visible(F,name,true); }
    ui.set_visible(F,"CheckBox1",false);
    ui.set_visible(F,"Button3",false);
    ui.set_item_index(F,"SeMode",st.hybrid);
    ui.set_item_index(F,"SeRepeat",st.repeat1 as i32);
    ui.set_item_index(F,"SeSplit",st.start2 as i32-1);
    ui.set_item_index(F,"SeRepeat2",st.repeat2 as i32);
    ui.set_item_index(F,"SeRender",ui.item_index(F,"ComboBox1"));
    let name=st.slots[t].as_ref().map_or("Choose Formula".to_string(),|f|f.name());
    ui.set_caption(F,"SeFormula",&name);
    ui.set_caption(F,"LabelItCount",if st.hybrid==1{"Interpolation weight"}else{"Iterations per pass"});
    for n in ["SeSplit","SeRepeat2","DECombineCmb","MaxIterHybridPart2Edit","Edit23"] { ui.set_enabled(F,n,combined); }
    ui.set_enabled(F,"SeRepeat",st.hybrid!=1);
    ui.set_enabled(F,"Edit25",ui.checked(F,"CheckBox2") || (combined&&ui.item_index(F,"DECombineCmb")==5));
    ui.set_enabled(F,"SePasteSlot",app.formula.se_clipboard.is_some());
}
pub(super) fn event(app:&mut Mb3d,ui:&mut Ui,e:&Event)->bool {
    let h=e.handler.as_str();
    match h {
        "SeSmoothDecomb" => {
            if app.formula.user_change {
                if let Some(value)=super::super::util::parse_float(&ui.text(F,"Edit23")).filter(|v|v.is_finite()){app.formula.decomb_smooth=value.clamp(0.0,100.0) as f32;}
            }
        }
        "SeFormula" => {
            ui.popup_menu(F,"SeFormulaMenu","SeFormula",0,28);
        }
        "SeFormulaChoice" => select_formula(app,ui,&ui.caption(F,&e.sender)),
        "SeClearFormula" => {
            let i=tab(ui);
            app.formula.slots[i]=None;app.formula.its[i]=0;
            tab_control1_change(app,ui);
        }
        "SeSearch" => super::super::navi_se::open_search(ui,true),
        "SeMode" => {
            ui.cm(F,"TabControl2").tab_index=ui.item_index(F,"SeMode");
            let event=Event {handler:"TabControl2Change".into(),..e.clone()};
            super::event(app,ui,&event);
        }
        "SeRepeat" => app.formula.repeat1=ui.item_index(F,h).max(0) as usize,
        "SeSplit" => {
            app.formula.start2=(ui.item_index(F,h)+1).clamp(1,5) as usize;
            app.formula.repeat1=app.formula.repeat1.min(app.formula.start2-1);
            app.formula.repeat2=app.formula.repeat2.max(app.formula.start2);
        }
        "SeRepeat2" => app.formula.repeat2=(ui.item_index(F,h).max(0) as usize).max(app.formula.start2),
        "SeRender" => ui.set_item_index(F,"ComboBox1",ui.item_index(F,h)),
        "SeCopySlotMouseDown" => {
            if let Ev::MouseDown {button:crate::vcl::MouseButton::Right,..}=e.ev {
                let st=&app.formula;
                let names=(0..if st.hybrid==1 {2}else{6}).filter(|&i| {
                    if st.hybrid==1 {st.weights[i]>0.0}else{st.its[i]>0}
                }).filter_map(|i|st.slots[i].as_ref().map(|f|f.name())).collect::<Vec<_>>().join(", ");
                crate::vcl::clipboard::set(&names);
                ui.set_caption(F,"SeFormulaStatus","Active formula names copied to clipboard.");
            }
        }
        "SeCopySlot" => {
            let i=tab(ui);
            app.formula.se_clipboard=Some((app.formula.slots[i].clone(),app.formula.its[i]));
        }
        "SePasteSlot" => if let Some((formula,iterations))=app.formula.se_clipboard.clone() {
            let i=tab(ui);app.formula.slots[i]=formula;app.formula.its[i]=iterations;
            tab_control1_change(app,ui);
        },
        "SeInfo" => {
            let visible=!ui.visible(F,"RichEdit1");
            let event=Event {handler:"SpeedButton2Click".into(),..e.clone()};
            super::event(app,ui,&event);
            ui.set_visible(F,"RichEdit1",visible);
            ui.set_visible(F,"SeFormulaPane",!visible);
        }
        "SeResetProgram" => {
            let event=Event{handler:"SpeedButton3Click".into(),..e.clone()};
            super::event(app,ui,&event);
        }
        "SeApplyProgram" => { super::super::main_form::calc_mand(app,ui,true); }
        _=>return false,
    }
    sync(app,ui);
    true
}
