;Include file created by h2incX, Version C.01.00, 08/10/2022 19:14
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX - Kopie\png.h', last modified: 14/09/2022 22:42
;Creation parameters: 

png_byte      typedef BYTE
png_uint_16   typedef WORD
png_uint_32   typedef DWORD
png_charp     typedef POINTER
png_int_32    typedef SDWORD


ifndef PNG_H
  PNG_H equ <>
  PNG_LIBPNG_VER_STRING equ <"1.6.38">
  PNG_HEADER_VERSION_STRING equ <" libpng version 1.6.38 - September 14, 2022",0Ah>
  PNG_LIBPNG_VER_SONUM equ 16
  PNG_LIBPNG_VER_DLLNUM equ 16
  PNG_LIBPNG_VER_MAJOR equ 1
  PNG_LIBPNG_VER_MINOR equ 6
  PNG_LIBPNG_VER_RELEASE equ 38
  PNG_LIBPNG_VER_BUILD equ 0
  PNG_LIBPNG_BUILD_ALPHA equ 1
  PNG_LIBPNG_BUILD_BETA equ 2
  PNG_LIBPNG_BUILD_RC equ 3
  PNG_LIBPNG_BUILD_STABLE equ 4
  PNG_LIBPNG_BUILD_RELEASE_STATUS_MASK equ 7
  PNG_LIBPNG_BUILD_PATCH equ 8
  PNG_LIBPNG_BUILD_PRIVATE equ 16
  PNG_LIBPNG_BUILD_SPECIAL equ 32
  PNG_LIBPNG_BUILD_BASE_TYPE equ <PNG_LIBPNG_BUILD_STABLE>
  PNG_LIBPNG_VER equ 10638
  ifndef PNGLCONF_H
    include pnglibconf.inc
  endif
  ifndef PNG_VERSION_INFO_ONLY
    ;include pngconf.inc
  endif
  ifdef PNG_USER_PRIVATEBUILD
    PNG_LIBPNG_BUILD_TYPE equ <(PNG_LIBPNG_BUILD_BASE_TYPE or PNG_LIBPNG_BUILD_PRIVATE)>
  else
    ifdef PNG_LIBPNG_SPECIALBUILD
      PNG_LIBPNG_BUILD_TYPE equ <(PNG_LIBPNG_BUILD_BASE_TYPE or PNG_LIBPNG_BUILD_SPECIAL)>
    else
      PNG_LIBPNG_BUILD_TYPE equ <(PNG_LIBPNG_BUILD_BASE_TYPE)>
    endif
  endif
  ifndef PNG_VERSION_INFO_ONLY
    ifdef __cplusplus
      ;[...]
    endif
    png_libpng_ver equ <png_get_header_ver (NULL)>
    png_libpng_version_1_6_38 typedef ptr SBYTE
    ;png_struct typedef png_struct_def
    
    png_const_structp typedef ptr png_struct
    png_structp typedef ptr png_struct
    png_structpp typedef ptr ptr png_struct
    ;png_info typedef png_info_def
    
    png_infop typedef ptr png_info
    png_const_infop typedef ptr png_info
    png_infopp typedef ptr ptr png_info
    png_structrp typedef ptr png_struct
    png_const_structrp typedef ptr png_struct
    png_inforp typedef ptr png_info
    png_const_inforp typedef ptr png_info
    png_color struct
      red png_byte ?
      green png_byte ?
      blue png_byte ?
    png_color ends
    png_color_struct typedef png_color
    png_colorp typedef ptr png_color
    png_const_colorp typedef ptr png_color
    png_colorpp typedef ptr ptr png_color
    png_color_16 struct
      index png_byte ?
      red png_uint_16 ?
      green png_uint_16 ?
      blue png_uint_16 ?
      gray png_uint_16 ?
    png_color_16 ends
    png_color_16_struct typedef png_color_16
    png_color_16p typedef ptr png_color_16
    png_const_color_16p typedef ptr png_color_16
    png_color_16pp typedef ptr ptr png_color_16
    png_color_8 struct
      red png_byte ?
      green png_byte ?
      blue png_byte ?
      gray png_byte ?
      alpha png_byte ?
    png_color_8 ends
    png_color_8_struct typedef png_color_8
    png_color_8p typedef ptr png_color_8
    png_const_color_8p typedef ptr png_color_8
    png_color_8pp typedef ptr ptr png_color_8
    png_sPLT_entry struct
      red png_uint_16 ?
      green png_uint_16 ?
      blue png_uint_16 ?
      alpha png_uint_16 ?
      frequency png_uint_16 ?
    png_sPLT_entry ends
    png_sPLT_entry_struct typedef png_sPLT_entry
    png_sPLT_entryp typedef ptr png_sPLT_entry
    png_const_sPLT_entryp typedef ptr png_sPLT_entry
    png_sPLT_entrypp typedef ptr ptr png_sPLT_entry
    png_sPLT_t struct
      name_ png_charp ?
      depth png_byte ?
      entries png_sPLT_entryp ?
      nentries png_int_32 ?
    png_sPLT_t ends
    png_sPLT_struct typedef png_sPLT_t
    png_sPLT_tp typedef ptr png_sPLT_t
    png_const_sPLT_tp typedef ptr png_sPLT_t
    png_sPLT_tpp typedef ptr ptr png_sPLT_t
    ifdef PNG_TEXT_SUPPORTED
      png_text struct
        compression SDWORD ?
        key png_charp ?
        text png_charp ?
        text_length size_t ?
        itxt_length size_t ?
        lang png_charp ?
        lang_key png_charp ?
      png_text ends
      png_text_struct typedef png_text
      png_textp typedef ptr png_text
      png_const_textp typedef ptr png_text
      png_textpp typedef ptr ptr png_text
    endif
    PNG_TEXT_COMPRESSION_NONE_WR equ -3
    PNG_TEXT_COMPRESSION_zTXt_WR equ -2
    PNG_TEXT_COMPRESSION_NONE equ -1
    PNG_TEXT_COMPRESSION_zTXt equ 0
    PNG_ITXT_COMPRESSION_NONE equ 1
    PNG_ITXT_COMPRESSION_zTXt equ 2
    PNG_TEXT_COMPRESSION_LAST equ 3
    png_time struct
      year png_uint_16 ?
      month png_byte ?
      day png_byte ?
      hour png_byte ?
      minute png_byte ?
      second png_byte ?
    png_time ends
    png_time_struct typedef png_time
    png_timep typedef ptr png_time
    png_const_timep typedef ptr png_time
    png_timepp typedef ptr ptr png_time
    if Defined(PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED) or Defined(PNG_USER_CHUNKS_SUPPORTED)
      png_unknown_chunk struct
        name_ png_byte 5 dup (?)
        data POINTER ?
        size_ size_t ?
        location png_byte ?
      png_unknown_chunk ends
      png_unknown_chunk_t typedef png_unknown_chunk
      png_unknown_chunkp typedef ptr png_unknown_chunk
      png_const_unknown_chunkp typedef ptr png_unknown_chunk
      png_unknown_chunkpp typedef ptr ptr png_unknown_chunk
    endif
    PNG_HAVE_IHDR equ 01h
    PNG_HAVE_PLTE equ 02h
    PNG_AFTER_IDAT equ 08h
    PNG_UINT_31_MAX equ ((png_uint_32) 7fffffffh)
    PNG_UINT_32_MAX equ ((png_uint_32) - 1)
    PNG_SIZE_MAX equ (- 1)
    PNG_FP_1 equ 100000
    PNG_FP_HALF equ 50000
    PNG_FP_MAX equ ((png_fixed_point) 7fffffffh)
    PNG_FP_MIN equ <(- PNG_FP_MAX)>
    PNG_COLOR_MASK_PALETTE equ 1
    PNG_COLOR_MASK_COLOR equ 2
    PNG_COLOR_MASK_ALPHA equ 4
    PNG_COLOR_TYPE_GRAY equ 0
    PNG_COLOR_TYPE_PALETTE equ <(PNG_COLOR_MASK_COLOR or PNG_COLOR_MASK_PALETTE)>
    PNG_COLOR_TYPE_RGB equ <(PNG_COLOR_MASK_COLOR)>
    PNG_COLOR_TYPE_RGB_ALPHA equ <(PNG_COLOR_MASK_COLOR or PNG_COLOR_MASK_ALPHA)>
    PNG_COLOR_TYPE_GRAY_ALPHA equ <(PNG_COLOR_MASK_ALPHA)>
    PNG_COLOR_TYPE_RGBA equ <PNG_COLOR_TYPE_RGB_ALPHA>
    PNG_COLOR_TYPE_GA equ <PNG_COLOR_TYPE_GRAY_ALPHA>
    PNG_COMPRESSION_TYPE_BASE equ 0
    PNG_COMPRESSION_TYPE_DEFAULT equ <PNG_COMPRESSION_TYPE_BASE>
    PNG_FILTER_TYPE_BASE equ 0
    PNG_INTRAPIXEL_DIFFERENCING equ 64
    PNG_FILTER_TYPE_DEFAULT equ <PNG_FILTER_TYPE_BASE>
    PNG_INTERLACE_NONE equ 0
    PNG_INTERLACE_ADAM7 equ 1
    PNG_INTERLACE_LAST equ 2
    PNG_OFFSET_PIXEL equ 0
    PNG_OFFSET_MICROMETER equ 1
    PNG_OFFSET_LAST equ 2
    PNG_EQUATION_LINEAR equ 0
    PNG_EQUATION_BASE_E equ 1
    PNG_EQUATION_ARBITRARY equ 2
    PNG_EQUATION_HYPERBOLIC equ 3
    PNG_EQUATION_LAST equ 4
    PNG_SCALE_UNKNOWN equ 0
    PNG_SCALE_METER equ 1
    PNG_SCALE_RADIAN equ 2
    PNG_SCALE_LAST equ 3
    PNG_RESOLUTION_UNKNOWN equ 0
    PNG_RESOLUTION_METER equ 1
    PNG_RESOLUTION_LAST equ 2
    PNG_sRGB_INTENT_PERCEPTUAL equ 0
    PNG_sRGB_INTENT_RELATIVE equ 1
    PNG_sRGB_INTENT_SATURATION equ 2
    PNG_sRGB_INTENT_ABSOLUTE equ 3
    PNG_sRGB_INTENT_LAST equ 4
    PNG_KEYWORD_MAX_LENGTH equ 79
    PNG_MAX_PALETTE_LENGTH equ 256
    PNG_INFO_gAMA equ 0001h
    PNG_INFO_sBIT equ 0002h
    PNG_INFO_cHRM equ 0004h
    PNG_INFO_PLTE equ 0008h
    PNG_INFO_tRNS equ 0010h
    PNG_INFO_bKGD equ 0020h
    PNG_INFO_hIST equ 0040h
    PNG_INFO_pHYs equ 0080h
    PNG_INFO_oFFs equ 0100h
    PNG_INFO_tIME equ 0200h
    PNG_INFO_pCAL equ 0400h
    PNG_INFO_sRGB equ 0800h
    PNG_INFO_iCCP equ 1000h
    PNG_INFO_sPLT equ 2000h
    PNG_INFO_sCAL equ 4000h
    PNG_INFO_IDAT equ 8000h
    PNG_INFO_eXIf equ 10000h
    png_row_info struct
      width_ png_uint_32 ?
      rowbytes size_t ?
      color_type png_byte ?
      bit_depth png_byte ?
      channels png_byte ?
      pixel_depth png_byte ?
    png_row_info ends
    png_row_info_struct typedef png_row_info
    png_row_infop typedef ptr png_row_info
    png_row_infopp typedef ptr ptr png_row_info
;    PNG_CALLBACK typedef proto, :ptr png_error_ptr, :(, :png_const_charp
;    PNG_CALLBACK typedef proto, :ptr png_rw_ptr, :(, :png_bytep, :size_t
;    PNG_CALLBACK typedef proto, :ptr png_flush_ptr, :(
;    PNG_CALLBACK typedef proto, :ptr png_read_status_ptr, :(, :png_uint_32, :SDWORD
;    PNG_CALLBACK typedef proto, :ptr png_write_status_ptr, :(, :png_uint_32, :SDWORD
;    ifdef PNG_PROGRESSIVE_READ_SUPPORTED
;      PNG_CALLBACK typedef proto, :ptr png_progressive_info_ptr, :(, :png_infop
;      PNG_CALLBACK typedef proto, :ptr png_progressive_end_ptr, :(, :png_infop
;      PNG_CALLBACK typedef proto, :ptr png_progressive_row_ptr, :(, :png_bytep, :png_uint_32, :SDWORD
;    endif
;    if Defined(PNG_READ_USER_TRANSFORM_SUPPORTED) or Defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED)
;      PNG_CALLBACK typedef proto, :ptr png_user_transform_ptr, :(, :png_row_infop, :png_bytep
;    endif
;    ifdef PNG_USER_CHUNKS_SUPPORTED
;      PNG_CALLBACK typedef proto :SDWORD, :ptr png_user_chunk_ptr, :(, :png_unknown_chunkp
;    endif
;    ifdef PNG_UNKNOWN_CHUNKS_SUPPORTED
;    endif
;    ifdef PNG_SETJMP_SUPPORTED
;      PNG_FUNCTION proto WIN_STD_CALL_CONV, :ptr PNGCAPI, :PNGARG, :SDWORD, :typedef_
;    endif
    PNG_TRANSFORM_IDENTITY equ 0000h
    PNG_TRANSFORM_STRIP_16 equ 0001h
    PNG_TRANSFORM_STRIP_ALPHA equ 0002h
    PNG_TRANSFORM_PACKING equ 0004h
    PNG_TRANSFORM_PACKSWAP equ 0008h
    PNG_TRANSFORM_EXPAND equ 0010h
    PNG_TRANSFORM_INVERT_MONO equ 0020h
    PNG_TRANSFORM_SHIFT equ 0040h
    PNG_TRANSFORM_BGR equ 0080h
    PNG_TRANSFORM_SWAP_ALPHA equ 0100h
    PNG_TRANSFORM_SWAP_ENDIAN equ 0200h
    PNG_TRANSFORM_INVERT_ALPHA equ 0400h
    PNG_TRANSFORM_STRIP_FILLER equ 0800h
    PNG_TRANSFORM_STRIP_FILLER_BEFORE equ <PNG_TRANSFORM_STRIP_FILLER>
    PNG_TRANSFORM_STRIP_FILLER_AFTER equ 1000h
    PNG_TRANSFORM_GRAY_TO_RGB equ 2000h
    PNG_TRANSFORM_EXPAND_16 equ 4000h
    if INT_MAX ge 8000h
      PNG_TRANSFORM_SCALE_16 equ 8000h
    endif
    PNG_FLAG_MNG_EMPTY_PLTE equ 01h
    PNG_FLAG_MNG_FILTER_64 equ 04h
    PNG_ALL_MNG_FEATURES equ 05h

;    PNG_CALLBACK typedef proto :png_voidp, :ptr png_malloc_ptr, :(, :png_alloc_size_t
;    PNG_CALLBACK typedef proto, :ptr png_free_ptr, :(, :png_voidp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :1, :png_uint_32, :png_access_version_number, 
;    PNG_EXPORT proto WIN_STD_CALL_CONV :2,, :png_set_sig_bytes, :png_structrp, :SDWORD
;    PNG_EXPORT proto WIN_STD_CALL_CONV :3, :SDWORD, :png_sig_cmp, :png_const_bytep, :size_t, :size_t
;    png_check_sig macro sig, n
;      exitm <! png_sig_cmp ((sig), 0, (n))>
;    endm
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :4, :png_structp, :png_create_read_struct, :png_const_charp, :png_voidp, :png_error_ptr, :png_error_ptr, :PNG_ALLOCATED
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :5, :png_structp, :png_create_write_struct, :png_const_charp, :png_voidp, :png_error_ptr, :png_error_ptr, :PNG_ALLOCATED
;    PNG_EXPORT proto WIN_STD_CALL_CONV :6, :size_t, :png_get_compression_buffer_size, :png_const_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :7,, :png_set_compression_buffer_size, :png_structrp, :size_t
;    ifdef PNG_SETJMP_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :8, :ptr jmp_buf, :png_set_longjmp_fn, :png_structrp, :png_longjmp_ptr, :size_t
;      png_jmpbuf macro png_ptr
;        exitm <(* png_set_longjmp_fn ((png_ptr), longjmp, (sizeof(jmp_buf))))>
;      endm
;    else
;      png_jmpbuf macro png_ptr
;        exitm <(LIBPNG_WAS_COMPILED_WITH__PNG_NO_SETJMP)>
;      endm
;    endif
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :9,, :png_longjmp, :png_const_structrp, :SDWORD, :PNG_NORETURN
;    ifdef PNG_READ_SUPPORTED
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :10, :SDWORD, :png_reset_zstream, :png_structrp, :PNG_DEPRECATED
;    endif
;    ifdef PNG_USER_MEM_SUPPORTED
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :11, :png_structp, :png_create_read_struct_2, :png_const_charp, :png_voidp, :png_error_ptr, :png_error_ptr, :png_voidp, :png_malloc_ptr, :png_free_ptr, :PNG_ALLOCATED
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :12, :png_structp, :png_create_write_struct_2, :png_const_charp, :png_voidp, :png_error_ptr, :png_error_ptr, :png_voidp, :png_malloc_ptr, :png_free_ptr, :PNG_ALLOCATED
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :13,, :png_write_sig, :png_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :14,, :png_write_chunk, :png_structrp, :png_const_bytep, :png_const_bytep, :size_t
;    PNG_EXPORT proto WIN_STD_CALL_CONV :15,, :png_write_chunk_start, :png_structrp, :png_const_bytep, :png_uint_32
;    PNG_EXPORT proto WIN_STD_CALL_CONV :16,, :png_write_chunk_data, :png_structrp, :png_const_bytep, :size_t
;    PNG_EXPORT proto WIN_STD_CALL_CONV :17,, :png_write_chunk_end, :png_structrp
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :18, :png_infop, :png_create_info_struct, :png_const_structrp, :PNG_ALLOCATED
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :19,, :png_info_init_3, :png_infopp, :size_t, :PNG_DEPRECATED
;    PNG_EXPORT proto WIN_STD_CALL_CONV :20,, :png_write_info_before_PLTE, :png_structrp, :png_const_inforp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :21,, :png_write_info, :png_structrp, :png_const_inforp
;    ifdef PNG_SEQUENTIAL_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :22,, :png_read_info, :png_structrp, :png_inforp
;    endif
;    ifdef PNG_TIME_RFC1123_SUPPORTED
;      if PNG_LIBPNG_VER lt 10700
;        PNG_EXPORTA proto WIN_STD_CALL_CONV :23, :png_const_charp, :png_convert_to_rfc1123, :png_structrp, :png_const_timep, :PNG_DEPRECATED
;      endif
;      PNG_EXPORT proto WIN_STD_CALL_CONV :241, :SDWORD, :png_convert_to_rfc1123_buffer, :ptr SBYTE, :png_const_timep
;    endif
;    ifdef PNG_CONVERT_tIME_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :24,, :png_convert_from_struct_tm, :png_timep, :ptr tm
;      PNG_EXPORT proto WIN_STD_CALL_CONV :25,, :png_convert_from_time_t, :png_timep, :time_t
;    endif
;    ifdef PNG_READ_EXPAND_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :26,, :png_set_expand, :png_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :27,, :png_set_expand_gray_1_2_4_to_8, :png_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :28,, :png_set_palette_to_rgb, :png_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :29,, :png_set_tRNS_to_alpha, :png_structrp
;    endif
;    ifdef PNG_READ_EXPAND_16_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :221,, :png_set_expand_16, :png_structrp
;    endif
;    if Defined(PNG_READ_BGR_SUPPORTED) or Defined(PNG_WRITE_BGR_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :30,, :png_set_bgr, :png_structrp
;    endif
;    ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :31,, :png_set_gray_to_rgb, :png_structrp
;    endif
;    ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
;      PNG_ERROR_ACTION_NONE equ 1
;      PNG_ERROR_ACTION_WARN equ 2
;      PNG_ERROR_ACTION_ERROR equ 3
;      PNG_RGB_TO_GRAY_DEFAULT equ -1
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :32,, :png_set_rgb_to_gray, :png_structrp, :SDWORD, :REAL8, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :33,, :png_set_rgb_to_gray_fixed, :png_structrp, :SDWORD, :png_fixed_point, :png_fixed_point
;      PNG_EXPORT proto WIN_STD_CALL_CONV :34, :png_byte, :png_get_rgb_to_gray_status, :png_const_structrp
;    endif
;    ifdef PNG_BUILD_GRAYSCALE_PALETTE_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :35,, :png_build_grayscale_palette, :SDWORD, :png_colorp
;    endif
;    ifdef PNG_READ_ALPHA_MODE_SUPPORTED
;      PNG_ALPHA_PNG equ 0
;      PNG_ALPHA_STANDARD equ 1
;      PNG_ALPHA_ASSOCIATED equ 1
;      PNG_ALPHA_PREMULTIPLIED equ 1
;      PNG_ALPHA_OPTIMIZED equ 2
;      PNG_ALPHA_BROKEN equ 3
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :227,, :png_set_alpha_mode, :png_structrp, :SDWORD, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :228,, :png_set_alpha_mode_fixed, :png_structrp, :SDWORD, :png_fixed_point
;    endif
;    if Defined(PNG_GAMMA_SUPPORTED) or Defined(PNG_READ_ALPHA_MODE_SUPPORTED)
;      PNG_DEFAULT_sRGB equ -1
;      PNG_GAMMA_MAC_18 equ -2
;      PNG_GAMMA_sRGB equ 220000
;      PNG_GAMMA_LINEAR equ <PNG_FP_1>
;    endif
;    ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :36,, :png_set_strip_alpha, :png_structrp
;    endif
;    if Defined(PNG_READ_SWAP_ALPHA_SUPPORTED) or Defined(PNG_WRITE_SWAP_ALPHA_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :37,, :png_set_swap_alpha, :png_structrp
;    endif
;    if Defined(PNG_READ_INVERT_ALPHA_SUPPORTED) or Defined(PNG_WRITE_INVERT_ALPHA_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :38,, :png_set_invert_alpha, :png_structrp
;    endif
;    if Defined(PNG_READ_FILLER_SUPPORTED) or Defined(PNG_WRITE_FILLER_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :39,, :png_set_filler, :png_structrp, :png_uint_32, :SDWORD
;      PNG_FILLER_BEFORE equ 0
;      PNG_FILLER_AFTER equ 1
;      PNG_EXPORT proto WIN_STD_CALL_CONV :40,, :png_set_add_alpha, :png_structrp, :png_uint_32, :SDWORD
;    endif
;    if Defined(PNG_READ_SWAP_SUPPORTED) or Defined(PNG_WRITE_SWAP_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :41,, :png_set_swap, :png_structrp
;    endif
;    if Defined(PNG_READ_PACK_SUPPORTED) or Defined(PNG_WRITE_PACK_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :42,, :png_set_packing, :png_structrp
;    endif
;    if Defined(PNG_READ_PACKSWAP_SUPPORTED) or Defined(PNG_WRITE_PACKSWAP_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :43,, :png_set_packswap, :png_structrp
;    endif
;    if Defined(PNG_READ_SHIFT_SUPPORTED) or Defined(PNG_WRITE_SHIFT_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :44,, :png_set_shift, :png_structrp, :png_const_color_8p
;    endif
;    if Defined(PNG_READ_INTERLACING_SUPPORTED) or Defined(PNG_WRITE_INTERLACING_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :45, :SDWORD, :png_set_interlace_handling, :png_structrp
;    endif
;    if Defined(PNG_READ_INVERT_SUPPORTED) or Defined(PNG_WRITE_INVERT_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :46,, :png_set_invert_mono, :png_structrp
;    endif
;    ifdef PNG_READ_BACKGROUND_SUPPORTED
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :47,, :png_set_background, :png_structrp, :png_const_color_16p, :SDWORD, :SDWORD, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :215,, :png_set_background_fixed, :png_structrp, :png_const_color_16p, :SDWORD, :SDWORD, :png_fixed_point
;    endif
;    ifdef PNG_READ_BACKGROUND_SUPPORTED
;      PNG_BACKGROUND_GAMMA_UNKNOWN equ 0
;      PNG_BACKGROUND_GAMMA_SCREEN equ 1
;      PNG_BACKGROUND_GAMMA_FILE equ 2
;      PNG_BACKGROUND_GAMMA_UNIQUE equ 3
;    endif
;    ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :229,, :png_set_scale_16, :png_structrp
;    endif
;    ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
;      PNG_READ_16_TO_8_SUPPORTED equ <>
;      PNG_EXPORT proto WIN_STD_CALL_CONV :48,, :png_set_strip_16, :png_structrp
;    endif
;    ifdef PNG_READ_QUANTIZE_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :49,, :png_set_quantize, :png_structrp, :png_colorp, :SDWORD, :SDWORD, :png_const_uint_16p, :SDWORD
;    endif
;    ifdef PNG_READ_GAMMA_SUPPORTED
;      PNG_GAMMA_THRESHOLD equ <(PNG_GAMMA_THRESHOLD_FIXED * .00001)>
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :50,, :png_set_gamma, :png_structrp, :REAL8, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :208,, :png_set_gamma_fixed, :png_structrp, :png_fixed_point, :png_fixed_point
;    endif
;    ifdef PNG_WRITE_FLUSH_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :51,, :png_set_flush, :png_structrp, :SDWORD
;      PNG_EXPORT proto WIN_STD_CALL_CONV :52,, :png_write_flush, :png_structrp
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :53,, :png_start_read_image, :png_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :54,, :png_read_update_info, :png_structrp, :png_inforp
;    ifdef PNG_SEQUENTIAL_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :55,, :png_read_rows, :png_structrp, :png_bytepp, :png_bytepp, :png_uint_32
;    endif
;    ifdef PNG_SEQUENTIAL_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :56,, :png_read_row, :png_structrp, :png_bytep, :png_bytep
;    endif
;    ifdef PNG_SEQUENTIAL_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :57,, :png_read_image, :png_structrp, :png_bytepp
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :58,, :png_write_row, :png_structrp, :png_const_bytep
;    PNG_EXPORT proto WIN_STD_CALL_CONV :59,, :png_write_rows, :png_structrp, :png_bytepp, :png_uint_32
;    PNG_EXPORT proto WIN_STD_CALL_CONV :60,, :png_write_image, :png_structrp, :png_bytepp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :61,, :png_write_end, :png_structrp, :png_inforp
;    ifdef PNG_SEQUENTIAL_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :62,, :png_read_end, :png_structrp, :png_inforp
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :63,, :png_destroy_info_struct, :png_const_structrp, :png_infopp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :64,, :png_destroy_read_struct, :png_structpp, :png_infopp, :png_infopp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :65,, :png_destroy_write_struct, :png_structpp, :png_infopp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :66,, :png_set_crc_action, :png_structrp, :SDWORD, :SDWORD
;    PNG_CRC_DEFAULT equ 0
;    PNG_CRC_ERROR_QUIT equ 1
;    PNG_CRC_WARN_DISCARD equ 2
;    PNG_CRC_WARN_USE equ 3
;    PNG_CRC_QUIET_USE equ 4
;    PNG_CRC_NO_CHANGE equ 5
;    ifdef PNG_WRITE_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :67,, :png_set_filter, :png_structrp, :SDWORD, :SDWORD
;    endif
;    PNG_NO_FILTERS equ 00h
;    PNG_FILTER_NONE equ 08h
;    PNG_FILTER_SUB equ 10h
;    PNG_FILTER_UP equ 20h
;    PNG_FILTER_AVG equ 40h
;    PNG_FILTER_PAETH equ 80h
;    PNG_FAST_FILTERS equ <(PNG_FILTER_NONE or PNG_FILTER_SUB or PNG_FILTER_UP)>
;    PNG_ALL_FILTERS equ <(PNG_FAST_FILTERS or PNG_FILTER_AVG or PNG_FILTER_PAETH)>
;    PNG_FILTER_VALUE_NONE equ 0
;    PNG_FILTER_VALUE_SUB equ 1
;    PNG_FILTER_VALUE_UP equ 2
;    PNG_FILTER_VALUE_AVG equ 3
;    PNG_FILTER_VALUE_PAETH equ 4
;    PNG_FILTER_VALUE_LAST equ 5
;    ifdef PNG_WRITE_SUPPORTED
;      ifdef PNG_WRITE_WEIGHTED_FILTER_SUPPORTED
;        PNG_FP_EXPORT proto WIN_STD_CALL_CONV :68,, :png_set_filter_heuristics, :png_structrp, :SDWORD, :SDWORD, :png_const_doublep, :png_const_doublep
;        PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :209,, :png_set_filter_heuristics_fixed, :png_structrp, :SDWORD, :SDWORD, :png_const_fixed_point_p, :png_const_fixed_point_p
;      endif
;      PNG_FILTER_HEURISTIC_DEFAULT equ 0
;      PNG_FILTER_HEURISTIC_UNWEIGHTED equ 1
;      PNG_FILTER_HEURISTIC_WEIGHTED equ 2
;      PNG_FILTER_HEURISTIC_LAST equ 3
;      ifdef PNG_WRITE_CUSTOMIZE_COMPRESSION_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :69,, :png_set_compression_level, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :70,, :png_set_compression_mem_level, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :71,, :png_set_compression_strategy, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :72,, :png_set_compression_window_bits, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :73,, :png_set_compression_method, :png_structrp, :SDWORD
;      endif
;      ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :222,, :png_set_text_compression_level, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :223,, :png_set_text_compression_mem_level, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :224,, :png_set_text_compression_strategy, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :225,, :png_set_text_compression_window_bits, :png_structrp, :SDWORD
;        PNG_EXPORT proto WIN_STD_CALL_CONV :226,, :png_set_text_compression_method, :png_structrp, :SDWORD
;      endif
;    endif
;    ifdef PNG_STDIO_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :74,, :png_init_io, :png_structrp, :png_FILE_p
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :75,, :png_set_error_fn, :png_structrp, :png_voidp, :png_error_ptr, :png_error_ptr
;    PNG_EXPORT proto WIN_STD_CALL_CONV :76, :png_voidp, :png_get_error_ptr, :png_const_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :77,, :png_set_write_fn, :png_structrp, :png_voidp, :png_rw_ptr, :png_flush_ptr
;    PNG_EXPORT proto WIN_STD_CALL_CONV :78,, :png_set_read_fn, :png_structrp, :png_voidp, :png_rw_ptr
;    PNG_EXPORT proto WIN_STD_CALL_CONV :79, :png_voidp, :png_get_io_ptr, :png_const_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :80,, :png_set_read_status_fn, :png_structrp, :png_read_status_ptr
;    PNG_EXPORT proto WIN_STD_CALL_CONV :81,, :png_set_write_status_fn, :png_structrp, :png_write_status_ptr
;    ifdef PNG_USER_MEM_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :82,, :png_set_mem_fn, :png_structrp, :png_voidp, :png_malloc_ptr, :png_free_ptr
;      PNG_EXPORT proto WIN_STD_CALL_CONV :83, :png_voidp, :png_get_mem_ptr, :png_const_structrp
;    endif
;    ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :84,, :png_set_read_user_transform_fn, :png_structrp, :png_user_transform_ptr
;    endif
;    ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :85,, :png_set_write_user_transform_fn, :png_structrp, :png_user_transform_ptr
;    endif
;    ifdef PNG_USER_TRANSFORM_PTR_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :86,, :png_set_user_transform_info, :png_structrp, :png_voidp, :SDWORD, :SDWORD
;      PNG_EXPORT proto WIN_STD_CALL_CONV :87, :png_voidp, :png_get_user_transform_ptr, :png_const_structrp
;    endif
;    ifdef PNG_USER_TRANSFORM_INFO_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :217, :png_uint_32, :png_get_current_row_number, :png_const_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :218, :png_byte, :png_get_current_pass_number, :png_const_structrp
;    endif
;    ifdef PNG_READ_USER_CHUNKS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :88,, :png_set_read_user_chunk_fn, :png_structrp, :png_voidp, :png_user_chunk_ptr
;    endif
;    ifdef PNG_USER_CHUNKS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :89, :png_voidp, :png_get_user_chunk_ptr, :png_const_structrp
;    endif
;    ifdef PNG_PROGRESSIVE_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :90,, :png_set_progressive_read_fn, :png_structrp, :png_voidp, :png_progressive_info_ptr, :png_progressive_row_ptr, :png_progressive_end_ptr
;      PNG_EXPORT proto WIN_STD_CALL_CONV :91, :png_voidp, :png_get_progressive_ptr, :png_const_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :92,, :png_process_data, :png_structrp, :png_inforp, :png_bytep, :size_t
;      PNG_EXPORT proto WIN_STD_CALL_CONV :219, :size_t, :png_process_data_pause, :png_structrp, :SDWORD
;      PNG_EXPORT proto WIN_STD_CALL_CONV :220, :png_uint_32, :png_process_data_skip, :png_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :93,, :png_progressive_combine_row, :png_const_structrp, :png_bytep, :png_const_bytep
;    endif
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :94, :png_voidp, :png_malloc, :png_const_structrp, :png_alloc_size_t, :PNG_ALLOCATED
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :95, :png_voidp, :png_calloc, :png_const_structrp, :png_alloc_size_t, :PNG_ALLOCATED
;    PNG_EXPORTA proto WIN_STD_CALL_CONV :96, :png_voidp, :png_malloc_warn, :png_const_structrp, :png_alloc_size_t, :PNG_ALLOCATED
;    PNG_EXPORT proto WIN_STD_CALL_CONV :97,, :png_free, :png_const_structrp, :png_voidp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :98,, :png_free_data, :png_const_structrp, :png_inforp, :png_uint_32, :SDWORD
;    PNG_EXPORT proto WIN_STD_CALL_CONV :99,, :png_data_freer, :png_const_structrp, :png_inforp, :SDWORD, :png_uint_32
;    PNG_DESTROY_WILL_FREE_DATA equ 1
;    PNG_SET_WILL_FREE_DATA equ 1
;    PNG_USER_WILL_FREE_DATA equ 2
;    PNG_FREE_HIST equ 0008h
;    PNG_FREE_ICCP equ 0010h
;    PNG_FREE_SPLT equ 0020h
;    PNG_FREE_ROWS equ 0040h
;    PNG_FREE_PCAL equ 0080h
;    PNG_FREE_SCAL equ 0100h
;    ifdef PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
;      PNG_FREE_UNKN equ 0200h
;    endif
;    PNG_FREE_PLTE equ 1000h
;    PNG_FREE_TRNS equ 2000h
;    PNG_FREE_TEXT equ 4000h
;    PNG_FREE_EXIF equ 8000h
;    PNG_FREE_ALL equ 0ffffh
;    PNG_FREE_MUL equ 4220h
;    ifdef PNG_USER_MEM_SUPPORTED
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :100, :png_voidp, :png_malloc_default, :png_const_structrp, :png_alloc_size_t, :PNG_ALLOCATED
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :101,, :png_free_default, :png_const_structrp, :png_voidp, :PNG_DEPRECATED
;    endif
;    ifdef PNG_ERROR_TEXT_SUPPORTED
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :102,, :png_error, :png_const_structrp, :png_const_charp, :PNG_NORETURN
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :103,, :png_chunk_error, :png_const_structrp, :png_const_charp, :PNG_NORETURN
;    else
;      PNG_EXPORTA proto WIN_STD_CALL_CONV :104,, :png_err, :png_const_structrp, :PNG_NORETURN
;      png_error macro s1, s2
;        exitm <png_err (s1)>
;      endm
;      png_chunk_error macro s1, s2
;        exitm <png_err (s1)>
;      endm
;    endif
;    ifdef PNG_WARNINGS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :105,, :png_warning, :png_const_structrp, :png_const_charp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :106,, :png_chunk_warning, :png_const_structrp, :png_const_charp
;    else
;      png_warning macro s1, s2
;        exitm <((s1))>
;      endm
;      png_chunk_warning macro s1, s2
;        exitm <((s1))>
;      endm
;    endif
;    ifdef PNG_BENIGN_ERRORS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :107,, :png_benign_error, :png_const_structrp, :png_const_charp
;      ifdef PNG_READ_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :108,, :png_chunk_benign_error, :png_const_structrp, :png_const_charp
;      endif
;      PNG_EXPORT proto WIN_STD_CALL_CONV :109,, :png_set_benign_errors, :png_structrp, :SDWORD
;    else
;      ifdef PNG_ALLOW_BENIGN_ERRORS
;        png_benign_error equ <png_warning>
;        png_chunk_benign_error equ <png_chunk_warning>
;      else
;        png_benign_error equ <png_error>
;        png_chunk_benign_error equ <png_chunk_error>
;      endif
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :110, :png_uint_32, :png_get_valid, :png_const_structrp, :png_const_inforp, :png_uint_32
;    PNG_EXPORT proto WIN_STD_CALL_CONV :111, :size_t, :png_get_rowbytes, :png_const_structrp, :png_const_inforp
;    ifdef PNG_INFO_IMAGE_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :112, :png_bytepp, :png_get_rows, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :113,, :png_set_rows, :png_const_structrp, :png_inforp, :png_bytepp
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :114, :png_byte, :png_get_channels, :png_const_structrp, :png_const_inforp
;    ifdef PNG_EASY_ACCESS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :115, :png_uint_32, :png_get_image_width, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :116, :png_uint_32, :png_get_image_height, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :117, :png_byte, :png_get_bit_depth, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :118, :png_byte, :png_get_color_type, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :119, :png_byte, :png_get_filter_type, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :120, :png_byte, :png_get_interlace_type, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :121, :png_byte, :png_get_compression_type, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :122, :png_uint_32, :png_get_pixels_per_meter, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :123, :png_uint_32, :png_get_x_pixels_per_meter, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :124, :png_uint_32, :png_get_y_pixels_per_meter, :png_const_structrp, :png_const_inforp
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :125, :REAL4, :png_get_pixel_aspect_ratio, :png_const_structrp, :png_const_inforp
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :210, :png_fixed_point, :png_get_pixel_aspect_ratio_fixed, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :126, :png_int_32, :png_get_x_offset_pixels, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :127, :png_int_32, :png_get_y_offset_pixels, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :128, :png_int_32, :png_get_x_offset_microns, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :129, :png_int_32, :png_get_y_offset_microns, :png_const_structrp, :png_const_inforp
;    endif
;    ifdef PNG_READ_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :130, :png_const_bytep, :png_get_signature, :png_const_structrp, :png_const_inforp
;    endif
;    ifdef PNG_bKGD_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :131, :png_uint_32, :png_get_bKGD, :png_const_structrp, :png_inforp, :ptr png_color_16p
;    endif
;    ifdef PNG_bKGD_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :132,, :png_set_bKGD, :png_const_structrp, :png_inforp, :png_const_color_16p
;    endif
;    ifdef PNG_cHRM_SUPPORTED
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :133, :png_uint_32, :png_get_cHRM, :png_const_structrp, :png_const_inforp, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :230, :png_uint_32, :png_get_cHRM_XYZ, :png_const_structrp, :png_const_inforp, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8, :ptr REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :134, :png_uint_32, :png_get_cHRM_fixed, :png_const_structrp, :png_const_inforp, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :231, :png_uint_32, :png_get_cHRM_XYZ_fixed, :png_const_structrp, :png_const_inforp, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point, :ptr png_fixed_point
;    endif
;    ifdef PNG_cHRM_SUPPORTED
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :135,, :png_set_cHRM, :png_const_structrp, :png_inforp, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :232,, :png_set_cHRM_XYZ, :png_const_structrp, :png_inforp, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :136,, :png_set_cHRM_fixed, :png_const_structrp, :png_inforp, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :233,, :png_set_cHRM_XYZ_fixed, :png_const_structrp, :png_inforp, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point, :png_fixed_point
;    endif
;    ifdef PNG_eXIf_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :246, :png_uint_32, :png_get_eXIf, :png_const_structrp, :png_inforp, :ptr png_bytep
;      PNG_EXPORT proto WIN_STD_CALL_CONV :247,, :png_set_eXIf, :png_const_structrp, :png_inforp, :png_bytep
;      PNG_EXPORT proto WIN_STD_CALL_CONV :248, :png_uint_32, :png_get_eXIf_1, :png_const_structrp, :png_const_inforp, :ptr png_uint_32, :ptr png_bytep
;      PNG_EXPORT proto WIN_STD_CALL_CONV :249,, :png_set_eXIf_1, :png_const_structrp, :png_inforp, :png_uint_32, :png_bytep
;    endif
;    ifdef PNG_gAMA_SUPPORTED
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :137, :png_uint_32, :png_get_gAMA, :png_const_structrp, :png_const_inforp, :ptr REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :138, :png_uint_32, :png_get_gAMA_fixed, :png_const_structrp, :png_const_inforp, :ptr png_fixed_point
;    endif
;    ifdef PNG_gAMA_SUPPORTED
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :139,, :png_set_gAMA, :png_const_structrp, :png_inforp, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :140,, :png_set_gAMA_fixed, :png_const_structrp, :png_inforp, :png_fixed_point
;    endif
;    ifdef PNG_hIST_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :141, :png_uint_32, :png_get_hIST, :png_const_structrp, :png_inforp, :ptr png_uint_16p
;      PNG_EXPORT proto WIN_STD_CALL_CONV :142,, :png_set_hIST, :png_const_structrp, :png_inforp, :png_const_uint_16p
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :143, :png_uint_32, :png_get_IHDR, :png_const_structrp, :png_const_inforp, :ptr png_uint_32, :ptr png_uint_32, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD, :ptr SDWORD
;    PNG_EXPORT proto WIN_STD_CALL_CONV :144,, :png_set_IHDR, :png_const_structrp, :png_inforp, :png_uint_32, :png_uint_32, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD
;    ifdef PNG_oFFs_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :145, :png_uint_32, :png_get_oFFs, :png_const_structrp, :png_const_inforp, :ptr png_int_32, :ptr png_int_32, :ptr SDWORD
;    endif
;    ifdef PNG_oFFs_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :146,, :png_set_oFFs, :png_const_structrp, :png_inforp, :png_int_32, :png_int_32, :SDWORD
;    endif
;    ifdef PNG_pCAL_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :147, :png_uint_32, :png_get_pCAL, :png_const_structrp, :png_inforp, :ptr png_charp, :ptr png_int_32, :ptr png_int_32, :ptr SDWORD, :ptr SDWORD, :ptr png_charp, :ptr png_charpp
;    endif
;    ifdef PNG_pCAL_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :148,, :png_set_pCAL, :png_const_structrp, :png_inforp, :png_const_charp, :png_int_32, :png_int_32, :SDWORD, :SDWORD, :png_const_charp, :png_charpp
;    endif
;    ifdef PNG_pHYs_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :149, :png_uint_32, :png_get_pHYs, :png_const_structrp, :png_const_inforp, :ptr png_uint_32, :ptr png_uint_32, :ptr SDWORD
;    endif
;    ifdef PNG_pHYs_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :150,, :png_set_pHYs, :png_const_structrp, :png_inforp, :png_uint_32, :png_uint_32, :SDWORD
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :151, :png_uint_32, :png_get_PLTE, :png_const_structrp, :png_inforp, :ptr png_colorp, :ptr SDWORD
;    PNG_EXPORT proto WIN_STD_CALL_CONV :152,, :png_set_PLTE, :png_structrp, :png_inforp, :png_const_colorp, :SDWORD
;    ifdef PNG_sBIT_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :153, :png_uint_32, :png_get_sBIT, :png_const_structrp, :png_inforp, :ptr png_color_8p
;    endif
;    ifdef PNG_sBIT_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :154,, :png_set_sBIT, :png_const_structrp, :png_inforp, :png_const_color_8p
;    endif
;    ifdef PNG_sRGB_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :155, :png_uint_32, :png_get_sRGB, :png_const_structrp, :png_const_inforp, :ptr SDWORD
;    endif
;    ifdef PNG_sRGB_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :156,, :png_set_sRGB, :png_const_structrp, :png_inforp, :SDWORD
;      PNG_EXPORT proto WIN_STD_CALL_CONV :157,, :png_set_sRGB_gAMA_and_cHRM, :png_const_structrp, :png_inforp, :SDWORD
;    endif
;    ifdef PNG_iCCP_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :158, :png_uint_32, :png_get_iCCP, :png_const_structrp, :png_inforp, :png_charpp, :ptr SDWORD, :png_bytepp, :ptr png_uint_32
;    endif
;    ifdef PNG_iCCP_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :159,, :png_set_iCCP, :png_const_structrp, :png_inforp, :png_const_charp, :SDWORD, :png_const_bytep, :png_uint_32
;    endif
;    ifdef PNG_sPLT_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :160, :SDWORD, :png_get_sPLT, :png_const_structrp, :png_inforp, :png_sPLT_tpp
;    endif
;    ifdef PNG_sPLT_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :161,, :png_set_sPLT, :png_const_structrp, :png_inforp, :png_const_sPLT_tp, :SDWORD
;    endif
;    ifdef PNG_TEXT_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :162, :SDWORD, :png_get_text, :png_const_structrp, :png_inforp, :ptr png_textp, :ptr SDWORD
;    endif
;    ifdef PNG_TEXT_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :163,, :png_set_text, :png_const_structrp, :png_inforp, :png_const_textp, :SDWORD
;    endif
;    ifdef PNG_tIME_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :164, :png_uint_32, :png_get_tIME, :png_const_structrp, :png_inforp, :ptr png_timep
;    endif
;    ifdef PNG_tIME_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :165,, :png_set_tIME, :png_const_structrp, :png_inforp, :png_const_timep
;    endif
;    ifdef PNG_tRNS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :166, :png_uint_32, :png_get_tRNS, :png_const_structrp, :png_inforp, :ptr png_bytep, :ptr SDWORD, :ptr png_color_16p
;    endif
;    ifdef PNG_tRNS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :167,, :png_set_tRNS, :png_structrp, :png_inforp, :png_const_bytep, :SDWORD, :png_const_color_16p
;    endif
;    ifdef PNG_sCAL_SUPPORTED
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :168, :png_uint_32, :png_get_sCAL, :png_const_structrp, :png_const_inforp, :ptr SDWORD, :ptr REAL8, :ptr REAL8
;      if Defined(PNG_FLOATING_ARITHMETIC_SUPPORTED) or Defined(PNG_FLOATING_POINT_SUPPORTED)
;        PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :214, :png_uint_32, :png_get_sCAL_fixed, :png_const_structrp, :png_const_inforp, :ptr SDWORD, :ptr png_fixed_point, :ptr png_fixed_point
;      endif
;      PNG_EXPORT proto WIN_STD_CALL_CONV :169, :png_uint_32, :png_get_sCAL_s, :png_const_structrp, :png_const_inforp, :ptr SDWORD, :png_charpp, :png_charpp
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :170,, :png_set_sCAL, :png_const_structrp, :png_inforp, :SDWORD, :REAL8, :REAL8
;      PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :213,, :png_set_sCAL_fixed, :png_const_structrp, :png_inforp, :SDWORD, :png_fixed_point, :png_fixed_point
;      PNG_EXPORT proto WIN_STD_CALL_CONV :171,, :png_set_sCAL_s, :png_const_structrp, :png_inforp, :SDWORD, :png_const_charp, :png_const_charp
;    endif
;    ifdef PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
;      ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :172,, :png_set_keep_unknown_chunks, :png_structrp, :SDWORD, :png_const_bytep, :SDWORD
;      endif
;      PNG_EXPORT proto WIN_STD_CALL_CONV :173, :SDWORD, :png_handle_as_unknown, :png_const_structrp, :png_const_bytep
;    endif
;    ifdef PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :174,, :png_set_unknown_chunks, :png_const_structrp, :png_inforp, :png_const_unknown_chunkp, :SDWORD
;      PNG_EXPORT proto WIN_STD_CALL_CONV :175,, :png_set_unknown_chunk_location, :png_const_structrp, :png_inforp, :SDWORD, :SDWORD
;      PNG_EXPORT proto WIN_STD_CALL_CONV :176, :SDWORD, :png_get_unknown_chunks, :png_const_structrp, :png_inforp, :png_unknown_chunkpp
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :177,, :png_set_invalid, :png_const_structrp, :png_inforp, :SDWORD
;    ifdef PNG_INFO_IMAGE_SUPPORTED
;      ifdef PNG_SEQUENTIAL_READ_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :178,, :png_read_png, :png_structrp, :png_inforp, :SDWORD, :png_voidp
;      endif
;      ifdef PNG_WRITE_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :179,, :png_write_png, :png_structrp, :png_inforp, :SDWORD, :png_voidp
;      endif
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :180, :png_const_charp, :png_get_copyright, :png_const_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :181, :png_const_charp, :png_get_header_ver, :png_const_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :182, :png_const_charp, :png_get_header_version, :png_const_structrp
;    PNG_EXPORT proto WIN_STD_CALL_CONV :183, :png_const_charp, :png_get_libpng_ver, :png_const_structrp
;    ifdef PNG_MNG_FEATURES_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :184, :png_uint_32, :png_permit_mng_features, :png_structrp, :png_uint_32
;    endif
;    PNG_HANDLE_CHUNK_AS_DEFAULT equ 0
;    PNG_HANDLE_CHUNK_NEVER equ 1
;    PNG_HANDLE_CHUNK_IF_SAFE equ 2
;    PNG_HANDLE_CHUNK_ALWAYS equ 3
;    PNG_HANDLE_CHUNK_LAST equ 4
;    ifdef PNG_ERROR_NUMBERS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :185,, :png_set_strip_error_numbers, :png_structrp, :png_uint_32
;    endif
;    ifdef PNG_SET_USER_LIMITS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :186,, :png_set_user_limits, :png_structrp, :png_uint_32, :png_uint_32
;      PNG_EXPORT proto WIN_STD_CALL_CONV :187, :png_uint_32, :png_get_user_width_max, :png_const_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :188, :png_uint_32, :png_get_user_height_max, :png_const_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :189,, :png_set_chunk_cache_max, :png_structrp, :png_uint_32
;      PNG_EXPORT proto WIN_STD_CALL_CONV :190, :png_uint_32, :png_get_chunk_cache_max, :png_const_structrp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :191,, :png_set_chunk_malloc_max, :png_structrp, :png_alloc_size_t
;      PNG_EXPORT proto WIN_STD_CALL_CONV :192, :png_alloc_size_t, :png_get_chunk_malloc_max, :png_const_structrp
;    endif
;    if Defined(PNG_INCH_CONVERSIONS_SUPPORTED)
;      PNG_EXPORT proto WIN_STD_CALL_CONV :193, :png_uint_32, :png_get_pixels_per_inch, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :194, :png_uint_32, :png_get_x_pixels_per_inch, :png_const_structrp, :png_const_inforp
;      PNG_EXPORT proto WIN_STD_CALL_CONV :195, :png_uint_32, :png_get_y_pixels_per_inch, :png_const_structrp, :png_const_inforp
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :196, :REAL4, :png_get_x_offset_inches, :png_const_structrp, :png_const_inforp
;      ifdef PNG_FIXED_POINT_SUPPORTED
;        PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :211, :png_fixed_point, :png_get_x_offset_inches_fixed, :png_const_structrp, :png_const_inforp
;      endif
;      PNG_FP_EXPORT proto WIN_STD_CALL_CONV :197, :REAL4, :png_get_y_offset_inches, :png_const_structrp, :png_const_inforp
;      ifdef PNG_FIXED_POINT_SUPPORTED
;        PNG_FIXED_EXPORT proto WIN_STD_CALL_CONV :212, :png_fixed_point, :png_get_y_offset_inches_fixed, :png_const_structrp, :png_const_inforp
;      endif
;      ifdef PNG_pHYs_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :198, :png_uint_32, :png_get_pHYs_dpi, :png_const_structrp, :png_const_inforp, :ptr png_uint_32, :ptr png_uint_32, :ptr SDWORD
;      endif
;    endif
;    ifdef PNG_IO_STATE_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :199, :png_uint_32, :png_get_io_state, :png_const_structrp
;      PNG_REMOVED proto WIN_STD_CALL_CONV :200, :png_const_bytep, :png_get_io_chunk_name, :png_structrp, :PNG_DEPRECATED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :216, :png_uint_32, :png_get_io_chunk_type, :png_const_structrp
;      PNG_IO_NONE equ 0000h
;      PNG_IO_READING equ 0001h
;      PNG_IO_WRITING equ 0002h
;      PNG_IO_SIGNATURE equ 0010h
;      PNG_IO_CHUNK_HDR equ 0020h
;      PNG_IO_CHUNK_DATA equ 0040h
;      PNG_IO_CHUNK_CRC equ 0080h
;      PNG_IO_MASK_OP equ 000fh
;      PNG_IO_MASK_LOC equ 00f0h
;    endif
;    PNG_INTERLACE_ADAM7_PASSES equ 7
;    PNG_PASS_START_ROW macro pass
;      exitm <(((1 and not (pass)) shl (3 - ((pass) shr 1))) and 7)>
;    endm
;    PNG_PASS_START_COL macro pass
;      exitm <(((1 and (pass)) shl (3 - (((pass) + 1) shr 1))) and 7)>
;    endm
;    PNG_PASS_ROW_OFFSET macro pass
;      exitm <((pass) > 2? (8 shr (((pass) - 1) shr 1)) : 8)>
;    endm
;    PNG_PASS_COL_OFFSET macro pass
;      exitm <(1 shl ((7 - (pass)) shr 1))>
;    endm
;    PNG_PASS_ROW_SHIFT macro pass
;      exitm <((pass) > 2? (8 - (pass)) shr 1 : 3)>
;    endm
;    PNG_PASS_COL_SHIFT macro pass
;      exitm <((pass) > 1? (7 - (pass)) shr 1 : 3)>
;    endm
;    PNG_PASS_ROWS macro height, pass
;      exitm <(((height) + (((1 shl PNG_PASS_ROW_SHIFT(pass)) - 1) - PNG_PASS_START_ROW(pass))) shr PNG_PASS_ROW_SHIFT(pass))>
;    endm
;    PNG_PASS_COLS macro width_, pass
;      exitm <(((width_) + (((1 shl PNG_PASS_COL_SHIFT(pass)) - 1) - PNG_PASS_START_COL(pass))) shr PNG_PASS_COL_SHIFT(pass))>
;    endm
;    PNG_ROW_FROM_PASS_ROW macro y_in, pass
;      exitm <(((y_in) shl PNG_PASS_ROW_SHIFT(pass)) + PNG_PASS_START_ROW(pass))>
;    endm
;    PNG_COL_FROM_PASS_COL macro x_in, pass
;      exitm <(((x_in) shl PNG_PASS_COL_SHIFT(pass)) + PNG_PASS_START_COL(pass))>
;    endm
;    PNG_PASS_MASK macro pass, off
;      exitm <(((110145AFh shr (((7 - (off)) - (pass)) shl 2)) and 0Fh) or ((01145AF0h shr (((7 - (off)) - (pass)) shl 2)) and 0F0h))>
;    endm
;    PNG_ROW_IN_INTERLACE_PASS macro y, pass
;      exitm <((PNG_PASS_MASK(pass, 0) shr ((y) and 7)) and 1)>
;    endm
;    PNG_COL_IN_INTERLACE_PASS macro x, pass
;      exitm <((PNG_PASS_MASK(pass, 1) shr ((x) and 7)) and 1)>
;    endm
;    ifdef PNG_READ_COMPOSITE_NODIV_SUPPORTED
;      png_composite macro composite, fg, alpha, bg
;        exitm <{ png_uint_16 temp = (png_uint_16) ((png_uint_16) (fg) * (png_uint_16) (alpha) + (png_uint_16) (bg) * (png_uint_16) (255 - (png_uint_16) (alpha)) + 128) ; (composite) = (png_byte) (((temp + (temp shr 8)) shr 8) and 0ffh) ; }>
;      endm
;      png_composite_16 macro composite, fg, alpha, bg
;        exitm <{ png_uint_32 temp = (png_uint_32) ((png_uint_32) (fg) * (png_uint_32) (alpha) + (png_uint_32) (bg) * (65535 - (png_uint_32) (alpha)) + 32768) ; (composite) = (png_uint_16) (0ffffh and ((temp + (temp shr 16)) shr 16)) ; }>
;      endm
;    else
;      png_composite macro composite, fg, alpha, bg
;        exitm <(composite) = (png_byte) (0ffh and (((png_uint_16) (fg) * (png_uint_16) (alpha) + (png_uint_16) (bg) * (png_uint_16) (255 - (png_uint_16) (alpha)) + 127) / 255))>
;      endm
;      png_composite_16 macro composite, fg, alpha, bg
;        exitm <(composite) = (png_uint_16) (0ffffh and (((png_uint_32) (fg) * (png_uint_32) (alpha) + (png_uint_32) (bg) * (png_uint_32) (65535 - (png_uint_32) (alpha)) + 32767) / 65535))>
;      endm
;    endif
;    ifdef PNG_READ_INT_FUNCTIONS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :201, :png_uint_32, :png_get_uint_32, :png_const_bytep
;      PNG_EXPORT proto WIN_STD_CALL_CONV :202, :png_uint_16, :png_get_uint_16, :png_const_bytep
;      PNG_EXPORT proto WIN_STD_CALL_CONV :203, :png_int_32, :png_get_int_32, :png_const_bytep
;    endif
;    PNG_EXPORT proto WIN_STD_CALL_CONV :204, :png_uint_32, :png_get_uint_31, :png_const_structrp, :png_const_bytep
;    ifdef PNG_WRITE_INT_FUNCTIONS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :205,, :png_save_uint_32, :png_bytep, :png_uint_32
;    endif
;    ifdef PNG_SAVE_INT_32_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :206,, :png_save_int_32, :png_bytep, :png_int_32
;    endif
;    ifdef PNG_WRITE_INT_FUNCTIONS_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :207,, :png_save_uint_16, :png_bytep, :DWORD
;    endif
;    ifdef PNG_USE_READ_MACROS
;      PNG_get_uint_32 macro buf
;        exitm <(((png_uint_32) (* (buf)) shl 24) + ((png_uint_32) (* ((buf) + 1)) shl 16) + ((png_uint_32) (* ((buf) + 2)) shl 8) + ((png_uint_32) (* ((buf) + 3))))>
;      endm
;      PNG_get_uint_16 macro buf
;        exitm <((png_uint_16) (((* (buf)) shl 8) + ((* ((buf) + 1)))))>
;      endm
;      PNG_get_int_32 macro buf
;        exitm <((png_int_32) ((* (buf) and 80h) ? - ((png_int_32) (((png_get_uint_32 (buf) ^ 0ffffffffh) + 1) and 7fffffffh)) : (png_int_32) png_get_uint_32 (buf)))>
;      endm
;      ifndef PNG_PREFIX
;        png_get_uint_32 macro buf
;          exitm <PNG_get_uint_32(buf)>
;        endm
;        png_get_uint_16 macro buf
;          exitm <PNG_get_uint_16(buf)>
;        endm
;        png_get_int_32 macro buf
;          exitm <PNG_get_int_32(buf)>
;        endm
;      endif
;    else
;      ifdef PNG_PREFIX
;        PNG_get_uint_32 equ <(png_get_uint_32)>
;        PNG_get_uint_16 equ <(png_get_uint_16)>
;        PNG_get_int_32 equ <(png_get_int_32)>
;      endif
;    endif
;    ifdef PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED
;      PNG_EXPORT proto WIN_STD_CALL_CONV :242,, :png_set_check_for_invalid_index, :png_structrp, :SDWORD
;      ifdef PNG_GET_PALETTE_MAX_SUPPORTED
;        PNG_EXPORT proto WIN_STD_CALL_CONV :243, :SDWORD, :png_get_palette_max, :png_const_structp, :png_const_infop
;      endif
;    endif
;    if Defined(PNG_SIMPLIFIED_READ_SUPPORTED) or Defined(PNG_SIMPLIFIED_WRITE_SUPPORTED)
;      PNG_IMAGE_VERSION equ 1
;      png_controlp typedef ptr png_control
;      
;      png_image struct
;        opaque png_controlp ?
;        version png_uint_32 ?
;        width_ png_uint_32 ?
;        height png_uint_32 ?
;        format png_uint_32 ?
;        flags png_uint_32 ?
;        colormap_entries png_uint_32 ?
;        PNG_IMAGE_WARNING equ 1
;        PNG_IMAGE_ERROR equ 2
;        PNG_IMAGE_FAILED macro png_cntrl
;          exitm <((((png_cntrl).warning_or_error) and 03h) > 1)>
;        endm
;        warning_or_error png_uint_32 ?
;        message SBYTE 64 dup (?)
;      png_image ends
;      png_imagep typedef ptr png_image
;      
;      PNG_FORMAT_FLAG_ALPHA equ 01h
;      PNG_FORMAT_FLAG_COLOR equ 02h
;      PNG_FORMAT_FLAG_LINEAR equ 04h
;      PNG_FORMAT_FLAG_COLORMAP equ 08h
;      ifdef PNG_FORMAT_BGR_SUPPORTED
;        PNG_FORMAT_FLAG_BGR equ 10h
;      endif
;      ifdef PNG_FORMAT_AFIRST_SUPPORTED
;        PNG_FORMAT_FLAG_AFIRST equ 20h
;      endif
;      PNG_FORMAT_FLAG_ASSOCIATED_ALPHA equ 40h
;      PNG_FORMAT_GRAY equ 0
;      PNG_FORMAT_GA equ <PNG_FORMAT_FLAG_ALPHA>
;      PNG_FORMAT_AG equ <(PNG_FORMAT_GA or PNG_FORMAT_FLAG_AFIRST)>
;      PNG_FORMAT_RGB equ <PNG_FORMAT_FLAG_COLOR>
;      PNG_FORMAT_BGR equ <(PNG_FORMAT_FLAG_COLOR or PNG_FORMAT_FLAG_BGR)>
;      PNG_FORMAT_RGBA equ <(PNG_FORMAT_RGB or PNG_FORMAT_FLAG_ALPHA)>
;      PNG_FORMAT_ARGB equ <(PNG_FORMAT_RGBA or PNG_FORMAT_FLAG_AFIRST)>
;      PNG_FORMAT_BGRA equ <(PNG_FORMAT_BGR or PNG_FORMAT_FLAG_ALPHA)>
;      PNG_FORMAT_ABGR equ <(PNG_FORMAT_BGRA or PNG_FORMAT_FLAG_AFIRST)>
;      PNG_FORMAT_LINEAR_Y equ <PNG_FORMAT_FLAG_LINEAR>
;      PNG_FORMAT_LINEAR_Y_ALPHA equ <(PNG_FORMAT_FLAG_LINEAR or PNG_FORMAT_FLAG_ALPHA)>
;      PNG_FORMAT_LINEAR_RGB equ <(PNG_FORMAT_FLAG_LINEAR or PNG_FORMAT_FLAG_COLOR)>
;      PNG_FORMAT_LINEAR_RGB_ALPHA equ <(PNG_FORMAT_FLAG_LINEAR or PNG_FORMAT_FLAG_COLOR or PNG_FORMAT_FLAG_ALPHA)>
;      PNG_FORMAT_RGB_COLORMAP equ <(PNG_FORMAT_RGB or PNG_FORMAT_FLAG_COLORMAP)>
;      PNG_FORMAT_BGR_COLORMAP equ <(PNG_FORMAT_BGR or PNG_FORMAT_FLAG_COLORMAP)>
;      PNG_FORMAT_RGBA_COLORMAP equ <(PNG_FORMAT_RGBA or PNG_FORMAT_FLAG_COLORMAP)>
;      PNG_FORMAT_ARGB_COLORMAP equ <(PNG_FORMAT_ARGB or PNG_FORMAT_FLAG_COLORMAP)>
;      PNG_FORMAT_BGRA_COLORMAP equ <(PNG_FORMAT_BGRA or PNG_FORMAT_FLAG_COLORMAP)>
;      PNG_FORMAT_ABGR_COLORMAP equ <(PNG_FORMAT_ABGR or PNG_FORMAT_FLAG_COLORMAP)>
;      PNG_IMAGE_SAMPLE_CHANNELS macro fmt
;        exitm <(((fmt) and (PNG_FORMAT_FLAG_COLOR or PNG_FORMAT_FLAG_ALPHA)) + 1)>
;      endm
;      PNG_IMAGE_SAMPLE_COMPONENT_SIZE macro fmt
;        exitm <((((fmt) and PNG_FORMAT_FLAG_LINEAR) shr 2) + 1)>
;      endm
;      PNG_IMAGE_SAMPLE_SIZE macro fmt
;        exitm <(PNG_IMAGE_SAMPLE_CHANNELS(fmt) * PNG_IMAGE_SAMPLE_COMPONENT_SIZE(fmt))>
;      endm
;      PNG_IMAGE_MAXIMUM_COLORMAP_COMPONENTS macro fmt
;        exitm <(PNG_IMAGE_SAMPLE_CHANNELS(fmt) * 256)>
;      endm
;      PNG_IMAGE_PIXEL_ macro test_, fmt
;        exitm <(((fmt) and PNG_FORMAT_FLAG_COLORMAP) ?1 : test_ (fmt))>
;      endm
;      PNG_IMAGE_PIXEL_CHANNELS macro fmt
;        exitm <PNG_IMAGE_PIXEL_(PNG_IMAGE_SAMPLE_CHANNELS, fmt)>
;      endm
;      PNG_IMAGE_PIXEL_COMPONENT_SIZE macro fmt
;        exitm <PNG_IMAGE_PIXEL_(PNG_IMAGE_SAMPLE_COMPONENT_SIZE, fmt)>
;      endm
;      PNG_IMAGE_PIXEL_SIZE macro fmt
;        exitm <PNG_IMAGE_PIXEL_(PNG_IMAGE_SAMPLE_SIZE, fmt)>
;      endm
;      PNG_IMAGE_ROW_STRIDE macro image
;        exitm <(PNG_IMAGE_PIXEL_CHANNELS((image).format) * (image).width)>
;      endm
;      PNG_IMAGE_BUFFER_SIZE macro image, row_stride
;        exitm <(PNG_IMAGE_PIXEL_COMPONENT_SIZE((image).format) * (image).height * (row_stride))>
;      endm
;      PNG_IMAGE_SIZE macro image
;        exitm <PNG_IMAGE_BUFFER_SIZE(image, PNG_IMAGE_ROW_STRIDE(image))>
;      endm
;      PNG_IMAGE_COLORMAP_SIZE macro image
;        exitm <(PNG_IMAGE_SAMPLE_SIZE((image).format) * (image).colormap_entries)>
;      endm
;      PNG_IMAGE_FLAG_COLORSPACE_NOT_sRGB equ 01h
;      PNG_IMAGE_FLAG_FAST equ 02h
;      PNG_IMAGE_FLAG_16BIT_sRGB equ 04h
;      ifdef PNG_SIMPLIFIED_READ_SUPPORTED
;        ifdef PNG_STDIO_SUPPORTED
;          PNG_EXPORT proto WIN_STD_CALL_CONV :234, :SDWORD, :png_image_begin_read_from_file, :png_imagep, :ptr SBYTE
;          PNG_EXPORT proto WIN_STD_CALL_CONV :235, :SDWORD, :png_image_begin_read_from_stdio, :png_imagep, :ptr FILE
;        endif
;        PNG_EXPORT proto WIN_STD_CALL_CONV :236, :SDWORD, :png_image_begin_read_from_memory, :png_imagep, :png_const_voidp, :size_t
;        PNG_EXPORT proto WIN_STD_CALL_CONV :237, :SDWORD, :png_image_finish_read, :png_imagep, :png_const_colorp, :ptr, :png_int_32, :ptr
;        PNG_EXPORT proto WIN_STD_CALL_CONV :238,, :png_image_free, :png_imagep
;      endif
;      ifdef PNG_SIMPLIFIED_WRITE_SUPPORTED
;        ifdef PNG_SIMPLIFIED_WRITE_STDIO_SUPPORTED
;          PNG_EXPORT proto WIN_STD_CALL_CONV :239, :SDWORD, :png_image_write_to_file, :png_imagep, :ptr SBYTE, :SDWORD, :ptr, :png_int_32, :ptr
;          PNG_EXPORT proto WIN_STD_CALL_CONV :240, :SDWORD, :png_image_write_to_stdio, :png_imagep, :ptr FILE, :SDWORD, :ptr, :png_int_32, :ptr
;        endif
;        PNG_EXPORT proto WIN_STD_CALL_CONV :245, :SDWORD, :png_image_write_to_memory, :png_imagep, :ptr, :ptr png_alloc_size_t, :SDWORD, :ptr, :png_int_32, :ptr
;        png_image_write_get_memory_size macro image, size_, convert_to_8_bit, buffer, row_stride, colormap
;          exitm <png_image_write_to_memory (and (image), 0, and (size_), convert_to_8_bit, buffer, row_stride, colormap)>
;        endm
;        PNG_IMAGE_DATA_SIZE macro image
;          exitm <(PNG_IMAGE_SIZE(image) + (image).height)>
;        endm
;        ifndef PNG_ZLIB_MAX_SIZE
;          PNG_ZLIB_MAX_SIZE macro b
;            exitm <((b) + (((b) + 7) shr 3) + (((b) + 63) shr 6) + 11)>
;          endm
;        endif
;        PNG_IMAGE_COMPRESSED_SIZE_MAX macro image
;          exitm <PNG_ZLIB_MAX_SIZE((png_alloc_size_t) PNG_IMAGE_DATA_SIZE(image))>
;        endm
;        PNG_IMAGE_PNG_SIZE_MAX_ macro image, image_size
;          exitm <((8 + 25 + 16 + 44 + 12 + (((image).format and PNG_FORMAT_FLAG_COLORMAP) ? 12 + 3 * (image).colormap_entries + (((image).format and PNG_FORMAT_FLAG_ALPHA) ? 12 + (image).colormap_entries : 0) : 0) + 12) + (12 * ((image_size) / PNG_ZBUF_SIZE)) + (image_size))>
;        endm
;        PNG_IMAGE_PNG_SIZE_MAX macro image
;          exitm <PNG_IMAGE_PNG_SIZE_MAX_(image, PNG_IMAGE_COMPRESSED_SIZE_MAX(image))>
;        endm
;      endif
;    endif
;    ifdef PNG_SET_OPTION_SUPPORTED
;      ifdef PNG_ARM_NEON_API_SUPPORTED
;        PNG_ARM_NEON equ 0
;      endif
;      PNG_MAXIMUM_INFLATE_WINDOW equ 2
;      PNG_SKIP_sRGB_CHECK_PROFILE equ 4
;      ifdef PNG_MIPS_MSA_API_SUPPORTED
;        PNG_MIPS_MSA equ 6
;      endif
;      PNG_IGNORE_ADLER32 equ 8
;      ifdef PNG_POWERPC_VSX_API_SUPPORTED
;        PNG_POWERPC_VSX equ 10
;      endif
;      PNG_OPTION_NEXT equ 12
;      PNG_OPTION_UNSET equ 0
;      PNG_OPTION_INVALID equ 1
;      PNG_OPTION_OFF equ 2
;      PNG_OPTION_ON equ 3
;      PNG_EXPORT proto WIN_STD_CALL_CONV :244, :SDWORD, :png_set_option, :png_structrp, :SDWORD, :SDWORD
;    endif
;    ifdef PNG_EXPORT_LAST_ORDINAL
;      PNG_EXPORT_LAST_ORDINAL proto WIN_STD_CALL_CONV :249
;    endif
;    ifdef __cplusplus
;      ;[...]
;    endif
  endif
endif
 