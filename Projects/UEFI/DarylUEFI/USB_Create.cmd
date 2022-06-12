cd %PROGRAMFILES%\oracle\VirtualBox
VBoxManage internalcommands createrawvmdk -filename "%USERPROFILE%"\.VirtualBox\USB.vmdk -rawdisk \\.\PhysicalDrive2
pause
