
// Ciemat.cpp


#include "stdafx.h"
#include "..\DLLDiag.h"

#include <math.h>



#include "Ciemat.h"

#include "DlgParamEntradaIrradExt.h"
#include "DlgResIrradExterna.h"
#include "DlgMostrarE.h"
#include "DlgMostrar2E.h"
#include "DlgSedimentacion.h"


// Clases de comunicación entre bloques: 

IMPLEMENTAR_COMUNICACION(ParamIrradExt,CCom,1) 

IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Ca)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Cw)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Cso)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,L)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,DFinm_b)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,DFinm_g)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,DFaire_b)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,DFaire_g)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,DFgr_b)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,DFgr_g)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,tb)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Fb_b)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Fb_g)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Ofinm)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Ofaire_ext)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Ofaire_int)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Oforilla)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,Wpiel)
IMPLEMENTAR_VARIABLE_COM(ParamIrradExt,double,d)


ParamIrradExt::ParamIrradExt()
{
	Ca = 0;
	Cw = 0;
	Cso = 0;
	L = 0;
	DFinm_b = 0;
	DFinm_g = 0;
	DFaire_b = 0;
	DFaire_g = 0;
	DFgr_b = 0;
	DFgr_g = 0;
	tb = 0;
	Fb_b = 0;
	Fb_g = 0;
	Ofinm = 0;
	Ofaire_ext = 0;
	Ofaire_int = 0;
	Oforilla = 0;
	Wpiel = 0;
	d = 0;
}


ParamIrradExt& ParamIrradExt::operator=(const ParamIrradExt& param)
{
	Ca = param.Ca;
	Cw = param.Cw;
	Cso = param.Cso;
	L = param.L;
	DFinm_b = param.DFinm_b;
	DFinm_g = param.DFinm_g;
	DFaire_b = param.DFaire_b;
	DFaire_g = param.DFaire_g;
	DFgr_b = param.DFgr_b;
	DFgr_g = param.DFgr_g;
	tb = param.tb;
	Fb_b = param.Fb_b;
	Fb_g = param.Fb_g;
	Ofinm = param.Ofinm;
	Ofaire_ext = param.Ofaire_ext;
	Ofaire_int = param.Ofaire_int;
	Oforilla = param.Oforilla;
	Wpiel = param.Wpiel;
	d = param.d;

	return *this;
}


void ParamIrradExt::GuardarFichero(CArchive& ar)
{
	ar << (double)Ca;
	ar << (double)Cw;
	ar << (double)Cso;
	ar << (double)L;
	ar << (double)DFinm_b;
	ar << (double)DFinm_g;
	ar << (double)DFaire_b;
	ar << (double)DFaire_g;
	ar << (double)DFgr_b;
	ar << (double)DFgr_g;
	ar << (double)tb;
	ar << (double)Fb_b;
	ar << (double)Fb_g;
	ar << (double)Ofinm;
	ar << (double)Ofaire_ext;
	ar << (double)Ofaire_int;
	ar << (double)Oforilla;
	ar << (double)Wpiel;
	ar << (double)d;
}

void ParamIrradExt::LeerFichero(CArchive& ar)
{
	ar >> (double&)Ca;
	ar >> (double&)Cw;
	ar >> (double&)Cso;
	ar >> (double&)L;
	ar >> (double&)DFinm_b;
	ar >> (double&)DFinm_g;
	ar >> (double&)DFaire_b;
	ar >> (double&)DFaire_g;
	ar >> (double&)DFgr_b;
	ar >> (double&)DFgr_g;
	ar >> (double&)tb;
	ar >> (double&)Fb_b;
	ar >> (double&)Fb_g;
	ar >> (double&)Ofinm;
	ar >> (double&)Ofaire_ext;
	ar >> (double&)Ofaire_int;
	ar >> (double&)Oforilla;
	ar >> (double&)Wpiel;
	ar >> (double&)d;
}


IMPLEMENTAR_COMUNICACION(ResIrradExt,CCom,1) 

IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_aire)
IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_suelo)
IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_inm_fondo)
IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_inm_susp)
IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_inm_w)
IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_inm_total)
IMPLEMENTAR_VARIABLE_COM(ResIrradExt, double, Eext_orilla)

ResIrradExt::ResIrradExt()
{
	Eext_aire = 0;
	Eext_suelo = 0;
	Eext_inm_fondo = 0;
	Eext_inm_susp = 0;
	Eext_inm_w = 0;
	Eext_inm_total = 0;
	Eext_orilla = 0;
}


ResIrradExt& ResIrradExt::operator=(const ResIrradExt& entrada)
{
	Eext_aire = entrada.Eext_aire;
	Eext_suelo = entrada.Eext_suelo;
	Eext_inm_fondo = entrada.Eext_inm_fondo;
	Eext_inm_susp = entrada.Eext_inm_susp;
	Eext_inm_w = entrada.Eext_inm_w;
	Eext_inm_total = entrada.Eext_inm_total;
	Eext_orilla = entrada.Eext_orilla;

	return *this;
}

BOOL ResIrradExt::SetValor(const CString& NombreVar,double valor)
{
	if (NombreVar == "Eext_aire")		{ Eext_aire = valor; return true; }
	if (NombreVar == "Eext_suelo")		{ Eext_suelo = valor; return true; }
	if (NombreVar == "Eext_inm_fondo")	{ Eext_inm_fondo = valor; return true; }
	if (NombreVar == "Eext_inm_susp")	{ Eext_inm_susp = valor; return true; }
	if (NombreVar == "Eext_inm_w")		{ Eext_inm_w = valor; return true; }
	if (NombreVar == "Eext_inm_total")	{ Eext_inm_total = valor; return true; }
	if (NombreVar == "Eext_orilla")		{ Eext_orilla = valor; return true; }

	return false;
}

void ResIrradExt::GuardarFichero(CArchive& ar)
{
	ar << (double)Eext_aire;
	ar << (double)Eext_suelo;
	ar << (double)Eext_inm_fondo;
	ar << (double)Eext_inm_susp;
	ar << (double)Eext_inm_w;
	ar << (double)Eext_inm_total;
	ar << (double)Eext_orilla;
}

void ResIrradExt::LeerFichero(CArchive& ar)
{
	ar >> (double&)Eext_aire;
	ar >> (double&)Eext_suelo;
	ar >> (double&)Eext_inm_fondo;
	ar >> (double&)Eext_inm_susp;
	ar >> (double&)Eext_inm_w;
	ar >> (double&)Eext_inm_total;
	ar >> (double&)Eext_orilla;
}


// Clases de Bloques Funcionales/Retroanotación: 

// Clases de Bloques Funcionales: 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueCondicionSINO,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueCondicionSINO
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueCondicionSINO) 
BOOL BloqueCondicionSINO::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueCondicionSINO
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueCondicionSINO) 
void BloqueCondicionSINO::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque;
} 

void BloqueCondicionSINO::IniciarDatos() 
{ 
	CambiaEstado(CORRECTO);  
} 
BOOL BloqueCondicionSINO::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueCondicionSINO::DestObjDatos() 
{ 
 
} 
void BloqueCondicionSINO::GuardarFichero(CArchive& ar) 
{ 
	ResBloque.GuardarFichero(ar);
} 

void BloqueCondicionSINO::LeerFichero(CArchive& ar) 
{ 
	ResBloque.LeerFichero(ar); 
} 

CString BloqueCondicionSINO::Accion() 
{ 
	if (Confirmar(getEtiqueta())) return "SI";
	return "NO"; 
} 

BOOL BloqueCondicionSINO::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueIrradExt_inm_fondo_susp,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueIrradExt_inm_fondo_susp
IMPLEMENTAR_COM_ENTRADA(ParamIrradExt,BloqueIrradExt_inm_fondo_susp) 
BOOL BloqueIrradExt_inm_fondo_susp::RecibirDatosEntrada(const ParamIrradExt* pE) 
{ 
	ParamBloque = *pE;
	CambiaEstado(CORRECTO);  
	return true;
} 
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueIrradExt_inm_fondo_susp) 
BOOL BloqueIrradExt_inm_fondo_susp::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueIrradExt_inm_fondo_susp
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueIrradExt_inm_fondo_susp) 
void BloqueIrradExt_inm_fondo_susp::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque; 
} 

void BloqueIrradExt_inm_fondo_susp::IniciarDatos() 
{ 
	Ssedim = 0;
	Csedim_fondo = 0;
	Csedim_susp = 0;
} 
BOOL BloqueIrradExt_inm_fondo_susp::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueIrradExt_inm_fondo_susp::DestObjDatos() 
{ 
 
} 
void BloqueIrradExt_inm_fondo_susp::GuardarFichero(CArchive& ar) 
{ 
	ParamBloque.GuardarFichero(ar);
	ResBloque.GuardarFichero(ar); 
	ar << Ssedim;
	ar << Csedim_fondo;
	ar << Csedim_susp;
} 
void BloqueIrradExt_inm_fondo_susp::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
	ResBloque.LeerFichero(ar); 
	ar >> Ssedim;
	ar >> Csedim_fondo;
	ar >> Csedim_susp;
} 
CString BloqueIrradExt_inm_fondo_susp::Accion() 
{ 
	DlgSedimentacion dlgsed(getMainWnd());

	dlgsed.m_Ssedim = Ssedim;
	dlgsed.m_Csedim_fondo = Csedim_fondo;
	dlgsed.m_Csedim_susp = Csedim_susp;

	if (dlgsed.DoModal() == IDOK)
	{
		Ssedim = dlgsed.m_Ssedim;
		Csedim_fondo = dlgsed.m_Csedim_fondo;
		Csedim_susp = dlgsed.m_Csedim_susp;
	}
	
	ParamIrradExt& p = ParamBloque; // Simplemente para que el nombre de la variable se a más corto.
	ResBloque.Eext_inm_fondo = 60*Csedim_fondo*p.DFgr_g*p.Ofinm;
	ResBloque.Eext_inm_susp =  Ssedim*Csedim_susp*p.Ofinm;
	
	DlgMostrar2E dlg(getMainWnd());

	dlg.m_Etiq_E = "E ext,inm,fondo : ";
	dlg.m_Etiq_E2 = "E ext,inm,suspensión : ";
	dlg.m_Valor_E = ResBloque.Eext_inm_fondo;
	dlg.m_Valor_E2 = ResBloque.Eext_inm_susp;

	if (dlg.DoModal() == IDOK)
	{
		ResBloque.Eext_inm_fondo = dlg.m_Valor_E;
		ResBloque.Eext_inm_susp = dlg.m_Valor_E2;
	}
	return ""; 
} 
BOOL BloqueIrradExt_inm_fondo_susp::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueResIrradExterna,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueResIrradExterna
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueResIrradExterna) 
BOOL BloqueResIrradExterna::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	CambiaEstado(CORRECTO);	
	ResBloque = *pE;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueResIrradExterna

void BloqueResIrradExterna::IniciarDatos() 
{ 

} 
BOOL BloqueResIrradExterna::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueResIrradExterna::DestObjDatos() 
{ 
 
} 
void BloqueResIrradExterna::GuardarFichero(CArchive& ar) 
{ 
	ResBloque.GuardarFichero(ar);
} 
void BloqueResIrradExterna::LeerFichero(CArchive& ar) 
{ 
	ResBloque.LeerFichero(ar); 
} 
CString BloqueResIrradExterna::Accion() 
{ 
	DlgResIrradExterna dlg(getMainWnd());

	dlg.m_Eext_aire = ResBloque.Eext_aire;
	dlg.m_Eext_suelo = ResBloque.Eext_suelo;
	dlg.m_Eext_inm_total = ResBloque.Eext_inm_total;
	dlg.m_Eext_orilla = ResBloque.Eext_orilla;
	
	if (dlg.DoModal() == IDOK)
	{
		ResBloque.Eext_aire = dlg.m_Eext_aire;
		ResBloque.Eext_suelo = dlg.m_Eext_suelo;
		ResBloque.Eext_inm_total = dlg.m_Eext_inm_total;
		ResBloque.Eext_orilla = dlg.m_Eext_orilla;
	}

	return ""; 
} 
BOOL BloqueResIrradExterna::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueIrradNula,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueIrradNula
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueIrradNula) 
BOOL BloqueIrradNula::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueIrradNula
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueIrradNula) 
void BloqueIrradNula::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque; 
} 

void BloqueIrradNula::IniciarDatos() 
{ 
	NombreVar = getMacro();
	// Le quitamos el retorno de carro si hubiera
	NombreVar = NombreVar.SpanExcluding("\r");
	CambiaEstado(CORRECTO);  
} 
BOOL BloqueIrradNula::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueIrradNula::DestObjDatos() 
{ 
 
} 
void BloqueIrradNula::GuardarFichero(CArchive& ar) 
{ 
	ResBloque.GuardarFichero(ar);
} 

void BloqueIrradNula::LeerFichero(CArchive& ar) 
{ 
	ResBloque.LeerFichero(ar); 
	// const char* ftemp = tmpnam(NULL);
	NombreVar = getMacro();
	NombreVar = NombreVar.SpanExcluding("\r");
} 

CString BloqueIrradNula::Accion() 
{ 
	if (!ResBloque.SetValor(NombreVar,0))
	{
		Mensaje("No está bien configurado: ver el campo Macro en Propiedades del bloque, corregir e iniciar explícitamente el diagrama");
	}
	return ""; 
} 
BOOL BloqueIrradNula::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueIrradExt_orilla,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueIrradExt_orilla
IMPLEMENTAR_COM_ENTRADA(ParamIrradExt,BloqueIrradExt_orilla) 
BOOL BloqueIrradExt_orilla::RecibirDatosEntrada(const ParamIrradExt* pE) 
{ 
	ParamBloque = *pE;
	CambiaEstado(CORRECTO);  
	return true;
} 
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueIrradExt_orilla) 
BOOL BloqueIrradExt_orilla::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueIrradExt_orilla
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueIrradExt_orilla) 
void BloqueIrradExt_orilla::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque; 
} 

void BloqueIrradExt_orilla::IniciarDatos() 
{ 

} 
BOOL BloqueIrradExt_orilla::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueIrradExt_orilla::DestObjDatos() 
{ 
 
} 
void BloqueIrradExt_orilla::GuardarFichero(CArchive& ar) 
{ 
 	ParamBloque.GuardarFichero(ar);
	ResBloque.GuardarFichero(ar);
} 
void BloqueIrradExt_orilla::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
	ResBloque.LeerFichero(ar); 
} 
CString BloqueIrradExt_orilla::Accion() 
{ 
	ParamIrradExt& p = ParamBloque; // Simplemente para que el nombre de la variable se a más corto.
	ResBloque.Eext_orilla = 60*p.Cso *(p.DFgr_g + p.Wpiel*p.DFgr_b)*p.Oforilla;
	
	DlgMostrarE dlg(getMainWnd());

	dlg.m_Etiq_E = "E ext,orilla : ";
	dlg.m_Valor_E = ResBloque.Eext_orilla;

	if (dlg.DoModal() == IDOK)
	{
		ResBloque.Eext_orilla = dlg.m_Valor_E;
	}

	return ""; 
} 
BOOL BloqueIrradExt_orilla::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueIrradExt_suelo,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueIrradExt_suelo
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueIrradExt_suelo) 
BOOL BloqueIrradExt_suelo::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 
IMPLEMENTAR_COM_ENTRADA(ParamIrradExt,BloqueIrradExt_suelo) 
BOOL BloqueIrradExt_suelo::RecibirDatosEntrada(const ParamIrradExt* pE) 
{ 
	ParamBloque = *pE;
	CambiaEstado(CORRECTO);  
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueIrradExt_suelo
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueIrradExt_suelo) 
void BloqueIrradExt_suelo::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque; 
} 

void BloqueIrradExt_suelo::IniciarDatos() 
{ 

} 
BOOL BloqueIrradExt_suelo::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueIrradExt_suelo::DestObjDatos() 
{ 
 
} 
void BloqueIrradExt_suelo::GuardarFichero(CArchive& ar) 
{ 
 	ParamBloque.GuardarFichero(ar);
	ResBloque.GuardarFichero(ar);
} 
void BloqueIrradExt_suelo::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
	ResBloque.LeerFichero(ar); 
} 
CString BloqueIrradExt_suelo::Accion() 
{ 
	ParamIrradExt& p = ParamBloque; // Simplemente para que el nombre de la variable se a más corto.
	ResBloque.Eext_suelo = (p.d/p.L)*(1-exp(-p.L*p.tb))*(p.DFgr_g*(p.Ofaire_ext + p.Fb_g*p.Ofaire_int) + p.DFgr_b*(p.Ofaire_ext + p.Fb_b*p.Ofaire_int)*p.Wpiel);
	
	DlgMostrarE dlg(getMainWnd());

	dlg.m_Etiq_E = "E ext,suelo : ";
	dlg.m_Valor_E = ResBloque.Eext_suelo;

	if (dlg.DoModal() == IDOK)
	{
		ResBloque.Eext_suelo = dlg.m_Valor_E;
	}
	return ""; 
} 
BOOL BloqueIrradExt_suelo::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueEntradaParamIrradExt,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueEntradaParamIrradExt

// Implementación de clases de comunicación de Salida del bloque: BloqueEntradaParamIrradExt
IMPLEMENTAR_COM_SALIDA(ParamIrradExt,BloqueEntradaParamIrradExt) 
void BloqueEntradaParamIrradExt::EnviarDatosSalida(ParamIrradExt* pS) 
{ 
	*pS = ParamBloque;
} 
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueEntradaParamIrradExt) 
void BloqueEntradaParamIrradExt::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	// Aquí comienza la comunicación de ResBloque por todo el diagrama
	// Este bloque no hace nada con él sólo lo pasa iniciado a cero.
	*pS = ResBloque; 
} 

void BloqueEntradaParamIrradExt::IniciarDatos() 
{ 

} 
BOOL BloqueEntradaParamIrradExt::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueEntradaParamIrradExt::DestObjDatos() 
{ 
 
} 
void BloqueEntradaParamIrradExt::GuardarFichero(CArchive& ar) 
{ 
	ParamBloque.GuardarFichero(ar);
	ResBloque.GuardarFichero(ar); 
} 
void BloqueEntradaParamIrradExt::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
	ResBloque.LeerFichero(ar); 
} 
CString BloqueEntradaParamIrradExt::Accion() 
{ 
	DlgParamEntradaIrradExt dlg(getMainWnd());

	dlg.m_Ca = ParamBloque.Ca;
	dlg.m_Cw = ParamBloque.Cw;
	dlg.m_Cso = ParamBloque.Cso;
	dlg.m_L = ParamBloque.L;
	dlg.m_DFinm_b = ParamBloque.DFinm_b;
	dlg.m_DFinm_g = ParamBloque.DFinm_g;
	dlg.m_DFaire_b = ParamBloque.DFaire_b;
	dlg.m_DFaire_g = ParamBloque.DFaire_g;
	dlg.m_DFgr_b = ParamBloque.DFgr_b;
	dlg.m_DFgr_g = ParamBloque.DFgr_g;
	dlg.m_tb = ParamBloque.tb;
	dlg.m_Fb_b = ParamBloque.Fb_b;
	dlg.m_Fb_g = ParamBloque.Fb_g;
	dlg.m_Ofinm = ParamBloque.Ofinm;
	dlg.m_Ofaire_ext = ParamBloque.Ofaire_ext;
	dlg.m_Ofaire_int = ParamBloque.Ofaire_int;
	dlg.m_Oforilla = ParamBloque.Oforilla;
	dlg.m_Wpiel = ParamBloque.Wpiel;
	dlg.m_d = ParamBloque.d;
	
	if (dlg.DoModal() == IDOK)
	{
		ParamBloque.Ca = dlg.m_Ca;
		ParamBloque.Cw = dlg.m_Cw;
		ParamBloque.Cso = dlg.m_Cso;
		ParamBloque.L = dlg.m_L;
		ParamBloque.DFinm_b = dlg.m_DFinm_b;
		ParamBloque.DFinm_g = dlg.m_DFinm_g;
		ParamBloque.DFaire_b = dlg.m_DFaire_b;
		ParamBloque.DFaire_g = dlg.m_DFaire_g;
		ParamBloque.DFgr_b = dlg.m_DFgr_b;
		ParamBloque.DFgr_g = dlg.m_DFgr_g;
		ParamBloque.tb = dlg.m_tb;
		ParamBloque.Fb_b = dlg.m_Fb_b;
		ParamBloque.Fb_g = dlg.m_Fb_g;
		ParamBloque.Ofinm = dlg.m_Ofinm;
		ParamBloque.Ofaire_ext = dlg.m_Ofaire_ext;
		ParamBloque.Ofaire_int = dlg.m_Ofaire_int;
		ParamBloque.Oforilla = dlg.m_Oforilla;
		ParamBloque.Wpiel = dlg.m_Wpiel;
		ParamBloque.d = dlg.m_d;
	}

	CambiaEstado(CORRECTO);  
	RetroanotarEnCascada("");	
	return ""; 
} 
BOOL BloqueEntradaParamIrradExt::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueIrradExt_inm_total,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueIrradExt_inm_total
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueIrradExt_inm_total) 
BOOL BloqueIrradExt_inm_total::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 
IMPLEMENTAR_COM_ENTRADA(ParamIrradExt,BloqueIrradExt_inm_total) 
BOOL BloqueIrradExt_inm_total::RecibirDatosEntrada(const ParamIrradExt* pE) 
{ 
	ParamBloque = *pE;
	CambiaEstado(CORRECTO);
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueIrradExt_inm_total
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueIrradExt_inm_total) 
void BloqueIrradExt_inm_total::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque; 
} 

void BloqueIrradExt_inm_total::IniciarDatos() 
{ 

} 
BOOL BloqueIrradExt_inm_total::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueIrradExt_inm_total::DestObjDatos() 
{ 
 
} 
void BloqueIrradExt_inm_total::GuardarFichero(CArchive& ar) 
{ 
 	ParamBloque.GuardarFichero(ar);
	ResBloque.GuardarFichero(ar);
} 
void BloqueIrradExt_inm_total::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
	ResBloque.LeerFichero(ar); 
} 
CString BloqueIrradExt_inm_total::Accion() 
{ 
	ParamIrradExt& p = ParamBloque; // Simplemente para que el nombre de la variable se a más corto.
	ResBloque.Eext_inm_w = p.Cw*(p.DFinm_g + p.Wpiel*p.DFinm_b)*p.Ofinm;

	ResBloque.Eext_inm_total = ResBloque.Eext_inm_w + ResBloque.Eext_inm_fondo + ResBloque.Eext_inm_susp;
	
	DlgMostrar2E dlg(getMainWnd());

	dlg.m_Etiq_E = "E ext,inm agua : ";
	dlg.m_Etiq_E2 = "E ext,inm total : ";

	dlg.m_Valor_E = ResBloque.Eext_inm_w;
	dlg.m_Valor_E2 = ResBloque.Eext_inm_total;

	if (dlg.DoModal() == IDOK)
	{
		ResBloque.Eext_inm_w = dlg.m_Valor_E;
		ResBloque.Eext_inm_total = dlg.m_Valor_E2;
	}
	
	return ""; 
} 
BOOL BloqueIrradExt_inm_total::PropiedadesBloque() 
{ 
	return true; 
} 

IMPLEMENTAR_BLOQUE_FUNCIONAL(BloqueIrradExt_aire,CBloqueFunc,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueIrradExt_aire
IMPLEMENTAR_COM_ENTRADA(ParamIrradExt,BloqueIrradExt_aire) 
BOOL BloqueIrradExt_aire::RecibirDatosEntrada(const ParamIrradExt* pE) 
{ 
	ParamBloque = *pE;
	CambiaEstado(CORRECTO);  
	return true;
} 
IMPLEMENTAR_COM_ENTRADA(ResIrradExt,BloqueIrradExt_aire) 
BOOL BloqueIrradExt_aire::RecibirDatosEntrada(const ResIrradExt* pE) 
{ 
	ResBloque = *pE;
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueIrradExt_aire
IMPLEMENTAR_COM_SALIDA(ResIrradExt,BloqueIrradExt_aire) 
void BloqueIrradExt_aire::EnviarDatosSalida(ResIrradExt* pS) 
{ 
	*pS = ResBloque; 
} 

void BloqueIrradExt_aire::IniciarDatos() 
{ 

} 
BOOL BloqueIrradExt_aire::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueIrradExt_aire::DestObjDatos() 
{ 
 
} 
void BloqueIrradExt_aire::GuardarFichero(CArchive& ar) 
{ 
	ParamBloque.GuardarFichero(ar);
	ResBloque.GuardarFichero(ar); 
} 
void BloqueIrradExt_aire::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
	ResBloque.LeerFichero(ar); 
} 
CString BloqueIrradExt_aire::Accion() 
{ 
	ParamIrradExt& p = ParamBloque; // Simplemente para que el nombre de la variable se a más corto.
	ResBloque.Eext_aire = p.Ca*(p.DFaire_g*(p.Ofaire_ext + p.Fb_g*p.Ofaire_int) + p.DFaire_b*(p.Ofaire_ext + p.Fb_b*p.Ofaire_int)*p.Wpiel);

	DlgMostrarE dlg(getMainWnd());

	dlg.m_Etiq_E = "E ext,aire : ";
	dlg.m_Valor_E = ResBloque.Eext_aire;

	if (dlg.DoModal() == IDOK)
	{
		ResBloque.Eext_aire = dlg.m_Valor_E;
	}

	return ""; 
} 
BOOL BloqueIrradExt_aire::PropiedadesBloque() 
{ 
	return true; 
} 

// Clases de Bloques de Retroanotación: 

IMPLEMENTAR_BLOQUE_RETROANOTACION(BloqueRetroDatosIrradExt,CBloqueRetro,1) 

// Implementación de clases de comunicación de Entrada del bloque: BloqueRetroDatosIrradExt
IMPLEMENTAR_COM_ENTRADA(ParamIrradExt,BloqueRetroDatosIrradExt) 
BOOL BloqueRetroDatosIrradExt::RecibirDatosEntrada(const ParamIrradExt* pE) 
{ 
	ParamBloque = *pE;
	CambiaEstado(CORRECTO);  
	return true;
} 

// Implementación de clases de comunicación de Salida del bloque: BloqueRetroDatosIrradExt
IMPLEMENTAR_COM_SALIDA(ParamIrradExt,BloqueRetroDatosIrradExt) 
void BloqueRetroDatosIrradExt::EnviarDatosSalida(ParamIrradExt* pS) 
{ 
	*pS = ParamBloque;
} 

void BloqueRetroDatosIrradExt::IniciarDatos() 
{ 

} 
BOOL BloqueRetroDatosIrradExt::NuevosObjDatos() 
{ 
	return true; 
} 
void BloqueRetroDatosIrradExt::DestObjDatos() 
{ 
 
} 
void BloqueRetroDatosIrradExt::GuardarFichero(CArchive& ar) 
{ 
 	ParamBloque.GuardarFichero(ar);
} 
void BloqueRetroDatosIrradExt::LeerFichero(CArchive& ar) 
{ 
 	ParamBloque.LeerFichero(ar);
} 
BOOL BloqueRetroDatosIrradExt::PropiedadesBloque() 
{ 
	DlgParamEntradaIrradExt dlg(getMainWnd());

	dlg.m_Ca = ParamBloque.Ca;
	dlg.m_Cw = ParamBloque.Cw;
	dlg.m_Cso = ParamBloque.Cso;
	dlg.m_L = ParamBloque.L;
	dlg.m_DFinm_b = ParamBloque.DFinm_b;
	dlg.m_DFinm_g = ParamBloque.DFinm_g;
	dlg.m_DFaire_b = ParamBloque.DFaire_b;
	dlg.m_DFaire_g = ParamBloque.DFaire_g;
	dlg.m_DFgr_b = ParamBloque.DFgr_b;
	dlg.m_DFgr_g = ParamBloque.DFgr_g;
	dlg.m_tb = ParamBloque.tb;
	dlg.m_Fb_b = ParamBloque.Fb_b;
	dlg.m_Fb_g = ParamBloque.Fb_g;
	dlg.m_Ofinm = ParamBloque.Ofinm;
	dlg.m_Ofaire_ext = ParamBloque.Ofaire_ext;
	dlg.m_Ofaire_int = ParamBloque.Ofaire_int;
	dlg.m_Oforilla = ParamBloque.Oforilla;
	dlg.m_Wpiel = ParamBloque.Wpiel;
	dlg.m_d = ParamBloque.d;
	
	if (dlg.DoModal() == IDOK)
	{
		ParamBloque.Ca = dlg.m_Ca;
		ParamBloque.Cw = dlg.m_Cw;
		ParamBloque.Cso = dlg.m_Cso;
		ParamBloque.L = dlg.m_L;
		ParamBloque.DFinm_b = dlg.m_DFinm_b;
		ParamBloque.DFinm_g = dlg.m_DFinm_g;
		ParamBloque.DFaire_b = dlg.m_DFaire_b;
		ParamBloque.DFaire_g = dlg.m_DFaire_g;
		ParamBloque.DFgr_b = dlg.m_DFgr_b;
		ParamBloque.DFgr_g = dlg.m_DFgr_g;
		ParamBloque.tb = dlg.m_tb;
		ParamBloque.Fb_b = dlg.m_Fb_b;
		ParamBloque.Fb_g = dlg.m_Fb_g;
		ParamBloque.Ofinm = dlg.m_Ofinm;
		ParamBloque.Ofaire_ext = dlg.m_Ofaire_ext;
		ParamBloque.Ofaire_int = dlg.m_Ofaire_int;
		ParamBloque.Oforilla = dlg.m_Oforilla;
		ParamBloque.Wpiel = dlg.m_Wpiel;
		ParamBloque.d = dlg.m_d;
	}

	return true; 
} 
