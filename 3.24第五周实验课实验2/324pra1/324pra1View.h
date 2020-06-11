
// 324pra1View.h : CMy324pra1View 类的接口
//

#pragma once


class CMy324pra1View : public CView
{
protected: // 仅从序列化创建
	CMy324pra1View();
	DECLARE_DYNCREATE(CMy324pra1View)

// 特性
public:
	CMy324pra1Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

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
	virtual ~CMy324pra1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
};

#ifndef _DEBUG  // 324pra1View.cpp 中的调试版本
inline CMy324pra1Doc* CMy324pra1View::GetDocument() const
   { return reinterpret_cast<CMy324pra1Doc*>(m_pDocument); }
#endif

