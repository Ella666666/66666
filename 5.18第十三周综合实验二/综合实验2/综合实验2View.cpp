
// �ۺ�ʵ��2View.cpp : C�ۺ�ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ��2.h"
#endif

#include "�ۺ�ʵ��2Set.h"
#include "�ۺ�ʵ��2Doc.h"
#include "�ۺ�ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��2View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ��2View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ��2View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ۺ�ʵ��2View::OnShowPicture)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ��2View::OnRecordFirst)
END_MESSAGE_MAP()

// C�ۺ�ʵ��2View ����/����

C�ۺ�ʵ��2View::C�ۺ�ʵ��2View()
	: CRecordView(IDD_MY2_FORM)
	, picture(_T(""))
{
	m_pSet = NULL;
	flag = 0;
	path = _T("C:\\�����\\ʵ��\\ѧ����Ƭ\\");
	// TODO: �ڴ˴���ӹ������

}
void C�ۺ�ʵ��2View::foo(CImage& img, int& sx, int& sy, int& w, int& h)
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
C�ۺ�ʵ��2View::~C�ۺ�ʵ��2View()
{
}

void C�ۺ�ʵ��2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C�ۺ�ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ��2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ��2Set;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ��2View ���

#ifdef _DEBUG
void C�ۺ�ʵ��2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ��2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ��2Doc* C�ۺ�ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ��2Doc)));
	return (C�ۺ�ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ��2View ���ݿ�֧��
CRecordset* C�ۺ�ʵ��2View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ��2View ��Ϣ�������


void C�ۺ�ʵ��2View::OnShowPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	m_pSet->GetFieldValue(short(4), s);
	img.Load(s);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void C�ۺ�ʵ��2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	if (flag)
	{
		CString s;
		CImage img;
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//�����õ�getdc�����ͷ���
		pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
		m_pSet->GetFieldValue(short(4), s);

		img.Load(s);

		int sx, sy, w, h;
		foo(img, sx, sy, w, h);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}
}

void C�ۺ�ʵ��2View::drawpicture(CString file)
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

void C�ۺ�ʵ��2View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	drawpicture(_T("C:\\�����\\ʵ��\\ѧ����Ƭ\\JZYL2.jpg"));
	// TODO: �ڴ���������������
}
