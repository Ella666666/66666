
// ������ʵ���ʵ��3View.h : C������ʵ���ʵ��3View ��Ľӿ�
//

#pragma once


class C������ʵ���ʵ��3View : public CView
{
protected: // �������л�����
	C������ʵ���ʵ��3View();
	DECLARE_DYNCREATE(C������ʵ���ʵ��3View)

// ����
public:
	C������ʵ���ʵ��3Doc* GetDocument() const;
	CPoint p1;
	CPoint p2;

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
	virtual ~C������ʵ���ʵ��3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawcircle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ������ʵ���ʵ��3View.cpp �еĵ��԰汾
inline C������ʵ���ʵ��3Doc* C������ʵ���ʵ��3View::GetDocument() const
   { return reinterpret_cast<C������ʵ���ʵ��3Doc*>(m_pDocument); }
#endif

