
// 318Pra2View.h : CMy318Pra2View ��Ľӿ�
//

#pragma once


class CMy318Pra2View : public CView
{
protected: // �������л�����
	CMy318Pra2View();
	DECLARE_DYNCREATE(CMy318Pra2View)

// ����
public:
	CMy318Pra2Doc* GetDocument() const;
	int i;
// ����
public:
	int m_clr1;
	CRect cr;
	CPoint cp;
	bool set;
	int t;
	CBrush cbrush;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy318Pra2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnChangecircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 318Pra2View.cpp �еĵ��԰汾
inline CMy318Pra2Doc* CMy318Pra2View::GetDocument() const
   { return reinterpret_cast<CMy318Pra2Doc*>(m_pDocument); }
#endif

