@echo off
REM Usage: Inc2RC SrcFile DstFile
REM Translates a SrcFile from asm notation to a DstFile in RC notation.

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

echo Inc2RC is converting %1 ...
if not [!LogFile!] == [] (
  echo Inc2RC is converting %1 ...>> !LogFile!
)

if [%~1]==[] (
  echo inc2rc error: missing argument
) else (
  set SrcFile=%~1
  set SrcFileNoExt=!SrcFile:~0,-4!

  if [%~2]==[] (
    set DstFile=!SrcFileNoExt!.tmp
  ) else (
    set DstFile=%~2
  )
  echo //RC-file created by Inc2RC from !SrcFile! on %DATE%, %TIME%> !DstFile!
  echo.>> !DstFile!

  for /f "tokens=1,2,*" %%A in (!SrcFile!) do (
    if "%%B" == "=" (
      echo #define %%A %%C>> !DstFile!
    ) else (
      set Text=%%C
      set FirstChar=!Text:~0,1!
      if "!FirstChar!" == "<" (
        set Text=!Text:^<="!
        set Text=!Text:^>="!
        call :Trim !Text! Text
      )
      if "%%B" == "equ" (
        echo #define %%A !Text!>> !DstFile!
      ) else (
        if "%%B" == "textequ" (
          echo #define %%A !Text!>> !DstFile!
        ) else (
          echo Conversion failed:  %%A %%B %%C
          if not [!LogFile!] == [] (
            echo Conversion failed:  %%A %%B %%C>> !LogFile!
          )
        )
      )
    )
  )
)
goto :EOF

:Trim
set %2=%1
goto :EOF
