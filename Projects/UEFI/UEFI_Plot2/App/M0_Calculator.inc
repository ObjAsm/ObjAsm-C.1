
Object M0_Calculator,,Primer
    RedefineMethod Init
    RedefineMethod Done
    VirtualMethod Calculo
    VirtualMethod MuestraG
    VirtualMethod MuestraVariables, POINTER    
    Embed TestBW, LinealTest
ObjectEnd

Method M0_Calculator.Init, uses xsi
    SetObject xsi
    OCall [xsi].TestBW::LinealTest.Init
MethodEnd

Method M0_Calculator.Done, uses xsi
    SetObject xsi
    OCall [xsi].TestBW::LinealTest.Done
MethodEnd

Method M0_Calculator.LoopUnidad, uses xsi xbx, lista : POINTER, v1:xword
    local lbuffer[32]:CHR

    SetObject xsi, LinkedList, lista
    OCall xsi.GetFirst
    .while xax != NULL
        .if xax
            assume xax: $ObjPtr(ACUo)
            .if v1 == 0
                fld [xax].R8_edad
            .elseif v1 == 1    
                fld [xax].R8_ebw
            .endif
            invoke St0ToStr, addr lbuffer, 8, 4, 0
            fstp st
            mov rcx, pConsoleOut
            invoke [rcx].ConOut.OutputString, rcx, ADDR lbuffer
        
            assume xax: nothing			
        .endif
        OCall xsi.GetNext
    .endw    
MethodEnd

Method M0_Calculator.LoopVariables, uses xsi xbx, lista : POINTER, tope:xword
    local v1:xword
    local lbuffer[32]:CHR
    local gralx:real8, graly:real8

    SetObject xsi, LinkedList, lista
    OCall xsi.GetFirst
    .while xax != NULL
        .if xax
            mov xbx, xax
            assume xbx: $ObjPtr(ACUo)
            ForLp v1, 0, tope
                .if v1 == 0
                    fld [xbx].R8_edad
                .elseif v1 == 1    
                    fld [xbx].R8_ebw
                .endif
                
                invoke St0ToStr, addr lbuffer, 8, 4, 0
                fstp st
                mov rcx,pConsoleOut
                invoke [rcx].ConOut.OutputString, rcx, ADDR lbuffer
            Next v1
            assume xbx: nothing			
            mov rcx,pConsoleOut
            invoke [rcx].ConOut.OutputString, rcx, ADDR cr$
        .endif
        OCall xsi.GetNext
    .endw    
MethodEnd

Method M0_Calculator.MuestraVariables, uses xsi xbx, lista : POINTER
    local v1:xword
    local lbuffer[32]:CHR
    local gralx:real8, graly:real8

    SetObject xsi, LinkedList, lista
    OCall xsi.GetFirst
    .while xax != NULL
        .if xax
            mov xbx, xax
            assume xbx: $ObjPtr(ACUo)
            if 1
            OCall pGraphic::Graphic1.CargaPuntoS, 0, [xbx].R8_ebw, [xbx].R8_prot
            OCall pGraphic::Graphic1.CargaPuntoS, 1, [xbx].R8_ebw, [xbx].R8_fat
            OCall pGraphic::Graphic1.CargaPuntoS, 2, [xbx].R8_ebw, [xbx].R8_water
            else
            OCall pGraphic::Graphic1.CargaPuntoS, 0, [xbx].R8_edad, [xbx].R8_prot
            OCall pGraphic::Graphic1.CargaPuntoS, 1, [xbx].R8_edad, [xbx].R8_fat
            OCall pGraphic::Graphic1.CargaPuntoS, 2, [xbx].R8_edad, [xbx].R8_water
            endif
            assume xbx: nothing			
        .endif
        OCall xsi.GetNext
    .endw    
MethodEnd

Method M0_Calculator.MuestraG, uses xsi xbx
	
    local v1: xword
   
    SetObject xsi
	
    OCall pGraphic::Graphic1.InitSerieS, 0, 0FF0000FFh, SG_Modo_PipeLine, 0
    OCall pGraphic::Graphic1.InitSerieS, 1, 0FF00FF00h, SG_Modo_PipeLine, 0
    OCall pGraphic::Graphic1.InitSerieS, 2, 0FFFFFF00h, SG_Modo_PipeLine, 0
    
    mov xax, pGraphic
    mov [xax].$Obj(Graphic1).moscasT, 3
    lea xbx, [xax].$Obj(Graphic1).tituloSerie
    m2m [xbx+0*@WordSize], $OfsCStr("Protein"),xax
    m2m [xbx+1*@WordSize], $OfsCStr("Fat"), xax
    m2m [xbx+2*@WordSize], $OfsCStr("Water"),xax

    lea xbx, [xsi].TestBW
	
    OCall xbx::LinealTest.GetFirst
    .while xax != NULL
        lea xcx, [xax].$Obj(UnidadExperimental).integ
        mov xdx, [xcx].$Obj(IntgSim).acum
        OCall xsi.MuestraVariables, xdx
        OCall xbx::LinealTest.GetNext	
    .endw

MethodEnd

Method M0_Calculator.Calculo, uses xsi
	
    local krnl: xword
    
    SetObject xsi

    OCall [xsi].TestBW::SimpleTest.SetControls
    OCall [xsi].TestBW::SimpleTest.SetAjustando, FALSE
    OCall [xsi].TestBW::SimpleTest.Simulacion

    mov [xsi].TestBW.calculado, TRUE
			
MethodEnd
