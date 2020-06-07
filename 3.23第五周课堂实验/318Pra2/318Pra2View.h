
// 318Pra2View.h : CMy318Pra2View 类的接口
//

#pragma once


class CMy318Pra2View : public CView
{
protected: // 仅从序列化创建
	CMy318Pra2View();
	DECLARE_DYNCREATE(CMy318Pra2View)

// 特性
public:
	CMy318Pra2Doc* GetDocument() const;
	int i;
// 操作
public:
	int m_clr1;
	CRect cr;
	CPoint cp;
	bool set;
	int t;
	CBrush cbrush;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy318Pra2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnChangecircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 318Pra2View.cpp 中的调试版本
inline CMy318Pra2Doc* CMy318Pra2View::GetDocument() const
   { return reinterpret_cast<CMy318Pra2Doc*>(m_pDocument); }
#endif

