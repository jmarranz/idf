// Newton_Actuales.h: interface for the Newton_Actuales class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_ACTUALES_H__256DF6B1_F946_4D28_8432_7DB2B31C0EFF__INCLUDED_)
#define AFX_NEWTON_ACTUALES_H__256DF6B1_F946_4D28_8432_7DB2B31C0EFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Clase Newton_Actuales, clase de muestra de los valores actuales de iteraci¢n, susceptibles de modificarse. Es tambi‚n el di logo de salida de resultados.

class Newton_SalidaDatos;
class Newton_SalidaInicio;


class Newton_Actuales : public CBloqueFunc
{
public:
  	DECLARAR_BLOQUE_FUNCIONAL(Newton_Actuales)

  	DECLARAR_COM_ENTRADA(Newton_SalidaDatos)
  	DECLARAR_COM_ENTRADA(Newton_SalidaInicio)
  	DECLARAR_COM_ENTRADA(CComSerial)

	DECLARAR_COM_SALIDA(Newton_SalidaDatos)
	DECLARAR_COM_SALIDA(CComSerial)

	
  	virtual void IniciarDatos();    
  	virtual void LeerFichero(CArchive& ar);
  	virtual void GuardarFichero(CArchive& ar);

  	virtual BOOL RecibirDatosEntrada(Newton_SalidaDatos* pE);
  	virtual BOOL RecibirDatosEntrada(Newton_SalidaInicio* pE);  
  	virtual BOOL RecibirDatosEntrada(CComSerial* pE);  

  	virtual void EnviarDatosSalida(Newton_SalidaDatos* pS);
  	virtual void EnviarDatosSalida(CComSerial* pS);
	
  	virtual CString Accion();
  	
private:
  
  	double x;
  	double e;
};

#endif // !defined(AFX_NEWTON_ACTUALES_H__256DF6B1_F946_4D28_8432_7DB2B31C0EFF__INCLUDED_)
