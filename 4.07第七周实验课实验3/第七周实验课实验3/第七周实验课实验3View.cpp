
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C������ʵ���ʵ��3View ����/����

C������ʵ���ʵ��3View::C������ʵ���ʵ��3View()
{
	// TODO: �ڴ˴���ӹ������
	flag1 = 0;
	flag2 = 0;
	flag3 = 1;
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
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&cr1);
	if (cr.top != cr1.Height() / 2 - 50)
	{
		cr.top = cr1.Height() / 2 - 50;
		cr.bottom = cr1.Height() / 2 + 50;
	}
	if (flag3)
	{
		cr.left = 0;
		cr.top = cr1.Height() / 2 - 50;
		cr.right = 100;
		cr.bottom = cr1.Height() / 2 + 50;
		flag3 = 0;
	}
	SetTimer(0, 100, NULL);
	pDC->Ellipse(cr);
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


void C������ʵ���ʵ��3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag2 = 1;
	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ���ʵ��3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag2 = 0;
	CView::OnLButtonDblClk(nFlags, point);
}


void C������ʵ���ʵ��3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��
	GetClientRect(&cr1);
	if (flag2)
	{
		if (flag1 == 0)
		{
			cr.left += 50;
			cr.right += 50;
			Invalidate();
			if (cr.right >= cr1.right)
				flag1 = 1;
		}
		else
		{
			cr.left -= 50;
			cr.right -= 50;
			Invalidate();
			if (cr.left <= cr1.left)
				flag1 = 0;
		}
	}
	CView::OnTimer(nIDEvent);
}
