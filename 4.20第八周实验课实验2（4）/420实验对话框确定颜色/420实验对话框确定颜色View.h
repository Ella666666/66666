
// 420实验对话框确定颜色View.h : CMy420实验对话框确定颜色View 类的接口
//

#pragma once


class CMy420实验对话框确定颜色View : public CView
{
protected: // 仅从序列化创建
	CMy420实验对话框确定颜色View();
	DECLARE_DYNCREATE(CMy420实验对话框确定颜色View)

// 特性
public:
	CMy420实验对话框确定颜色Doc* GetDocument() const;

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
	virtual ~CMy420实验对话框确定颜色View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnInputrgb();
};

#ifndef _DEBUG  // 420实验对话框确定颜色View.cpp 中的调试版本
inline CMy420实验对话框确定颜色Doc* CMy420实验对话框确定颜色View::GetDocument() const
   { return reinterpret_cast<CMy420实验对话框确定颜色Doc*>(m_pDocument); }
#endif

