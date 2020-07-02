
// 综合实验2View.h : C综合实验2View 类的接口
//

#pragma once

class C综合实验2Set;

class C综合实验2View : public CRecordView
{
protected: // 仅从序列化创建
	C综合实验2View();
	void foo(CImage & img, int & sx, int & sy, int & w, int & h);
	DECLARE_DYNCREATE(C综合实验2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY2_FORM };
#endif
	C综合实验2Set* m_pSet;

// 特性
public:
	C综合实验2Doc* GetDocument() const;

// 操作
public:
	BOOL flag;
	CString path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C综合实验2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString picture;
	afx_msg void OnShowPicture();
	afx_msg void OnPaint();
	void drawpicture(CString file);
	afx_msg void OnRecordFirst();
};

#ifndef _DEBUG  // 综合实验2View.cpp 中的调试版本
inline C综合实验2Doc* C综合实验2View::GetDocument() const
   { return reinterpret_cast<C综合实验2Doc*>(m_pDocument); }
#endif

