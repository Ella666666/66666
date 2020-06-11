
// 2.2.4View.cpp : CMy224View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2.2.4.h"
#endif

#include "2.2.4Doc.h"
#include "2.2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy224View

IMPLEMENT_DYNCREATE(CMy224View, CView)

BEGIN_MESSAGE_MAP(CMy224View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy224View 构造/析构

CMy224View::CMy224View()
{
	// TODO: 在此处添加构造代码

}

CMy224View::~CMy224View()
{
}

BOOL CMy224View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy224View 绘制

void CMy224View::OnDraw(CDC* pDC)
{
	CMy224Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC = GetDC();
	CBrush brush(RGB(255, 0, 0));
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//选新的画刷
	pDC->Ellipse(100, 100, 500, 500);

}


// CMy224View 打印

BOOL CMy224View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy224View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy224View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy224View 诊断

#ifdef _DEBUG
void CMy224View::AssertValid() const
{
	CView::AssertValid();
}

void CMy224View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy224Doc* CMy224View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy224Doc)));
	return (CMy224Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy224View 消息处理程序
