// Newton_Resultados.h: interface for the Newton_Resultados class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_RESULTADOS_H__1FE1F3A4_49FC_452F_8AA2_806381E1E09B__INCLUDED_)
#define AFX_NEWTON_RESULTADOS_H__1FE1F3A4_49FC_452F_8AA2_806381E1E09B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Newton_SalidaDatos;


// Clase Newton_Resultados, clase de muestra de los valores actuales de iteraci¢n, susceptibles de modificarse. Es tambi‚n el di logo de salida de resultados.

class Newton_Resultados : public CBloqueFunc
{

public:
  	DECLARAR_BLOQUE_FUNCIONAL(Newton_Resultados)

	DECLARAR_COM_ENTRADA(Newton_SalidaDatos)
	DECLARAR_COM_ENTRADA(CComSerial)
    DECLARAR_COM_SALIDA(Newton_SalidaDatos) // Usado en multidiagrama
    DECLARAR_COM_SALIDA(CComSerial)

    
  	virtual void IniciarDatos();  
  	virtual void LeerFichero(CArchive& ar);
  	virtual void GuardarFichero(CArchive& ar);
  	virtual BOOL RecibirDatosEntrada(Newton_SalidaDatos* pE);
  	virtual BOOL RecibirDatosEntrada(CComSerial* pE);

	virtual void EnviarDatosSalida(Newton_SalidaDatos* pS);
	virtual void EnviarDatosSalida(CComSerial* pS);

	virtual CString Accion();

private:
  
  	double x;
  	double e;
};



#endif // !defined(AFX_NEWTON_RESULTADOS_H__1FE1F3A4_49FC_452F_8AA2_806381E1E09B__INCLUDED_)
