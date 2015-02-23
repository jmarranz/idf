class CtrlAdap_Bloq_Inversor : public CBloqueRetro
{ 
public: 
	DECLARAR_BLOQUE_RETROANOTACION(CtrlAdap_Bloq_Inversor) 

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
	virtual BOOL PropiedadesBloque(); 

private:
	double Var;
	double T;
}; 

