
// 331praView.cpp : CMy331praView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "331pra.h"
#endif

#include "331praDoc.h"
#include "331praView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy331praView

IMPLEMENT_DYNCREATE(CMy331praView, CView)

BEGIN_MESSAGE_MAP(CMy331praView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy331praView 构造/析构

CMy331praView::CMy331praView()
{
	// TODO: 在此处添加构造代码
	m_str = "";
	use = FALSE;
}

CMy331praView::~CMy331praView()
{
}

BOOL CMy331praView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy331praView 绘制

void CMy331praView::OnDraw(CDC* pDC)
{
	CMy331praDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(100, 100, 200, 200);
	pDC->BeginPath();
	
	pDC->EndPath();
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy331praView 打印

BOOL CMy331praView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy331praView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy331praView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy331praView 诊断

#ifdef _DEBUG
void CMy331praView::AssertValid() const
{
	CView::AssertValid();
}

void CMy331praView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy331praDoc* CMy331praView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy331praDoc)));
	return (CMy331praDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy331praView 消息处理程序


int CMy331praView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	ShowCaret();
	return 0;
}


void CMy331praView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_str.Empty();
	m_ptr = point;
	use = TRUE;
	CView::OnLButtonDown(nFlags, point);
}


void CMy331praView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d== nChar)
	{
		m_str.Empty();
		m_ptr.y += tm.tmHeight;
	}
	else if (0x08 == nChar)
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(m_ptr.x, m_ptr.y, m_str);
		m_str = m_str.Left(m_str.GetLength() - 1);
		dc.SetTextColor(clr);
	}
	else 
	{ 
		m_str += char(nChar);
	}
	CSize sz = dc.GetTextExtent(m_str);
	CPoint pt;
	pt.x = m_ptr.x + sz.cx;
	pt.y = m_ptr.y;
	SetCaretPos(pt);
	dc.TextOut(m_ptr.x, m_ptr.y, m_str);
	CView::OnChar(nChar, nRepCnt, nFlags);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
