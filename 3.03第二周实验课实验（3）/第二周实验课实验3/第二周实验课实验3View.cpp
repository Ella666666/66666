
// �ڶ���ʵ���ʵ��3View.cpp : C�ڶ���ʵ���ʵ��3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ���ʵ��3.h"
#endif

#include "�ڶ���ʵ���ʵ��3Doc.h"
#include "�ڶ���ʵ���ʵ��3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ���ʵ��3View

IMPLEMENT_DYNCREATE(C�ڶ���ʵ���ʵ��3View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ���ʵ��3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڶ���ʵ���ʵ��3View ����/����

C�ڶ���ʵ���ʵ��3View::C�ڶ���ʵ���ʵ��3View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ���ʵ���ʵ��3View::~C�ڶ���ʵ���ʵ��3View()
{
}

BOOL C�ڶ���ʵ���ʵ��3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���ʵ���ʵ��3View ����

void C�ڶ���ʵ���ʵ��3View::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ���ʵ��3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڶ���ʵ���ʵ��3View ��ӡ

BOOL C�ڶ���ʵ���ʵ��3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڶ���ʵ���ʵ��3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڶ���ʵ���ʵ��3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڶ���ʵ���ʵ��3View ���

#ifdef _DEBUG
void C�ڶ���ʵ���ʵ��3View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ���ʵ��3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ���ʵ��3Doc* C�ڶ���ʵ���ʵ��3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ���ʵ��3Doc)));
	return (C�ڶ���ʵ���ʵ��3Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ���ʵ��3View ��Ϣ�������


void C�ڶ���ʵ���ʵ��3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ڶ���ʵ���ʵ��3Doc* pDoc = GetDocument();
	pDoc->count += 1;
	CView::OnLButtonDown(nFlags, point);
}


void C�ڶ���ʵ���ʵ��3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ڶ���ʵ���ʵ��3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;
	s.Format("%d", pDoc->count);
	dc.TextOut(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
