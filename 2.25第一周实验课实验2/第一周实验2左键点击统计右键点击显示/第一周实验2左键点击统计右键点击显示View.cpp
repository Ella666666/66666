
// 第一周实验2左键点击统计右键点击显示View.cpp : C第一周实验2左键点击统计右键点击显示View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第一周实验2左键点击统计右键点击显示.h"
#endif

#include "第一周实验2左键点击统计右键点击显示Doc.h"
#include "第一周实验2左键点击统计右键点击显示View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第一周实验2左键点击统计右键点击显示View

IMPLEMENT_DYNCREATE(C第一周实验2左键点击统计右键点击显示View, CView)

BEGIN_MESSAGE_MAP(C第一周实验2左键点击统计右键点击显示View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C第一周实验2左键点击统计右键点击显示View 构造/析构

C第一周实验2左键点击统计右键点击显示View::C第一周实验2左键点击统计右键点击显示View()
{
	// TODO: 在此处添加构造代码

}

C第一周实验2左键点击统计右键点击显示View::~C第一周实验2左键点击统计右键点击显示View()
{
}

BOOL C第一周实验2左键点击统计右键点击显示View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第一周实验2左键点击统计右键点击显示View 绘制

void C第一周实验2左键点击统计右键点击显示View::OnDraw(CDC* pDC)
{
	C第一周实验2左键点击统计右键点击显示Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第一周实验2左键点击统计右键点击显示View 打印

BOOL C第一周实验2左键点击统计右键点击显示View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第一周实验2左键点击统计右键点击显示View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第一周实验2左键点击统计右键点击显示View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第一周实验2左键点击统计右键点击显示View 诊断

#ifdef _DEBUG
void C第一周实验2左键点击统计右键点击显示View::AssertValid() const
{
	CView::AssertValid();
}

void C第一周实验2左键点击统计右键点击显示View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第一周实验2左键点击统计右键点击显示Doc* C第一周实验2左键点击统计右键点击显示View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第一周实验2左键点击统计右键点击显示Doc)));
	return (C第一周实验2左键点击统计右键点击显示Doc*)m_pDocument;
}
#endif //_DEBUG


// C第一周实验2左键点击统计右键点击显示View 消息处理程序


void C第一周实验2左键点击统计右键点击显示View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第一周实验2左键点击统计右键点击显示Doc* pDoc = GetDocument();
	pDoc->count += 1;


	CView::OnLButtonDown(nFlags, point);
}


void C第一周实验2左键点击统计右键点击显示View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第一周实验2左键点击统计右键点击显示Doc* pDoc = GetDocument();
	CClientDC dc(this);	
	CString s;
	s.Format("%d", pDoc->count);
	dc.TextOut(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
