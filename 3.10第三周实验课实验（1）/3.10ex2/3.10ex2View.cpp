
// 3.10ex2View.cpp : CMy310ex2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.10ex2.h"
#endif

#include "3.10ex2Doc.h"
#include "3.10ex2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy310ex2View

IMPLEMENT_DYNCREATE(CMy310ex2View, CView)

BEGIN_MESSAGE_MAP(CMy310ex2View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy310ex2View ����/����

CMy310ex2View::CMy310ex2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy310ex2View::~CMy310ex2View()
{
}

BOOL CMy310ex2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy310ex2View ����

void CMy310ex2View::OnDraw(CDC* pDC)
{
	CMy310ex2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// CMy310ex2View ���

#ifdef _DEBUG
void CMy310ex2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy310ex2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy310ex2Doc* CMy310ex2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy310ex2Doc)));
	return (CMy310ex2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy310ex2View ��Ϣ�������


void CMy310ex2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy310ex2Doc* pDoc = GetDocument();
	int C = pDoc->A + pDoc->B;
	CString s;
	CClientDC dc(this);
	s.Format(_T("A+B=%d"), C);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
