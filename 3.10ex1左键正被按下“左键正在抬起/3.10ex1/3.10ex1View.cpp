
// 3.10ex1View.cpp : CMy310ex1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.10ex1.h"
#endif

#include "3.10ex1Doc.h"
#include "3.10ex1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy310ex1View

IMPLEMENT_DYNCREATE(CMy310ex1View, CView)

BEGIN_MESSAGE_MAP(CMy310ex1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy310ex1View ����/����

CMy310ex1View::CMy310ex1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy310ex1View::~CMy310ex1View()
{
}

BOOL CMy310ex1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy310ex1View ����

void CMy310ex1View::OnDraw(CDC* pDC)
{
	CMy310ex1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy310ex1View ���

#ifdef _DEBUG
void CMy310ex1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy310ex1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy310ex1Doc* CMy310ex1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy310ex1Doc)));
	return (CMy310ex1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy310ex1View ��Ϣ�������


void CMy310ex1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s=_T("�����������");
	CClientDC dc(this);
	dc.TextOutW(100, 200, s);
}


void CMy310ex1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s = _T("�������̧��");
	CClientDC dc(this);
	dc.TextOutW(100,200, s);
	CView::OnLButtonUp(nFlags, point);
}
