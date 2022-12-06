; ==================================================================================================
; Title:   GraphicsUEFI.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
include Graphic_OOP.inc
.data 

    nd254	dd 255
    nd128	dd 128
  
    minmin REAL8 10000000000000000000.0
    maxmax REAL8 -10000000000000000000.0	

    CStr tituloy1, "A N I M A L   C O M P O S I T I O N (kg)"
	
.code

if IMPLEMENT
    include SerieGraph.inc
    include Graphic_PROC.inc
    include Grilla_PROC.inc
    include Graphic1_PROC.inc
    include tipoS.inc
endif