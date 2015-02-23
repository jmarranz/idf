class CtrlAdap_Bloq_x : public CBloqueFunc
{ 
public: 
	DECLARAR_BLOQUE_FUNCIONAL(CtrlAdap_Bloq_x) 

	// Declaración de clases de comunicación de Entrada : 

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
	double x;
	double T;
	int K;
}; 

