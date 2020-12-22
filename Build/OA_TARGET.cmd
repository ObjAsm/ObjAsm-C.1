REM Set default targets
REM TARGET_USER_INTERFACE: WINDOW, NONE
set TARGET_USER_INTERFACE=WINDOW
REM TARGET_BITNESS: 32, 64
set TARGET_BITNESS=32
REM TARGET_BIN_FORMAT: EXE, DLL, LIB
set TARGET_BIN_FORMAT=EXE
REM TARGET_STRING_TYPE: ANSI, WIDE
set TARGET_STRING_TYPE=WIDE
REM TARGET_SUPPORT_OOP: ENABLED, DISABLED
set TARGET_SUPPORT_OOP=DISABLED
REM TARGET_MODE: RLS, DBG
set TARGET_MODE=RLS
REM TARGET_MODE: RELEASE, DEBUG
set TARGET_MODE_STR=RELEASE

REM Read main project file and get build targets
for /f "tokens=1,* eol=;" %%X in (!ProjectName!.asm) do (
  if %%X==SysSetup (
    for /f "tokens=1 delims=;" %%Z in ("%%Y") do (
      for %%A in (%%Z) do (
        if %%A == OOP (
          set TARGET_SUPPORT_OOP=ENABLED
        ) else (
          if %%A == WIN64 (
            set TARGET_BITNESS=64
          ) else (
            if %%A == NUI32 (
              set TARGET_BITNESS=32
              set TARGET_USER_INTERFACE=NONE
            ) else (
              if %%A == NUI64 (
                set TARGET_BITNESS=64
                set TARGET_USER_INTERFACE=NONE
              ) else (
                if %%A == LIB32 (
                  set TARGET_BITNESS=32
                  set TARGET_USER_INTERFACE=WIN
                  set TARGET_BIN_FORMAT=LIB
                ) else (
                  if %%A == LIB64 (
                    set TARGET_BITNESS=64
                    set TARGET_USER_INTERFACE=WIN
                    set TARGET_BIN_FORMAT=LIB
                  ) else (
                    if %%A == DLL32 (
                      set TARGET_BITNESS=32
                      set TARGET_USER_INTERFACE=WIN
                      set TARGET_BIN_FORMAT=DLL
                    ) else (
                      if %%A == DLL64 (
                        set TARGET_BITNESS=64
                        set TARGET_USER_INTERFACE=WIN
                        set TARGET_BIN_FORMAT=DLL
                      ) else (
                        if %%A == ANSI_STRING (
                          set TARGET_STRING_TYPE=ANSI
                        ) else (
                          for /f "tokens=1-9 delims=(,)" %%M in ("%%A") do (
                            if %%M == DEBUG (
                              set TARGET_MODE=DBG
                              set TARGET_MODE_STR=DEBUG
                            )
                          )
                        )
                      )
                    )
                  )
                )
              )
            )
          )
        )
      )
    )
  )
)
