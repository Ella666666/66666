
// 第八周实验课实验2.3View.cpp : C第八周实验课实验23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第八周实验课实验2.3.h"
#endif

#include "第八周实验课实验2.3Doc.h"
#include "第八周实验课实验2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第八周实验课实验23View

IMPLEMENT_DYNCREATE(C第八周实验课实验23View, CView)

BEGIN_MESSAGE_MAP(C第八周实验课实验23View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第八周实验课实验23View 构造/析构

C第八周实验课实验23View::C第八周实验课实验23View()
{
	// TODO: 在此处添加构造代码
	cr.left = 100;
	cr.top = 100;
	cr.bottom = 200;
	cr.right = 200;
	set = false;
}

C第八周实验课实验23View::~C第八周实验课实验23View()
{
}

BOOL C第八周实验课实验23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第八周实验课实验23View 绘制

void C第八周实验课实验23View::OnDraw(CDC* pDC)
{
	C第八周实验课实验23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);

	// TODO: 在此处为本机数据添加绘制代码
}


// C第八周实验课实验23View 打印

BOOL C第八周实验课实验23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第八周实验课实验23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第八周实验课实验23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第八周实验课实验23View 诊断

#ifdef _DEBUG
void C第八周实验课实验23View::AssertValid() const
{
	CView::AssertValid();
}

void C第八周实验课实验23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第八周实验课实验23Doc* C第八周实验课实验23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第八周实验课实验23Doc)));
	return (C第八周实验课实验23Doc*)m_pDocument;
}
#endif //_DEBUG


// C第八周实验课实验23View 消息处理程序


void C第八周实验课实验23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x<cr.left||point.x>cr.right||point.y<cr.bottom||point.y>cr.top)
	{
		CDC * dc = GetDC();
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));//虚线	
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//背景透明效果		
		pOldBrush = dc->SelectObject(pBrush);
		CRect rect;	rect.bottom = 200; rect.top = 100; rect.right = 200; rect.left = 100;
		dc->Rectangle(&rect);
		dc->SelectObject(pOldPen);
		pen.DeleteObject();
	}
	CView::OnLButtonDown(nFlags, point);
}
