
// 3.9ex1View.cpp : CMy39ex1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.9ex1.h"
#endif

#include "3.9ex1Doc.h"
#include "3.9ex1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy39ex1View

IMPLEMENT_DYNCREATE(CMy39ex1View, CView)

BEGIN_MESSAGE_MAP(CMy39ex1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy39ex1View ����/����

CMy39ex1View::CMy39ex1View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

CMy39ex1View::~CMy39ex1View()
{
}

BOOL CMy39ex1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy39ex1View ����

void CMy39ex1View::OnDraw(CDC*  pDC)
{
	CMy39ex1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//for (int i = 0; i <pDoc->ca.GetSize(); i++)
		//pDC->Rectangle(pDoc->ca.GetAt[i]);
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// CMy39ex1View ���

#ifdef _DEBUG
void CMy39ex1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy39ex1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy39ex1Doc* CMy39ex1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy39ex1Doc)));
	return (CMy39ex1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy39ex1View ��Ϣ�������


void CMy39ex1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMy39ex1Doc* pDoc = GetDocument();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand() % 100 + 50;
	int b = rand() % 100 + 50;
	CRect cr(point.x - a, point.y - b, point.x + a, point.y + b);
	pDoc->ca.Add(cr);
	this->Invalidate();
	CClientDC dc(this);
	dc.Ellipse(&cr);
	/*int r=rand()%50+5;
	CRect cr(point.x-r,point.y-r,point.x+r,point.y+r);
	pDoc->ca.Add(cr);
	this->Invalidate();*/
	//CClientDC dc(this);
	//dc.Rectangle(cr);

	CView::OnLButtonDown(nFlags, point);
}
