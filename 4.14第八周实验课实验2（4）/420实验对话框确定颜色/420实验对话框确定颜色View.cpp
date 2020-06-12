
// 420实验对话框确定颜色View.cpp : CMy420实验对话框确定颜色View 类的实现
//

#include "stdafx.h"
#include "填充颜色.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "420实验对话框确定颜色.h"
#endif

#include "420实验对话框确定颜色Doc.h"
#include "420实验对话框确定颜色View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy420实验对话框确定颜色View

IMPLEMENT_DYNCREATE(CMy420实验对话框确定颜色View, CView)

BEGIN_MESSAGE_MAP(CMy420实验对话框确定颜色View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_InputRGB, &CMy420实验对话框确定颜色View::OnInputrgb)
END_MESSAGE_MAP()

// CMy420实验对话框确定颜色View 构造/析构

CMy420实验对话框确定颜色View::CMy420实验对话框确定颜色View()
{
	// TODO: 在此处添加构造代码

}

CMy420实验对话框确定颜色View::~CMy420实验对话框确定颜色View()
{
}

BOOL CMy420实验对话框确定颜色View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy420实验对话框确定颜色View 绘制

void CMy420实验对话框确定颜色View::OnDraw(CDC* /*pDC*/)
{
	CMy420实验对话框确定颜色Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy420实验对话框确定颜色View 打印

BOOL CMy420实验对话框确定颜色View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy420实验对话框确定颜色View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy420实验对话框确定颜色View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy420实验对话框确定颜色View 诊断

#ifdef _DEBUG
void CMy420实验对话框确定颜色View::AssertValid() const
{
	CView::AssertValid();
}

void CMy420实验对话框确定颜色View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy420实验对话框确定颜色Doc* CMy420实验对话框确定颜色View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy420实验对话框确定颜色Doc)));
	return (CMy420实验对话框确定颜色Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy420实验对话框确定颜色View 消息处理程序


void CMy420实验对话框确定颜色View::OnInputrgb()
{
	填充颜色 rgb;
	CClientDC dc(this);
	dc.Ellipse(60, 60, 300, 160);
	int t = rgb.DoModal();
	if (t == IDOK)
	{	
	    CBrush *b = new CBrush(RGB(rgb.x, rgb.y, rgb.z));
	    dc.SelectObject(b);
		dc.Ellipse(60, 60, 300, 160);
	}
	// TODO: 在此添加命令处理程序代码
}
