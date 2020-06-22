
// 第九周课堂实验1）View.h : C第九周课堂实验1）View 类的接口
//

#pragma once


class C第九周课堂实验1）View : public CView
{
protected: // 仅从序列化创建
	C第九周课堂实验1）View();
	DECLARE_DYNCREATE(C第九周课堂实验1）View)

// 特性
public:
	C第九周课堂实验1）Doc* GetDocument() const;
	CString filename;

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
	virtual ~C第九周课堂实验1）View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdialog();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnShowPicture();
};

#ifndef _DEBUG  // 第九周课堂实验1）View.cpp 中的调试版本
inline C第九周课堂实验1）Doc* C第九周课堂实验1）View::GetDocument() const
   { return reinterpret_cast<C第九周课堂实验1）Doc*>(m_pDocument); }
#endif

