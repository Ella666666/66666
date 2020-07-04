
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
#include "EnlargeDlg.h"
#include "A���ģ��.h"
#include "ModDlg.h"
#include "SortDlg.h"
#include "SelectDlg.h"
#include "ErgodicDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ����View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ����View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ����View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ����View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ����View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ����View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ����View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON9, &C�ۺ�ʵ����View::OnEnlarge)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON11, &C�ۺ�ʵ����View::OnBnClickedADD)
	ON_BN_CLICKED(IDC_BUTTON13, &C�ۺ�ʵ����View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON12, &C�ۺ�ʵ����View::OnBnClickedMod)
	ON_COMMAND(ID_Sort, &C�ۺ�ʵ����View::OnSort)
	ON_COMMAND(ID_Select, &C�ۺ�ʵ����View::OnSelect)
	ON_BN_CLICKED(IDC_BUTTON10, &C�ۺ�ʵ����View::OnBnClickedRecover)
	ON_COMMAND(ID_Ergodic, &C�ۺ�ʵ����View::OnErgodic)
END_MESSAGE_MAP()

// C�ۺ�ʵ����View ����/����

C�ۺ�ʵ����View::C�ۺ�ʵ����View()
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
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->m_8);
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


// C�ۺ�ʵ����View ��ӡ

BOOL C�ۺ�ʵ����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ۺ�ʵ����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ۺ�ʵ����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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
	UpdateData(false);
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	// TODO: �ڴ���������������
}
void  C�ۺ�ʵ����View::draw_pic(CString filename)
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

void C�ۺ�ʵ����View::OnDraw(CDC* pDC)
{
	// TODO: �ڴ����ר�ô����/����û���
	filepath = m_pSet->m_8;
	draw_pic(filepath);
}

void C�ۺ�ʵ����View::OnEnlarge()
{
	EnlargeDlg dlg;
	dlg.filepath = m_pSet->m_8;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	draw_pic(filepath);
}


void C�ۺ�ʵ����View::OnBnClickedADD()
{
	A���ģ�� dlg;
	
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnBnClickedDelete()
{
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnBnClickedMod()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnSort()
{
	SortDlg sdlg;
	int r = sdlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), sdlg.sort);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnSelect()
{
	SelectDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), dlg.sele);
		m_pSet->Requery();
		UpdateData(false);
	}
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ����View::OnBnClickedRecover()
{
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ����View::OnErgodic()
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
	// TODO: �ڴ���������������
}
