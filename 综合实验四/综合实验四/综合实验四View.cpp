
// 综合实验四View.cpp : C综合实验四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验四.h"
#endif

#include "综合实验四Set.h"
#include "综合实验四Doc.h"
#include "综合实验四View.h"
#include "PIC_DLG.h"
#include "Adddlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验四View

IMPLEMENT_DYNCREATE(C综合实验四View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验四View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验四View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验四View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验四View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验四View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON6, &C综合实验四View::OnShowPicture)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON7, &C综合实验四View::OnReturn)
	ON_COMMAND(ID_Add, &C综合实验四View::OnAdd)
	ON_COMMAND(ID_Sort, &C综合实验四View::OnSort)
	ON_COMMAND(ID_Select, &C综合实验四View::OnSelect)
	ON_COMMAND(ID_mod, &C综合实验四View::Onmod)
END_MESSAGE_MAP()

// C综合实验四View 构造/析构

C综合实验四View::C综合实验四View()
	: CRecordView(IDD_MY_FORM)
	, num(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, money(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验四View::~C综合实验四View()
{
}

void C综合实验四View::DoDataExchange(CDataExchange* pDX)
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
}

BOOL C综合实验四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验四View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验四Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验四View 诊断

#ifdef _DEBUG
void C综合实验四View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验四View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验四Doc* C综合实验四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验四Doc)));
	return (C综合实验四Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验四View 数据库支持
CRecordset* C综合实验四View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验四View 消息处理程序


void C综合实验四View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveLast();
	}
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::OnRecordLast()
{
	m_pSet->MoveLast();
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::OnShowPicture()
{
	PIC_DLG dlg;
	dlg.path = m_pSet->m_3;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验四View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();

	CImage img;
	CString filename;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_picture为picture控件ID
	pWnd->GetClientRect(&rect);//rc为控件的大小
	filename = _T("C:\\大二下\\实验\\学生照片");
	img.Load(filename +m_pSet->m_3);
	if (img)
	{
		int w, h, sx, sy;
		float r_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
		if (r_ratio > img_ratio)
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
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}//Null
	else
	{
		pDC->TextOutW(20, 20, _T("图片不存在"));
	}
	img.Destroy();
	ReleaseDC(pDC);//释放DC 注意获取后必须释放
}


void C综合实验四View::OnReturn()
{

	// TODO: 在此添加控件通知处理程序代码
}


void C综合实验四View::OnAdd()
{
	Adddlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		if (!dlg.Num.IsEmpty())
		{
			m_pSet->AddNew();
			m_pSet->m_1 = dlg.Num;
			m_pSet->m_2 = dlg.Name;
			m_pSet->m_3 = dlg.PicPath;
			m_pSet->m_4 = dlg.Money;
			m_pSet->Update();
			UpdateData(false);
		}
		else
			MessageBox(_T("未填入主键"));
	}
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::OnSort()
{
	SortDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), dlg.sort);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::OnSelect()
{
	SelectDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

		m_pSet->m_strFilter.Format(_T("%s"), dlg.search);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: 在此添加命令处理程序代码
}


void C综合实验四View::Onmod()
{
	Traversal_Dlg dlg;
	int n, i;
	CString str, s;

	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())

	{
		n = m_pSet->GetODBCFieldCount();


		for (i = 1; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, str);
			s += _T(" ") + str;
		}
		s += _T("\r\n");
		dlg.trav = s;
		UpdateData(false);
		m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}
	// TODO: 在此添加命令处理程序代码
}
