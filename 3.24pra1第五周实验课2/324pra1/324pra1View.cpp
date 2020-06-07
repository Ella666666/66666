
// 324pra1View.cpp : CMy324pra1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "324pra1.h"
#endif

#include "324pra1Doc.h"
#include "324pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy324pra1View

IMPLEMENT_DYNCREATE(CMy324pra1View, CView)

BEGIN_MESSAGE_MAP(CMy324pra1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWNAME, &CMy324pra1View::OnShowname)
	ON_COMMAND(ID_Line, &CMy324pra1View::OnLine)
	ON_COMMAND(ID_Rectangle, &CMy324pra1View::OnRectangle)
	ON_COMMAND(ID_Ellipse, &CMy324pra1View::OnEllipse)
END_MESSAGE_MAP()

// CMy324pra1View 构造/析构

CMy324pra1View::CMy324pra1View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CMy324pra1View::~CMy324pra1View()
{
}

BOOL CMy324pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy324pra1View 绘制

void CMy324pra1View::OnDraw(CDC* pDC)
{
	CMy324pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy324pra1View 打印

BOOL CMy324pra1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy324pra1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy324pra1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy324pra1View 诊断

#ifdef _DEBUG
void CMy324pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy324pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy324pra1Doc* CMy324pra1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy324pra1Doc)));
	return (CMy324pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy324pra1View 消息处理程序


void CMy324pra1View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("李扬云");
	CClientDC dc(this);
	dc.TextOutW(500, 500, s);

}


void CMy324pra1View::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	dc.LineTo(50, 50);
}


void CMy324pra1View::OnRectangle()
{
	// TODO: 在此添加命令处理程序
	CClientDC dc(this);
	dc.Rectangle(500, 500, 1200, 1150);
}


void CMy324pra1View::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	dc.Ellipse(1050, 1250, 1500, 1050);
}
