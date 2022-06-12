;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\ucrt\StdIO.h', last modified: 01/09/2021 17:14

ifndef _INC_STDIO
  _INC_STDIO equ <>
  include corecrt.inc
  include corecrt_wstdio.inc
  BUFSIZ equ 512
  _NFILE equ <_NSTREAM_>
  _NSTREAM_ equ 512
  _IOB_ENTRIES equ 3
  EOF equ -1
  _IOFBF equ 0000h
  _IOLBF equ 0040h
  _IONBF equ 0004h
  L_tmpnam equ 260
  if __STDC_WANT_SECURE_LIB__
    L_tmpnam_s equ <L_tmpnam>
  endif
  SEEK_CUR equ 1
  SEEK_END equ 2
  SEEK_SET equ 0
  FILENAME_MAX equ 260
  FOPEN_MAX equ 20
  _SYS_OPEN equ 20
  TMP_MAX equ <_CRT_INT_MAX>
  if __STDC_WANT_SECURE_LIB__
    TMP_MAX_S equ <TMP_MAX>
    _TMP_MAX_S equ <TMP_MAX>
  endif
  fpos_t typedef SQWORD
  if _CRT_FUNCTIONS_REQUIRED
    @DefProto DllImport, _get_stream_buffer_pointers, c,, <:ptr FILE, :ptr ptr ptr SBYTE, :ptr ptr ptr SBYTE, :ptr ptr SDWORD>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, clearerr_s, c,, <:ptr FILE>
      @DefProto DllImport, fopen_s, c,, <:ptr ptr FILE, :ptr SBYTE, :ptr SBYTE>
      @DefProto DllImport, fread_s, c,, <:ptr, :size_t, :size_t, :size_t, :ptr FILE>
      @DefProto DllImport, freopen_s, c,, <:ptr ptr FILE, :ptr SBYTE, :ptr SBYTE, :ptr FILE>
      @DefProto DllImport, gets_s, c,, <:ptr SBYTE, :rsize_t>
      @DefProto DllImport, tmpfile_s, c,, <:ptr ptr FILE>
      @DefProto DllImport, tmpnam_s, c,, <:ptr SBYTE, :rsize_t>
    endif
    @DefProto DllImport, clearerr, c,, <:ptr FILE>
    @DefProto DllImport, fclose, c,, <:ptr FILE>
    @DefProto DllImport, _fcloseall, c,, <>
    @DefProto DllImport, _fdopen, c,, <:SDWORD, :ptr SBYTE>
    @DefProto DllImport, feof, c,, <:ptr FILE>
    @DefProto DllImport, ferror, c,, <:ptr FILE>
    @DefProto DllImport, fflush, c,, <:ptr FILE>
    @DefProto DllImport, fgetc, c,, <:ptr FILE>
    @DefProto DllImport, _fgetchar, c,, <>
    @DefProto DllImport, fgetpos, c,, <:ptr FILE, :ptr fpos_t>
    @DefProto DllImport, fgets, c,, <:ptr SBYTE, :SDWORD, :ptr FILE>
    @DefProto DllImport, _fileno, c,, <:ptr FILE>
    @DefProto DllImport, _flushall, c,, <>
    @DefProto DllImport, fopen, c,, <:ptr SBYTE, :ptr SBYTE>
    @DefProto DllImport, fputc, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, _fputchar, c,, <:SDWORD>
    @DefProto DllImport, fputs, c,, <:ptr SBYTE, :ptr FILE>
    @DefProto DllImport, fread, c,, <:ptr, :size_t, :size_t, :ptr FILE>
    @DefProto DllImport, freopen, c,, <:ptr SBYTE, :ptr SBYTE, :ptr FILE>
    @DefProto DllImport, _fsopen, c,, <:ptr SBYTE, :ptr SBYTE, :SDWORD>
    @DefProto DllImport, fsetpos, c,, <:ptr FILE, :ptr fpos_t>
    @DefProto DllImport, fseek, c,, <:ptr FILE, :SDWORD, :SDWORD>
    @DefProto DllImport, _fseeki64, c,, <:ptr FILE, :SQWORD, :SDWORD>
    @DefProto DllImport, ftell, c,, <:ptr FILE>
    @DefProto DllImport, _ftelli64, c,, <:ptr FILE>
    @DefProto DllImport, fwrite, c,, <:ptr, :size_t, :size_t, :ptr FILE>
    @DefProto DllImport, getc, c,, <:ptr FILE>
    @DefProto DllImport, getchar, c,, <>
    @DefProto DllImport, _getmaxstdio, c,, <>
    @DefProto DllImport, _getw, c,, <:ptr FILE>
    @DefProto DllImport, perror, c,, <:ptr SBYTE>
    if Defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP)
      @DefProto DllImport, _pclose, c,, <:ptr FILE>
      @DefProto DllImport, _popen, c,, <:ptr SBYTE, :ptr SBYTE>
    endif
    @DefProto DllImport, putc, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, putchar, c,, <:SDWORD>
    @DefProto DllImport, puts, c,, <:ptr SBYTE>
    @DefProto DllImport, _putw, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, remove, c,, <:ptr SBYTE>
    @DefProto DllImport, rename, c,, <:ptr SBYTE, :ptr SBYTE>
    @DefProto DllImport, _unlink, c,, <:ptr SBYTE>
    if Defined(_CRT_INTERNAL_NONSTDC_NAMES) and _CRT_INTERNAL_NONSTDC_NAMES
      @DefProto DllImport, unlink, c,, <:ptr SBYTE>
    endif
    @DefProto DllImport, rewind, c,, <:ptr FILE>
    @DefProto DllImport, _rmtmp, c,, <>
    @DefProto DllImport, setbuf, c,, <:ptr FILE, :ptr SBYTE>
    @DefProto DllImport, _setmaxstdio, c,, <:SDWORD>
    @DefProto DllImport, setvbuf, c,, <:ptr FILE, :ptr SBYTE, :SDWORD, :size_t>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _tempnam, c,, <:ptr SBYTE, :ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, tmpfile, c,, <>
    @DefProto DllImport, ungetc, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, _lock_file, c,, <:ptr FILE>
    @DefProto DllImport, _unlock_file, c,, <:ptr FILE>
    @DefProto DllImport, _fclose_nolock, c,, <:ptr FILE>
    @DefProto DllImport, _fflush_nolock, c,, <:ptr FILE>
    @DefProto DllImport, _fgetc_nolock, c,, <:ptr FILE>
    @DefProto DllImport, _fputc_nolock, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, _fread_nolock, c,, <:ptr, :size_t, :size_t, :ptr FILE>
    @DefProto DllImport, _fread_nolock_s, c,, <:ptr, :size_t, :size_t, :size_t, :ptr FILE>
    @DefProto DllImport, _fseek_nolock, c,, <:ptr FILE, :SDWORD, :SDWORD>
    @DefProto DllImport, _fseeki64_nolock, c,, <:ptr FILE, :SQWORD, :SDWORD>
    @DefProto DllImport, _ftell_nolock, c,, <:ptr FILE>
    @DefProto DllImport, _ftelli64_nolock, c,, <:ptr FILE>
    @DefProto DllImport, _fwrite_nolock, c,, <:ptr, :size_t, :size_t, :ptr FILE>
    @DefProto DllImport, _getc_nolock, c,, <:ptr FILE>
    @DefProto DllImport, _putc_nolock, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, _ungetc_nolock, c,, <:SDWORD, :ptr FILE>
    _getchar_nolock macro 
      exitm <_getc_nolock(stdin)>
    endm
    _putchar_nolock macro _Ch
      exitm <_putc_nolock(_Ch, stdout)>
    endm
    _getwchar_nolock macro 
      exitm <_getwc_nolock(stdin)>
    endm
    _putwchar_nolock macro _Ch
      exitm <_putwc_nolock(_Ch, stdout)>
    endm
    if Defined(_CRT_DISABLE_PERFCRIT_LOCKS) and  not Defined(_DLL)
      fclose macro _Stream
        exitm <_fclose_nolock (_Stream)>
      endm
      fflush macro _Stream
        exitm <_fflush_nolock (_Stream)>
      endm
      fgetc macro _Stream
        exitm <_fgetc_nolock(_Stream)>
      endm
      fputc macro _Ch, _Stream
        exitm <_fputc_nolock(_Ch, _Stream)>
      endm
      fread macro _DstBuf, _ElementSize, _Count, _Stream
        exitm <_fread_nolock (_DstBuf, _ElementSize, _Count, _Stream)>
      endm
      fread_s macro _DstBuf, _DstSize, _ElementSize, _Count, _Stream
        exitm <_fread_nolock_s (_DstBuf, _DstSize, _ElementSize, _Count, _Stream)>
      endm
      fseek macro _Stream, _Offset, _Origin
        exitm <_fseek_nolock (_Stream, _Offset, _Origin)>
      endm
      _fseeki64 macro _Stream, _Offset, _Origin
        exitm <_fseeki64_nolock (_Stream, _Offset, _Origin)>
      endm
      ftell macro _Stream
        exitm <_ftell_nolock (_Stream)>
      endm
      _ftelli64 macro _Stream
        exitm <_ftelli64_nolock (_Stream)>
      endm
      fwrite macro _SrcBuf, _ElementSize, _Count, _Stream
        exitm <_fwrite_nolock (_SrcBuf, _ElementSize, _Count, _Stream)>
      endm
      getc macro _Stream
        exitm <_getc_nolock(_Stream)>
      endm
      putc macro _Ch, _Stream
        exitm <_putc_nolock(_Ch, _Stream)>
      endm
      ungetc macro _Ch, _Stream
        exitm <_ungetc_nolock (_Ch, _Stream)>
      endm
    endif
    @DefProto DllImport, __p__commode, c,, <>
    ifdef _CRT_DECLARE_GLOBAL_VARIABLES_DIRECTLY
      externdef _commode:SDWORD
    else
      _commode equ <(* __p__commode ())>
    endif
    if Defined(_M_CEE_MIXED)
      ;[...]
    endif
    @DefProto DllImport, __stdio_common_vfprintf, c,, <:QWORD, :ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, __stdio_common_vfprintf_s, c,, <:QWORD, :ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, __stdio_common_vfprintf_p, c,, <:QWORD, :ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
    _vfprintf_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :va_list
    if Defined(_NO_CRT_STDIO_INLINE)
      if Defined(_NO_CRT_STDIO_INLINE)
      else
        __stdio_common_vfprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
      endif
      vfprintf proto c :ptr FILE, :ptr SBYTE, :va_list
      if Defined(_NO_CRT_STDIO_INLINE)
        if Defined(_NO_CRT_STDIO_INLINE)
        else
          _vfprintf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
        endif
        _vfprintf_s_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :va_list
        if Defined(_NO_CRT_STDIO_INLINE)
          if Defined(_NO_CRT_STDIO_INLINE)
          else
            __stdio_common_vfprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
          endif
          if __STDC_WANT_SECURE_LIB__
            vfprintf_s proto c :ptr FILE, :ptr SBYTE, :va_list
            if Defined(_NO_CRT_STDIO_INLINE)
              if Defined(_NO_CRT_STDIO_INLINE)
              else
                _vfprintf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
              endif
            endif
            _vfprintf_p_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :va_list
            if Defined(_NO_CRT_STDIO_INLINE)
              if Defined(_NO_CRT_STDIO_INLINE)
              else
                __stdio_common_vfprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
              endif
              _vfprintf_p proto c :ptr FILE, :ptr SBYTE, :va_list
              if Defined(_NO_CRT_STDIO_INLINE)
                if Defined(_NO_CRT_STDIO_INLINE)
                else
                  _vfprintf_p_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                endif
                _vprintf_l proto c :ptr SBYTE, :_locale_t, :va_list
                if Defined(_NO_CRT_STDIO_INLINE)
                  if Defined(_NO_CRT_STDIO_INLINE)
                  else
                    _vfprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                  endif
                  vprintf proto c :ptr SBYTE, :va_list
                  if Defined(_NO_CRT_STDIO_INLINE)
                    if Defined(_NO_CRT_STDIO_INLINE)
                    else
                      _vfprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                    endif
                    _vprintf_s_l proto c :ptr SBYTE, :_locale_t, :va_list
                    if Defined(_NO_CRT_STDIO_INLINE)
                      if Defined(_NO_CRT_STDIO_INLINE)
                      else
                        _vfprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                      endif
                      if __STDC_WANT_SECURE_LIB__
                        vprintf_s proto c :ptr SBYTE, :va_list
                        if Defined(_NO_CRT_STDIO_INLINE)
                          if Defined(_NO_CRT_STDIO_INLINE)
                          else
                            _vfprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                          endif
                        endif
                        _vprintf_p_l proto c :ptr SBYTE, :_locale_t, :va_list
                        if Defined(_NO_CRT_STDIO_INLINE)
                          if Defined(_NO_CRT_STDIO_INLINE)
                          else
                            _vfprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                          endif
                          _vprintf_p proto c :ptr SBYTE, :va_list
                          if Defined(_NO_CRT_STDIO_INLINE)
                            if Defined(_NO_CRT_STDIO_INLINE)
                            else
                              _vfprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                            endif
                            _fprintf_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :vararg
                            if Defined(_NO_CRT_STDIO_INLINE)
                              if Defined(_NO_CRT_STDIO_INLINE)
                              else
                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                _vfprintf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                              endif
                              fprintf proto c :ptr FILE, :ptr SBYTE, :vararg
                              if Defined(_NO_CRT_STDIO_INLINE)
                                if Defined(_NO_CRT_STDIO_INLINE)
                                else
                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                  _vfprintf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                endif
                                @DefProto DllImport, _set_printf_count_output, c,, <:SDWORD>
                                @DefProto DllImport, _get_printf_count_output, c,, <>
                                _fprintf_s_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :vararg
                                if Defined(_NO_CRT_STDIO_INLINE)
                                  if Defined(_NO_CRT_STDIO_INLINE)
                                  else
                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                    _vfprintf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                  endif
                                  if __STDC_WANT_SECURE_LIB__
                                    fprintf_s proto c :ptr FILE, :ptr SBYTE, :vararg
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                      else
                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                        _vfprintf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                      endif
                                    endif
                                    _fprintf_p_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :vararg
                                    if Defined(_NO_CRT_STDIO_INLINE)
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                      else
                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                        _vfprintf_p_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                      endif
                                      _fprintf_p proto c :ptr FILE, :ptr SBYTE, :vararg
                                      if Defined(_NO_CRT_STDIO_INLINE)
                                        if Defined(_NO_CRT_STDIO_INLINE)
                                        else
                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                          _vfprintf_p_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                        endif
                                        _printf_l proto c :ptr SBYTE, :_locale_t, :vararg
                                        if Defined(_NO_CRT_STDIO_INLINE)
                                          if Defined(_NO_CRT_STDIO_INLINE)
                                          else
                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                            _vfprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                          endif
                                          printf proto c :ptr SBYTE, :vararg
                                          if Defined(_NO_CRT_STDIO_INLINE)
                                            if Defined(_NO_CRT_STDIO_INLINE)
                                            else
                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                              _vfprintf_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                            endif
                                            _printf_s_l proto c :ptr SBYTE, :_locale_t, :vararg
                                            if Defined(_NO_CRT_STDIO_INLINE)
                                              if Defined(_NO_CRT_STDIO_INLINE)
                                              else
                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                _vfprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                              endif
                                              if __STDC_WANT_SECURE_LIB__
                                                printf_s proto c :ptr SBYTE, :vararg
                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                  else
                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                    _vfprintf_s_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                  endif
                                                endif
                                                _printf_p_l proto c :ptr SBYTE, :_locale_t, :vararg
                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                  else
                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                    _vfprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :_Locale, :_ArgList
                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                  endif
                                                  _printf_p proto c :ptr SBYTE, :vararg
                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                    else
                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                      _vfprintf_p_l proto WIN_STD_CALL_CONV :stdout, :_Format, :NULL, :_ArgList
                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                    endif
                                                    @DefProto DllImport, __stdio_common_vfscanf, c,, <:QWORD, :ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
                                                    _vfscanf_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :va_list
                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                      else
                                                        __stdio_common_vfscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
                                                      endif
                                                      vfscanf proto c :ptr FILE, :ptr SBYTE, :va_list
                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                        else
                                                          _vfscanf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                        endif
                                                        _vfscanf_s_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :va_list
                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                          else
                                                            __stdio_common_vfscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Stream, :_Format, :_Locale, :_ArgList
                                                          endif
                                                          if __STDC_WANT_SECURE_LIB__
                                                            vfscanf_s proto c :ptr FILE, :ptr SBYTE, :va_list
                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                              else
                                                                _vfscanf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                              endif
                                                            endif
                                                            _vscanf_l proto c :ptr SBYTE, :_locale_t, :va_list
                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                              else
                                                                _vfscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                              endif
                                                              vscanf proto c :ptr SBYTE, :va_list
                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                else
                                                                  _vfscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                endif
                                                                _vscanf_s_l proto c :ptr SBYTE, :_locale_t, :va_list
                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                  else
                                                                    _vfscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                                  endif
                                                                  if __STDC_WANT_SECURE_LIB__
                                                                    vscanf_s proto c :ptr SBYTE, :va_list
                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                      else
                                                                        _vfscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                      endif
                                                                    endif
                                                                    _fscanf_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :vararg
                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                      else
                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                        _vfscanf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                      endif
                                                                      fscanf proto c :ptr FILE, :ptr SBYTE, :vararg
                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                        else
                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                          _vfscanf_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                        endif
                                                                        _fscanf_s_l proto c :ptr FILE, :ptr SBYTE, :_locale_t, :vararg
                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                          else
                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                            _vfscanf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :_Locale, :_ArgList
                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                          endif
                                                                          if __STDC_WANT_SECURE_LIB__
                                                                            fscanf_s proto c :ptr FILE, :ptr SBYTE, :vararg
                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                              else
                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                _vfscanf_s_l proto WIN_STD_CALL_CONV :_Stream, :_Format, :NULL, :_ArgList
                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                              endif
                                                                            endif
                                                                            _scanf_l proto c :ptr SBYTE, :_locale_t, :vararg
                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                              else
                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                _vfscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                              endif
                                                                              scanf proto c :ptr SBYTE, :vararg
                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                else
                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                  _vfscanf_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                endif
                                                                                _scanf_s_l proto c :ptr SBYTE, :_locale_t, :vararg
                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                  else
                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                    _vfscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :_Locale, :_ArgList
                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                  endif
                                                                                  if __STDC_WANT_SECURE_LIB__
                                                                                    scanf_s proto c :ptr SBYTE, :vararg
                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                      else
                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                        _vfscanf_s_l proto WIN_STD_CALL_CONV :stdin, :_Format, :NULL, :_ArgList
                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                      endif
                                                                                    endif
                                                                                    @DefProto DllImport, __stdio_common_vsprintf, c,, <:QWORD, :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
                                                                                    @DefProto DllImport, __stdio_common_vsprintf_s, c,, <:QWORD, :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
                                                                                    @DefProto DllImport, __stdio_common_vsnprintf_s, c,, <:QWORD, :ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :_locale_t, :va_list>
                                                                                    @DefProto DllImport, __stdio_common_vsprintf_p, c,, <:QWORD, :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
                                                                                    _vsnprintf_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list
                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                      else
                                                                                        __stdio_common_vsprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                      endif
                                                                                      _vsnprintf proto c :ptr SBYTE, :size_t, :ptr SBYTE, :va_list
                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                        else
                                                                                          _vsnprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                        endif
                                                                                        if Defined(vsnprintf)
                                                                                          vsnprintf equ <Do not define vsnprintf as a macro>
                                                                                          .err <Macro definition of vsnprintf conflicts with Standard Library function declaration>
                                                                                        endif
                                                                                        vsnprintf proto c :ptr SBYTE, :size_t, :ptr SBYTE, :va_list
                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                          else
                                                                                            __stdio_common_vsprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                          endif
                                                                                          _vsprintf_l proto c :ptr SBYTE, :ptr SBYTE, :_locale_t, :va_list
                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                            else
                                                                                              _vsnprintf_l proto WIN_STD_CALL_CONV :_Buffer, :size_t :-, :_Format, :_Locale, :_ArgList
                                                                                            endif
                                                                                            vsprintf proto c :ptr SBYTE, :ptr SBYTE, :va_list
                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                              else
                                                                                                _vsnprintf_l proto WIN_STD_CALL_CONV :_Buffer, :size_t :-, :_Format, :NULL, :_ArgList
                                                                                              endif
                                                                                              _vsprintf_s_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list
                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                else
                                                                                                  __stdio_common_vsprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                endif
                                                                                                if __STDC_WANT_SECURE_LIB__
                                                                                                  vsprintf_s proto c :ptr SBYTE, :size_t, :ptr SBYTE, :va_list
                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                    else
                                                                                                      _vsprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                    endif
                                                                                                  endif
                                                                                                  _vsprintf_p_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list
                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                    else
                                                                                                      __stdio_common_vsprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                    endif
                                                                                                    _vsprintf_p proto c :ptr SBYTE, :size_t, :ptr SBYTE, :va_list
                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                      else
                                                                                                        _vsprintf_p_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                      endif
                                                                                                      _vsnprintf_s_l proto c :ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :_locale_t, :va_list
                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                        else
                                                                                                          __stdio_common_vsnprintf_s proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_MaxCount, :_Format, :_Locale, :_ArgList
                                                                                                        endif
                                                                                                        _vsnprintf_s proto c :ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :va_list
                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                          else
                                                                                                            _vsnprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :NULL, :_ArgList
                                                                                                          endif
                                                                                                          if __STDC_WANT_SECURE_LIB__
                                                                                                            vsnprintf_s proto c :ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :va_list
                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                              else
                                                                                                                _vsnprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :NULL, :_ArgList
                                                                                                              endif
                                                                                                            endif
                                                                                                            _vscprintf_l proto c :ptr SBYTE, :_locale_t, :va_list
                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                              else
                                                                                                                __stdio_common_vsprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :NULL, :0, :_Format, :_Locale, :_ArgList
                                                                                                              endif
                                                                                                              _vscprintf proto c :ptr SBYTE, :va_list
                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                else
                                                                                                                  _vscprintf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                endif
                                                                                                                _vscprintf_p_l proto c :ptr SBYTE, :_locale_t, :va_list
                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                  else
                                                                                                                    __stdio_common_vsprintf_p proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :NULL, :0, :_Format, :_Locale, :_ArgList
                                                                                                                  endif
                                                                                                                  _vscprintf_p proto c :ptr SBYTE, :va_list
                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                    else
                                                                                                                      _vscprintf_p_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                    endif
                                                                                                                    _vsnprintf_c_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list
                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                      else
                                                                                                                        __stdio_common_vsprintf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                      endif
                                                                                                                      _vsnprintf_c proto c :ptr SBYTE, :size_t, :ptr SBYTE, :va_list
                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                        else
                                                                                                                          _vsnprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                        endif
                                                                                                                        _sprintf_l proto c :ptr SBYTE, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                          else
                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                            _vsprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_Locale, :_ArgList
                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                          endif
                                                                                                                          sprintf proto c :ptr SBYTE, :ptr SBYTE, :vararg
                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                            else
                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                              _vsprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                            endif
                                                                                                                            _sprintf_s_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                              else
                                                                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                _vsprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                              endif
                                                                                                                              if __STDC_WANT_SECURE_LIB__
                                                                                                                                sprintf_s proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                  else
                                                                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                    _vsprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                  endif
                                                                                                                                endif
                                                                                                                                _sprintf_p_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                  else
                                                                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                    _vsprintf_p_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                  endif
                                                                                                                                  _sprintf_p proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                    else
                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                      _vsprintf_p_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                    endif
                                                                                                                                    _snprintf_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                      else
                                                                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                        _vsnprintf_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                      endif
                                                                                                                                      if Defined(snprintf)
                                                                                                                                        snprintf equ <Do not define snprintf as a macro>
                                                                                                                                        .err <Macro definition of snprintf conflicts with Standard Library function declaration>
                                                                                                                                      endif
                                                                                                                                      snprintf proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                        else
                                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                          vsnprintf proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_ArgList
                                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                        endif
                                                                                                                                        _snprintf proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                          else
                                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                            _vsnprintf proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_ArgList
                                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                          endif
                                                                                                                                          _snprintf_c_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                            else
                                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                              _vsnprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                            endif
                                                                                                                                            _snprintf_c proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                              else
                                                                                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                _vsnprintf_c_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                              endif
                                                                                                                                              _snprintf_s_l proto c :ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                else
                                                                                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                  _vsnprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                endif
                                                                                                                                                _snprintf_s proto c :ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :vararg
                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                  else
                                                                                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                    _vsnprintf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_BufferCount, :_MaxCount, :_Format, :NULL, :_ArgList
                                                                                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                  endif
                                                                                                                                                  _scprintf_l proto c :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                    else
                                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                      _vscprintf_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                    endif
                                                                                                                                                    _scprintf proto c :ptr SBYTE, :vararg
                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                      else
                                                                                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                        _vscprintf_l proto WIN_STD_CALL_CONV :_Format, :NULL, :_ArgList
                                                                                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                      endif
                                                                                                                                                      _scprintf_p_l proto c :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                        else
                                                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                          _vscprintf_p_l proto WIN_STD_CALL_CONV :_Format, :_Locale, :_ArgList
                                                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                        endif
                                                                                                                                                        _scprintf_p proto c :ptr SBYTE, :vararg
                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                          else
                                                                                                                                                            __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                            _vscprintf_p proto WIN_STD_CALL_CONV :_Format, :_ArgList
                                                                                                                                                            __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                          endif
                                                                                                                                                          @DefProto DllImport, __stdio_common_vsscanf, c,, <:QWORD, :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
                                                                                                                                                          _vsscanf_l proto c :ptr SBYTE, :ptr SBYTE, :_locale_t, :va_list
                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                            else
                                                                                                                                                              __stdio_common_vsscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :size_t :-, :_Format, :_Locale, :_ArgList
                                                                                                                                                            endif
                                                                                                                                                            vsscanf proto c :ptr SBYTE, :ptr SBYTE, :va_list
                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                              else
                                                                                                                                                                _vsscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                              endif
                                                                                                                                                              _vsscanf_s_l proto c :ptr SBYTE, :ptr SBYTE, :_locale_t, :va_list
                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                else
                                                                                                                                                                  __stdio_common_vsscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :size_t :-, :_Format, :_Locale, :_ArgList
                                                                                                                                                                endif
                                                                                                                                                                if __STDC_WANT_SECURE_LIB__
                                                                                                                                                                  vsscanf_s proto c :ptr SBYTE, :ptr SBYTE, :va_list
                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    else
                                                                                                                                                                      _vsscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                                    endif
                                                                                                                                                                  endif
                                                                                                                                                                  _sscanf_l proto c :ptr SBYTE, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                    else
                                                                                                                                                                      __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                      _vsscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_Locale, :_ArgList
                                                                                                                                                                      __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                    endif
                                                                                                                                                                    sscanf proto c :ptr SBYTE, :ptr SBYTE, :vararg
                                                                                                                                                                    if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                      else
                                                                                                                                                                        __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                        _vsscanf_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :NULL, :_ArgList
                                                                                                                                                                        __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                      endif
                                                                                                                                                                      _sscanf_s_l proto c :ptr SBYTE, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                                                      if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                        if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                        else
                                                                                                                                                                          __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                          _vsscanf_s_l proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_Locale, :_ArgList
                                                                                                                                                                          __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                        endif
                                                                                                                                                                        if __STDC_WANT_SECURE_LIB__
                                                                                                                                                                          sscanf_s proto c :ptr SBYTE, :ptr SBYTE, :vararg
                                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                            else
                                                                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                              vsscanf_s proto WIN_STD_CALL_CONV :_Buffer, :_Format, :_ArgList
                                                                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                            endif
                                                                                                                                                                          endif
                                                                                                                                                                          _snscanf_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                                                          if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                            else
                                                                                                                                                                              __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                              __stdio_common_vsscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                                              __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                            endif
                                                                                                                                                                            _snscanf proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                                                            if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                              else
                                                                                                                                                                                __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                                __stdio_common_vsscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                                                                __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                              endif
                                                                                                                                                                              _snscanf_s_l proto c :ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg
                                                                                                                                                                              if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                else
                                                                                                                                                                                  __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Locale
                                                                                                                                                                                  __stdio_common_vsscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :_Locale, :_ArgList
                                                                                                                                                                                  __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                endif
                                                                                                                                                                                _snscanf_s proto c :ptr SBYTE, :size_t, :ptr SBYTE, :vararg
                                                                                                                                                                                if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                  if Defined(_NO_CRT_STDIO_INLINE)
                                                                                                                                                                                  else
                                                                                                                                                                                    __crt_va_start proto WIN_STD_CALL_CONV :_ArgList, :_Format
                                                                                                                                                                                    __stdio_common_vsscanf proto WIN_STD_CALL_CONV :_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, :_Buffer, :_BufferCount, :_Format, :NULL, :_ArgList
                                                                                                                                                                                    __crt_va_end proto WIN_STD_CALL_CONV :_ArgList
                                                                                                                                                                                  endif
                                                                                                                                                                                  if Defined(_M_CEE_MIXED)
                                                                                                                                                                                    ;[...]
                                                                                                                                                                                  endif
                                                                                                                                                                                  if Defined(_CRT_INTERNAL_NONSTDC_NAMES) and _CRT_INTERNAL_NONSTDC_NAMES
                                                                                                                                                                                    SYS_OPEN equ <_SYS_OPEN>
                                                                                                                                                                                    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
                                                                                                                                                                                    endif
                                                                                                                                                                                    @DefProto DllImport, tempnam, c,, <:ptr SBYTE, :ptr SBYTE>
                                                                                                                                                                                    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
                                                                                                                                                                                    endif
                                                                                                                                                                                    @DefProto DllImport, fcloseall, c,, <>
                                                                                                                                                                                    @DefProto DllImport, fdopen, c,, <:SDWORD, :ptr SBYTE>
                                                                                                                                                                                    @DefProto DllImport, fgetchar, c,, <>
                                                                                                                                                                                    @DefProto DllImport, fileno, c,, <:ptr FILE>
                                                                                                                                                                                    @DefProto DllImport, flushall, c,, <>
                                                                                                                                                                                    @DefProto DllImport, fputchar, c,, <:SDWORD>
                                                                                                                                                                                    @DefProto DllImport, getw, c,, <:ptr FILE>
                                                                                                                                                                                    @DefProto DllImport, putw, c,, <:SDWORD, :ptr FILE>
                                                                                                                                                                                    @DefProto DllImport, rmtmp, c,, <>
                                                                                                                                                                                  endif
                                                                                                                                                                                endif
                                                                                                                                                                              endif
 