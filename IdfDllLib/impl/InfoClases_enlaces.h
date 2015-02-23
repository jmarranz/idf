
// dllapi.h

#ifndef INFOCLASESDLLAPI_H
#define INFOCLASESDLLAPI_H


struct DatosBloque;
struct DatosCom;
struct DatosComES;


// Funciones exportadas del DLL


// Enlaza con CDiag

POSITION    _PrimerBloquePos(int tipo);
void    _SiguienteBloque(POSITION& pos, int tipo, const char*& clase,const char*& claseBase,const char*& verSerial);

POSITION    _PrimerComPos();
void    _SiguienteCom(POSITION& pos,const char*& clase,const char*& claseBase,const char*& verSerial);

BOOL _BuscarComES(const char* clave,int tipo,const char*& clase,const char*& claseBloque);

#endif


