
// �ھ���ʵ���ʵ��2View.h : C�ھ���ʵ���ʵ��2View ��Ľӿ�
//

#pragma once


class C�ھ���ʵ���ʵ��2View : public CView
{
protected: // �������л�����
	C�ھ���ʵ���ʵ��2View();
	DECLARE_DYNCREATE(C�ھ���ʵ���ʵ��2View)

// ����
public:
	C�ھ���ʵ���ʵ��2Doc* GetDocument() const;
	CRect r;
	bool set;
	CString filename;
	int i;
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
	virtual ~C�ھ���ʵ���ʵ��2View();
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
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // �ھ���ʵ���ʵ��2View.cpp �еĵ��԰汾
inline C�ھ���ʵ���ʵ��2Doc* C�ھ���ʵ���ʵ��2View::GetDocument() const
   { return reinterpret_cast<C�ھ���ʵ���ʵ��2Doc*>(m_pDocument); }
#endif

