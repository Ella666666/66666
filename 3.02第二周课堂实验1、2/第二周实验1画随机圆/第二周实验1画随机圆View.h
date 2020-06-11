
// 第二周实验1画随机圆View.h : C第二周实验1画随机圆View 类的接口
//

#pragma once
#define  MAX_BUBBLE  250 

class C第二周实验1画随机圆View : public CView
{
protected: // 仅从序列化创建
	C第二周实验1画随机圆View();
	DECLARE_DYNCREATE(C第二周实验1画随机圆View)

// 特性
public:
	C第二周实验1画随机圆Doc* GetDocument() const;

// 操作
public:
	CRect  m_rectBubble[MAX_BUBBLE];
	int  m_nBubbleCount;
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
	virtual ~C第二周实验1画随机圆View();
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

#ifndef _DEBUG  // 第二周实验1画随机圆View.cpp 中的调试版本
inline C第二周实验1画随机圆Doc* C第二周实验1画随机圆View::GetDocument() const
   { return reinterpret_cast<C第二周实验1画随机圆Doc*>(m_pDocument); }
#endif

