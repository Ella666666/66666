
// 413实验View.cpp : CMy413实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "413实验.h"
#endif

#include "413实验Doc.h"
#include "413实验View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define Trans(p1, rect) CPoint(long((p1.x+0.5)/1) - rect.Width()/2, long((p1.y+0.5)/1) - rect.Height()/2)
// CMy413实验View

IMPLEMENT_DYNCREATE(CMy413实验View, CView)

BEGIN_MESSAGE_MAP(CMy413实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &CMy413实验View::OnPopout)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy413实验View 构造/析构

CMy413实验View::CMy413实验View()
{
	// TODO: 在此处添加构造代码
	m_IsREadyToMove = false;
	p1 = 0;
	CPen Blackpen(0, 1, RGB(0, 0, 0));
	m_Points[0] = CPoint(121, 100);
	m_Points[1] = CPoint(367, 100);
	m_Points[2] = CPoint(367, 245);
	m_Points[3] = CPoint(121, 245);
	m_CurrentPen = &Blackpen;
}


CMy413实验View::~CMy413实验View()
{
}

BOOL CMy413实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy413实验View 绘制
void CMy413实验View::DrawObject(CDC* pDC, const CRect& rect) 
{
	int i = 0;
	CPen * oldPen = pDC->SelectObject(m_CurrentPen);

	// 画出矩形
	pDC->Rectangle(CRect(Trans(m_Points[0], rect), Trans(m_Points[2], rect)));
	pDC->SelectObject(oldPen);

}

void CMy413实验View::OnDraw(CDC* pDC)
{
	CMy413实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

	CDC memDC;  // 声明内存DC
	CBitmap NewBitmap, *pOldBitmap;
	memDC.CreateCompatibleDC(pDC);  // 创建一个与显示DC兼容的内存DC 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());     // 创建兼容内存位图 
	pOldBitmap = memDC.SelectObject(&NewBitmap);    // 将兼容位图选入内存DC
	memDC.FillSolidRect(rect, pDC->GetBkColor());   // 按原来背景色填充客户区，否则是黑色
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	memDC.SetROP2(R2_COPYPEN); // 设置绘图方式

	DrawObject(&memDC, rect);  // 画矩形的代码在这一个函数里

							   // 将内存DC中的位图拷贝到设备DC
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);

	// TODO: 在此处为本机数据添加绘制代码
}




// CMy413实验View 打印

BOOL CMy413实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy413实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy413实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}





// CMy413实验View 诊断

#ifdef _DEBUG
void CMy413实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMy413实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy413实验Doc* CMy413实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy413实验Doc)));
	return (CMy413实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy413实验View 消息处理程序


void CMy413实验View::OnPopout()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int R, X, Y;
		R = dlg.r;
		X = dlg.x;
		Y = dlg.y;
		CRect cr(X - R, Y - R, X + R, Y + R);
		GetDC()->Ellipse(cr);
	}
	// TODO: 在此添加命令处理程序代码
}





void CMy413实验View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	CPen RedPen(1, 1, RGB(0, 0, 0));
	 m_IsREadyToMove = false;   // 初始标记一下不能移动
	if (m_Points[0].x <= point.x && point.x <= m_Points[2].x &&
		m_Points[0].y <= point.y && point.y <= m_Points[2].y)
	{
		p1 = point;
		m_IsREadyToMove = true; // 标记一下可以移动了
		m_CurrentPen = &RedPen;

		SetCapture();           // 设置鼠标捕获   
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // 设置光标为八个方向
	}
	// 触发OnDraw函数，动态效果
	Invalidate(FALSE);
	CView::OnLButtonDown(nFlags, point);
}


void CMy413实验View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPen Blackpen(0, 1, RGB(0, 0, 0));
	if (true == m_IsREadyToMove)
	{
		m_CurrentPen = &Blackpen;   // 修改画笔颜色为黑色
		p1 = NULL;      // 清空移动信息
	}
	ReleaseCapture(); // 释放鼠标捕获
	m_IsREadyToMove = false;   // 标记一下此时不可以移动了
							   // 触发OnDraw函数，动态效果
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy413实验View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (true == m_IsREadyToMove)
	{
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // 设置光标为八个方向   
												  // 利用当前鼠标位置和初始记录的位置来修改矩形的每个顶点，做到图随鼠标动的效果
		for (int i = 0; i < 4; i++)
		{
			m_Points[i] += point - p1;
		}
		p1 = point;
	}
	// 触发OnDraw函数，动态效果
	Invalidate(FALSE);
	
	CView::OnMouseMove(nFlags, point);
}
