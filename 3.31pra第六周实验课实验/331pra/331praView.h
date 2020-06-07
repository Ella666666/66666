
// 331praView.h : CMy331praView 类的接口
//

#pragma once


class CMy331praView : public CView
{
protected: // 仅从序列化创建
	CMy331praView();
	DECLARE_DYNCREATE(CMy331praView)

// 特性
private:
		CString m_str;CPoint m_ptr;
public:
	CMy331praDoc* GetDocument() const;
	CString filename;
	CRect rect;
	int x, y;
	CImage img;
	CPoint p1;
	BOOL use;
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
	virtual ~CMy331praView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 331praView.cpp 中的调试版本
inline CMy331praDoc* CMy331praView::GetDocument() const
   { return reinterpret_cast<CMy331praDoc*>(m_pDocument); }
#endif

