; ==================================================================================================
; Title:      DbgOutComErrX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness independent code.
; ==================================================================================================


% include &ObjMemPath&ObjMemWin.cop

DOM struc
  ID    DWORD     ?
  pStr  POINTER   ?
DOM ends

.const
DbgComErrTable \
  DOM {080000001h, $OfsTStrA("Not implemented")}
  DOM {080000002h, $OfsTStrA("Ran out of memory")}
  DOM {080000003h, $OfsTStrA("One or more arguments are invalid")}
  DOM {080000004h, $OfsTStrA("No such interface supported")}
  DOM {080000005h, $OfsTStrA("Invalid pointer")}
  DOM {080000006h, $OfsTStrA("Invalid HANDLE")}
  DOM {080000007h, $OfsTStrA("Operation aborted")}
  DOM {080000008h, $OfsTStrA("Unspecified error")}
  DOM {080000009h, $OfsTStrA("General access denied error")}
  DOM {08000000Ah, $OfsTStrA("The data necessary to complete this operation not yet available.")}

  DOM {080004001h, $OfsTStrA("Not implemented")}
  DOM {080004002h, $OfsTStrA("No such interface supported")}
  DOM {080004003h, $OfsTStrA("Invalid pointer")}
  DOM {080004004h, $OfsTStrA("Operation aborted")}
  DOM {080004005h, $OfsTStrA("Unspecified error")}
  DOM {080004006h, $OfsTStrA("Thread local storage failure")}
  DOM {080004007h, $OfsTStrA("Get shared memory allocator failure")}
  DOM {080004008h, $OfsTStrA("Get memory allocator failure")}
  DOM {080004009h, $OfsTStrA("Unable to initialize class cache")}
  DOM {08000400Ah, $OfsTStrA("Unable to initialize RPC services")}
  DOM {08000400Bh, $OfsTStrA("Cannot set thread local storage channel control")}
  DOM {08000400Ch, $OfsTStrA("Could not allocate thread local storage channel control")}
  DOM {08000400Dh, $OfsTStrA("The user supplied memory allocator is unacceptable")}
  DOM {08000400Eh, $OfsTStrA("The OLE service mutex already exists")}
  DOM {08000400Fh, $OfsTStrA("The OLE service file mapping already exists")}
  DOM {080004010h, $OfsTStrA("Unable to map view of file for OLE service")}
  DOM {080004011h, $OfsTStrA("Failure attempting to launch OLE service")}
  DOM {080004012h, $OfsTStrA("There was an attempt to call CoInitialize a second time while single threaded")}
  DOM {080004013h, $OfsTStrA("A Remote activation was necessary but was not allowed")}
  DOM {080004014h, $OfsTStrA("A Remote activation was necessary but the server name provided was invalid")}
  DOM {080004015h, $OfsTStrA("The class is configured to run as a security id different from the caller")}
  DOM {080004016h, $OfsTStrA("Use of Ole1 services requiring DDE windows is disabled")}
  DOM {080004017h, $OfsTStrA("A RunAs specification must be \ name or simply")}
  DOM {080004018h, $OfsTStrA("The server process could not be started. The pathname may be incorrect.")}
  DOM {080004019h, $OfsTStrA("The server process could not be started as the configured identity. The pathname may be incorrect or unavailable.")}
  DOM {08000401Ah, $OfsTStrA("The server process could not be started because the configured identity is incorrect. Check the username and password.")}
  DOM {08000401Bh, $OfsTStrA("The client is not allowed to launch this server.")}
  DOM {08000401Ch, $OfsTStrA("The service providing this server could not be started.")}
  DOM {08000401Dh, $OfsTStrA("This computer was unable to communicate with the computer providing the server.")}
  DOM {08000401Eh, $OfsTStrA("The server did not respond after being launched.")}
  DOM {08000401Fh, $OfsTStrA("The registration information for this server is inconsistent or incomplete.")}
  DOM {080004020h, $OfsTStrA("The registration information for this interface is inconsistent or incomplete.")}
  DOM {080004021h, $OfsTStrA("The operation attempted is not supported.")}

  DOM {080010001h, $OfsTStrA("Call was rejected by callee.")}
  DOM {080010002h, $OfsTStrA("Call was canceled by the message filter.")}
  DOM {080010003h, $OfsTStrA("The caller is dispatching an intertask SendMessage call and cannot call out via PostMessage.")}
  DOM {080010004h, $OfsTStrA("The caller is dispatching an asynchronous call and cannot make an outgoing call on behalf of this call.")}
  DOM {080010005h, $OfsTStrA("It is illegal to call out while inside message filter.")}
  DOM {080010006h, $OfsTStrA("The connection terminated or is in a bogus state and cannot be used any more. Other connections are still valid.")}
  DOM {080010007h, $OfsTStrA("The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call may have executed.")}
  DOM {080010008h, $OfsTStrA("The caller (client) disappeared while the callee (server) was processing a call.")}
  DOM {080010009h, $OfsTStrA("The data packet with the marshalled parameter data is incorrect.")}
  DOM {08001000Ah, $OfsTStrA("The call was not transmitted properly; the message queue was full and was not emptied after yielding.")}
  DOM {08001000Bh, $OfsTStrA("The client (caller) cannot marshal the parameter data - low memory, etc.")}
  DOM {08001000Ch, $OfsTStrA("The client (caller) cannot unmarshal the return data - low memory, etc.")}
  DOM {08001000Dh, $OfsTStrA("The server (callee) cannot marshal the return data - low memory, etc.")}
  DOM {08001000Eh, $OfsTStrA("The server (callee) cannot unmarshal the parameter data - low memory, etc.")}
  DOM {08001000Fh, $OfsTStrA("Received data is invalid; could be server or client data.")}
  DOM {080010010h, $OfsTStrA("A particular parameter is invalid and cannot be (un)marshalled.")}
  DOM {080010011h, $OfsTStrA("There is no second outgoing call on same channel in DDE conversation.")}
  DOM {080010012h, $OfsTStrA("The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call did not execute.")}
  DOM {080010100h, $OfsTStrA("System call failed.")}
  DOM {080010101h, $OfsTStrA("Could not allocate some required resource (memory, events, ...)")}
  DOM {080010102h, $OfsTStrA("Attempted to make calls on more than one thread in single threaded mode.")}
  DOM {080010103h, $OfsTStrA("The requested interface is not registered on the server object.")}
  DOM {080010104h, $OfsTStrA("RPC could not call the server or could not return the results of calling the server.")}
  DOM {080010105h, $OfsTStrA("The server threw an exception.")}
  DOM {080010106h, $OfsTStrA("Cannot change thread mode after it is set.")}
  DOM {080010107h, $OfsTStrA("The method called does not exist on the server.")}
  DOM {080010108h, $OfsTStrA("The object invoked has disconnected from its clients.")}
  DOM {080010109h, $OfsTStrA("The object invoked chose not to process the call now. Try again later.")}
  DOM {08001010Ah, $OfsTStrA("The message filter indicated that the application is busy.")}
  DOM {08001010Bh, $OfsTStrA("The message filter rejected the call.")}
  DOM {08001010Ch, $OfsTStrA("A call control interfaces was called with invalid data.")}
  DOM {08001010Dh, $OfsTStrA("An outgoing call cannot be made since the application is dispatching an input-synchronous call.")}
  DOM {08001010Eh, $OfsTStrA("The application called an interface that was marshalled for a different thread.")}
  DOM {08001010Fh, $OfsTStrA("CoInitialize has not been called on the current thread.")}
  DOM {080010110h, $OfsTStrA("The version of OLE on the client and server machines does not match.")}
  DOM {080010111h, $OfsTStrA("OLE received a packet with an invalid header.")}
  DOM {080010112h, $OfsTStrA("OLE received a packet with an invalid extension.")}
  DOM {080010113h, $OfsTStrA("The requested object or interface does not exist.")}
  DOM {080010114h, $OfsTStrA("The requested object does not exist.")}
  DOM {080010115h, $OfsTStrA("OLE has sent a request and is waiting for a reply.")}
  DOM {080010116h, $OfsTStrA("OLE is waiting before retrying a request.")}
  DOM {080010117h, $OfsTStrA("Call context cannot be accessed after call completed.")}
  DOM {080010118h, $OfsTStrA("Impersonate on unsecured calls is not supported.")}
  DOM {080010119h, $OfsTStrA("Security must be initialized before any interfaces are marshalled or unmarshalled. It cannot be changed once initialized.")}
  DOM {08001011Ah, $OfsTStrA("No security packages are installed on this machine or the user is not logged on or there are no compatible security packages between the client and server.")}
  DOM {08001011Bh, $OfsTStrA("Access is denied.")}
  DOM {08001011Ch, $OfsTStrA("Remote calls are not allowed for this process.")}
  DOM {08001011Dh, $OfsTStrA("The marshalled interface data packet (OBJREF) has an invalid or unknown format.")}
  DOM {08001FFFFh, $OfsTStrA("An internal error occurred.")}

  DOM {080020001h, $OfsTStrA("Unknown interface.")}
  DOM {080020003h, $OfsTStrA("Member not found.")}
  DOM {080020004h, $OfsTStrA("Parameter not found.")}
  DOM {080020005h, $OfsTStrA("Type mismatch.")}
  DOM {080020006h, $OfsTStrA("Unknown name.")}
  DOM {080020007h, $OfsTStrA("No named arguments.")}
  DOM {080020008h, $OfsTStrA("Bad variable type.")}
  DOM {080020009h, $OfsTStrA("Exception occurred.")}
  DOM {08002000Ah, $OfsTStrA("Out of present range. ")}

  DOM {08002000Bh, $OfsTStrA("Invalid index.")}
  DOM {08002000Ch, $OfsTStrA("Unknown language.")}
  DOM {08002000Dh, $OfsTStrA("Memory is locked.")}
  DOM {08002000Eh, $OfsTStrA("Invalid number of parameters.")}
  DOM {08002000Fh, $OfsTStrA("Parameter not optional.")}
  DOM {080020010h, $OfsTStrA("Invalid callee.")}
  DOM {080020011h, $OfsTStrA("Does not support a collection.")}
  DOM {080028016h, $OfsTStrA("Buffer too small.")}
  DOM {080028018h, $OfsTStrA("Old format or invalid type library.")}
  DOM {080028019h, $OfsTStrA("Old format or invalid type library.")}
  DOM {08002801Ch, $OfsTStrA("Error accessing the OLE registry.")}
  DOM {08002801Dh, $OfsTStrA("Library not registered.")}
  DOM {080028027h, $OfsTStrA("Bound to unknown type.")}
  DOM {080028028h, $OfsTStrA("Qualified name disallowed.")}
  DOM {080028029h, $OfsTStrA("Invalid forward reference, or reference to uncompiled type.")}
  DOM {08002802Ah, $OfsTStrA("Type mismatch.")}
  DOM {08002802Bh, $OfsTStrA("Element not found.")}
  DOM {08002802Ch, $OfsTStrA("Ambiguous name.")}
  DOM {08002802Dh, $OfsTStrA("Name already exists in the library.")}
  DOM {08002802Eh, $OfsTStrA("Unknown LCID.")}
  DOM {08002802Fh, $OfsTStrA("Function not defined in specified DLL.")}
  DOM {0800288BDh, $OfsTStrA("Wrong module kind for the operation.")}
  DOM {0800288C5h, $OfsTStrA("Size may not exceed 64K.")}
  DOM {0800288C6h, $OfsTStrA("Duplicate ID in inheritance hierarchy.")}
  DOM {0800288CFh, $OfsTStrA("Incorrect inheritance depth in standard OLE hmember.")}
  DOM {080028CA0h, $OfsTStrA("Type mismatch.")}
  DOM {080028CA1h, $OfsTStrA("Invalid number of arguments.")}
  DOM {080028CA2h, $OfsTStrA("I/O Error.")}
  DOM {080028CA3h, $OfsTStrA("Error creating unique tmp file.")}
  DOM {080029C4Ah, $OfsTStrA("Error loading type library/DLL.")}
  DOM {080029C83h, $OfsTStrA("Inconsistent property functions.")}
  DOM {080029C84h, $OfsTStrA("Circular dependency between types/modules.")}

  DOM {080030001h, $OfsTStrA("Unable to perform requested operation.")}
  DOM {080030002h, $OfsTStrA("%1 could not be found.")}
  DOM {080030003h, $OfsTStrA("The path %1 could not be found.")}
  DOM {080030004h, $OfsTStrA("There are insufficient resources to open another file.")}
  DOM {080030005h, $OfsTStrA("Access Denied.")}
  DOM {080030006h, $OfsTStrA("Attempted an operation on an invalid object.")}
  DOM {080030008h, $OfsTStrA("There is insufficient memory available to complete operation.")}
  DOM {080030009h, $OfsTStrA("Invalid pointer error.")}
  DOM {080030012h, $OfsTStrA("There are no more entries to return.")}
  DOM {080030013h, $OfsTStrA("Disk is write-protected.")}
  DOM {080030019h, $OfsTStrA("An error occurred during a seek operation.")}
  DOM {08003001Dh, $OfsTStrA("A disk error occurred during a write operation.")}
  DOM {08003001Eh, $OfsTStrA("A disk error occurred during a read operation.")}
  DOM {080030020h, $OfsTStrA("A share violation has occurred.")}
  DOM {080030021h, $OfsTStrA("A lock violation has occurred.")}
  DOM {080030050h, $OfsTStrA("%1 already exists.")}
  DOM {080030057h, $OfsTStrA("Invalid parameter error.")}
  DOM {080030070h, $OfsTStrA("There is insufficient disk space to complete operation.")}
  DOM {0800300F0h, $OfsTStrA("Illegal write of non-simple property to simple property set.")}
  DOM {0800300FAh, $OfsTStrA("An API call exited abnormally.")}
  DOM {0800300FBh, $OfsTStrA("The file %1 is not a valid compound file.")}
  DOM {0800300FCh, $OfsTStrA("The name %1 is not valid.")}
  DOM {0800300FDh, $OfsTStrA("An unexpected error occurred.")}
  DOM {0800300FEh, $OfsTStrA("That function is not implemented.")}
  DOM {0800300FFh, $OfsTStrA("Invalid flag error.")}
  DOM {080030100h, $OfsTStrA("Attempted to use an object that is busy.")}
  DOM {080030101h, $OfsTStrA("The storage has been changed since the last commit.")}
  DOM {080030102h, $OfsTStrA("Attempted to use an object that has ceased to exist.")}
  DOM {080030103h, $OfsTStrA("Can't save.")}
  DOM {080030104h, $OfsTStrA("The compound file %1 was produced with an incompatible version of storage.")}
  DOM {080030105h, $OfsTStrA("The compound file %1 was produced with a newer version of storage.")}
  DOM {080030106h, $OfsTStrA("Share.exe or equivalent is required for operation.")}
  DOM {080030107h, $OfsTStrA("Illegal operation called on non-file based storage.")}
  DOM {080030108h, $OfsTStrA("Illegal operation called on object with extant marshallings.")}
  DOM {080030109h, $OfsTStrA("The docfile has been corrupted.")}
  DOM {080030110h, $OfsTStrA("Ole32.DLL has been loaded at the wrong address.")}
  DOM {080030201h, $OfsTStrA("The file download was aborted abnormally. The file is incomplete.")}
  DOM {080030202h, $OfsTStrA("The file download has been terminated.")}

  DOM {080040000h, $OfsTStrA("Invalid OLEVERB structure")}
  DOM {080040001h, $OfsTStrA("Invalid advise flags")}
  DOM {080040002h, $OfsTStrA("Can't enumerate any more, because the associated data is missing")}
  DOM {080040003h, $OfsTStrA("This implementation doesn't take advises")}
  DOM {080040004h, $OfsTStrA("There is no connection for this connection ID")}
  DOM {080040005h, $OfsTStrA("Need to run the object to perform this operation")}
  DOM {080040006h, $OfsTStrA("There is no cache to operate on")}
  DOM {080040007h, $OfsTStrA("Uninitialized object")}
  DOM {080040008h, $OfsTStrA("Linked object's source class has changed")}
  DOM {080040009h, $OfsTStrA("Not able to get the moniker of the object")}
  DOM {08004000Ah, $OfsTStrA("Not able to bind to the source")}
  DOM {08004000Bh, $OfsTStrA("Object is static; operation not allowed")}
  DOM {08004000Ch, $OfsTStrA("User cancelled out of save dialog")}
  DOM {08004000Dh, $OfsTStrA("Invalid rectangle")}
  DOM {08004000Eh, $OfsTStrA("compobj.dll is too old for the ole2.dll initialized")}
  DOM {08004000Fh, $OfsTStrA("Invalid window HANDLE")}
  DOM {080040010h, $OfsTStrA("Object is not in any of the inplace active states")}
  DOM {080040011h, $OfsTStrA("Not able to convert object")}
  DOM {080040012h, $OfsTStrA("Not able to perform the operation because Object is not given storage yet")}
  DOM {080040064h, $OfsTStrA("Invalid FORMATETC structure")}
  DOM {080040065h, $OfsTStrA("Invalid DVTARGETDEVICE structure")}
  DOM {080040066h, $OfsTStrA("Invalid STDGMEDIUM structure")}
  DOM {080040067h, $OfsTStrA("Invalid STATDATA structure")}
  DOM {080040068h, $OfsTStrA("Invalid lindex")}
  DOM {080040069h, $OfsTStrA("Invalid tymed")}
  DOM {08004006Ah, $OfsTStrA("Invalid clipboard format")}
  DOM {08004006Bh, $OfsTStrA("Invalid aspect(s)")}
  DOM {08004006Ch, $OfsTStrA("tdSize parameter of the DVTARGETDEVICE structure is invalid")}
  DOM {08004006Dh, $OfsTStrA("Object doesn't support IViewObject interface")}
  DOM {080040100h, $OfsTStrA("Trying to revoke a drop target that has not been registered")}
  DOM {080040101h, $OfsTStrA("This window has already been registered as a drop target")}
  DOM {080040102h, $OfsTStrA("Invalid window HANDLE")}
  DOM {080040110h, $OfsTStrA("Class does not support aggregation (or class object is remote)")}
  DOM {080040111h, $OfsTStrA("ClassFactory cannot supply requested class")}
  DOM {080040140h, $OfsTStrA("Error drawing view")}
  DOM {080040150h, $OfsTStrA("Could not read key from registry")}
  DOM {080040151h, $OfsTStrA("Could not write key to registry")}
  DOM {080040152h, $OfsTStrA("Could not find the key in the registry")}
  DOM {080040153h, $OfsTStrA("Invalid value for registry")}
  DOM {080040154h, $OfsTStrA("Class not registered")}
  DOM {080040155h, $OfsTStrA("Interface not registered")}
  DOM {080040170h, $OfsTStrA("Cache not updated")}
  DOM {080040180h, $OfsTStrA("No verbs for OLE object")}
  DOM {080040181h, $OfsTStrA("Invalid verb for OLE object")}
  DOM {0800401A0h, $OfsTStrA("Undo is not available")}
  DOM {0800401A1h, $OfsTStrA("Space for tools is not available")}
  DOM {0800401C0h, $OfsTStrA("OLESTREAM Get method failed")}
  DOM {0800401C1h, $OfsTStrA("OLESTREAM Put method failed")}
  DOM {0800401C2h, $OfsTStrA("Contents of the OLESTREAM not in correct format")}
  DOM {0800401C3h, $OfsTStrA("There was an error in a Windows GDI call while converting the bitmap to a DIB")}
  DOM {0800401C4h, $OfsTStrA("Contents of the IStorage not in correct format")}
  DOM {0800401C5h, $OfsTStrA("Contents of IStorage is missing one of the standard streams")}
  DOM {0800401C6h, $OfsTStrA("There was an error in a Windows GDI call while converting the DIB to a bitmap.")}
  DOM {0800401D0h, $OfsTStrA("OpenClipboard Failed")}
  DOM {0800401D1h, $OfsTStrA("EmptyClipboard Failed")}
  DOM {0800401D2h, $OfsTStrA("SetClipboard Failed")}
  DOM {0800401D3h, $OfsTStrA("Data on clipboard is invalid")}
  DOM {0800401D4h, $OfsTStrA("CloseClipboard Failed")}
  DOM {0800401E0h, $OfsTStrA("Moniker needs to be connected manually")}
  DOM {0800401E1h, $OfsTStrA("Operation exceeded deadline")}
  DOM {0800401E2h, $OfsTStrA("Moniker needs to be generic")}
  DOM {0800401E3h, $OfsTStrA("Operation unavailable")}
  DOM {0800401E4h, $OfsTStrA("Invalid syntax")}
  DOM {0800401E5h, $OfsTStrA("No object for moniker")}
  DOM {0800401E6h, $OfsTStrA("Bad extension for file")}
  DOM {0800401E7h, $OfsTStrA("Intermediate operation failed")}
  DOM {0800401E8h, $OfsTStrA("Moniker is not bindable")}
  DOM {0800401E9h, $OfsTStrA("Moniker is not bound")}
  DOM {0800401EAh, $OfsTStrA("Moniker cannot open file")}
  DOM {0800401EBh, $OfsTStrA("User input required for operation to succeed")}
  DOM {0800401ECh, $OfsTStrA("Moniker class has no inverse")}
  DOM {0800401EDh, $OfsTStrA("Moniker does not refer to storage")}
  DOM {0800401EEh, $OfsTStrA("No common prefix")}
  DOM {0800401EFh, $OfsTStrA("Moniker could not be enumerated")}
  DOM {0800401F0h, $OfsTStrA("CoInitialize has not been called. ")}
  DOM {0800401F1h, $OfsTStrA("CoInitialize has already been called.")}
  DOM {0800401F2h, $OfsTStrA("Class of object cannot be determined")}
  DOM {0800401F3h, $OfsTStrA("Invalid class string")}
  DOM {0800401F4h, $OfsTStrA("Invalid interface string")}
  DOM {0800401F5h, $OfsTStrA("Application not found")}
  DOM {0800401F6h, $OfsTStrA("Application cannot be run more than once")}
  DOM {0800401F7h, $OfsTStrA("Some error in application program")}
  DOM {0800401F8h, $OfsTStrA("DLL for class not found")}
  DOM {0800401F9h, $OfsTStrA("Error in the DLL")}
  DOM {0800401FAh, $OfsTStrA("Wrong OS or OS version for application")}
  DOM {0800401FBh, $OfsTStrA("Object is not registered")}
  DOM {0800401FCh, $OfsTStrA("Object is already registered")}
  DOM {0800401FDh, $OfsTStrA("Object is not connected to server")}
  DOM {0800401FEh, $OfsTStrA("Application was launched but it didn't register a class factory")}
  DOM {0800401FFh, $OfsTStrA("Object has been released")}

  DOM {08007000Eh, $OfsTStrA("Ran out of memory")}
  DOM {080070057h, $OfsTStrA("One or more arguments are invalid")}
  DOM {080070006h, $OfsTStrA("Invalid HANDLE")}
  DOM {080070005h, $OfsTStrA("General access denied error")}

  DOM {080080001h, $OfsTStrA("Attempt to create a class object failed")}
  DOM {080080002h, $OfsTStrA("OLE service could not bind object")}
  DOM {080080003h, $OfsTStrA("RPC communication failed with OLE service")}
  DOM {080080004h, $OfsTStrA("Bad path to object")}
  DOM {080080005h, $OfsTStrA("Server execution failed")}
  DOM {080080006h, $OfsTStrA("OLE service could not communicate with the Object server")}
  DOM {080080007h, $OfsTStrA("Moniker path could not be normalized")}
  DOM {080080008h, $OfsTStrA("Object server is stopping when OLE service contacts it")}
  DOM {080080009h, $OfsTStrA("An invalid root block pointer was specified")}
  DOM {080080010h, $OfsTStrA("An allocation chain contained an invalid link pointer")}
  DOM {080080011h, $OfsTStrA("The requested allocation size was too large")}

  DOM {080090001h, $OfsTStrA("Bad UID.")}
  DOM {080090002h, $OfsTStrA("Bad Hash.")}
  DOM {080090003h, $OfsTStrA("Bad Key.")}
  DOM {080090004h, $OfsTStrA("Bad Length.")}
  DOM {080090005h, $OfsTStrA("Bad Data.")}
  DOM {080090006h, $OfsTStrA("Invalid Signature.")}
  DOM {080090007h, $OfsTStrA("Bad Version of provider.")}
  DOM {080090008h, $OfsTStrA("Invalid algorithm specified.")}
  DOM {080090009h, $OfsTStrA("Invalid flags specified.")}
  DOM {08009000Ah, $OfsTStrA("Invalid type specified.")}
  DOM {08009000Bh, $OfsTStrA("Key not valid for use in specified state.")}
  DOM {08009000Ch, $OfsTStrA("Hash not valid for use in specified state.")}
  DOM {08009000Dh, $OfsTStrA("Key does not exist.")}
  DOM {08009000Eh, $OfsTStrA("Insufficient memory available for the operation.")}
  DOM {08009000Fh, $OfsTStrA("Object already exists.")}
  DOM {080090010h, $OfsTStrA("Access denied.")}
  DOM {080090011h, $OfsTStrA("Object was not found.")}
  DOM {080090012h, $OfsTStrA("Data already encrypted. ")}
  DOM {080090013h, $OfsTStrA("Invalid provider specified.")}
  DOM {080090014h, $OfsTStrA("Invalid provider type specified.")}
  DOM {080090015h, $OfsTStrA("Provider's public key is invalid.")}
  DOM {080090016h, $OfsTStrA("Keyset does not exist")}
  DOM {080090017h, $OfsTStrA("Provider type not defined.")}
  DOM {080090018h, $OfsTStrA("Provider type as registered is invalid.")}
  DOM {080090019h, $OfsTStrA("The keyset is not defined.")}
  DOM {08009001Ah, $OfsTStrA("Keyset as registered is invalid.")}
  DOM {08009001Bh, $OfsTStrA("Provider type does not match registered value.")}
  DOM {08009001Ch, $OfsTStrA("The digital signature file is corrupt.")}
  DOM {08009001Dh, $OfsTStrA("Provider DLL failed to initialize correctly.")}
  DOM {08009001Eh, $OfsTStrA("Provider DLL could not be found.")}
  DOM {08009001Fh, $OfsTStrA("The Keyset parameter is invalid.")}
  DOM {080090020h, $OfsTStrA("An internal error occurred.")}
  DOM {080090021h, $OfsTStrA("A base error occurred.")}

  DOM {0800B0001h, $OfsTStrA("The specified trust provider is not known on this system.")}
  DOM {0800B0002h, $OfsTStrA("The trust verification action specified is not supported by the specified trust provider.")}
  DOM {0800B0003h, $OfsTStrA("The form specified for the subject is not one supported or known by the specified trust provider.")}
  DOM {0800B0004h, $OfsTStrA("The subject is not trusted for the specified action.")}
  DOM {0800B0005h, $OfsTStrA("Error due to problem in ASN.1 encoding process.")}
  DOM {0800B0006h, $OfsTStrA("Error due to problem in ASN.1 decoding process.")}
  DOM {0800B0007h, $OfsTStrA("Reading / writing Extensions where Attributes are appropriate, and visa versa.")}
  DOM {0800B0008h, $OfsTStrA("Unspecified cryptographic failure.")}
  DOM {0800B0009h, $OfsTStrA("The size of the data could not be determined.")}
  DOM {0800B000Ah, $OfsTStrA("The size of the indefinite-sized data could not be determined.")}
  DOM {0800B000Bh, $OfsTStrA("This object does not read and write self-sizing data.")}
  DOM {0800B0100h, $OfsTStrA("No signature was present in the subject.")}
  DOM {0800B0101h, $OfsTStrA("A required certificate is not within its validity period.")}
  DOM {0800B0102h, $OfsTStrA("The validity periods of the certification chain do not nest correctly.")}
  DOM {0800B0103h, $OfsTStrA("A certificate that can only be used as an end-entity is being used as a CA or visa versa.")}
  DOM {0800B0104h, $OfsTStrA("A path length constraint in the certification chain has been violated.")}
  DOM {0800B0105h, $OfsTStrA("An extension of unknown type that is labeled 'critical' is present in a certificate.")}
  DOM {0800B0106h, $OfsTStrA("A certificate is being used for a purpose other than that for which it is permitted.")}
  DOM {0800B0107h, $OfsTStrA("A parent of a given certificate in fact did not issue that child certificate.")}
  DOM {0800B0108h, $OfsTStrA("A certificate is missing or has an empty value for an important field, such as a subject or issuer name.")}
  DOM {0800B0109h, $OfsTStrA("A certification chain processed correctly, but terminated in a root certificate which isn't trusted by the trust provider.")}
  DOM {0800B010Ah, $OfsTStrA("A chain of certs didn't chain as they should in a certain application of chaining.")}

  DOM {08000FFFFh, $OfsTStrA("Catastrophic failure")}

  DOM {088760818h, $OfsTStrA("D3DERR_WRONGTEXTUREFORMAT")}
  DOM {088760819h, $OfsTStrA("D3DERR_UNSUPPORTEDCOLOROPERATION")}
  DOM {08876081Ah, $OfsTStrA("D3DERR_UNSUPPORTEDCOLORARG")}
  DOM {08876081Bh, $OfsTStrA("D3DERR_UNSUPPORTEDALPHAOPERATION")}
  DOM {08876081Ch, $OfsTStrA("D3DERR_UNSUPPORTEDALPHAARG")}
  DOM {08876081Dh, $OfsTStrA("D3DERR_TOOMANYOPERATIONS")}
  DOM {08876081Eh, $OfsTStrA("D3DERR_CONFLICTINGTEXTUREFILTER")}
  DOM {08876081Fh, $OfsTStrA("D3DERR_UNSUPPORTEDFACTORVALUE")}
  DOM {088760821h, $OfsTStrA("D3DERR_CONFLICTINGRENDERSTATE")}
  DOM {088760822h, $OfsTStrA("D3DERR_UNSUPPORTEDTEXTUREFILTER")}
  DOM {088760826h, $OfsTStrA("D3DERR_CONFLICTINGTEXTUREPALETTE")}
  DOM {088760827h, $OfsTStrA("D3DERR_DRIVERINTERNALERROR")}
  DOM {088760866h, $OfsTStrA("D3DERR_NOTFOUND")}
  DOM {088760867h, $OfsTStrA("D3DERR_MOREDATA")}
  DOM {088760868h, $OfsTStrA("D3DERR_DEVICELOST")}
  DOM {088760869h, $OfsTStrA("D3DERR_DEVICENOTRESET")}
  DOM {08876086Ah, $OfsTStrA("D3DERR_NOTAVAILABLE")}
  DOM {08876017Ch, $OfsTStrA("D3DERR_OUTOFVIDEOMEMORY")}
  DOM {08876086Bh, $OfsTStrA("D3DERR_INVALIDDEVICE")}
  DOM {08876086Ch, $OfsTStrA("D3DERR_INVALIDCALL")}
  DOM {08876086Dh, $OfsTStrA("D3DERR_DRIVERINVALIDCALL")}
  DOM {08876021Ch, $OfsTStrA("D3DERR_WASSTILLDRAWING")}
  DOM {08876086Fh, $OfsTStrA("D3DOK_NOAUTOGEN")}
DbgComErrTableCount equ ($ - DbgComErrTable)/sizeof(DOM)

.const
  DbgComErrUnk    CHRA  "Unknown error", 0
  DbgComSuccess   CHRA  "Success code", 0


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComErr 
; Purpose:    Identifies a COM error with a string.
; Arguments:  Arg1: COM error ID.
;             Arg2: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutComErr proc uses xbx dErrCode:DWORD, pDest:POINTER
  local bHexBuffer[16]:CHRA                             ;13 ANSI characters + filler

  mov ebx, dErrCode
  mov xax, offset DbgComErrTable
  mov ecx, DbgComErrTableCount
  test ebx, BIT31                                       ;Test success bit
  je @@4
  jmp @@2
@@1:
  add xax, sizeof(DOM)
@@2:
  cmp ebx, DWORD ptr [xax]
  je @@3
  dec ecx
  test ecx, ecx
  jne @@1
  mov xcx, offset DbgComErrUnk
  jmp @@5
@@3:
  mov xcx, [xax].DOM.pStr
  jmp @@5
@@4:
  mov xcx, offset DbgComSuccess
@@5:
  invoke DbgOutTextA, xcx, $RGB(255,0,0), DBG_EFFECT_NORMAL, pDest
  lea xbx, bHexBuffer
  FillWordA [xbx], < [>
  add xbx, 2*sizeof(CHRA)
  invoke dword2hexA, xbx, dErrCode
  FillStringA [xbx + 8*sizeof(CHRA)], <h]>
  invoke DbgOutTextA, addr bHexBuffer, $RGB(255,0,0), DBG_EFFECT_NORMAL, pDest
  ret
DbgOutComErr endp
