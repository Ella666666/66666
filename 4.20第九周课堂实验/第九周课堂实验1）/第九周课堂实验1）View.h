
// �ھ��ܿ���ʵ��1��View.h : C�ھ��ܿ���ʵ��1��View ��Ľӿ�
//

#pragma once


class C�ھ��ܿ���ʵ��1��View : public CView
{
protected: // �������л�����
	C�ھ��ܿ���ʵ��1��View();
	DECLARE_DYNCREATE(C�ھ��ܿ���ʵ��1��View)

// ����
public:
	C�ھ��ܿ���ʵ��1��Doc* GetDocument() const;
	CString filename;

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
	virtual ~C�ھ��ܿ���ʵ��1��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdialog();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnShowPicture();
};

#ifndef _DEBUG  // �ھ��ܿ���ʵ��1��View.cpp �еĵ��԰汾
inline C�ھ��ܿ���ʵ��1��Doc* C�ھ��ܿ���ʵ��1��View::GetDocument() const
   { return reinterpret_cast<C�ھ��ܿ���ʵ��1��Doc*>(m_pDocument); }
#endif

