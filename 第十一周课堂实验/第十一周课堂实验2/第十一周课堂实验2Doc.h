
// ��ʮһ�ܿ���ʵ��2Doc.h : C��ʮһ�ܿ���ʵ��2Doc ��Ľӿ�
//


#pragma once
#include "��ʮһ�ܿ���ʵ��2Set.h"


class C��ʮһ�ܿ���ʵ��2Doc : public CDocument
{
protected: // �������л�����
	C��ʮһ�ܿ���ʵ��2Doc();
	DECLARE_DYNCREATE(C��ʮһ�ܿ���ʵ��2Doc)

// ����
public:
	C��ʮһ�ܿ���ʵ��2Set m_��ʮһ�ܿ���ʵ��2Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��ʮһ�ܿ���ʵ��2Doc();
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
