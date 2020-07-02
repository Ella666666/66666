
// 综合实验2View.cpp : C综合实验2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验2.h"
#endif

#include "综合实验2Set.h"
#include "综合实验2Doc.h"
#include "综合实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验2View

IMPLEMENT_DYNCREATE(C综合实验2View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验2View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验2View::OnShowPicture)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验2View::OnRecordFirst)
END_MESSAGE_MAP()

// C综合实验2View 构造/析构

C综合实验2View::C综合实验2View()
	: CRecordView(IDD_MY2_FORM)
	, picture(_T(""))
{
	m_pSet = NULL;
	flag = 0;
	path = _T("C:\\大二下\\实验\\学生照片\\");
	// TODO: 在此处添加构造代码

}
void C综合实验2View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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
C综合实验2View::~C综合实验2View()
{
}

void C综合实验2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C综合实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验2Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验2View 诊断

#ifdef _DEBUG
void C综合实验2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验2Doc* C综合实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验2Doc)));
	return (C综合实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验2View 数据库支持
CRecordset* C综合实验2View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验2View 消息处理程序


void C综合实验2View::OnShowPicture()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
	m_pSet->GetFieldValue(short(4), s);
	img.Load(s);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void C综合实验2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	if (flag)
	{
		CString s;
		CImage img;
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//凡是用到getdc必须释放它
		pDC->SetStretchBltMode(HALFTONE);//图像不失真
		m_pSet->GetFieldValue(short(4), s);

		img.Load(s);

		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}
}

void C综合实验2View::drawpicture(CString file)
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

void C综合实验2View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	drawpicture(_T("C:\\大二下\\实验\\学生照片\\JZYL2.jpg"));
	// TODO: 在此添加命令处理程序代码
}
