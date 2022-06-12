RAWINTERFACE MACRO CName:REQ
  curClass TEXTEQU <CName>
  % __&CName&_size = 0
  @CatStr(CName, < STRUCT >)
  ptrDefS TEXTEQU <psr>
  ptrDefS CATSTR ptrDefS, <&curClass&>, < TYPEDEF PTR >, <&curClass&>
  % ptrDefS
ENDM

ENDRAWINTERFACE MACRO
  curClass ENDS
ENDM

STDFUNC MACRO _method_:REQ, retType:REQ, protoDef:VARARG
  LOCAL sz1, sz2
  pDef CATSTR <TYPEDEF PROTO >,<(&retType&) >
  IFNB <protoDef>
    pDef CATSTR pDef, <, >, <&protoDef>
  ENDIF
  sz2 CATSTR <_>, curClass, <_&_method_>, <Pto>
  % &sz2 &pDef
  % sz1 typedef PTR &sz2
  % _method_ sz1 0
  % __&curClass&_size = __&curClass&_size + 8
  fnex TEXTEQU <_>
  fnex CATSTR fnex, curClass, <_>, <&_method_&>, < PROTO >, <(&retType&) >
  IFNB <&protoDef>
    fnex CATSTR fnex, <, >, <&protoDef&>
  ELSE
  ENDIF
  fnex
ENDM
