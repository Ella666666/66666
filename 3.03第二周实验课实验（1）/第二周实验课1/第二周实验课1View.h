
// �ڶ���ʵ���1View.h : C�ڶ���ʵ���1View ��Ľӿ�
//

#pragma once


class C�ڶ���ʵ���1View : public CView
{
protected: // �������л�����
	C�ڶ���ʵ���1View();
	DECLARE_DYNCREATE(C�ڶ���ʵ���1View)

// ����
public:
	C�ڶ���ʵ���1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ڶ���ʵ���1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �ڶ���ʵ���1View.cpp �еĵ��԰汾
inline C�ڶ���ʵ���1Doc* C�ڶ���ʵ���1View::GetDocument() const
   { return reinterpret_cast<C�ڶ���ʵ���1Doc*>(m_pDocument); }
#endif

