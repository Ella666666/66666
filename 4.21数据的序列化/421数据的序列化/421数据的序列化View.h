
// 421数据的序列化View.h : CMy421数据的序列化View 类的接口
//

#pragma once


class CMy421数据的序列化View : public CView
{
protected: // 仅从序列化创建
	CMy421数据的序列化View();
	DECLARE_DYNCREATE(CMy421数据的序列化View)

// 特性
public:
	CMy421数据的序列化Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy421数据的序列化View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChange();
};

#ifndef _DEBUG  // 421数据的序列化View.cpp 中的调试版本
inline CMy421数据的序列化Doc* CMy421数据的序列化View::GetDocument() const
   { return reinterpret_cast<CMy421数据的序列化Doc*>(m_pDocument); }
#endif

