
// �ڶ���ʵ���1View.cpp : C�ڶ���ʵ���1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ���1.h"
#endif

#include "�ڶ���ʵ���1Doc.h"
#include "�ڶ���ʵ���1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ���1View

IMPLEMENT_DYNCREATE(C�ڶ���ʵ���1View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ���1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�ڶ���ʵ���1View ����/����

C�ڶ���ʵ���1View::C�ڶ���ʵ���1View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ���ʵ���1View::~C�ڶ���ʵ���1View()
{
}

BOOL C�ڶ���ʵ���1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���ʵ���1View ����

void C�ڶ���ʵ���1View::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ���1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC dc(this);
	CString S = _T("S:����***");
	int A = 110;
	CString ss;
	ss.Format("A=%d", A);
	dc.TextOut(200, 200, S);
	dc.TextOut(200, 220, ss);

}


// C�ڶ���ʵ���1View ��ӡ

BOOL C�ڶ���ʵ���1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڶ���ʵ���1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڶ���ʵ���1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڶ���ʵ���1View ���

#ifdef _DEBUG
void C�ڶ���ʵ���1View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ���1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ���1Doc* C�ڶ���ʵ���1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ���1Doc)));
	return (C�ڶ���ʵ���1Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ���1View ��Ϣ�������
