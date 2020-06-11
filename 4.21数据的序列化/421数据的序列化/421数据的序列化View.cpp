
// 421数据的序列化View.cpp : CMy421数据的序列化View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "421数据的序列化.h"
#endif

#include "421数据的序列化Doc.h"
#include "421数据的序列化View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy421数据的序列化View

IMPLEMENT_DYNCREATE(CMy421数据的序列化View, CView)

BEGIN_MESSAGE_MAP(CMy421数据的序列化View, CView)
	ON_COMMAND(ID_Change, &CMy421数据的序列化View::OnChange)
END_MESSAGE_MAP()

// CMy421数据的序列化View 构造/析构

CMy421数据的序列化View::CMy421数据的序列化View()
{
	// TODO: 在此处添加构造代码

}

CMy421数据的序列化View::~CMy421数据的序列化View()
{
}

BOOL CMy421数据的序列化View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy421数据的序列化View 绘制

void CMy421数据的序列化View::OnDraw(CDC* pDC)
{
	CMy421数据的序列化Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(200, 300, pDoc->s);
	CString ss;
	ss.Format(_T("%d yes!"), 100 + pDoc->a);
	pDC->TextOutW(300, 3000, ss);
}


// CMy421数据的序列化View 诊断

#ifdef _DEBUG
void CMy421数据的序列化View::AssertValid() const
{
	CView::AssertValid();
}

void CMy421数据的序列化View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy421数据的序列化Doc* CMy421数据的序列化View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy421数据的序列化Doc)));
	return (CMy421数据的序列化Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy421数据的序列化View 消息处理程序


void CMy421数据的序列化View::OnChange()
{
	CMy421数据的序列化Doc* pDoc = GetDocument();
	pDoc->a += 1000;
	pDoc->s += _T("added!");
	Invalidate();
		// TODO: 在此添加命令处理程序代码

}
