
// 第八周实验课实验2.1View.cpp : C第八周实验课实验21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第八周实验课实验2.1.h"
#endif

#include "第八周实验课实验2.1Doc.h"
#include "第八周实验课实验2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第八周实验课实验21View

IMPLEMENT_DYNCREATE(C第八周实验课实验21View, CView)

BEGIN_MESSAGE_MAP(C第八周实验课实验21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第八周实验课实验21View 构造/析构

C第八周实验课实验21View::C第八周实验课实验21View()
{
	// TODO: 在此处添加构造代码
	cr.bottom = 200;
	cr.top = 100;
	cr.right = 200;
	cr.left = 100;
	set = false;
}

C第八周实验课实验21View::~C第八周实验课实验21View()
{
}

BOOL C第八周实验课实验21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第八周实验课实验21View 绘制

void C第八周实验课实验21View::OnDraw(CDC* pDC)
{
	C第八周实验课实验21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	cr.left += p1.x/100;
	cr.top += p1.y/100;
	cr.right += p2.x/100;
	cr.bottom += p2.y/100;
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第八周实验课实验21View 打印

BOOL C第八周实验课实验21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第八周实验课实验21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第八周实验课实验21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第八周实验课实验21View 诊断

#ifdef _DEBUG
void C第八周实验课实验21View::AssertValid() const
{
	CView::AssertValid();
}

void C第八周实验课实验21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第八周实验课实验21Doc* C第八周实验课实验21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第八周实验课实验21Doc)));
	return (C第八周实验课实验21Doc*)m_pDocument;
}
#endif //_DEBUG


// C第八周实验课实验21View 消息处理程序


void C第八周实验课实验21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = 1;
	p1 = point;
	p2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void C第八周实验课实验21View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set = 1)
	{
		p2 = point;
		
	}Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void C第八周实验课实验21View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = 0;
	CView::OnLButtonUp(nFlags, point);
}
