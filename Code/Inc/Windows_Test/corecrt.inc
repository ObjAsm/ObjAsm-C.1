;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\ucrt\corecrt.h', last modified: 01/09/2021 17:14

include vcruntime.inc
ifndef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  ifdef WINAPI_FAMILY
    include winapifamily.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      _CRT_USE_WINAPI_FAMILY_DESKTOP_APP equ <>
    else
      ifdef WINAPI_FAMILY_PHONE_APP
        if WINAPI_FAMILY eq WINAPI_FAMILY_PHONE_APP
          _CRT_USE_WINAPI_FAMILY_PHONE_APP equ <>
        endif
      endif
      ifdef WINAPI_FAMILY_GAMES
        if WINAPI_FAMILY eq WINAPI_FAMILY_GAMES
          _CRT_USE_WINAPI_FAMILY_GAMES equ <>
        endif
      endif
    endif
  else
    _CRT_USE_WINAPI_FAMILY_DESKTOP_APP equ <>
  endif
endif
ifndef _ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE
  _ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE equ 1
endif
ifndef _CRT_BUILD_DESKTOP_APP
  ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    _CRT_BUILD_DESKTOP_APP equ 1
  else
    _CRT_BUILD_DESKTOP_APP equ 0
  endif
endif
ifdef _M_ARM
  ;[...]
endif
ifndef _UCRT_DISABLED_WARNING_4412
  ifdef _M_CEE_PURE
    ;[...]
  else
    _UCRT_DISABLED_WARNING_4412 equ <>
  endif
endif
ifndef _UCRT_EXTRA_DISABLED_WARNINGS
  _UCRT_EXTRA_DISABLED_WARNINGS equ <>
endif
ifndef _UCRT_DISABLED_WARNINGS
  _UCRT_DISABLED_WARNINGS equ 4324 _UCRT_DISABLED_WARNING_4412 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 _UCRT_EXTRA_DISABLED_WARNINGS
endif
ifndef _UCRT_DISABLE_CLANG_WARNINGS
  ifdef __clang__
    _UCRT_DISABLE_CLANG_WARNINGS equ <_Pragma ("clang diagnostic push") _Pragma ("clang diagnostic ignored "" - Wdeprecated - declarations\"") _Pragma ("clang diagnostic ignored "" - Wignored - attributes\"") _Pragma ("clang diagnostic ignored "" - Wignored - pragma - optimize\"") _Pragma ("clang diagnostic ignored "" - Wunknown - pragmas\"")>
  else
    _UCRT_DISABLE_CLANG_WARNINGS equ <>
  endif
endif
ifndef _UCRT_RESTORE_CLANG_WARNINGS
  ifdef __clang__
    _UCRT_RESTORE_CLANG_WARNINGS equ <_Pragma ("clang diagnostic pop")>
  else
    _UCRT_RESTORE_CLANG_WARNINGS equ <>
  endif
endif
ifndef _ACRTIMP
  if Defined(_CRTIMP) and  not Defined(_VCRT_DEFINED_CRTIMP)
    _ACRTIMP equ <_CRTIMP>
  elseif  not Defined(_CORECRT_BUILD) and Defined(_DLL)
    _ACRTIMP equ <__declspec(dllimport)>
  else
    _ACRTIMP equ <>
  endif
endif
ifndef _ACRTIMP_ALT
  _ACRTIMP_ALT equ <_ACRTIMP>
endif
ifndef _DCRTIMP
  if Defined(_CRTIMP) and  not Defined(_VCRT_DEFINED_CRTIMP)
    _DCRTIMP equ <_CRTIMP>
  elseif  not Defined(_CORECRT_BUILD) and Defined(_DLL)
    _DCRTIMP equ <__declspec(dllimport)>
  else
    _DCRTIMP equ <>
  endif
endif
if Defined(_CRT_SUPPRESS_RESTRICT) or Defined(_CORECRT_BUILD)
  _CRTRESTRICT equ <>
else
  _CRTRESTRICT equ <__declspec(restrict)>
endif
if Defined(_MSC_VER) and _MSC_VER ge 1900 and  not Defined(_CORECRT_BUILD)
  _CRTALLOCATOR equ <__declspec(allocator)>
else
  _CRTALLOCATOR equ <>
endif
if Defined(_M_CEE) and Defined(_M_X64)
  ;[...]
else
  _CRT_JIT_INTRINSIC equ <>
endif
ifdef _GUARDOVERFLOW_CRT_ALLOCATORS
  _CRT_GUARDOVERFLOW equ <__declspec(guard (overflow))>
else
  _CRT_GUARDOVERFLOW equ <>
endif
if Defined(_DLL) and (Defined(_M_HYBRID) or Defined(_M_ARM64EC)) and (Defined(_CORECRT_BUILD) or Defined(_VCRT_BUILD))
  _CRT_HYBRIDPATCHABLE equ <__declspec(hybrid_patchable)>
else
  _CRT_HYBRIDPATCHABLE equ <>
endif
ifdef _M_CEE_PURE
  ;[...]
else
  _CRT_INLINE_PURE_SECURITYCRITICAL_ATTRIBUTE equ <>
endif
ifndef _CONST_RETURN
  ifdef __cplusplus
    ;[...]
  else
    _CONST_RETURN equ <>
  endif
endif
_WConst_return equ <_CONST_RETURN>
ifndef _CRT_ALIGN
  ifdef __midl
    ;[...]
  else
    _CRT_ALIGN macro x
      exitm <__declspec(align(x))>
    endm
  endif
endif
if Defined(_PREFAST_) and Defined(_CA_SHOULD_CHECK_RETURN)
  ;[...]
else
  _Check_return_opt_ equ <>
endif
if Defined(_PREFAST_) and Defined(_CA_SHOULD_CHECK_RETURN_WER)
  ;[...]
else
  _Check_return_wat_ equ <>
endif
if  not Defined(__midl) and  not Defined(MIDL_PASS) and Defined(_PREFAST_)
  ;[...]
else
  __crt_typefix macro ctype
    exitm <>
  endm
endif
ifndef _CRT_NOEXCEPT
  ifdef __cplusplus
    ;[...]
  else
    _CRT_NOEXCEPT equ <>
  endif
endif
ifdef __cplusplus
  ;[...]
endif
if Defined(__cplusplus)
  ;[...]
elseif Defined(__midl)
  ;[...]
else
  __crt_bool typedef _Bool
endif
_ARGMAX equ 100
_TRUNCATE equ (- 1)
_CRT_INT_MAX equ 2147483647
_CRT_SIZE_MAX equ (- 1)
__FILEW__ equ <_CRT_WIDE(__FILE__)>
__FUNCTIONW__ equ <_CRT_WIDE(__FUNCTION__)>
ifdef __cplusplus
  ;[...]
else
  ifndef _STATIC_ASSERT
    ifdef __clang__
      _STATIC_ASSERT macro expr
        exitm <_Static_assert ((expr), # expr)>
      endm
    else
      _STATIC_ASSERT macro expr
        exitm <typedef char __static_assert_t [ (expr) != 0 ]>
      endm
    endif
  endif
endif
ifndef NULL
  ifdef __cplusplus
    ;[...]
  else
    NULL equ (0)
  endif
endif
if  not Defined(_CRT_FUNCTIONS_REQUIRED)
  if Defined(__assembler) or Defined(__midl) or Defined(RC_INVOKED)
    _CRT_FUNCTIONS_REQUIRED equ 0
  else
    _CRT_FUNCTIONS_REQUIRED equ 1
  endif
endif
if  not Defined(_NO_INLINING) and  not _CRT_FUNCTIONS_REQUIRED
  _NO_INLINING equ <>
endif
ifndef _CRT_UNUSED
  _CRT_UNUSED macro x
    exitm <x>
  endm
endif
ifndef _CRT_HAS_CXX17
  ifdef _MSVC_LANG
    if _MSVC_LANG gt 201402
      _CRT_HAS_CXX17 equ 1
    else
      _CRT_HAS_CXX17 equ 0
    endif
  else
    if Defined(__cplusplus) and __cplusplus gt 201402
      ;[...]
    else
      _CRT_HAS_CXX17 equ 0
    endif
  endif
endif
ifndef _CRT_HAS_C11
  if Defined(__STDC_VERSION__) and __STDC_VERSION__ ge 201112
    _CRT_HAS_C11 equ 1
  else
    _CRT_HAS_C11 equ 0
  endif
endif
ifdef _DEBUG
  @DefProto DllImport, _invalid_parameter, c,, <:ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :DWORD, :uintptr_t>
endif
@DefProto DllImport, _invalid_parameter_noinfo, c,, <>
@DefProto DllImport, _invalid_parameter_noinfo_noreturn, c,, <>
@DefProto DllImport, _invoke_watson, c,, <:ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :DWORD, :uintptr_t>
ifndef _CRT_SECURE_INVALID_PARAMETER
  ifdef _DEBUG
    _CRT_SECURE_INVALID_PARAMETER macro expr
      exitm <:: _invalid_parameter (_CRT_WIDE(# expr), __FUNCTIONW__, __FILEW__, __LINE__, 0)>
    endm
  else
    _CRT_SECURE_INVALID_PARAMETER macro expr
      exitm <:: _invalid_parameter_noinfo_noreturn ()>
    endm
  endif
endif
_CRT_WARNING_MESSAGE macro NUMBER, MESSAGE
  exitm <__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): warning " NUMBER ": " MESSAGE>
endm
if (Defined(_CRT_DECLARE_NONSTDC_NAMES) and _CRT_DECLARE_NONSTDC_NAMES) or ( not Defined(_CRT_DECLARE_NONSTDC_NAMES) and  not __STDC__)
  _CRT_INTERNAL_NONSTDC_NAMES equ 1
else
  _CRT_INTERNAL_NONSTDC_NAMES equ 0
endif
if Defined(_CRT_NONSTDC_NO_DEPRECATE) and  not Defined(_CRT_NONSTDC_NO_WARNINGS)
  _CRT_NONSTDC_NO_WARNINGS equ <>
endif
ifndef _CRT_NONSTDC_DEPRECATE
  ifdef _CRT_NONSTDC_NO_WARNINGS
    _CRT_NONSTDC_DEPRECATE macro _NewName
      exitm <>
    endm
  else
    _CRT_NONSTDC_DEPRECATE macro _NewName
      exitm <_CRT_DEPRECATE_TEXT("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " # _NewName ". See online help for details.")>
    endm
  endif
endif
ifndef _PGLOBAL
  ifdef _M_CEE
    ;[...]
  else
    _PGLOBAL equ <>
  endif
endif
ifndef _AGLOBAL
  ifdef _M_CEE
    ;[...]
  else
    _AGLOBAL equ <>
  endif
endif
if Defined(_M_CEE) and  not Defined(_M_CEE_PURE)
  ;[...]
endif
if Defined(_CRTBLD) or Defined(_CORECRT_BUILD) or Defined(_VCRT_BUILD)
  _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES equ 0
  _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT equ 0
  _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES equ 0
endif
if  not _CRT_FUNCTIONS_REQUIRED
  _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES equ 0
  _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT equ 0
  _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES equ 0
  _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY equ 0
  _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY equ 0
endif
__STDC_SECURE_LIB__ equ 200411
__GOT_SECURE_LIB__ equ <__STDC_SECURE_LIB__>
ifndef __STDC_WANT_SECURE_LIB__
  __STDC_WANT_SECURE_LIB__ equ 1
endif
if  not __STDC_WANT_SECURE_LIB__ and  not Defined(_CRT_SECURE_NO_WARNINGS)
  _CRT_SECURE_NO_WARNINGS equ <>
endif
ifndef RC_INVOKED
  if Defined(_CRT_SECURE_NO_DEPRECATE_GLOBALS) and  not Defined(_CRT_SECURE_NO_WARNINGS_GLOBALS)
    _CRT_SECURE_NO_WARNINGS_GLOBALS equ <>
  endif
endif
ifndef _CRT_INSECURE_DEPRECATE_GLOBALS
  ifdef RC_INVOKED
    ;[...]
  else
    ifdef _CRT_SECURE_NO_WARNINGS_GLOBALS
      _CRT_INSECURE_DEPRECATE_GLOBALS macro replacement
        exitm <>
      endm
    else
      _CRT_INSECURE_DEPRECATE_GLOBALS macro replacement
        exitm <_CRT_INSECURE_DEPRECATE(replacement)>
      endm
    endif
  endif
endif
if Defined(_CRT_MANAGED_HEAP_NO_DEPRECATE) and  not Defined(_CRT_MANAGED_HEAP_NO_WARNINGS)
  _CRT_MANAGED_HEAP_NO_WARNINGS equ <>
endif
_SECURECRT_FILL_BUFFER_PATTERN equ 0FEh
if Defined(_CRT_OBSOLETE_NO_DEPRECATE) and  not Defined(_CRT_OBSOLETE_NO_WARNINGS)
  _CRT_OBSOLETE_NO_WARNINGS equ <>
endif
ifndef _CRT_OBSOLETE
  ifdef _CRT_OBSOLETE_NO_WARNINGS
    _CRT_OBSOLETE macro _NewItem
      exitm <>
    endm
  else
    _CRT_OBSOLETE macro _NewItem
      exitm <_CRT_DEPRECATE_TEXT("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " # _NewItem " " "instead. See online help for details.")>
    endm
  endif
endif
ifndef RC_INVOKED
  ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
    _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES equ 0
  else
    if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
      .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
    endif
  endif
  ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
    _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT equ 0
  else
    if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
      .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
    endif
  endif
  ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
    if __STDC_WANT_SECURE_LIB__
      _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES equ 1
    else
      _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES equ 0
    endif
  else
    if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
      .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
    endif
  endif
  ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
    _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY equ 0
  else
    if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
      .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
    endif
  endif
  ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
    _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY equ 0
  else
    if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
      .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
    endif
  endif
endif
ifndef _CRT_SECURE_CPP_NOTHROW
  _CRT_SECURE_CPP_NOTHROW equ <throw ()>
endif
errno_t typedef SDWORD
wint_t typedef WORD
wctype_t typedef WORD
__time32_t typedef SDWORD
__time64_t typedef SQWORD
__crt_locale_data_public struct
  _locale_pctype POINTER ?
  _locale_mb_cur_max SDWORD ?
  _locale_lc_codepage DWORD ?
__crt_locale_data_public ends

__crt_locale_pointers struct
  locinfo POINTER ?
  mbcinfo POINTER ?
__crt_locale_pointers ends

_locale_t typedef ptr __crt_locale_pointers
_Mbstatet struct
  _Wchar DWORD ?
  _Byte WORD ?
_Mbstatet ends

mbstate_t typedef _Mbstatet
if Defined(_USE_32BIT_TIME_T) and Defined(_WIN64)
  .err <You cannot use 32 - bit time_t ( _USE_32BIT_TIME_T ) with _WIN64>
endif
if Defined(_VCRT_BUILD) or Defined(_CORECRT_BUILD)
  _CRT_NO_TIME_T equ <>
endif
ifndef _CRT_NO_TIME_T
  ifdef _USE_32BIT_TIME_T
    time_t typedef __time32_t
  else
    time_t typedef __time64_t
  endif
endif
ifndef _TIME_T_DEFINED
  _TIME_T_DEFINED equ <>
endif
if __STDC_WANT_SECURE_LIB__
  rsize_t typedef size_t
endif
ifndef RC_INVOKED
  if Defined(__cplusplus) and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
    ;[...]
  else
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0 macro _ReturnType, _FuncName, _DstType, _Dst
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1 macro _ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2 macro _ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3 macro _ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0 macro _ReturnType, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _DstType, _Dst
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST macro _ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST macro _ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
      exitm <>
    endm
    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH macro _ReturnType, _FuncName, _DstType, _Src
      exitm <>
    endm
  endif
endif
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _FuncName ## _s, _VFuncName, _VFuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _VFuncName, _VFuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _DstType, _Dst, _TType1, _TArg1)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, __cdecl, _FuncName, _FuncName ## _s, _VFuncName, _VFuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
endm
__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
  exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
endm
ifndef RC_INVOKED
  if Defined(__cplusplus) and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
    ;[...]
  else
    __RETURN_POLICY_SAME macro _FunctionCall
      exitm <>
    endm
    __RETURN_POLICY_DST macro _FunctionCall
      exitm <>
    endm
    __RETURN_POLICY_VOID macro _FunctionCall
      exitm <>
    endm
    __EMPTY_DECLSPEC equ <>
    if _CRT_FUNCTIONS_REQUIRED
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS macro _ReturnType, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType _CC _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1,...) ; _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType _CC _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _VFuncName, _SecureVFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType _CC _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2,...) ; _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType _CC _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_GETS macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType _CC _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1,...) ; _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType _CC _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2,...) ; _CRT_INSECURE_DEPRECATE(_VFuncName ## _s) _DeclSpec _ReturnType __cdecl _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _CC, _FuncName, _VFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType _CC _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2,...) ; _CRT_INSECURE_DEPRECATE(_VFuncName ## _s) _DeclSpec _ReturnType _CC _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <>
      endm
    else
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_GETS macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX macro ...
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX macro ...
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX macro ...
        exitm <>
      endm
    endif
  endif
endif
 