
// 331praView.cpp : CMy331praView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "331pra.h"
#endif

#include "331praDoc.h"
#include "331praView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy331praView

IMPLEMENT_DYNCREATE(CMy331praView, CView)

BEGIN_MESSAGE_MAP(CMy331praView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy331praView ����/����

CMy331praView::CMy331praView()
{
	// TODO: �ڴ˴���ӹ������
	m_str = "";
	use = FALSE;
}

CMy331praView::~CMy331praView()
{
}

BOOL CMy331praView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy331praView ����

void CMy331praView::OnDraw(CDC* pDC)
{
	CMy331praDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(100, 100, 200, 200);
	pDC->BeginPath();
	
	pDC->EndPath();
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy331praView ��ӡ

BOOL CMy331praView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy331praView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy331praView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy331praView ���

#ifdef _DEBUG
void CMy331praView::AssertValid() const
{
	CView::AssertValid();
}

void CMy331praView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy331praDoc* CMy331praView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy331praDoc)));
	return (CMy331praDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy331praView ��Ϣ�������


int CMy331praView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	ShowCaret();
	return 0;
}


void CMy331praView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_str.Empty();
	m_ptr = point;
	use = TRUE;
	CView::OnLButtonDown(nFlags, point);
}


void CMy331praView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d== nChar)
	{
		m_str.Empty();
		m_ptr.y += tm.tmHeight;
	}
	else if (0x08 == nChar)
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(m_ptr.x, m_ptr.y, m_str);
		m_str = m_str.Left(m_str.GetLength() - 1);
		dc.SetTextColor(clr);
	}
	else 
	{ 
		m_str += char(nChar);
	}
	CSize sz = dc.GetTextExtent(m_str);
	CPoint pt;
	pt.x = m_ptr.x + sz.cx;
	pt.y = m_ptr.y;
	SetCaretPos(pt);
	dc.TextOut(m_ptr.x, m_ptr.y, m_str);
	CView::OnChar(nChar, nRepCnt, nFlags);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
