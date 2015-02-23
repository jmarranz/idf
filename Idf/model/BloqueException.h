// BloqueException.h: interface for the BloqueException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOQUEEXCEPTION_H__E5B75355_4990_4604_8CEF_CE734BA85549__INCLUDED_)
#define AFX_BLOQUEEXCEPTION_H__E5B75355_4990_4604_8CEF_CE734BA85549__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponenteDiagException.h"

class CBloque;


class BloqueException : public ComponenteDiagException  
{
public:
	BloqueException(CBloque* pbloque,const char* message);
	virtual ~BloqueException();

};

#endif // !defined(AFX_BLOQUEEXCEPTION_H__E5B75355_4990_4604_8CEF_CE734BA85549__INCLUDED_)
