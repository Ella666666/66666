
// 3.10ex2View.cpp : CMy310ex2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.10ex2.h"
#endif

#include "3.10ex2Doc.h"
#include "3.10ex2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy310ex2View

IMPLEMENT_DYNCREATE(CMy310ex2View, CView)

BEGIN_MESSAGE_MAP(CMy310ex2View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy310ex2View 构造/析构

CMy310ex2View::CMy310ex2View()
{
	// TODO: 在此处添加构造代码

}

CMy310ex2View::~CMy310ex2View()
{
}

BOOL CMy310ex2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy310ex2View 绘制

void CMy310ex2View::OnDraw(CDC* pDC)
{
	CMy310ex2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMy310ex2View 诊断

#ifdef _DEBUG
void CMy310ex2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy310ex2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy310ex2Doc* CMy310ex2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy310ex2Doc)));
	return (CMy310ex2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy310ex2View 消息处理程序


void CMy310ex2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy310ex2Doc* pDoc = GetDocument();
	int C = pDoc->A + pDoc->B;
	CString s;
	CClientDC dc(this);
	s.Format(_T("A+B=%d"), C);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
