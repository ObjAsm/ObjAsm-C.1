
Output.Clear
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_CodecFile")

For Each objItem in colItems
    Output.Write "Access Mask: " & objItem.AccessMask & vbCRLF
    Output.Write "Archive: " & objItem.Archive & vbCRLF
    Output.Write "Caption: " & objItem.Caption & vbCRLF
    Output.Write "Creation Date: " & WMIDateStringToDate(objItem.CreationDate) & vbCRLF
    Output.Write "Drive: " & objItem.Drive & vbCRLF
    Output.Write "8.3 File Name: " & objItem.EightDotThreeFileName & vbCRLF
    Output.Write "Extension: " & objItem.Extension & vbCRLF
    Output.Write "File Name: " & objItem.FileName & vbCRLF
    Output.Write "File Size: " & objItem.FileSize & vbCRLF
    Output.Write "File Type: " & objItem.FileType & vbCRLF
    Output.Write "File System Name: " & objItem.FSName & vbCRLF
    Output.Write "Group: " & objItem.Group & vbCRLF
    Output.Write "Hidden: " & objItem.Hidden & vbCRLF
    Output.Write "Last Accessed: " & WMIDateStringToDate(objItem.InstallDate) & vbCRLF
    Output.Write "Last Modified: " & WMIDateStringToDate(objItem.LastModified) & vbCRLF
    Output.Write "Manufacturer: " & objItem.Manufacturer & vbCRLF
    Output.Write "Name: " & objItem.Name & vbCRLF
    Output.Write "Path: " & objItem.Path & vbCRLF
    Output.Write "Version: " & objItem.Version & vbCRLF & vbCRLF
Next
 
Function WMIDateStringToDate(dtmDate)
    WMIDateStringToDate = CDate(Mid(dtmDate, 5, 2) & "/" & _
        Mid(dtmDate, 7, 2) & "/" & Left(dtmDate, 4) _
            & " " & Mid (dtmDate, 9, 2) & ":" & _
                Mid(dtmDate, 11, 2) & ":" & Mid(dtmDate, _
                    13, 2))
End Function