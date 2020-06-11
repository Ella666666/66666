
// 第四周实验课实验3View.cpp : C第四周实验课实验3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周实验课实验3.h"
#endif

#include "第四周实验课实验3Doc.h"
#include "第四周实验课实验3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周实验课实验3View

IMPLEMENT_DYNCREATE(C第四周实验课实验3View, CView)

BEGIN_MESSAGE_MAP(C第四周实验课实验3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C第四周实验课实验3View 构造/析构

C第四周实验课实验3View::C第四周实验课实验3View()
{
	// TODO: 在此处添加构造代码
	set = true;N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
		b[i] = false;
	}	
}

C第四周实验课实验3View::~C第四周实验课实验3View()
{
}

BOOL C第四周实验课实验3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周实验课实验3View 绘制

void C第四周实验课实验3View::OnDraw(CDC* pDC)
{
	C第四周实验课实验3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 100 + 50, NULL);
		}
		set = false;
	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C第四周实验课实验3View 打印

BOOL C第四周实验课实验3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第四周实验课实验3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第四周实验课实验3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第四周实验课实验3View 诊断

#ifdef _DEBUG
void C第四周实验课实验3View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周实验课实验3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周实验课实验3Doc* C第四周实验课实验3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周实验课实验3Doc)));
	return (C第四周实验课实验3Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周实验课实验3View 消息处理程序


void C第四周实验课实验3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CRect cl;
	GetClientRect(&cl);
	if (cr[i].bottom >= cl.bottom)
	{
		b[i] = true;
	}
	if (cr[i].top <= cl.top)
	{
		b[i] = false;
	}
	if (b[i])
	{
		cr[i].top -= 20;
		cr[i].bottom -= 20;
	}
	else
	{
		cr[i].top += 20;
		cr[i].bottom += 20;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
