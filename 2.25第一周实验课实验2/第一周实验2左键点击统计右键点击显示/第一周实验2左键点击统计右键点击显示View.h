
// ��һ��ʵ��2������ͳ���Ҽ������ʾView.h : C��һ��ʵ��2������ͳ���Ҽ������ʾView ��Ľӿ�
//

#pragma once


class C��һ��ʵ��2������ͳ���Ҽ������ʾView : public CView
{
protected: // �������л�����
	C��һ��ʵ��2������ͳ���Ҽ������ʾView();
	DECLARE_DYNCREATE(C��һ��ʵ��2������ͳ���Ҽ������ʾView)

// ����
public:
	C��һ��ʵ��2������ͳ���Ҽ������ʾDoc* GetDocument() const;

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
	virtual ~C��һ��ʵ��2������ͳ���Ҽ������ʾView();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��һ��ʵ��2������ͳ���Ҽ������ʾView.cpp �еĵ��԰汾
inline C��һ��ʵ��2������ͳ���Ҽ������ʾDoc* C��һ��ʵ��2������ͳ���Ҽ������ʾView::GetDocument() const
   { return reinterpret_cast<C��һ��ʵ��2������ͳ���Ҽ������ʾDoc*>(m_pDocument); }
#endif

