
// 2.2.4View.cpp : CMy224View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2.2.4.h"
#endif

#include "2.2.4Doc.h"
#include "2.2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy224View

IMPLEMENT_DYNCREATE(CMy224View, CView)

BEGIN_MESSAGE_MAP(CMy224View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy224View ����/����

CMy224View::CMy224View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy224View::~CMy224View()
{
}

BOOL CMy224View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy224View ����

void CMy224View::OnDraw(CDC* pDC)
{
	CMy224Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC = GetDC();
	CBrush brush(RGB(255, 0, 0));
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//ѡ�µĻ�ˢ
	pDC->Ellipse(100, 100, 500, 500);

}


// CMy224View ��ӡ

BOOL CMy224View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy224View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy224View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy224View ���

#ifdef _DEBUG
void CMy224View::AssertValid() const
{
	CView::AssertValid();
}

void CMy224View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy224Doc* CMy224View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy224Doc)));
	return (CMy224Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy224View ��Ϣ�������
