
// �ڶ���ʵ���ʵ��2View.cpp : C�ڶ���ʵ���ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ���ʵ��2.h"
#endif

#include "�ڶ���ʵ���ʵ��2Doc.h"
#include "�ڶ���ʵ���ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ���ʵ��2View

IMPLEMENT_DYNCREATE(C�ڶ���ʵ���ʵ��2View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ���ʵ��2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�ڶ���ʵ���ʵ��2View ����/����

C�ڶ���ʵ���ʵ��2View::C�ڶ���ʵ���ʵ��2View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ���ʵ���ʵ��2View::~C�ڶ���ʵ���ʵ��2View()
{
}

BOOL C�ڶ���ʵ���ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���ʵ���ʵ��2View ����

void C�ڶ���ʵ���ʵ��2View::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ���ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	CString ss;
	ss.Format("A=%d", pDoc->A);
	dc.TextOut(200, 200, pDoc->S);
	dc.TextOut(200, 220, ss);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڶ���ʵ���ʵ��2View ��ӡ

BOOL C�ڶ���ʵ���ʵ��2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڶ���ʵ���ʵ��2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڶ���ʵ���ʵ��2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڶ���ʵ���ʵ��2View ���

#ifdef _DEBUG
void C�ڶ���ʵ���ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ���ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ���ʵ��2Doc* C�ڶ���ʵ���ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ���ʵ��2Doc)));
	return (C�ڶ���ʵ���ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ���ʵ��2View ��Ϣ�������
