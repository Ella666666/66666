
// ��һ����չʵ��ƴ���ַ���Doc.h : C��һ����չʵ��ƴ���ַ���Doc ��Ľӿ�
//


#pragma once


class C��һ����չʵ��ƴ���ַ���Doc : public CDocument
{
protected: // �������л�����
	C��һ����չʵ��ƴ���ַ���Doc();
	DECLARE_DYNCREATE(C��һ����չʵ��ƴ���ַ���Doc)

// ����
public:
	CString a;
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
	virtual ~C��һ����չʵ��ƴ���ַ���Doc();
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
