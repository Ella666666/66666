
// 317pra1View.h : CMy317pra1View ��Ľӿ�
//

#pragma once


class CMy317pra1View : public CView
{
protected: // �������л�����
	CMy317pra1View();
	DECLARE_DYNCREATE(CMy317pra1View)

// ����
public:
	CMy317pra1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy317pra1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 317pra1View.cpp �еĵ��԰汾
inline CMy317pra1Doc* CMy317pra1View::GetDocument() const
   { return reinterpret_cast<CMy317pra1Doc*>(m_pDocument); }
#endif

