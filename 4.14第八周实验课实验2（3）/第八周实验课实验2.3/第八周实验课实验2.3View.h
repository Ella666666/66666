
// �ڰ���ʵ���ʵ��2.3View.h : C�ڰ���ʵ���ʵ��23View ��Ľӿ�
//

#pragma once


class C�ڰ���ʵ���ʵ��23View : public CView
{
protected: // �������л�����
	C�ڰ���ʵ���ʵ��23View();
	DECLARE_DYNCREATE(C�ڰ���ʵ���ʵ��23View)

// ����
public:
	C�ڰ���ʵ���ʵ��23Doc* GetDocument() const;

// ����
public:
	CRect cr;
	BOOL set;
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
	virtual ~C�ڰ���ʵ���ʵ��23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �ڰ���ʵ���ʵ��2.3View.cpp �еĵ��԰汾
inline C�ڰ���ʵ���ʵ��23Doc* C�ڰ���ʵ���ʵ��23View::GetDocument() const
   { return reinterpret_cast<C�ڰ���ʵ���ʵ��23Doc*>(m_pDocument); }
#endif

