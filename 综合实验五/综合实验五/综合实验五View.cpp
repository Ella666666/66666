
// 综合实验五View.cpp : C综合实验五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验五.h"
#endif

#include "综合实验五Set.h"
#include "综合实验五Doc.h"
#include "综合实验五View.h"
#include "EnlargeDlg.h"
#include "AｄｄＤｌｇ.h"
#include "ModDlg.h"
#include "SortDlg.h"
#include "SelectDlg.h"
#include "ErgodicDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验五View

IMPLEMENT_DYNCREATE(C综合实验五View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验五View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验五View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验五View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验五View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验五View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON9, &C综合实验五View::OnEnlarge)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON11, &C综合实验五View::OnBnClickedADD)
	ON_BN_CLICKED(IDC_BUTTON13, &C综合实验五View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON12, &C综合实验五View::OnBnClickedMod)
	ON_COMMAND(ID_Sort, &C综合实验五View::OnSort)
	ON_COMMAND(ID_Select, &C综合实验五View::OnSelect)
	ON_BN_CLICKED(IDC_BUTTON10, &C综合实验五View::OnBnClickedRecover)
	ON_COMMAND(ID_Ergodic, &C综合实验五View::OnErgodic)
END_MESSAGE_MAP()

// C综合实验五View 构造/析构

C综合实验五View::C综合实验五View()
	: CRecordView(IDD_MY_FORM)
	, name(_T(""))
	, num(_T(""))
	, specia(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, picpath(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验五View::~C综合实验五View()
{
}

void C综合实验五View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->m_8);
}

BOOL C综合实验五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验五View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验五Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验五View 打印

BOOL C综合实验五View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C综合实验五View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C综合实验五View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C综合实验五View 诊断

#ifdef _DEBUG
void C综合实验五View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验五View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验五Doc* C综合实验五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验五Doc)));
	return (C综合实验五Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验五View 数据库支持
CRecordset* C综合实验五View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验五View 消息处理程序


void C综合实验五View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验五View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验五View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验五View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}
void  C综合实验五View::draw_pic(CString filename)
{
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();

	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}

void C综合实验五View::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	filepath = m_pSet->m_8;
	draw_pic(filepath);
}

void C综合实验五View::OnEnlarge()
{
	EnlargeDlg dlg;
	dlg.filepath = m_pSet->m_8;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验五View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	draw_pic(filepath);
}


void C综合实验五View::OnBnClickedADD()
{
	AｄｄＤｌｇ dlg;
	
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_1 = dlg.name2;
		m_pSet->m_2 = dlg.num2;
		m_pSet->m_3 = dlg.specia2;
		m_pSet->m_4 = dlg.sex;
		m_pSet->m_5 = dlg.birth2;
		m_pSet->m_6 = dlg.phone2;
		m_pSet->m_7 = dlg.address;
		m_pSet->m_8 = dlg.picpath2;
		m_pSet->Update();
		UpdateData(false);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验五View::OnBnClickedDelete()
{
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验五View::OnBnClickedMod()
{
	ModDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->Edit();
		m_pSet->AddNew();
		m_pSet->m_1 = dlg.name1;
		m_pSet->m_2 = dlg.num1;
		m_pSet->m_3 = dlg.specia1;
		m_pSet->m_4 = dlg.sex1;
		m_pSet->m_5 = dlg.birth1;
		m_pSet->m_6 = dlg.phone;
		m_pSet->m_7 = dlg.address1;
		m_pSet->m_8 = dlg.picpath1;
		m_pSet->Update();
		UpdateData(false);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验五View::OnSort()
{
	SortDlg sdlg;
	int r = sdlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), sdlg.sort);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: 在此添加命令处理程序代码
}


void C综合实验五View::OnSelect()
{
	SelectDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), dlg.sele);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: 在此添加命令处理程序代码
}


void C综合实验五View::OnBnClickedRecover()
{
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验五View::OnErgodic()
{
	ErgodicDlg dlg;
	int n, i;
	CString ss, s;
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		n = m_pSet->GetODBCFieldCount();
		for (i = 1; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, ss);
			s += _T(" ") + ss;
		}
		s += _T("\r\n");
		dlg.er = s;
		UpdateData(false);
		m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}
	// TODO: 在此添加命令处理程序代码
}
