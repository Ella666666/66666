
// 第八周课堂实验1View.cpp : C第八周课堂实验1View 类的实现
//

#include "stdafx.h"
#include "MyDlg.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第八周课堂实验1.h"
#endif

#include "第八周课堂实验1Doc.h"
#include "第八周课堂实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第八周课堂实验1View

IMPLEMENT_DYNCREATE(C第八周课堂实验1View, CView)

BEGIN_MESSAGE_MAP(C第八周课堂实验1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDOK, &C第八周课堂实验1View::OnBnClickedOk)
END_MESSAGE_MAP()

// C第八周课堂实验1View 构造/析构

C第八周课堂实验1View::C第八周课堂实验1View()
{
	// TODO: 在此处添加构造代码
	set = false;
	s = "";
}

C第八周课堂实验1View::~C第八周课堂实验1View()
{
}

BOOL C第八周课堂实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第八周课堂实验1View 绘制

void C第八周课堂实验1View::OnDraw(CDC* pDC)
{
	C第八周课堂实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		MyDlg *dlg = new MyDlg;
		dlg->Create(IDD_DIALOG1);
		dlg->ShowWindow(1);
	}
}


// C第八周课堂实验1View 打印

BOOL C第八周课堂实验1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第八周课堂实验1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第八周课堂实验1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第八周课堂实验1View 诊断

#ifdef _DEBUG
void C第八周课堂实验1View::AssertValid() const
{
	CView::AssertValid();
}

void C第八周课堂实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第八周课堂实验1Doc* C第八周课堂实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第八周课堂实验1Doc)));
	return (C第八周课堂实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// C第八周课堂实验1View 消息处理程序


void C第八周课堂实验1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK)
	{
		s = cfd.GetFileName();
	}
	GetDC()->TextOutW(200, 200, s);
	CView::OnLButtonDblClk(nFlags, point);
}


void C第八周课堂实验1View::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 1;
	
}
