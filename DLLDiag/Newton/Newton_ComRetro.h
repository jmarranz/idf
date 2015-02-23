// Newton_ComRetro.h: interface for the Newton_ComRetro class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTON_COMRETRO_H__40D0B560_6C33_4E72_BE1B_CE3967891F2D__INCLUDED_)
#define AFX_NEWTON_COMRETRO_H__40D0B560_6C33_4E72_BE1B_CE3967891F2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Newton_ComRetro : public CCom
{
public:
  	DECLARAR_COMUNICACION(Newton_ComRetro)

	virtual void GuardarDatos(CArchive& ar); // Util sólo en comunicación entre dos DLLs
	virtual void LeerDatos(CArchive& ar); // Util sólo en comunicación entre dos DLLs
		
public:
  	//DECLARAR_VARIABLE_COM(emax, double) emax;	
  	//DECLARAR_VARIABLE_COM(h, double) h;
	
	double emax;
	double h;
};

#endif // !defined(AFX_NEWTON_COMRETRO_H__40D0B560_6C33_4E72_BE1B_CE3967891F2D__INCLUDED_)
