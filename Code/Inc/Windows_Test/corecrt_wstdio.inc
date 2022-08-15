;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\ucrt\corecrt_wstdio.h', last modified: 01/09/2021 17:14

include corecrt.inc
include corecrt_stdio_config.inc
ifndef _FILE_DEFINED
  _FILE_DEFINED equ <>
  FILE struct
    _Placeholder POINTER ?
  FILE ends

  _iobuf typedef FILE
endif
@DefProto DllImport, __acrt_iob_func, c,, <:DWORD>
stdin equ (__acrt_iob_func (0))
stdout equ (__acrt_iob_func (1))
stderr equ (__acrt_iob_func (2))
WEOF equ (0FFFFh)
if _CRT_FUNCTIONS_REQUIRED
  @DefProto DllImport, fgetwc, c,, <:ptr FILE>
  @DefProto DllImport, _fgetwchar, c,, <>
  @DefProto DllImport, fputwc, c,, <:wchar_t, :ptr FILE>
  @DefProto DllImport, _fputwchar, c,, <:wchar_t>
  @DefProto DllImport, getwc, c,, <:ptr FILE>
  @DefProto DllImport, getwchar, c,, <>
  @DefProto DllImport, fgetws, c,, <:ptr wchar_t, :SDWORD, :ptr FILE>
  @DefProto DllImport, fputws, c,, <:ptr wchar_t, :ptr FILE>
  @DefProto DllImport, _getws_s, c,, <:ptr wchar_t, :size_t>
  @DefProto DllImport, putwc, c,, <:wchar_t, :ptr FILE>
  @DefProto DllImport, putwchar, c,, <:wchar_t>
  @DefProto DllImport, _putws, c,, <:ptr wchar_t>
  @DefProto DllImport, ungetwc, c,, <:wint_t, :ptr FILE>
  @DefProto DllImport, _wfdopen, c,, <:SDWORD, :ptr wchar_t>
  @DefProto DllImport, _wfopen, c,, <:ptr wchar_t, :ptr wchar_t>
  @DefProto DllImport, _wfopen_s, c,, <:ptr ptr FILE, :ptr wchar_t, :ptr wchar_t>
  @DefProto DllImport, _wfreopen, c,, <:ptr wchar_t, :ptr wchar_t, :ptr FILE>
  @DefProto DllImport, _wfreopen_s, c,, <:ptr ptr FILE, :ptr wchar_t, :ptr wchar_t, :ptr FILE>
  @DefProto DllImport, _wfsopen, c,, <:ptr wchar_t, :ptr wchar_t, :SDWORD>
  @DefProto DllImport, _wperror, c,, <:ptr wchar_t>
  ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    @DefProto DllImport, _wpopen, c,, <:ptr wchar_t, :ptr wchar_t>
  endif
  @DefProto DllImport, _wremove, c,, <:ptr wchar_t>
  @DefProto DllImport, _wtempnam, c,, <:ptr wchar_t, :ptr wchar_t>
  @DefProto DllImport, _wtmpnam_s, c,, <:ptr wchar_t, :size_t>
  @DefProto DllImport, _fgetwc_nolock, c,, <:ptr FILE>
  @DefProto DllImport, _fputwc_nolock, c,, <:wchar_t, :ptr FILE>
  @DefProto DllImport, _getwc_nolock, c,, <:ptr FILE>
  @DefProto DllImport, _putwc_nolock, c,, <:wchar_t, :ptr FILE>
  @DefProto DllImport, _ungetwc_nolock, c,, <:wint_t, :ptr FILE>
  if Defined(_CRT_DISABLE_PERFCRIT_LOCKS) and  not Defined(_DLL)
    fgetwc macro stream
      exitm <_getwc_nolock(stream)>
    endm
    fputwc macro c_, stream
      exitm <_putwc_nolock(c_, stream)>
    endm
    ungetwc macro c_, stream
      exitm <_ungetwc_nolock (c_, stream)>
    endm
  endif
  ifdef _M_CEE_MIXED
    ;[...]
  endif
  @DefProto DllImport, __stdio_common_vfwprintf, c,, <:QWORD, :ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
  @DefProto DllImport, __stdio_common_vfwprintf_s, c,, <:QWORD, :ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
  @DefProto DllImport, __stdio_common_vfwprintf_p, c,, <:QWORD, :ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
  _vfwprintf_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :va_list
  if Defined(_NO_CRT_STDIO_INLINE)
    if Defined(_NO_CRT_STDIO_INLINE)
    else
      __stdio_common_vfwprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
    endif
    vfwprintf proto c :ptr FILE, :ptr wchar_t, :va_list
    if Defined(_NO_CRT_STDIO_INLINE)
      if Defined(_NO_CRT_STDIO_INLINE)
      else
        _vfwprintf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
      endif
      _vfwprintf_s_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :va_list
      if Defined(_NO_CRT_STDIO_INLINE)
        if Defined(_NO_CRT_STDIO_INLINE)
        else
          __stdio_common_vfwprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
        endif
        if __STDC_WANT_SECURE_LIB__
          vfwprintf_s proto c :ptr FILE, :ptr wchar_t, :va_list
          if Defined(_NO_CRT_STDIO_INLINE)
            if Defined(_NO_CRT_STDIO_INLINE)
            else
              _vfwprintf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
            endif
          endif
          _vfwprintf_p_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :va_list
          if Defined(_NO_CRT_STDIO_INLINE)
            if Defined(_NO_CRT_STDIO_INLINE)
            else
              __stdio_common_vfwprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
            endif
            _vfwprintf_p proto c :ptr FILE, :ptr wchar_t, :va_list
            if Defined(_NO_CRT_STDIO_INLINE)
              if Defined(_NO_CRT_STDIO_INLINE)
              else
                _vfwprintf_p_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
              endif
              _vwprintf_l proto c :ptr wchar_t, :_locale_t, :va_list
              if Defined(_NO_CRT_STDIO_INLINE)
                if Defined(_NO_CRT_STDIO_INLINE)
                else
                  _vfwprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                endif
                vwprintf proto c :ptr wchar_t, :va_list
                if Defined(_NO_CRT_STDIO_INLINE)
                  if Defined(_NO_CRT_STDIO_INLINE)
                  else
                    _vfwprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                  endif
                  _vwprintf_s_l proto c :ptr wchar_t, :_locale_t, :va_list
                  if Defined(_NO_CRT_STDIO_INLINE)
                    if Defined(_NO_CRT_STDIO_INLINE)
                    else
                      _vfwprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                    endif
                    if __STDC_WANT_SECURE_LIB__
                      vwprintf_s proto c :ptr wchar_t, :va_list
                      if Defined(_NO_CRT_STDIO_INLINE)
                        if Defined(_NO_CRT_STDIO_INLINE)
                        else
                          _vfwprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                        endif
                      endif
                      _vwprintf_p_l proto c :ptr wchar_t, :_locale_t, :va_list
                      if Defined(_NO_CRT_STDIO_INLINE)
                        if Defined(_NO_CRT_STDIO_INLINE)
                        else
                          _vfwprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                        endif
                        _vwprintf_p proto c :ptr wchar_t, :va_list
                        if Defined(_NO_CRT_STDIO_INLINE)
                          if Defined(_NO_CRT_STDIO_INLINE)
                          else
                            _vfwprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                          endif
                          _fwprintf_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :vararg
                          if Defined(_NO_CRT_STDIO_INLINE)
                            if Defined(_NO_CRT_STDIO_INLINE)
                            else
                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                              _vfwprintf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                            endif
                            fwprintf proto c :ptr FILE, :ptr wchar_t, :vararg
                            if Defined(_NO_CRT_STDIO_INLINE)
                              if Defined(_NO_CRT_STDIO_INLINE)
                              else
                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                _vfwprintf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                              endif
                              _fwprintf_s_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :vararg
                              if Defined(_NO_CRT_STDIO_INLINE)
                                if Defined(_NO_CRT_STDIO_INLINE)
                                else
                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                  _vfwprintf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                endif
                                if __STDC_WANT_SECURE_LIB__
                                  fwprintf_s proto c :ptr FILE, :ptr wchar_t, :vararg
                                  if Defined(_NO_CRT_STDIO_INLINE)
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                    else
                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                      _vfwprintf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                    endif
                                  endif
                                  _fwprintf_p_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :vararg
                                  if Defined(_NO_CRT_STDIO_INLINE)
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                    else
                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                      _vfwprintf_p_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                    endif
                                    _fwprintf_p proto c :ptr FILE, :ptr wchar_t, :vararg
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                      else
                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                        _vfwprintf_p_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                      endif
                                      _wprintf_l proto c :ptr wchar_t, :_locale_t, :vararg
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                        if Defined(_NO_CRT_STDIO_INLINE)
                                        else
                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                          _vfwprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                        endif
                                        wprintf proto c :ptr wchar_t, :vararg
                                        if Defined(_NO_CRT_STDIO_INLINE)
                                          if Defined(_NO_CRT_STDIO_INLINE)
                                          else
                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                            _vfwprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                          endif
                                          _wprintf_s_l proto c :ptr wchar_t, :_locale_t, :vararg
                                          if Defined(_NO_CRT_STDIO_INLINE)
                                            if Defined(_NO_CRT_STDIO_INLINE)
                                            else
                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                              _vfwprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                            endif
                                            if __STDC_WANT_SECURE_LIB__
                                              wprintf_s proto c :ptr wchar_t, :vararg
                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                else
                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                  _vfwprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                endif
                                              endif
                                              _wprintf_p_l proto c :ptr wchar_t, :_locale_t, :vararg
                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                else
                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                  _vfwprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                endif
                                                _wprintf_p proto c :ptr wchar_t, :vararg
                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                  else
                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                    _vfwprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                  endif
                                                  @DefProto DllImport, __stdio_common_vfwscanf, c,, <:QWORD, :ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
                                                  _vfwscanf_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :va_list
                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                    else
                                                      __stdio_common_vfwscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
                                                    endif
                                                    vfwscanf proto c :ptr FILE, :ptr wchar_t, :va_list
                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                      else
                                                        _vfwscanf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                      endif
                                                      _vfwscanf_s_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :va_list
                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                        else
                                                          __stdio_common_vfwscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
                                                        endif
                                                        if __STDC_WANT_SECURE_LIB__
                                                          vfwscanf_s proto c :ptr FILE, :ptr wchar_t, :va_list
                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                            else
                                                              _vfwscanf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                            endif
                                                          endif
                                                          _vwscanf_l proto c :ptr wchar_t, :_locale_t, :va_list
                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                            else
                                                              _vfwscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                            endif
                                                            vwscanf proto c :ptr wchar_t, :va_list
                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                              else
                                                                _vfwscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                              endif
                                                              _vwscanf_s_l proto c :ptr wchar_t, :_locale_t, :va_list
                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                else
                                                                  _vfwscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                                endif
                                                                if __STDC_WANT_SECURE_LIB__
                                                                  vwscanf_s proto c :ptr wchar_t, :va_list
                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                    else
                                                                      _vfwscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                    endif
                                                                  endif
                                                                  _fwscanf_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :vararg
                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                    else
                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                      _vfwscanf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                    endif
                                                                    fwscanf proto c :ptr FILE, :ptr wchar_t, :vararg
                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                      else
                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                        _vfwscanf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                      endif
                                                                      _fwscanf_s_l proto c :ptr FILE, :ptr wchar_t, :_locale_t, :vararg
                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                        else
                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                          _vfwscanf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                        endif
                                                                        if __STDC_WANT_SECURE_LIB__
                                                                          fwscanf_s proto c :ptr FILE, :ptr wchar_t, :vararg
                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                            else
                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                              _vfwscanf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                            endif
                                                                          endif
                                                                          _wscanf_l proto c :ptr wchar_t, :_locale_t, :vararg
                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                            else
                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                              _vfwscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                            endif
                                                                            wscanf proto c :ptr wchar_t, :vararg
                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                              else
                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                _vfwscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                              endif
                                                                              _wscanf_s_l proto c :ptr wchar_t, :_locale_t, :vararg
                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                else
                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                  _vfwscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                endif
                                                                                if __STDC_WANT_SECURE_LIB__
                                                                                  wscanf_s proto c :ptr wchar_t, :vararg
                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                    else
                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                      _vfwscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                    endif
                                                                                  endif
                                                                                  ifndef _CRT_NON_CONFORMING_SWPRINTFS
                                                                                    _SWPRINTFS_DEPRECATED equ <_CRT_DEPRECATE_TEXT ("function has been changed to conform with the ISO C standard, " "adding an extra character count parameter. To use the traditional " "Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")>
                                                                                  else
                                                                                    _SWPRINTFS_DEPRECATED equ <>
                                                                                  endif
                                                                                  @DefProto DllImport, __stdio_common_vswprintf, c,, <:QWORD, :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
                                                                                  @DefProto DllImport, __stdio_common_vswprintf_s, c,, <:QWORD, :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
                                                                                  @DefProto DllImport, __stdio_common_vsnwprintf_s, c,, <:QWORD, :ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
                                                                                  @DefProto DllImport, __stdio_common_vswprintf_p, c,, <:QWORD, :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
                                                                                  _vsnwprintf_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                    else
                                                                                      __stdio_common_vswprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                    endif
                                                                                    _vsnwprintf_s_l proto c :ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                      else
                                                                                        __stdio_common_vsnwprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_MaxCount, :_Format, :_Locale, :_ArgList
                                                                                      endif
                                                                                      _vsnwprintf_s proto c :ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :va_list
                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                        else
                                                                                          _vsnwprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :NULL, :_ArgList
                                                                                        endif
                                                                                        _vsnwprintf proto c :ptr wchar_t, :size_t, :ptr wchar_t, :va_list
                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                          else
                                                                                            _vsnwprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                          endif
                                                                                          _vswprintf_c_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                            else
                                                                                              __stdio_common_vswprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                            endif
                                                                                            _vswprintf_c proto c :ptr wchar_t, :size_t, :ptr wchar_t, :va_list
                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                              else
                                                                                                _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                              endif
                                                                                              _vswprintf_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                else
                                                                                                  _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                endif
                                                                                                __vswprintf_l proto c :ptr wchar_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                  else
                                                                                                    _vswprintf_l proto WIN_STD_CALL_CONV :_Buffer, :size_t :-, :_Format, :_Locale, :_ArgList
                                                                                                  endif
                                                                                                  _vswprintf proto c :ptr wchar_t, :ptr wchar_t, :va_list
                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                    else
                                                                                                      _vswprintf_l proto WIN_STD_CALL_CONV :_Buffer, :size_t :-, :_Format, :NULL, :_ArgList
                                                                                                    endif
                                                                                                    vswprintf proto c :ptr wchar_t, :size_t, :ptr wchar_t, :va_list
                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                      else
                                                                                                        _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                      endif
                                                                                                      _vswprintf_s_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                        else
                                                                                                          __stdio_common_vswprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                        endif
                                                                                                        if __STDC_WANT_SECURE_LIB__
                                                                                                          vswprintf_s proto c :ptr wchar_t, :size_t, :ptr wchar_t, :va_list
                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                            else
                                                                                                              _vswprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                            endif
                                                                                                          endif
                                                                                                          _vswprintf_p_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                            else
                                                                                                              __stdio_common_vswprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                            endif
                                                                                                            _vswprintf_p proto c :ptr wchar_t, :size_t, :ptr wchar_t, :va_list
                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                              else
                                                                                                                _vswprintf_p_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                              endif
                                                                                                              _vscwprintf_l proto c :ptr wchar_t, :_locale_t, :va_list
                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                else
                                                                                                                  __stdio_common_vswprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :NULL, :0, :_Format, :_Locale, :_ArgList
                                                                                                                endif
                                                                                                                _vscwprintf proto c :ptr wchar_t, :va_list
                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                  else
                                                                                                                    _vscwprintf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                  endif
                                                                                                                  _vscwprintf_p_l proto c :ptr wchar_t, :_locale_t, :va_list
                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                    else
                                                                                                                      __stdio_common_vswprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :NULL, :0, :_Format, :_Locale, :_ArgList
                                                                                                                    endif
                                                                                                                    _vscwprintf_p proto c :ptr wchar_t, :va_list
                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                      else
                                                                                                                        _vscwprintf_p_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                      endif
                                                                                                                      __swprintf_l proto c :ptr wchar_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                        else
                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                          __vswprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_Locale, :_ArgList
                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                        endif
                                                                                                                        _swprintf_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                          else
                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                            _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                          endif
                                                                                                                          _swprintf proto c :ptr wchar_t, :ptr wchar_t, :vararg
                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                            else
                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                              __vswprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                            endif
                                                                                                                            swprintf proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                              else
                                                                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                              endif
                                                                                                                              _swprintf_s_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                else
                                                                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                  _vswprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                endif
                                                                                                                                if __STDC_WANT_SECURE_LIB__
                                                                                                                                  swprintf_s proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                    else
                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                      _vswprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                    endif
                                                                                                                                  endif
                                                                                                                                  _swprintf_p_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                    else
                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                      _vswprintf_p_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                    endif
                                                                                                                                    _swprintf_p proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                      else
                                                                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                        _vswprintf_p_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                      endif
                                                                                                                                      _swprintf_c_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                        else
                                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                          _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                        endif
                                                                                                                                        _swprintf_c proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                          else
                                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                            _vswprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                          endif
                                                                                                                                          _snwprintf_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                            else
                                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                              _vsnwprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                            endif
                                                                                                                                            _snwprintf proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                              else
                                                                                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                _vsnwprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                              endif
                                                                                                                                              _snwprintf_s_l proto c :ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                else
                                                                                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                  _vsnwprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                endif
                                                                                                                                                _snwprintf_s proto c :ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                  else
                                                                                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                    _vsnwprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :NULL, :_ArgList
                                                                                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                  endif
                                                                                                                                                  _scwprintf_l proto c :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                    else
                                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                      _vscwprintf_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                    endif
                                                                                                                                                    _scwprintf proto c :ptr wchar_t, :vararg
                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                      else
                                                                                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                        _vscwprintf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                      endif
                                                                                                                                                      _scwprintf_p_l proto c :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                        else
                                                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                          _vscwprintf_p_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                                                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                        endif
                                                                                                                                                        _scwprintf_p proto c :ptr wchar_t, :vararg
                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                          else
                                                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                            _vscwprintf_p_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                          endif
                                                                                                                                                          if  not Defined(RC_INVOKED) and  not Defined(__midl) and  not Defined(_INC_SWPRINTF_INL_)
                                                                                                                                                            ifdef __cplusplus
                                                                                                                                                              ;[...]
                                                                                                                                                            endif
                                                                                                                                                          endif
                                                                                                                                                          if Defined(_CRT_NON_CONFORMING_SWPRINTFS) and  not Defined(__cplusplus)
                                                                                                                                                            swprintf equ <_swprintf>
                                                                                                                                                            vswprintf equ <_vswprintf>
                                                                                                                                                            _swprintf_l equ <__swprintf_l>
                                                                                                                                                            _vswprintf_l equ <__vswprintf_l>
                                                                                                                                                          endif
                                                                                                                                                          @DefProto DllImport, __stdio_common_vswscanf, c,, <:QWORD, :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
                                                                                                                                                          _vswscanf_l proto c :ptr wchar_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                            else
                                                                                                                                                              __stdio_common_vswscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :size_t :-, :_Format, :_Locale, :_ArgList
                                                                                                                                                            endif
                                                                                                                                                            vswscanf proto c :ptr wchar_t, :ptr wchar_t, :va_list
                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                              else
                                                                                                                                                                _vswscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                              endif
                                                                                                                                                              _vswscanf_s_l proto c :ptr wchar_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                else
                                                                                                                                                                  __stdio_common_vswscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :size_t :-, :_Format, :_Locale, :_ArgList
                                                                                                                                                                endif
                                                                                                                                                                if __STDC_WANT_SECURE_LIB__
                                                                                                                                                                  vswscanf_s proto c :ptr wchar_t, :ptr wchar_t, :va_list
                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    else
                                                                                                                                                                      _vswscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                                    endif
                                                                                                                                                                  endif
                                                                                                                                                                  _vsnwscanf_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    else
                                                                                                                                                                      __stdio_common_vswscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                                    endif
                                                                                                                                                                    _vsnwscanf_s_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list
                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                      else
                                                                                                                                                                        __stdio_common_vswscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                                      endif
                                                                                                                                                                      _swscanf_l proto c :ptr wchar_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                        else
                                                                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                          _vswscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_Locale, :_ArgList
                                                                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                        endif
                                                                                                                                                                        swscanf proto c :ptr wchar_t, :ptr wchar_t, :vararg
                                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                          else
                                                                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                            _vswscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                          endif
                                                                                                                                                                          _swscanf_s_l proto c :ptr wchar_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                            else
                                                                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                              _vswscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_Locale, :_ArgList
                                                                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                            endif
                                                                                                                                                                            if __STDC_WANT_SECURE_LIB__
                                                                                                                                                                              swscanf_s proto c :ptr wchar_t, :ptr wchar_t, :vararg
                                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                else
                                                                                                                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                                  _vswscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                endif
                                                                                                                                                                              endif
                                                                                                                                                                              _snwscanf_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                else
                                                                                                                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                                  _vsnwscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                endif
                                                                                                                                                                                _snwscanf proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                  else
                                                                                                                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                                    _vsnwscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                  endif
                                                                                                                                                                                  _snwscanf_s_l proto c :ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg
                                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                    else
                                                                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                                      _vsnwscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                    endif
                                                                                                                                                                                    _snwscanf_s proto c :ptr wchar_t, :size_t, :ptr wchar_t, :vararg
                                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                      else
                                                                                                                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                                        _vsnwscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                      endif
                                                                                                                                                                                      ifdef _M_CEE_MIXED
                                                                                                                                                                                        ;[...]
                                                                                                                                                                                      endif
                                                                                                                                                                                    endif
 