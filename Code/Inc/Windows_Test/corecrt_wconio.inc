;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\ucrt\corecrt_wconio.h', last modified: 25/10/2021 15:09

include corecrt.inc
include corecrt_stdio_config.inc
WEOF equ (0FFFFh)
ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  @DefProto DllImport, _cgetws_s, c,, <:ptr wchar_t, :size_t, :ptr size_t>
  @DefProto DllImport, _cputws, c,, <:ptr wchar_t>
  @DefProto DllImport, _getwch, c,, <>
  @DefProto DllImport, _getwche, c,, <>
  @DefProto DllImport, _putwch, c,, <:wchar_t>
  @DefProto DllImport, _ungetwch, c,, <:wint_t>
  @DefProto DllImport, _getwch_nolock, c,, <>
  @DefProto DllImport, _getwche_nolock, c,, <>
  @DefProto DllImport, _putwch_nolock, c,, <:wchar_t>
  @DefProto DllImport, _ungetwch_nolock, c,, <:wint_t>
  @DefProto DllImport, __conio_common_vcwprintf, c,, <:QWORD, :ptr wchar_t, :_locale_t, :va_list>
  @DefProto DllImport, __conio_common_vcwprintf_s, c,, <:QWORD, :ptr wchar_t, :_locale_t, :va_list>
  @DefProto DllImport, __conio_common_vcwprintf_p, c,, <:QWORD, :ptr wchar_t, :_locale_t, :va_list>
  _vcwprintf_l proto c :ptr wchar_t, :_locale_t, :va_list
  if Defined(_NO_CRT_STDIO_INLINE)
    if Defined(_NO_CRT_STDIO_INLINE)
    else
      __conio_common_vcwprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Format, :_Locale, :_ArgList
    endif
    _vcwprintf proto c :ptr wchar_t, :va_list
    if Defined(_NO_CRT_STDIO_INLINE)
      if Defined(_NO_CRT_STDIO_INLINE)
      else
        _vcwprintf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
      endif
      _vcwprintf_s_l proto c :ptr wchar_t, :_locale_t, :va_list
      if Defined(_NO_CRT_STDIO_INLINE)
        if Defined(_NO_CRT_STDIO_INLINE)
        else
          __conio_common_vcwprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Format, :_Locale, :_ArgList
        endif
        _vcwprintf_s proto c :ptr wchar_t, :va_list
        if Defined(_NO_CRT_STDIO_INLINE)
          if Defined(_NO_CRT_STDIO_INLINE)
          else
            _vcwprintf_s_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
          endif
          _vcwprintf_p_l proto c :ptr wchar_t, :_locale_t, :va_list
          if Defined(_NO_CRT_STDIO_INLINE)
            if Defined(_NO_CRT_STDIO_INLINE)
            else
              __conio_common_vcwprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Format, :_Locale, :_ArgList
            endif
            _vcwprintf_p proto c :ptr wchar_t, :va_list
            if Defined(_NO_CRT_STDIO_INLINE)
              if Defined(_NO_CRT_STDIO_INLINE)
              else
                _vcwprintf_p_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
              endif
              _cwprintf_l proto c :ptr wchar_t, :_locale_t, :vararg
              if Defined(_NO_CRT_STDIO_INLINE)
                if Defined(_NO_CRT_STDIO_INLINE)
                else
                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                  _vcwprintf_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                endif
                _cwprintf proto c :ptr wchar_t, :vararg
                if Defined(_NO_CRT_STDIO_INLINE)
                  if Defined(_NO_CRT_STDIO_INLINE)
                  else
                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                    _vcwprintf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                  endif
                  _cwprintf_s_l proto c :ptr wchar_t, :_locale_t, :vararg
                  if Defined(_NO_CRT_STDIO_INLINE)
                    if Defined(_NO_CRT_STDIO_INLINE)
                    else
                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                      _vcwprintf_s_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                    endif
                    _cwprintf_s proto c :ptr wchar_t, :vararg
                    if Defined(_NO_CRT_STDIO_INLINE)
                      if Defined(_NO_CRT_STDIO_INLINE)
                      else
                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                        _vcwprintf_s_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                      endif
                      _cwprintf_p_l proto c :ptr wchar_t, :_locale_t, :vararg
                      if Defined(_NO_CRT_STDIO_INLINE)
                        if Defined(_NO_CRT_STDIO_INLINE)
                        else
                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                          _vcwprintf_p_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                        endif
                        _cwprintf_p proto c :ptr wchar_t, :vararg
                        if Defined(_NO_CRT_STDIO_INLINE)
                          if Defined(_NO_CRT_STDIO_INLINE)
                          else
                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                            _vcwprintf_p_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                          endif
                          @DefProto DllImport, __conio_common_vcwscanf, c,, <:QWORD, :ptr wchar_t, :_locale_t, :va_list>
                          _vcwscanf_l proto c :ptr wchar_t, :_locale_t, :va_list
                          if Defined(_NO_CRT_STDIO_INLINE)
                            if Defined(_NO_CRT_STDIO_INLINE)
                            else
                              __conio_common_vcwscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Format, :_Locale, :_ArgList
                            endif
                            _vcwscanf proto c :ptr wchar_t, :va_list
                            if Defined(_NO_CRT_STDIO_INLINE)
                              if Defined(_NO_CRT_STDIO_INLINE)
                              else
                                _vcwscanf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                              endif
                              _vcwscanf_s_l proto c :ptr wchar_t, :_locale_t, :va_list
                              if Defined(_NO_CRT_STDIO_INLINE)
                                if Defined(_NO_CRT_STDIO_INLINE)
                                else
                                  __conio_common_vcwscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Format, :_Locale, :_ArgList
                                endif
                                _vcwscanf_s proto c :ptr wchar_t, :va_list
                                if Defined(_NO_CRT_STDIO_INLINE)
                                  if Defined(_NO_CRT_STDIO_INLINE)
                                  else
                                    _vcwscanf_s_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                  endif
                                  _cwscanf_l proto c :ptr wchar_t, :_locale_t, :vararg
                                  if Defined(_NO_CRT_STDIO_INLINE)
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                    else
                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                      _vcwscanf_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                    endif
                                    _cwscanf proto c :ptr wchar_t, :vararg
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                      else
                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                        _vcwscanf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                      endif
                                      _cwscanf_s_l proto c :ptr wchar_t, :_locale_t, :vararg
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                        if Defined(_NO_CRT_STDIO_INLINE)
                                        else
                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                          _vcwscanf_s_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                        endif
                                        _cwscanf_s proto c :ptr wchar_t, :vararg
                                        if Defined(_NO_CRT_STDIO_INLINE)
                                          if Defined(_NO_CRT_STDIO_INLINE)
                                          else
                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                            _vcwscanf_s_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                          endif
                                        endif
 