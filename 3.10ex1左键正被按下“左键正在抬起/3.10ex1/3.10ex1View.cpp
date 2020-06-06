
// 3.10ex1View.cpp : CMy310ex1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.10ex1.h"
#endif

#include "3.10ex1Doc.h"
#include "3.10ex1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy310ex1View

IMPLEMENT_DYNCREATE(CMy310ex1View, CView)

BEGIN_MESSAGE_MAP(CMy310ex1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy310ex1View 构造/析构

CMy310ex1View::CMy310ex1View()
{
	// TODO: 在此处添加构造代码

}

CMy310ex1View::~CMy310ex1View()
{
}

BOOL CMy310ex1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy310ex1View 绘制

void CMy310ex1View::OnDraw(CDC* pDC)
{
	CMy310ex1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy310ex1View 诊断

#ifdef _DEBUG
void CMy310ex1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy310ex1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy310ex1Doc* CMy310ex1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy310ex1Doc)));
	return (CMy310ex1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy310ex1View 消息处理程序


void CMy310ex1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s=_T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(100, 200, s);
}


void CMy310ex1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正在抬起");
	CClientDC dc(this);
	dc.TextOutW(100,200, s);
	CView::OnLButtonUp(nFlags, point);
}
