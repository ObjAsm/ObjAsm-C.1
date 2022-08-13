;Include file created by h2incX, Version 1.2.0, 02/12/2021 16:49
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\_MySoftware_\ObjAsm\Projects\Experimental\h2IncX\10.0.22000.0\cppwinrt\ucrt\mbstring.h', last modified: 01/09/2021 17:14

ifndef _INC_MBSTRING
  _INC_MBSTRING equ <>
  include corecrt.inc
  ifndef _FILE_DEFINED
    _FILE_DEFINED equ <>
    FILE struct
      _Placeholder POINTER ?
    FILE ends

    _iobuf typedef FILE
  endif
  ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    @DefProto DllImport, _mbsdup, c,, <:ptr BYTE>
    @DefProto DllImport, _mbbtombc, c,, <:DWORD>
    @DefProto DllImport, _mbbtombc_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbbtype, c,, <:BYTE, :SDWORD>
    @DefProto DllImport, _mbbtype_l, c,, <:BYTE, :SDWORD, :_locale_t>
    @DefProto DllImport, _mbctombb, c,, <:DWORD>
    @DefProto DllImport, _mbctombb_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbsbtype, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbsbtype_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbscat_s, c,, <:ptr BYTE, :size_t, :ptr BYTE>
    @DefProto DllImport, _mbscat_s_l, c,, <:ptr BYTE, :size_t, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbschr, c,, <:ptr BYTE, :DWORD>
    @DefProto DllImport, _mbschr_l, c,, <:ptr BYTE, :DWORD, :_locale_t>
    @DefProto DllImport, _mbscmp, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbscmp_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbscoll, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbscoll_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbscpy_s, c,, <:ptr BYTE, :size_t, :ptr BYTE>
    @DefProto DllImport, _mbscpy_s_l, c,, <:ptr BYTE, :size_t, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbscspn, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbscspn_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsdec, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbsdec_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsicmp, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbsicmp_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsicoll, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbsicoll_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsinc, c,, <:ptr BYTE>
    @DefProto DllImport, _mbsinc_l, c,, <:ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbslen, c,, <:ptr BYTE>
    @DefProto DllImport, _mbslen_l, c,, <:ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsnlen, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnlen_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbslwr_s, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbslwr_s_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbcat_s, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbcat_s_l, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbcmp, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbcmp_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbcoll, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbcoll_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbcnt, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbcnt_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbcpy_s, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbcpy_s_l, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbicmp, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbicmp_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbicoll, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnbicoll_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnbset_s, c,, <:ptr BYTE, :size_t, :DWORD, :size_t>
    @DefProto DllImport, _mbsnbset_s_l, c,, <:ptr BYTE, :size_t, :DWORD, :size_t, :_locale_t>
    @DefProto DllImport, _mbsncat_s, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsncat_s_l, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnccnt, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnccnt_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsncmp, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsncmp_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsncoll, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsncoll_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsncpy_s, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsncpy_s_l, c,, <:ptr BYTE, :size_t, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnextc, c,, <:ptr BYTE>
    @DefProto DllImport, _mbsnextc_l, c,, <:ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsnicmp, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnicmp_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnicoll, c,, <:ptr BYTE, :ptr BYTE, :size_t>
    @DefProto DllImport, _mbsnicoll_l, c,, <:ptr BYTE, :ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsninc, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbsninc_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbsnset_s, c,, <:ptr BYTE, :size_t, :DWORD, :size_t>
    @DefProto DllImport, _mbsnset_s_l, c,, <:ptr BYTE, :size_t, :DWORD, :size_t, :_locale_t>
    @DefProto DllImport, _mbspbrk, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbspbrk_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsrchr, c,, <:ptr BYTE, :DWORD>
    @DefProto DllImport, _mbsrchr_l, c,, <:ptr BYTE, :DWORD, :_locale_t>
    @DefProto DllImport, _mbsrev, c,, <:ptr BYTE>
    @DefProto DllImport, _mbsrev_l, c,, <:ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsset_s, c,, <:ptr BYTE, :size_t, :DWORD>
    @DefProto DllImport, _mbsset_s_l, c,, <:ptr BYTE, :size_t, :DWORD, :_locale_t>
    @DefProto DllImport, _mbsspn, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbsspn_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsspnp, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbsspnp_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsstr, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbsstr_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbstok, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbstok_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbstok_s, c,, <:ptr BYTE, :ptr BYTE, :ptr ptr BYTE>
    @DefProto DllImport, _mbstok_s_l, c,, <:ptr BYTE, :ptr BYTE, :ptr ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbsupr_s, c,, <:ptr BYTE, :size_t>
    @DefProto DllImport, _mbsupr_s_l, c,, <:ptr BYTE, :size_t, :_locale_t>
    @DefProto DllImport, _mbclen, c,, <:ptr BYTE>
    @DefProto DllImport, _mbclen_l, c,, <:ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbccpy, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _mbccpy_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _mbccpy_s, c,, <:ptr BYTE, :size_t, :ptr SDWORD, :ptr BYTE>
    @DefProto DllImport, _mbccpy_s_l, c,, <:ptr BYTE, :size_t, :ptr SDWORD, :ptr BYTE, :_locale_t>
    _mbccmp macro _cpc1, _cpc2
      exitm <_mbsncmp ((_cpc1), (_cpc2), 1)>
    endm
    ifndef _EXCLUDE_MBSTRING_CONST_CORRECT_OVERLOADS
      ifdef __cplusplus
        ;[...]
      endif
    endif
    @DefProto DllImport, _ismbcalnum, c,, <:DWORD>
    @DefProto DllImport, _ismbcalpha, c,, <:DWORD>
    @DefProto DllImport, _ismbcdigit, c,, <:DWORD>
    @DefProto DllImport, _ismbcgraph, c,, <:DWORD>
    @DefProto DllImport, _ismbclegal, c,, <:DWORD>
    @DefProto DllImport, _ismbclower, c,, <:DWORD>
    @DefProto DllImport, _ismbcprint, c,, <:DWORD>
    @DefProto DllImport, _ismbcpunct, c,, <:DWORD>
    @DefProto DllImport, _ismbcblank, c,, <:DWORD>
    @DefProto DllImport, _ismbcspace, c,, <:DWORD>
    @DefProto DllImport, _ismbcupper, c,, <:DWORD>
    @DefProto DllImport, _ismbcalnum_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcalpha_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcdigit_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcgraph_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbclegal_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbclower_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcprint_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcpunct_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcblank_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcspace_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcupper_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbctolower, c,, <:DWORD>
    @DefProto DllImport, _mbctoupper, c,, <:DWORD>
    @DefProto DllImport, _mbctolower_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbctoupper_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbchira, c,, <:DWORD>
    @DefProto DllImport, _ismbckata, c,, <:DWORD>
    @DefProto DllImport, _ismbcsymbol, c,, <:DWORD>
    @DefProto DllImport, _ismbcl0, c,, <:DWORD>
    @DefProto DllImport, _ismbcl1, c,, <:DWORD>
    @DefProto DllImport, _ismbcl2, c,, <:DWORD>
    @DefProto DllImport, _ismbchira_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbckata_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcsymbol_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcl0_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcl1_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbcl2_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbcjistojms, c,, <:DWORD>
    @DefProto DllImport, _mbcjmstojis, c,, <:DWORD>
    @DefProto DllImport, _mbctohira, c,, <:DWORD>
    @DefProto DllImport, _mbctokata, c,, <:DWORD>
    @DefProto DllImport, _mbcjistojms_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbcjmstojis_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbctohira_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _mbctokata_l, c,, <:DWORD, :_locale_t>
  endif
  if _CRT_FUNCTIONS_REQUIRED
    @DefProto DllImport, _ismbblead, c,, <:DWORD>
    @DefProto DllImport, _ismbbtrail, c,, <:DWORD>
    @DefProto DllImport, _ismbblead_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbbtrail_l, c,, <:DWORD, :_locale_t>
    @DefProto DllImport, _ismbslead, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _ismbslead_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
    @DefProto DllImport, _ismbstrail, c,, <:ptr BYTE, :ptr BYTE>
    @DefProto DllImport, _ismbstrail_l, c,, <:ptr BYTE, :ptr BYTE, :_locale_t>
  endif
endif
 