
// �����ܿ���ʵ��View.cpp : C�����ܿ���ʵ��View ���ʵ��
//

#include "stdafx.h"
#include "MyDlg.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ���ʵ��.h"
#endif

#include "�����ܿ���ʵ��Doc.h"
#include "�����ܿ���ʵ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ���ʵ��View

IMPLEMENT_DYNCREATE(C�����ܿ���ʵ��View, CView)

BEGIN_MESSAGE_MAP(C�����ܿ���ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowDig, &C�����ܿ���ʵ��View::OnShowdig)
END_MESSAGE_MAP()

// C�����ܿ���ʵ��View ����/����

C�����ܿ���ʵ��View::C�����ܿ���ʵ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܿ���ʵ��View::~C�����ܿ���ʵ��View()
{
}

BOOL C�����ܿ���ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ���ʵ��View ����

void C�����ܿ���ʵ��View::OnDraw(CDC* /*pDC*/)
{
	C�����ܿ���ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�����ܿ���ʵ��View ��ӡ

BOOL C�����ܿ���ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����ܿ���ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����ܿ���ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�����ܿ���ʵ��View ���

#ifdef _DEBUG
void C�����ܿ���ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ���ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ���ʵ��Doc* C�����ܿ���ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ���ʵ��Doc)));
	return (C�����ܿ���ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ���ʵ��View ��Ϣ�������


void C�����ܿ���ʵ��View::OnShowdig()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CClientDC dc(this);
		CString s;
		s = _T("�����˳��Ի���");
		dc.TextOutW(200, 200, s);
	}
	// TODO: �ڴ���������������
}








