
// 2.2.4View.h : CMy224View 类的接口
//

#pragma once


class CMy224View : public CView
{
protected: // 仅从序列化创建
	CMy224View();
	DECLARE_DYNCREATE(CMy224View)

// 特性
public:
	CMy224Doc* GetDocument() const;

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
	virtual ~CMy224View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2.2.4View.cpp 中的调试版本
inline CMy224Doc* CMy224View::GetDocument() const
   { return reinterpret_cast<CMy224Doc*>(m_pDocument); }
#endif

