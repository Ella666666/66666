
// 3.16Pra1View.h : CMy316Pra1View ��Ľӿ�
//

#pragma once


class CMy316Pra1View : public CView
{
protected: // �������л�����
	CMy316Pra1View();
	DECLARE_DYNCREATE(CMy316Pra1View)

// ����
public:
	CMy316Pra1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy316Pra1View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.16Pra1View.cpp �еĵ��԰汾
inline CMy316Pra1Doc* CMy316Pra1View::GetDocument() const
   { return reinterpret_cast<CMy316Pra1Doc*>(m_pDocument); }
#endif

