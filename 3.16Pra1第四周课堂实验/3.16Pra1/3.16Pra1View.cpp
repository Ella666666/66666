
// 3.16Pra1View.cpp : CMy316Pra1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16Pra1.h"
#endif

#include "3.16Pra1Doc.h"
#include "3.16Pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316Pra1View

IMPLEMENT_DYNCREATE(CMy316Pra1View, CView)

BEGIN_MESSAGE_MAP(CMy316Pra1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316Pra1View ����/����

CMy316Pra1View::CMy316Pra1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316Pra1View::~CMy316Pra1View()
{
}

BOOL CMy316Pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316Pra1View ����

void CMy316Pra1View::OnDraw(CDC* pDC)
{
	CMy316Pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy316Pra1View ���

#ifdef _DEBUG
void CMy316Pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316Pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316Pra1Doc* CMy316Pra1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316Pra1Doc)));
	return (CMy316Pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316Pra1View ��Ϣ�������


void CMy316Pra1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy316Pra1Doc* pDoc = GetDocument();
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void CMy316Pra1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CMy316Pra1Doc* pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x ;
	pDoc->m_tagRec.bottom = point.y ;
	InvalidateRect(NULL, TRUE);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnLButtonUp(nFlags, point);
}


void CMy316Pra1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d,%d"), point.x, point.y);
	dc.TextOutW(0, 0, s);
	CView::OnMouseMove(nFlags, point);
}
