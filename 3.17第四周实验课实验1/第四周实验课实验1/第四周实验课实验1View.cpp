
// ������ʵ���ʵ��1View.cpp : C������ʵ���ʵ��1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���ʵ��1.h"
#endif

#include "������ʵ���ʵ��1Doc.h"
#include "������ʵ���ʵ��1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���ʵ��1View

IMPLEMENT_DYNCREATE(C������ʵ���ʵ��1View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���ʵ��1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C������ʵ���ʵ��1View ����/����

C������ʵ���ʵ��1View::C������ʵ���ʵ��1View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;
	n = 0;
	m = 0;
	s = "";
}

C������ʵ���ʵ��1View::~C������ʵ���ʵ��1View()
{
}

BOOL C������ʵ���ʵ��1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���ʵ��1View ����

void C������ʵ���ʵ��1View::OnDraw(CDC* pDC)
{
	C������ʵ���ʵ��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ���ʵ��1View ��ӡ

BOOL C������ʵ���ʵ��1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ���ʵ��1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ���ʵ��1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ���ʵ��1View ���

#ifdef _DEBUG
void C������ʵ���ʵ��1View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���ʵ��1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���ʵ��1Doc* C������ʵ���ʵ��1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���ʵ��1Doc)));
	return (C������ʵ���ʵ��1Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���ʵ��1View ��Ϣ�������


void C������ʵ���ʵ��1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	count += 1;
	CView::OnMouseMove(nFlags, point);
}


void C������ʵ���ʵ��1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	count = 0;
	m = point.x;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ���ʵ��1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	n = point.x;
	int d = n - m;
	CString ss;
	if (d == 0)
	{
		ss=(_T("���û���ƶ����޷�����"));
		dc.TextOutW(0, 0, ss);
	}
	else
	{
		s.Format(_T("MouseMove������ %d �Σ������ƶ� %d ���ط���һ��"), count, d / count);
		dc.TextOutW(0, 0, s);
	}
	CView::OnLButtonUp(nFlags, point);
}
