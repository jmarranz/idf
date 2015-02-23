// FileUtil.cpp: implementation of the CFileUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\Idf.h"
#include "FileUtil.h"

#include <direct.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileUtil::CFileUtil()
{

}

CFileUtil::~CFileUtil()
{

}

CString CFileUtil::DirectorioActual()
{
	char pathdir[_MAX_PATH];  // unidad y directorio
	_getcwd( pathdir, _MAX_PATH );
	return pathdir;
}

CString CFileUtil::FormarPathAbsoluto(const CString& PathRel, const CString& NombreFich)
{
   // char path_buffer[_MAX_PATH];
   char drive[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fname[_MAX_FNAME];
   char ext[_MAX_EXT];

	// Vemos si NombreFich es un path absoluto o relativo:
	_splitpath( NombreFich, drive, dir, fname, ext );
	if (strlen(drive) >0)	return NombreFich; // Tiene unidad-> absoluto
	if (strlen(dir) >0)  // path no nulo, vemos si es absoluto
	{
		if ((dir[0] == '\\') || (dir[0] == '/')) return NombreFich; // Tiene barra de root-> absoluto
	}
	return CString( PathRel + NombreFich ); 
}


BOOL CFileUtil::ExisteDirectorio(const CString& Directorio)
{
	if (Directorio == ".") return true;

	if (Directorio.IsEmpty())  return false;

	// Comprobamos si el directorio existe
	// Recogemos antes el directorio actual para no perderlo.
	char pathdir[_MAX_PATH];  // unidad y directorio
	_getcwd( pathdir, _MAX_PATH );
	int res = _chdir(Directorio);
	_chdir(pathdir);  // Restauramos
	if (res == -1) return false;
	return true;
}

