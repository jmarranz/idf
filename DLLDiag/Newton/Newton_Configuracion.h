// Newton_Configuracion.h: interface for the Newton_Configuracion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Newton_Configuracion_H__26260B6A_4BC1_4487_B00C_505997E00786__INCLUDED_)
#define AFX_Newton_Configuracion_H__26260B6A_4BC1_4487_B00C_505997E00786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Newton_ComRetro;

// Clase Newton_Configuracion. Clase de retroanotación por objeto global.

class Newton_Configuracion : public CBloqueRetro
{
	DECLARAR_BLOQUE_RETROANOTACION(Newton_Configuracion)
	
	DECLARAR_COM_ENTRADA(Newton_ComRetro)
	DECLARAR_COM_ENTRADA(CComSerial)

	DECLARAR_COM_SALIDA(Newton_ComRetro)
	DECLARAR_COM_SALIDA(CComSerial)


public:	
	virtual void IniciarDatos();  
  	virtual BOOL NuevosObjDatos();
  	virtual void DestObjDatos();
  	virtual void LeerFichero(CArchive& ar);
  	virtual void GuardarFichero(CArchive& ar);	
	virtual BOOL PropiedadesBloque();

	virtual BOOL RecibirDatosEntrada(Newton_ComRetro* pE);
	virtual BOOL RecibirDatosEntrada(CComSerial* pE);

	virtual void EnviarDatosSalida(Newton_ComRetro* pS);
	virtual void EnviarDatosSalida(CComSerial* pS);

	double emax;
	double h;
  	
  	CString* ejemplo;
};


#endif // !defined(AFX_Newton_Configuracion_H__26260B6A_4BC1_4487_B00C_505997E00786__INCLUDED_)
