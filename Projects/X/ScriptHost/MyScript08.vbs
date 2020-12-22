On Error Resume Next

strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_Processor")

Output.Clear
For Each objItem in colItems
    Output.Write "Address Width: " & objItem.AddressWidth & vbCRLF
    Output.Write "Architecture: " & objItem.Architecture & vbCRLF
    Output.Write "Availability: " & objItem.Availability & vbCRLF
    Output.Write "CPU Status: " & objItem.CpuStatus & vbCRLF
    Output.Write "Current Clock Speed: " & objItem.CurrentClockSpeed & vbCRLF
    Output.Write "Data Width: " & objItem.DataWidth & vbCRLF
    Output.Write "Description: " & objItem.Description & vbCRLF
    Output.Write "Device ID: " & objItem.DeviceID & vbCRLF
    Output.Write "External Clock: " & objItem.ExtClock & vbCRLF
    Output.Write "Family: " & objItem.Family & vbCRLF
    Output.Write "L2 Cache Size: " & objItem.L2CacheSize & vbCRLF
    Output.Write "L2 Cache Speed: " & objItem.L2CacheSpeed & vbCRLF
    Output.Write "Level: " & objItem.Level & vbCRLF
    Output.Write "Load Percentage: " & objItem.LoadPercentage & vbCRLF
    Output.Write "Manufacturer: " & objItem.Manufacturer & vbCRLF
    Output.Write "Maximum Clock Speed: " & objItem.MaxClockSpeed & vbCRLF
    Output.Write "Name: " & objItem.Name & vbCRLF
    Output.Write "PNP Device ID: " & objItem.PNPDeviceID & vbCRLF
    Output.Write "Processor ID: " & objItem.ProcessorId & vbCRLF
    Output.Write "Processor Type: " & objItem.ProcessorType & vbCRLF
    Output.Write "Revision: " & objItem.Revision & vbCRLF
    Output.Write "Role: " & objItem.Role & vbCRLF
    Output.Write "Socket Designation: " & objItem.SocketDesignation & vbCRLF
    Output.Write "Status Information: " & objItem.StatusInfo & vbCRLF
    Output.Write "Stepping: " & objItem.Stepping & vbCRLF
    Output.Write "Unique Id: " & objItem.UniqueId & vbCRLF
    Output.Write "Upgrade Method: " & objItem.UpgradeMethod & vbCRLF
    Output.Write "Version: " & objItem.Version & vbCRLF
    Output.Write "Voltage Caps: " & objItem.VoltageCaps & vbCRLF
Next