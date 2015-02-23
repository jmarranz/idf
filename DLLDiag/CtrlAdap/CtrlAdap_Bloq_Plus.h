class CtrlAdap_Bloq_Plus : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_Plus) 

	// Declaraci�n de clases de comunicaci�n de Entrada : 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaraci�n de clases de comunicaci�n de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Var) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Var* pS); 

	// Funciones est�ndar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

private:
	double X;
	double Yn;  // -Y
	double T;

	double E;
}; 

