
// �ڶ���ʵ��1�����ԲView.h : C�ڶ���ʵ��1�����ԲView ��Ľӿ�
//

#pragma once
#define  MAX_BUBBLE  250 

class C�ڶ���ʵ��1�����ԲView : public CView
{
protected: // �������л�����
	C�ڶ���ʵ��1�����ԲView();
	DECLARE_DYNCREATE(C�ڶ���ʵ��1�����ԲView)

// ����
public:
	C�ڶ���ʵ��1�����ԲDoc* GetDocument() const;

// ����
public:
	CRect  m_rectBubble[MAX_BUBBLE];
	int  m_nBubbleCount;
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
	virtual ~C�ڶ���ʵ��1�����ԲView();
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

#ifndef _DEBUG  // �ڶ���ʵ��1�����ԲView.cpp �еĵ��԰汾
inline C�ڶ���ʵ��1�����ԲDoc* C�ڶ���ʵ��1�����ԲView::GetDocument() const
   { return reinterpret_cast<C�ڶ���ʵ��1�����ԲDoc*>(m_pDocument); }
#endif

