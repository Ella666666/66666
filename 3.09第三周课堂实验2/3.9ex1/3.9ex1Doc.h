
// 3.9ex1Doc.h : CMy39ex1Doc ��Ľӿ�
//


#pragma once


class CMy39ex1Doc : public CDocument
{
protected: // �������л�����
	CMy39ex1Doc();
	DECLARE_DYNCREATE(CMy39ex1Doc)

// ����
public:

// ����
public:
	CArray<CRect, CRect&>ca;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy39ex1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
