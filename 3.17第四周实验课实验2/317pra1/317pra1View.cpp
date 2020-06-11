
// 317pra1View.cpp : CMy317pra1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "317pra1.h"
#endif

#include "317pra1Doc.h"
#include "317pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy317pra1View

IMPLEMENT_DYNCREATE(CMy317pra1View, CView)

BEGIN_MESSAGE_MAP(CMy317pra1View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy317pra1View 构造/析构

CMy317pra1View::CMy317pra1View()
{
	// TODO: 在此处添加构造代码

}

CMy317pra1View::~CMy317pra1View()
{
}

BOOL CMy317pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy317pra1View 绘制

void CMy317pra1View::OnDraw(CDC* pDC)
{
	CMy317pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMy317pra1View 诊断

#ifdef _DEBUG
void CMy317pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy317pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy317pra1Doc* CMy317pra1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy317pra1Doc)));
	return (CMy317pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy317pra1View 消息处理程序


void CMy317pra1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy317pra1Doc* pDoc = GetDocument();
	CRect cli;
	GetClientRect(&cli);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_crlRect.left > 0)
		{
			pDoc->m_crlRect.left -= 15;
			pDoc->m_crlRect.right -= 15;
		}break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right <=(cli.right-cli.left))
		{
			pDoc->m_crlRect.left += 15;
			pDoc->m_crlRect.right += 15;
		}break;
	case VK_UP:
			if (pDoc->m_crlRect.top>0)
			{
				pDoc->m_crlRect.top -=15;
				pDoc->m_crlRect.bottom -= 15;
			}break;
	case VK_DOWN:
			if (pDoc->m_crlRect.top<=(cli.bottom-cli.top))
			{
				pDoc->m_crlRect.top += 15;
				pDoc->m_crlRect.bottom += 15;
			}break;
	case VK_END:
			if (pDoc->m_crlRect.top <= (cli.bottom - cli.top))
			{
				pDoc->m_crlRect.top += 15;
				pDoc->m_crlRect.left += 15;
			}break;
	case VK_HOME:
			if (pDoc->m_crlRect.top <= (cli.bottom - cli.top))
			{
				pDoc->m_crlRect.right += 15;
				pDoc->m_crlRect.bottom += 15;
				
			}break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy317pra1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy317pra1Doc* pDoc = GetDocument();
	pDoc->m_crlRect.left = 450; pDoc->m_crlRect.right = 900;
	pDoc->m_crlRect.top = 50; pDoc->m_crlRect.bottom = 500;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
