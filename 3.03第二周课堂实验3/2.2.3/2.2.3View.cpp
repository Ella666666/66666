
// 2.2.3View.cpp : CMy223View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2.2.3.h"
#endif

#include "2.2.3Doc.h"
#include "2.2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy223View

IMPLEMENT_DYNCREATE(CMy223View, CView)

BEGIN_MESSAGE_MAP(CMy223View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy223View 构造/析构

CMy223View::CMy223View()
{
	// TODO: 在此处添加构造代码

}

CMy223View::~CMy223View()
{
}

BOOL CMy223View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy223View 绘制

void CMy223View::OnDraw(CDC* pDC)
{
	CMy223Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPaintDC dc(this);
	CRect cr;//矩形结构
	GetClientRect(&cr);//获得客户区窗口
	int cx = cr.right;//右
	int cy = cr.bottom;//底
	pDC->SetMapMode(MM_ISOTROPIC);//X=Y
	pDC->SetWindowExt(1000, 1000);//设置逻辑窗口，默认窗口原点为（0，0）
	pDC->SetViewportExt(cx, -cy);//定义输出视口,X右Y上为正
	pDC->SetViewportOrg(cx / 2, cy / 2);//定义视口原点为客户区中心
	pDC->Ellipse(-500, 500, 500, -500);//绘制椭圆与客户区外切的椭圆
}


// CMy223View 打印

BOOL CMy223View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy223View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy223View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy223View 诊断

#ifdef _DEBUG
void CMy223View::AssertValid() const
{
	CView::AssertValid();
}

void CMy223View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy223Doc* CMy223View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy223Doc)));
	return (CMy223Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy223View 消息处理程序
