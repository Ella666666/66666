
// ��ʮһ�ܿ���ʵ��2View.cpp : C��ʮһ�ܿ���ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮһ�ܿ���ʵ��2.h"
#endif

#include "��ʮһ�ܿ���ʵ��2Set.h"
#include "��ʮһ�ܿ���ʵ��2Doc.h"
#include "��ʮһ�ܿ���ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ�ܿ���ʵ��2View

IMPLEMENT_DYNCREATE(C��ʮһ�ܿ���ʵ��2View, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮһ�ܿ���ʵ��2View, CRecordView)
END_MESSAGE_MAP()

// C��ʮһ�ܿ���ʵ��2View ����/����

C��ʮһ�ܿ���ʵ��2View::C��ʮһ�ܿ���ʵ��2View()
	: CRecordView(IDD_MY2_FORM)
	, id(0)
	, name(_T(""))
	, num(_T(""))
	, year(0)
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ʮһ�ܿ���ʵ��2View::~C��ʮһ�ܿ���ʵ��2View()
{
}

void C��ʮһ�ܿ���ʵ��2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL C��ʮһ�ܿ���ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮһ�ܿ���ʵ��2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ʮһ�ܿ���ʵ��2Set;
	CRecordView::OnInitialUpdate();

}


// C��ʮһ�ܿ���ʵ��2View ���

#ifdef _DEBUG
void C��ʮһ�ܿ���ʵ��2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮһ�ܿ���ʵ��2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮһ�ܿ���ʵ��2Doc* C��ʮһ�ܿ���ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮһ�ܿ���ʵ��2Doc)));
	return (C��ʮһ�ܿ���ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮһ�ܿ���ʵ��2View ���ݿ�֧��
CRecordset* C��ʮһ�ܿ���ʵ��2View::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮһ�ܿ���ʵ��2View ��Ϣ�������
