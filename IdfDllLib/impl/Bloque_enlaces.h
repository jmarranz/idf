
#ifndef BLOQUEBASEDLLAPI_H
#define BLOQUEBASEDLLAPI_H

class CBloque;
class CCom;


// Enlazan con CBloque

BOOL   _Bloque_setNuevo(CBloque * pBloque);

void   _Bloque_DefineBloque(CBloque * pBloque, void * bloque);

BOOL   _Bloque_IniciarDatosBloque( CBloque * pBloque );

const char *   _Bloque_Accion(CBloque * pBloque);

BOOL   _Bloque_Serializar(CBloque * pBloque, LPSTREAM stream, UINT modo);

CCom *    _Bloque_DevolverDatos(CBloque * pBloque);	

void   _Bloque_DestObjBloqueFunc(CBloque * pBloque, BOOL ObjUsuarioCreado);   

void   _Bloque_IniciarExplicito(CBloque * pBloque);

void   _Bloque_EnError(CBloque * pBloque, int TipoError, const char * EtiqPost);

BOOL   _Bloque_PropUsuario(CBloque  *pBloque);


#endif
