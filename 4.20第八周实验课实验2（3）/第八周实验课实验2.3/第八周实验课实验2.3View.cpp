
// �ڰ���ʵ���ʵ��2.3View.cpp : C�ڰ���ʵ���ʵ��23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ���ʵ���ʵ��2.3.h"
#endif

#include "�ڰ���ʵ���ʵ��2.3Doc.h"
#include "�ڰ���ʵ���ʵ��2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ���ʵ���ʵ��23View

IMPLEMENT_DYNCREATE(C�ڰ���ʵ���ʵ��23View, CView)

BEGIN_MESSAGE_MAP(C�ڰ���ʵ���ʵ��23View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڰ���ʵ���ʵ��23View ����/����

C�ڰ���ʵ���ʵ��23View::C�ڰ���ʵ���ʵ��23View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 100;
	cr.top = 100;
	cr.bottom = 200;
	cr.right = 200;
	set = false;
}

C�ڰ���ʵ���ʵ��23View::~C�ڰ���ʵ���ʵ��23View()
{
}

BOOL C�ڰ���ʵ���ʵ��23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ���ʵ���ʵ��23View ����

void C�ڰ���ʵ���ʵ��23View::OnDraw(CDC* pDC)
{
	C�ڰ���ʵ���ʵ��23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ���ʵ���ʵ��23View ��ӡ

BOOL C�ڰ���ʵ���ʵ��23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڰ���ʵ���ʵ��23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڰ���ʵ���ʵ��23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڰ���ʵ���ʵ��23View ���

#ifdef _DEBUG
void C�ڰ���ʵ���ʵ��23View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ���ʵ���ʵ��23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ���ʵ���ʵ��23Doc* C�ڰ���ʵ���ʵ��23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ���ʵ���ʵ��23Doc)));
	return (C�ڰ���ʵ���ʵ��23Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ���ʵ���ʵ��23View ��Ϣ�������


void C�ڰ���ʵ���ʵ��23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x<cr.left||point.x>cr.right||point.y<cr.bottom||point.y>cr.top)
	{
		CDC * dc = GetDC();
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));//����	
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//����͸��Ч��		
		pOldBrush = dc->SelectObject(pBrush);
		CRect rect;	rect.bottom = 200; rect.top = 100; rect.right = 200; rect.left = 100;
		dc->Rectangle(&rect);
		dc->SelectObject(pOldPen);
		pen.DeleteObject();
	}
	CView::OnLButtonDown(nFlags, point);
}
