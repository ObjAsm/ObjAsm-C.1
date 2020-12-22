@echo off
start "Building 32 bit ANSI Objects" "%OBJASM_PATH%\Code\Objects\Build\MakeObjects32A.cmd" %*
start "Building 32 bit WIDE Objects" "%OBJASM_PATH%\Code\Objects\Build\MakeObjects32W.cmd" %*
start "Building 64 bit ANSI Objects" "%OBJASM_PATH%\Code\Objects\Build\MakeObjects64A.cmd" %*
start "Building 64 bit WIDE Objects" "%OBJASM_PATH%\Code\Objects\Build\MakeObjects64W.cmd" %*
