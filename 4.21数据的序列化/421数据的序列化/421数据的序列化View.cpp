
// 421���ݵ����л�View.cpp : CMy421���ݵ����л�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "421���ݵ����л�.h"
#endif

#include "421���ݵ����л�Doc.h"
#include "421���ݵ����л�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy421���ݵ����л�View

IMPLEMENT_DYNCREATE(CMy421���ݵ����л�View, CView)

BEGIN_MESSAGE_MAP(CMy421���ݵ����л�View, CView)
	ON_COMMAND(ID_Change, &CMy421���ݵ����л�View::OnChange)
END_MESSAGE_MAP()

// CMy421���ݵ����л�View ����/����

CMy421���ݵ����л�View::CMy421���ݵ����л�View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy421���ݵ����л�View::~CMy421���ݵ����л�View()
{
}

BOOL CMy421���ݵ����л�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy421���ݵ����л�View ����

void CMy421���ݵ����л�View::OnDraw(CDC* pDC)
{
	CMy421���ݵ����л�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(200, 300, pDoc->s);
	CString ss;
	ss.Format(_T("%d yes!"), 100 + pDoc->a);
	pDC->TextOutW(300, 3000, ss);
}


// CMy421���ݵ����л�View ���

#ifdef _DEBUG
void CMy421���ݵ����л�View::AssertValid() const
{
	CView::AssertValid();
}

void CMy421���ݵ����л�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy421���ݵ����л�Doc* CMy421���ݵ����л�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy421���ݵ����л�Doc)));
	return (CMy421���ݵ����л�Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy421���ݵ����л�View ��Ϣ�������


void CMy421���ݵ����л�View::OnChange()
{
	CMy421���ݵ����л�Doc* pDoc = GetDocument();
	pDoc->a += 1000;
	pDoc->s += _T("added!");
	Invalidate();
		// TODO: �ڴ���������������

}
