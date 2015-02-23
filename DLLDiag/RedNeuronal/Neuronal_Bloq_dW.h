class Neuronal_Bloq_dW : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(Neuronal_Bloq_dW) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(Neuronal_Com_Dato) 
	virtual  BOOL RecibirDatosEntrada(Neuronal_Com_Dato* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(Neuronal_Com_Dato) 
	virtual  void EnviarDatosSalida(Neuronal_Com_Dato* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	// virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

protected:
	double m_Alfa;
	double m_dg;
	CMap<CString,const char*,double,double&> m_Err;
	double m_W;
	double m_A;
}; 

