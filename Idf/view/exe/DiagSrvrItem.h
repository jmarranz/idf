// srvritem.h : interface of the CDiagSrvrItem class
//
class CDiagExeDoc;

class CDiagSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CDiagSrvrItem)

// Constructors
public:
	CDiagSrvrItem(CDiagExeDoc* pContainerDoc);

// Attributes
	CDiagExeDoc* GetDocument() const
		{ return (CDiagExeDoc*)COleServerItem::GetDocument(); }

// Implementation
public:
	~CDiagSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	virtual BOOL IsBlank();

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

/////////////////////////////////////////////////////////////////////////////
