
// 第九周课堂实验1）View.cpp : C第九周课堂实验1）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第九周课堂实验1）.h"
#endif

#include "第九周课堂实验1）Doc.h"
#include "第九周课堂实验1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <fstream>
#include <string>
#include <iostream>
#include "MyDlg.h"
using namespace std;

// C第九周课堂实验1）View

IMPLEMENT_DYNCREATE(C第九周课堂实验1）View, CView)

BEGIN_MESSAGE_MAP(C第九周课堂实验1）View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWDIALOG, &C第九周课堂实验1）View::OnShowdialog)
	ON_COMMAND(ID_FILE_OPEN, &C第九周课堂实验1）View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &C第九周课堂实验1）View::OnFileSave)
	ON_BN_CLICKED(IDC_BUTTON1, &C第九周课堂实验1）View::OnShowPicture)
END_MESSAGE_MAP()

// C第九周课堂实验1）View 构造/析构

C第九周课堂实验1）View::C第九周课堂实验1）View()
{
	// TODO: 在此处添加构造代码

}

C第九周课堂实验1）View::~C第九周课堂实验1）View()
{
}

BOOL C第九周课堂实验1）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第九周课堂实验1）View 绘制

void C第九周课堂实验1）View::OnDraw(CDC* /*pDC*/)
{
	C第九周课堂实验1）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第九周课堂实验1）View 打印

BOOL C第九周课堂实验1）View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第九周课堂实验1）View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第九周课堂实验1）View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第九周课堂实验1）View 诊断

#ifdef _DEBUG
void C第九周课堂实验1）View::AssertValid() const
{
	CView::AssertValid();
}

void C第九周课堂实验1）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第九周课堂实验1）Doc* C第九周课堂实验1）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第九周课堂实验1）Doc)));
	return (C第九周课堂实验1）Doc*)m_pDocument;
}
#endif //_DEBUG


// C第九周课堂实验1）View 消息处理程序


void C第九周课堂实验1）View::OnShowdialog()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	filename = cfd.GetPathName();
	dc.TextOutW(0, 0, filename);
	if (r == IDOK)
	{
		ifstream ifs(filename);
		string s;
		ifs >> s;
		ofstream ofs(cfd.GetPathName());
		CString ss = cfd.GetPathName();
		ofs << CT2A(ss.GetString()) << endl;

	}
	
}


void C第九周课堂实验1）View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		while (ifs >> s)
		{
			CString str;
			str = CString(s.c_str());
			CClientDC dc(this);
			dc.TextOutW(200, 200, CString(s.c_str()));

		}

	}
	// TODO: 在此添加命令处理程序代码
}


void C第九周课堂实验1）View::OnFileSave()
{
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(filename);
		CString s = filename;
		ofs << filename << endl;
		ofs << CT2A(s.GetString()) << endl;


	}
	// TODO: 在此添加命令处理程序代码
}


void C第九周课堂实验1）View::OnShowPicture()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		CString s;
		s.Format(_T("C:\\Users\\86187\\Desktop\\abc.txt"));
		ofstream ofs(s);
		ofs << CT2A(filename.GetString()) << endl;
	}
	// TODO: 在此添加控件通知处理程序代码
}
