
// 3.10ex2View.h : CMy310ex2View ��Ľӿ�
//

#pragma once


class CMy310ex2View : public CView
{
protected: // �������л�����
	CMy310ex2View();
	DECLARE_DYNCREATE(CMy310ex2View)

// ����
public:
	CMy310ex2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy310ex2View();
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

#ifndef _DEBUG  // 3.10ex2View.cpp �еĵ��԰汾
inline CMy310ex2Doc* CMy310ex2View::GetDocument() const
   { return reinterpret_cast<CMy310ex2Doc*>(m_pDocument); }
#endif

