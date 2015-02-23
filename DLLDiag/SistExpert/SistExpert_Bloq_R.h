class SistExpert_Bloq_R : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(SistExpert_Bloq_R) 

	// Declaración de clases de comunicación de Entrada : 
	DECLARAR_COM_ENTRADA(SistExpert_Com_Ley_R) 
	virtual  BOOL RecibirDatosEntrada(SistExpert_Com_Ley_R* pE); 
	DECLARAR_COM_ENTRADA(CtrlAdap_Com_Var) 
	virtual  BOOL RecibirDatosEntrada(CtrlAdap_Com_Var* pE); 

	// Declaración de clases de comunicación de Salida : 
	DECLARAR_COM_SALIDA(CtrlAdap_Com_Var) 
	virtual  void EnviarDatosSalida(CtrlAdap_Com_Var* pS); 

	// Funciones estándar a implementar
	virtual void IniciarDatos(); 
	virtual BOOL NuevosObjDatos(); 
	virtual void DestObjDatos(); 
	virtual void GuardarFichero(CArchive& ar); 
	virtual void LeerFichero(CArchive& ar); 
	virtual CString Accion(); 
	virtual BOOL PropiedadesBloque(); 

private:
	double e;
	double du;
	double Kr; // Ganancia del regulador
	double T;

	BOOL Ajustar;
}; 

