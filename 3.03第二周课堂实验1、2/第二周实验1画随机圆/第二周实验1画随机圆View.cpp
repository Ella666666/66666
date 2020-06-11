
// 第二周实验1画随机圆View.cpp : C第二周实验1画随机圆View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验1画随机圆.h"
#endif

#include "第二周实验1画随机圆Doc.h"
#include "第二周实验1画随机圆View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验1画随机圆View

IMPLEMENT_DYNCREATE(C第二周实验1画随机圆View, CView)

BEGIN_MESSAGE_MAP(C第二周实验1画随机圆View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第二周实验1画随机圆View 构造/析构

C第二周实验1画随机圆View::C第二周实验1画随机圆View()
{
	// TODO: 在此处添加构造代码
	m_nBubbleCount = 0;
}

C第二周实验1画随机圆View::~C第二周实验1画随机圆View()
{
}

BOOL C第二周实验1画随机圆View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}
void C第二周实验1画随机圆View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int  r = rand() % 50 + 10;
	CRect  rect(point.x - r, point.y - r, point.x + r, point.y + r);
	if (m_nBubbleCount<MAX_BUBBLE)
	{
		m_rectBubble[m_nBubbleCount] = rect;
		m_nBubbleCount++;
	}
	InvalidateRect(rect, FALSE);
	CView::OnLButtonDown(nFlags, point);
}
// C第二周实验1画随机圆View 绘制

void C第二周实验1画随机圆View::OnDraw(CDC* pDC)
{
	C第二周实验1画随机圆Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i<m_nBubbleCount; i++)
	pDC->Ellipse(m_rectBubble[i]);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第二周实验1画随机圆View 打印

BOOL C第二周实验1画随机圆View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第二周实验1画随机圆View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第二周实验1画随机圆View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第二周实验1画随机圆View 诊断

#ifdef _DEBUG
void C第二周实验1画随机圆View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验1画随机圆View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验1画随机圆Doc* C第二周实验1画随机圆View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验1画随机圆Doc)));
	return (C第二周实验1画随机圆Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验1画随机圆View 消息处理程序



