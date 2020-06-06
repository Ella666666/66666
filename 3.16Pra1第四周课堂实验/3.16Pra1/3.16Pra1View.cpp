
// 3.16Pra1View.cpp : CMy316Pra1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.16Pra1.h"
#endif

#include "3.16Pra1Doc.h"
#include "3.16Pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316Pra1View

IMPLEMENT_DYNCREATE(CMy316Pra1View, CView)

BEGIN_MESSAGE_MAP(CMy316Pra1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316Pra1View 构造/析构

CMy316Pra1View::CMy316Pra1View()
{
	// TODO: 在此处添加构造代码

}

CMy316Pra1View::~CMy316Pra1View()
{
}

BOOL CMy316Pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy316Pra1View 绘制

void CMy316Pra1View::OnDraw(CDC* pDC)
{
	CMy316Pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy316Pra1View 诊断

#ifdef _DEBUG
void CMy316Pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316Pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316Pra1Doc* CMy316Pra1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316Pra1Doc)));
	return (CMy316Pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316Pra1View 消息处理程序


void CMy316Pra1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy316Pra1Doc* pDoc = GetDocument();
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void CMy316Pra1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CMy316Pra1Doc* pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x ;
	pDoc->m_tagRec.bottom = point.y ;
	InvalidateRect(NULL, TRUE);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonUp(nFlags, point);
}


void CMy316Pra1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d,%d"), point.x, point.y);
	dc.TextOutW(0, 0, s);
	CView::OnMouseMove(nFlags, point);
}
