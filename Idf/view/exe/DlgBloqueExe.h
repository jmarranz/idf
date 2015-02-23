// dlgbloq.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBloque dialog

#if !defined(AFX_DLGBLOQUEEXE_H__E129707D_4EA2_49C1_90B9_B26C619DB3EA__INCLUDED_)
#define AFX_DLGBLOQUEEXE_H__E129707D_4EA2_49C1_90B9_B26C619DB3EA__INCLUDED_


#include "..\DlgBloque.h"

class CBaseView;
class CBloque;


class CDlgBloqueExe : public CDlgBloque
{
// Construction
public:
	CDlgBloqueExe(CWnd* pParent = NULL);	// standard constructor
    //CDlgBloque();  // Retocado para ser no modal de modelo decidido en ejecución.

	virtual BOOL Crear(CBaseView* view,CBloqueVistas* pvistas);
	virtual BOOL OnInitDialog();
	virtual void ActualizaEtiq();
	virtual void MoverEtiqueta(CRect& rect);

	virtual void cargarMenu(CPoint point);

// Dialog Data
	//{{AFX_DATA(CDlgBloque)
	enum { IDD = IDD_BLOQUE };
	CStatic	m_CtrlEtiq;
	CString	m_Etiq;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDlgBloqueExe)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnOperaciones();
	afx_msg void OnPropDll();
	afx_msg void OnPropGen();
	afx_msg void OnPropEspec();
	afx_msg void OnPropInform();
	afx_msg void OnPropListaconect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	// Controles incluidos en el diálogo.


};


#endif // !defined(AFX_DLGBLOQUEEXE_H__E129707D_4EA2_49C1_90B9_B26C619DB3EA__INCLUDED_)
