
// 第二周实验课1View.cpp : C第二周实验课1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验课1.h"
#endif

#include "第二周实验课1Doc.h"
#include "第二周实验课1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验课1View

IMPLEMENT_DYNCREATE(C第二周实验课1View, CView)

BEGIN_MESSAGE_MAP(C第二周实验课1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C第二周实验课1View 构造/析构

C第二周实验课1View::C第二周实验课1View()
{
	// TODO: 在此处添加构造代码

}

C第二周实验课1View::~C第二周实验课1View()
{
}

BOOL C第二周实验课1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二周实验课1View 绘制

void C第二周实验课1View::OnDraw(CDC* pDC)
{
	C第二周实验课1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	CString S = _T("S:我是***");
	int A = 110;
	CString ss;
	ss.Format("A=%d", A);
	dc.TextOut(200, 200, S);
	dc.TextOut(200, 220, ss);

}


// C第二周实验课1View 打印

BOOL C第二周实验课1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第二周实验课1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第二周实验课1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第二周实验课1View 诊断

#ifdef _DEBUG
void C第二周实验课1View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验课1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验课1Doc* C第二周实验课1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验课1Doc)));
	return (C第二周实验课1Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验课1View 消息处理程序
