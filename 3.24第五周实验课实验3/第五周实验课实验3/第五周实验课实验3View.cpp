
// ������ʵ���ʵ��3View.cpp : C������ʵ���ʵ��3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���ʵ��3.h"
#endif

#include "������ʵ���ʵ��3Doc.h"
#include "������ʵ���ʵ��3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���ʵ��3View

IMPLEMENT_DYNCREATE(C������ʵ���ʵ��3View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���ʵ��3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DrawLine, &C������ʵ���ʵ��3View::OnDrawline)
	ON_COMMAND(ID_DrawRectangle, &C������ʵ���ʵ��3View::OnDrawrectangle)
	ON_COMMAND(ID_DrawCircle, &C������ʵ���ʵ��3View::OnDrawcircle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C������ʵ���ʵ��3View ����/����

C������ʵ���ʵ��3View::C������ʵ���ʵ��3View()
{
	// TODO: �ڴ˴���ӹ������
}

C������ʵ���ʵ��3View::~C������ʵ���ʵ��3View()
{
}

BOOL C������ʵ���ʵ��3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���ʵ��3View ����

void C������ʵ���ʵ��3View::OnDraw(CDC* pDC)
{
	C������ʵ���ʵ��3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// C������ʵ���ʵ��3View ��ӡ

BOOL C������ʵ���ʵ��3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ���ʵ��3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ���ʵ��3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ���ʵ��3View ���

#ifdef _DEBUG
void C������ʵ���ʵ��3View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���ʵ��3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���ʵ��3Doc* C������ʵ���ʵ��3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���ʵ��3Doc)));
	return (C������ʵ���ʵ��3Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���ʵ��3View ��Ϣ�������


void C������ʵ���ʵ��3View::OnDrawline()
{
	CClientDC dc(this);
		dc.MoveTo(p1);
		dc.LineTo(p2);
	// TODO: �ڴ���������������
}


void C������ʵ���ʵ��3View::OnDrawrectangle()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
}


void C������ʵ���ʵ��3View::OnDrawcircle()
{
	CClientDC dc(this);

		dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
	
	// TODO: �ڴ���������������
}


void C������ʵ���ʵ��3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ���ʵ��3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p2 = point;
	CView::OnLButtonUp(nFlags, point);
}
