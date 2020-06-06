
// 413实验View.h : CMy413实验View 类的接口
//

#pragma once


class CMy413实验View : public CView
{
protected: // 仅从序列化创建
	CMy413实验View();
	DECLARE_DYNCREATE(CMy413实验View)

// 特性
public:
	CMy413实验Doc* GetDocument() const;
    bool m_IsREadyToMove;
	CPoint p1;
	CPen *m_CurrentPen;
	CPoint m_Points[4];
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
	void CMy413实验View::DrawObject(CDC* pDC, const CRect& rect);

// 实现
public:
	virtual ~CMy413实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 413实验View.cpp 中的调试版本
inline CMy413实验Doc* CMy413实验View::GetDocument() const
   { return reinterpret_cast<CMy413实验Doc*>(m_pDocument); }
#endif

