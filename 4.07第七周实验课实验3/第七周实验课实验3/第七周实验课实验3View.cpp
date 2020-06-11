
// 第七周实验课实验3View.cpp : C第七周实验课实验3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第七周实验课实验3.h"
#endif

#include "第七周实验课实验3Doc.h"
#include "第七周实验课实验3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第七周实验课实验3View

IMPLEMENT_DYNCREATE(C第七周实验课实验3View, CView)

BEGIN_MESSAGE_MAP(C第七周实验课实验3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C第七周实验课实验3View 构造/析构

C第七周实验课实验3View::C第七周实验课实验3View()
{
	// TODO: 在此处添加构造代码
	flag1 = 0;
	flag2 = 0;
	flag3 = 1;
}

C第七周实验课实验3View::~C第七周实验课实验3View()
{
}

BOOL C第七周实验课实验3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第七周实验课实验3View 绘制

void C第七周实验课实验3View::OnDraw(CDC* pDC)
{
	C第七周实验课实验3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&cr1);
	if (cr.top != cr1.Height() / 2 - 50)
	{
		cr.top = cr1.Height() / 2 - 50;
		cr.bottom = cr1.Height() / 2 + 50;
	}
	if (flag3)
	{
		cr.left = 0;
		cr.top = cr1.Height() / 2 - 50;
		cr.right = 100;
		cr.bottom = cr1.Height() / 2 + 50;
		flag3 = 0;
	}
	SetTimer(0, 100, NULL);
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第七周实验课实验3View 打印

BOOL C第七周实验课实验3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第七周实验课实验3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第七周实验课实验3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第七周实验课实验3View 诊断

#ifdef _DEBUG
void C第七周实验课实验3View::AssertValid() const
{
	CView::AssertValid();
}

void C第七周实验课实验3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第七周实验课实验3Doc* C第七周实验课实验3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第七周实验课实验3Doc)));
	return (C第七周实验课实验3Doc*)m_pDocument;
}
#endif //_DEBUG


// C第七周实验课实验3View 消息处理程序


void C第七周实验课实验3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag2 = 1;
	CView::OnLButtonDown(nFlags, point);
}


void C第七周实验课实验3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag2 = 0;
	CView::OnLButtonDblClk(nFlags, point);
}


void C第七周实验课实验3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认
	GetClientRect(&cr1);
	if (flag2)
	{
		if (flag1 == 0)
		{
			cr.left += 50;
			cr.right += 50;
			Invalidate();
			if (cr.right >= cr1.right)
				flag1 = 1;
		}
		else
		{
			cr.left -= 50;
			cr.right -= 50;
			Invalidate();
			if (cr.left <= cr1.left)
				flag1 = 0;
		}
	}
	CView::OnTimer(nIDEvent);
}
