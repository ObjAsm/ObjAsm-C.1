cd %PROGRAMFILES%\oracle\VirtualBox
VBoxManage.exe closemedium "%USERPROFILE%"\.VirtualBox\USB.vmdk --delete

VBoxManage.exe closemedium "%USERPROFILE%\VirtualBox VMs\UEFI Test\VMUBDrive000.vmdk" --delete