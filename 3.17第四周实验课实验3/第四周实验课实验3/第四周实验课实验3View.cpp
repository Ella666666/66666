
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
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C������ʵ���ʵ��3View ����/����

C������ʵ���ʵ��3View::C������ʵ���ʵ��3View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
		b[i] = false;
	}	
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
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 100 + 50, NULL);
		}
		set = false;
	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
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


void C������ʵ���ʵ��3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	CRect cl;
	GetClientRect(&cl);
	if (cr[i].bottom >= cl.bottom)
	{
		b[i] = true;
	}
	if (cr[i].top <= cl.top)
	{
		b[i] = false;
	}
	if (b[i])
	{
		cr[i].top -= 20;
		cr[i].bottom -= 20;
	}
	else
	{
		cr[i].top += 20;
		cr[i].bottom += 20;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
