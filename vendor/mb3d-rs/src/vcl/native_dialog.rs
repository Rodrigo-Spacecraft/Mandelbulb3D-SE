//! Windows Common Item Dialogs. COM pointers and UTF-16 buffers stay on
//! the UI thread and are released before returning the ordinary dialog event.
use super::dialogs::FileOptions;
use std::{
    ffi::c_void,
    os::windows::ffi::{OsStrExt, OsStringExt},
    path::PathBuf,
    ptr::null_mut,
};
pub(super) type Ptr = *mut c_void;
#[repr(C)]
#[derive(PartialEq,Eq)]
pub(super) struct Guid(pub(super) u32, pub(super) u16, pub(super) u16, pub(super) [u8; 8]);
const OPEN: Guid = Guid(
    0xdc1c5a9c,
    0xe88a,
    0x4dde,
    [0xa5, 0xa1, 0x60, 0xf8, 0x2a, 0x20, 0xae, 0xf7],
);
const SAVE: Guid = Guid(
    0xc0b4e2f3,
    0xba21,
    0x4773,
    [0x8d, 0xba, 0x33, 0x5e, 0xc9, 0x46, 0xeb, 0x8b],
);
const IID_OPEN: Guid = Guid(
    0xd57c7288,
    0xd4ad,
    0x4768,
    [0xbe, 0x02, 0x9d, 0x96, 0x95, 0x32, 0xd9, 0x60],
);
const IID_SAVE: Guid = Guid(
    0x84bccd23,
    0x5fde,
    0x4cdb,
    [0xae, 0xa4, 0xaf, 0x64, 0xb8, 0x3d, 0x78, 0xab],
);
const IID_ITEM: Guid = Guid(
    0x43826d1e,
    0xe718,
    0x42ee,
    [0xbc, 0x55, 0xa1, 0xe2, 0x61, 0xc3, 0x7b, 0xfe],
);
#[link(name = "ole32")]
unsafe extern "system" {
    fn CoInitializeEx(reserved: Ptr, flags: u32) -> i32;
    fn CoUninitialize();
    fn CoCreateInstance(
        class: *const Guid,
        outer: Ptr,
        context: u32,
        iid: *const Guid,
        result: *mut Ptr,
    ) -> i32;
    fn CoTaskMemFree(p: Ptr);
}
#[link(name = "shell32")]
unsafe extern "system" {
    fn SHCreateItemFromParsingName(
        name: *const u16,
        context: Ptr,
        iid: *const Guid,
        result: *mut Ptr,
    ) -> i32;
}
#[link(name = "user32")]
unsafe extern "system" {
    fn GetForegroundWindow() -> Ptr;
}
pub(super) struct Com(pub(super) Ptr);
impl Drop for Com {
    fn drop(&mut self) {
        unsafe {
            let release: unsafe extern "system" fn(Ptr) -> u32 =
                std::mem::transmute(slot(self.0, 2));
            release(self.0);
        }
    }
}
struct Apartment;
impl Drop for Apartment {
    fn drop(&mut self) {
        unsafe {
            CoUninitialize();
        }
    }
}
pub(super) unsafe fn slot(p: Ptr, n: usize) -> *const c_void {
    unsafe { *(*(p as *const *const *const c_void)).add(n) }
}
fn wide(s: &std::ffi::OsStr) -> Vec<u16> {
    s.encode_wide().chain(Some(0)).collect()
}
pub(super) fn text(s: &str) -> Vec<u16> {
    wide(s.as_ref())
}
pub(super) fn check(hr: i32) -> Result<(), i32> {
    if hr < 0 {
        Err(hr)
    } else {
        Ok(())
    }
}
unsafe fn set_text(p: Ptr, n: usize, s: &[u16]) -> Result<(), i32> {
    unsafe {
        let f: unsafe extern "system" fn(Ptr, *const u16) -> i32 = std::mem::transmute(slot(p, n));
        check(f(p, s.as_ptr()))
    }
}
pub(super) unsafe fn result(p: Ptr, n: usize) -> Result<Com, i32> {
    unsafe {
        let f: unsafe extern "system" fn(Ptr, *mut Ptr) -> i32 = std::mem::transmute(slot(p, n));
        let mut out = null_mut();
        check(f(p, &mut out))?;
        Ok(Com(out))
    }
}
pub(super) unsafe fn path(p: Ptr) -> Result<PathBuf, i32> {
    unsafe {
        let f: unsafe extern "system" fn(Ptr, u32, *mut *mut u16) -> i32 =
            std::mem::transmute(slot(p, 5));
        let mut s = null_mut();
        check(f(p, 0x80058000, &mut s))?;
        let mut len = 0;
        while *s.add(len) != 0 {
            len += 1;
        }
        let path = PathBuf::from(std::ffi::OsString::from_wide(std::slice::from_raw_parts(
            s, len,
        )));
        CoTaskMemFree(s.cast());
        Ok(path)
    }
}
#[repr(C)]
struct Filter {
    label: *const u16,
    pattern: *const u16,
}
pub(super) fn show(o: &FileOptions, save: bool) -> Result<(Vec<PathBuf>, usize), i32> {
    unsafe {
        check(CoInitializeEx(null_mut(), 2 | 4))?;
        let _apartment = Apartment;
        let mut p = null_mut();
        check(CoCreateInstance(
            if save { &SAVE } else { &OPEN },
            null_mut(),
            1,
            if save { &IID_SAVE } else { &IID_OPEN },
            &mut p,
        ))?;
        let dialog = Com(p);
        let mut flags = 0;
        let get: unsafe extern "system" fn(Ptr, *mut u32) -> i32 = std::mem::transmute(slot(p, 10));
        check(get(p, &mut flags))?;
        flags |= 0x40 | 0x800 | 8; // filesystem paths, existing folders, no working-dir changes
        if save {
            flags |= 2;
        } else if o.folder {
            flags |= 0x20;
        } else {
            flags |= 0x1000;
        }
        if o.multi && !save && !o.folder {
            flags |= 0x200;
        }
        let set: unsafe extern "system" fn(Ptr, u32) -> i32 = std::mem::transmute(slot(p, 9));
        check(set(p, flags))?;
        let mut buffers = Vec::new();
        let pieces = o.filter.split('|').collect::<Vec<_>>();
        for pair in pieces.chunks_exact(2) {
            buffers.push((text(pair[0]), text(pair[1])));
        }
        if !o.folder && !buffers.is_empty() {
            let filters = buffers
                .iter()
                .map(|(a, b)| Filter {
                    label: a.as_ptr(),
                    pattern: b.as_ptr(),
                })
                .collect::<Vec<_>>();
            let set: unsafe extern "system" fn(Ptr, u32, *const Filter) -> i32 =
                std::mem::transmute(slot(p, 4));
            check(set(p, filters.len() as u32, filters.as_ptr()))?;
            let set_index: unsafe extern "system" fn(Ptr, u32) -> i32 =
                std::mem::transmute(slot(p, 5));
            check(set_index(
                p,
                o.filter_index.max(1).min(filters.len()) as u32,
            ))?;
        }
        if !o.title.is_empty() {
            set_text(p, 17, &text(&o.title))?;
        }
        if !o.file_name.is_empty() {
            set_text(p, 15, &text(&o.file_name))?;
        }
        if save && !o.default_ext.is_empty() {
            set_text(p, 22, &text(o.default_ext.trim_start_matches('.')))?;
        }
        if let Some(dir) = &o.initial_dir {
            let mut folder = null_mut();
            if SHCreateItemFromParsingName(
                wide(dir.as_os_str()).as_ptr(),
                null_mut(),
                &IID_ITEM,
                &mut folder,
            ) >= 0
            {
                let folder = Com(folder);
                let set: unsafe extern "system" fn(Ptr, Ptr) -> i32 =
                    std::mem::transmute(slot(p, 12));
                check(set(p, folder.0))?;
            }
        }
        let preview=if o.preview&&!save&&!o.folder{Some(super::native_preview::Preview::attach(p)?)}else{None};
        let show: unsafe extern "system" fn(Ptr, Ptr) -> i32 = std::mem::transmute(slot(p, 3));
        let hr = show(p, GetForegroundWindow());
        if hr == 0x800704c7u32 as i32 {
            return Ok((Vec::new(), o.filter_index));
        }
        check(hr)?;
        let mut index = o.filter_index.max(1) as u32;
        let get: unsafe extern "system" fn(Ptr, *mut u32) -> i32 = std::mem::transmute(slot(p, 6));
        if !o.folder {
            check(get(p, &mut index))?;
        }
        let mut paths = Vec::new();
        if o.multi && !save && !o.folder {
            let items = result(p, 27)?;
            let count: unsafe extern "system" fn(Ptr, *mut u32) -> i32 =
                std::mem::transmute(slot(items.0, 7));
            let mut n = 0;
            check(count(items.0, &mut n))?;
            let at: unsafe extern "system" fn(Ptr, u32, *mut Ptr) -> i32 =
                std::mem::transmute(slot(items.0, 8));
            for i in 0..n {
                let mut item = null_mut();
                check(at(items.0, i, &mut item))?;
                let item = Com(item);
                paths.push(path(item.0)?);
            }
        } else {
            let item = result(p, 20)?;
            paths.push(path(item.0)?);
        }
        drop(preview);
        drop(dialog);
        Ok((paths, index as usize))
    }
}
