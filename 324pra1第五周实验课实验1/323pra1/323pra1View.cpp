
// 323pra1View.cpp : CMy323pra1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "323pra1.h"
#endif

#include "323pra1Doc.h"
#include "323pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy323pra1View

IMPLEMENT_DYNCREATE(CMy323pra1View, CView)

BEGIN_MESSAGE_MAP(CMy323pra1View, CView)
	ON_COMMAND(ID_size, &CMy323pra1View::Onsize)
END_MESSAGE_MAP()

// CMy323pra1View ����/����

CMy323pra1View::CMy323pra1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy323pra1View::~CMy323pra1View()
{
}

BOOL CMy323pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy323pra1View ����

void CMy323pra1View::OnDraw(CDC* pDC)
{
	CMy323pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy323pra1View ���

#ifdef _DEBUG
void CMy323pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy323pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy323pra1Doc* CMy323pra1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy323pra1Doc)));
	return (CMy323pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy323pra1View ��Ϣ�������


void CMy323pra1View::Onsize(CDC* pDC)
{
	// TODO: �ڴ���������������
	for(int i=500;i<=1000;i++)
	pDC->Ellipse(200, 200, i+i % 10, i+i%10);


}
