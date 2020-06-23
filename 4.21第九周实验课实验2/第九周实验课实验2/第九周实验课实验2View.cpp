
// 第九周实验课实验2View.cpp : C第九周实验课实验2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第九周实验课实验2.h"
#endif

#include "第九周实验课实验2Doc.h"
#include "第九周实验课实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"string"
#include"iostream"
#include"fstream"
using namespace std;

// C第九周实验课实验2View

IMPLEMENT_DYNCREATE(C第九周实验课实验2View, CView)

BEGIN_MESSAGE_MAP(C第九周实验课实验2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_SAVE_AS, &C第九周实验课实验2View::OnFileSaveAs)
	ON_COMMAND(ID_FILE_OPEN, &C第九周实验课实验2View::OnFileOpen)
END_MESSAGE_MAP()

// C第九周实验课实验2View 构造/析构

C第九周实验课实验2View::C第九周实验课实验2View()
{
	// TODO: 在此处添加构造代码
	i = 0;

}

C第九周实验课实验2View::~C第九周实验课实验2View()
{
}

BOOL C第九周实验课实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第九周实验课实验2View 绘制

void C第九周实验课实验2View::OnDraw(CDC* pDC)
{
	C第九周实验课实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第九周实验课实验2View 打印

BOOL C第九周实验课实验2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第九周实验课实验2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第九周实验课实验2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第九周实验课实验2View 诊断

#ifdef _DEBUG
void C第九周实验课实验2View::AssertValid() const
{
	CView::AssertValid();
}

void C第九周实验课实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第九周实验课实验2Doc* C第九周实验课实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第九周实验课实验2Doc)));
	return (C第九周实验课实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// C第九周实验课实验2View 消息处理程序


void C第九周实验课实验2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDC*pDC = GetDC();
	C第九周实验课实验2Doc* pDoc = GetDocument();
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen *oldpen = (CPen*)pDC->SelectObject(&pen);
	    i += 1;
		pDC->Ellipse(pDoc->c[i]);
	CView::OnLButtonDown(nFlags, point);
}


void C第九周实验课实验2View::OnFileSaveAs()
{
	Invalidate();
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());
		C第九周实验课实验2Doc* pDoc = GetDocument();
		for (int i = 0; i < pDoc->c.GetSize(); i++)
		{
			CString s0, s1, s2, s3;
			s0.Format(_T("%d"), pDoc->c[i].top);
			s1.Format(_T("%d"), pDoc->c[i].left);
			s2.Format(_T("%d"), pDoc->c[i].right);
			s3.Format(_T("%d"), pDoc->c[i].bottom);
			ofs << CT2A(s0.GetString()) << " ";
			ofs << CT2A(s1.GetString()) << " ";
			ofs << CT2A(s2.GetString()) << " ";
			ofs << CT2A(s3.GetString()) << " ";
			ofs << endl;
		}


	}
	// TODO: 在此添加命令处理程序代码
}


void C第九周实验课实验2View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CDC* pDC = GetDC();
		C第九周实验课实验2Doc* pDoc = GetDocument();
		for (int i = 0; i < pDoc->c.GetSize(); i++)
		{
			pDC->Ellipse(pDoc->c[i]);

		}
	}
	// TODO: 在此添加命令处理程序代码
}
