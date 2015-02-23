
// enlaces.h

#ifndef CONECT_ENLACES_H
#define CONECT_ENLACES_H

class CConect;


// EXPORTACIONES HACIA LOS DLL DE DIAGRAMAS Y BLOQUES PARA COMUNICACIÓN BIDIRECCIONAL


extern "C" {


// Para Conector
_export  const char* ConectorDLL_GetNombreInterno(CConect* pCon);
_export  const char* ConectorDLL_GetEtiqueta(CConect* pCon);
_export  BOOL ConectorDLL_EsRetroAnotador(CConect* pCon);
_export  void ConectorDLL_Mensaje(CConect* pCon, const char * mensaje);

}

#endif
