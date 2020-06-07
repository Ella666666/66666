
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Set.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication1View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
	: CRecordView(IDD_MFCAPPLICATION1_FORM)
	, pictureName(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\大二下\\实验\\vc\\第十一周\\MFCApplication1\\Debug");
}

CMFCApplication1View::~CMFCApplication1View()
{
}

void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication1Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 数据库支持
CRecordset* CMFCApplication1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication1View 消息处理程序


void CMFCApplication1View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
	GetDlgItem(IDC_EDIT1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT1)->ShowWindow(true);
	OnPaint();
}


void CMFCApplication1View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	GetDlgItem(IDC_EDIT1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT1)->ShowWindow(true);
	OnPaint();
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	GetDlgItem(IDC_EDIT1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT1)->ShowWindow(true);
	OnPaint();
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItem(IDC_EDIT1)->ShowWindow(false);
	GetDlgItem(IDC_EDIT1)->ShowWindow(true);
	OnPaint();
	// TODO: 在此添加命令处理程序代码
}

void CMFCApplication1View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CMFCApplication1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	if (use)
	{
		CString s;
		CImage img;
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		m_pSet->GetFieldValue(short(1), s);
		img.Load(s);
		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}

}
void CMFCApplication1View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}
