
// �ڰ���ʵ���ʵ��2.1View.cpp : C�ڰ���ʵ���ʵ��21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ���ʵ���ʵ��2.1.h"
#endif

#include "�ڰ���ʵ���ʵ��2.1Doc.h"
#include "�ڰ���ʵ���ʵ��2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ���ʵ���ʵ��21View

IMPLEMENT_DYNCREATE(C�ڰ���ʵ���ʵ��21View, CView)

BEGIN_MESSAGE_MAP(C�ڰ���ʵ���ʵ��21View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C�ڰ���ʵ���ʵ��21View ����/����

C�ڰ���ʵ���ʵ��21View::C�ڰ���ʵ���ʵ��21View()
{
	// TODO: �ڴ˴���ӹ������
	cr.bottom = 200;
	cr.top = 100;
	cr.right = 200;
	cr.left = 100;
	set = false;
}

C�ڰ���ʵ���ʵ��21View::~C�ڰ���ʵ���ʵ��21View()
{
}

BOOL C�ڰ���ʵ���ʵ��21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ���ʵ���ʵ��21View ����

void C�ڰ���ʵ���ʵ��21View::OnDraw(CDC* pDC)
{
	C�ڰ���ʵ���ʵ��21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	cr.left += p1.x/100;
	cr.top += p1.y/100;
	cr.right += p2.x/100;
	cr.bottom += p2.y/100;
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ���ʵ���ʵ��21View ��ӡ

BOOL C�ڰ���ʵ���ʵ��21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڰ���ʵ���ʵ��21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڰ���ʵ���ʵ��21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڰ���ʵ���ʵ��21View ���

#ifdef _DEBUG
void C�ڰ���ʵ���ʵ��21View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ���ʵ���ʵ��21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ���ʵ���ʵ��21Doc* C�ڰ���ʵ���ʵ��21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ���ʵ���ʵ��21Doc)));
	return (C�ڰ���ʵ���ʵ��21Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ���ʵ���ʵ��21View ��Ϣ�������


void C�ڰ���ʵ���ʵ��21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = 1;
	p1 = point;
	p2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void C�ڰ���ʵ���ʵ��21View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set = 1)
	{
		p2 = point;
		
	}Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void C�ڰ���ʵ���ʵ��21View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = 0;
	CView::OnLButtonUp(nFlags, point);
}
