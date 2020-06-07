
// 317pra1View.h : CMy317pra1View 类的接口
//

#pragma once


class CMy317pra1View : public CView
{
protected: // 仅从序列化创建
	CMy317pra1View();
	DECLARE_DYNCREATE(CMy317pra1View)

// 特性
public:
	CMy317pra1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy317pra1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 317pra1View.cpp 中的调试版本
inline CMy317pra1Doc* CMy317pra1View::GetDocument() const
   { return reinterpret_cast<CMy317pra1Doc*>(m_pDocument); }
#endif

