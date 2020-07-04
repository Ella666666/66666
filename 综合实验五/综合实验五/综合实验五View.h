
// 综合实验五View.h : C综合实验五View 类的接口
//

#pragma once

class C综合实验五Set;

class C综合实验五View : public CRecordView
{
protected: // 仅从序列化创建
	C综合实验五View();
	DECLARE_DYNCREATE(C综合实验五View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C综合实验五Set* m_pSet;
	CString filepath;
// 特性
public:
	C综合实验五Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C综合实验五View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 综合实验五View.cpp 中的调试版本
inline C综合实验五Doc* C综合实验五View::GetDocument() const
   { return reinterpret_cast<C综合实验五Doc*>(m_pDocument); }
#endif

