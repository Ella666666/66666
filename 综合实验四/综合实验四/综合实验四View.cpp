
// �ۺ�ʵ����View.cpp : C�ۺ�ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ����.h"
#endif

#include "�ۺ�ʵ����Set.h"
#include "�ۺ�ʵ����Doc.h"
#include "�ۺ�ʵ����View.h"
#include "PIC_DLG.h"
#include "Adddlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ����View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ����View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ����View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ����View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ����View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ����View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ����View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON6, &C�ۺ�ʵ����View::OnShowPicture)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON7, &C�ۺ�ʵ����View::OnReturn)
	ON_COMMAND(ID_Add, &C�ۺ�ʵ����View::OnAdd)
	ON_COMMAND(ID_Sort, &C�ۺ�ʵ����View::OnSort)
	ON_COMMAND(ID_Select, &C�ۺ�ʵ����View::OnSelect)
	ON_COMMAND(ID_mod, &C�ۺ�ʵ����View::Onmod)
END_MESSAGE_MAP()

// C�ۺ�ʵ����View ����/����

C�ۺ�ʵ����View::C�ۺ�ʵ����View()
	: CRecordView(IDD_MY_FORM)
	, num(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, money(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C�ۺ�ʵ����View::~C�ۺ�ʵ����View()
{
}

void C�ۺ�ʵ����View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL C�ۺ�ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ����View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ����Set;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ����View ���

#ifdef _DEBUG
void C�ۺ�ʵ����View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ����View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ����Doc* C�ۺ�ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ����Doc)));
	return (C�ۺ�ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ����View ���ݿ�֧��
CRecordset* C�ۺ�ʵ����View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ����View ��Ϣ�������


void C�ۺ�ʵ����View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveLast();
	}
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnRecordLast()
{
	m_pSet->MoveLast();
	InvalidateRect(&rect, true);
	RedrawWindow();
	UpdateData(false);
	
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnShowPicture()
{
	PIC_DLG dlg;
	dlg.path = m_pSet->m_3;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();

	CImage img;
	CString filename;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С
	filename = _T("C:\\�����\\ʵ��\\ѧ����Ƭ");
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
		pDC->TextOutW(20, 20, _T("ͼƬ������"));
	}
	img.Destroy();
	ReleaseDC(pDC);//�ͷ�DC ע���ȡ������ͷ�
}


void C�ۺ�ʵ����View::OnReturn()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnAdd()
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
			MessageBox(_T("δ��������"));
	}
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnSort()
{
	SortDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), dlg.sort);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnSelect()
{
	SelectDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

		m_pSet->m_strFilter.Format(_T("%s"), dlg.search);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::Onmod()
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
	// TODO: �ڴ���������������
}
