
// Diagrama_enlaces.h

#ifndef DIAGRAMA_ENLACES_H
#define DIAGRAMA_ENLACES_H


// Funciones exportadas del DLL

// Parte del c�digo tomado de traceapi.h del ejemplo DLLTRACE del Visual C++ 1.0

/*  Probablemente no se necesiten, pero si se colgara inexplicablemente el programa,
	habr�a que enlazarlas din�micamente al PROY. 

BOOL   PASCAL  _export FilterDllMsg(LPMSG lpMsg);
void   PASCAL  _export ProcessDllIdle();

*/


// Enlaza con CDiag

BOOL   _IniciarDLLDiagrama(HINSTANCE hInstance, HWND hwin);

void   _LiberarDLLDiagrama();


#endif


