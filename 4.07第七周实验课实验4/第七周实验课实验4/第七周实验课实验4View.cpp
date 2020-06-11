
// 第七周实验课实验4View.cpp : C第七周实验课实验4View 类的实现
//

#include "stdafx.h"
#include "MyDlg.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第七周实验课实验4.h"
#endif

#include "第七周实验课实验4Doc.h"
#include "第七周实验课实验4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第七周实验课实验4View

IMPLEMENT_DYNCREATE(C第七周实验课实验4View, CView)

BEGIN_MESSAGE_MAP(C第七周实验课实验4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDOK, &C第七周实验课实验4View::OnOk)
	ON_COMMAND(ID_ShowDlg, &C第七周实验课实验4View::OnShowdlg)
END_MESSAGE_MAP()

// C第七周实验课实验4View 构造/析构

C第七周实验课实验4View::C第七周实验课实验4View()
{
	// TODO: 在此处添加构造代码

}

C第七周实验课实验4View::~C第七周实验课实验4View()
{
}

BOOL C第七周实验课实验4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第七周实验课实验4View 绘制

void C第七周实验课实验4View::OnDraw(CDC* /*pDC*/)
{
	C第七周实验课实验4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第七周实验课实验4View 打印

BOOL C第七周实验课实验4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第七周实验课实验4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第七周实验课实验4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第七周实验课实验4View 诊断

#ifdef _DEBUG
void C第七周实验课实验4View::AssertValid() const
{
	CView::AssertValid();
}

void C第七周实验课实验4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第七周实验课实验4Doc* C第七周实验课实验4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第七周实验课实验4Doc)));
	return (C第七周实验课实验4Doc*)m_pDocument;
}
#endif //_DEBUG


// C第七周实验课实验4View 消息处理程序


void C第七周实验课实验4View::OnOk()
{

	// TODO: 在此添加控件通知处理程序代码
}


void C第七周实验课实验4View::OnShowdlg()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
	// TODO: 在此添加命令处理程序代码
}
