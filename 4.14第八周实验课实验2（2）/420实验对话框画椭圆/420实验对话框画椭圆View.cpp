
// 420实验对话框画椭圆View.cpp : CMy420实验对话框画椭圆View 类的实现
//

#include "stdafx.h"
#include "DrawEllipse.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "420实验对话框画椭圆.h"
#endif

#include "420实验对话框画椭圆Doc.h"
#include "420实验对话框画椭圆View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy420实验对话框画椭圆View

IMPLEMENT_DYNCREATE(CMy420实验对话框画椭圆View, CView)

BEGIN_MESSAGE_MAP(CMy420实验对话框画椭圆View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_InputPoint, &CMy420实验对话框画椭圆View::OnInputpoint)
END_MESSAGE_MAP()

// CMy420实验对话框画椭圆View 构造/析构

CMy420实验对话框画椭圆View::CMy420实验对话框画椭圆View()
{
	// TODO: 在此处添加构造代码

}

CMy420实验对话框画椭圆View::~CMy420实验对话框画椭圆View()
{
}

BOOL CMy420实验对话框画椭圆View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy420实验对话框画椭圆View 绘制

void CMy420实验对话框画椭圆View::OnDraw(CDC* pDC)
{
	CMy420实验对话框画椭圆Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy420实验对话框画椭圆View 打印

BOOL CMy420实验对话框画椭圆View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy420实验对话框画椭圆View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy420实验对话框画椭圆View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy420实验对话框画椭圆View 诊断

#ifdef _DEBUG
void CMy420实验对话框画椭圆View::AssertValid() const
{
	CView::AssertValid();
}

void CMy420实验对话框画椭圆View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy420实验对话框画椭圆Doc* CMy420实验对话框画椭圆View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy420实验对话框画椭圆Doc)));
	return (CMy420实验对话框画椭圆Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy420实验对话框画椭圆View 消息处理程序


void CMy420实验对话框画椭圆View::OnInputpoint()
{
	DrawEllipse point;
	int t = point.DoModal();
	if(t==IDOK)
	{
		CRect re(point.x1, point.y1, point.x2, point.y2);
	    GetDC()->Ellipse(re);
	}
	
	// TODO: 在此添加命令处理程序代码
}
