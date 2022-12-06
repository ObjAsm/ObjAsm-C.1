; ==================================================================================================
; Title:   SimpleTest.asm
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: ObjAsm compilation file for SimpleTest object.
; Version: Version 1.0.0, December 2018
;            - First release.
; ==================================================================================================
include Control_OA.inc

BASE textequ <\masm32/projects/gralF>

% include BASE\ObjHSE.inc

%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc
% SysSetup OOP, NUIOA, LIBOA, DEBUG(WND, INFO, TRACE,"SimpleTest")

% include &MacPath&WinHelpers.inc
;Add here all files that build the inheritance path and referenced objects
%include @Environ(OBJASM_PATH)\\Code\\Objects\\Primer.inc
%include @Environ(OBJASM_PATH)\\Code\\Objects\\Stream.inc
%include @Environ(OBJASM_PATH)\\Code\\Objects\\WinPrimer.inc

include \masm32\macros\SmplMath\math.inc
fSlvSelectBackEnd FPU
;include \masm32\macros\SmplMath\freg_notin32.inc
%include @Environ(OBJASM_PATH)\\Code\\Macros\\fMath.inc

%include BASE/macs.asm

%include BASE/modelo/modelomac.inc

include proyecto.inc

LoadObjectsD .\, .\objects\, LinkedListH

LoadObjectsD .\, ..\gralF\Statics\, StatLin

LoadObjectsD .\, .\modelo\, modeloB

LoadObjectsD .\, .\basic\, IntgBase
LoadObjectsD .\, .\basic\, IntgSim
;Add here the file that defines the object(s) to be included in the library
MakeObjects .\Test\SimpleTest

end