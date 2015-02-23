// BloqueExe.h: interface for the CBloqueExe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEEXE_H__965A38B3_576A_48FC_A7B3_AD288294F026__INCLUDED_)
#define AFX_BLOQUEEXE_H__965A38B3_576A_48FC_A7B3_AD288294F026__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\BloqueModo.h"

class CConect;
class CBaseView;
class CComunicacion;


class CBloqueExe : public CBloqueModo  
{
	DECLARE_DYNAMIC(CBloqueExe)
public:
	CBloqueExe();
	virtual ~CBloqueExe();

	virtual void IniciarVarEstado();   // Inicializa variables de estado que no se guardan a fichero.
	virtual BOOL IniciarDatosBloque() = 0;  
	virtual void IniciarExplicito(const Instante& t);  // Llamada a través de menú para reiniciar los datos de un diagrama ya creado.

	virtual void EnError(int TipoError, CBloque* bloque) = 0;    

	virtual BOOL EstadoValido();  // true si el estado es válido para devolver datos ejecutarse etc.

	virtual CString Accion(CBaseView* view) = 0;

	virtual CString Ejecutar(CBaseView *view);
	virtual CString Ejecutar(CConect* con,CBaseView *view);	

	virtual void ComienzoEjecucion(CBaseView *view);   // Para Ejecución directa normal
	virtual void ComienzoEjecucionAuto(CBaseView *view);    // Para Ejecución directa automática

	virtual BOOL ProcesarEntradaDeDatos(CConect* con,CString& etiq, BOOL Retroanotar = false);
	virtual BOOL ProcesarSalidaDeDatos(CBaseView* view, CString& etiq, BOOL Retroanotar = false, BOOL EnviarCascadaRetro = false);
	virtual CComunicacion* DevolverDatos(CConect* con);
	virtual BOOL AceptarDatos(CBaseView* view, CConect* con, CComunicacion* pE);

	virtual BOOL Retroanotar(CString& EtiqConector, BOOL EnviarCascadaRetro);
	virtual BOOL RecibirRetroanotacion(CString& EtiqConector);

	virtual void Consola(const char* mensaje, int origen = SISTEMA);
	virtual void Consola(CString& mensaje, int origen = SISTEMA);

	virtual CBloque* BuscaBloqueIni(CString& conetiq, POSITION& pos,CConect*& con, BOOL Retroanota);
	virtual CBloque* BuscaBloqueFin(CString& conetiq,POSITION& pos,CConect*& con, BOOL Retroanota);
	virtual CBloque* BuscaBloqueFinSgte(CString& etiq,POSITION& pos,CConect*& con, BOOL Retroanota);

	virtual void ActualizaEstado() { }

public:
	// Variables de estado que no se guardan a fichero, necesario inicializar respecto a la funcionalidad:

	CString m_etiqContinuar;  // Por donde continuar (idem salida de Proceso()), se usa en multidiagrama para que el bloque padre sepa por donde continuar.
	
	BOOL m_inicioAuto;  // Controla si el bloque inició un proceso automático directo. Valor 1 -> inició auto. Es variable de estado que no se guarda a fichero pues su valor sería siempre 0	
	UINT m_contAuto;     // Número de veces que se ha pasado por el bloque en modo Auto.
	BOOL m_haPasadoRetro;  // Evita que una retroanotación en cascada sea un bucle infinito

};

#endif // !defined(AFX_BLOQUEEXE_H__965A38B3_576A_48FC_A7B3_AD288294F026__INCLUDED_)
