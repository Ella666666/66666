
// 3.9ex1View.h : CMy39ex1View 类的接口
//

#pragma once


class CMy39ex1View : public CView
{
protected: // 仅从序列化创建
	CMy39ex1View();
	DECLARE_DYNCREATE(CMy39ex1View)

// 特性
public:
	CMy39ex1Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&>ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy39ex1View();
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
};

#ifndef _DEBUG  // 3.9ex1View.cpp 中的调试版本
inline CMy39ex1Doc* CMy39ex1View::GetDocument() const
   { return reinterpret_cast<CMy39ex1Doc*>(m_pDocument); }
#endif

