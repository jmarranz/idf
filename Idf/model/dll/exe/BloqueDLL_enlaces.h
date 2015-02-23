
// BloqueDLL_enlaces.h

#ifndef BLOQUEDLL_ENLACES_H
#define BLOQUEDLL_ENLACES_H

class CBloqueDLL;


// EXPORTACIONES HACIA LOS DLL DE DIAGRAMAS Y BLOQUES PARA COMUNICACIÓN BIDIRECCIONAL


extern "C" {

// Para Bloque

_export  const char *    BloqueDLL_getEtiqueta(CBloqueDLL* bloque);
_export  const char *    BloqueDLL_getNombreInterno(CBloqueDLL* bloque);
_export  void    BloqueDLL_CambiaEstado(CBloqueDLL* bloque, int estado);
_export  int     BloqueDLL_getEstado(CBloqueDLL* bloque);
_export  BOOL    BloqueDLL_EsNuevo(CBloqueDLL* bloque);
_export  BOOL    BloqueDLL_EsModoAuto(CBloqueDLL* bloque);
_export  BOOL    BloqueDLL_InicioModoAuto(CBloqueDLL* bloque);
_export  void    BloqueDLL_ExpMensaje(CBloqueDLL* bloque, const char  * mensaje);
_export  BOOL    BloqueDLL_ExpConfirm(CBloqueDLL* bloque, const char  * mensaje);
_export  BOOL    BloqueDLL_ExpWinSpawn(CBloqueDLL* bloque, LPCSTR lpszCmdLine, UINT fuCmdShow);
_export  void    BloqueDLL_Consola(CBloqueDLL* bloque, const char  * mensaje, int origen);
_export  BOOL    BloqueDLL_Retroanotar(CBloqueDLL* bloque, const char  * EtiqConector, BOOL EnviarCascadaRetro);
_export  BOOL    BloqueDLL_RecibirRetroanotacion(CBloqueDLL* bloque, const char  * EtiqConector);
_export  BOOL    BloqueDLL_AccionOLEItem(CBloqueDLL* bloque, const char  * nombre, LONG nVerbo);
_export  void    BloqueDLL_IterarOLEItem(CBloqueDLL* bloque, POSITION& pos, const char  *& nombre );

_export  void    BloqueDLL_Ayuda(CBloqueDLL* bloque, const char *& texto);
_export  void    BloqueDLL_RedefAyuda(CBloqueDLL* bloque, const char * ayuda);
_export  void    BloqueDLL_getMacro(CBloqueDLL* bloque, const char *& macro);	
_export  void    BloqueDLL_RedefMacro(CBloqueDLL* bloque, const char * macro);

}

#endif
