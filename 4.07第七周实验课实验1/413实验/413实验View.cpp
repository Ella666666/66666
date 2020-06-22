
// 413ʵ��View.cpp : CMy413ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "413ʵ��.h"
#endif

#include "413ʵ��Doc.h"
#include "413ʵ��View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define Trans(p1, rect) CPoint(long((p1.x+0.5)/1) - rect.Width()/2, long((p1.y+0.5)/1) - rect.Height()/2)
// CMy413ʵ��View

IMPLEMENT_DYNCREATE(CMy413ʵ��View, CView)

BEGIN_MESSAGE_MAP(CMy413ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &CMy413ʵ��View::OnPopout)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy413ʵ��View ����/����

CMy413ʵ��View::CMy413ʵ��View()
{
	// TODO: �ڴ˴���ӹ������
	m_IsREadyToMove = false;
	p1 = 0;
	CPen Blackpen(0, 1, RGB(0, 0, 0));
	m_Points[0] = CPoint(121, 100);
	m_Points[1] = CPoint(367, 100);
	m_Points[2] = CPoint(367, 245);
	m_Points[3] = CPoint(121, 245);
	m_CurrentPen = &Blackpen;
}


CMy413ʵ��View::~CMy413ʵ��View()
{
}

BOOL CMy413ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy413ʵ��View ����
void CMy413ʵ��View::DrawObject(CDC* pDC, const CRect& rect) 
{
	int i = 0;
	CPen * oldPen = pDC->SelectObject(m_CurrentPen);

	// ��������
	pDC->Rectangle(CRect(Trans(m_Points[0], rect), Trans(m_Points[2], rect)));
	pDC->SelectObject(oldPen);

}

void CMy413ʵ��View::OnDraw(CDC* pDC)
{
	CMy413ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

	CDC memDC;  // �����ڴ�DC
	CBitmap NewBitmap, *pOldBitmap;
	memDC.CreateCompatibleDC(pDC);  // ����һ������ʾDC���ݵ��ڴ�DC 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());     // ���������ڴ�λͼ 
	pOldBitmap = memDC.SelectObject(&NewBitmap);    // ������λͼѡ���ڴ�DC
	memDC.FillSolidRect(rect, pDC->GetBkColor());   // ��ԭ������ɫ���ͻ����������Ǻ�ɫ
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	memDC.SetROP2(R2_COPYPEN); // ���û�ͼ��ʽ

	DrawObject(&memDC, rect);  // �����εĴ�������һ��������

							   // ���ڴ�DC�е�λͼ�������豸DC
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}




// CMy413ʵ��View ��ӡ

BOOL CMy413ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy413ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy413ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}





// CMy413ʵ��View ���

#ifdef _DEBUG
void CMy413ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void CMy413ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy413ʵ��Doc* CMy413ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy413ʵ��Doc)));
	return (CMy413ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy413ʵ��View ��Ϣ�������


void CMy413ʵ��View::OnPopout()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int R, X, Y;
		R = dlg.r;
		X = dlg.x;
		Y = dlg.y;
		CRect cr(X - R, Y - R, X + R, Y + R);
		GetDC()->Ellipse(cr);
	}
	// TODO: �ڴ���������������
}





void CMy413ʵ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	CPen RedPen(1, 1, RGB(0, 0, 0));
	 m_IsREadyToMove = false;   // ��ʼ���һ�²����ƶ�
	if (m_Points[0].x <= point.x && point.x <= m_Points[2].x &&
		m_Points[0].y <= point.y && point.y <= m_Points[2].y)
	{
		p1 = point;
		m_IsREadyToMove = true; // ���һ�¿����ƶ���
		m_CurrentPen = &RedPen;

		SetCapture();           // ������겶��   
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // ���ù��Ϊ�˸�����
	}
	// ����OnDraw��������̬Ч��
	Invalidate(FALSE);
	CView::OnLButtonDown(nFlags, point);
}


void CMy413ʵ��View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPen Blackpen(0, 1, RGB(0, 0, 0));
	if (true == m_IsREadyToMove)
	{
		m_CurrentPen = &Blackpen;   // �޸Ļ�����ɫΪ��ɫ
		p1 = NULL;      // ����ƶ���Ϣ
	}
	ReleaseCapture(); // �ͷ���겶��
	m_IsREadyToMove = false;   // ���һ�´�ʱ�������ƶ���
							   // ����OnDraw��������̬Ч��
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy413ʵ��View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (true == m_IsREadyToMove)
	{
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // ���ù��Ϊ�˸�����   
												  // ���õ�ǰ���λ�úͳ�ʼ��¼��λ�����޸ľ��ε�ÿ�����㣬����ͼ����궯��Ч��
		for (int i = 0; i < 4; i++)
		{
			m_Points[i] += point - p1;
		}
		p1 = point;
	}
	// ����OnDraw��������̬Ч��
	Invalidate(FALSE);
	
	CView::OnMouseMove(nFlags, point);
}
