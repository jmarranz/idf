

// Macros, funciones etc. de utilidad globales.

#ifndef GLOBAL_H
#define GLOBAL_H


// Declaración más resumida y a la vieja usanza (como era en 16 bits)
#define  _export  __declspec(dllexport)



// MACROS GLOBALES:

// Variables de visualización:

#define ANCHOLIN       2


// Colores

#define 	AZUL		RGB(0  , 255, 255)
#define 	AMARILLO	RGB(255, 255,   0)
#define 	MORADO		RGB(255,   0, 255)
#define 	VERDE		RGB(  0, 255,   0)

#define 	GRIS  		RGB(240, 240, 240) /* RGB(191, 191, 191) */


// Origen mensaje consola:

#define 	SISTEMA	1
#define 	USUARIO 2


// FUNCIONES de utilidad GLOBALES.



BOOL EsValidaVentana(CWnd* pwin);  // Verifica que pwin apunta a una ventana existente

class CConect;
class CDiagBase;
class CBloqueDiag;


class CGlobal
{
public:

	static void setDLLInfo(HINSTANCE hins);


	static void Mensaje(const CString& men);
	static void Mensaje(const char * men);
	static BOOL Confirm(const CString& men);

	static CDocument*  NuevoDiagSinPrompt(BOOL diseno);   // Creación de nuevo diagrama funcional a partir de LDD pasado en CWinApp. Por ejemplo para el diagrama hijo en multidiagrama.
	static CDocument*  AbrirDiagSinPrompt(LPCSTR lpszFileName,BOOL diseno); // Carga de un diagrama funcional ya salvadado a partir de un fichero .pry pasado por CWinApp. Por ejemplo para el diagrama hijo en multidiagrama.

public:
	static HINSTANCE m_DLLhinstance;  // Instancia de Idf.dll

	// Variables temporales de intercambio en el proceso de crear/cargar multidiagramas: 

	static CString m_fichero;
	static BOOL m_esLDD;

	static BOOL m_nuevoDesdeDiseno; // Temporal cuando se carga un diagrama en modo funcional a partir del LDD generado en diseño.
    static CBloqueDiag* p_bloqPadre;  // El padre creador del diagrama nuevo o cargado.

	static CMultiDocTemplate* p_docTemplateExe;
	static CMultiDocTemplate* p_docTemplateDis;

protected:
	// Punteros con valor temporal

};


#endif


