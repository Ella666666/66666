
// �ڰ��ܿ���ʵ��1View.cpp : C�ڰ��ܿ���ʵ��1View ���ʵ��
//

#include "stdafx.h"
#include "MyDlg.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ���ʵ��1.h"
#endif

#include "�ڰ��ܿ���ʵ��1Doc.h"
#include "�ڰ��ܿ���ʵ��1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ��ܿ���ʵ��1View

IMPLEMENT_DYNCREATE(C�ڰ��ܿ���ʵ��1View, CView)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ���ʵ��1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDOK, &C�ڰ��ܿ���ʵ��1View::OnBnClickedOk)
END_MESSAGE_MAP()

// C�ڰ��ܿ���ʵ��1View ����/����

C�ڰ��ܿ���ʵ��1View::C�ڰ��ܿ���ʵ��1View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	s = "";
}

C�ڰ��ܿ���ʵ��1View::~C�ڰ��ܿ���ʵ��1View()
{
}

BOOL C�ڰ��ܿ���ʵ��1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ��ܿ���ʵ��1View ����

void C�ڰ��ܿ���ʵ��1View::OnDraw(CDC* pDC)
{
	C�ڰ��ܿ���ʵ��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		MyDlg *dlg = new MyDlg;
		dlg->Create(IDD_DIALOG1);
		dlg->ShowWindow(1);
	}
}


// C�ڰ��ܿ���ʵ��1View ��ӡ

BOOL C�ڰ��ܿ���ʵ��1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڰ��ܿ���ʵ��1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڰ��ܿ���ʵ��1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڰ��ܿ���ʵ��1View ���

#ifdef _DEBUG
void C�ڰ��ܿ���ʵ��1View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ��ܿ���ʵ��1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ��ܿ���ʵ��1Doc* C�ڰ��ܿ���ʵ��1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ��ܿ���ʵ��1Doc)));
	return (C�ڰ��ܿ���ʵ��1Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ��ܿ���ʵ��1View ��Ϣ�������


void C�ڰ��ܿ���ʵ��1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK)
	{
		s = cfd.GetFileName();
	}
	GetDC()->TextOutW(200, 200, s);
	CView::OnLButtonDblClk(nFlags, point);
}


void C�ڰ��ܿ���ʵ��1View::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 1;
	
}
