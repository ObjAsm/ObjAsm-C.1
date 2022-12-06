; ==================================================================================================
; Title:   Graphic_OOP.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
	DefineDD macro a1,a2
		DefineVariable &a1, dword, &a2
	endm
	DefinePT macro a1,a2
		DefineVariable &a1, POINTER, &a2
	endm

	DefineRect macro a1
		DefineVariable &a1, RECT, {}
	endm

	ifndef maxejes
		maxejes equ 1
	endif

	xconf equ 380
	yconf equ 330

	fontconfig equ 18
	
	
    SG_Modo_Punto           equ  0
    SG_Modo_LineaDC         equ  1	; DC
    SG_Modo_Rectangle       equ  2	; DC
    SG_Modo_DoubleCircle    equ  3	; DC
    SG_Modo_Circle          equ  4	; DC
    SG_Modo_Diamante        equ  5	; DC
    SG_Modo_Esfera          equ  6
    SG_Modo_Cub             equ  7
    SG_Modo_CircleandLine   equ  8
    SG_Modo_Linea           equ  9
    SG_Modo_LineaGruesa     equ 10
    SG_Modo_Esfera2         equ 11
    SG_Modo_LineaGdip       equ 12
    SG_Modo_CircleGdip      equ 13
    SG_Modo_PipeLine        equ 14
	
    SG_Modo_LineaCortada    equ 15
	
    SG_Modo_Jewel           equ 16

Object Eje_gr1,, Primer
	DefineDD completo, 1
	DefineDD base, 0 ; ubicación en el gráfico
	DefineDD tope, 0
	DefineDD color, $RGB(200,200,200,255)
	DefinePT titulo, 0 
ObjectEnd

Object Puntito,, Primer
	DefineVariable	x, real8, 0.0
	DefineVariable	y, real8, 0.0
	RedefineMethod	Init, QWORD, QWORD
ObjectEnd

Object SerieGraph, 5003, Primer
	DefineVariable  xName, CHR, 32 dup (0)
	DefineVariable  Eje, dword, 0	
	DefineVariable  Prioridad, dword, 0	
	DefineVariable  Color, dword, 0	
	DefineVariable  Brush, dword, 0	
	DefineVariable  Pen, dword, 0	
	DefineVariable  Modo, dword, 0	
	DefineVariable  Dot, dword, 0	

	Embed			Puntos, LinkedList	

	DefineVariable	maximox, REAL8, 360.0
	DefineVariable	maximoy, REAL8, 80.0
	DefineVariable	minimox, REAL8, 0.0
	DefineVariable	minimoy, REAL8, 0.0
	
  	RedefineMethod  Init, DWORD, DWORD, DWORD, DWORD    ;-> Eje, Color, Modalidad, Prioridad 
  	RedefineMethod  Done
 
   	VirtualMethod  CargaPunto, REAL8, REAL8    ;-> x, y
  	VirtualMethod  Clear
  	
ObjectEnd


Object Grilla, , Primer
	
	DefineDD dWidth, xconf
	DefineDD dHeight, yconf 
	DefineDD pxTitulo, 1;5+30
	DefineDD pxEjeX2, 15+30
	DefineDD pxEjeX1, 0;16+30
	DefineDD pxLeyenda, 18+30
	DefineDD pxEjeY1, 75+25
	DefineDD pxEjeY2, 10+5

	DefineDD pxArcMargin, 3
	
    DefineRect rTitulo
	DefineRect rEjeX2
	DefineRect rEjeX1
	DefineRect rLeyenda
	DefineRect rEjeY1
	DefineRect rEjeY2

	DefineRect rDibujo

	DefineRect rArcTL
	DefineRect rArcTR
	DefineRect rArcBL
	DefineRect rArcBR

	DefineDD pxArc	
	DefineDD pxcArc	
	DefineDD pxx1Arc	
	DefineDD pxx2Arc	
	DefineDD pxy1Arc
	DefineDD pxy2Arc
	
	DefineDD pxx1Line
	DefineDD pxy1Line
	DefineDD pxx2Line
	DefineDD pxy2Line

	DefineDD dCentrow
	DefineDD dCentroh

	DefineDD alto
	DefineDD ancho
	VirtualMethod CalculaMarcos
	Embed Pxm, CharsUEFI
	
ObjectEnd

Object Graphic0, , Grilla
	RedefineMethod  Done
  	RedefineMethod  Init, POINTER, POINTER, DWORD, DWORD, XWORD   ;-> Owner, ScreenBuffer, Width, Height, Delta
	DefineVariable	BASE_BRUSH, DWORD, NULL
	
	DefineVariable step, dword, 50
	DefineVariable pos, dword, 0
	DefineVariable lastpos, dword, 0
	DefineVariable ini, dword, 0
	DefineVariable fin, dword, 1000
	DefineVariable marginl, dword, 5
	DefineVariable marginr, dword, 5
	DefineVariable margint, dword, 5
	DefineVariable marginb, dword, 5
	DefineVariable steping, dword, 1

	DefineVariable numbercolor, dword, $RGB(50,50,250,255)
	
	; Escalado
	DefineVariable	inicio, DWORD, NULL
	DefineVariable	final, DWORD, NULL

	DefineVariable	escala0, REAL8, ?
	DefineVariable	escalax, REAL8, ?
	DefineVariable	escalay, REAL8, maxejes dup (  0.0)
	DefineVariable	escalam, REAL8, 30.0
	DefineVariable	intervalox, REAL8, 30.25

	DefineVariable	maximox, REAL8, 360.0
	DefineVariable	maximoy, REAL8, maxejes dup ( 0.0)
	DefineVariable	minimox, REAL8, 0.0
	DefineVariable	minimoy, REAL8, maxejes dup (  0.0)
	DefineVariable	meanx, REAL8,  0.0
	DefineVariable	meany, REAL8, maxejes dup (  0.0)

	; Anclajes
	DefineVariable 	puntosS, POINTER, 6 dup (NULL)
	
	DefineVariable 	etapasg, dword, 6 dup (0)	
  	
	DefineVariable 	moscasS, xword, 0
	DefineVariable 	moscasT, xword, 0	; for tituloSerie
	  
	; Detalles
	
	DefineVariable	titulo, POINTER
	DefineVariable	tituloSerie, POINTER, 5 dup (NULL)
	DefineVariable	unidady, POINTER

	DefineVariable 	ColorSeries, dword, 6 dup (NULL)
	; Procesos 
	VirtualMethod	grilla
	VirtualMethod	HaceEjesX
	VirtualMethod	HaceEjesY
	DefineVariable 	yadibujo, dword, FALSE
	
	DefineDD EjesY, 1
	DefineVariable 	BaseEjesY, POINTER, 6 dup (NULL)
	
	DefineDD EjesX, 1
	DefineVariable 	BaseEjesX, POINTER, 2 dup (NULL)
ObjectEnd                                               ;Ends object definition

Object Graphic1,, Graphic0
    RedefineMethod  Init, POINTER, POINTER, DWORD, DWORD, XWORD   ;-> Owner, ScreenBuffer, Width, Height, Delta
    VirtualMethod   Paint

    Embed	      BaseSeries, LinkedList
    
    VirtualMethod   InitSerieS, DWORD, DWORD, DWORD, DWORD    ;-> Eje, Color, Modalidad, Prioridad
    ;----------------------------------------------------
    DefineVariable  calculado, dword, 0 
    DefineVariable	minmin, REAL8, 10000000000000000000.0
    DefineVariable	maxmax, REAL8, -10000000000000000000.0	
    VirtualMethod 	BuscaMaximos
    ;----------------------------------------------------
    DefineVariable  modo, dword, 0 		; store SerieGraph mode
    DefineVariable  color, dword, 0 		; store SerieGraph mode
    DefineVariable  ColorBas, dword, 6 dup (NULL)
    DefineVariable  activeColor, dword, 0 		; store SerieGraph color
    DefineVariable  Dot, dword, 0	
    DefineVariable  dotp, dword, 0	; guarda puntero a Resul03
	
    DefineVariable lastx, sdword, 0
    DefineVariable lasty, sdword, 0

    DefineVariable	posix, DWORD, NULL
    DefineVariable	posiy, DWORD, NULL
    DefineVariable  ColorEnUso, dword,0
    ;----------------------------------------------------
    DefineVariable	arranque, dword , 0

    ; ---- Multiples --------------------------------
    VirtualMethod   CargaPuntoS, DWORD, REAL8, REAL8
    VirtualMethod   graficaS
    VirtualMethod   dibujaS, DWORD, XWORD
	
    VirtualMethod 	Clear
    ;---------------------------------------------------
	
    VirtualMethod	PoneSeries
	
    DefineVariable resized, dword, 0

ObjectEnd

    CalculaPuntito macro eje1
			
        SetObject xbx, Puntito, punto

        mov     xax, &eje1
			
        fld     [xsi].minimoy[xax*8]
        fsub    [xbx].y
        fmul    [xsi].escalay[xax*8]
        fiadd   [xsi].rDibujo.bottom
        fistp   a1
			
        fld     [xbx].x
        fsub    [xsi].minimox[xax*8]
        fmul    [xsi].escalax
        fiadd   [xsi].rDibujo.left
        fistp   a3
    endm
