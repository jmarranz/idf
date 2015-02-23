
// Ciemat.h



// Clases de comunicación entre bloques: 

class ParamIrradExt : public CCom
{ 
public: 
	DECLARAR_COMUNICACION(ParamIrradExt) 

	ParamIrradExt();
	ParamIrradExt& ParamIrradExt::operator=(const ParamIrradExt& param);

	// Se llaman cuando es objeto de bloque
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 

 	 // Variables exportadas: 
	DECLARAR_VARIABLE_COM(Ca, double)		Ca;
	DECLARAR_VARIABLE_COM(Cw, double)		Cw;
	DECLARAR_VARIABLE_COM(Cso, double)		Cso;
	DECLARAR_VARIABLE_COM(L,double)			L;
	DECLARAR_VARIABLE_COM(DFinm_b,double)	DFinm_b;
	DECLARAR_VARIABLE_COM(DFinm_g,double)	DFinm_g;
	DECLARAR_VARIABLE_COM(DFaire_b,double)	DFaire_b;
	DECLARAR_VARIABLE_COM(DFaire_g,double)	DFaire_g;
	DECLARAR_VARIABLE_COM(DFgr_b,double)	DFgr_b;
	DECLARAR_VARIABLE_COM(DFgr_g,double)	DFgr_g;
	DECLARAR_VARIABLE_COM(tb,double)		tb;
	DECLARAR_VARIABLE_COM(Fb_b,double)		Fb_b;
	DECLARAR_VARIABLE_COM(Fb_g,double)		Fb_g;
	DECLARAR_VARIABLE_COM(Ofinm,double)		Ofinm;
	DECLARAR_VARIABLE_COM(Ofaire_ext,double)	Ofaire_ext;
	DECLARAR_VARIABLE_COM(Ofaire_int,double)	Ofaire_int;
	DECLARAR_VARIABLE_COM(Oforilla,double)	Oforilla;
	DECLARAR_VARIABLE_COM(Wpiel,double)		Wpiel;
	DECLARAR_VARIABLE_COM(d,double)			d;

 	 // Funciones exportadas de acceso a variables internas: 


}; 


class ResIrradExt : public CCom
{ 
public: 
	DECLARAR_COMUNICACION(ResIrradExt) 

	ResIrradExt();

	ResIrradExt& operator=(const ResIrradExt& entrada);
	BOOL SetValor(const CString& NombreVar,double valor);

	// Se llaman cuando es objeto de bloque
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 

 	 // Variables exportadas: 
	DECLARAR_VARIABLE_COM(Eext_aire, double) Eext_aire;
	DECLARAR_VARIABLE_COM(Eext_suelo, double) Eext_suelo;
	DECLARAR_VARIABLE_COM(Eext_inm_fondo, double) Eext_inm_fondo;
	DECLARAR_VARIABLE_COM(Eext_inm_susp, double) Eext_inm_susp;
	DECLARAR_VARIABLE_COM(Eext_inm_w, double) Eext_inm_w;
	DECLARAR_VARIABLE_COM(Eext_inm_total, double) Eext_inm_total;
	DECLARAR_VARIABLE_COM(Eext_orilla, double) Eext_orilla;

 	 // Funciones exportadas de acceso a variables internas: 

}; 


// Clases de Bloques Funcionales/Retroanotación: 

// Clases de Bloques Funcionales: 
class BloqueCondicionSINO : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueCondicionSINO) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ResIrradExt ResBloque;

}; 

class BloqueIrradExt_inm_fondo_susp : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueIrradExt_inm_fondo_susp) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ParamIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ParamIrradExt* pE); 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 


	// Variables internas no exportadas
private:
	ParamIrradExt ParamBloque;
	ResIrradExt ResBloque;

	double	Ssedim;
	double	Csedim_fondo;
	double	Csedim_susp;
}; 

class BloqueResIrradExterna : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueResIrradExterna) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ResIrradExt ResBloque;
}; 

class BloqueIrradNula : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueIrradNula) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ResIrradExt ResBloque;
	CString NombreVar;

}; 

class BloqueIrradExt_orilla : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueIrradExt_orilla) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ParamIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ParamIrradExt* pE); 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ParamIrradExt ParamBloque;
	ResIrradExt ResBloque;

}; 

class BloqueIrradExt_suelo : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueIrradExt_suelo) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 
	DECLARAR_COM_ENTRADA(ParamIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ParamIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ParamIrradExt ParamBloque;
	ResIrradExt ResBloque;
}; 

class BloqueEntradaParamIrradExt : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueEntradaParamIrradExt) 

	// Declaración de clases de comunicación de Entrada : 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ParamIrradExt) 
	virtual  void EnviarDatosSalida(ParamIrradExt* pS); 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ParamIrradExt ParamBloque;
	ResIrradExt ResBloque;
}; 


class BloqueIrradExt_inm_total : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueIrradExt_inm_total) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 
	DECLARAR_COM_ENTRADA(ParamIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ParamIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ParamIrradExt ParamBloque;
	ResIrradExt ResBloque;
}; 

class BloqueIrradExt_aire : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(BloqueIrradExt_aire) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ParamIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ParamIrradExt* pE); 
	DECLARAR_COM_ENTRADA(ResIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ResIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ResIrradExt) 
	virtual  void EnviarDatosSalida(ResIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

	// Variables internas no exportadas
private:
	ParamIrradExt ParamBloque;
	ResIrradExt ResBloque;
}; 


// Clases de Bloques de Retroanotación: 
class BloqueRetroDatosIrradExt : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(BloqueRetroDatosIrradExt) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(ParamIrradExt) 
	virtual  BOOL RecibirDatosEntrada(const ParamIrradExt* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(ParamIrradExt) 
	virtual  void EnviarDatosSalida(ParamIrradExt* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual BOOL PropiedadesBloque(); 

	// Variables:
private:
	ParamIrradExt ParamBloque;
}; 

