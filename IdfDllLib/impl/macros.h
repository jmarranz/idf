
// clases.h

#ifndef MACROS_H 
#define MACROS_H


// Declaración de API para el diagrama, deberá declararse en la clase aplicación
#define DECLARAR_DIAGRAMA(Clase)


#define IMPLEMENTAR_DIAGRAMA(Clase,ClaseBase)  \
		IMPLEMENTAR_DLLAPI_INFOCLASES  \
		IMPLEMENTAR_DLLAPI_DIAGRAMA  \
		IMPLEMENTAR_DLLAPI_BLOQUE  \
		IMPLEMENTAR_DLLAPI_COM


#define IMPLEMENTAR_DLLAPI_INFOCLASES  \
	extern "C" _export POSITION PrimerBloquePos(int tipo)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _PrimerBloquePos(tipo);  \
	}  \
	extern "C" _export void SiguienteBloque(POSITION& pos,int tipo, const char*& clase,const char*& claseBase,const char*& verSerial)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_SiguienteBloque(pos,tipo,clase,claseBase,verSerial);  \
	}  \
	extern "C" _export POSITION PrimerComPos()  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _PrimerComPos();  \
	}  \
	extern "C" _export void SiguienteCom(POSITION& pos,const char*& clase,const char*& claseBase,const char*& verSerial)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_SiguienteCom(pos,clase,claseBase,verSerial);  \
	}  \
	extern "C" _export BOOL BuscarComES(const char* clave,int tipo,const char*& clase,const char*& claseBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _BuscarComES(clave,tipo,clase,claseBloque);  \
	}


#define IMPLEMENTAR_DLLAPI_DIAGRAMA  \
	extern "C" _export BOOL IniciarDLLDiagrama(HINSTANCE hInstance, HWND hwin)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _IniciarDLLDiagrama(hInstance,hwin);  \
	}  \
	extern "C" _export void LiberarDLLDiagrama()  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_LiberarDLLDiagrama();  \
	}



#define IMPLEMENTAR_DLLAPI_BLOQUE  \
	extern "C" _export BOOL Bloque_setNuevo(CBloque * pBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Bloque_setNuevo(pBloque);  \
	}  \
	extern "C" _export BOOL Bloque_IniciarDatosBloque( CBloque * pBloque ) \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Bloque_IniciarDatosBloque(pBloque);  \
	}  \
	extern "C" _export void  Bloque_DefineBloque(CBloque * pBloque, void * bloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_Bloque_DefineBloque(pBloque,bloque);  \
	}  \
	extern "C" _export const char*  Bloque_Accion(CBloque * pBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Bloque_Accion(pBloque);  \
	}  \
	extern "C" _export BOOL  Bloque_Serializar(CBloque * pBloque, LPSTREAM stream, UINT modo)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Bloque_Serializar(pBloque,stream,modo);  \
	}  \
	extern "C" _export void Bloque_DestObjBloqueFunc(CBloque * pBloque, BOOL ObjUsuarioCreado)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_Bloque_DestObjBloqueFunc(pBloque,ObjUsuarioCreado);  \
	}  \
	extern "C" _export void  Bloque_IniciarExplicito(CBloque * pBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_Bloque_IniciarExplicito(pBloque);  \
	}  \
	extern "C" _export void Bloque_EnError(CBloque * pBloque, int TipoError, const char * EtiqPost)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_Bloque_EnError(pBloque,TipoError,EtiqPost);  \
	}  \
	extern "C" _export BOOL Bloque_PropUsuario(CBloque  *pBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Bloque_PropUsuario(pBloque);  \
	}


#define IMPLEMENTAR_DLLAPI_COM  \
	extern "C" _export BYTE* Com_SerializarGuardadoObjCom(CCom * pCom,DWORD& len)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Com_SerializarGuardadoObjCom(pCom,len);  \
	}  \
	extern "C" _export BOOL Com_SerializarCargaObjCom(BYTE* buff,DWORD len,CCom* pCom)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		return _Com_SerializarCargaObjCom(buff,len,pCom);  \
	}  \
	extern "C" _export void Com_DestObjDatosCom( CCom * pECCom )  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( ));  \
		_Com_DestObjDatosCom(pECCom);  \
	}	\
	CComSerial m_comSerialInutil;  \
	NULO m_NULOInutil;

/* La finalidad de m_comSerialInutil y m_NULOInutil es para que se linke la clase
   CComSerial y NULO y se registre el objeto CInfoCom
   Es útil para un DLL de componentes cuando no se han definidos
   bloques (caso de NULO) o que usen la clase de comunicación
   (caso de CComSerial)
*/


// Declaración de objetos de comunicación

#define DECLARAR_COMUNICACION(Clase)  \
	DECLARE_SERIAL(Clase)  \
	static CInfoCom InfoCom##Clase;


#define IMPLEMENTAR_COMUNICACION(Clase,ClaseBase,ver)  \
	IMPLEMENT_SERIAL(Clase, ClaseBase,ver)  \
	extern "C" _export  BOOL  Com_TestObjCom##Clase(); \
	extern "C" _export  CCom* Com_CrearObjCom##Clase(void* pCon); \
	BOOL  Com_TestObjCom##Clase()  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		CCom* pD = new Clase();  delete pD; \
		return true;   \
	}  \
	CCom* Com_CrearObjCom##Clase(void* pCon) \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		CCom* pCom = new Clase(); \
		pCom->DefineConector(pCon); \
		return pCom; \
	} \
	CInfoCom Clase::InfoCom##Clase(#Clase,#ClaseBase,#ver);


// Todos los bloques están preparados para admitir el objeto nulo de comunicaciones en
// entrada y salida, es decir permiten conectarse aunque no comuniquen ningún dato.
// La función CrearBloqueEnDLL##ClaseDerivBloque() además de crear un objeto bloque
// al hacer un cast obliga a que el objeto sea del tipo derivado de CBloque


#define DECLARAR_BLOQUE_BASE(ClaseDerivBloqueBase)   \
    DECLARE_SERIAL(ClaseDerivBloqueBase) \
	DECLARAR_COM_ENTRADA(NULO)  \
	DECLARAR_COM_SALIDA(NULO)   \
 	virtual void EnviarDatosSalida(NULO* pS);  \
  	virtual BOOL RecibirDatosEntrada(const NULO* pE);


#define IMPLEMENTAR_BLOQUE_BASE(ClaseDerivBloqueBase, ClaseBase, ver)  \
    IMPLEMENT_SERIAL(ClaseDerivBloqueBase, ClaseBase, ver) \
	IMPLEMENTAR_COM_ENTRADA(NULO, ClaseDerivBloqueBase)  \
	IMPLEMENTAR_COM_SALIDA(NULO, ClaseDerivBloqueBase)	\
	void ClaseDerivBloqueBase::EnviarDatosSalida(NULO* pS) { }  \
	BOOL ClaseDerivBloqueBase::RecibirDatosEntrada(const NULO* pE) { return true; }  \
	extern "C" _export  CBloque *   CrearBloqueEnDLL##ClaseDerivBloqueBase(); \
	CBloque  *  CrearBloqueEnDLL##ClaseDerivBloqueBase()  \
	{   \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		return new ClaseDerivBloqueBase();  \
	}


// Declaración/Implementación para un bloque de los dos tipos (funcional y retroanotación)
// Si se utiliza como retroanotador la función Accion será ignorada y no es necesario
// implementarse.

#define DECLARAR_BLOQUE(ClaseDerivBloque)   \
    DECLARAR_BLOQUE_BASE(ClaseDerivBloque)  \
	static CInfoBloque InfoBloque##ClaseDerivBloque;


#define IMPLEMENTAR_BLOQUE(ClaseDerivBloque, ClaseBase, ver)  \
    IMPLEMENTAR_BLOQUE_BASE(ClaseDerivBloque, ClaseBase, ver)  \
	CInfoBloque ClaseDerivBloque::InfoBloque##ClaseDerivBloque(#ClaseDerivBloque,#ClaseBase,#ver, 0);


// Declaración/Implementación del objeto derivado de CBloqueFunc 
// TestTipoClase es inútil funcionalmente. Sólo sirve para evitar
// compilarse cuando la clase no deriva del tipo correcto al no poderse hacer el cast


#define DECLARAR_BLOQUE_FUNCIONAL(ClaseDerivBloqueFunc)   \
    DECLARAR_BLOQUE_BASE(ClaseDerivBloqueFunc)  \
 	virtual void TestTipoClase();  \
	static CInfoBloque InfoBloque##ClaseDerivBloqueFunc;


#define IMPLEMENTAR_BLOQUE_FUNCIONAL(ClaseDerivBloqueFunc, ClaseBase, ver)  \
    IMPLEMENTAR_BLOQUE_BASE(ClaseDerivBloqueFunc, ClaseBase, ver)  \
	void ClaseDerivBloqueFunc::TestTipoClase()  \
	{   \
		ClaseDerivBloqueFunc testclase;    \
		CBloqueFunc* ptestclase = &testclase;  \
	} \
	CInfoBloque ClaseDerivBloqueFunc::InfoBloque##ClaseDerivBloqueFunc(#ClaseDerivBloqueFunc,#ClaseBase,#ver, 1);


// Declaración/Implementación del objeto derivado de CBloqueRetro de retroanotación. 
// TestTipoClase es inútil funcionalmente. Sólo sirve para evitar
// compilarse cuando la clase no deriva del tipo correcto al no poderse hacer el cast

#define DECLARAR_BLOQUE_RETROANOTACION(ClaseDerivBloqueRetro)  \
  	DECLARAR_BLOQUE_BASE(ClaseDerivBloqueRetro)  \
 	virtual void TestTipoClase();  \
	static CInfoBloque InfoBloque##ClaseDerivBloqueRetro;


#define IMPLEMENTAR_BLOQUE_RETROANOTACION(ClaseDerivBloqueRetro, ClaseBase, ver)  \
    IMPLEMENTAR_BLOQUE_BASE(ClaseDerivBloqueRetro, ClaseBase, ver)	\
	void ClaseDerivBloqueRetro::TestTipoClase()  \
	{   \
		ClaseDerivBloqueRetro testclase;    \
		CBloqueRetro* ptestclase = &testclase;  \
	}   \
	CInfoBloque ClaseDerivBloqueRetro::InfoBloque##ClaseDerivBloqueRetro(#ClaseDerivBloqueRetro,#ClaseBase,#ver,2);


// La función: TestEntrada (y TestSalida en salida) sirven para comprobar que la clase derivada de  CBloque admite el tipo de
// objeto de comunicación cuyo nombre exacto es especificado en el argumento.
// Esto es necesario porque AceptarDatos##ClaseEntrada se llama en mayúsculas por ser PASCAL por lo que
// la existencia de esta función exportada no confirma con exactitud el nombre de la clase de comunicación que acepta.  
// El hecho de manejar el objeto como CCom obliga a que sea derivado sino no compila.
// Se verifica a su vez que no deriva de CBloque


#define DECLARAR_COM_ENTRADA(ClaseEntrada)  \
	virtual BOOL AceptarDatos##ClaseEntrada(ClaseEntrada* pE);  \
	static CInfoComES InfoComEntrada##ClaseEntrada;   


#define IMPLEMENTAR_COM_ENTRADA(ClaseEntrada, ClaseDerivBloque)  \
	extern "C" _export  BOOL   AceptarDatos##ClaseDerivBloque##ClaseEntrada(CBloque * pBloque,ClaseEntrada * pE);  \
	extern "C" _export  BOOL   TestEntrada##ClaseDerivBloque##ClaseEntrada(CBloque * pBloque);  \
	BOOL  TestEntrada##ClaseDerivBloque##ClaseEntrada(CBloque * pBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		CCom* pD = new ClaseEntrada(); delete pD;  \
		return true;  \
	}  \
	BOOL  AceptarDatos##ClaseDerivBloque##ClaseEntrada(CBloque * pBloque,ClaseEntrada * pE)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		ClaseDerivBloque* pTemp = (ClaseDerivBloque *) pBloque;   \
	 	return pTemp->AceptarDatos##ClaseEntrada( pE );   \
	}	\
	BOOL ClaseDerivBloque::AceptarDatos##ClaseEntrada(ClaseEntrada * pCom)  \
	{  \
		pCom->PrepararParaDevolverDatos();  \
		BOOL res = RecibirDatosEntrada(pCom); \
		pCom->PostDevolverDatos(); \
		return res;  \
	}  \
	CInfoComES ClaseDerivBloque::InfoComEntrada##ClaseEntrada(#ClaseEntrada,#ClaseDerivBloque,0);


	
#define DECLARAR_COM_SALIDA(ClaseSalida)  \
	virtual void DevolverDatos##ClaseSalida(ClaseSalida* pCom);  \
	static CInfoComES InfoComSalida##ClaseSalida;


#define IMPLEMENTAR_COM_SALIDA(ClaseSalida, ClaseDerivBloque)  \
	extern "C" _export  BOOL  TestSalida##ClaseDerivBloque##ClaseSalida(CBloque * pBloque);  \
	extern "C" _export  void  DevolverDatos##ClaseDerivBloque##ClaseSalida(CBloque * pBloque,ClaseSalida* pCom);  \
	BOOL  TestSalida##ClaseDerivBloque##ClaseSalida(CBloque * pBloque)  \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		CCom* pD = new ClaseSalida();  delete pD; \
		return true;   \
	}  \
	void DevolverDatos##ClaseDerivBloque##ClaseSalida(CBloque * pBloque,ClaseSalida* pCom)  \
	{   \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		ClaseDerivBloque* pTemp = (ClaseDerivBloque *) pBloque;  \
	 	pTemp->DevolverDatos##ClaseSalida( pCom );   \
	}	\
	void ClaseDerivBloque::DevolverDatos##ClaseSalida(ClaseSalida* pCom)  \
	{   \
		pCom->PrepararParaRecibirDatos();  \
		EnviarDatosSalida( pCom );   \
		pCom->PostRecibirDatos(); \
	}	\
	CInfoComES ClaseDerivBloque::InfoComSalida##ClaseSalida(#ClaseSalida,#ClaseDerivBloque,1);


// BORRAR O REFORMAR CON OTRA FINALIDAD (añadir << y >> , pensar en serialización automática etc)



// Macro de comunicación segura de datos.
// El operador -> sólo es correcto a nivel lógico si TipoVar es un puntero.


#define DECLARAR_VARIABLE_COM(NombreVar, TipoVar)  \
	class ClaseVarCom_##NombreVar  \
	{   \
	public: \
		ClaseVarCom_##NombreVar();  \
		TipoVar operator = (TipoVar valor)  { return (VarInterna = valor); }   \
		TipoVar  GetValor ()  { return  *(GetValorPtr()); };   \
  		operator TipoVar  ()  { return  *(GetValorPtr()); };  \
  		operator TipoVar * ()  { return (TipoVar *)GetValorPtr(); };  \
   		operator void* () { return (void*)GetValorPtr(); };  \
		TipoVar * GetValorPtr();  \
	private:	\
		TipoVar VarInterna; \
	}


#define IMPLEMENTAR_VARIABLE_COM(ClaseCom, TipoVar, NombreVar)  \
	ClaseCom::ClaseVarCom_##NombreVar::ClaseVarCom_##NombreVar() \
	{  \
	}  \
	TipoVar * ClaseCom::ClaseVarCom_##NombreVar::GetValorPtr() \
	{   \
		return &VarInterna;   \
	}  \
	void operator >> (CArchive& ar, ClaseCom::ClaseVarCom_##NombreVar & d) \
	{   \
		ar >> (*d.GetValorPtr());  \
	}   \
	void operator << (CArchive& ar, ClaseCom::ClaseVarCom_##NombreVar & d) \
	{   \
		ar << (*d.GetValorPtr());  \
	}

// Macros para comunicar datos entre DLLs pero a través de variables simples (int, double, const char* etc)
// sin necesidad de punteros. 


#define DECLARAR_FUNCION_COM(NombreVar, TipoVar, NombreFunc)  \
	virtual void Set##NombreFunc(TipoVar valor);  \
	virtual TipoVar Get##NombreFunc();  \
	class ClaseFuncCom_##NombreFunc  \
	{   \
	public: \
		ClaseFuncCom_##NombreFunc();  \
	private:	\
	} ##NombreVar##NombreFunc;



#define IMPLEMENTAR_FUNCION_COM(ClaseCom, NombreVar, TipoVar, NombreFunc)  \
	void ClaseCom::Set##NombreFunc(TipoVar valor)  \
	{   \
		NombreVar = valor; \
	}   \
	TipoVar ClaseCom::Get##NombreFunc()  \
	{   \
		return NombreVar; \
	}   \
	ClaseCom::ClaseFuncCom_##NombreFunc::ClaseFuncCom_##NombreFunc() \
	{  \
	}  \
	extern "C" _export int  TestSizeTipoVariable##ClaseCom##NombreVar(); \
	int  TestSizeTipoVariable##ClaseCom##NombreVar() \
	{  \
		AFX_MANAGE_STATE(AfxGetStaticModuleState( )); \
		return sizeof(TipoVar);  \
	}



#endif
  	
