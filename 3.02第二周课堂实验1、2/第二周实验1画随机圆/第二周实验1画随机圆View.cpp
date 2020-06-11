
// �ڶ���ʵ��1�����ԲView.cpp : C�ڶ���ʵ��1�����ԲView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ��1�����Բ.h"
#endif

#include "�ڶ���ʵ��1�����ԲDoc.h"
#include "�ڶ���ʵ��1�����ԲView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ��1�����ԲView

IMPLEMENT_DYNCREATE(C�ڶ���ʵ��1�����ԲView, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ��1�����ԲView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڶ���ʵ��1�����ԲView ����/����

C�ڶ���ʵ��1�����ԲView::C�ڶ���ʵ��1�����ԲView()
{
	// TODO: �ڴ˴���ӹ������
	m_nBubbleCount = 0;
}

C�ڶ���ʵ��1�����ԲView::~C�ڶ���ʵ��1�����ԲView()
{
}

BOOL C�ڶ���ʵ��1�����ԲView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}
void C�ڶ���ʵ��1�����ԲView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int  r = rand() % 50 + 10;
	CRect  rect(point.x - r, point.y - r, point.x + r, point.y + r);
	if (m_nBubbleCount<MAX_BUBBLE)
	{
		m_rectBubble[m_nBubbleCount] = rect;
		m_nBubbleCount++;
	}
	InvalidateRect(rect, FALSE);
	CView::OnLButtonDown(nFlags, point);
}
// C�ڶ���ʵ��1�����ԲView ����

void C�ڶ���ʵ��1�����ԲView::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ��1�����ԲDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i<m_nBubbleCount; i++)
	pDC->Ellipse(m_rectBubble[i]);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڶ���ʵ��1�����ԲView ��ӡ

BOOL C�ڶ���ʵ��1�����ԲView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڶ���ʵ��1�����ԲView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڶ���ʵ��1�����ԲView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڶ���ʵ��1�����ԲView ���

#ifdef _DEBUG
void C�ڶ���ʵ��1�����ԲView::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ��1�����ԲView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ��1�����ԲDoc* C�ڶ���ʵ��1�����ԲView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ��1�����ԲDoc)));
	return (C�ڶ���ʵ��1�����ԲDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ��1�����ԲView ��Ϣ�������



