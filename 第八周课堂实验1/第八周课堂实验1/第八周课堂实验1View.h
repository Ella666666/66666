
// 第八周课堂实验1View.h : C第八周课堂实验1View 类的接口
//

#pragma once


class C第八周课堂实验1View : public CView
{
protected: // 仅从序列化创建
	C第八周课堂实验1View();
	DECLARE_DYNCREATE(C第八周课堂实验1View)

// 特性
public:
	C第八周课堂实验1Doc* GetDocument() const;
	CString s;
	BOOL set;
	CString filename;
	CString strFilePath;
		CString s1;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C第八周课堂实验1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnChoose();
	afx_msg void OnDiadlg();
};

#ifndef _DEBUG  // 第八周课堂实验1View.cpp 中的调试版本
inline C第八周课堂实验1Doc* C第八周课堂实验1View::GetDocument() const
   { return reinterpret_cast<C第八周课堂实验1Doc*>(m_pDocument); }
#endif

