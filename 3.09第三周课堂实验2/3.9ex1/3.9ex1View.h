
// 3.9ex1View.h : CMy39ex1View ��Ľӿ�
//

#pragma once


class CMy39ex1View : public CView
{
protected: // �������л�����
	CMy39ex1View();
	DECLARE_DYNCREATE(CMy39ex1View)

// ����
public:
	CMy39ex1Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&>ca;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy39ex1View();
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

#ifndef _DEBUG  // 3.9ex1View.cpp �еĵ��԰汾
inline CMy39ex1Doc* CMy39ex1View::GetDocument() const
   { return reinterpret_cast<CMy39ex1Doc*>(m_pDocument); }
#endif

