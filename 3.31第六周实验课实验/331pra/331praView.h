
// 331praView.h : CMy331praView ��Ľӿ�
//

#pragma once


class CMy331praView : public CView
{
protected: // �������л�����
	CMy331praView();
	DECLARE_DYNCREATE(CMy331praView)

// ����
private:
		CString m_str;CPoint m_ptr;
public:
	CMy331praDoc* GetDocument() const;
	CString filename;
	CRect rect;
	int x, y;
	CImage img;
	CPoint p1;
	BOOL use;
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
	virtual ~CMy331praView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 331praView.cpp �еĵ��԰汾
inline CMy331praDoc* CMy331praView::GetDocument() const
   { return reinterpret_cast<CMy331praDoc*>(m_pDocument); }
#endif

