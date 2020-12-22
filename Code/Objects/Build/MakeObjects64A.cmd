@echo off
set TARGET_BITNESS=64
set TARGET_MODE=RLS
set TARGET_STR_TYPE=STR_TYPE_ANSI
set TARGET_STR_NAME=ANSI
set TARGET_FOLDER="%OBJASM_PATH%\Code\Objects\Lib\%TARGET_BITNESS%A"

call "%OBJASM_PATH%\Code\Objects\Build\MakeObjects.cmd" %*

exit
