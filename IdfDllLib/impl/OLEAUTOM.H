// oleautom.h 
//

#ifndef OLEAUTOM_H
#define OLEAUTOM_H


#define DECPARAM(n)  const COleVariantExt param##n

#define NDECPARAMS_1                  DECPARAM(1)
#define NDECPARAMS_2   NDECPARAMS_1,  DECPARAM(2)
#define NDECPARAMS_3   NDECPARAMS_2,  DECPARAM(3)
#define NDECPARAMS_4   NDECPARAMS_3,  DECPARAM(4)
#define NDECPARAMS_5   NDECPARAMS_4,  DECPARAM(5)
#define NDECPARAMS_6   NDECPARAMS_5,  DECPARAM(6)
#define NDECPARAMS_7   NDECPARAMS_6,  DECPARAM(7)
#define NDECPARAMS_8   NDECPARAMS_7,  DECPARAM(8)        
#define NDECPARAMS_9   NDECPARAMS_8,  DECPARAM(9)
#define NDECPARAMS_10  NDECPARAMS_9,  DECPARAM(10)
#define NDECPARAMS_11  NDECPARAMS_10, DECPARAM(11)
#define NDECPARAMS_12  NDECPARAMS_11, DECPARAM(12)
#define NDECPARAMS_13  NDECPARAMS_12, DECPARAM(13)
#define NDECPARAMS_14  NDECPARAMS_13, DECPARAM(14)
#define NDECPARAMS_15  NDECPARAMS_14, DECPARAM(15)


#define PASOARG(n)  param##n

#define NPASOARG_1                PASOARG(1)
#define NPASOARG_2   NPASOARG_1,  PASOARG(2)
#define NPASOARG_3   NPASOARG_2,  PASOARG(3)
#define NPASOARG_4   NPASOARG_3,  PASOARG(4)
#define NPASOARG_5   NPASOARG_4,  PASOARG(5)
#define NPASOARG_6   NPASOARG_5,  PASOARG(6)
#define NPASOARG_7   NPASOARG_6,  PASOARG(7)
#define NPASOARG_8   NPASOARG_7,  PASOARG(8)
#define NPASOARG_9   NPASOARG_8,  PASOARG(9)
#define NPASOARG_10  NPASOARG_9,  PASOARG(10)
#define NPASOARG_11  NPASOARG_10, PASOARG(11)
#define NPASOARG_12  NPASOARG_11, PASOARG(12)
#define NPASOARG_13  NPASOARG_12, PASOARG(13)
#define NPASOARG_14  NPASOARG_13, PASOARG(14)
#define NPASOARG_15  NPASOARG_14, PASOARG(15)


#define PASOCASTARG(n)  (VARIANT*)&(VARIANT)param##n

#define NPASOCASTARG_1                    PASOCASTARG(1)
#define NPASOCASTARG_2   NPASOCASTARG_1,  PASOCASTARG(2)
#define NPASOCASTARG_3   NPASOCASTARG_2,  PASOCASTARG(3)
#define NPASOCASTARG_4   NPASOCASTARG_3,  PASOCASTARG(4)
#define NPASOCASTARG_5   NPASOCASTARG_4,  PASOCASTARG(5)
#define NPASOCASTARG_6   NPASOCASTARG_5,  PASOCASTARG(6)
#define NPASOCASTARG_7   NPASOCASTARG_6,  PASOCASTARG(7)
#define NPASOCASTARG_8   NPASOCASTARG_7,  PASOCASTARG(8)
#define NPASOCASTARG_9   NPASOCASTARG_8,  PASOCASTARG(9)
#define NPASOCASTARG_10  NPASOCASTARG_9,  PASOCASTARG(10)
#define NPASOCASTARG_11  NPASOCASTARG_10, PASOCASTARG(11)
#define NPASOCASTARG_12  NPASOCASTARG_11, PASOCASTARG(12)
#define NPASOCASTARG_13  NPASOCASTARG_12, PASOCASTARG(13)
#define NPASOCASTARG_14  NPASOCASTARG_13, PASOCASTARG(14)
#define NPASOCASTARG_15  NPASOCASTARG_14, PASOCASTARG(15)



#define NVARVARIANT_1                   VTS_VARIANT
#define NVARVARIANT_2   NVARVARIANT_1   VTS_VARIANT
#define NVARVARIANT_3   NVARVARIANT_2   VTS_VARIANT
#define NVARVARIANT_4   NVARVARIANT_3   VTS_VARIANT
#define NVARVARIANT_5   NVARVARIANT_4   VTS_VARIANT
#define NVARVARIANT_6   NVARVARIANT_5   VTS_VARIANT
#define NVARVARIANT_7   NVARVARIANT_6   VTS_VARIANT
#define NVARVARIANT_8   NVARVARIANT_7   VTS_VARIANT
#define NVARVARIANT_9   NVARVARIANT_8   VTS_VARIANT
#define NVARVARIANT_10  NVARVARIANT_9   VTS_VARIANT
#define NVARVARIANT_11  NVARVARIANT_10  VTS_VARIANT
#define NVARVARIANT_12  NVARVARIANT_11  VTS_VARIANT
#define NVARVARIANT_13  NVARVARIANT_12  VTS_VARIANT
#define NVARVARIANT_14  NVARVARIANT_13  VTS_VARIANT
#define NVARVARIANT_15  NVARVARIANT_14  VTS_VARIANT


#define Declara_Func(n)  virtual COleVariantExt& Func(char * nombre, NDECPARAMS_##n );

#define Implementa_Func(n)  \
COleVariantExt& COleAutomation::Func(char * nombre, NDECPARAMS_##n )  \
{  \
	PasoParamComun(nombre,VT_VARIANT, NPASOARG_##n); \
	return result;  \
}


#define Declara_Proc(n)  virtual void Proc(char * nombre, NDECPARAMS_##n );

#define Implementa_Proc(n) \
void COleAutomation::Proc(char * nombre, NDECPARAMS_##n )  \
{  \
	PasoParamComun(nombre,VT_EMPTY, NPASOARG_##n);  \
}


#define Declara_PasoParamComun(n)   virtual void PasoParamComun(char * nombre,const VARTYPE& tiposalida, NDECPARAMS_##n );

#define Implementa_PasoParamComun(n)  \
void COleAutomation::PasoParamComun(char * nombre,const VARTYPE& tiposalida, NDECPARAMS_##n ) \
{  \
	AfxGetApp()->DoWaitCursor(1);  \
	ProcesoComun(nombre,tiposalida);  \
	static BYTE BASED_CODE parms[] = NVARVARIANT_##n;  \
	InvokeHelper(dispid, DISPATCH_METHOD, result.vt, (void*)(VARIANT*)&result, parms, NPASOCASTARG_##n);  \
	AfxGetApp()->DoWaitCursor(-1);  \
} 



/////////////////////////////////////////////////////////////////////////////
// COleAutomation 

class COleVariantExt;

class COleAutomation : public COleDispatchDriver
{   

private:  // De uso interno.
	virtual void ProcesoComun(char * nombre,const VARTYPE& tiposalida);

	virtual void PasoParamComun(char * nombre,const VARTYPE& tiposalida);

	Declara_PasoParamComun(1)
	Declara_PasoParamComun(2)
	Declara_PasoParamComun(3)
	Declara_PasoParamComun(4)
	Declara_PasoParamComun(5)
	Declara_PasoParamComun(6)
	Declara_PasoParamComun(7)
	Declara_PasoParamComun(8)
	Declara_PasoParamComun(9)
	Declara_PasoParamComun(10)
	Declara_PasoParamComun(11)
	Declara_PasoParamComun(12)
	Declara_PasoParamComun(13)
	Declara_PasoParamComun(14)
	Declara_PasoParamComun(15)

public:
	COleAutomation();		
	virtual ~COleAutomation();
	
	virtual COleVariantExt& LiberarResult();	// Libera result y devuelve una referencia.
	virtual HRESULT getIDdelNombre(char * nombre, DISPID& dispid);	

	virtual void DefPropiedad(char * nombre,const COleVariantExt& var);  // Paralela a SetProperty
	virtual COleVariantExt&  getPropiedad(char * nombre);  // Paralela a GetProperty	
	
	virtual COleVariantExt& Func(char * nombre);

	Declara_Func(1)
	Declara_Func(2)
	Declara_Func(3)
	Declara_Func(4)
	Declara_Func(5)
	Declara_Func(6)
	Declara_Func(7)
	Declara_Func(8)
	Declara_Func(9)
	Declara_Func(10)
	Declara_Func(11)
	Declara_Func(12)
	Declara_Func(13)
	Declara_Func(14)
	Declara_Func(15)

	virtual void  Proc(char * nombre);

	Declara_Proc(1)
	Declara_Proc(2)
	Declara_Proc(3)
	Declara_Proc(4)
	Declara_Proc(5)
	Declara_Proc(6)
	Declara_Proc(7)
	Declara_Proc(8)
	Declara_Proc(9)
	Declara_Proc(10)
	Declara_Proc(11)
	Declara_Proc(12)
	Declara_Proc(13)
	Declara_Proc(14)
	Declara_Proc(15)

private:
	DISPID dispid;  // Se pone común para minimizar el tamaño del código y el paso de parámetros.
	
public:
	CString FuncUltima;  // Memoriza el nombre de la función última ejecutada. Sólo para ver que función, procedimiento o propiedad que falló ante una aserción.
	COleVariantExt result;  // Puede accederse para definir el tipo de resultado (por ejemplo) en vt ej. Obj.DefResult().vt = símbolo de VARTYPE (ej. VT_EMPTY)

};

/////////////////////////////////////////////////////////////////////////////

#endif

