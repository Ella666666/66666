
// 第十一周课堂实验2Doc.h : C第十一周课堂实验2Doc 类的接口
//


#pragma once
#include "第十一周课堂实验2Set.h"


class C第十一周课堂实验2Doc : public CDocument
{
protected: // 仅从序列化创建
	C第十一周课堂实验2Doc();
	DECLARE_DYNCREATE(C第十一周课堂实验2Doc)

// 特性
public:
	C第十一周课堂实验2Set m_第十一周课堂实验2Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C第十一周课堂实验2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
