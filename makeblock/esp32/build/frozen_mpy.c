#include "py/mpconfig.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/emitglue.h"

#if MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE != 0
#error "incompatible MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE"
#endif

#if MICROPY_LONGINT_IMPL != 2
#error "incompatible MICROPY_LONGINT_IMPL"
#endif

#if MPZ_DIG_SIZE != 16
#error "incompatible MPZ_DIG_SIZE"
#endif

#if MICROPY_PY_BUILTINS_FLOAT
typedef struct _mp_obj_float_t {
    mp_obj_base_t base;
    mp_float_t value;
} mp_obj_float_t;
#endif

#if MICROPY_PY_BUILTINS_COMPLEX
typedef struct _mp_obj_complex_t {
    mp_obj_base_t base;
    mp_float_t real;
    mp_float_t imag;
} mp_obj_complex_t;
#endif

enum {
    MP_QSTR_apa106_dot_py = MP_QSTRnumber_of,
    MP_QSTR_NeoPixel,
    MP_QSTR_neopixel,
    MP_QSTR_APA106,
    MP_QSTR_ORDER,
    MP_QSTR_dht_dot_py,
    MP_QSTR_DHTBase,
    MP_QSTR_DHT11,
    MP_QSTR_DHT22,
    MP_QSTR_measure,
    MP_QSTR_buf,
    MP_QSTR_self,
    MP_QSTR_humidity,
    MP_QSTR_temperature,
    MP_QSTR_ds18x20_dot_py,
    MP_QSTR_flashbdev_dot_py,
    MP_QSTR_FlashBdev,
    MP_QSTR_size,
    MP_QSTR_bdev,
    MP_QSTR_SEC_SIZE,
    MP_QSTR_START_SEC,
    MP_QSTR_blocks,
    MP_QSTR_n,
    MP_QSTR_op,
    MP_QSTR_inisetup_dot_py,
    MP_QSTR_flashbdev,
    MP_QSTR_check_bootsec,
    MP_QSTR_fs_corrupted,
    MP_QSTR_setup,
    MP_QSTR__slash_flash,
    MP_QSTR_boot_dot_py,
    MP_QSTR_w,
    MP_QSTR_neopixel_dot_py,
    MP_QSTR_bpp,
    MP_QSTR_timing,
    MP_QSTR_val,
    MP_QSTR_color,
    MP_QSTR_onewire_dot_py,
    MP_QSTR__ow,
    MP_QSTR_OneWireError,
    MP_QSTR_OneWire,
    MP_QSTR_SEARCH_ROM,
    MP_QSTR_MATCH_ROM,
    MP_QSTR_SKIP_ROM,
    MP_QSTR_select_rom,
    MP_QSTR__search_rom,
    MP_QSTR_required,
    MP_QSTR_rom,
    MP_QSTR_l_rom,
    MP_QSTR_diff,
    MP_QSTR_data,
    MP_QSTR_upip_dot_py,
    MP_QSTR_upip_utarfile,
    MP_QSTR_tarfile,
    MP_QSTR_debug,
    MP_QSTR_install_path,
    MP_QSTR_cleanup_files,
    MP_QSTR_gzdict_sz,
    MP_QSTR_file_buf,
    MP_QSTR_NotFoundError,
    MP_QSTR_op_split,
    MP_QSTR_op_basename,
    MP_QSTR__makedirs,
    MP_QSTR_save_file,
    MP_QSTR_install_tar,
    MP_QSTR_expandhome,
    MP_QSTR_warn_ussl,
    MP_QSTR_url_open,
    MP_QSTR_get_pkg_metadata,
    MP_QSTR_fatal,
    MP_QSTR_install_pkg,
    MP_QSTR_install,
    MP_QSTR_get_install_path,
    MP_QSTR_cleanup,
    MP_QSTR_main,
    MP_QSTR_wb,
    MP_QSTR_fname,
    MP_QSTR_subf,
    MP_QSTR_setup_dot_,
    MP_QSTR_PKG_hyphen_INFO,
    MP_QSTR_README,
    MP_QSTR__dot_egg_hyphen_info,
    MP_QSTR_extractfile,
    MP_QSTR_deps,
    MP_QSTR_Skipping,
    MP_QSTR_DIRTYPE,
    MP_QSTR_f,
    MP_QSTR_prefix,
    MP_QSTR__tilde__slash_,
    MP_QSTR_getenv,
    MP_QSTR_HOME,
    MP_QSTR_s,
    MP_QSTR_https_colon_,
    MP_QSTR_url,
    MP_QSTR_Error_colon_,
    MP_QSTR_msg,
    MP_QSTR_exc,
    MP_QSTR_info,
    MP_QSTR_releases,
    MP_QSTR_TarFile,
    MP_QSTR_fileobj,
    MP_QSTR_pkg_spec,
    MP_QSTR_Queue_colon_,
    MP_QSTR_to_install,
    MP_QSTR_unlink,
    MP_QSTR__hyphen_h,
    MP_QSTR__hyphen__hyphen_help,
    MP_QSTR__hyphen_p,
    MP_QSTR__hyphen_r,
    MP_QSTR__hash_,
    MP_QSTR__hyphen__hyphen_debug,
    MP_QSTR__hyphen_,
    MP_QSTR_upip_utarfile_dot_py,
    MP_QSTR_TAR_HEADER,
    MP_QSTR_REGTYPE,
    MP_QSTR_roundup,
    MP_QSTR_FileSection,
    MP_QSTR_TarInfo,
    MP_QSTR_align,
    MP_QSTR_skip,
    MP_QSTR_content_len,
    MP_QSTR_aligned_len,
    MP_QSTR_sz,
    MP_QSTR_rb,
    MP_QSTR_tarinfo,
    MP_QSTR_urequests_dot_py,
    MP_QSTR_Response,
    MP_QSTR_request_sema,
    MP_QSTR_request,
    MP_QSTR_head,
    MP_QSTR_post,
    MP_QSTR_patch,
    MP_QSTR_delete,
    MP_QSTR_content,
    MP_QSTR_raw,
    MP_QSTR__cached,
    MP_QSTR_http_colon_,
    MP_QSTR__colon_,
    MP_QSTR_Host,
    MP_QSTR_status_code,
    MP_QSTR_reason,
    MP_QSTR_uquest_colon__space_,
    MP_QSTR_method,
    MP_QSTR_headers,
    MP_QSTR_stream,
    MP_QSTR_HEAD,
    MP_QSTR_GET,
    MP_QSTR_POST,
    MP_QSTR_PUT,
    MP_QSTR_PATCH,
    MP_QSTR_DELETE,
    MP_QSTR__boot_dot_py,
    MP_QSTR_inisetup,
    MP_QSTR_vfs,
};

extern const qstr_pool_t mp_qstr_const_pool;
const qstr_pool_t mp_qstr_frozen_const_pool = {
    (qstr_pool_t*)&mp_qstr_const_pool, // previous pool
    MP_QSTRnumber_of, // previous pool size
    154, // allocated entries
    154, // used entries
    {
        (const byte*)"\xa5\xdf\x09" "apa106.py",
        (const byte*)"\x69\x83\x08" "NeoPixel",
        (const byte*)"\x69\xa0\x08" "neopixel",
        (const byte*)"\xa2\x4e\x06" "APA106",
        (const byte*)"\x4b\x69\x05" "ORDER",
        (const byte*)"\x5a\xdd\x06" "dht.py",
        (const byte*)"\x28\x6f\x07" "DHTBase",
        (const byte*)"\x5d\x80\x05" "DHT11",
        (const byte*)"\xfd\x80\x05" "DHT22",
        (const byte*)"\x1d\xae\x07" "measure",
        (const byte*)"\x74\x49\x03" "buf",
        (const byte*)"\x79\x77\x04" "self",
        (const byte*)"\x7c\xaf\x08" "humidity",
        (const byte*)"\xe9\xde\x0b" "temperature",
        (const byte*)"\xa6\x68\x0a" "ds18x20.py",
        (const byte*)"\xe7\xe7\x0c" "flashbdev.py",
        (const byte*)"\xc0\xf8\x09" "FlashBdev",
        (const byte*)"\x20\xa5\x04" "size",
        (const byte*)"\x70\x30\x04" "bdev",
        (const byte*)"\xaa\x86\x08" "SEC_SIZE",
        (const byte*)"\xef\xb6\x09" "START_SEC",
        (const byte*)"\x1f\x23\x06" "blocks",
        (const byte*)"\xcb\xb5\x01" "n",
        (const byte*)"\x7a\x6f\x02" "op",
        (const byte*)"\xab\x1b\x0b" "inisetup.py",
        (const byte*)"\xc0\xf5\x09" "flashbdev",
        (const byte*)"\xff\x70\x0d" "check_bootsec",
        (const byte*)"\xd3\x63\x0c" "fs_corrupted",
        (const byte*)"\xc2\x02\x05" "setup",
        (const byte*)"\x1a\x4e\x06" "/flash",
        (const byte*)"\x74\xb9\x07" "boot.py",
        (const byte*)"\xd2\xb5\x01" "w",
        (const byte*)"\xae\xc1\x0b" "neopixel.py",
        (const byte*)"\xc7\x49\x03" "bpp",
        (const byte*)"\x35\x23\x06" "timing",
        (const byte*)"\xfe\x7a\x03" "val",
        (const byte*)"\xd8\x06\x05" "color",
        (const byte*)"\x0f\xd8\x0a" "onewire.py",
        (const byte*)"\x82\x1f\x03" "_ow",
        (const byte*)"\x50\x5d\x0c" "OneWireError",
        (const byte*)"\x68\xd8\x07" "OneWire",
        (const byte*)"\xa4\x6f\x0a" "SEARCH_ROM",
        (const byte*)"\xb9\x51\x09" "MATCH_ROM",
        (const byte*)"\xcb\x11\x08" "SKIP_ROM",
        (const byte*)"\xe2\x4f\x0a" "select_rom",
        (const byte*)"\xfb\x7e\x0b" "_search_rom",
        (const byte*)"\x2c\x4c\x08" "required",
        (const byte*)"\xb5\x8b\x03" "rom",
        (const byte*)"\x26\xa3\x05" "l_rom",
        (const byte*)"\xc8\xfc\x04" "diff",
        (const byte*)"\x15\xdc\x04" "data",
        (const byte*)"\x9e\xa2\x07" "upip.py",
        (const byte*)"\x32\x80\x0d" "upip_utarfile",
        (const byte*)"\x24\xc0\x07" "tarfile",
        (const byte*)"\xd4\x55\x05" "debug",
        (const byte*)"\x56\x0a\x0c" "install_path",
        (const byte*)"\x8f\x1f\x0d" "cleanup_files",
        (const byte*)"\x34\x14\x09" "gzdict_sz",
        (const byte*)"\xed\x15\x08" "file_buf",
        (const byte*)"\x9e\x1a\x0d" "NotFoundError",
        (const byte*)"\xd7\xb9\x08" "op_split",
        (const byte*)"\xb7\x56\x0b" "op_basename",
        (const byte*)"\xb4\xa9\x09" "_makedirs",
        (const byte*)"\xbd\xa0\x09" "save_file",
        (const byte*)"\x7c\xcb\x0b" "install_tar",
        (const byte*)"\x4c\x47\x0a" "expandhome",
        (const byte*)"\x49\xae\x09" "warn_ussl",
        (const byte*)"\xc5\xfa\x08" "url_open",
        (const byte*)"\xa2\x78\x10" "get_pkg_metadata",
        (const byte*)"\xdb\xd0\x05" "fatal",
        (const byte*)"\xa7\xb8\x0b" "install_pkg",
        (const byte*)"\x04\xdb\x07" "install",
        (const byte*)"\xdf\xf8\x10" "get_install_path",
        (const byte*)"\xc5\x2e\x07" "cleanup",
        (const byte*)"\xce\xb7\x04" "main",
        (const byte*)"\x70\x70\x02" "wb",
        (const byte*)"\xe4\x55\x05" "fname",
        (const byte*)"\x27\x31\x04" "subf",
        (const byte*)"\x2c\x5b\x06" "setup.",
        (const byte*)"\xfa\xaa\x08" "PKG-INFO",
        (const byte*)"\x5f\xeb\x06" "README",
        (const byte*)"\x2d\x61\x09" ".egg-info",
        (const byte*)"\xae\x9d\x0b" "extractfile",
        (const byte*)"\x87\xec\x04" "deps",
        (const byte*)"\x34\xd0\x08" "Skipping",
        (const byte*)"\x42\x17\x07" "DIRTYPE",
        (const byte*)"\xc3\xb5\x01" "f",
        (const byte*)"\x95\x3e\x06" "prefix",
        (const byte*)"\x14\x71\x02" "~/",
        (const byte*)"\xae\xfb\x06" "getenv",
        (const byte*)"\x6a\x76\x04" "HOME",
        (const byte*)"\xd6\xb5\x01" "s",
        (const byte*)"\x34\xf9\x06" "https:",
        (const byte*)"\x8e\x63\x03" "url",
        (const byte*)"\x47\x4d\x06" "Error:",
        (const byte*)"\x7c\x46\x03" "msg",
        (const byte*)"\xdb\x24\x03" "exc",
        (const byte*)"\xeb\xb3\x04" "info",
        (const byte*)"\x1f\x8d\x08" "releases",
        (const byte*)"\x64\xfd\x07" "TarFile",
        (const byte*)"\x04\x4c\x07" "fileobj",
        (const byte*)"\x43\x9a\x08" "pkg_spec",
        (const byte*)"\x0e\x69\x06" "Queue:",
        (const byte*)"\x80\xf8\x0a" "to_install",
        (const byte*)"\xfe\x8f\x06" "unlink",
        (const byte*)"\xe0\x66\x02" "-h",
        (const byte*)"\x34\x6e\x06" "--help",
        (const byte*)"\xf8\x66\x02" "-p",
        (const byte*)"\xfa\x66\x02" "-r",
        (const byte*)"\x86\xb5\x01" "#",
        (const byte*)"\x34\x9b\x07" "--debug",
        (const byte*)"\x88\xb5\x01" "-",
        (const byte*)"\x55\x87\x10" "upip_utarfile.py",
        (const byte*)"\x82\x45\x0a" "TAR_HEADER",
        (const byte*)"\xcd\xd1\x07" "REGTYPE",
        (const byte*)"\x82\x38\x07" "roundup",
        (const byte*)"\x0a\x55\x0b" "FileSection",
        (const byte*)"\x4c\x5c\x07" "TarInfo",
        (const byte*)"\xa8\xfb\x05" "align",
        (const byte*)"\x04\xaf\x04" "skip",
        (const byte*)"\x54\x75\x0b" "content_len",
        (const byte*)"\xb1\x45\x0b" "aligned_len",
        (const byte*)"\xec\x70\x02" "sz",
        (const byte*)"\xd5\x70\x02" "rb",
        (const byte*)"\x0c\x60\x07" "tarinfo",
        (const byte*)"\x35\x8e\x0c" "urequests.py",
        (const byte*)"\xc6\x16\x08" "Response",
        (const byte*)"\xb1\x60\x0c" "request_sema",
        (const byte*)"\x74\xb0\x07" "request",
        (const byte*)"\xed\x5d\x04" "head",
        (const byte*)"\x3d\xd8\x04" "post",
        (const byte*)"\x8b\x9e\x05" "patch",
        (const byte*)"\x9c\xe7\x06" "delete",
        (const byte*)"\xac\xd9\x07" "content",
        (const byte*)"\xe1\x8b\x03" "raw",
        (const byte*)"\x52\x18\x07" "_cached",
        (const byte*)"\x07\x0f\x05" "http:",
        (const byte*)"\x9f\xb5\x01" ":",
        (const byte*)"\x05\xfa\x04" "Host",
        (const byte*)"\x63\xf5\x0b" "status_code",
        (const byte*)"\xc1\xe7\x06" "reason",
        (const byte*)"\x6c\x84\x08" "uquest: ",
        (const byte*)"\x9a\x58\x06" "method",
        (const byte*)"\xa9\xab\x07" "headers",
        (const byte*)"\x59\xd4\x06" "stream",
        (const byte*)"\xed\x7d\x04" "HEAD",
        (const byte*)"\x13\xbf\x03" "GET",
        (const byte*)"\x3d\x19\x04" "POST",
        (const byte*)"\x94\x0c\x03" "PUT",
        (const byte*)"\xeb\xd7\x05" "PATCH",
        (const byte*)"\x1c\x2c\x06" "DELETE",
        (const byte*)"\xab\x3d\x08" "_boot.py",
        (const byte*)"\x0c\xb4\x08" "inisetup",
        (const byte*)"\x86\x7a\x03" "vfs",
    },
};

// frozen bytecode for file apa106.py, scope apa106__lt_module_gt__APA106
STATIC const byte bytecode_data_apa106__lt_module_gt__APA106[39] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8,
    MP_QSTR_apa106_dot_py & 0xff, MP_QSTR_apa106_dot_py >> 8,
    0x8d, 0x07, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x80, 
    0x81, 
    0x82, 
    0x83, 
    0x50, 0x04, 
    0x24, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_raw_code_t raw_code_apa106__lt_module_gt__APA106 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_apa106__lt_module_gt__APA106,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 39,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file apa106.py, scope apa106_<module>
STATIC const byte bytecode_data_apa106__lt_module_gt_[48] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_apa106_dot_py & 0xff, MP_QSTR_apa106_dot_py >> 8,
    0x61, 0x70, 0x00, 0x00, 0xff,
    0x80, 
    0x16, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x50, 0x01, 
    0x68, MP_QSTR_neopixel & 0xff, MP_QSTR_neopixel >> 8,
    0x69, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x24, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x32, 
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8,
    0x1b, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_apa106__lt_module_gt_[1] = {
    MP_ROM_PTR(&raw_code_apa106__lt_module_gt__APA106),
};
const mp_raw_code_t raw_code_apa106__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_apa106__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_apa106__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 48,
        .n_obj = 0,
        .n_raw_code = 1,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHTBase___init__
STATIC const byte bytecode_data_dht__lt_module_gt__DHTBase___init__[34] = {
    0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x81, 0x07, 0x25, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x85, 
    0x64, 0x01, 
    0xb0, 
    0x26, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHTBase___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHTBase___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHTBase___init__,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHTBase___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 34,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHTBase_measure
STATIC const byte bytecode_data_dht__lt_module_gt__DHTBase_measure[75] = {
    0x06, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_measure & 0xff, MP_QSTR_measure >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x81, 0x0b, 0x25, 0x2e, 0x3a, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0xc1, 
    0x1c, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb1, 
    0x66, 0x02, 
    0x32, 
    0xb1, 
    0x80, 
    0x21, 
    0xb1, 
    0x81, 
    0x21, 
    0xf1, 
    0xb1, 
    0x82, 
    0x21, 
    0xf1, 
    0xb1, 
    0x83, 
    0x21, 
    0xf1, 
    0x14, 0x81, 0x7f, 
    0xee, 
    0xb1, 
    0x84, 
    0x21, 
    0xdc, 
    0x37, 0x09, 0x80, 
    0x1c, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0x17, 0x01, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_dht__lt_module_gt__DHTBase_measure_0 = {{&mp_type_str}, 53040, 14, (const byte*)"\x63\x68\x65\x63\x6b\x73\x75\x6d\x20\x65\x72\x72\x6f\x72"};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHTBase_measure[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_PTR(&const_obj_dht__lt_module_gt__DHTBase_measure_0),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHTBase_measure = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHTBase_measure,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHTBase_measure,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 75,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHTBase
STATIC const byte bytecode_data_dht__lt_module_gt__DHTBase[42] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
    MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x6d, 0x60, 0x65, 0x20, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_measure & 0xff, MP_QSTR_measure >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHTBase[2] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHTBase___init__),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHTBase_measure),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHTBase = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHTBase,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHTBase,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 42,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT11_humidity
STATIC const byte bytecode_data_dht__lt_module_gt__DHT11_humidity[23] = {
    0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x81, 0x12, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x80, 
    0x21, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT11_humidity[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT11_humidity = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHT11_humidity,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT11_humidity,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 23,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT11_temperature
STATIC const byte bytecode_data_dht__lt_module_gt__DHT11_temperature[23] = {
    0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x81, 0x15, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x82, 
    0x21, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT11_temperature[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT11_temperature = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHT11_temperature,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT11_temperature,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 23,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT11
STATIC const byte bytecode_data_dht__lt_module_gt__DHT11[41] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x8d, 0x11, 0x65, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT11[2] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT11_humidity),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT11_temperature),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT11 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHT11,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT11,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 41,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT22_humidity
STATIC const byte bytecode_data_dht__lt_module_gt__DHT22_humidity[35] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x81, 0x19, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x80, 
    0x21, 
    0x88, 
    0xef, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x81, 
    0x21, 
    0xec, 
    0x17, 0x01, 
    0xf3, 
    0x5b, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_dht__lt_module_gt__DHT22_humidity_0 = {{&mp_type_float}, 0.1};
#endif
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT22_humidity[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_dht__lt_module_gt__DHT22_humidity_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbe4cccce),
#else
#error "MICROPY_OBJ_REPR_D not supported with floats in frozen mpy files"
#endif
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT22_humidity = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHT22_humidity,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT22_humidity,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 35,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT22_temperature
STATIC const byte bytecode_data_dht__lt_module_gt__DHT22_temperature[60] = {
    0x05, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x81, 0x1c, 0x37, 0x2d, 0x23, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x82, 
    0x21, 
    0x14, 0x80, 0x7f, 
    0xee, 
    0x88, 
    0xef, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x83, 
    0x21, 
    0xec, 
    0x17, 0x01, 
    0xf3, 
    0xc1, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x82, 
    0x21, 
    0x14, 0x81, 0x00, 
    0xee, 
    0x37, 0x03, 0x80, 
    0xb1, 
    0xd1, 
    0xc1, 
    0xb1, 
    0x5b, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_dht__lt_module_gt__DHT22_temperature_0 = {{&mp_type_float}, 0.1};
#endif
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT22_temperature[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_dht__lt_module_gt__DHT22_temperature_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbe4cccce),
#else
#error "MICROPY_OBJ_REPR_D not supported with floats in frozen mpy files"
#endif
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT22_temperature = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHT22_temperature,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT22_temperature,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 60,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT22
STATIC const byte bytecode_data_dht__lt_module_gt__DHT22[41] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x8d, 0x18, 0x65, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT22[2] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT22_humidity),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT22_temperature),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT22 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt__DHT22,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT22,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 41,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file dht.py, scope dht_<module>
STATIC const byte bytecode_data_dht__lt_module_gt_[69] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x61, 0x48, 0x8b, 0x0b, 0x8e, 0x07, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x24, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x20, 
    0x60, 0x01, 
    0x16, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    0x1b, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    0x20, 
    0x60, 0x02, 
    0x16, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    0x1b, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt_[3] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHTBase),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT11),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT22),
};
const mp_raw_code_t raw_code_dht__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_dht__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 69,
        .n_obj = 0,
        .n_raw_code = 3,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHTBase___init__
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHTBase___init__[34] = {
    0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x81, 0x07, 0x25, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x85, 
    0x64, 0x01, 
    0xb0, 
    0x26, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHTBase___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHTBase___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHTBase___init__,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHTBase___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 34,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHTBase_measure
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHTBase_measure[75] = {
    0x06, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_measure & 0xff, MP_QSTR_measure >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x81, 0x0b, 0x25, 0x2e, 0x3a, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0xc1, 
    0x1c, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb1, 
    0x66, 0x02, 
    0x32, 
    0xb1, 
    0x80, 
    0x21, 
    0xb1, 
    0x81, 
    0x21, 
    0xf1, 
    0xb1, 
    0x82, 
    0x21, 
    0xf1, 
    0xb1, 
    0x83, 
    0x21, 
    0xf1, 
    0x14, 0x81, 0x7f, 
    0xee, 
    0xb1, 
    0x84, 
    0x21, 
    0xdc, 
    0x37, 0x09, 0x80, 
    0x1c, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0x17, 0x01, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_ds18x20__lt_module_gt__DHTBase_measure_0 = {{&mp_type_str}, 53040, 14, (const byte*)"\x63\x68\x65\x63\x6b\x73\x75\x6d\x20\x65\x72\x72\x6f\x72"};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHTBase_measure[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_PTR(&const_obj_ds18x20__lt_module_gt__DHTBase_measure_0),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHTBase_measure = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHTBase_measure,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHTBase_measure,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 75,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHTBase
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHTBase[42] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
    MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x6d, 0x60, 0x65, 0x20, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_measure & 0xff, MP_QSTR_measure >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHTBase[2] = {
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHTBase___init__),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHTBase_measure),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHTBase = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHTBase,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHTBase,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 42,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHT11_humidity
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHT11_humidity[23] = {
    0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x81, 0x12, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x80, 
    0x21, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHT11_humidity[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHT11_humidity = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHT11_humidity,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHT11_humidity,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 23,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHT11_temperature
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHT11_temperature[23] = {
    0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x81, 0x15, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x82, 
    0x21, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHT11_temperature[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHT11_temperature = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHT11_temperature,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHT11_temperature,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 23,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHT11
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHT11[41] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x8d, 0x11, 0x65, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHT11[2] = {
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHT11_humidity),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHT11_temperature),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHT11 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHT11,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHT11,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 41,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHT22_humidity
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHT22_humidity[35] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x81, 0x19, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x80, 
    0x21, 
    0x88, 
    0xef, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x81, 
    0x21, 
    0xec, 
    0x17, 0x01, 
    0xf3, 
    0x5b, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_ds18x20__lt_module_gt__DHT22_humidity_0 = {{&mp_type_float}, 0.1};
#endif
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHT22_humidity[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_ds18x20__lt_module_gt__DHT22_humidity_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbe4cccce),
#else
#error "MICROPY_OBJ_REPR_D not supported with floats in frozen mpy files"
#endif
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHT22_humidity = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHT22_humidity,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHT22_humidity,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 35,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHT22_temperature
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHT22_temperature[60] = {
    0x05, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x81, 0x1c, 0x37, 0x2d, 0x23, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x82, 
    0x21, 
    0x14, 0x80, 0x7f, 
    0xee, 
    0x88, 
    0xef, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x83, 
    0x21, 
    0xec, 
    0x17, 0x01, 
    0xf3, 
    0xc1, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x82, 
    0x21, 
    0x14, 0x81, 0x00, 
    0xee, 
    0x37, 0x03, 0x80, 
    0xb1, 
    0xd1, 
    0xc1, 
    0xb1, 
    0x5b, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_ds18x20__lt_module_gt__DHT22_temperature_0 = {{&mp_type_float}, 0.1};
#endif
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHT22_temperature[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_ds18x20__lt_module_gt__DHT22_temperature_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbe4cccce),
#else
#error "MICROPY_OBJ_REPR_D not supported with floats in frozen mpy files"
#endif
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHT22_temperature = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHT22_temperature,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHT22_temperature,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 60,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DHT22
STATIC const byte bytecode_data_ds18x20__lt_module_gt__DHT22[41] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a,
    MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x8d, 0x18, 0x65, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DHT22[2] = {
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHT22_humidity),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHT22_temperature),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DHT22 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt__DHT22,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DHT22,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 41,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file ds18x20.py, scope ds18x20_<module>
STATIC const byte bytecode_data_ds18x20__lt_module_gt_[69] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x61, 0x48, 0x8b, 0x0b, 0x8e, 0x07, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x24, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x20, 
    0x60, 0x01, 
    0x16, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    0x1b, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    0x20, 
    0x60, 0x02, 
    0x16, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    0x1b, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt_[3] = {
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHTBase),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHT11),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DHT22),
};
const mp_raw_code_t raw_code_ds18x20__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_ds18x20__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 69,
        .n_obj = 0,
        .n_raw_code = 3,
        #endif
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev__lt_module_gt__FlashBdev___init__
STATIC const byte bytecode_data_flashbdev__lt_module_gt__FlashBdev___init__[23] = {
    0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x81, 0x08, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_blocks & 0xff, MP_QSTR_blocks >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_flashbdev__lt_module_gt__FlashBdev___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_blocks),
};
STATIC const mp_raw_code_t raw_code_flashbdev__lt_module_gt__FlashBdev___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_flashbdev__lt_module_gt__FlashBdev___init__,
        .const_table = (mp_uint_t*)const_table_data_flashbdev__lt_module_gt__FlashBdev___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 23,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev__lt_module_gt__FlashBdev_readblocks
STATIC const byte bytecode_data_flashbdev__lt_module_gt__FlashBdev_readblocks[39] = {
    0x07, 0x00, 0x00, 0x03, 0x00, 0x00, 0x09,
    MP_QSTR_readblocks & 0xff, MP_QSTR_readblocks >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x81, 0x0c, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_flash_read & 0xff, MP_QSTR_flash_read >> 8,
    0xb1, 
    0xb0, 
    0x1d, MP_QSTR_START_SEC & 0xff, MP_QSTR_START_SEC >> 8,
    0xf1, 
    0xb0, 
    0x1d, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0xf3, 
    0xb2, 
    0x66, 0x02, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_flashbdev__lt_module_gt__FlashBdev_readblocks[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_n),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_flashbdev__lt_module_gt__FlashBdev_readblocks = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_flashbdev__lt_module_gt__FlashBdev_readblocks,
        .const_table = (mp_uint_t*)const_table_data_flashbdev__lt_module_gt__FlashBdev_readblocks,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 39,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev__lt_module_gt__FlashBdev_writeblocks
STATIC const byte bytecode_data_flashbdev__lt_module_gt__FlashBdev_writeblocks[55] = {
    0x07, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0a,
    MP_QSTR_writeblocks & 0xff, MP_QSTR_writeblocks >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x81, 0x11, 0x2f, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_flash_erase & 0xff, MP_QSTR_flash_erase >> 8,
    0xb1, 
    0xb0, 
    0x1d, MP_QSTR_START_SEC & 0xff, MP_QSTR_START_SEC >> 8,
    0xf1, 
    0x66, 0x01, 
    0x32, 
    0x1c, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_flash_write & 0xff, MP_QSTR_flash_write >> 8,
    0xb1, 
    0xb0, 
    0x1d, MP_QSTR_START_SEC & 0xff, MP_QSTR_START_SEC >> 8,
    0xf1, 
    0xb0, 
    0x1d, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0xf3, 
    0xb2, 
    0x66, 0x02, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_flashbdev__lt_module_gt__FlashBdev_writeblocks[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_n),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_flashbdev__lt_module_gt__FlashBdev_writeblocks = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_flashbdev__lt_module_gt__FlashBdev_writeblocks,
        .const_table = (mp_uint_t*)const_table_data_flashbdev__lt_module_gt__FlashBdev_writeblocks,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 55,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev__lt_module_gt__FlashBdev_ioctl
STATIC const byte bytecode_data_flashbdev__lt_module_gt__FlashBdev_ioctl[43] = {
    0x05, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0c,
    MP_QSTR_ioctl & 0xff, MP_QSTR_ioctl >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x81, 0x16, 0x26, 0x25, 0x26, 0x00, 0x00, 0xff,
    0xb1, 
    0x84, 
    0xd9, 
    0x37, 0x05, 0x80, 
    0xb0, 
    0x1d, MP_QSTR_blocks & 0xff, MP_QSTR_blocks >> 8,
    0x5b, 
    0xb1, 
    0x85, 
    0xd9, 
    0x37, 0x05, 0x80, 
    0xb0, 
    0x1d, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0x5b, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_flashbdev__lt_module_gt__FlashBdev_ioctl[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_op),
    MP_ROM_QSTR(MP_QSTR_arg),
};
STATIC const mp_raw_code_t raw_code_flashbdev__lt_module_gt__FlashBdev_ioctl = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_flashbdev__lt_module_gt__FlashBdev_ioctl,
        .const_table = (mp_uint_t*)const_table_data_flashbdev__lt_module_gt__FlashBdev_ioctl,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 43,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev__lt_module_gt__FlashBdev
STATIC const byte bytecode_data_flashbdev__lt_module_gt__FlashBdev[78] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
    MP_QSTR_FlashBdev & 0xff, MP_QSTR_FlashBdev >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x6d, 0x20, 0x26, 0x4f, 0x65, 0x65, 0x20, 0x65, 0x60, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_FlashBdev & 0xff, MP_QSTR_FlashBdev >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x14, 0xa0, 0x00, 
    0x24, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0x1b, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_flash_user_start & 0xff, MP_QSTR_flash_user_start >> 8,
    0x66, 0x00, 
    0x1b, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0xf4, 
    0x24, MP_QSTR_START_SEC & 0xff, MP_QSTR_START_SEC >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_readblocks & 0xff, MP_QSTR_readblocks >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR_writeblocks & 0xff, MP_QSTR_writeblocks >> 8,
    0x60, 0x03, 
    0x24, MP_QSTR_ioctl & 0xff, MP_QSTR_ioctl >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_flashbdev__lt_module_gt__FlashBdev[4] = {
    MP_ROM_PTR(&raw_code_flashbdev__lt_module_gt__FlashBdev___init__),
    MP_ROM_PTR(&raw_code_flashbdev__lt_module_gt__FlashBdev_readblocks),
    MP_ROM_PTR(&raw_code_flashbdev__lt_module_gt__FlashBdev_writeblocks),
    MP_ROM_PTR(&raw_code_flashbdev__lt_module_gt__FlashBdev_ioctl),
};
STATIC const mp_raw_code_t raw_code_flashbdev__lt_module_gt__FlashBdev = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_flashbdev__lt_module_gt__FlashBdev,
        .const_table = (mp_uint_t*)const_table_data_flashbdev__lt_module_gt__FlashBdev,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 78,
        .n_obj = 0,
        .n_raw_code = 4,
        #endif
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev_<module>
STATIC const byte bytecode_data_flashbdev__lt_module_gt_[93] = {
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x49, 0x8b, 0x19, 0x2b, 0x4c, 0x67, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x24, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_FlashBdev & 0xff, MP_QSTR_FlashBdev >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_FlashBdev & 0xff, MP_QSTR_FlashBdev >> 8,
    0x1b, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x1e, MP_QSTR_flash_size & 0xff, MP_QSTR_flash_size >> 8,
    0x66, 0x00, 
    0x24, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x1b, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x14, 0x80, 0xc0, 0x80, 0x00, 
    0xd7, 
    0x37, 0x07, 0x80, 
    0x11, 
    0x24, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x35, 0x16, 0x80, 
    0x1b, MP_QSTR_FlashBdev & 0xff, MP_QSTR_FlashBdev >> 8,
    0x14, 0x90, 0x00, 
    0x14, 0x88, 0x00, 
    0xf3, 
    0x1b, MP_QSTR_FlashBdev & 0xff, MP_QSTR_FlashBdev >> 8,
    0x1d, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0xf4, 
    0x64, 0x01, 
    0x24, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_flashbdev__lt_module_gt_[1] = {
    MP_ROM_PTR(&raw_code_flashbdev__lt_module_gt__FlashBdev),
};
const mp_raw_code_t raw_code_flashbdev__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_flashbdev__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_flashbdev__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 93,
        .n_obj = 0,
        .n_raw_code = 1,
        #endif
    },
};

// frozen bytecode for file inisetup.py, scope inisetup__lt_module_gt__check_bootsec
STATIC const byte bytecode_data_inisetup__lt_module_gt__check_bootsec[90] = {
    0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12,
    MP_QSTR_check_bootsec & 0xff, MP_QSTR_check_bootsec >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x61, 0x20, 0x2c, 0x2b, 0x22, 0x26, 0x28, 0x22, 0x2a, 0x24, 0x22, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x1c, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x1d, MP_QSTR_SEC_SIZE & 0xff, MP_QSTR_SEC_SIZE >> 8,
    0x64, 0x01, 
    0xc0, 
    0x1c, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x1e, MP_QSTR_readblocks & 0xff, MP_QSTR_readblocks >> 8,
    0x80, 
    0xb0, 
    0x66, 0x02, 
    0x32, 
    0x12, 
    0xc1, 
    0xb0, 
    0x47, 
    0x43, 0x15, 0x00, 
    0xc2, 
    0xb2, 
    0x14, 0x81, 0x7f, 
    0xdc, 
    0x37, 0x09, 0x80, 
    0x10, 
    0xc1, 
    0x32, 
    0x32, 
    0x32, 
    0x32, 
    0x35, 0x03, 0x80, 
    0x35, 0xe8, 0x7f, 
    0xb1, 
    0x37, 0x02, 0x80, 
    0x12, 
    0x5b, 
    0x1c, MP_QSTR_fs_corrupted & 0xff, MP_QSTR_fs_corrupted >> 8,
    0x64, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_raw_code_t raw_code_inisetup__lt_module_gt__check_bootsec = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_inisetup__lt_module_gt__check_bootsec,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 90,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file inisetup.py, scope inisetup__lt_module_gt__fs_corrupted
STATIC const byte bytecode_data_inisetup__lt_module_gt__fs_corrupted[47] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    MP_QSTR_fs_corrupted & 0xff, MP_QSTR_fs_corrupted >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x81, 0x10, 0x26, 0x20, 0x68, 0x60, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_time & 0xff, MP_QSTR_time >> 8,
    0xc0, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x00, 
    0x64, 0x01, 
    0x32, 
    0xb0, 
    0x1e, MP_QSTR_sleep & 0xff, MP_QSTR_sleep >> 8,
    0x83, 
    0x66, 0x01, 
    0x32, 
    0x35, 0xed, 0x7f, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_inisetup__lt_module_gt__fs_corrupted_0 = {{&mp_type_str}, 33619, 258, (const byte*)"\x46\x41\x54\x20\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x20\x61\x70\x70\x65\x61\x72\x73\x20\x74\x6f\x20\x62\x65\x20\x63\x6f\x72\x72\x75\x70\x74\x65\x64\x2e\x20\x49\x66\x20\x79\x6f\x75\x20\x68\x61\x64\x20\x69\x6d\x70\x6f\x72\x74\x61\x6e\x74\x20\x64\x61\x74\x61\x20\x74\x68\x65\x72\x65\x2c\x20\x79\x6f\x75\x0a\x6d\x61\x79\x20\x77\x61\x6e\x74\x20\x74\x6f\x20\x6d\x61\x6b\x65\x20\x61\x20\x66\x6c\x61\x73\x68\x20\x73\x6e\x61\x70\x73\x68\x6f\x74\x20\x74\x6f\x20\x74\x72\x79\x20\x74\x6f\x20\x72\x65\x63\x6f\x76\x65\x72\x20\x69\x74\x2e\x20\x4f\x74\x68\x65\x72\x77\x69\x73\x65\x2c\x20\x70\x65\x72\x66\x6f\x72\x6d\x0a\x66\x61\x63\x74\x6f\x72\x79\x20\x72\x65\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x20\x6f\x66\x20\x4d\x69\x63\x72\x6f\x50\x79\x74\x68\x6f\x6e\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x28\x63\x6f\x6d\x70\x6c\x65\x74\x65\x6c\x79\x20\x65\x72\x61\x73\x65\x20\x66\x6c\x61\x73\x68\x2c\x20\x66\x6f\x6c\x6c\x6f\x77\x65\x64\x0a\x62\x79\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x29\x2e\x0a"};
STATIC const mp_rom_obj_t const_table_data_inisetup__lt_module_gt__fs_corrupted[1] = {
    MP_ROM_PTR(&const_obj_inisetup__lt_module_gt__fs_corrupted_0),
};
STATIC const mp_raw_code_t raw_code_inisetup__lt_module_gt__fs_corrupted = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_inisetup__lt_module_gt__fs_corrupted,
        .const_table = (mp_uint_t*)const_table_data_inisetup__lt_module_gt__fs_corrupted,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 47,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file inisetup.py, scope inisetup__lt_module_gt__setup
STATIC const byte bytecode_data_inisetup__lt_module_gt__setup[120] = {
    0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x11,
    MP_QSTR_setup & 0xff, MP_QSTR_setup >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x81, 0x1b, 0x26, 0x28, 0x2f, 0x2c, 0x2d, 0x2c, 0x2f, 0x6d, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_check_bootsec & 0xff, MP_QSTR_check_bootsec >> 8,
    0x64, 0x00, 
    0x32, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x00, 
    0x64, 0x01, 
    0x32, 
    0x1c, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x1d, MP_QSTR_VfsFat & 0xff, MP_QSTR_VfsFat >> 8,
    0x1e, MP_QSTR_mkfs & 0xff, MP_QSTR_mkfs >> 8,
    0x1c, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x66, 0x01, 
    0x32, 
    0x1c, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x1e, MP_QSTR_VfsFat & 0xff, MP_QSTR_VfsFat >> 8,
    0x1c, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x66, 0x01, 
    0xc0, 
    0x1c, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x1e, MP_QSTR_mount & 0xff, MP_QSTR_mount >> 8,
    0xb0, 
    0x16, MP_QSTR__slash_flash & 0xff, MP_QSTR__slash_flash >> 8,
    0x66, 0x02, 
    0x32, 
    0x1c, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x1e, MP_QSTR_chdir & 0xff, MP_QSTR_chdir >> 8,
    0x16, MP_QSTR__slash_flash & 0xff, MP_QSTR__slash_flash >> 8,
    0x66, 0x01, 
    0x32, 
    0x1c, MP_QSTR_open & 0xff, MP_QSTR_open >> 8,
    0x16, MP_QSTR_boot_dot_py & 0xff, MP_QSTR_boot_dot_py >> 8,
    0x16, MP_QSTR_w & 0xff, MP_QSTR_w >> 8,
    0x64, 0x02, 
    0x3d, 0x0c, 0x00, 
    0xc1, 
    0xb1, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x01, 
    0x66, 0x01, 
    0x32, 
    0x44, 
    0x11, 
    0x3e, 
    0x41, 
    0xb0, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_inisetup__lt_module_gt__setup_0 = {{&mp_type_str}, 7181, 24, (const byte*)"\x50\x65\x72\x66\x6f\x72\x6d\x69\x6e\x67\x20\x69\x6e\x69\x74\x69\x61\x6c\x20\x73\x65\x74\x75\x70"};
STATIC const mp_obj_str_t const_obj_inisetup__lt_module_gt__setup_1 = {{&mp_type_str}, 24049, 75, (const byte*)"\x23\x20\x54\x68\x69\x73\x20\x66\x69\x6c\x65\x20\x69\x73\x20\x65\x78\x65\x63\x75\x74\x65\x64\x20\x6f\x6e\x20\x65\x76\x65\x72\x79\x20\x62\x6f\x6f\x74\x20\x28\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x77\x61\x6b\x65\x2d\x62\x6f\x6f\x74\x20\x66\x72\x6f\x6d\x20\x64\x65\x65\x70\x73\x6c\x65\x65\x70\x29\x0a"};
STATIC const mp_rom_obj_t const_table_data_inisetup__lt_module_gt__setup[2] = {
    MP_ROM_PTR(&const_obj_inisetup__lt_module_gt__setup_0),
    MP_ROM_PTR(&const_obj_inisetup__lt_module_gt__setup_1),
};
STATIC const mp_raw_code_t raw_code_inisetup__lt_module_gt__setup = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_inisetup__lt_module_gt__setup,
        .const_table = (mp_uint_t*)const_table_data_inisetup__lt_module_gt__setup,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 120,
        .n_obj = 2,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file inisetup.py, scope inisetup_<module>
STATIC const byte bytecode_data_inisetup__lt_module_gt_[61] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x29, 0x50, 0x85, 0x0c, 0x85, 0x0b, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x24, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x80, 
    0x16, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x50, 0x01, 
    0x68, MP_QSTR_flashbdev & 0xff, MP_QSTR_flashbdev >> 8,
    0x69, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x24, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x32, 
    0x60, 0x00, 
    0x24, MP_QSTR_check_bootsec & 0xff, MP_QSTR_check_bootsec >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_fs_corrupted & 0xff, MP_QSTR_fs_corrupted >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR_setup & 0xff, MP_QSTR_setup >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_inisetup__lt_module_gt_[3] = {
    MP_ROM_PTR(&raw_code_inisetup__lt_module_gt__check_bootsec),
    MP_ROM_PTR(&raw_code_inisetup__lt_module_gt__fs_corrupted),
    MP_ROM_PTR(&raw_code_inisetup__lt_module_gt__setup),
};
const mp_raw_code_t raw_code_inisetup__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_inisetup__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_inisetup__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 61,
        .n_obj = 0,
        .n_raw_code = 3,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___init__
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel___init__[69] = {
    0x08, 0x00, 0x00, 0x05, 0x00, 0x02, 0x0e,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x81, 0x0a, 0x25, 0x25, 0x25, 0x2c, 0x2e, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb2, 
    0xb0, 
    0x26, MP_QSTR_n & 0xff, MP_QSTR_n >> 8,
    0xb3, 
    0xb0, 
    0x26, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8,
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0xb2, 
    0xb3, 
    0xf3, 
    0x64, 0x01, 
    0xb0, 
    0x26, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x1e, MP_QSTR_init & 0xff, MP_QSTR_init >> 8,
    0xb1, 
    0x1d, MP_QSTR_OUT & 0xff, MP_QSTR_OUT >> 8,
    0x66, 0x01, 
    0x32, 
    0xb4, 
    0xb0, 
    0x26, MP_QSTR_timing & 0xff, MP_QSTR_timing >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___init__[5] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
    MP_ROM_QSTR(MP_QSTR_n),
    MP_ROM_QSTR(MP_QSTR_bpp),
    MP_ROM_QSTR(MP_QSTR_timing),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 5,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel___init__,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 69,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___setitem__
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel___setitem__[63] = {
    0x0c, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0b,
    MP_QSTR___setitem__ & 0xff, MP_QSTR___setitem__ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x81, 0x12, 0x27, 0x2a, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x1d, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8,
    0xf3, 
    0xc3, 
    0xb0, 
    0x1d, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8,
    0x80, 
    0x35, 0x14, 0x80, 
    0x30, 
    0xc4, 
    0xb2, 
    0xb4, 
    0x21, 
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0xb3, 
    0xb0, 
    0x1d, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8,
    0xb4, 
    0x21, 
    0xf1, 
    0x27, 
    0x81, 
    0xe5, 
    0x31, 
    0x33, 
    0xd7, 
    0x36, 0xe6, 0x7f, 
    0x32, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___setitem__[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_index),
    MP_ROM_QSTR(MP_QSTR_val),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___setitem__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel___setitem__,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___setitem__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 63,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___getitem___<genexpr>
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_[47] = {
    0x0c, 0x00, 0x04, 0x03, 0x00, 0x00, 0x09,
    MP_QSTR__lt_genexpr_gt_ & 0xff, MP_QSTR__lt_genexpr_gt_ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x89, 0x18, 0x00, 0x00, 0xff,
    0x18, 
    0xb2, 
    0x18, 
    0x18, 
    0x43, 0x16, 0x00, 
    0xc3, 
    0x1a, 0x00, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0x1a, 0x01, 
    0x1a, 0x00, 
    0x1d, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8,
    0xb3, 
    0x21, 
    0xf1, 
    0x21, 
    0x5d, 
    0x32, 
    0x35, 0xe7, 0x7f, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_[3] = {
    MP_ROM_QSTR(MP_QSTR__star_),
    MP_ROM_QSTR(MP_QSTR__star_),
    MP_ROM_QSTR(MP_QSTR__star_),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x04,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 47,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___getitem__
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel___getitem__[53] = {
    0x07, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0b,
    MP_QSTR___getitem__ & 0xff, MP_QSTR___getitem__ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x83, 0x17, 0x29, 0x28, 0x00, 0x00, 0x00, 0x02, 0xff,
    0xb1, 
    0x1a, 0x00, 
    0x1d, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8,
    0xf3, 
    0x23, 0x02, 
    0x1c, MP_QSTR_tuple & 0xff, MP_QSTR_tuple >> 8,
    0xb0, 
    0xb2, 
    0x62, 0x02, 0x02, 
    0x1c, MP_QSTR_range & 0xff, MP_QSTR_range >> 8,
    0x1a, 0x00, 
    0x1d, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8,
    0x64, 0x01, 
    0x42, 
    0x64, 0x01, 
    0x64, 0x01, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___getitem__[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_index),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___getitem__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel___getitem__,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___getitem__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 53,
        .n_obj = 0,
        .n_raw_code = 1,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel_fill
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel_fill[43] = {
    0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a,
    MP_QSTR_fill & 0xff, MP_QSTR_fill >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x81, 0x1c, 0x2a, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_n & 0xff, MP_QSTR_n >> 8,
    0x80, 
    0x35, 0x08, 0x80, 
    0x30, 
    0xc2, 
    0xb1, 
    0xb0, 
    0xb2, 
    0x27, 
    0x81, 
    0xe5, 
    0x31, 
    0x33, 
    0xd7, 
    0x36, 0xf2, 0x7f, 
    0x32, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel_fill[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_color),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel_fill = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel_fill,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel_fill,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 43,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel_write
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel_write[36] = {
    0x05, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x81, 0x20, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb0, 
    0x1d, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8,
    0xb0, 
    0x1d, MP_QSTR_timing & 0xff, MP_QSTR_timing >> 8,
    0x64, 0x03, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel_write[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel_write = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel_write,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel_write,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 36,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel
STATIC const byte bytecode_data_neopixel__lt_module_gt__NeoPixel[78] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12,
    MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x8d, 0x07, 0x49, 0x8a, 0x08, 0x65, 0x40, 0x65, 0x40, 0x65, 0x20, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x81, 
    0x80, 
    0x82, 
    0x83, 
    0x50, 0x04, 
    0x24, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8,
    0x83, 
    0x80, 
    0x50, 0x02, 
    0x18, 
    0x61, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR___setitem__ & 0xff, MP_QSTR___setitem__ >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR___getitem__ & 0xff, MP_QSTR___getitem__ >> 8,
    0x60, 0x03, 
    0x24, MP_QSTR_fill & 0xff, MP_QSTR_fill >> 8,
    0x60, 0x04, 
    0x24, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel[5] = {
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___init__),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___setitem__),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___getitem__),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel_fill),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel_write),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt__NeoPixel,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 78,
        .n_obj = 0,
        .n_raw_code = 5,
        #endif
    },
};

// frozen bytecode for file neopixel.py, scope neopixel_<module>
STATIC const byte bytecode_data_neopixel__lt_module_gt_[45] = {
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x61, 0x70, 0x00, 0x00, 0xff,
    0x80, 
    0x16, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8,
    0x50, 0x01, 
    0x68, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8,
    0x69, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8,
    0x24, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8,
    0x32, 
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt_[1] = {
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel),
};
const mp_raw_code_t raw_code_neopixel__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_neopixel__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 45,
        .n_obj = 0,
        .n_raw_code = 1,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWireError
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWireError[30] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x8d, 0x07, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWireError = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWireError,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 30,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire___init__
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire___init__[42] = {
    0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x0f, 0x25, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x1e, MP_QSTR_init & 0xff, MP_QSTR_init >> 8,
    0xb1, 
    0x1d, MP_QSTR_OPEN_DRAIN & 0xff, MP_QSTR_OPEN_DRAIN >> 8,
    0xb1, 
    0x1d, MP_QSTR_PULL_UP & 0xff, MP_QSTR_PULL_UP >> 8,
    0x66, 0x02, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire___init__,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 42,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_reset
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_reset[47] = {
    0x06, 0x00, 0x00, 0x02, 0x00, 0x01, 0x0c,
    MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x13, 0x2d, 0x28, 0x25, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x66, 0x01, 
    0xc2, 
    0xb1, 
    0x37, 0x09, 0x80, 
    0xb2, 
    0x36, 0x05, 0x80, 
    0x1c, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8,
    0x5c, 0x01, 
    0xb2, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_reset[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_required),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_reset = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_reset,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_reset,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 47,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_readbit
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_readbit[29] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x19, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x66, 0x01, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_readbit[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_readbit = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_readbit,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_readbit,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 29,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_readbyte
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_readbyte[29] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x1c, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x66, 0x01, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_readbyte[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_readbyte = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_readbyte,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_readbyte,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 29,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_readinto
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_readinto[56] = {
    0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a,
    MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x1f, 0x2c, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0xb1, 
    0x64, 0x01, 
    0x80, 
    0x35, 0x13, 0x80, 
    0x30, 
    0xc2, 
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0x66, 0x01, 
    0xb1, 
    0xb2, 
    0x27, 
    0x81, 
    0xe5, 
    0x31, 
    0x33, 
    0xd7, 
    0x36, 0xe7, 0x7f, 
    0x32, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_readinto[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_readinto = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_readinto,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_readinto,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 56,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_writebit
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_writebit[30] = {
    0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09,
    MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x23, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb1, 
    0x66, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_writebit[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_value),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_writebit = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_writebit,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_writebit,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 30,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_writebyte
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_writebyte[30] = {
    0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09,
    MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x26, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb1, 
    0x66, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_writebyte[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_value),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_writebyte = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_writebyte,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_writebyte,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 30,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_write
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_write[42] = {
    0x0b, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a,
    MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x29, 0x26, 0x00, 0x00, 0xff,
    0xb1, 
    0x47, 
    0x43, 0x12, 0x00, 
    0xc2, 
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    0xb0, 
    0x1d, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8,
    0xb2, 
    0x66, 0x02, 
    0x32, 
    0x35, 0xeb, 0x7f, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_write[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_write = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_write,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_write,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 42,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_select_rom
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_select_rom[45] = {
    0x05, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0b,
    MP_QSTR_select_rom & 0xff, MP_QSTR_select_rom >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x2d, 0x27, 0x2a, 0x00, 0x00, 0xff,
    0xb0, 
    0x1e, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8,
    0x66, 0x00, 
    0x32, 
    0xb0, 
    0x1e, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    0x14, 0x80, 0x55, 
    0x66, 0x01, 
    0x32, 
    0xb0, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0xb1, 
    0x66, 0x01, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_select_rom[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_rom),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_select_rom = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_select_rom,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_select_rom,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 45,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_scan
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_scan[84] = {
    0x0a, 0x00, 0x00, 0x01, 0x00, 0x00, 0x12,
    MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x32, 0x23, 0x24, 0x22, 0x26, 0x2c, 0x24, 0x26, 0x26, 0x2e, 0x00, 0x00, 0xff,
    0x51, 0x00, 
    0xc1, 
    0x14, 0x80, 0x41, 
    0xc2, 
    0x10, 
    0xc3, 
    0x80, 
    0x35, 0x23, 0x80, 
    0x30, 
    0xc4, 
    0xb0, 
    0x1e, MP_QSTR__search_rom & 0xff, MP_QSTR__search_rom >> 8,
    0xb3, 
    0xb2, 
    0x66, 0x02, 
    0x59, 0x02, 
    0xc3, 
    0xc2, 
    0xb3, 
    0x37, 0x06, 0x80, 
    0xb1, 
    0xb3, 
    0x51, 0x01, 
    0xe5, 
    0xc1, 
    0xb2, 
    0x80, 
    0xd9, 
    0x37, 0x03, 0x80, 
    0x35, 0x0a, 0x80, 
    0x81, 
    0xe5, 
    0x30, 
    0x14, 0x81, 0x7f, 
    0xd7, 
    0x36, 0xd5, 0x7f, 
    0x32, 
    0xb1, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_scan[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_scan = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_scan,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_scan,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 84,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire__search_rom
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire__search_rom[209] = {
    0x0f, 0x00, 0x00, 0x03, 0x00, 0x00, 0x21,
    MP_QSTR__search_rom & 0xff, MP_QSTR__search_rom >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x3e, 0x29, 0x25, 0x2a, 0x24, 0x27, 0x27, 0x22, 0x24, 0x26, 0x22, 0x26, 0x27, 0x29, 0x24, 0x48, 0x24, 0x36, 0x22, 0x22, 0x28, 0x24, 0x26, 0x2d, 0x2d, 0x00, 0x00, 0xff,
    0xb0, 
    0x1e, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8,
    0x66, 0x00, 
    0x36, 0x05, 0x80, 
    0x11, 
    0x80, 
    0x50, 0x02, 
    0x5b, 
    0xb0, 
    0x1e, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    0x14, 0x81, 0x70, 
    0x66, 0x01, 
    0x32, 
    0xb1, 
    0x36, 0x07, 0x80, 
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x88, 
    0x64, 0x01, 
    0xc1, 
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x88, 
    0x64, 0x01, 
    0xc3, 
    0x80, 
    0xc4, 
    0x14, 0x80, 0x40, 
    0xc5, 
    0x80, 
    0x35, 0x69, 0x80, 
    0x30, 
    0xc6, 
    0x80, 
    0xc7, 
    0x80, 
    0x35, 0x54, 0x80, 
    0x30, 
    0xc8, 
    0xb0, 
    0x1e, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8,
    0x66, 0x00, 
    0xc9, 
    0xb0, 
    0x1e, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8,
    0x66, 0x00, 
    0x37, 0x0c, 0x80, 
    0xb9, 
    0x37, 0x05, 0x80, 
    0x11, 
    0x80, 
    0x50, 0x02, 
    0x5b, 
    0x35, 0x1e, 0x80, 
    0xb9, 
    0x36, 0x1a, 0x80, 
    0xb2, 
    0xb5, 
    0xd8, 
    0x36, 0x10, 0x80, 
    0xb1, 
    0xb6, 
    0x21, 
    0x81, 
    0xb8, 
    0xef, 
    0xee, 
    0x37, 0x0a, 0x80, 
    0xb2, 
    0xb5, 
    0xdc, 
    0x37, 0x04, 0x80, 
    0x81, 
    0xc9, 
    0xb5, 
    0xc4, 
    0xb0, 
    0x1e, MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8,
    0xb9, 
    0x66, 0x01, 
    0x32, 
    0xb9, 
    0x37, 0x06, 0x80, 
    0xb7, 
    0x81, 
    0xb8, 
    0xef, 
    0xe0, 
    0xc7, 
    0xb5, 
    0x81, 
    0xe6, 
    0xc5, 
    0x81, 
    0xe5, 
    0x30, 
    0x88, 
    0xd7, 
    0x36, 0xa6, 0x7f, 
    0x32, 
    0xb7, 
    0xb3, 
    0xb6, 
    0x27, 
    0x81, 
    0xe5, 
    0x30, 
    0x88, 
    0xd7, 
    0x36, 0x91, 0x7f, 
    0x32, 
    0xb3, 
    0xb4, 
    0x50, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire__search_rom[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_l_rom),
    MP_ROM_QSTR(MP_QSTR_diff),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire__search_rom = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire__search_rom,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire__search_rom,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 209,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_crc8
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire_crc8[26] = {
    0x05, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09,
    MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x81, 0x5a, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x1e, MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8,
    0xb1, 
    0x66, 0x01, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_crc8[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_data),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_crc8 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire_crc8,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_crc8,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 26,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire
STATIC const byte bytecode_data_onewire__lt_module_gt__OneWire[133] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e,
    MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x8d, 0x0a, 0x26, 0x26, 0x46, 0x65, 0x20, 0x69, 0x60, 0x65, 0x65, 0x65, 0x20, 0x65, 0x65, 0x65, 0x20, 0x65, 0x40, 0x85, 0x0c, 0x85, 0x1c, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x14, 0x81, 0x70, 
    0x24, MP_QSTR_SEARCH_ROM & 0xff, MP_QSTR_SEARCH_ROM >> 8,
    0x14, 0x80, 0x55, 
    0x24, MP_QSTR_MATCH_ROM & 0xff, MP_QSTR_MATCH_ROM >> 8,
    0x14, 0x81, 0x4c, 
    0x24, MP_QSTR_SKIP_ROM & 0xff, MP_QSTR_SKIP_ROM >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x10, 
    0x50, 0x01, 
    0x18, 
    0x61, 0x01, 
    0x24, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8,
    0x60, 0x03, 
    0x24, MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8,
    0x60, 0x04, 
    0x24, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    0x60, 0x05, 
    0x24, MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8,
    0x60, 0x06, 
    0x24, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    0x60, 0x07, 
    0x24, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x60, 0x08, 
    0x24, MP_QSTR_select_rom & 0xff, MP_QSTR_select_rom >> 8,
    0x60, 0x09, 
    0x24, MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8,
    0x60, 0x0a, 
    0x24, MP_QSTR__search_rom & 0xff, MP_QSTR__search_rom >> 8,
    0x60, 0x0b, 
    0x24, MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire[12] = {
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire___init__),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_reset),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_readbit),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_readbyte),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_readinto),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_writebit),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_writebyte),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_write),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_select_rom),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_scan),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire__search_rom),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_crc8),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt__OneWire,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 133,
        .n_obj = 0,
        .n_raw_code = 12,
        #endif
    },
};

// frozen bytecode for file onewire.py, scope onewire_<module>
STATIC const byte bytecode_data_onewire__lt_module_gt_[69] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x61, 0x30, 0x48, 0x6e, 0x00, 0x00, 0xff,
    0x80, 
    0x16, MP_QSTR_const & 0xff, MP_QSTR_const >> 8,
    0x50, 0x01, 
    0x68, MP_QSTR_micropython & 0xff, MP_QSTR_micropython >> 8,
    0x69, MP_QSTR_const & 0xff, MP_QSTR_const >> 8,
    0x24, MP_QSTR_const & 0xff, MP_QSTR_const >> 8,
    0x32, 
    0x80, 
    0x11, 
    0x68, MP_QSTR__onewire & 0xff, MP_QSTR__onewire >> 8,
    0x24, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8,
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8,
    0x1b, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8,
    0x20, 
    0x60, 0x01, 
    0x16, MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt_[2] = {
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWireError),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire),
};
const mp_raw_code_t raw_code_onewire__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_onewire__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 69,
        .n_obj = 0,
        .n_raw_code = 2,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__NotFoundError
STATIC const byte bytecode_data_upip__lt_module_gt__NotFoundError[30] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x8d, 0x12, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__NotFoundError = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__NotFoundError,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 30,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__op_split
STATIC const byte bytecode_data_upip__lt_module_gt__op_split[89] = {
    0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x11,
    MP_QSTR_op_split & 0xff, MP_QSTR_op_split >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x15, 0x28, 0x29, 0x2b, 0x2b, 0x27, 0x24, 0x24, 0x24, 0x00, 0x00, 0xff,
    0xb0, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0xd9, 
    0x37, 0x09, 0x80, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0x50, 0x02, 
    0x5b, 
    0xb0, 
    0x1e, MP_QSTR_rsplit & 0xff, MP_QSTR_rsplit >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x81, 
    0x66, 0x02, 
    0xc1, 
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0xb1, 
    0x64, 0x01, 
    0x81, 
    0xd9, 
    0x37, 0x07, 0x80, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0xb0, 
    0x50, 0x02, 
    0x5b, 
    0xb1, 
    0x80, 
    0x21, 
    0xc2, 
    0xb2, 
    0x36, 0x04, 0x80, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xc2, 
    0xb2, 
    0xb1, 
    0x81, 
    0x21, 
    0x50, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__op_split[1] = {
    MP_ROM_QSTR(MP_QSTR_path),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__op_split = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__op_split,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__op_split,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 89,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__op_basename
STATIC const byte bytecode_data_upip__lt_module_gt__op_basename[25] = {
    0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_op_basename & 0xff, MP_QSTR_op_basename >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x20, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_op_split & 0xff, MP_QSTR_op_split >> 8,
    0xb0, 
    0x64, 0x01, 
    0x81, 
    0x21, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__op_basename[1] = {
    MP_ROM_QSTR(MP_QSTR_path),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__op_basename = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__op_basename,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__op_basename,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 25,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt___makedirs
STATIC const byte bytecode_data_upip__lt_module_gt___makedirs[189] = {
    0x11, 0x02, 0x00, 0x02, 0x00, 0x01, 0x19,
    MP_QSTR__makedirs & 0xff, MP_QSTR__makedirs >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x24, 0x22, 0x24, 0x37, 0x2a, 0x24, 0x26, 0x2e, 0x26, 0x24, 0x23, 0x2a, 0x52, 0x1f, 0x21, 0x22, 0x31, 0x00, 0x00, 0xff,
    0x10, 
    0xc2, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0xc3, 
    0xb0, 
    0x1e, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x66, 0x01, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x66, 0x01, 
    0x11, 
    0x7f, 
    0x58, 0x02, 
    0x21, 
    0xc4, 
    0xb4, 
    0x80, 
    0x21, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0xd9, 
    0x37, 0x04, 0x80, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xc3, 
    0xb4, 
    0x47, 
    0x43, 0x6b, 0x00, 
    0xc5, 
    0xb3, 
    0x37, 0x10, 0x80, 
    0xb3, 
    0x7f, 
    0x21, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xdc, 
    0x37, 0x06, 0x80, 
    0xb3, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xe5, 
    0xc3, 
    0xb3, 
    0xb5, 
    0xe5, 
    0xc3, 
    0x3f, 0x10, 0x00, 
    0x1c, MP_QSTR_os & 0xff, MP_QSTR_os >> 8,
    0x1e, MP_QSTR_mkdir & 0xff, MP_QSTR_mkdir >> 8,
    0xb3, 
    0x66, 0x01, 
    0x32, 
    0x12, 
    0xc2, 
    0x44, 
    0x35, 0x3c, 0x80, 
    0x30, 
    0x1c, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8,
    0xdf, 
    0x37, 0x33, 0x80, 
    0xc6, 
    0x40, 0x27, 0x00, 
    0xb6, 
    0x1d, MP_QSTR_args & 0xff, MP_QSTR_args >> 8,
    0x80, 
    0x21, 
    0x1c, MP_QSTR_errno & 0xff, MP_QSTR_errno >> 8,
    0x1d, MP_QSTR_EEXIST & 0xff, MP_QSTR_EEXIST >> 8,
    0xdc, 
    0x37, 0x12, 0x80, 
    0xb6, 
    0x1d, MP_QSTR_args & 0xff, MP_QSTR_args >> 8,
    0x80, 
    0x21, 
    0x1c, MP_QSTR_errno & 0xff, MP_QSTR_errno >> 8,
    0x1d, MP_QSTR_EISDIR & 0xff, MP_QSTR_EISDIR >> 8,
    0xdc, 
    0x37, 0x02, 0x80, 
    0x5c, 0x00, 
    0x10, 
    0xc2, 
    0x44, 
    0x45, 
    0x11, 
    0x11, 
    0xc6, 
    0x28, 0x06, 
    0x41, 
    0x35, 0x01, 0x80, 
    0x41, 
    0x35, 0x92, 0x7f, 
    0xb2, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt___makedirs[2] = {
    MP_ROM_QSTR(MP_QSTR_name),
    MP_ROM_QSTR(MP_QSTR_mode),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt___makedirs = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt___makedirs,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt___makedirs,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 189,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__save_file
STATIC const byte bytecode_data_upip__lt_module_gt__save_file[72] = {
    0x0a, 0x01, 0x00, 0x02, 0x00, 0x00, 0x0f,
    MP_QSTR_save_file & 0xff, MP_QSTR_save_file >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x38, 0x20, 0x2d, 0x20, 0x2a, 0x24, 0x23, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_open & 0xff, MP_QSTR_open >> 8,
    0xb0, 
    0x16, MP_QSTR_wb & 0xff, MP_QSTR_wb >> 8,
    0x64, 0x02, 
    0x3d, 0x22, 0x00, 
    0xc2, 
    0xb1, 
    0x1e, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    0x1c, MP_QSTR_file_buf & 0xff, MP_QSTR_file_buf >> 8,
    0x66, 0x01, 
    0xc3, 
    0xb3, 
    0x36, 0x03, 0x80, 
    0x35, 0x0e, 0x80, 
    0xb2, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x1c, MP_QSTR_file_buf & 0xff, MP_QSTR_file_buf >> 8,
    0xb3, 
    0x66, 0x02, 
    0x32, 
    0x35, 0xe1, 0x7f, 
    0x44, 
    0x11, 
    0x3e, 
    0x41, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__save_file[2] = {
    MP_ROM_QSTR(MP_QSTR_fname),
    MP_ROM_QSTR(MP_QSTR_subf),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__save_file = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__save_file,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__save_file,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 72,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__install_tar
STATIC const byte bytecode_data_upip__lt_module_gt__install_tar[253] = {
    0x14, 0x01, 0x00, 0x02, 0x00, 0x00, 0x20,
    MP_QSTR_install_tar & 0xff, MP_QSTR_install_tar >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x41, 0x23, 0x46, 0x25, 0x23, 0x5e, 0x49, 0x22, 0x50, 0x32, 0x2b, 0x31, 0x22, 0x26, 0x2a, 0x4a, 0x24, 0x24, 0x2e, 0x26, 0x2a, 0x27, 0x28, 0x2b, 0x00, 0x00, 0xff,
    0x53, 0x00, 
    0xc2, 
    0xb0, 
    0x47, 
    0x43, 0xcc, 0x00, 
    0xc3, 
    0xb3, 
    0x1d, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0xc4, 
    0x3f, 0x15, 0x00, 
    0xb4, 
    0xb4, 
    0x1e, MP_QSTR_index & 0xff, MP_QSTR_index >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x66, 0x01, 
    0x81, 
    0xf1, 
    0x11, 
    0x58, 0x02, 
    0x21, 
    0xc4, 
    0x44, 
    0x35, 0x12, 0x80, 
    0x30, 
    0x1c, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8,
    0xdf, 
    0x37, 0x09, 0x80, 
    0x32, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0xc4, 
    0x45, 
    0x35, 0x01, 0x80, 
    0x41, 
    0x12, 
    0xc5, 
    0x16, MP_QSTR_setup_dot_ & 0xff, MP_QSTR_setup_dot_ >> 8,
    0x16, MP_QSTR_PKG_hyphen_INFO & 0xff, MP_QSTR_PKG_hyphen_INFO >> 8,
    0x16, MP_QSTR_README & 0xff, MP_QSTR_README >> 8,
    0x50, 0x03, 
    0x47, 
    0x43, 0x4b, 0x00, 
    0xc6, 
    0xb4, 
    0x1e, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8,
    0xb6, 
    0x66, 0x01, 
    0x36, 0x08, 0x80, 
    0x16, MP_QSTR__dot_egg_hyphen_info & 0xff, MP_QSTR__dot_egg_hyphen_info >> 8,
    0xb4, 
    0xdd, 
    0x37, 0x35, 0x80, 
    0xb4, 
    0x1e, MP_QSTR_endswith & 0xff, MP_QSTR_endswith >> 8,
    0x17, 0x02, 
    0x66, 0x01, 
    0x37, 0x11, 0x80, 
    0xb0, 
    0x1e, MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8,
    0xb3, 
    0x66, 0x01, 
    0x1e, MP_QSTR_read & 0xff, MP_QSTR_read >> 8,
    0x66, 0x00, 
    0xb2, 
    0x16, MP_QSTR_deps & 0xff, MP_QSTR_deps >> 8,
    0x27, 
    0x10, 
    0xc5, 
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x37, 0x0a, 0x80, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x16, MP_QSTR_Skipping & 0xff, MP_QSTR_Skipping >> 8,
    0xb4, 
    0x64, 0x02, 
    0x32, 
    0x32, 
    0x32, 
    0x32, 
    0x32, 
    0x35, 0x03, 0x80, 
    0x35, 0xb2, 0x7f, 
    0xb5, 
    0x37, 0x39, 0x80, 
    0xb1, 
    0xb4, 
    0xf1, 
    0xc7, 
    0xb3, 
    0x1d, MP_QSTR_type & 0xff, MP_QSTR_type >> 8,
    0x1c, MP_QSTR_tarfile & 0xff, MP_QSTR_tarfile >> 8,
    0x1d, MP_QSTR_DIRTYPE & 0xff, MP_QSTR_DIRTYPE >> 8,
    0xdc, 
    0x37, 0x27, 0x80, 
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x37, 0x0a, 0x80, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x03, 
    0xb7, 
    0xf1, 
    0x64, 0x01, 
    0x32, 
    0x1c, MP_QSTR__makedirs & 0xff, MP_QSTR__makedirs >> 8,
    0xb7, 
    0x64, 0x01, 
    0x32, 
    0xb0, 
    0x1e, MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8,
    0xb3, 
    0x66, 0x01, 
    0xc8, 
    0x1c, MP_QSTR_save_file & 0xff, MP_QSTR_save_file >> 8,
    0xb7, 
    0xb8, 
    0x64, 0x02, 
    0x32, 
    0x35, 0x31, 0x7f, 
    0xb2, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_tar_0 = {{&mp_type_str}, 36962, 13, (const byte*)"\x2f\x72\x65\x71\x75\x69\x72\x65\x73\x2e\x74\x78\x74"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_tar_1 = {{&mp_type_str}, 56712, 11, (const byte*)"\x45\x78\x74\x72\x61\x63\x74\x69\x6e\x67\x20"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__install_tar[4] = {
    MP_ROM_QSTR(MP_QSTR_f),
    MP_ROM_QSTR(MP_QSTR_prefix),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_tar_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_tar_1),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__install_tar = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__install_tar,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__install_tar,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 253,
        .n_obj = 2,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__expandhome
STATIC const byte bytecode_data_upip__lt_module_gt__expandhome[56] = {
    0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_expandhome & 0xff, MP_QSTR_expandhome >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x60, 0x28, 0x2c, 0x2f, 0x00, 0x00, 0xff,
    0x16, MP_QSTR__tilde__slash_ & 0xff, MP_QSTR__tilde__slash_ >> 8,
    0xb0, 
    0xdd, 
    0x37, 0x1b, 0x80, 
    0x1c, MP_QSTR_os & 0xff, MP_QSTR_os >> 8,
    0x1e, MP_QSTR_getenv & 0xff, MP_QSTR_getenv >> 8,
    0x16, MP_QSTR_HOME & 0xff, MP_QSTR_HOME >> 8,
    0x66, 0x01, 
    0xc1, 
    0xb0, 
    0x1e, MP_QSTR_replace & 0xff, MP_QSTR_replace >> 8,
    0x16, MP_QSTR__tilde__slash_ & 0xff, MP_QSTR__tilde__slash_ >> 8,
    0xb1, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xf1, 
    0x66, 0x02, 
    0xc0, 
    0xb0, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__expandhome[1] = {
    MP_ROM_QSTR(MP_QSTR_s),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__expandhome = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__expandhome,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__expandhome,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 56,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__url_open
STATIC const byte bytecode_data_upip__lt_module_gt__url_open[345] = {
    0x13, 0x02, 0x00, 0x01, 0x00, 0x00, 0x28,
    MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x69, 0x40, 0x26, 0x47, 0x30, 0x23, 0x5d, 0x57, 0x46, 0x2e, 0x43, 0x48, 0x28, 0x2a, 0x26, 0x2a, 0x64, 0x2e, 0x27, 0x2d, 0x27, 0x2e, 0x29, 0x28, 0x20, 0x27, 0x24, 0x29, 0x27, 0x56, 0x27, 0x4f, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x37, 0x07, 0x80, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0xb0, 
    0x64, 0x01, 
    0x32, 
    0xb0, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x83, 
    0x66, 0x02, 
    0x59, 0x04, 
    0xc1, 
    0xc2, 
    0xc3, 
    0xc4, 
    0x3f, 0x11, 0x00, 
    0x1c, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x1e, MP_QSTR_getaddrinfo & 0xff, MP_QSTR_getaddrinfo >> 8,
    0xb3, 
    0x14, 0x83, 0x3b, 
    0x66, 0x02, 
    0xc5, 
    0x44, 
    0x35, 0x23, 0x80, 
    0x30, 
    0x1c, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8,
    0xdf, 
    0x37, 0x1a, 0x80, 
    0xc6, 
    0x40, 0x0e, 0x00, 
    0x1c, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8,
    0x17, 0x01, 
    0xb3, 
    0xf6, 
    0xb6, 
    0x64, 0x02, 
    0x32, 
    0x44, 
    0x45, 
    0x11, 
    0x11, 
    0xc6, 
    0x28, 0x06, 
    0x41, 
    0x35, 0x01, 0x80, 
    0x41, 
    0xb5, 
    0x80, 
    0x21, 
    0x84, 
    0x21, 
    0xc7, 
    0x1c, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x1e, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8,
    0xb5, 
    0x80, 
    0x21, 
    0x80, 
    0x21, 
    0x66, 0x01, 
    0xc8, 
    0x3f, 0x9b, 0x00, 
    0xb8, 
    0x1e, MP_QSTR_connect & 0xff, MP_QSTR_connect >> 8,
    0xb7, 
    0x66, 0x01, 
    0x32, 
    0xb1, 
    0x16, MP_QSTR_https_colon_ & 0xff, MP_QSTR_https_colon_ >> 8,
    0xd9, 
    0x37, 0x1e, 0x80, 
    0x1c, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8,
    0x1e, MP_QSTR_wrap_socket & 0xff, MP_QSTR_wrap_socket >> 8,
    0xb8, 
    0x66, 0x01, 
    0xc8, 
    0x1c, MP_QSTR_warn_ussl & 0xff, MP_QSTR_warn_ussl >> 8,
    0x37, 0x0e, 0x80, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x02, 
    0xb3, 
    0xf6, 
    0x64, 0x01, 
    0x32, 
    0x10, 
    0x25, MP_QSTR_warn_ussl & 0xff, MP_QSTR_warn_ussl >> 8,
    0xb8, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x03, 
    0xb4, 
    0xb3, 
    0x50, 0x02, 
    0xf6, 
    0x66, 0x01, 
    0x32, 
    0xb8, 
    0x1e, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8,
    0x66, 0x00, 
    0xc9, 
    0xb9, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x11, 
    0x82, 
    0x66, 0x02, 
    0x59, 0x03, 
    0xca, 
    0xcb, 
    0xcc, 
    0xbb, 
    0x17, 0x04, 
    0xdc, 
    0x37, 0x1f, 0x80, 
    0xbb, 
    0x17, 0x05, 
    0xd9, 
    0x36, 0x07, 0x80, 
    0xbb, 
    0x17, 0x06, 
    0xd9, 
    0x37, 0x09, 0x80, 
    0x1c, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8,
    0x17, 0x07, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0x1c, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8,
    0xbb, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0xb8, 
    0x1e, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8,
    0x66, 0x00, 
    0xc9, 
    0xb9, 
    0x36, 0x09, 0x80, 
    0x1c, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8,
    0x17, 0x08, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0xb9, 
    0x17, 0x09, 
    0xd9, 
    0x37, 0x03, 0x80, 
    0x35, 0x03, 0x80, 
    0x35, 0xdf, 0x7f, 
    0x44, 
    0x35, 0x22, 0x80, 
    0x30, 
    0x1c, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0xdf, 
    0x37, 0x19, 0x80, 
    0xc6, 
    0x40, 0x0d, 0x00, 
    0xb8, 
    0x1e, MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    0x66, 0x00, 
    0x32, 
    0xb6, 
    0x5c, 0x01, 
    0x44, 
    0x45, 
    0x11, 
    0x11, 
    0xc6, 
    0x28, 0x06, 
    0x41, 
    0x35, 0x01, 0x80, 
    0x41, 
    0xb8, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_0 = {{&mp_type_str}, 10889, 35, (const byte*)"\x55\x6e\x61\x62\x6c\x65\x20\x74\x6f\x20\x72\x65\x73\x6f\x6c\x76\x65\x20\x25\x73\x20\x28\x6e\x6f\x20\x49\x6e\x74\x65\x72\x6e\x65\x74\x3f\x29"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_1 = {{&mp_type_str}, 51159, 44, (const byte*)"\x57\x61\x72\x6e\x69\x6e\x67\x3a\x20\x25\x73\x20\x53\x53\x4c\x20\x63\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x76\x61\x6c\x69\x64\x61\x74\x65\x64"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_2 = {{&mp_type_str}, 26169, 30, (const byte*)"\x47\x45\x54\x20\x2f\x25\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\x0d\x0a\x48\x6f\x73\x74\x3a\x20\x25\x73\x0d\x0a\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_3 = {{&mp_type_bytes}, 28951, 3, (const byte*)"\x32\x30\x30"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_4 = {{&mp_type_bytes}, 22421, 3, (const byte*)"\x34\x30\x34"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_5 = {{&mp_type_bytes}, 29975, 3, (const byte*)"\x33\x30\x31"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_6 = {{&mp_type_str}, 48284, 17, (const byte*)"\x50\x61\x63\x6b\x61\x67\x65\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_7 = {{&mp_type_str}, 39199, 30, (const byte*)"\x55\x6e\x65\x78\x70\x65\x63\x74\x65\x64\x20\x45\x4f\x46\x20\x69\x6e\x20\x48\x54\x54\x50\x20\x68\x65\x61\x64\x65\x72\x73"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_8 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__url_open[10] = {
    MP_ROM_QSTR(MP_QSTR_url),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_1),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_2),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_3),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_4),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_5),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_6),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_7),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_8),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__url_open = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__url_open,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__url_open,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 345,
        .n_obj = 9,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__get_pkg_metadata
STATIC const byte bytecode_data_upip__lt_module_gt__get_pkg_metadata[54] = {
    0x08, 0x01, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_get_pkg_metadata & 0xff, MP_QSTR_get_pkg_metadata >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x97, 0x2a, 0x23, 0x4c, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8,
    0x17, 0x01, 
    0xb0, 
    0xf6, 
    0x64, 0x01, 
    0xc1, 
    0x40, 0x0c, 0x00, 
    0x1c, MP_QSTR_json & 0xff, MP_QSTR_json >> 8,
    0x1e, MP_QSTR_load & 0xff, MP_QSTR_load >> 8,
    0xb1, 
    0x66, 0x01, 
    0x5b, 
    0x44, 
    0x11, 
    0xb1, 
    0x1e, MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    0x66, 0x00, 
    0x32, 
    0x41, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__get_pkg_metadata_0 = {{&mp_type_str}, 42459, 36, (const byte*)"\x68\x74\x74\x70\x73\x3a\x2f\x2f\x70\x79\x70\x69\x2e\x70\x79\x74\x68\x6f\x6e\x2e\x6f\x72\x67\x2f\x70\x79\x70\x69\x2f\x25\x73\x2f\x6a\x73\x6f\x6e"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__get_pkg_metadata[2] = {
    MP_ROM_QSTR(MP_QSTR_name),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__get_pkg_metadata_0),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__get_pkg_metadata = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__get_pkg_metadata,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__get_pkg_metadata,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 54,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__fatal
STATIC const byte bytecode_data_upip__lt_module_gt__fatal[54] = {
    0x05, 0x00, 0x00, 0x02, 0x00, 0x01, 0x0c,
    MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0x9f, 0x2a, 0x2a, 0x23, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x16, MP_QSTR_Error_colon_ & 0xff, MP_QSTR_Error_colon_ >> 8,
    0xb0, 
    0x64, 0x02, 
    0x32, 
    0xb1, 
    0x37, 0x09, 0x80, 
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x37, 0x03, 0x80, 
    0xb1, 
    0x5c, 0x01, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1e, MP_QSTR_exit & 0xff, MP_QSTR_exit >> 8,
    0x81, 
    0x66, 0x01, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__fatal[2] = {
    MP_ROM_QSTR(MP_QSTR_msg),
    MP_ROM_QSTR(MP_QSTR_exc),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__fatal = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__fatal,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__fatal,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 54,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__install_pkg
STATIC const byte bytecode_data_upip__lt_module_gt__install_pkg[185] = {
    0x12, 0x01, 0x00, 0x02, 0x00, 0x00, 0x1b,
    MP_QSTR_install_pkg & 0xff, MP_QSTR_install_pkg >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0xa5, 0x47, 0x2a, 0x28, 0x22, 0x29, 0x30, 0x28, 0x2e, 0x27, 0x27, 0x23, 0x2d, 0x2e, 0x4a, 0x28, 0x22, 0x22, 0x29, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_get_pkg_metadata & 0xff, MP_QSTR_get_pkg_metadata >> 8,
    0xb0, 
    0x64, 0x01, 
    0xc2, 
    0xb2, 
    0x16, MP_QSTR_info & 0xff, MP_QSTR_info >> 8,
    0x21, 
    0x16, MP_QSTR_version & 0xff, MP_QSTR_version >> 8,
    0x21, 
    0xc3, 
    0xb2, 
    0x16, MP_QSTR_releases & 0xff, MP_QSTR_releases >> 8,
    0x21, 
    0xb3, 
    0x21, 
    0xc4, 
    0x28, 0x02, 
    0x1c, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x1e, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8,
    0x66, 0x00, 
    0x32, 
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0xb4, 
    0x64, 0x01, 
    0x81, 
    0xd9, 
    0x36, 0x05, 0x80, 
    0x1c, MP_QSTR_AssertionError & 0xff, MP_QSTR_AssertionError >> 8,
    0x5c, 0x01, 
    0xb4, 
    0x80, 
    0x21, 
    0x16, MP_QSTR_url & 0xff, MP_QSTR_url >> 8,
    0x21, 
    0xc5, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x02, 
    0xb0, 
    0xb3, 
    0xb5, 
    0x50, 0x03, 
    0xf6, 
    0x64, 0x01, 
    0x32, 
    0x1c, MP_QSTR_op_basename & 0xff, MP_QSTR_op_basename >> 8,
    0xb5, 
    0x64, 0x01, 
    0xc6, 
    0x1c, MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8,
    0xb5, 
    0x64, 0x01, 
    0xc7, 
    0x40, 0x25, 0x00, 
    0x1c, MP_QSTR_uzlib & 0xff, MP_QSTR_uzlib >> 8,
    0x1e, MP_QSTR_DecompIO & 0xff, MP_QSTR_DecompIO >> 8,
    0xb7, 
    0x1c, MP_QSTR_gzdict_sz & 0xff, MP_QSTR_gzdict_sz >> 8,
    0x66, 0x02, 
    0xc8, 
    0x1c, MP_QSTR_tarfile & 0xff, MP_QSTR_tarfile >> 8,
    0x1e, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8,
    0x16, MP_QSTR_fileobj & 0xff, MP_QSTR_fileobj >> 8,
    0xb8, 
    0x66, 0x82, 0x00, 
    0xc9, 
    0x1c, MP_QSTR_install_tar & 0xff, MP_QSTR_install_tar >> 8,
    0xb9, 
    0xb1, 
    0x64, 0x02, 
    0xca, 
    0x44, 
    0x11, 
    0xb7, 
    0x1e, MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    0x66, 0x00, 
    0x32, 
    0x41, 
    0x28, 0x09, 
    0x28, 0x08, 
    0x1c, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x1e, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8,
    0x66, 0x00, 
    0x32, 
    0xba, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_pkg_0 = {{&mp_type_str}, 7236, 24, (const byte*)"\x49\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x25\x73\x20\x25\x73\x20\x66\x72\x6f\x6d\x20\x25\x73"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__install_pkg[3] = {
    MP_ROM_QSTR(MP_QSTR_pkg_spec),
    MP_ROM_QSTR(MP_QSTR_install_path),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_pkg_0),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__install_pkg = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__install_pkg,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__install_pkg,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 185,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__install
STATIC const byte bytecode_data_upip__lt_module_gt__install[307] = {
    0x10, 0x02, 0x00, 0x02, 0x00, 0x01, 0x25,
    MP_QSTR_install & 0xff, MP_QSTR_install >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0xbd, 0x20, 0x32, 0x29, 0x44, 0x26, 0x26, 0x2a, 0x26, 0x2c, 0x24, 0x4a, 0x23, 0x23, 0x23, 0x26, 0x2a, 0x28, 0x26, 0x23, 0x28, 0x28, 0x26, 0x27, 0x32, 0x24, 0x32, 0x5c, 0x4f, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x1e, MP_QSTR_mem_free & 0xff, MP_QSTR_mem_free >> 8,
    0x66, 0x00, 
    0x1c, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x1e, MP_QSTR_mem_alloc & 0xff, MP_QSTR_mem_alloc >> 8,
    0x66, 0x00, 
    0xf1, 
    0xc2, 
    0xb2, 
    0x14, 0x84, 0x80, 0x00, 
    0xda, 
    0x37, 0x04, 0x80, 
    0x9c, 
    0x25, MP_QSTR_gzdict_sz & 0xff, MP_QSTR_gzdict_sz >> 8,
    0xb1, 
    0x11, 
    0xde, 
    0x37, 0x06, 0x80, 
    0x1c, MP_QSTR_get_install_path & 0xff, MP_QSTR_get_install_path >> 8,
    0x64, 0x00, 
    0xc1, 
    0xb1, 
    0x7f, 
    0x21, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xdc, 
    0x37, 0x06, 0x80, 
    0xb1, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xe5, 
    0xc1, 
    0x1c, MP_QSTR_isinstance & 0xff, MP_QSTR_isinstance >> 8,
    0xb0, 
    0x1c, MP_QSTR_list & 0xff, MP_QSTR_list >> 8,
    0x64, 0x02, 
    0x36, 0x04, 0x80, 
    0xb0, 
    0x51, 0x01, 
    0xc0, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x02, 
    0xb1, 
    0xf1, 
    0x64, 0x01, 
    0x32, 
    0x51, 0x00, 
    0xc3, 
    0x3f, 0x79, 0x00, 
    0x35, 0x6e, 0x80, 
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x37, 0x0a, 0x80, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x16, MP_QSTR_Queue_colon_ & 0xff, MP_QSTR_Queue_colon_ >> 8,
    0xb0, 
    0x64, 0x02, 
    0x32, 
    0xb0, 
    0x1e, MP_QSTR_pop & 0xff, MP_QSTR_pop >> 8,
    0x80, 
    0x66, 0x01, 
    0xc4, 
    0xb4, 
    0xb3, 
    0xdd, 
    0x37, 0x03, 0x80, 
    0x35, 0x4d, 0x80, 
    0x1c, MP_QSTR_install_pkg & 0xff, MP_QSTR_install_pkg >> 8,
    0xb4, 
    0xb1, 
    0x64, 0x02, 
    0xc5, 
    0xb3, 
    0x1e, MP_QSTR_append & 0xff, MP_QSTR_append >> 8,
    0xb4, 
    0x66, 0x01, 
    0x32, 
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x37, 0x07, 0x80, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0xb5, 
    0x64, 0x01, 
    0x32, 
    0xb5, 
    0x1e, MP_QSTR_get & 0xff, MP_QSTR_get >> 8,
    0x16, MP_QSTR_deps & 0xff, MP_QSTR_deps >> 8,
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0x66, 0x02, 
    0x1e, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8,
    0x66, 0x00, 
    0xc6, 
    0xb6, 
    0x37, 0x1a, 0x80, 
    0xb6, 
    0x1e, MP_QSTR_decode & 0xff, MP_QSTR_decode >> 8,
    0x16, MP_QSTR_utf_hyphen_8 & 0xff, MP_QSTR_utf_hyphen_8 >> 8,
    0x66, 0x01, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x16, MP_QSTR__0x0a_ & 0xff, MP_QSTR__0x0a_ >> 8,
    0x66, 0x01, 
    0xc6, 
    0xb0, 
    0x1e, MP_QSTR_extend & 0xff, MP_QSTR_extend >> 8,
    0xb6, 
    0x66, 0x01, 
    0x32, 
    0xb0, 
    0x36, 0x8e, 0x7f, 
    0x44, 
    0x35, 0x31, 0x80, 
    0x30, 
    0x1c, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0xdf, 
    0x37, 0x28, 0x80, 
    0xc7, 
    0x40, 0x1c, 0x00, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x03, 
    0x1e, MP_QSTR_format & 0xff, MP_QSTR_format >> 8,
    0xb4, 
    0xb7, 
    0x66, 0x02, 
    0x16, MP_QSTR_file & 0xff, MP_QSTR_file >> 8,
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_stderr & 0xff, MP_QSTR_stderr >> 8,
    0x64, 0x82, 0x01, 
    0x32, 
    0x44, 
    0x45, 
    0x11, 
    0x11, 
    0xc7, 
    0x28, 0x07, 
    0x41, 
    0x35, 0x01, 0x80, 
    0x41, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_0 = {{&mp_type_str}, 1253, 15, (const byte*)"\x49\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x74\x6f\x3a\x20"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_1 = {{&mp_type_str}, 31671, 62, (const byte*)"\x45\x72\x72\x6f\x72\x20\x69\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x27\x7b\x7d\x27\x3a\x20\x7b\x7d\x2c\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x6d\x61\x79\x20\x62\x65\x20\x70\x61\x72\x74\x69\x61\x6c\x6c\x79\x20\x69\x6e\x73\x74\x61\x6c\x6c\x65\x64"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__install[4] = {
    MP_ROM_QSTR(MP_QSTR_to_install),
    MP_ROM_QSTR(MP_QSTR_install_path),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_1),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__install = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__install,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__install,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 307,
        .n_obj = 2,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__get_install_path
STATIC const byte bytecode_data_upip__lt_module_gt__get_install_path[54] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    MP_QSTR_get_install_path & 0xff, MP_QSTR_get_install_path >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0xe0, 0x20, 0x48, 0x2b, 0x2b, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x11, 
    0xde, 
    0x37, 0x0b, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_path & 0xff, MP_QSTR_path >> 8,
    0x81, 
    0x21, 
    0x25, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x1c, MP_QSTR_expandhome & 0xff, MP_QSTR_expandhome >> 8,
    0x1c, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x64, 0x01, 
    0x25, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x1c, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x5b, 
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__get_install_path = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__get_install_path,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 54,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__cleanup
STATIC const byte bytecode_data_upip__lt_module_gt__cleanup[73] = {
    0x0b, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0c,
    MP_QSTR_cleanup & 0xff, MP_QSTR_cleanup >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0xe8, 0x28, 0x23, 0x57, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_cleanup_files & 0xff, MP_QSTR_cleanup_files >> 8,
    0x47, 
    0x43, 0x2d, 0x00, 
    0xc0, 
    0x3f, 0x0e, 0x00, 
    0x1c, MP_QSTR_os & 0xff, MP_QSTR_os >> 8,
    0x1e, MP_QSTR_unlink & 0xff, MP_QSTR_unlink >> 8,
    0xb0, 
    0x66, 0x01, 
    0x32, 
    0x44, 
    0x35, 0x18, 0x80, 
    0x30, 
    0x1c, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8,
    0xdf, 
    0x37, 0x0f, 0x80, 
    0x32, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x00, 
    0xb0, 
    0xf1, 
    0x64, 0x01, 
    0x32, 
    0x45, 
    0x35, 0x01, 0x80, 
    0x41, 
    0x35, 0xd0, 0x7f, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__cleanup_0 = {{&mp_type_str}, 17877, 23, (const byte*)"\x57\x61\x72\x6e\x69\x6e\x67\x3a\x20\x43\x61\x6e\x6e\x6f\x74\x20\x64\x65\x6c\x65\x74\x65\x20"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__cleanup[1] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__cleanup_0),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__cleanup = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__cleanup,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__cleanup,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 73,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__help
STATIC const byte bytecode_data_upip__lt_module_gt__help[53] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
    MP_QSTR_help & 0xff, MP_QSTR_help >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0xef, 0x88, 0x08, 0x30, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x00, 
    0x64, 0x01, 
    0x32, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x01, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_path & 0xff, MP_QSTR_path >> 8,
    0x81, 
    0x21, 
    0x64, 0x02, 
    0x32, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x17, 0x02, 
    0x64, 0x01, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__help_0 = {{&mp_type_str}, 14525, 341, (const byte*)"\x75\x70\x69\x70\x20\x2d\x20\x53\x69\x6d\x70\x6c\x65\x20\x50\x79\x50\x49\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x6d\x61\x6e\x61\x67\x65\x72\x20\x66\x6f\x72\x20\x4d\x69\x63\x72\x6f\x50\x79\x74\x68\x6f\x6e\x0a\x55\x73\x61\x67\x65\x3a\x20\x6d\x69\x63\x72\x6f\x70\x79\x74\x68\x6f\x6e\x20\x2d\x6d\x20\x75\x70\x69\x70\x20\x69\x6e\x73\x74\x61\x6c\x6c\x20\x5b\x2d\x70\x20\x3c\x70\x61\x74\x68\x3e\x5d\x20\x3c\x70\x61\x63\x6b\x61\x67\x65\x3e\x2e\x2e\x2e\x20\x7c\x20\x2d\x72\x20\x3c\x72\x65\x71\x75\x69\x72\x65\x6d\x65\x6e\x74\x73\x2e\x74\x78\x74\x3e\x0a\x69\x6d\x70\x6f\x72\x74\x20\x75\x70\x69\x70\x3b\x20\x75\x70\x69\x70\x2e\x69\x6e\x73\x74\x61\x6c\x6c\x28\x70\x61\x63\x6b\x61\x67\x65\x5f\x6f\x72\x5f\x6c\x69\x73\x74\x2c\x20\x5b\x3c\x70\x61\x74\x68\x3e\x5d\x29\x0a\x0a\x49\x66\x20\x3c\x70\x61\x74\x68\x3e\x20\x69\x73\x20\x6e\x6f\x74\x20\x67\x69\x76\x65\x6e\x2c\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x69\x6e\x73\x74\x61\x6c\x6c\x65\x64\x20\x69\x6e\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x5b\x31\x5d\x0a\x28\x63\x61\x6e\x20\x62\x65\x20\x73\x65\x74\x20\x66\x72\x6f\x6d\x20\x4d\x49\x43\x52\x4f\x50\x59\x50\x41\x54\x48\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x2c\x20\x69\x66\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x73\x79\x73\x74\x65\x6d\x0a\x73\x75\x70\x70\x6f\x72\x74\x73\x20\x74\x68\x61\x74\x29\x2e"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__help_1 = {{&mp_type_str}, 17177, 29, (const byte*)"\x43\x75\x72\x72\x65\x6e\x74\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x5b\x31\x5d\x3a"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__help_2 = {{&mp_type_str}, 34882, 146, (const byte*)"\x0a\x4e\x6f\x74\x65\x3a\x20\x6f\x6e\x6c\x79\x20\x4d\x69\x63\x72\x6f\x50\x79\x74\x68\x6f\x6e\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x28\x75\x73\x75\x61\x6c\x6c\x79\x2c\x20\x6e\x61\x6d\x65\x64\x20\x6d\x69\x63\x72\x6f\x70\x79\x74\x68\x6f\x6e\x2d\x2a\x29\x20\x61\x72\x65\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x0a\x66\x6f\x72\x20\x69\x6e\x73\x74\x61\x6c\x6c\x61\x74\x69\x6f\x6e\x2c\x20\x75\x70\x69\x70\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x61\x72\x62\x69\x74\x72\x61\x72\x79\x20\x63\x6f\x64\x65\x20\x69\x6e\x20\x73\x65\x74\x75\x70\x2e\x70\x79\x2e\x0a"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__help[3] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__help_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__help_1),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__help_2),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__help = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__help,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__help,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 53,
        .n_obj = 3,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__main
STATIC const byte bytecode_data_upip__lt_module_gt__main[399] = {
    0x0c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x32,
    MP_QSTR_main & 0xff, MP_QSTR_main >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x81, 0xff, 0x20, 0x20, 0x44, 0x1f, 0x2f, 0x26, 0x42, 0x2f, 0x48, 0x43, 0x22, 0x23, 0x29, 0x24, 0x30, 0x26, 0x22, 0x28, 0x2b, 0x27, 0x28, 0x29, 0x24, 0x2a, 0x20, 0x27, 0x24, 0x23, 0x2a, 0x23, 0x37, 0x28, 0x47, 0x1f, 0x4c, 0x32, 0x24, 0x26, 0x42, 0x47, 0x26, 0x00, 0x00, 0xff,
    0x11, 
    0x25, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0x64, 0x01, 
    0x82, 
    0xd7, 
    0x36, 0x1e, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0x81, 
    0x21, 
    0x16, MP_QSTR__hyphen_h & 0xff, MP_QSTR__hyphen_h >> 8,
    0xd9, 
    0x36, 0x0f, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0x81, 
    0x21, 
    0x16, MP_QSTR__hyphen__hyphen_help & 0xff, MP_QSTR__hyphen__hyphen_help >> 8,
    0xd9, 
    0x37, 0x08, 0x80, 
    0x1c, MP_QSTR_help & 0xff, MP_QSTR_help >> 8,
    0x64, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0x81, 
    0x21, 
    0x16, MP_QSTR_install & 0xff, MP_QSTR_install >> 8,
    0xdc, 
    0x37, 0x08, 0x80, 
    0x1c, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8,
    0x17, 0x00, 
    0x64, 0x01, 
    0x32, 
    0x51, 0x00, 
    0xc0, 
    0x82, 
    0xc1, 
    0x35, 0xa9, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0xb1, 
    0x21, 
    0xc2, 
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0xb2, 
    0x16, MP_QSTR__hyphen_h & 0xff, MP_QSTR__hyphen_h >> 8,
    0xd9, 
    0x36, 0x08, 0x80, 
    0xb2, 
    0x16, MP_QSTR__hyphen__hyphen_help & 0xff, MP_QSTR__hyphen__hyphen_help >> 8,
    0xd9, 
    0x37, 0x08, 0x80, 
    0x1c, MP_QSTR_help & 0xff, MP_QSTR_help >> 8,
    0x64, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
    0xb2, 
    0x16, MP_QSTR__hyphen_p & 0xff, MP_QSTR__hyphen_p >> 8,
    0xd9, 
    0x37, 0x12, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0xb1, 
    0x21, 
    0x25, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0x35, 0x6a, 0x80, 
    0xb2, 
    0x16, MP_QSTR__hyphen_r & 0xff, MP_QSTR__hyphen_r >> 8,
    0xd9, 
    0x37, 0x49, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0xb1, 
    0x21, 
    0xc3, 
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0x1c, MP_QSTR_open & 0xff, MP_QSTR_open >> 8,
    0xb3, 
    0x64, 0x01, 
    0x3d, 0x2e, 0x00, 
    0xc4, 
    0xb4, 
    0x1e, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8,
    0x66, 0x00, 
    0xc5, 
    0xb5, 
    0x36, 0x03, 0x80, 
    0x35, 0x1d, 0x80, 
    0xb5, 
    0x80, 
    0x21, 
    0x16, MP_QSTR__hash_ & 0xff, MP_QSTR__hash_ >> 8,
    0xd9, 
    0x37, 0x03, 0x80, 
    0x35, 0x0d, 0x80, 
    0xb0, 
    0x1e, MP_QSTR_append & 0xff, MP_QSTR_append >> 8,
    0xb5, 
    0x1e, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8,
    0x66, 0x00, 
    0x66, 0x01, 
    0x32, 
    0x35, 0xd5, 0x7f, 
    0x44, 
    0x11, 
    0x3e, 
    0x41, 
    0x35, 0x19, 0x80, 
    0xb2, 
    0x16, MP_QSTR__hyphen__hyphen_debug & 0xff, MP_QSTR__hyphen__hyphen_debug >> 8,
    0xd9, 
    0x37, 0x07, 0x80, 
    0x12, 
    0x25, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x35, 0x0a, 0x80, 
    0x1c, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8,
    0x17, 0x01, 
    0xb2, 
    0xf1, 
    0x64, 0x01, 
    0x32, 
    0xb1, 
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0x64, 0x01, 
    0xd7, 
    0x37, 0x11, 0x80, 
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0xb1, 
    0x21, 
    0x80, 
    0x21, 
    0x16, MP_QSTR__hyphen_ & 0xff, MP_QSTR__hyphen_ >> 8,
    0xd9, 
    0x36, 0x36, 0x7f, 
    0xb0, 
    0x1e, MP_QSTR_extend & 0xff, MP_QSTR_extend >> 8,
    0x1c, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x1d, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8,
    0xb1, 
    0x11, 
    0x58, 0x02, 
    0x21, 
    0x66, 0x01, 
    0x32, 
    0xb0, 
    0x36, 0x08, 0x80, 
    0x1c, MP_QSTR_help & 0xff, MP_QSTR_help >> 8,
    0x64, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
    0x1c, MP_QSTR_install & 0xff, MP_QSTR_install >> 8,
    0xb0, 
    0x64, 0x01, 
    0x32, 
    0x1c, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x36, 0x06, 0x80, 
    0x1c, MP_QSTR_cleanup & 0xff, MP_QSTR_cleanup >> 8,
    0x64, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__main_0 = {{&mp_type_str}, 50937, 32, (const byte*)"\x4f\x6e\x6c\x79\x20\x27\x69\x6e\x73\x74\x61\x6c\x6c\x27\x20\x63\x6f\x6d\x6d\x61\x6e\x64\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__main_1 = {{&mp_type_str}, 40302, 28, (const byte*)"\x55\x6e\x6b\x6e\x6f\x77\x6e\x2f\x75\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x6f\x70\x74\x69\x6f\x6e\x3a\x20"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__main[2] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__main_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__main_1),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__main = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt__main,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__main,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 399,
        .n_obj = 2,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip.py, scope upip_<module>
STATIC const byte bytecode_data_upip__lt_module_gt_[296] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x29, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x69, 0x24, 0x24, 0x25, 0x44, 0x4b, 0x6e, 0x85, 0x0b, 0x65, 0x20, 0x8b, 0x14, 0x85, 0x09, 0x85, 0x1f, 0x65, 0x60, 0x28, 0x28, 0x24, 0x85, 0x2e, 0x85, 0x08, 0x69, 0x60, 0x85, 0x17, 0x89, 0x24, 0x85, 0x08, 0x85, 0x07, 0x85, 0x10, 0x85, 0x33, 0x2a, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x24, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x24, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x24, MP_QSTR_os & 0xff, MP_QSTR_os >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_uerrno & 0xff, MP_QSTR_uerrno >> 8,
    0x24, MP_QSTR_errno & 0xff, MP_QSTR_errno >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_ujson & 0xff, MP_QSTR_ujson >> 8,
    0x24, MP_QSTR_json & 0xff, MP_QSTR_json >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_uzlib & 0xff, MP_QSTR_uzlib >> 8,
    0x24, MP_QSTR_uzlib & 0xff, MP_QSTR_uzlib >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_upip_utarfile & 0xff, MP_QSTR_upip_utarfile >> 8,
    0x24, MP_QSTR_tarfile & 0xff, MP_QSTR_tarfile >> 8,
    0x1b, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x1e, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8,
    0x66, 0x00, 
    0x32, 
    0x10, 
    0x25, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8,
    0x11, 
    0x25, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8,
    0x51, 0x00, 
    0x24, MP_QSTR_cleanup_files & 0xff, MP_QSTR_cleanup_files >> 8,
    0x9f, 
    0x25, MP_QSTR_gzdict_sz & 0xff, MP_QSTR_gzdict_sz >> 8,
    0x1b, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x14, 0x84, 0x00, 
    0x64, 0x01, 
    0x25, MP_QSTR_file_buf & 0xff, MP_QSTR_file_buf >> 8,
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8,
    0x1b, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0x64, 0x03, 
    0x24, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_op_split & 0xff, MP_QSTR_op_split >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR_op_basename & 0xff, MP_QSTR_op_basename >> 8,
    0x14, 0x83, 0x7f, 
    0x50, 0x01, 
    0x18, 
    0x61, 0x03, 
    0x24, MP_QSTR__makedirs & 0xff, MP_QSTR__makedirs >> 8,
    0x60, 0x04, 
    0x24, MP_QSTR_save_file & 0xff, MP_QSTR_save_file >> 8,
    0x60, 0x05, 
    0x24, MP_QSTR_install_tar & 0xff, MP_QSTR_install_tar >> 8,
    0x60, 0x06, 
    0x24, MP_QSTR_expandhome & 0xff, MP_QSTR_expandhome >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8,
    0x24, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x24, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x12, 
    0x25, MP_QSTR_warn_ussl & 0xff, MP_QSTR_warn_ussl >> 8,
    0x60, 0x07, 
    0x24, MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8,
    0x60, 0x08, 
    0x24, MP_QSTR_get_pkg_metadata & 0xff, MP_QSTR_get_pkg_metadata >> 8,
    0x11, 
    0x50, 0x01, 
    0x18, 
    0x61, 0x09, 
    0x24, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8,
    0x60, 0x0a, 
    0x24, MP_QSTR_install_pkg & 0xff, MP_QSTR_install_pkg >> 8,
    0x11, 
    0x50, 0x01, 
    0x18, 
    0x61, 0x0b, 
    0x24, MP_QSTR_install & 0xff, MP_QSTR_install >> 8,
    0x60, 0x0c, 
    0x24, MP_QSTR_get_install_path & 0xff, MP_QSTR_get_install_path >> 8,
    0x60, 0x0d, 
    0x24, MP_QSTR_cleanup & 0xff, MP_QSTR_cleanup >> 8,
    0x60, 0x0e, 
    0x24, MP_QSTR_help & 0xff, MP_QSTR_help >> 8,
    0x60, 0x0f, 
    0x24, MP_QSTR_main & 0xff, MP_QSTR_main >> 8,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x16, MP_QSTR___main__ & 0xff, MP_QSTR___main__ >> 8,
    0xd9, 
    0x37, 0x06, 0x80, 
    0x1b, MP_QSTR_main & 0xff, MP_QSTR_main >> 8,
    0x64, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt_[16] = {
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__NotFoundError),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__op_split),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__op_basename),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt___makedirs),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__save_file),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__install_tar),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__expandhome),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__url_open),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__get_pkg_metadata),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__fatal),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__install_pkg),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__install),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__get_install_path),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__cleanup),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__help),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__main),
};
const mp_raw_code_t raw_code_upip__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 296,
        .n_obj = 0,
        .n_raw_code = 16,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__roundup
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__roundup[27] = {
    0x05, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09,
    MP_QSTR_roundup & 0xff, MP_QSTR_roundup >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x0c, 0x00, 0x00, 0xff,
    0xb0, 
    0xb1, 
    0xf1, 
    0x81, 
    0xf2, 
    0xb1, 
    0x81, 
    0xf2, 
    0xd2, 
    0xee, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__roundup[2] = {
    MP_ROM_QSTR(MP_QSTR_val),
    MP_ROM_QSTR(MP_QSTR_align),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__roundup = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__roundup,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__roundup,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 27,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection___init__
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__FileSection___init__[37] = {
    0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0b,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x11, 0x25, 0x25, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0xb2, 
    0xb0, 
    0x26, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xb3, 
    0xb2, 
    0xf2, 
    0xb0, 
    0x26, MP_QSTR_align & 0xff, MP_QSTR_align >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection___init__[4] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_f),
    MP_ROM_QSTR(MP_QSTR_content_len),
    MP_ROM_QSTR(MP_QSTR_aligned_len),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 4,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__FileSection___init__,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 37,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection_read
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__FileSection_read[80] = {
    0x06, 0x00, 0x00, 0x02, 0x00, 0x01, 0x10,
    MP_QSTR_read & 0xff, MP_QSTR_read >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x16, 0x29, 0x23, 0x29, 0x25, 0x2b, 0x27, 0x2b, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0x80, 
    0xd9, 
    0x37, 0x03, 0x80, 
    0x17, 0x02, 
    0x5b, 
    0xb1, 
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xd8, 
    0x37, 0x05, 0x80, 
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xc1, 
    0xb0, 
    0x1d, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0x1e, MP_QSTR_read & 0xff, MP_QSTR_read >> 8,
    0xb1, 
    0x66, 0x01, 
    0xc2, 
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0xb2, 
    0x64, 0x01, 
    0xc1, 
    0xb0, 
    0x30, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xb1, 
    0xe6, 
    0x33, 
    0x26, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xb2, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip_utarfile__lt_module_gt__FileSection_read_0 = {{&mp_type_bytes}, 5381, 0, (const byte*)""};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection_read[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_sz),
    MP_ROM_PTR(&const_obj_upip_utarfile__lt_module_gt__FileSection_read_0),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection_read = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__FileSection_read,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection_read,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 80,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection_readinto
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__FileSection_readinto[86] = {
    0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0f,
    MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x20, 0x29, 0x22, 0x2e, 0x2f, 0x2b, 0x2b, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0x80, 
    0xd9, 
    0x37, 0x02, 0x80, 
    0x80, 
    0x5b, 
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0xb1, 
    0x64, 0x01, 
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xd8, 
    0x37, 0x0f, 0x80, 
    0x1c, MP_QSTR_memoryview & 0xff, MP_QSTR_memoryview >> 8,
    0xb1, 
    0x64, 0x01, 
    0x11, 
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0x58, 0x02, 
    0x21, 
    0xc1, 
    0xb0, 
    0x1d, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0x1e, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    0xb1, 
    0x66, 0x01, 
    0xc2, 
    0xb0, 
    0x30, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xb2, 
    0xe6, 
    0x33, 
    0x26, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xb2, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection_readinto[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection_readinto = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__FileSection_readinto,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection_readinto,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 86,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection_skip
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__FileSection_skip[76] = {
    0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0f,
    MP_QSTR_skip & 0xff, MP_QSTR_skip >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x29, 0x2a, 0x24, 0x27, 0x23, 0x28, 0x2c, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8,
    0xb0, 
    0x1d, MP_QSTR_align & 0xff, MP_QSTR_align >> 8,
    0xf1, 
    0xc1, 
    0xb1, 
    0x37, 0x26, 0x80, 
    0x1c, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8,
    0x90, 
    0x64, 0x01, 
    0xc2, 
    0x35, 0x18, 0x80, 
    0x1c, MP_QSTR_min & 0xff, MP_QSTR_min >> 8,
    0xb1, 
    0x90, 
    0x64, 0x02, 
    0xc3, 
    0xb0, 
    0x1d, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0x1e, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    0xb2, 
    0xb3, 
    0x66, 0x02, 
    0x32, 
    0xb1, 
    0xb3, 
    0xe6, 
    0xc1, 
    0xb1, 
    0x36, 0xe4, 0x7f, 
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection_skip[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection_skip = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__FileSection_skip,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection_skip,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 76,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__FileSection[63] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
    MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x8d, 0x10, 0x65, 0x40, 0x8c, 0x0a, 0x85, 0x09, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x14, 0x84, 0x80, 0x00, 
    0x50, 0x01, 
    0x18, 
    0x61, 0x01, 
    0x24, MP_QSTR_read & 0xff, MP_QSTR_read >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    0x60, 0x03, 
    0x24, MP_QSTR_skip & 0xff, MP_QSTR_skip >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection[4] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection___init__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection_read),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection_readinto),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection_skip),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__FileSection,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 63,
        .n_obj = 0,
        .n_raw_code = 4,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarInfo___str__
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarInfo___str__[34] = {
    0x05, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR___str__ & 0xff, MP_QSTR___str__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x34, 0x00, 0x00, 0xff,
    0x17, 0x01, 
    0xb0, 
    0x1d, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0xb0, 
    0x1d, MP_QSTR_type & 0xff, MP_QSTR_type >> 8,
    0xb0, 
    0x1d, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x50, 0x03, 
    0xf6, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_upip_utarfile__lt_module_gt__TarInfo___str___0 = {{&mp_type_str}, 62189, 19, (const byte*)"\x54\x61\x72\x49\x6e\x66\x6f\x28\x25\x72\x2c\x20\x25\x73\x2c\x20\x25\x64\x29"};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarInfo___str__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_PTR(&const_obj_upip_utarfile__lt_module_gt__TarInfo___str___0),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarInfo___str__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarInfo___str__,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarInfo___str__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 34,
        .n_obj = 1,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarInfo
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarInfo[35] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x8d, 0x33, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___str__ & 0xff, MP_QSTR___str__ >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarInfo[1] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarInfo___str__),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarInfo = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarInfo,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarInfo,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 35,
        .n_obj = 0,
        .n_raw_code = 1,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile___init__
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarFile___init__[51] = {
    0x06, 0x00, 0x00, 0x03, 0x00, 0x02, 0x0c,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x39, 0x24, 0x48, 0x2d, 0x00, 0x00, 0xff,
    0xb2, 
    0x37, 0x08, 0x80, 
    0xb2, 
    0xb0, 
    0x26, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0x35, 0x0d, 0x80, 
    0x1c, MP_QSTR_open & 0xff, MP_QSTR_open >> 8,
    0xb1, 
    0x16, MP_QSTR_rb & 0xff, MP_QSTR_rb >> 8,
    0x64, 0x02, 
    0xb0, 
    0x26, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0x11, 
    0xb0, 
    0x26, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile___init__[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_name),
    MP_ROM_QSTR(MP_QSTR_fileobj),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarFile___init__,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 51,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile_next
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarFile_next[216] = {
    0x0a, 0x00, 0x00, 0x01, 0x00, 0x00, 0x17,
    MP_QSTR_next & 0xff, MP_QSTR_next >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x40, 0x27, 0x2a, 0x2d, 0x24, 0x42, 0x7b, 0x2b, 0x42, 0x26, 0x35, 0x38, 0x37, 0x1f, 0x23, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8,
    0x37, 0x0a, 0x80, 
    0xb0, 
    0x1d, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8,
    0x1e, MP_QSTR_skip & 0xff, MP_QSTR_skip >> 8,
    0x66, 0x00, 
    0x32, 
    0xb0, 
    0x1d, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0x1e, MP_QSTR_read & 0xff, MP_QSTR_read >> 8,
    0x14, 0x84, 0x00, 
    0x66, 0x01, 
    0xc1, 
    0xb1, 
    0x36, 0x02, 0x80, 
    0x11, 
    0x5b, 
    0x1c, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1e, MP_QSTR_struct & 0xff, MP_QSTR_struct >> 8,
    0x1c, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1e, MP_QSTR_addressof & 0xff, MP_QSTR_addressof >> 8,
    0xb1, 
    0x66, 0x01, 
    0x1c, MP_QSTR_TAR_HEADER & 0xff, MP_QSTR_TAR_HEADER >> 8,
    0x1c, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1d, MP_QSTR_LITTLE_ENDIAN & 0xff, MP_QSTR_LITTLE_ENDIAN >> 8,
    0x66, 0x03, 
    0xc2, 
    0xb2, 
    0x1d, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0x80, 
    0x21, 
    0x80, 
    0xd9, 
    0x37, 0x02, 0x80, 
    0x11, 
    0x5b, 
    0x1c, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8,
    0x64, 0x00, 
    0xc3, 
    0x1c, MP_QSTR_str & 0xff, MP_QSTR_str >> 8,
    0xb2, 
    0x1d, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0x16, MP_QSTR_utf_hyphen_8 & 0xff, MP_QSTR_utf_hyphen_8 >> 8,
    0x64, 0x02, 
    0x1e, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8,
    0x66, 0x00, 
    0xb3, 
    0x26, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0x1c, MP_QSTR_int & 0xff, MP_QSTR_int >> 8,
    0x1c, MP_QSTR_bytes & 0xff, MP_QSTR_bytes >> 8,
    0xb2, 
    0x1d, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x64, 0x01, 
    0x1e, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8,
    0x66, 0x00, 
    0x88, 
    0x64, 0x02, 
    0xb3, 
    0x26, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x1c, MP_QSTR_REGTYPE & 0xff, MP_QSTR_REGTYPE >> 8,
    0x1c, MP_QSTR_DIRTYPE & 0xff, MP_QSTR_DIRTYPE >> 8,
    0x51, 0x02, 
    0xb3, 
    0x1d, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0x7f, 
    0x21, 
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0xd9, 
    0x21, 
    0xb3, 
    0x26, MP_QSTR_type & 0xff, MP_QSTR_type >> 8,
    0x1c, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8,
    0xb0, 
    0x1d, MP_QSTR_f & 0xff, MP_QSTR_f >> 8,
    0xb3, 
    0x1d, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x1c, MP_QSTR_roundup & 0xff, MP_QSTR_roundup >> 8,
    0xb3, 
    0x1d, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x14, 0x84, 0x00, 
    0x64, 0x02, 
    0x64, 0x03, 
    0x30, 
    0xb0, 
    0x26, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8,
    0xb3, 
    0x26, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8,
    0xb3, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile_next[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile_next = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarFile_next,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile_next,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 216,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile___iter__
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarFile___iter__[18] = {
    0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR___iter__ & 0xff, MP_QSTR___iter__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x54, 0x00, 0x00, 0xff,
    0xb0, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile___iter__[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile___iter__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarFile___iter__,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile___iter__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 18,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile___next__
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarFile___next__[39] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR___next__ & 0xff, MP_QSTR___next__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x57, 0x27, 0x26, 0x25, 0x00, 0x00, 0xff,
    0xb0, 
    0x1e, MP_QSTR_next & 0xff, MP_QSTR_next >> 8,
    0x66, 0x00, 
    0xc1, 
    0xb1, 
    0x11, 
    0xde, 
    0x37, 0x05, 0x80, 
    0x1c, MP_QSTR_StopIteration & 0xff, MP_QSTR_StopIteration >> 8,
    0x5c, 0x01, 
    0xb1, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile___next__[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile___next__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarFile___next__,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile___next__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 39,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile_extractfile
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarFile_extractfile[21] = {
    0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09,
    MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x81, 0x5d, 0x00, 0x00, 0xff,
    0xb1, 
    0x1d, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8,
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile_extractfile[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_tarinfo),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile_extractfile = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarFile_extractfile,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile_extractfile,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 21,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt__TarFile[67] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
    MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x8d, 0x38, 0x8a, 0x07, 0x85, 0x14, 0x65, 0x65, 0x60, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x11, 
    0x11, 
    0x50, 0x02, 
    0x18, 
    0x61, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_next & 0xff, MP_QSTR_next >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR___iter__ & 0xff, MP_QSTR___iter__ >> 8,
    0x60, 0x03, 
    0x24, MP_QSTR___next__ & 0xff, MP_QSTR___next__ >> 8,
    0x60, 0x04, 
    0x24, MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile[5] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile___init__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile_next),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile___iter__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile___next__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile_extractfile),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt__TarFile,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 67,
        .n_obj = 0,
        .n_raw_code = 5,
        #endif
    },
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile_<module>
STATIC const byte bytecode_data_upip_utarfile__lt_module_gt_[138] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x69, 0x22, 0x38, 0x7b, 0x26, 0x46, 0x65, 0x8b, 0x23, 0x6b, 0x40, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x24, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x53, 0x02, 
    0x1b, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1d, MP_QSTR_ARRAY & 0xff, MP_QSTR_ARRAY >> 8,
    0x80, 
    0xec, 
    0x1b, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1d, MP_QSTR_UINT8 & 0xff, MP_QSTR_UINT8 >> 8,
    0x14, 0x80, 0x64, 
    0xec, 
    0x50, 0x02, 
    0x16, MP_QSTR_name & 0xff, MP_QSTR_name >> 8,
    0x54, 
    0x1b, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1d, MP_QSTR_ARRAY & 0xff, MP_QSTR_ARRAY >> 8,
    0x14, 0x80, 0x7c, 
    0xec, 
    0x1b, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8,
    0x1d, MP_QSTR_UINT8 & 0xff, MP_QSTR_UINT8 >> 8,
    0x8c, 
    0xec, 
    0x50, 0x02, 
    0x16, MP_QSTR_size & 0xff, MP_QSTR_size >> 8,
    0x54, 
    0x24, MP_QSTR_TAR_HEADER & 0xff, MP_QSTR_TAR_HEADER >> 8,
    0x16, MP_QSTR_dir & 0xff, MP_QSTR_dir >> 8,
    0x24, MP_QSTR_DIRTYPE & 0xff, MP_QSTR_DIRTYPE >> 8,
    0x16, MP_QSTR_file & 0xff, MP_QSTR_file >> 8,
    0x24, MP_QSTR_REGTYPE & 0xff, MP_QSTR_REGTYPE >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR_roundup & 0xff, MP_QSTR_roundup >> 8,
    0x20, 
    0x60, 0x01, 
    0x16, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8,
    0x20, 
    0x60, 0x02, 
    0x16, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8,
    0x20, 
    0x60, 0x03, 
    0x16, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt_[4] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__roundup),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarInfo),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile),
};
const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_upip_utarfile__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 138,
        .n_obj = 0,
        .n_raw_code = 4,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__Response___init__
STATIC const byte bytecode_data_urequests__lt_module_gt__Response___init__[37] = {
    0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0b,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x61, 0x40, 0x25, 0x27, 0x00, 0x00, 0xff,
    0xb1, 
    0xb0, 
    0x26, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0x16, MP_QSTR_utf_hyphen_8 & 0xff, MP_QSTR_utf_hyphen_8 >> 8,
    0xb0, 
    0x26, MP_QSTR_encoding & 0xff, MP_QSTR_encoding >> 8,
    0x11, 
    0xb0, 
    0x26, MP_QSTR__cached & 0xff, MP_QSTR__cached >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__Response___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_f),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__Response___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__Response___init__,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__Response___init__,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 37,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__Response_close
STATIC const byte bytecode_data_urequests__lt_module_gt__Response_close[48] = {
    0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0c,
    MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x0a, 0x27, 0x2a, 0x25, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0x37, 0x0f, 0x80, 
    0xb0, 
    0x1d, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0x1e, MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    0x66, 0x00, 
    0x32, 
    0x11, 
    0xb0, 
    0x26, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0x11, 
    0xb0, 
    0x26, MP_QSTR__cached & 0xff, MP_QSTR__cached >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__Response_close[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__Response_close = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__Response_close,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__Response_close,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 48,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__Response_content
STATIC const byte bytecode_data_urequests__lt_module_gt__Response_content[65] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0d,
    MP_QSTR_content & 0xff, MP_QSTR_content >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x11, 0x29, 0x30, 0x2a, 0x25, 0x00, 0x00, 0xff,
    0xb0, 
    0x1d, MP_QSTR__cached & 0xff, MP_QSTR__cached >> 8,
    0x11, 
    0xde, 
    0x37, 0x1f, 0x80, 
    0xb0, 
    0x1d, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0x1e, MP_QSTR_recv & 0xff, MP_QSTR_recv >> 8,
    0x14, 0x88, 0x00, 
    0x66, 0x01, 
    0xb0, 
    0x26, MP_QSTR__cached & 0xff, MP_QSTR__cached >> 8,
    0xb0, 
    0x1d, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0x1e, MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    0x66, 0x00, 
    0x32, 
    0x11, 
    0xb0, 
    0x26, MP_QSTR_raw & 0xff, MP_QSTR_raw >> 8,
    0xb0, 
    0x1d, MP_QSTR__cached & 0xff, MP_QSTR__cached >> 8,
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__Response_content[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__Response_content = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__Response_content,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__Response_content,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 65,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__Response_text
STATIC const byte bytecode_data_urequests__lt_module_gt__Response_text[30] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_text & 0xff, MP_QSTR_text >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x19, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_str & 0xff, MP_QSTR_str >> 8,
    0xb0, 
    0x1d, MP_QSTR_content & 0xff, MP_QSTR_content >> 8,
    0xb0, 
    0x1d, MP_QSTR_encoding & 0xff, MP_QSTR_encoding >> 8,
    0x64, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__Response_text[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__Response_text = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__Response_text,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__Response_text,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 30,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__Response_json
STATIC const byte bytecode_data_urequests__lt_module_gt__Response_json[34] = {
    0x05, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0a,
    MP_QSTR_json & 0xff, MP_QSTR_json >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x1c, 0x26, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_ujson & 0xff, MP_QSTR_ujson >> 8,
    0xc1, 
    0xb1, 
    0x1e, MP_QSTR_loads & 0xff, MP_QSTR_loads >> 8,
    0xb0, 
    0x1d, MP_QSTR_content & 0xff, MP_QSTR_content >> 8,
    0x66, 0x01, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__Response_json[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__Response_json = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__Response_json,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__Response_json,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 34,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__Response
STATIC const byte bytecode_data_urequests__lt_module_gt__Response[73] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
    MP_QSTR_Response & 0xff, MP_QSTR_Response >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x6d, 0x20, 0x65, 0x40, 0x65, 0x60, 0x8a, 0x08, 0x6a, 0x20, 0x00, 0x00, 0xff,
    0x1b, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8,
    0x24, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8,
    0x16, MP_QSTR_Response & 0xff, MP_QSTR_Response >> 8,
    0x24, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8,
    0x60, 0x00, 
    0x24, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    0x60, 0x01, 
    0x24, MP_QSTR_close & 0xff, MP_QSTR_close >> 8,
    0x1b, MP_QSTR_property & 0xff, MP_QSTR_property >> 8,
    0x60, 0x02, 
    0x64, 0x01, 
    0x24, MP_QSTR_content & 0xff, MP_QSTR_content >> 8,
    0x1b, MP_QSTR_property & 0xff, MP_QSTR_property >> 8,
    0x60, 0x03, 
    0x64, 0x01, 
    0x24, MP_QSTR_text & 0xff, MP_QSTR_text >> 8,
    0x60, 0x04, 
    0x24, MP_QSTR_json & 0xff, MP_QSTR_json >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__Response[5] = {
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__Response___init__),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__Response_close),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__Response_content),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__Response_text),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__Response_json),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__Response = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__Response,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__Response,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 73,
        .n_obj = 0,
        .n_raw_code = 5,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__request
STATIC const byte bytecode_data_urequests__lt_module_gt__request[666] = {
    0x1f, 0x02, 0x00, 0x06, 0x00, 0x04, 0x43,
    MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x21, 0x23, 0x2a, 0x23, 0x5d, 0x2f, 0x29, 0x28, 0x27, 0x28, 0x26, 0x47, 0x4b, 0x28, 0x2e, 0x47, 0x2b, 0x26, 0x29, 0x28, 0x28, 0x28, 0x2e, 0x28, 0x4b, 0x26, 0x28, 0x29, 0x2a, 0x2c, 0x27, 0x2b, 0x27, 0x29, 0x24, 0x30, 0x29, 0x24, 0x48, 0x28, 0x31, 0x49, 0x20, 0x28, 0x2d, 0x43, 0x2c, 0x28, 0x2f, 0x1f, 0x24, 0x4f, 0x28, 0x27, 0x2c, 0x29, 0x54, 0x31, 0x29, 0x00, 0x00, 0xff,
    0x3f, 0x13, 0x02, 
    0x1c, MP_QSTR_request_sema & 0xff, MP_QSTR_request_sema >> 8,
    0x1e, MP_QSTR_acquire & 0xff, MP_QSTR_acquire >> 8,
    0x81, 
    0x66, 0x01, 
    0x32, 
    0x3f, 0x14, 0x00, 
    0xb1, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x83, 
    0x66, 0x02, 
    0x59, 0x04, 
    0xc6, 
    0xc7, 
    0xc8, 
    0xc9, 
    0x44, 
    0x35, 0x21, 0x80, 
    0x30, 
    0x1c, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8,
    0xdf, 
    0x37, 0x18, 0x80, 
    0x32, 
    0xb1, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x82, 
    0x66, 0x02, 
    0x59, 0x03, 
    0xc6, 
    0xc7, 
    0xc8, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0xc9, 
    0x45, 
    0x35, 0x01, 0x80, 
    0x41, 
    0xb6, 
    0x16, MP_QSTR_http_colon_ & 0xff, MP_QSTR_http_colon_ >> 8,
    0xd9, 
    0x37, 0x07, 0x80, 
    0x14, 0x80, 0x50, 
    0xca, 
    0x35, 0x20, 0x80, 
    0xb6, 
    0x16, MP_QSTR_https_colon_ & 0xff, MP_QSTR_https_colon_ >> 8,
    0xd9, 
    0x37, 0x0d, 0x80, 
    0x80, 
    0x11, 
    0x68, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8,
    0xcb, 
    0x14, 0x83, 0x3b, 
    0xca, 
    0x35, 0x0b, 0x80, 
    0x1c, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8,
    0x17, 0x06, 
    0xb6, 
    0xf1, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0x16, MP_QSTR__colon_ & 0xff, MP_QSTR__colon_ >> 8,
    0xb8, 
    0xdd, 
    0x37, 0x15, 0x80, 
    0xb8, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x16, MP_QSTR__colon_ & 0xff, MP_QSTR__colon_ >> 8,
    0x81, 
    0x66, 0x02, 
    0x59, 0x02, 
    0xc8, 
    0xca, 
    0x1c, MP_QSTR_int & 0xff, MP_QSTR_int >> 8,
    0xba, 
    0x64, 0x01, 
    0xca, 
    0x1c, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x1e, MP_QSTR_getaddrinfo & 0xff, MP_QSTR_getaddrinfo >> 8,
    0xb8, 
    0xba, 
    0x66, 0x02, 
    0xcc, 
    0xbc, 
    0x80, 
    0x21, 
    0x84, 
    0x21, 
    0xcd, 
    0x1c, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x1e, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8,
    0x66, 0x00, 
    0xce, 
    0xbe, 
    0x1e, MP_QSTR_connect & 0xff, MP_QSTR_connect >> 8,
    0xbd, 
    0x66, 0x01, 
    0x32, 
    0xb6, 
    0x16, MP_QSTR_https_colon_ & 0xff, MP_QSTR_https_colon_ >> 8,
    0xd9, 
    0x37, 0x08, 0x80, 
    0xbb, 
    0x1e, MP_QSTR_wrap_socket & 0xff, MP_QSTR_wrap_socket >> 8,
    0xbe, 
    0x66, 0x01, 
    0xce, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x07, 
    0xb0, 
    0xb9, 
    0x50, 0x02, 
    0xf6, 
    0x66, 0x01, 
    0x32, 
    0x16, MP_QSTR_Host & 0xff, MP_QSTR_Host >> 8,
    0xb4, 
    0xdd, 
    0x36, 0x0b, 0x80, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x08, 
    0xb8, 
    0xf6, 
    0x66, 0x01, 
    0x32, 
    0xb4, 
    0x47, 
    0x43, 0x28, 0x00, 
    0xcf, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0xbf, 
    0x66, 0x01, 
    0x32, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x09, 
    0x66, 0x01, 
    0x32, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0xb4, 
    0xbf, 
    0x21, 
    0x66, 0x01, 
    0x32, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x0a, 
    0x66, 0x01, 
    0x32, 
    0x35, 0xd5, 0x7f, 
    0xb3, 
    0x11, 
    0xde, 
    0xd3, 
    0x37, 0x1b, 0x80, 
    0xb2, 
    0x11, 
    0xde, 
    0x36, 0x05, 0x80, 
    0x1c, MP_QSTR_AssertionError & 0xff, MP_QSTR_AssertionError >> 8,
    0x5c, 0x01, 
    0x80, 
    0x11, 
    0x68, MP_QSTR_ujson & 0xff, MP_QSTR_ujson >> 8,
    0x22, 0x10, 
    0x19, 0x10, 
    0x1e, MP_QSTR_dumps & 0xff, MP_QSTR_dumps >> 8,
    0xb3, 
    0x66, 0x01, 
    0xc2, 
    0xb2, 
    0x37, 0x10, 0x80, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x0b, 
    0x1c, MP_QSTR_len & 0xff, MP_QSTR_len >> 8,
    0xb2, 
    0x64, 0x01, 
    0xf6, 
    0x66, 0x01, 
    0x32, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0x17, 0x0c, 
    0x66, 0x01, 
    0x32, 
    0xb2, 
    0x37, 0x08, 0x80, 
    0xbe, 
    0x1e, MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    0xb2, 
    0x66, 0x01, 
    0x32, 
    0xbe, 
    0x1e, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8,
    0x66, 0x00, 
    0x22, 0x11, 
    0x19, 0x11, 
    0x1e, MP_QSTR_split & 0xff, MP_QSTR_split >> 8,
    0x11, 
    0x82, 
    0x66, 0x02, 
    0x59, 0x03, 
    0x22, 0x12, 
    0x22, 0x13, 
    0x22, 0x14, 
    0x1c, MP_QSTR_int & 0xff, MP_QSTR_int >> 8,
    0x19, 0x13, 
    0x64, 0x01, 
    0x22, 0x13, 
    0xbe, 
    0x1e, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8,
    0x66, 0x00, 
    0x22, 0x11, 
    0x19, 0x11, 
    0x37, 0x08, 0x80, 
    0x19, 0x11, 
    0x17, 0x0d, 
    0xd9, 
    0x37, 0x03, 0x80, 
    0x35, 0x55, 0x80, 
    0x19, 0x11, 
    0x1e, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8,
    0x17, 0x0e, 
    0x66, 0x01, 
    0x37, 0x17, 0x80, 
    0x17, 0x0f, 
    0x19, 0x11, 
    0xdd, 
    0x37, 0x0c, 0x80, 
    0x1c, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8,
    0x17, 0x10, 
    0x19, 0x11, 
    0xf1, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0x35, 0x2f, 0x80, 
    0x19, 0x11, 
    0x1e, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8,
    0x17, 0x11, 
    0x66, 0x01, 
    0x37, 0x23, 0x80, 
    0x14, 0x81, 0x48, 
    0x19, 0x13, 
    0x30, 
    0x34, 
    0xda, 
    0x39, 0x07, 0x80, 
    0x14, 0x82, 0x2b, 
    0xda, 
    0x35, 0x02, 0x80, 
    0x33, 
    0x32, 
    0x36, 0x0c, 0x80, 
    0x1c, MP_QSTR_NotImplementedError & 0xff, MP_QSTR_NotImplementedError >> 8,
    0x17, 0x12, 
    0x64, 0x01, 
    0x5c, 0x01, 
    0x35, 0x00, 0x80, 
    0x35, 0x93, 0x7f, 
    0x1c, MP_QSTR_Response & 0xff, MP_QSTR_Response >> 8,
    0xbe, 
    0x64, 0x01, 
    0x22, 0x15, 
    0x19, 0x13, 
    0x19, 0x15, 
    0x26, MP_QSTR_status_code & 0xff, MP_QSTR_status_code >> 8,
    0x19, 0x14, 
    0x1e, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8,
    0x66, 0x00, 
    0x19, 0x15, 
    0x26, MP_QSTR_reason & 0xff, MP_QSTR_reason >> 8,
    0x1c, MP_QSTR_request_sema & 0xff, MP_QSTR_request_sema >> 8,
    0x1e, MP_QSTR_release & 0xff, MP_QSTR_release >> 8,
    0x66, 0x00, 
    0x32, 
    0x19, 0x15, 
    0x5b, 
    0x44, 
    0x35, 0x38, 0x80, 
    0x30, 
    0x1c, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8,
    0xdf, 
    0x37, 0x2f, 0x80, 
    0x22, 0x16, 
    0x40, 0x21, 0x00, 
    0x1c, MP_QSTR_print & 0xff, MP_QSTR_print >> 8,
    0x16, MP_QSTR_uquest_colon__space_ & 0xff, MP_QSTR_uquest_colon__space_ >> 8,
    0x1c, MP_QSTR_str & 0xff, MP_QSTR_str >> 8,
    0x19, 0x16, 
    0x64, 0x01, 
    0xf1, 
    0x64, 0x01, 
    0x32, 
    0x1c, MP_QSTR_request_sema & 0xff, MP_QSTR_request_sema >> 8,
    0x1e, MP_QSTR_release & 0xff, MP_QSTR_release >> 8,
    0x66, 0x00, 
    0x32, 
    0x16, MP_QSTR_ & 0xff, MP_QSTR_ >> 8,
    0x5b, 
    0x44, 
    0x45, 
    0x11, 
    0x11, 
    0x22, 0x16, 
    0x28, 0x16, 
    0x41, 
    0x35, 0x01, 0x80, 
    0x41, 
    0x11, 
    0x5b, 
};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_0 = {{&mp_type_str}, 38204, 22, (const byte*)"\x55\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x70\x72\x6f\x74\x6f\x63\x6f\x6c\x3a\x20"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_1 = {{&mp_type_bytes}, 47477, 17, (const byte*)"\x25\x73\x20\x2f\x25\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_2 = {{&mp_type_bytes}, 35534, 10, (const byte*)"\x48\x6f\x73\x74\x3a\x20\x25\x73\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_3 = {{&mp_type_bytes}, 26975, 2, (const byte*)"\x3a\x20"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_4 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_5 = {{&mp_type_bytes}, 8065, 20, (const byte*)"\x43\x6f\x6e\x74\x65\x6e\x74\x2d\x4c\x65\x6e\x67\x74\x68\x3a\x20\x25\x64\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_6 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_7 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_8 = {{&mp_type_bytes}, 59642, 18, (const byte*)"\x54\x72\x61\x6e\x73\x66\x65\x72\x2d\x45\x6e\x63\x6f\x64\x69\x6e\x67\x3a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_9 = {{&mp_type_bytes}, 3583, 7, (const byte*)"\x63\x68\x75\x6e\x6b\x65\x64"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_10 = {{&mp_type_str}, 18832, 12, (const byte*)"\x55\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_11 = {{&mp_type_bytes}, 1090, 9, (const byte*)"\x4c\x6f\x63\x61\x74\x69\x6f\x6e\x3a"};
STATIC const mp_obj_str_t const_obj_urequests__lt_module_gt__request_12 = {{&mp_type_str}, 223, 27, (const byte*)"\x52\x65\x64\x69\x72\x65\x63\x74\x73\x20\x6e\x6f\x74\x20\x79\x65\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64"};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__request[19] = {
    MP_ROM_QSTR(MP_QSTR_method),
    MP_ROM_QSTR(MP_QSTR_url),
    MP_ROM_QSTR(MP_QSTR_data),
    MP_ROM_QSTR(MP_QSTR_json),
    MP_ROM_QSTR(MP_QSTR_headers),
    MP_ROM_QSTR(MP_QSTR_stream),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_0),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_1),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_2),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_3),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_4),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_5),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_6),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_7),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_8),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_9),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_10),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_11),
    MP_ROM_PTR(&const_obj_urequests__lt_module_gt__request_12),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__request = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 6,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__request,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__request,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 666,
        .n_obj = 13,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__head
STATIC const byte bytecode_data_urequests__lt_module_gt__head[28] = {
    0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_head & 0xff, MP_QSTR_head >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x68, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x16, MP_QSTR_HEAD & 0xff, MP_QSTR_HEAD >> 8,
    0xb0, 
    0x18, 
    0xb1, 
    0x65, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__head[1] = {
    MP_ROM_QSTR(MP_QSTR_url),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__head = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x02,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__head,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__head,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 28,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__get
STATIC const byte bytecode_data_urequests__lt_module_gt__get[28] = {
    0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_get & 0xff, MP_QSTR_get >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x6b, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x16, MP_QSTR_GET & 0xff, MP_QSTR_GET >> 8,
    0xb0, 
    0x18, 
    0xb1, 
    0x65, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__get[1] = {
    MP_ROM_QSTR(MP_QSTR_url),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__get = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x02,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__get,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__get,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 28,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__post
STATIC const byte bytecode_data_urequests__lt_module_gt__post[28] = {
    0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_post & 0xff, MP_QSTR_post >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x6e, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x16, MP_QSTR_POST & 0xff, MP_QSTR_POST >> 8,
    0xb0, 
    0x18, 
    0xb1, 
    0x65, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__post[1] = {
    MP_ROM_QSTR(MP_QSTR_url),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__post = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x02,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__post,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__post,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 28,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__put
STATIC const byte bytecode_data_urequests__lt_module_gt__put[28] = {
    0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_put & 0xff, MP_QSTR_put >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x71, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x16, MP_QSTR_PUT & 0xff, MP_QSTR_PUT >> 8,
    0xb0, 
    0x18, 
    0xb1, 
    0x65, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__put[1] = {
    MP_ROM_QSTR(MP_QSTR_url),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__put = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x02,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__put,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__put,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 28,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__patch
STATIC const byte bytecode_data_urequests__lt_module_gt__patch[28] = {
    0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_patch & 0xff, MP_QSTR_patch >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x74, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x16, MP_QSTR_PATCH & 0xff, MP_QSTR_PATCH >> 8,
    0xb0, 
    0x18, 
    0xb1, 
    0x65, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__patch[1] = {
    MP_ROM_QSTR(MP_QSTR_url),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__patch = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x02,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__patch,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__patch,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 28,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests__lt_module_gt__delete
STATIC const byte bytecode_data_urequests__lt_module_gt__delete[28] = {
    0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x09,
    MP_QSTR_delete & 0xff, MP_QSTR_delete >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x81, 0x77, 0x00, 0x00, 0xff,
    0x1c, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x16, MP_QSTR_DELETE & 0xff, MP_QSTR_DELETE >> 8,
    0xb0, 
    0x18, 
    0xb1, 
    0x65, 0x02, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt__delete[1] = {
    MP_ROM_QSTR(MP_QSTR_url),
};
STATIC const mp_raw_code_t raw_code_urequests__lt_module_gt__delete = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x02,
    .n_pos_args = 1,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt__delete,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt__delete,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 28,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

// frozen bytecode for file urequests.py, scope urequests_<module>
STATIC const byte bytecode_data_urequests__lt_module_gt_[109] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_urequests_dot_py & 0xff, MP_QSTR_urequests_dot_py >> 8,
    0x29, 0x28, 0x8b, 0x1d, 0x2b, 0x8d, 0x47, 0x65, 0x65, 0x65, 0x65, 0x65, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x24, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR__thread & 0xff, MP_QSTR__thread >> 8,
    0x24, MP_QSTR__thread & 0xff, MP_QSTR__thread >> 8,
    0x20, 
    0x60, 0x00, 
    0x16, MP_QSTR_Response & 0xff, MP_QSTR_Response >> 8,
    0x64, 0x02, 
    0x24, MP_QSTR_Response & 0xff, MP_QSTR_Response >> 8,
    0x1b, MP_QSTR__thread & 0xff, MP_QSTR__thread >> 8,
    0x1e, MP_QSTR_allocate_lock & 0xff, MP_QSTR_allocate_lock >> 8,
    0x66, 0x00, 
    0x24, MP_QSTR_request_sema & 0xff, MP_QSTR_request_sema >> 8,
    0x11, 
    0x11, 
    0x53, 0x00, 
    0x11, 
    0x50, 0x04, 
    0x18, 
    0x61, 0x01, 
    0x24, MP_QSTR_request & 0xff, MP_QSTR_request >> 8,
    0x60, 0x02, 
    0x24, MP_QSTR_head & 0xff, MP_QSTR_head >> 8,
    0x60, 0x03, 
    0x24, MP_QSTR_get & 0xff, MP_QSTR_get >> 8,
    0x60, 0x04, 
    0x24, MP_QSTR_post & 0xff, MP_QSTR_post >> 8,
    0x60, 0x05, 
    0x24, MP_QSTR_put & 0xff, MP_QSTR_put >> 8,
    0x60, 0x06, 
    0x24, MP_QSTR_patch & 0xff, MP_QSTR_patch >> 8,
    0x60, 0x07, 
    0x24, MP_QSTR_delete & 0xff, MP_QSTR_delete >> 8,
    0x11, 
    0x5b, 
};
STATIC const mp_rom_obj_t const_table_data_urequests__lt_module_gt_[8] = {
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__Response),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__request),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__head),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__get),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__post),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__put),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__patch),
    MP_ROM_PTR(&raw_code_urequests__lt_module_gt__delete),
};
const mp_raw_code_t raw_code_urequests__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data_urequests__lt_module_gt_,
        .const_table = (mp_uint_t*)const_table_data_urequests__lt_module_gt_,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 109,
        .n_obj = 0,
        .n_raw_code = 8,
        #endif
    },
};

// frozen bytecode for file _boot.py, scope _boot_<module>
STATIC const byte bytecode_data__boot__lt_module_gt_[126] = {
    0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0f,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR__boot_dot_py & 0xff, MP_QSTR__boot_dot_py >> 8,
    0x29, 0x28, 0x50, 0x23, 0x26, 0x5c, 0x28, 0x50, 0x00, 0x00, 0xff,
    0x80, 
    0x11, 
    0x68, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x24, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x80, 
    0x11, 
    0x68, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x24, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x80, 
    0x16, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x50, 0x01, 
    0x68, MP_QSTR_flashbdev & 0xff, MP_QSTR_flashbdev >> 8,
    0x69, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x24, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x32, 
    0x3f, 0x19, 0x00, 
    0x1b, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x37, 0x0f, 0x80, 
    0x1b, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8,
    0x1e, MP_QSTR_mount & 0xff, MP_QSTR_mount >> 8,
    0x1b, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8,
    0x16, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8,
    0x66, 0x02, 
    0x32, 
    0x44, 
    0x35, 0x21, 0x80, 
    0x30, 
    0x1b, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8,
    0xdf, 
    0x37, 0x18, 0x80, 
    0x32, 
    0x80, 
    0x11, 
    0x68, MP_QSTR_inisetup & 0xff, MP_QSTR_inisetup >> 8,
    0x24, MP_QSTR_inisetup & 0xff, MP_QSTR_inisetup >> 8,
    0x1b, MP_QSTR_inisetup & 0xff, MP_QSTR_inisetup >> 8,
    0x1e, MP_QSTR_setup & 0xff, MP_QSTR_setup >> 8,
    0x66, 0x00, 
    0x24, MP_QSTR_vfs & 0xff, MP_QSTR_vfs >> 8,
    0x45, 
    0x35, 0x01, 0x80, 
    0x41, 
    0x1b, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8,
    0x1e, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8,
    0x66, 0x00, 
    0x32, 
    0x11, 
    0x5b, 
};
const mp_raw_code_t raw_code__boot__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .data.u_byte = {
        .bytecode = bytecode_data__boot__lt_module_gt_,
        .const_table = NULL,
        #if MICROPY_PERSISTENT_CODE_SAVE
        .bc_len = 126,
        .n_obj = 0,
        .n_raw_code = 0,
        #endif
    },
};

const char mp_frozen_mpy_names[] = {
"apa106.py\0"
"dht.py\0"
"ds18x20.py\0"
"flashbdev.py\0"
"inisetup.py\0"
"neopixel.py\0"
"onewire.py\0"
"upip.py\0"
"upip_utarfile.py\0"
"urequests.py\0"
"_boot.py\0"
"\0"};
const mp_raw_code_t *const mp_frozen_mpy_content[] = {
    &raw_code_apa106__lt_module_gt_,
    &raw_code_dht__lt_module_gt_,
    &raw_code_ds18x20__lt_module_gt_,
    &raw_code_flashbdev__lt_module_gt_,
    &raw_code_inisetup__lt_module_gt_,
    &raw_code_neopixel__lt_module_gt_,
    &raw_code_onewire__lt_module_gt_,
    &raw_code_upip__lt_module_gt_,
    &raw_code_upip_utarfile__lt_module_gt_,
    &raw_code_urequests__lt_module_gt_,
    &raw_code__boot__lt_module_gt_,
};
