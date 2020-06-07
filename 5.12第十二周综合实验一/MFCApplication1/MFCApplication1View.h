
// MFCApplication1View.h : CMFCApplication1View 类的接口
//

#pragma once

class CMFCApplication1Set;

class CMFCApplication1View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION1_FORM };
#endif
	CMFCApplication1Set* m_pSet;
	CString path;
// 特性
public:
	CMFCApplication1Doc* GetDocument() const;
	void draw_pic(CString file);
	BOOL use;
// 操作
public:
	
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString pictureName;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
};

#ifndef _DEBUG  // MFCApplication1View.cpp 中的调试版本
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

