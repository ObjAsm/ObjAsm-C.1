; ==================================================================================================
; Title:   SerieGraph.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================


Method Puntito.Init, uses xsi, x1:QWORD, y1:QWORD
    SetObject xsi
    fld     x1
    fstp    [xsi].x
    fld     y1
    fstp    [xsi].y
MethodEnd

Method SerieGraph.Init, uses xsi, xeje:dword, xcolor:dword, xmod:dword, xprior:dword
	SetObject xsi
	m2m [xsi].Prioridad, xprior, eax
	m2m [xsi].Modo, xmod, eax
	m2m [xsi].Color, xcolor, eax	
	m2m [xsi].Eje, xeje, eax	
MethodEnd

Method SerieGraph.CargaPunto , uses xsi xax, x : REAL8, y : REAL8
	SetObject xsi
	New Puntito
	OCall xax::Puntito.Init, x, y      			;Initialize Puntito instance values
	OCall [xsi].Puntos::LinkedList.Append, xax
	lea xax, [xsi].Puntos
MethodEnd

Method SerieGraph.Clear, uses xsi
	SetObject xsi
	OCall [xsi].Puntos::LinkedList.Clear 
MethodEnd

Method SerieGraph.Done, uses xsi
	SetObject xsi
	OCall [xsi].Puntos::LinkedList.Done
MethodEnd
