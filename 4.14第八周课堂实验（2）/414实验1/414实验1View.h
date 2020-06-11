
// 414实验1View.h : CMy414实验1View 类的接口
//

#pragma once


class CMy414实验1View : public CView
{
protected: // 仅从序列化创建
	CMy414实验1View();
	DECLARE_DYNCREATE(CMy414实验1View)

// 特性
public:
	CMy414实验1Doc* GetDocument() const;

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
	virtual ~CMy414实验1View();
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
	afx_msg void OnBnClickedOpenButton();
};

#ifndef _DEBUG  // 414实验1View.cpp 中的调试版本
inline CMy414实验1Doc* CMy414实验1View::GetDocument() const
   { return reinterpret_cast<CMy414实验1Doc*>(m_pDocument); }
#endif

