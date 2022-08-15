
option nokeyword:<this>
option nokeyword:<name>

ifdef __UASM__
elseifdef __JWASM__
elseifdef __ASMC__
else
  SQWORD typedef QWORD    ;Ugly, but MASM 6.15 does not know about SQWORD
endif

void                      equ   <>
TRUE                      equ   1                     ;Compatible with Windows_XX.inc
FALSE                     equ   0
NULL                      equ   0

;Some basic type definitions
POINTER               typedef     ptr
HANDLE                typedef     ptr

;---------------------------------------------------------------------------
; Constants and Types
;---------------------------------------------------------------------------
if TARGET_BITNESS eq 32
  EFIERR                    = 0x80000000
else
  EFIERR                    = 0x8000000000000000
endif
EFI_ERROR                   = EFIERR
EFI_SUCCESS                 = 0
EFI_LOAD_ERROR              = EFIERR OR 1
EFI_INVALID_PARAMETER       = EFIERR OR 2
EFI_UNSUPPORTED             = EFIERR OR 3
EFI_BAD_BUFFER_SIZE         = EFIERR OR 4
EFI_BUFFER_TOO_SMALL        = EFIERR OR 5
EFI_NOT_READY               = EFIERR OR 6
EFI_DEVICE_ERROR            = EFIERR OR 7
EFI_WRITE_PROTECTED         = EFIERR OR 8
EFI_OUT_OF_RESOURCES        = EFIERR OR 9
EFI_VOLUME_CORRUPTED        = EFIERR OR 10
EFI_VOLUME_FULL             = EFIERR OR 11
EFI_NO_MEDIA                = EFIERR OR 12
EFI_MEDIA_CHANGED           = EFIERR OR 13
EFI_NOT_FOUND               = EFIERR OR 14
EFI_ACCESS_DENIED           = EFIERR OR 15
EFI_NO_RESPONSE             = EFIERR OR 16
EFI_NO_MAPPING              = EFIERR OR 17
EFI_TIMEOUT                 = EFIERR OR 18
EFI_NOT_STARTED             = EFIERR OR 19
EFI_ALREADY_STARTED         = EFIERR OR 20
EFI_ABORTED                 = EFIERR OR 21
EFI_ICMP_ERROR              = EFIERR OR 22
EFI_TFTP_ERROR              = EFIERR OR 23
EFI_PROTOCOL_ERROR          = EFIERR OR 24



ifndef Defined
  Defined macro x
    ifdef x
      exitm <-1>                                      ;-1 to be able to use the 'NOT' operator.
    else                                              ;Not(-1) = 0 (FALSE)
      exitm <0>
    endif
  endm
endif

ifndef @Align
  @align equ <>
endif

if TARGET_BITNESS eq 64
  XWORD               typedef   QWORD
  SXWORD              typedef   SQWORD
  size_t              typedef   QWORD
else
  XWORD               typedef   DWORD
  SXWORD              typedef   SDWORD
  size_t              typedef   DWORD
endif

;Macro to define a prototype, either using an indirect call or an IAT thunk
;Link: https://msdn.microsoft.com/en-us/library/56h2zst2.aspx
;      https://msdn.microsoft.com/en-us/library/zxk0tw93.aspx
;      https://msdn.microsoft.com/en-us/library/zkwh89ks.aspx
;Note: in Windows x64, the only calling Convention is 'fastcall' or its extension 'vectorcall',
;      whereas in x86, we can find 'c', 'pascal', 'stdcall', 'thiscall', etc.

if TARGET_BITNESS eq 64
  WIN_STD_CALL_CONV equ <fastcall>
  @DefProto macro ApiQual, ProcName, CallConv, NameSuffix, Params, DecorSuffix
    ifdif <CallConv>, <vectorcall>
      ??CallConv equ <fastcall>
    else
      ??CallConv equ <&CallConv>
    endif

    ifidn <ApiQual>, <DllImport>                      ;;Call [IAT], a bit faster
      TYPE_&ProcName typedef proto ??CallConv Params
      externdef __imp_&ProcName: ptr TYPE_&ProcName
      ProcName&NameSuffix equ <__imp_&ProcName>
    else
      ProcName&NameSuffix proto ??CallConv Params     ;;Call thunk (jmp [IAT])
    endif
  endm

else
  WIN_STD_CALL_CONV equ <stdcall>
  @DefProto macro ApiQual, ProcName, CallConv, NameSuffix, Params, DecorSuffix

    ifidn <ApiQual>, <DllImport>                      ;;Call [IAT], a bit faster
      TYPE_&ProcName typedef proto CallConv Params
      ifnb <DecorSuffix>
        externdef CallConv _imp__&ProcName&@&DecorSuffix: ptr TYPE_&ProcName
        ProcName&NameSuffix equ <_imp__&ProcName&@&DecorSuffix>
      else
        externdef c _imp__&ProcName: ptr TYPE_&ProcName
        ProcName&NameSuffix equ <_imp__&ProcName>
      endif
    else
      ProcName&NameSuffix proto CallConv Params       ;;Call thunk (jmp [IAT])
    endif
  endm
endif


INT8       TYPEDEF SBYTE
UINT8      TYPEDEF BYTE
INT16      TYPEDEF SWORD
UINT16     TYPEDEF WORD
INT32      TYPEDEF SDWORD
UINT32     TYPEDEF DWORD
INT64      TYPEDEF SQWORD
UINT64     TYPEDEF QWORD
INTN       TYPEDEF SXWORD
UINTN      TYPEDEF XWORD
DPTR       TYPEDEF PTR
EFI_STATUS TYPEDEF UINTN
EFI_LBA    TYPEDEF UINT64
EFI_TPL    TYPEDEF UINTN
EFI_HANDLE TYPEDEF PTR
EFI_EVENT  TYPEDEF PTR
CHAR16     TYPEDEF WORD
BOOLEAN    TYPEDEF UINT8

P_UINTN    TYPEDEF PTR UINTN
P_UINT8    TYPEDEF PTR UINT8
P_UINT32   TYPEDEF PTR UINT32
P_CHAR16   TYPEDEF PTR CHAR16

EFI_GUID STRUCT
  Data1 UINT32 ?
  Data2 UINT16 ?
  Data3 UINT16 ?
  Data4 UINT8 8 DUP(?)
EFI_GUID ENDS

;---------------------------------------------------------------------------
; Time
;---------------------------------------------------------------------------
EFI_TIME STRUCT
  Year       UINT16 ?  ; 1998 - 20XX
  Month      UINT8  ?  ; 1 - 12
  Day        UINT8  ?  ; 1 - 31
  Hour       UINT8  ?  ; 0 - 23
  Minute     UINT8  ?  ; 0 - 59
  Second     UINT8  ?  ; 0 - 59
  Pad1       UINT8  ?
  Nanosecond UINT32 ?  ; 0 - 999,999,999
  TimeZone   INT16  ?  ; -1440 to 1440 or 2047
  Daylight   UINT8  ?
  Pad2       UINT8  ?
EFI_TIME ENDS

; Bit definitions for EFI_TIME.Daylight
EFI_TIME_ADJUST_DAYLIGHT equ 0x01
EFI_TIME_IN_DAYLIGHT     equ 0x02

; Value definition for EFI_TIME.TimeZone
EFI_UNSPECIFIED_TIMEZONE equ 0x07FF

;*******************************************************
; EFI_TIME_CAPABILITIES
;*******************************************************
; This provides the capabilities of the real time clock device as exposed through the EFI interfaces.
EFI_TIME_CAPABILITIES STRUCT
  Resolution  UINT32 ?
  Accuracy    UINT32 ?
  SetsToZero BOOLEAN ?
EFI_TIME_CAPABILITIES ENDS

;---------------------------------------------------------------------------
; Networking
;---------------------------------------------------------------------------
EFI_IPv4_ADDRESS STRUCT
  _Addr UINT8 4 DUP(?)
EFI_IPv4_ADDRESS ENDS

EFI_IPv6_ADDRESS STRUCT
  _Addr UINT8 16 DUP(?)
EFI_IPv6_ADDRESS ENDS

EFI_MAC_ADDRESS STRUCT
  _Addr UINT8 32 DUP(?)
EFI_MAC_ADDRESS ENDS

;---------------------------------------------------------------------------
; Memory
;---------------------------------------------------------------------------
EFI_PHYSICAL_ADDRESS   TYPEDEF UINT64
EFI_VIRTUAL_ADDRESS    TYPEDEF UINT64
P_EFI_PHYSICAL_ADDRESS TYPEDEF PTR EFI_PHYSICAL_ADDRESS
P_EFI_VIRTUAL_ADDRESS  TYPEDEF PTR EFI_VIRTUAL_ADDRESS

EFI_ALLOCATE_TYPE_AllocateAnyPages   equ 0x00
EFI_ALLOCATE_TYPE_AllocateMaxAddress equ 0x01
EFI_ALLOCATE_TYPE_AllocateAddress    equ 0x02
EFI_ALLOCATE_TYPE_MaxAllocateType    equ 0x03
EFI_ALLOCATE_TYPE TYPEDEF INT32

; possible caching types for the memory range
EFI_MEMORY_UC  equ 0x0000000000000001
EFI_MEMORY_WC  equ 0x0000000000000002
EFI_MEMORY_WT  equ 0x0000000000000004
EFI_MEMORY_WB  equ 0x0000000000000008
EFI_MEMORY_UCE equ 0x0000000000000010

; physical memory protection on range
EFI_MEMORY_WP equ 0x0000000000001000
EFI_MEMORY_RP equ 0x0000000000002000
EFI_MEMORY_XP equ 0x0000000000004000

EFI_MEMORY_NV            equ 0x0000000000008000
EFI_MEMORY_MORE_RELIABLE equ 0x0000000000010000
EFI_MEMORY_RO            equ 0x0000000000020000

; range requires a runtime mapping
EFI_MEMORY_RUNTIME equ 0x8000000000000000

; Preseve the attr on any range supplied.
; ConventialMemory must have WB,SR,SW when supplied.
; When allocating from ConventialMemory always make it WB,SR,SW
; When returning to ConventialMemory always make it WB,SR,SW
; When getting the memory map, or on RT for runtime types

EFI_MEMORY_TYPE_EfiReservedMemoryType = 0
EFI_MEMORY_TYPE_EfiLoaderCode = 1
EFI_MEMORY_TYPE_EfiLoaderData = 2
EFI_MEMORY_TYPE_EfiBootServicesCode = 3
EFI_MEMORY_TYPE_EfiBootServicesData = 4
EFI_MEMORY_TYPE_EfiRuntimeServicesCode = 5
EFI_MEMORY_TYPE_EfiRuntimeServicesData = 6
EFI_MEMORY_TYPE_EfiConventionalMemory = 7
EFI_MEMORY_TYPE_EfiUnusableMemory = 8
EFI_MEMORY_TYPE_EfiACPIReclaimMemory = 9
EFI_MEMORY_TYPE_EfiACPIMemoryNVS = 10
EFI_MEMORY_TYPE_EfiMemoryMappedIO = 11
EFI_MEMORY_TYPE_EfiMemoryMappedIOPortSpace = 12
EFI_MEMORY_TYPE_EfiPalCode = 13
EFI_MEMORY_TYPE_EfiMaxMemoryType = 14
EFI_MEMORY_TYPE TYPEDEF INT32

EFI_MEMORY_DESCRIPTOR_VERSION equ 1

EFI_MEMORY_DESCRIPTOR STRUCT
  _Type         UINT32 ?
  PhysicalStart EFI_PHYSICAL_ADDRESS ?
  VirtualStart  EFI_VIRTUAL_ADDRESS ?
  NumberOfPages UINT64 ?
  Attribute     UINT64 ?
EFI_MEMORY_DESCRIPTOR ENDS

P_EFI_MEMORY_DESCRIPTOR TYPEDEF PTR EFI_MEMORY_DESCRIPTOR

EFI_OPTIONAL_PTR equ 0x00000001

;---------------------------------------------------------------------------
; International Language
;---------------------------------------------------------------------------
ISO_639_2 TYPEDEF UINT8
ISO_639_2_ENTRY_SIZE = 3

EFI_PAGE_SIZE  equ 4096
EFI_PAGE_MASK  equ 0xFFF
EFI_PAGE_SHIFT equ 12

;EFI_SIZE_TO_PAGES MACRO a:REQ
;    ( ((a) >> EFI_PAGE_SHIFT) + (((a) & EFI_PAGE_MASK) ? 1 : 0) )
;ENDM

;---------------------------------------------------------------------------
; Task priority level
;---------------------------------------------------------------------------
TPL_APPLICATION equ 4
TPL_CALLBACK    equ 8
TPL_NOTIFY      equ 16
TPL_HIGH_LEVEL  equ 31

;---------------------------------------------------------------------------
; EFI Events
;---------------------------------------------------------------------------
EFI_EVENT TYPEDEF PTR
; These types can be “ORed” together as needed – for example,
; EVT_TIMER might be “Ored” with EVT_NOTIFY_WAIT or EVT_NOTIFY_SIGNAL.
EVT_TIMER                         equ 0x80000000
EVT_RUNTIME                       equ 0x40000000
EVT_RUNTIME_CONTEXT               equ 0x20000000
EVT_NOTIFY_WAIT                   equ 0x00000100
EVT_NOTIFY_SIGNAL                 equ 0x00000200
EVT_SIGNAL_EXIT_BOOT_SERVICES     equ 0x00000201
EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE equ 0x60000202
EVT_EFI_SIGNAL_MASK               equ 0x000000FF
EVT_EFI_SIGNAL_MAX                equ 2

EFI_TimerCancel   equ 0
EFI_TimerPeriodic equ 1
EFI_TimerRelative equ 2
EFI_TimerTypeMax  equ 3
EFI_TIMER_DELAY TYPEDEF INT32

;*******************************************************
; EFI_EVENT_NOTIFY
;*******************************************************
;typedef VOID (EFIAPI *EFI_EVENT_NOTIFY) (IN EFI_EVENT Event, IN VOID *Context);
EFI_EVENT_NOTIFY TYPEDEF PROTO Event:EFI_EVENT, pContext:PTR
P_EFI_EVENT_NOTIFY TYPEDEF PTR EFI_EVENT_NOTIFY

EFI_SYSTEM_TABLE_CONOUT                      equ 64
EFI_SYSTEM_TABLE_RUNTIMESERVICES             equ 88
EFI_SYSTEM_TABLE_BOOTSERVICES                equ 96
EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_RESET        equ 0
EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_OUTPUTSTRING equ 8
EFI_BOOT_SERVICES_GETMEMORYMAP               equ 56
EFI_BOOT_SERVICES_LOCATEHANDLE               equ 176
EFI_BOOT_SERVICES_LOADIMAGE                  equ 200
EFI_BOOT_SERVICES_EXIT                       equ 216
EFI_BOOT_SERVICES_EXITBOOTSERVICES           equ 232
EFI_BOOT_SERVICES_LOCATEPROTOCOL             equ 320
EFI_RUNTIME_SERVICES_RESETSYSTEM             equ 104

; Generic EFI Table Header Structure
EFI_TABLE_HEADER STRUCT
  Signature        UINT64 ?
  Revision         UINT32 ?
  HeaderSize       UINT32 ?
  CRC32_            UINT32 ?
  Reserved         UINT32 ?
EFI_TABLE_HEADER ENDS

EFI_INPUT_KEY STRUCT
  ScanCode    CHAR16 ?
  UnicodeChar CHAR16 ?
EFI_INPUT_KEY ENDS
P_EFI_INPUT_KEY TYPEDEF PTR EFI_INPUT_KEY

EFI_KEY_STATE struct
  KeyShiftState   dd ?
  KeyToggleState  db ? ; EFI_KEY_TOGGLE_STATE
EFI_KEY_STATE ends
P_EFI_KEY_STATE TYPEDEF PTR EFI_KEY_STATE

EFI_KEY_DATA struct
  Key       EFI_INPUT_KEY {?}
  KeyState  EFI_KEY_STATE {?}
EFI_KEY_DATA ends
P_EFI_KEY_DATA TYPEDEF PTR EFI_KEY_DATA

EFI_KEY_TOGGLE_STATE TYPEDEF UINT8
P_EFI_KEY_TOGGLE_STATE TYPEDEF PTR EFI_KEY_TOGGLE_STATE

; dword KeyShiftState:
EFI_SHIFT_STATE_VALID        equ 0x80000000
EFI_RIGHT_SHIFT_PRESSED      equ 0x00000001
EFI_LEFT_SHIFT_PRESSED       equ 0x00000002
EFI_RIGHT_CONTROL_PRESSED    equ 0x00000004
EFI_LEFT_CONTROL_PRESSED     equ 0x00000008
EFI_RIGHT_ALT_PRESSED        equ 0x00000010
EFI_LEFT_ALT_PRESSED         equ 0x00000020
EFI_RIGHT_LOGO_PRESSED       equ 0x00000040
EFI_LEFT_LOGO_PRESSED        equ 0x00000080
EFI_MENU_KEY_PRESSED         equ 0x00000100
EFI_SYS_REQ_PRESSED          equ 0x00000200

; byte EFI_KEY_TOGGLE_STATE:
EFI_SCROLL_LOCK_ACTIVE       equ 0x01
EFI_NUM_LOCK_ACTIVE          equ 0x02
EFI_CAPS_LOCK_ACTIVE         equ 0x04
EFI_KEY_STATE_EXPOSED        equ 0x40
EFI_TOGGLE_STATE_VALID       equ 0x80


;---------------------------------------------------------------------------
; EFI Device Path
;---------------------------------------------------------------------------

EFI_DEVICE_PATH STRUCT
  _Type   UINT8 ?
    SubType UINT8 ?
    _Length UINT8 2 DUP (?)
EFI_DEVICE_PATH ENDS

EFI_DEVICE_PATH_PROTOCOL TYPEDEF EFI_DEVICE_PATH

EFI_DP_TYPE_MASK                    equ 0x7F
EFI_DP_TYPE_UNPACKED                equ 0x80
END_DEVICE_PATH_TYPE                equ 0x7f
END_ENTIRE_DEVICE_PATH_SUBTYPE      equ 0xff
END_INSTANCE_DEVICE_PATH_SUBTYPE    equ 0x01
END_DEVICE_PATH_LENGTH              equ (sizeof(EFI_DEVICE_PATH))

;---------------------------------------------------------------------------
; Interface Types
;---------------------------------------------------------------------------
EFI_NATIVE_INTERFACE equ 0
EFI_PCODE_INTERFACE  equ 1
EFI_INTERFACE_TYPE TYPEDEF INT32

;---------------------------------------------------------------------------
; Search Types
;---------------------------------------------------------------------------
EFI_SEARCH_AllHandles       equ 0
EFI_SEARCH_ByRegisterNotify equ 1
EFI_SEARCH_ByProtocol       equ 2
EFI_LOCATE_SEARCH_TYPE TYPEDEF INT32

;---------------------------------------------------------------------------
; EFI Reset Types
;---------------------------------------------------------------------------
EFI_RESET_EfiResetCold equ 0
EFI_RESET_EfiResetWarm equ 1
EFI_RESET_TYPE TYPEDEF INT32

;---------------------------------------------------------------------------
; EFI Protocol Definitions
;---------------------------------------------------------------------------
EFI_OPEN_PROTOCOL_INFORMATION_ENTRY STRUCT
  AgentHandle      EFI_HANDLE ?
  ControllerHandle EFI_HANDLE ?
  Attributes       UINT32 ?
  OpenCount        UINT32 ?
EFI_OPEN_PROTOCOL_INFORMATION_ENTRY ENDS

; *******************************************************
; EFI_LOAD_FILE_PROTOCOL
; *******************************************************
RAWINTERFACE _EFI_LOAD_FILE_PROTOCOL
  STDFUNC LoadFile, <voidarg>, pThis:PTR, FilePath:PTR EFI_DEVICE_PATH_PROTOCOL, BootPolicy:BOOLEAN, BufferSize:P_UINTN, Buffer:PTR
ENDRAWINTERFACE
PLOADFILE TYPEDEF PTR _EFI_LOAD_FILE_PROTOCOL

; *******************************************************
; EFI_FILE_PROTOCOL
; *******************************************************
RAWINTERFACE EFI_FILE_HANDLE
  Revision UINT64 ?
  STDFUNC Open, <voidarg>, pThis:PTR, NewHandle:PTR PFILE, FileName:PTR, OpenMode:UINT64, Attributes:UINT64
  STDFUNC Close, <voidarg>, pThis:PTR
  STDFUNC Delete, <voidarg>, pThis:PTR
  STDFUNC Read, <voidarg>, pThis:PTR, BufferSize:PTR UINTN, Buffer:PTR
    ;EFI_FILE_WRITE          Write;
    ;EFI_FILE_GET_POSITION   GetPosition;
    ;EFI_FILE_SET_POSITION   SetPosition;
    ;EFI_FILE_GET_INFO       GetInfo;
    ;EFI_FILE_SET_INFO       SetInfo;
    ;EFI_FILE_FLUSH          Flush;
  ;EFI_FILE_OPEN_EX OpenEx; // Added for revision 2
  ;EFI_FILE_READ_EX ReadEx; // Added for revision 2
  ;EFI_FILE_WRITE_EX WriteEx; // Added for revision 2
  ;EFI_FILE_FLUSH_EX FlushEx; // Added for revision 2
ENDRAWINTERFACE
PFILE TYPEDEF PTR EFI_FILE_HANDLE

EFI_FILE_INFO STRUCT
  _Size            UINT64 ?
  FileSize         UINT64 ?
  PhysicalSize     UINT64 ?
  CreateTime       EFI_TIME <?>
  LastAccessTime   EFI_TIME <?>
  ModificationTime EFI_TIME <?>
  Attribute        UINT64 ?
  FileName         dw ?
EFI_FILE_INFO ENDS

EFI_FILE_SYSTEM_INFO STRUCT
  _Size       UINT64 ?
  ReadOnly    BOOLEAN ?
  VolumeSize  UINT64 ?
  FreeSpace   UINT64 ?
  BlockSize   UINT32 ?
  VolumeLabel dw ?
EFI_FILE_SYSTEM_INFO ENDS

;*******************************************************
; Open Modes
;*******************************************************
EFI_FILE_MODE_READ   equ 0x0000000000000001
EFI_FILE_MODE_WRITE  equ 0x0000000000000002
EFI_FILE_MODE_CREATE equ 0x8000000000000000

;*******************************************************
; File Attributes
;*******************************************************
EFI_FILE_READ_ONLY  equ 0x0000000000000001
EFI_FILE_HIDDEN     equ 0x0000000000000002
EFI_FILE_SYSTEM     equ 0x0000000000000004
EFI_FILE_RESERVED   equ 0x0000000000000008
EFI_FILE_DIRECTORY  equ 0x0000000000000010
EFI_FILE_ARCHIVE    equ 0x0000000000000020
EFI_FILE_VALID_ATTR equ 0x0000000000000037

; *******************************************************
; EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
; *******************************************************
RAWINTERFACE EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
  Revision UINT64 ?
  STDFUNC OpenVolume, <voidarg>, pThis:PTR, Root:PTR PFILE
ENDRAWINTERFACE
PFILESYS TYPEDEF PTR EFI_SIMPLE_FILE_SYSTEM_PROTOCOL

; *******************************************************
; EFI_SIMPLE_POINTER_MODE
; *******************************************************
EFI_SIMPLE_POINTER_MODE STRUCT
  ResolutionX  UINT64  ?    ; Resolution X-Axis in counts/mm. 0 = x-axis not supported.
  ResolutionY  UINT64  ?    ; Resolution Y-Axis in counts/mm. 0 = y-axis not supported.
  ResolutionZ  UINT64  ?    ; Resolution Z-Axis in counts/mm. 0 = z-axis not supported.
  LeftButton   BOOLEAN ?    ; TRUE = pressed, FALSE = not
  RightButton  BOOLEAN ?    ; TRUE = pressed, FALSE = not
EFI_SIMPLE_POINTER_MODE ENDS
P_EFI_SIMPLE_POINTER_MODE TYPEDEF PTR EFI_SIMPLE_POINTER_MODE

EFI_SIMPLE_POINTER_STATE STRUCT
  RelativeMovementX INT32 ?
  RelativeMovementY INT32 ?
  RelativeMovementZ INT32 ?
  LeftButton        BOOLEAN ?
  RightButton       BOOLEAN ?
EFI_SIMPLE_POINTER_STATE ENDS
P_EFI_SIMPLE_POINTER_STATE TYPEDEF PTR EFI_SIMPLE_POINTER_STATE

RAWINTERFACE EFI_SIMPLE_POINTER_PROTOCOL
  STDFUNC Reset, <voidarg>, pThis:PTR, ExtendedVerification:BOOLEAN
  STDFUNC GetState, <voidarg>, pThis:PTR, pState:P_EFI_SIMPLE_POINTER_STATE
  WaitForInput EFI_EVENT ?
  Mode P_EFI_SIMPLE_POINTER_MODE ?
ENDRAWINTERFACE

; *******************************************************
; SIMPLE_TEXT_OUTPUT_MODE
; *******************************************************
SIMPLE_TEXT_OUTPUT_MODE STRUCT
  MaxMode       INT32 ?
  Mode          INT32 ?
  Attribute     INT32 ?
  CursorColumn  INT32 ?
  CursorRow     INT32 ?
  CursorVisible BOOLEAN ?
SIMPLE_TEXT_OUTPUT_MODE ENDS
P_SIMPLE_TEXT_OUTPUT_MODE TYPEDEF PTR SIMPLE_TEXT_OUTPUT_MODE

;*******************************************************
; UNICODE DRAWING CHARACTERS
;*******************************************************
BOXDRAW_HORIZONTAL                 equ 0x2500
BOXDRAW_VERTICAL                   equ 0x2502
BOXDRAW_DOWN_RIGHT                 equ 0x250c
BOXDRAW_DOWN_LEFT                  equ 0x2510
BOXDRAW_UP_RIGHT                   equ 0x2514
BOXDRAW_UP_LEFT                    equ 0x2518
BOXDRAW_VERTICAL_RIGHT             equ 0x251c
BOXDRAW_VERTICAL_LEFT              equ 0x2524
BOXDRAW_DOWN_HORIZONTAL            equ 0x252c
BOXDRAW_UP_HORIZONTAL              equ 0x2534
BOXDRAW_VERTICAL_HORIZONTAL        equ 0x253c
BOXDRAW_DOUBLE_HORIZONTAL          equ 0x2550
BOXDRAW_DOUBLE_VERTICAL            equ 0x2551
BOXDRAW_DOWN_RIGHT_DOUBLE          equ 0x2552
BOXDRAW_DOWN_DOUBLE_RIGHT          equ 0x2553
BOXDRAW_DOUBLE_DOWN_RIGHT          equ 0x2554
BOXDRAW_DOWN_LEFT_DOUBLE           equ 0x2555
BOXDRAW_DOWN_DOUBLE_LEFT           equ 0x2556
BOXDRAW_DOUBLE_DOWN_LEFT           equ 0x2557
BOXDRAW_UP_RIGHT_DOUBLE            equ 0x2558
BOXDRAW_UP_DOUBLE_RIGHT            equ 0x2559
BOXDRAW_DOUBLE_UP_RIGHT            equ 0x255a
BOXDRAW_UP_LEFT_DOUBLE             equ 0x255b
BOXDRAW_UP_DOUBLE_LEFT             equ 0x255c
BOXDRAW_DOUBLE_UP_LEFT             equ 0x255d
BOXDRAW_VERTICAL_RIGHT_DOUBLE      equ 0x255e
BOXDRAW_VERTICAL_DOUBLE_RIGHT      equ 0x255f
BOXDRAW_DOUBLE_VERTICAL_RIGHT      equ 0x2560
BOXDRAW_VERTICAL_LEFT_DOUBLE       equ 0x2561
BOXDRAW_VERTICAL_DOUBLE_LEFT       equ 0x2562
BOXDRAW_DOUBLE_VERTICAL_LEFT       equ 0x2563
BOXDRAW_DOWN_HORIZONTAL_DOUBLE     equ 0x2564
BOXDRAW_DOWN_DOUBLE_HORIZONTAL     equ 0x2565
BOXDRAW_DOUBLE_DOWN_HORIZONTAL     equ 0x2566
BOXDRAW_UP_HORIZONTAL_DOUBLE       equ 0x2567
BOXDRAW_UP_DOUBLE_HORIZONTAL       equ 0x2568
BOXDRAW_DOUBLE_UP_HORIZONTAL       equ 0x2569
BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE equ 0x256a
BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL equ 0x256b
BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL equ 0x256c
;*******************************************************
; EFI Required Block Elements Code Chart
;*******************************************************
BLOCKELEMENT_FULL_BLOCK  equ 0x2588
BLOCKELEMENT_LIGHT_SHADE equ 0x2591
;*******************************************************
; EFI Required Geometric Shapes Code Chart
;*******************************************************
GEOMETRICSHAPE_UP_TRIANGLE    equ 0x25b2
GEOMETRICSHAPE_RIGHT_TRIANGLE equ 0x25ba
GEOMETRICSHAPE_DOWN_TRIANGLE  equ 0x25bc
GEOMETRICSHAPE_LEFT_TRIANGLE  equ 0x25c4
;*******************************************************
; EFI Required Arrow shapes
;*******************************************************
ARROW_UP   equ 0x2191
ARROW_DOWN equ 0x2193

;*******************************************************
; Attributes
;*******************************************************
EFI_BLACK                equ 0x00
EFI_BLUE                 equ 0x01
EFI_GREEN                equ 0x02
EFI_CYAN                 equ 0x03
EFI_RED                  equ 0x04
EFI_MAGENTA              equ 0x05
EFI_BROWN                equ 0x06
EFI_LIGHTGRAY            equ 0x07
EFI_BRIGHT               equ 0x08
EFI_DARKGRAY             equ (EFI_BLACK OR EFI_BRIGHT)
EFI_LIGHTBLUE            equ 0x09
EFI_LIGHTGREEN           equ 0x0A
EFI_LIGHTCYAN            equ 0x0B
EFI_LIGHTRED             equ 0x0C
EFI_LIGHTMAGENTA         equ 0x0D
EFI_YELLOW               equ 0x0E
EFI_WHITE                equ 0x0F
EFI_BACKGROUND_BLACK     equ 0x00
EFI_BACKGROUND_BLUE      equ 0x10
EFI_BACKGROUND_GREEN     equ 0x20
EFI_BACKGROUND_CYAN      equ 0x30
EFI_BACKGROUND_RED       equ 0x40
EFI_BACKGROUND_MAGENTA   equ 0x50
EFI_BACKGROUND_BROWN     equ 0x60
EFI_BACKGROUND_LIGHTGRAY equ 0x70

EFI_TEXT_ATTR MACRO fore:REQ, back:REQ
  EXITM <(fore OR (back SHL 4))>
ENDM

; Baseline unicode control chars
CHAR_NULL                       equ 0x0000
CHAR_BACKSPACE                  equ 0x0008
CHAR_TAB                        equ 0x0009
CHAR_LINEFEED                   equ 0x000A
CHAR_CARRIAGE_RETURN            equ 0x000D

;// Scan codes for base line keys
SCAN_NULL                       equ 0x0000
SCAN_UP                         equ 0x0001
SCAN_DOWN                       equ 0x0002
SCAN_RIGHT                      equ 0x0003
SCAN_LEFT                       equ 0x0004
SCAN_HOME                       equ 0x0005
SCAN_END                        equ 0x0006
SCAN_INSERT                     equ 0x0007
SCAN_DELETE                     equ 0x0008
SCAN_PAGE_UP                    equ 0x0009
SCAN_PAGE_DOWN                  equ 0x000A
SCAN_F1                         equ 0x000B
SCAN_F2                         equ 0x000C
SCAN_F3                         equ 0x000D
SCAN_F4                         equ 0x000E
SCAN_F5                         equ 0x000F
SCAN_F6                         equ 0x0010
SCAN_F7                         equ 0x0011
SCAN_F8                         equ 0x0012
SCAN_F9                         equ 0x0013
SCAN_F10                        equ 0x0014
SCAN_ESC                        equ 0x0017

; Macro to accept color values in their raw form to create
; a value that represents both a foreground and background
; color in a single byte.
; For Foreground, and EFI_* value is valid from EFI_BLACK(0x00) to EFI_WHITE (0x0F).

; For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN,
; EFI_CYAN, EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY are acceptable.

; Do not use EFI_BACKGROUND_xxx values with this macro.
; #define EFI_TEXT_ATTR(Foreground,Background) ((Foreground) | ((Background) << 4))
_EFI_CONFIGURATION_TABLE STRUCT
    VendorGuid  EFI_GUID <?>
    VendorTable DPTR      ?
_EFI_CONFIGURATION_TABLE ENDS

;---------------------------------------------------------------------------
; Simple Console In Protocol
;---------------------------------------------------------------------------
RAWINTERFACE ConIn
  STDFUNC Reset, <voidarg>, pThis:PTR ConIn, ExtendedVerification:BOOLEAN
  STDFUNC ReadKeyStroke, <voidarg>, pThis:PTR ConIn, key:P_EFI_INPUT_KEY
   WaitForKey EFI_EVENT ?
ENDRAWINTERFACE
PCONIN TYPEDEF PTR ConIn


;   EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL

;EFI_KEY_NOTIFY_FUNCTION Proto FASTCALL :P_EFI_KEY_DATA
P_EFI_KEY_NOTIFY_FUNCTION TYPEDEF POINTER;PTR EFI_KEY_NOTIFY_FUNCTION


RAWINTERFACE ConInEx
  STDFUNC Reset, <voidarg>, pThis:PTR ConInEx, ExtendedVerification:BOOLEAN
  STDFUNC ReadKeyStrokeEx, <voidarg>, pThis:PTR ConInEx, KeyData: P_EFI_KEY_DATA
  WaitForKeyEx EFI_EVENT ?
  STDFUNC SetState, <voidarg>, pThis:PTR ConInEx, KeyToggleState: P_EFI_KEY_TOGGLE_STATE
  STDFUNC RegisterKeyNotify, <voidarg>, pThis:PTR ConInEx, KeyData : P_EFI_KEY_DATA, KeyNotificationFunction: P_EFI_KEY_NOTIFY_FUNCTION
  STDFUNC UnregisterKeyNotify  , <voidarg>, pThis:PTR ConInEx, NotificationHandle: P_EFI_KEY_NOTIFY_FUNCTION
ENDRAWINTERFACE
PCONINEX TYPEDEF PTR ConInEx
;---------------------------------------------------------------------------
; Simple Console Out Protocol
;---------------------------------------------------------------------------
RAWINTERFACE ConOut
  STDFUNC Reset, <voidarg>, pThis:PTR ConOut, ExtendedVerification:BOOLEAN
  STDFUNC OutputString, <voidarg>, pThis:PTR ConOut, pStr:P_CHAR16
   STDFUNC TestString, <voidarg>, pThis:PTR ConOut, pStr:P_CHAR16
  STDFUNC QueryMode, <voidarg>, pThis:PTR ConOut, ModeNumber:UINTN, pCols:P_UINTN, pRows:P_UINTN
  STDFUNC SetMode, <voidarg>, pThis:PTR ConOut, ModeNumber:UINTN
  STDFUNC SetAttribute, <voidarg>, pThis:PTR ConOut, Attrib:UINTN
  STDFUNC ClearScreen, <voidarg>, pThis:PTR ConOut
  STDFUNC SetCursorPosition, <voidarg>, pThis:PTR ConOut, col:UINTN, row:UINTN
  STDFUNC EnableCursor, <voidarg>, pThis:PTR ConOut, visible:BOOLEAN
  Mode P_SIMPLE_TEXT_OUTPUT_MODE ?
ENDRAWINTERFACE
PCONOUT TYPEDEF PTR ConOut
PERROUT TYPEDEF PTR ConOut

;---------------------------------------------------------------------------
; Graphics Output Protocol
;---------------------------------------------------------------------------

EFI_GRAPHICS_OUTPUT_BLT_PIXEL STRUCT
  Blue      UINT8 ?
  Green     UINT8 ?
  Red       UINT8 ?
  Reserved  UINT8 ?
EFI_GRAPHICS_OUTPUT_BLT_PIXEL ENDS

BLT_OP_EfiBltVideoFill                  equ 0
BLT_OP_EfiBltVideoToBltBuffer           equ 1
BLT_OP_EfiBltBufferToVideo              equ 2
BLT_OP_EfiBltVideoToVideo               equ 3
BLT_OP_EfiGraphicsOutputBltOperationMax equ 4
EFI_GRAPHICS_OUTPUT_BLT_OPERATION TYPEDEF INT32

EFI_PIXEL_BITMASK STRUCT
  RedMask      UINT32 ?
  GreenMask    UINT32 ?
  BlueMask     UINT32 ?
  ReservedMask UINT32 ?
EFI_PIXEL_BITMASK ENDS

EFI_PIX_FMT_PixelRedGreenBlueReserved8BitPerColor equ 0
EFI_PIX_FMT_PixelBlueGreenRedReserved8BitPerColor equ 1
EFI_PIX_FMT_PixelBitMask equ 2
EFI_PIX_FMT_PixelBltOnly equ 3
EFI_PIX_FMT_PixelFormatMax equ 4
EFI_GRAPHICS_PIXEL_FORMAT TYPEDEF INT32

EFI_GRAPHICS_OUTPUT_MODE_INFORMATION STRUCT
  Version              UINT32 ?
  HorizontalResolution UINT32 ?
  VerticalResolution   UINT32 ?
  PixelFormat          EFI_GRAPHICS_PIXEL_FORMAT ?
  PixelInformation     EFI_PIXEL_BITMASK <?>
  PixelsPerScanLine    UINT32 ?
EFI_GRAPHICS_OUTPUT_MODE_INFORMATION ENDS
P_EFI_GRAPHICS_OUTPUT_MODE_INFORMATION TYPEDEF PTR EFI_GRAPHICS_OUTPUT_MODE_INFORMATION

EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE STRUCT
  MaxMode         UINT32 ? ; Number of modes supported by QueryMode() and SetMode()
  Mode            UINT32 ? ; (0-MaxMode-1) Current Mode
  Info            P_EFI_GRAPHICS_OUTPUT_MODE_INFORMATION ?
  SizeOfInfo      UINTN ?
  FrameBufferBase EFI_PHYSICAL_ADDRESS ?
  FrameBufferSize UINTN ?
EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE ENDS
P_EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE TYPEDEF PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE

RAWINTERFACE EFI_GRAPHICS_OUTPUT_PROTOCOL
  STDFUNC QueryMode, <voidarg>, pThis:PTR EFI_GRAPHICS_OUTPUT_PROTOCOL, ModeNumber:UINT32, SizeOfInfo:PTR UINTN, Info:PTR PTR EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
  STDFUNC SetMode, <voidarg>, pThis:PTR EFI_GRAPHICS_OUTPUT_PROTOCOL, ModeNumber:UINT32
  STDFUNC Blt, <voidarg>, pThis:PTR EFI_GRAPHICS_OUTPUT_PROTOCOL, BltBuffer:PTR EFI_GRAPHICS_OTPUT_BLT_PIXEL, BltOperation:EFI_GRAPHICS_OUTPUT_BLT_OPERATION, SourceX:UINTN, SourceY:UINTN, DestinationX:UINTN, DestinationY:UINTN, BltWidth:UINTN, BltHeight:UINTN, Delta:UINTN
  Mode P_EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE ?
ENDRAWINTERFACE
PGOP TYPEDEF PTR EFI_GRAPHICS_OUTPUT_PROTOCOL

EFI_EDID_DISCOVERED_PROTOCOL STRUCT
  SizeOfEdid UINT32 ?
  Edid       P_UINT8 ?
EFI_EDID_DISCOVERED_PROTOCOL ENDS

EFI_EDID_ACTIVE_PROTOCOL STRUCT
  SizeOfEdid UINT32 ?
  Edid       P_UINT8 ?
EFI_EDID_ACTIVE_PROTOCOL ENDS

RAWINTERFACE EFI_EDID_OVERRIDE_PROTOCOL
  STDFUNC GetEdid, <voidarg>, pThis:PTR EFI_EDID_OVERRIDE_PROTOCOL, ChildHandle:PTR EFI_HANDLE, Attributes:PTR UINT32, EdidSize:PTR UINTN, Edid:PTR UINT8
ENDRAWINTERFACE

EFI_EDID_OVERRIDE_DONT_OVERRIDE   equ 0x01
EFI_EDID_OVERRIDE_ENABLE_HOT_PLUG equ 0x02

EFI_CPU_PHYSICAL_LOCATION STRUCT
  Package UINT32 ?
  Core UINT32 ?
  Thread UINT32 ?
EFI_CPU_PHYSICAL_LOCATION ENDS

EFI_PROCESSOR_INFORMATION STRUCT
  ProcessorId UINT64 ?
  StatusFlag UINT32 ?          ;
  Location EFI_CPU_PHYSICAL_LOCATION <?>
EFI_PROCESSOR_INFORMATION ENDS

;*******************************************************
; StatusFlag Bits Definition
;*******************************************************
PROCESSOR_AS_BSP_BIT        equ 0x00000001
PROCESSOR_ENABLED_BIT       equ 0x00000002
PROCESSOR_HEALTH_STATUS_BIT equ 0x00000004

END_OF_CPU_LIST equ 0xffffffff

EFI_AP_PROCEDURE TYPEDEF PTR

;---------------------------------------------------------------------------
; MP SERVICES PROTOCOL
;---------------------------------------------------------------------------
RAWINTERFACE EFI_MP_SERVICES
  STDFUNC GetNumberOfProcessors, <voidarg>, pThis:PTR MP_SERVICES, NumberOfProcessors:PTR UINTN, NumberOfEnabledProcessors:PTR UINTN  ; Can only be called by BSP.
  STDFUNC GetProcessorInfo, <voidarg>, pThis:PTR MP_SERVICES, ProcessorNumber:UINTN, ProcessorInfoBuffer:PTR EFI_PROCESSOR_INFORMATION ; Can only be called by BSP.
  STDFUNC StartupAllAPs, <voidarg>, pThis:PTR MP_SERVICES, Procedure:EFI_AP_PROCEDURE, SingleThread:BOOLEAN, WaitEvent:EFI_EVENT, TimeoutUs:UINTN, ProcedureArgument:PTR, FailedCpuList:PTR
  STDFUNC StartupThisAP, <voidarg>, pThis:PTR MP_SERVICES, Procedure:EFI_AP_PROCEDURE, ProcessorNumber:UINTN, WaitEvent:EFI_EVENT, TimeoutUs:UINTN, ProcedureArgument:PTR, Finished:PTR BOOLEAN
  STDFUNC SwitchBSP, <voidarg>, pThis:PTR MP_SERVICES, ProcessorNumber:UINTN, EnableOldBSP:BOOLEAN
  STDFUNC EnableDisableAP, <voidarg>, pThis:PTR MP_SERVICES, ProcessorNumber:UINTN, EnableAP:BOOLEAN, HealthFlag:PTR UINT32
  STDFUNC WhoAmI, <voidarg>, pThis:PTR MP_SERVICES, ProcessorNumber:PTR UINTN
ENDRAWINTERFACE
P_MP_SERVICES TYPEDEF PTR MP_SERVICES

;---------------------------------------------------------------------------
; BOOT SERVICES PROTOCOL
;---------------------------------------------------------------------------
RAWINTERFACE EFI_BOOT_SERVICES
  Hdr EFI_TABLE_HEADER <>

  ; Task Priority Services
  STDFUNC RaiseTPL, <voidarg>, NewTPL:EFI_TPL
  STDFUNC RestoreTPL, <voidarg>, OldTPO:EFI_TPL

  ; Memory Services
  STDFUNC AllocatePages, <voidarg>, aType:EFI_ALLOCATE_TYPE, memType:EFI_MEMORY_TYPE, NoPages:UINTN, pMem:P_EFI_PHYSICAL_ADDRESS
  STDFUNC FreePages, <voidarg>, efiPhysAddr:EFI_PHYSICAL_ADDRESS, NoPages:UINTN
  STDFUNC GetMemoryMap, <voidarg>, MemoryMapSize:P_UINTN, MemoryMap:P_EFI_MEMORY_DESCRIPTOR, MapKey:P_UINTN, DescriptorSize:P_UINTN, DescriptorVersion:P_UINT32
  STDFUNC AllocatePool, <voidarg>, poolType:EFI_MEMORY_TYPE, poolSize:UINTN, Buffer:PTR
  STDFUNC FreePool, <voidarg>, buffer:PTR

  ; Event & Timer Services
  STDFUNC CreateEvent, <voidarg>, eventType:UINT32, notifyTpl:EFI_TPL, NotifyFunction:P_EFI_EVENT_NOTIFY, NotifyContext:PTR, pEvent:PTR
  STDFUNC SetTimer, <voidarg>, event:EFI_EVENT, eventType:EFI_TIMER_DELAY, triggerTime:UINT64
  STDFUNC WaitForEvent, <voidarg>, NumberOfEvents:UINTN, pEvent:PTR EFI_EVENT, Index:PTR UINTN
  STDFUNC SignalEvent, <voidarg>, Event:EFI_EVENT
  ;STDFUNC CreateEventEx, <voidarg>, eventType:UINT32, notifyTpl:EFI_TPL, NotifyFunction:EFI_EVENT_NOTIFY, EventGroup:PTR EFI_GUID, pEvent:PTR
  STDFUNC CloseEvent, <voidarg>, Event:EFI_EVENT
  STDFUNC CheckEvent, <voidarg>, Event:EFI_EVENT

  ; Protocol Handler Services
  STDFUNC InstallProtocolInterface, <voidarg>, Handle:PTR EFI_HANDLE, Protocol:PTR EFI_GUID, InterfaceType:EFI_INTERFACE_TYPE, pInterface:PTR
  STDFUNC ReinstallProtocolInterface, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, OldInterface:PTR, NewInterface:PTR
  STDFUNC UninstallProtocolInterface, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, Interface:PTR
  STDFUNC HandleProtocol, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, ppInterface:PTR PTR
  STDFUNC PCHandleProtocol, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, ppInterface:PTR PTR
  STDFUNC RegisterProtocolNotify, <voidarg>, Protocol:PTR EFI_GUID, Event:EFI_EVENT, ppRegistration:PTR PTR
  STDFUNC LocateHandle, <voidarg>, SearchType:EFI_LOCATE_SEARCH_TYPE, Protocol:PTR EFI_GUID, SearchKey:PTR, pBufferSize:PTR UINTN, pBuffer:EFI_HANDLE
  STDFUNC LocateDevicePath, <voidarg>, Protocol:PTR EFI_GUID, ppDevicePath:PTR EFI_DEVICE_PATH_PROTOCOL, pDevice:PTR EFI_HANDLE
  STDFUNC InstallConfigurationTable, <voidarg>

  ; Image Services
  STDFUNC LoadImage, <voidarg>, BootPolicy:BOOLEAN, ParentImageHandle:EFI_HANDLE, DevicePath:PTR EFI_DEVICE_PATH_PROTOCOL, SourceBuffer:PTR, SourceSize:UINTN, ImageHandle:PTR EFI_HANDLE
  STDFUNC StartImage, <voidarg>, ImageHandle:EFI_HANDLE, ExitDataSize:PTR UINTN, ExitData:P_CHAR16
  STDFUNC Exit, <voidarg>, imageHandle:EFI_HANDLE, exitStatus:EFI_STATUS, exitDataSize:UINTN, exitDataPtr:P_CHAR16
  STDFUNC UnloadImage, <voidarg>, ImageHandle:EFI_HANDLE
  STDFUNC ExitBootServices, <voidarg>, imageHandle:EFI_HANDLE, mapKey:UINTN

  ; Misc Services
  STDFUNC GetMonotonicCount, <voidarg>, Count:PTR UINT64
  STDFUNC Stall, <voidarg>, Microseconds:UINTN
  STDFUNC SetWatchdogTimer, <voidarg>, Timeout:UINTN, WatchdogCode:UINT64, DataSize:UINTN, WatchdogData:P_CHAR16

  ; DriverSupport Services
  STDFUNC ConnectController, <voidarg>, ControllerHandle:EFI_HANDLE, DriverImageHandle:PTR EFI_HANDLE, RemainingDevicePath:PTR EFI_DEVICE_PATH_PROTOCOL, Recursive:BOOLEAN
  STDFUNC DisconnectController, <voidarg>, ControllerHandle:EFI_HANDLE, DriverImageHandle:EFI_HANDLE, ChildHandle:EFI_HANDLE

  ; Open and Close Protocol Services
  STDFUNC OpenProtocol, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, ppInterface:PTR, AgentHandle:EFI_HANDLE, ControllerHandle:EFI_HANDLE, Attributes:UINT32
  STDFUNC CloseProtocol, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, AgentHandle:EFI_HANDLE, ControllerHandle:EFI_HANDLE
  STDFUNC OpenProtocolInformation, <voidarg>, Handle:EFI_HANDLE, Protocol:PTR EFI_GUID, ppEntryBuffer:PTR EFI_OPEN_PROTOCOL_INFORMATION_ENTRY, pEntryCount:P_UINTN

  ; Library Services
  STDFUNC ProtocolsPerHandle, <voidarg>, Handle:EFI_HANDLE, pppProtocolBuffer:PTR PTR PTR EFI_GUID, ProtocolBufferCount:P_UINTN
  STDFUNC LocateHandleBuffer, <voidarg>, SearchType:EFI_LOCATE_SEARCH_TYPE, Protocol:PTR EFI_GUID, SearchKey:PTR, NoHandles:P_UINTN, ppBuffer:PTR PTR EFI_HANDLE
  STDFUNC LocateProtocol, <voidarg>, Protocol:PTR EFI_GUID, Registration:PTR, ppInterface:PTR
  STDFUNC InstallMultipleProtocolInterfaces, <voidarg>, Handle:PTR EFI_HANDLE
  STDFUNC UninstallMultipleProtocolInterfaces, <voidarg>, Handle:EFI_HANDLE

  ; 32bit CRC Services
  STDFUNC CalculateCrc32, <voidarg>, Data:PTR, DataSize:UINTN, pCrc32:P_UINTN

  ; Misc Services
  STDFUNC CopyMem, <voidarg>, Destination:PTR, Source:PTR, DataLength:UINTN
  STDFUNC SetMem, <voidarg>, Buffer:PTR, DataSize:UINTN, Value:UINT8
ENDRAWINTERFACE
P_BOOT_SERVICES TYPEDEF PTR BOOT_SERVICES

;---------------------------------------------------------------------------
; RUNTIME SERVICES PROTOCOL
;---------------------------------------------------------------------------
EFI_RUNTIME_SERVICES STRUCT
  Hdr EFI_TABLE_HEADER <>

  ; Time services
  STDFUNC GetTime, <voidarg>, Time:PTR EFI_TIME, Capabilities:PTR EFI_TIME_CAPABILITIES
  STDFUNC SetTime, <voidarg>, Time:PTR EFI_TIME
  STDFUNC GetWakeupTime, <voidarg>, Enabled:PTR BOOLEAN, Pending:PTR BOOLEAN, Time:PTR EFI_TIME
  STDFUNC SetWakeupTime, <voidarg>, Enable:BOOLEAN, Time:PTR EFI_TIME

  ; Virtual memory services
  STDFUNC SetVirtualAddressMap, <voidarg>, MemoryMapSize:UINTN, DescriptorSize:UINTN, DescriptorVersion:UINT32, VirtualMap:PTR EFI_MEMORY_DESCRIPTOR
  STDFUNC ConvertPointer, <voidarg>, DebigDisposition:UINTN, Address:PTR PTR

  ; Variable serviers
  STDFUNC GetVariable, <voidarg>, VariableName:P_CHAR16, VendorGuid:PTR EFI_GUID, Attributes:PTR UINT32, DataSize:PTR UINTN, Data:PTR
  STDFUNC GetNextVariableName, <voidarg>, VariableNameSize:PTR UINTN, VariableName:P_CHAR16, VendorGuid:PTR EFI_GUID
  STDFUNC SetVariable, <voidarg>, VariableName:P_CHAR16, VendorGuid:PTR EFI_GUID, Attributes:UINT32, DataSize:UINTN, Data:PTR

  ; Misc
  STDFUNC GetNextHighMonotonicCount, <voidarg>, HighCount:PTR UINT32
  STDFUNC ResetSystem, <voidarg>, ResetType:EFI_RESET_TYPE, ResetStatus:EFI_STATUS, DataSize:UINTN, ResetData:PTR
EFI_RUNTIME_SERVICES ENDS
P_RUNTIME_SERVICES TYPEDEF PTR EFI_RUNTIME_SERVICES

EFI_SYSTEM_TABLE_SIGNATURE  equ 0x5453595320494249
EFI_BOOT_SERVICES_SIGNATURE equ 0x56524553544f4f42

EFI_SYSTEM_TABLE STRUCT
  Hdr                    EFI_TABLE_HEADER <>
  FirmwareVendor        DPTR       ?
  FirmwareRevision      UINT32     ?
  ConsoleInHandle       EFI_HANDLE ?
  ConIn                 PCONIN     ?
  ConsoleOutHandle      EFI_HANDLE ?
  ConOut                PCONOUT    ?
  StandardErrorHandle   EFI_HANDLE ?
  StdErr                PERROUT    ?
  RuntimeServices       P_RUNTIME_SERVICES ?
  BootServices          P_BOOT_SERVICES ?
  NumberOfTableEntries  UINTN      ?
  ConfigurationTable    DPTR       ?
EFI_SYSTEM_TABLE ENDS

PTR_EFI_SYSTEM_TABLE TYPEDEF PTR EFI_SYSTEM_TABLE

EFI_CONFIGURATION_TABLE STRUCT
  VendorGuid EFI_GUID <?>
  VendorTable DPTR ?
EFI_CONFIGURATION_TABLE ENDS

PRECT TYPEDEF PTR RECT
