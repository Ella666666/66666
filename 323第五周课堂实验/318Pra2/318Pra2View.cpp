
// 318Pra2View.cpp : CMy318Pra2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "318Pra2.h"
#endif

#include "318Pra2Doc.h"
#include "318Pra2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy318Pra2View

IMPLEMENT_DYNCREATE(CMy318Pra2View, CView)

BEGIN_MESSAGE_MAP(CMy318Pra2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_ChangeCircle, &CMy318Pra2View::OnChangecircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy318Pra2View ����/����

CMy318Pra2View::CMy318Pra2View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	t = 0;
	m_clr1+= 20;
}

CMy318Pra2View::~CMy318Pra2View()
{
}

BOOL CMy318Pra2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy318Pra2View ����

void CMy318Pra2View::OnDraw(CDC* pDC)
{
	CMy318Pra2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i = rand() % (100 - 10) + 50;
	int clr = RGB(i,i, m_clr1);
	CBrush newBrush(clr);
    CBrush *oldBrush = pDC->SelectObject(&newBrush);
	SetTimer(1, 500, NULL);
	GetClientRect(&cr);
	cp = cr.CenterPoint();
	cr.left = cp.x - 25; cr.top = cp.y - 25;
	cr.right = cp.x + 25; cr.bottom = cp.y + 25;
	if (set)
	{
		pDC->Ellipse(cr.left -= t, cr.top -= t, cr.right += t, cr.bottom += t);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy318Pra2View ���

#ifdef _DEBUG
void CMy318Pra2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy318Pra2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy318Pra2Doc* CMy318Pra2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy318Pra2Doc)));
	return (CMy318Pra2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy318Pra2View ��Ϣ�������



void CMy318Pra2View::OnChangecircle()
{
	set = true;
	// TODO: �ڴ���������������
}


void CMy318Pra2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	t += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
