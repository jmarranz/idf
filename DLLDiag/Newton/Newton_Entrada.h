// Newton_Entrada.h: interface for the Newton_Entrada class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_ENTRADA_H__462E5753_2F0E_4047_BBE8_51AFEEF54718__INCLUDED_)
#define AFX_NEWTON_ENTRADA_H__462E5753_2F0E_4047_BBE8_51AFEEF54718__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Newton_SalidaDatos;
class Newton_SalidaInicio;
class Newton_ComRetro;


// Clase Newton_Entrada

class Newton_Entrada : public CBloqueFunc  // Clase del bloque de entrada de datos y de configuraci¢n del bucle. Se encarga de Recibirr los datos de configuraci¢n del algoritmo.
{
 
public:
	DECLARAR_BLOQUE_FUNCIONAL(Newton_Entrada)

	DECLARAR_COM_SALIDA(Newton_SalidaInicio)
	DECLARAR_COM_SALIDA(CComSerial)
	DECLARAR_COM_SALIDA(Newton_ComRetro)
		  
  	Newton_Entrada();
  	~Newton_Entrada();

	virtual void IniciarDatos();  
  	virtual BOOL NuevosObjDatos();
  	virtual void DestObjDatos();
  	virtual void LeerFichero(CArchive& ar);
  	virtual void GuardarFichero(CArchive& ar);

 	virtual void EnviarDatosSalida(Newton_SalidaInicio* pS);
  	virtual void EnviarDatosSalida(CComSerial* pS);
	virtual void EnviarDatosSalida(Newton_ComRetro* pS);
  
  	virtual CString Accion();
  
  	virtual BOOL PropiedadesBloque();  

private:
  
  	double emax;
  	double x0;
	double h;
 
  	CFontDialog* ejemplo;
};

#endif // !defined(AFX_NEWTON_ENTRADA_H__462E5753_2F0E_4047_BBE8_51AFEEF54718__INCLUDED_)
