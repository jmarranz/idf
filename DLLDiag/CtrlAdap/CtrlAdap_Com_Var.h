
class CtrlAdap_Com_Var : public CCom
{ 
public: 
	DECLARAR_COMUNICACION(CtrlAdap_Com_Var) 

 	 // Variables exportadas: 
  	DECLARAR_VARIABLE_COM(Var,double) Var;
  	DECLARAR_VARIABLE_COM(T,double) T;

	// Funciones exportadas de acceso a variables internas: 
}; 

