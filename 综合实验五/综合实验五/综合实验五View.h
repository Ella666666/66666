
// �ۺ�ʵ����View.h : C�ۺ�ʵ����View ��Ľӿ�
//

#pragma once

class C�ۺ�ʵ����Set;

class C�ۺ�ʵ����View : public CRecordView
{
protected: // �������л�����
	C�ۺ�ʵ����View();
	DECLARE_DYNCREATE(C�ۺ�ʵ����View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C�ۺ�ʵ����Set* m_pSet;
	CString filepath;
// ����
public:
	C�ۺ�ʵ����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ۺ�ʵ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString num;
	CString specia;
	CString sex;
	CString birth;
	CString phone;
	CString address;
	CString picpath;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void draw_pic(CString filename);
	void OnDraw(CDC *);
	afx_msg void OnEnlarge();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedADD();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedMod();
	afx_msg void OnSort();
	afx_msg void OnSelect();
	afx_msg void OnBnClickedRecover();
	afx_msg void OnErgodic();
};

#ifndef _DEBUG  // �ۺ�ʵ����View.cpp �еĵ��԰汾
inline C�ۺ�ʵ����Doc* C�ۺ�ʵ����View::GetDocument() const
   { return reinterpret_cast<C�ۺ�ʵ����Doc*>(m_pDocument); }
#endif

