
// diagdis.h

// Derivada de CDiagBase orientada al diseño del diagrama.

#ifndef CDIAGDIS_H
#define CDIAGDIS_H


#include "..\DiagBase.h"  // Para no tener que incluir repetidamente en cada cpp


class CDiagDisDoc;
class CDiagDisView;
class CConect;
class CBloqueDLL;
class CBloqueDiag;
class CBloqueDLLRetroano;
class CDiagramaVistasDis;


typedef enum
{
	NULO,
	CAMBIAETIQDIAG,
	INSCONECT,
	INSCONECTRETRO,
	CAMBIAETIQCONECT,
	ASOCIABLQINI,
	ASOCIABLQFIN,
	MOVERGRUPO,
	SELECCGRUPO,
	DESELECCGRUPO
} EstadosDiseno;


typedef enum
{
	PTOINICIAL,  // Para MOVERGRUPO
	PTOFINAL     // Para MOVERGRUPO
} SubEstadosDiseno;



class CDiagDis : public CDiagBase
{
	DECLARE_SERIAL(CDiagDis)
public:
	CDiagDis();	
	virtual ~CDiagDis();
	virtual void Destruir();

	virtual void CrearNuevo();
	virtual void CrearDesdeFichero();
	virtual void Serialize(CArchive& ar);

	CDiagramaVistasDis* getVistas()
	{
		return (CDiagramaVistasDis*)p_vistas;
	}

	// Redefinidas de CDiagBase
	virtual CDiagramaVistas* CrearObjDiagramaVistas();	


	virtual BOOL EsDiagDiseno() { return true; };
		
	// Exclusivas de CDiagDis:

	virtual void NuevoBloque(CBloque* blq,const char* idRaiz,BOOL retro);
	virtual CBloqueDLL* NuevoBloqueDLLFunc();
	virtual CBloqueDiag* NuevoBloqueDiag();
	virtual CBloqueDLL* NuevoBloqueDLLRetro();

	virtual void NuevoConect(CConect* con,const char* idRaiz,BOOL retro,CPoint pmm);
	virtual CConect* NuevoConectFunc(CPoint pmm);
	virtual CConect* NuevoConectRetro(CPoint pmm);

	virtual void EliminarBloque(CBloque* pBloque);  // De cualquier tipo
	virtual void EliminarConector(CConect* pConect);


	virtual void comienzoAsociarBloqueIni(CConect* con);
	virtual void comienzoAsociarBloqueFin(CConect* con);
	virtual void comienzoAsociarBloque(EstadosDiseno extremo,CConect* con);

public:    
	// No se guardan a fichero :

	EstadosDiseno m_estadoEdic;  // Estado de edición (insertando etc.)
	SubEstadosDiseno m_subEstadoEdic;  // Subestado de edición dentro de un estado. 
	
	CConect* p_conect;  // Puntero temporal para cambio de la etiqueta del conector

};


#endif
