
// 324pra1View.cpp : CMy324pra1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "324pra1.h"
#endif

#include "324pra1Doc.h"
#include "324pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy324pra1View

IMPLEMENT_DYNCREATE(CMy324pra1View, CView)

BEGIN_MESSAGE_MAP(CMy324pra1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWNAME, &CMy324pra1View::OnShowname)
	ON_COMMAND(ID_Line, &CMy324pra1View::OnLine)
	ON_COMMAND(ID_Rectangle, &CMy324pra1View::OnRectangle)
	ON_COMMAND(ID_Ellipse, &CMy324pra1View::OnEllipse)
END_MESSAGE_MAP()

// CMy324pra1View ����/����

CMy324pra1View::CMy324pra1View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CMy324pra1View::~CMy324pra1View()
{
}

BOOL CMy324pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy324pra1View ����

void CMy324pra1View::OnDraw(CDC* pDC)
{
	CMy324pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy324pra1View ��ӡ

BOOL CMy324pra1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy324pra1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy324pra1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy324pra1View ���

#ifdef _DEBUG
void CMy324pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy324pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy324pra1Doc* CMy324pra1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy324pra1Doc)));
	return (CMy324pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy324pra1View ��Ϣ�������


void CMy324pra1View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s = _T("������");
	CClientDC dc(this);
	dc.TextOutW(500, 500, s);

}


void CMy324pra1View::OnLine()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	dc.LineTo(50, 50);
}


void CMy324pra1View::OnRectangle()
{
	// TODO: �ڴ������������
	CClientDC dc(this);
	dc.Rectangle(500, 500, 1200, 1150);
}


void CMy324pra1View::OnEllipse()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	dc.Ellipse(1050, 1250, 1500, 1050);
}
