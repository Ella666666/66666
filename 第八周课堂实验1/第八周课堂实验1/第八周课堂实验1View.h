
// �ڰ��ܿ���ʵ��1View.h : C�ڰ��ܿ���ʵ��1View ��Ľӿ�
//

#pragma once


class C�ڰ��ܿ���ʵ��1View : public CView
{
protected: // �������л�����
	C�ڰ��ܿ���ʵ��1View();
	DECLARE_DYNCREATE(C�ڰ��ܿ���ʵ��1View)

// ����
public:
	C�ڰ��ܿ���ʵ��1Doc* GetDocument() const;
	CString s;
	BOOL set;
	CString filename;
	CString strFilePath;
		CString s1;
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
	virtual ~C�ڰ��ܿ���ʵ��1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnChoose();
	afx_msg void OnDiadlg();
};

#ifndef _DEBUG  // �ڰ��ܿ���ʵ��1View.cpp �еĵ��԰汾
inline C�ڰ��ܿ���ʵ��1Doc* C�ڰ��ܿ���ʵ��1View::GetDocument() const
   { return reinterpret_cast<C�ڰ��ܿ���ʵ��1Doc*>(m_pDocument); }
#endif

