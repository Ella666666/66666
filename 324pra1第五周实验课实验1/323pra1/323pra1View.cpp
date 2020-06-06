
// 323pra1View.cpp : CMy323pra1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "323pra1.h"
#endif

#include "323pra1Doc.h"
#include "323pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy323pra1View

IMPLEMENT_DYNCREATE(CMy323pra1View, CView)

BEGIN_MESSAGE_MAP(CMy323pra1View, CView)
	ON_COMMAND(ID_size, &CMy323pra1View::Onsize)
END_MESSAGE_MAP()

// CMy323pra1View 构造/析构

CMy323pra1View::CMy323pra1View()
{
	// TODO: 在此处添加构造代码

}

CMy323pra1View::~CMy323pra1View()
{
}

BOOL CMy323pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy323pra1View 绘制

void CMy323pra1View::OnDraw(CDC* pDC)
{
	CMy323pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy323pra1View 诊断

#ifdef _DEBUG
void CMy323pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy323pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy323pra1Doc* CMy323pra1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy323pra1Doc)));
	return (CMy323pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy323pra1View 消息处理程序


void CMy323pra1View::Onsize(CDC* pDC)
{
	// TODO: 在此添加命令处理程序代码
	for(int i=500;i<=1000;i++)
	pDC->Ellipse(200, 200, i+i % 10, i+i%10);


}
