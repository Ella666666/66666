
// �ڰ���ʵ���ʵ��2.1View.h : C�ڰ���ʵ���ʵ��21View ��Ľӿ�
//

#pragma once


class C�ڰ���ʵ���ʵ��21View : public CView
{
protected: // �������л�����
	C�ڰ���ʵ���ʵ��21View();
	DECLARE_DYNCREATE(C�ڰ���ʵ���ʵ��21View)

// ����
public:
	C�ڰ���ʵ���ʵ��21Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CPoint p1, p2;
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
	virtual ~C�ڰ���ʵ���ʵ��21View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �ڰ���ʵ���ʵ��2.1View.cpp �еĵ��԰汾
inline C�ڰ���ʵ���ʵ��21Doc* C�ڰ���ʵ���ʵ��21View::GetDocument() const
   { return reinterpret_cast<C�ڰ���ʵ���ʵ��21Doc*>(m_pDocument); }
#endif

