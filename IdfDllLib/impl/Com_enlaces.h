
#ifndef COMDLLAPI_H
#define COMDLLAPI_H

class CCom;


// Enlaces con CConect:

void   _Com_DestObjDatosCom(CCom * pECCom );

BYTE*  _Com_SerializarGuardadoObjCom(CCom * pCom, DWORD& len);

BOOL  _Com_SerializarCargaObjCom(BYTE* buff,DWORD len,CCom* pCom);




#endif

