
// 414实验1View.cpp : CMy414实验1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "414实验1.h"
#endif

#include "414实验1Doc.h"
#include "414实验1View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy414实验1View

IMPLEMENT_DYNCREATE(CMy414实验1View, CView)

BEGIN_MESSAGE_MAP(CMy414实验1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy414实验1View 构造/析构

CMy414实验1View::CMy414实验1View()
{
	// TODO: 在此处添加构造代码

}

CMy414实验1View::~CMy414实验1View()
{
}

BOOL CMy414实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}



// CMy414实验1View 绘制

void CMy414实验1View::OnDraw(CDC* /*pDC*/)
{
	CMy414实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy414实验1View 打印

BOOL CMy414实验1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy414实验1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy414实验1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy414实验1View 诊断

#ifdef _DEBUG
void CMy414实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy414实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy414实验1Doc* CMy414实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy414实验1Doc)));
	return (CMy414实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy414实验1View 消息处理程序


void CMy414实验1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg md2;
	int r = md2.DoModal();
	if (r == IDOK)
	{
	
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CMy414实验1View::OnBnClickedOpenButton()
{
	TCHAR szFilter[] = _T("ALL File(*.*)|*.*||");	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath; 	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   		
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
		CString s1 = strFilePath;
		GetDC()->TextOutW(200, 100, s1);
	}
}
