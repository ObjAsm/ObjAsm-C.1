;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\ucrt\stdlib.h', last modified: 01/09/2021 17:14

ifndef _INC_STDLIB
  _INC_STDLIB equ <>
  include corecrt.inc
  include corecrt_malloc.inc
  include corecrt_search.inc
  include corecrt_wstdlib.inc
  include limits.inc
  ifndef _countof
    _countof equ <__crt_countof>
  endif
  __max macro a, b
    exitm <(((a) > (b)) ? (a) : (b))>
  endm
  __min macro a, b
    exitm <(((a) < (b)) ? (a) : (b))>
  endm
  @DefProto DllImport, _swab, c,, <:ptr SBYTE, :ptr SBYTE, :SDWORD>
  EXIT_SUCCESS equ 0
  EXIT_FAILURE equ 1
  if _CRT_FUNCTIONS_REQUIRED
    @DefProto DllImport, exit, c,, <:SDWORD>
    @DefProto DllImport, _exit, c,, <:SDWORD>
    @DefProto DllImport, _Exit, c,, <:SDWORD>
    @DefProto DllImport, quick_exit, c,, <:SDWORD>
    @DefProto DllImport, abort, c,, <>
  endif
  _WRITE_ABORT_MSG equ 1h
  _CALL_REPORTFAULT equ 2h
  @DefProto DllImport, _set_abort_behavior, c,, <:DWORD, :DWORD>
  ifndef _CRT_ONEXIT_T_DEFINED
    _CRT_ONEXIT_T_DEFINED equ <>
    TYPE__onexit_t typedef proto c
    _onexit_t typedef ptr TYPE__onexit_t
    
    ifdef _M_CEE
      ;[...]
    endif
  endif
  if Defined(_CRT_INTERNAL_NONSTDC_NAMES) and _CRT_INTERNAL_NONSTDC_NAMES
    onexit_t equ <_onexit_t>
  endif
  ifdef _M_CEE
    ;[...]
  endif
  ifdef _M_CEE_PURE
    ;[...]
  else
    atexit proto c :ptr
    _onexit proto c :_onexit_t
  endif
  at_quick_exit proto c :ptr
  ifndef _M_CEE_PURE
    TYPE__purecall_handler typedef proto c
    _purecall_handler typedef ptr TYPE__purecall_handler
    
    TYPE__invalid_parameter_handler typedef proto c :ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :DWORD, :uintptr_t
    _invalid_parameter_handler typedef ptr TYPE__invalid_parameter_handler
    
    _set_purecall_handler proto c :_purecall_handler
    _get_purecall_handler proto c
    @DefProto DllImport, _set_invalid_parameter_handler, c,, <:_invalid_parameter_handler>
    @DefProto DllImport, _get_invalid_parameter_handler, c,, <>
    @DefProto DllImport, _set_thread_local_invalid_parameter_handler, c,, <:_invalid_parameter_handler>
    @DefProto DllImport, _get_thread_local_invalid_parameter_handler, c,, <>
  endif
  if Defined(__cplusplus) and Defined(_M_CEE_PURE)
    ;[...]
  endif
  _OUT_TO_DEFAULT equ 0
  _OUT_TO_STDERR equ 1
  _OUT_TO_MSGBOX equ 2
  _REPORT_ERRMODE equ 3
  @DefProto DllImport, _set_error_mode, c,, <:SDWORD>
  if _CRT_FUNCTIONS_REQUIRED
    @DefProto DllImport, _errno, c,, <>
    errno equ <(* _errno ())>
    @DefProto DllImport, _set_errno, c,, <:SDWORD>
    @DefProto DllImport, _get_errno, c,, <:ptr SDWORD>
    @DefProto DllImport, __doserrno, c,, <>
    _doserrno equ <(* __doserrno ())>
    @DefProto DllImport, _set_doserrno, c,, <:DWORD>
    @DefProto DllImport, _get_doserrno, c,, <:ptr DWORD>
    @DefProto DllImport, __sys_errlist, c,, <>
    _sys_errlist equ <(__sys_errlist ())>
    @DefProto DllImport, __sys_nerr, c,, <>
    _sys_nerr equ <(* __sys_nerr ())>
    @DefProto DllImport, perror, c,, <:ptr SBYTE>
  endif
  @DefProto DllImport, __p__pgmptr, c,, <>
  @DefProto DllImport, __p__wpgmptr, c,, <>
  @DefProto DllImport, __p__fmode, c,, <>
  ifdef _CRT_DECLARE_GLOBAL_VARIABLES_DIRECTLY
    ifndef _CORECRT_BUILD
      externdef _fmode:SDWORD
    endif
  else
    _pgmptr equ <(* __p__pgmptr ())>
    _wpgmptr equ <(* __p__wpgmptr ())>
    _fmode equ <(* __p__fmode ())>
  endif
  @DefProto DllImport, _get_pgmptr, c,, <:ptr ptr SBYTE>
  @DefProto DllImport, _get_wpgmptr, c,, <:ptr ptr wchar_t>
  @DefProto DllImport, _set_fmode, c,, <:SDWORD>
  @DefProto DllImport, _get_fmode, c,, <:ptr SDWORD>
  div_t struct
    quot SDWORD ?
    rem SDWORD ?
  div_t ends

  _div_t typedef div_t
  ldiv_t struct
    quot SDWORD ?
    rem SDWORD ?
  ldiv_t ends

  _ldiv_t typedef ldiv_t
  lldiv_t struct
    quot SQWORD ?
    rem SQWORD ?
  lldiv_t ends

  _lldiv_t typedef lldiv_t
  abs_ proto c :SDWORD
  labs proto c :SDWORD
  llabs proto c :SQWORD
  _abs64 proto c :SQWORD
  _byteswap_ushort proto c :WORD
  _byteswap_ulong proto c :DWORD
  _byteswap_uint64 proto c :QWORD
  @DefProto DllImport, div, c, _, <:SDWORD, :SDWORD>
  @DefProto DllImport, ldiv, c,, <:SDWORD, :SDWORD>
  @DefProto DllImport, lldiv, c,, <:SQWORD, :SQWORD>
  _rotl proto c :DWORD, :SDWORD
  _lrotl proto c :DWORD, :SDWORD
  _rotl64 proto c :QWORD, :SDWORD
  _rotr proto c :DWORD, :SDWORD
  _lrotr proto c :DWORD, :SDWORD
  _rotr64 proto c :QWORD, :SDWORD
  RAND_MAX equ 7fffh
  @DefProto DllImport, srand, c,, <:DWORD>
  @DefProto DllImport, rand, c,, <>
  if Defined(_CRT_RAND_S) or Defined(_CRTBLD)
    @DefProto DllImport, rand_s, c,, <:ptr DWORD>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  _CRT_DOUBLE_DEC equ <>
  ifndef _LDSUPPORT
    _LDOUBLE struct
      ld BYTE (10) dup(?)
    _LDOUBLE ends

    _PTR_LD macro x
      exitm <((and (x) - ld))>
    endm
  else
    _LDOUBLE typedef REAL10
    _PTR_LD macro x
      exitm <((x))>
    endm
  endif
  _CRT_DOUBLE struct
    x REAL8 ?
  _CRT_DOUBLE ends

  _CRT_FLOAT struct
    f REAL4 ?
  _CRT_FLOAT ends

  _LONGDOUBLE struct
    x REAL10 ?
  _LONGDOUBLE ends

  _LDBL12 struct
    ld12 BYTE (12) dup(?)
  _LDBL12 ends

  @DefProto DllImport, atof, c,, <:ptr SBYTE>
  @DefProto DllImport, atoi, c,, <:ptr SBYTE>
  @DefProto DllImport, atol, c,, <:ptr SBYTE>
  @DefProto DllImport, atoll, c,, <:ptr SBYTE>
  @DefProto DllImport, _atoi64, c,, <:ptr SBYTE>
  @DefProto DllImport, _atof_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atoi_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atol_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atoll_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atoi64_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atoflt, c,, <:ptr _CRT_FLOAT, :ptr SBYTE>
  @DefProto DllImport, _atodbl, c,, <:ptr _CRT_DOUBLE, :ptr SBYTE>
  @DefProto DllImport, _atoldbl, c,, <:ptr _LDOUBLE, :ptr SBYTE>
  @DefProto DllImport, _atoflt_l, c,, <:ptr _CRT_FLOAT, :ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atodbl_l, c,, <:ptr _CRT_DOUBLE, :ptr SBYTE, :_locale_t>
  @DefProto DllImport, _atoldbl_l, c,, <:ptr _LDOUBLE, :ptr SBYTE, :_locale_t>
  @DefProto DllImport, strtof, c,, <:ptr SBYTE, :ptr ptr SBYTE>
  @DefProto DllImport, _strtof_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :_locale_t>
  @DefProto DllImport, strtod, c,, <:ptr SBYTE, :ptr ptr SBYTE>
  @DefProto DllImport, _strtod_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :_locale_t>
  @DefProto DllImport, strtold, c,, <:ptr SBYTE, :ptr ptr SBYTE>
  @DefProto DllImport, _strtold_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :_locale_t>
  @DefProto DllImport, strtol, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtol_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, strtoll, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoll_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, strtoul, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoul_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, strtoull, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoull_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, _strtoi64, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoi64_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, _strtoui64, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoui64_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, _itoa_s, c,, <:SDWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _ltoa_s, c,, <:SDWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _ultoa_s, c,, <:DWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _i64toa_s, c,, <:SQWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _i64toa, c,, <:SQWORD, :ptr SBYTE, :SDWORD>
  @DefProto DllImport, _ui64toa_s, c,, <:QWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _ui64toa, c,, <:QWORD, :ptr SBYTE, :SDWORD>
  _CVTBUFSIZE equ (309 + 40)
  @DefProto DllImport, _ecvt_s, c,, <:ptr SBYTE, :size_t, :REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
  @DefProto DllImport, _ecvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
  @DefProto DllImport, _fcvt_s, c,, <:ptr SBYTE, :size_t, :REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
  @DefProto DllImport, _fcvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
  @DefProto DllImport, _gcvt_s, c,, <:ptr SBYTE, :size_t, :REAL8, :SDWORD>
  @DefProto DllImport, _gcvt, c,, <:REAL8, :SDWORD, :ptr SBYTE>
  ifndef MB_CUR_MAX
    if Defined(_CRT_DISABLE_PERFCRIT_LOCKS) and  not Defined(_DLL)
      MB_CUR_MAX equ <__mb_cur_max>
    else
      MB_CUR_MAX equ <___mb_cur_max_func ()>
    endif
    ifdef _CRT_DECLARE_GLOBAL_VARIABLES_DIRECTLY
      externdef __mb_cur_max:SDWORD
    else
      __mb_cur_max equ <(___mb_cur_max_func ())>
    endif
    @DefProto DllImport, ___mb_cur_max_func, c,, <>
    @DefProto DllImport, ___mb_cur_max_l_func, c,, <:_locale_t>
  endif
  @DefProto DllImport, mblen, c,, <:ptr SBYTE, :size_t>
  @DefProto DllImport, _mblen_l, c,, <:ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, _mbstrlen, c,, <:ptr SBYTE>
  @DefProto DllImport, _mbstrlen_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _mbstrnlen, c,, <:ptr SBYTE, :size_t>
  @DefProto DllImport, _mbstrnlen_l, c,, <:ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, mbtowc, c,, <:ptr wchar_t, :ptr SBYTE, :size_t>
  @DefProto DllImport, _mbtowc_l, c,, <:ptr wchar_t, :ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, mbstowcs_s, c,, <:ptr size_t, :ptr wchar_t, :size_t, :ptr SBYTE, :size_t>
  @DefProto DllImport, _mbstowcs_s_l, c,, <:ptr size_t, :ptr wchar_t, :size_t, :ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, wctomb, c,, <:ptr SBYTE, :wchar_t>
  @DefProto DllImport, _wctomb_l, c,, <:ptr SBYTE, :wchar_t, :_locale_t>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, wctomb_s, c,, <:ptr SDWORD, :ptr SBYTE, :rsize_t, :wchar_t>
  endif
  @DefProto DllImport, _wctomb_s_l, c,, <:ptr SDWORD, :ptr SBYTE, :size_t, :wchar_t, :_locale_t>
  @DefProto DllImport, wcstombs_s, c,, <:ptr size_t, :ptr SBYTE, :size_t, :ptr wchar_t, :size_t>
  @DefProto DllImport, _wcstombs_s_l, c,, <:ptr size_t, :ptr SBYTE, :size_t, :ptr wchar_t, :size_t, :_locale_t>
  _MAX_PATH equ 260
  _MAX_DRIVE equ 3
  _MAX_DIR equ 256
  _MAX_FNAME equ 256
  _MAX_EXT equ 256
  @DefProto DllImport, _fullpath, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
  @DefProto DllImport, _makepath_s, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _splitpath, c,, <:ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _splitpath_s, c,, <:ptr SBYTE, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, getenv_s, c,, <:ptr size_t, :ptr SBYTE, :rsize_t, :ptr SBYTE>
  endif
  @DefProto DllImport, __p___argc, c,, <>
  @DefProto DllImport, __p___argv, c,, <>
  @DefProto DllImport, __p___wargv, c,, <>
  ifdef _CRT_DECLARE_GLOBAL_VARIABLES_DIRECTLY
    externdef __argc:SDWORD
  else
    __argc equ <(* __p___argc ())>
    __argv equ <(* __p___argv ())>
    __wargv equ <(* __p___wargv ())>
  endif
  @DefProto DllImport, __p__environ, c,, <>
  @DefProto DllImport, __p__wenviron, c,, <>
  ifndef _CRT_BEST_PRACTICES_USAGE
    _CRT_V12_LEGACY_FUNCTIONALITY equ <>
  endif
  ifndef _CRT_V12_LEGACY_FUNCTIONALITY
    _environ equ <crt_usage_error__do_not_reference_global_pointer_directly__environ>
    _wenviron equ <crt_usage_error__do_not_reference_global_pointer_directly__wenviron>
  else
    _environ equ <(* __p__environ ())>
    _wenviron equ <(* __p__wenviron ())>
  endif
  _MAX_ENV equ 32767
  if _CRT_FUNCTIONS_REQUIRED
    @DefProto DllImport, getenv, c,, <:ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _dupenv_s, c,, <:ptr ptr SBYTE, :ptr size_t, :ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, system, c,, <:ptr SBYTE>
    @DefProto DllImport, _putenv, c,, <:ptr SBYTE>
    @DefProto DllImport, _putenv_s, c,, <:ptr SBYTE, :ptr SBYTE>
    @DefProto DllImport, _searchenv_s, c,, <:ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :size_t>
    @DefProto DllImport, _seterrormode, c,, <:SDWORD>
    @DefProto DllImport, _beep, c,, <:DWORD, :DWORD>
    @DefProto DllImport, _sleep, c,, <:DWORD>
  endif
  if Defined(_CRT_INTERNAL_NONSTDC_NAMES) and _CRT_INTERNAL_NONSTDC_NAMES
    ifndef __cplusplus
      max macro a, b
        exitm <(((a) > (b)) ? (a) : (b))>
      endm
      min macro a, b
        exitm <(((a) < (b)) ? (a) : (b))>
      endm
    endif
    sys_errlist equ <_sys_errlist>
    sys_nerr equ <_sys_nerr>
    @DefProto DllImport, ecvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
    @DefProto DllImport, fcvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
    @DefProto DllImport, gcvt, c,, <:REAL8, :SDWORD, :ptr SBYTE>
    @DefProto DllImport, itoa, c,, <:SDWORD, :ptr SBYTE, :SDWORD>
    @DefProto DllImport, ltoa, c,, <:SDWORD, :ptr SBYTE, :SDWORD>
    @DefProto DllImport, swab, c,, <:ptr SBYTE, :ptr SBYTE, :SDWORD>
    @DefProto DllImport, ultoa, c,, <:DWORD, :ptr SBYTE, :SDWORD>
    environ equ <_environ>
    @DefProto DllImport, putenv, c,, <:ptr SBYTE>
    onexit proto c :onexit_t
  endif
endif
 