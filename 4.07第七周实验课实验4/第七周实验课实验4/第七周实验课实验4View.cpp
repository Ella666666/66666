
// ������ʵ���ʵ��4View.cpp : C������ʵ���ʵ��4View ���ʵ��
//

#include "stdafx.h"
#include "MyDlg.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���ʵ��4.h"
#endif

#include "������ʵ���ʵ��4Doc.h"
#include "������ʵ���ʵ��4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���ʵ��4View

IMPLEMENT_DYNCREATE(C������ʵ���ʵ��4View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���ʵ��4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDOK, &C������ʵ���ʵ��4View::OnOk)
	ON_COMMAND(ID_ShowDlg, &C������ʵ���ʵ��4View::OnShowdlg)
END_MESSAGE_MAP()

// C������ʵ���ʵ��4View ����/����

C������ʵ���ʵ��4View::C������ʵ���ʵ��4View()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʵ���ʵ��4View::~C������ʵ���ʵ��4View()
{
}

BOOL C������ʵ���ʵ��4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���ʵ��4View ����

void C������ʵ���ʵ��4View::OnDraw(CDC* /*pDC*/)
{
	C������ʵ���ʵ��4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ���ʵ��4View ��ӡ

BOOL C������ʵ���ʵ��4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ���ʵ��4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ���ʵ��4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ���ʵ��4View ���

#ifdef _DEBUG
void C������ʵ���ʵ��4View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���ʵ��4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���ʵ��4Doc* C������ʵ���ʵ��4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���ʵ��4Doc)));
	return (C������ʵ���ʵ��4Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���ʵ��4View ��Ϣ�������


void C������ʵ���ʵ��4View::OnOk()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C������ʵ���ʵ��4View::OnShowdlg()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
	// TODO: �ڴ���������������
}
