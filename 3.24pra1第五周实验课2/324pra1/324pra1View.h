
// 324pra1View.h : CMy324pra1View ��Ľӿ�
//

#pragma once


class CMy324pra1View : public CView
{
protected: // �������л�����
	CMy324pra1View();
	DECLARE_DYNCREATE(CMy324pra1View)

// ����
public:
	CMy324pra1Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

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
	virtual ~CMy324pra1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
};

#ifndef _DEBUG  // 324pra1View.cpp �еĵ��԰汾
inline CMy324pra1Doc* CMy324pra1View::GetDocument() const
   { return reinterpret_cast<CMy324pra1Doc*>(m_pDocument); }
#endif

