
// �ڶ���ʵ���ʵ��2Doc.h : C�ڶ���ʵ���ʵ��2Doc ��Ľӿ�
//


#pragma once


class C�ڶ���ʵ���ʵ��2Doc : public CDocument
{
protected: // �������л�����
	C�ڶ���ʵ���ʵ��2Doc();
	DECLARE_DYNCREATE(C�ڶ���ʵ���ʵ��2Doc)

// ����
public:
	CString S = _T("S:����***");
	int A = 110;
// ����
public:

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
	virtual ~C�ڶ���ʵ���ʵ��2Doc();
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
