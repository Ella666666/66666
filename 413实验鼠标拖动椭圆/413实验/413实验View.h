
// 413ʵ��View.h : CMy413ʵ��View ��Ľӿ�
//

#pragma once


class CMy413ʵ��View : public CView
{
protected: // �������л�����
	CMy413ʵ��View();
	DECLARE_DYNCREATE(CMy413ʵ��View)

// ����
public:
	CMy413ʵ��Doc* GetDocument() const;
    bool m_IsREadyToMove;
	CPoint p1;
	CPen *m_CurrentPen;
	CPoint m_Points[4];
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
	void CMy413ʵ��View::DrawObject(CDC* pDC, const CRect& rect);

// ʵ��
public:
	virtual ~CMy413ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 413ʵ��View.cpp �еĵ��԰汾
inline CMy413ʵ��Doc* CMy413ʵ��View::GetDocument() const
   { return reinterpret_cast<CMy413ʵ��Doc*>(m_pDocument); }
#endif

