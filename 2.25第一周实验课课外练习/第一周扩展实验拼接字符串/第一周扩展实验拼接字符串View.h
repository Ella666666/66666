
// 第一周扩展实验拼接字符串View.h : C第一周扩展实验拼接字符串View 类的接口
//

#pragma once


class C第一周扩展实验拼接字符串View : public CView
{
protected: // 仅从序列化创建
	C第一周扩展实验拼接字符串View();
	DECLARE_DYNCREATE(C第一周扩展实验拼接字符串View)

// 特性
public:
	C第一周扩展实验拼接字符串Doc* GetDocument() const;

// 操作
public:
	CString b;
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
	virtual ~C第一周扩展实验拼接字符串View();
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

#ifndef _DEBUG  // 第一周扩展实验拼接字符串View.cpp 中的调试版本
inline C第一周扩展实验拼接字符串Doc* C第一周扩展实验拼接字符串View::GetDocument() const
   { return reinterpret_cast<C第一周扩展实验拼接字符串Doc*>(m_pDocument); }
#endif

