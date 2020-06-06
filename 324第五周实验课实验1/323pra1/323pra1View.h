
// 323pra1View.h : CMy323pra1View 类的接口
//

#pragma once


class CMy323pra1View : public CView
{
protected: // 仅从序列化创建
	CMy323pra1View();
	DECLARE_DYNCREATE(CMy323pra1View)

// 特性
public:
	CMy323pra1Doc* GetDocument() const;

	void Onsize(CDC * pDC);

// 操作
public: CMenu size;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy323pra1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onsize(CDC* pDC);
};

#ifndef _DEBUG  // 323pra1View.cpp 中的调试版本
inline CMy323pra1Doc* CMy323pra1View::GetDocument() const
   { return reinterpret_cast<CMy323pra1Doc*>(m_pDocument); }
#endif

