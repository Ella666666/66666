
// �ڰ���ʵ���ʵ��2.1Doc.h : C�ڰ���ʵ���ʵ��21Doc ��Ľӿ�
//


#pragma once


class C�ڰ���ʵ���ʵ��21Doc : public CDocument
{
protected: // �������л�����
	C�ڰ���ʵ���ʵ��21Doc();
	DECLARE_DYNCREATE(C�ڰ���ʵ���ʵ��21Doc)

// ����
public:

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
	virtual ~C�ڰ���ʵ���ʵ��21Doc();
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
