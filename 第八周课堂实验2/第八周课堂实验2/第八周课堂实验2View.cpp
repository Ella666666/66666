
// �ڰ��ܿ���ʵ��2View.cpp : C�ڰ��ܿ���ʵ��2View ���ʵ��
//

#include "stdafx.h"
#include "MyDlg.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ���ʵ��2.h"
#endif

#include "�ڰ��ܿ���ʵ��2Doc.h"
#include "�ڰ��ܿ���ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ��ܿ���ʵ��2View

IMPLEMENT_DYNCREATE(C�ڰ��ܿ���ʵ��2View, CView)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ���ʵ��2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowDlg, &C�ڰ��ܿ���ʵ��2View::OnShowdlg)
	ON_BN_CLICKED(IDOK, &C�ڰ��ܿ���ʵ��2View::OnBnClickedOk)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C�ڰ��ܿ���ʵ��2View ����/����

C�ڰ��ܿ���ʵ��2View::C�ڰ��ܿ���ʵ��2View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	s = "";
}

C�ڰ��ܿ���ʵ��2View::~C�ڰ��ܿ���ʵ��2View()
{
}

BOOL C�ڰ��ܿ���ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ��ܿ���ʵ��2View ����

void C�ڰ��ܿ���ʵ��2View::OnDraw(CDC* pDC)
{
	C�ڰ��ܿ���ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (set)
	{
		MyDlg *dlg = new MyDlg;
		dlg->Create(IDD_DIALOG1);
		dlg->ShowWindow(1);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ��ܿ���ʵ��2View ��ӡ

BOOL C�ڰ��ܿ���ʵ��2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڰ��ܿ���ʵ��2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڰ��ܿ���ʵ��2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڰ��ܿ���ʵ��2View ���

#ifdef _DEBUG
void C�ڰ��ܿ���ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ��ܿ���ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ��ܿ���ʵ��2Doc* C�ڰ��ܿ���ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ��ܿ���ʵ��2Doc)));
	return (C�ڰ��ܿ���ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ��ܿ���ʵ��2View ��Ϣ�������


void C�ڰ��ܿ���ʵ��2View::OnShowdlg()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
	// TODO: �ڴ���������������
}


void C�ڰ��ܿ���ʵ��2View::OnBnClickedOk()
{
	set = 1;

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ڰ��ܿ���ʵ��2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MyDlg dlg;
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK)
	{
		s = cfd.GetFileName();
	}
	GetDC()->TextOut(200, 200, s);
	dlg.ss.AddString(s);
	CView::OnLButtonDblClk(nFlags, point);
}
