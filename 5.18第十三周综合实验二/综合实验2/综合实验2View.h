
// �ۺ�ʵ��2View.h : C�ۺ�ʵ��2View ��Ľӿ�
//

#pragma once

class C�ۺ�ʵ��2Set;

class C�ۺ�ʵ��2View : public CRecordView
{
protected: // �������л�����
	C�ۺ�ʵ��2View();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	DECLARE_DYNCREATE(C�ۺ�ʵ��2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY2_FORM };
#endif
	C�ۺ�ʵ��2Set* m_pSet;

// ����
public:
	C�ۺ�ʵ��2Doc* GetDocument() const;

// ����
public:
	BOOL flag;
	CString path;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C�ۺ�ʵ��2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString picture;
	afx_msg void OnShowPicture();
	afx_msg void OnPaint();
	void drawpicture(CString file);
	afx_msg void OnRecordFirst();
};

#ifndef _DEBUG  // �ۺ�ʵ��2View.cpp �еĵ��԰汾
inline C�ۺ�ʵ��2Doc* C�ۺ�ʵ��2View::GetDocument() const
   { return reinterpret_cast<C�ۺ�ʵ��2Doc*>(m_pDocument); }
#endif

