
// 3.10ex1View.h : CMy310ex1View ��Ľӿ�
//

#pragma once


class CMy310ex1View : public CView
{
protected: // �������л�����
	CMy310ex1View();
	DECLARE_DYNCREATE(CMy310ex1View)

// ����
public:
	CMy310ex1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy310ex1View();
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
};

#ifndef _DEBUG  // 3.10ex1View.cpp �еĵ��԰汾
inline CMy310ex1Doc* CMy310ex1View::GetDocument() const
   { return reinterpret_cast<CMy310ex1Doc*>(m_pDocument); }
#endif

