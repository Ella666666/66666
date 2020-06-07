
// 3.10ex1View.h : CMy310ex1View 类的接口
//

#pragma once


class CMy310ex1View : public CView
{
protected: // 仅从序列化创建
	CMy310ex1View();
	DECLARE_DYNCREATE(CMy310ex1View)

// 特性
public:
	CMy310ex1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy310ex1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.10ex1View.cpp 中的调试版本
inline CMy310ex1Doc* CMy310ex1View::GetDocument() const
   { return reinterpret_cast<CMy310ex1Doc*>(m_pDocument); }
#endif

