@echo off
set TARGET_BITNESS=64
set TARGET_MODE=RLS
set TARGET_STR_TYPE=STR_TYPE_WIDE
set TARGET_STR_NAME=WIDE
set TARGET_FOLDER="%OBJASM_PATH%\Code\Objects\Lib\%TARGET_BITNESS%W"

call "%OBJASM_PATH%\Code\Objects\Build\MakeObjects.cmd" %*

exit
