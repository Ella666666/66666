
// 317pra1View.cpp : CMy317pra1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "317pra1.h"
#endif

#include "317pra1Doc.h"
#include "317pra1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy317pra1View

IMPLEMENT_DYNCREATE(CMy317pra1View, CView)

BEGIN_MESSAGE_MAP(CMy317pra1View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy317pra1View ����/����

CMy317pra1View::CMy317pra1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy317pra1View::~CMy317pra1View()
{
}

BOOL CMy317pra1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy317pra1View ����

void CMy317pra1View::OnDraw(CDC* pDC)
{
	CMy317pra1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMy317pra1View ���

#ifdef _DEBUG
void CMy317pra1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy317pra1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy317pra1Doc* CMy317pra1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy317pra1Doc)));
	return (CMy317pra1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy317pra1View ��Ϣ�������


void CMy317pra1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy317pra1Doc* pDoc = GetDocument();
	CRect cli;
	GetClientRect(&cli);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_crlRect.left > 0)
		{
			pDoc->m_crlRect.left -= 15;
			pDoc->m_crlRect.right -= 15;
		}break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right <=(cli.right-cli.left))
		{
			pDoc->m_crlRect.left += 15;
			pDoc->m_crlRect.right += 15;
		}break;
	case VK_UP:
			if (pDoc->m_crlRect.top>0)
			{
				pDoc->m_crlRect.top -=15;
				pDoc->m_crlRect.bottom -= 15;
			}break;
	case VK_DOWN:
			if (pDoc->m_crlRect.top<=(cli.bottom-cli.top))
			{
				pDoc->m_crlRect.top += 15;
				pDoc->m_crlRect.bottom += 15;
			}break;
	case VK_END:
			if (pDoc->m_crlRect.top <= (cli.bottom - cli.top))
			{
				pDoc->m_crlRect.top += 15;
				pDoc->m_crlRect.left += 15;
			}break;
	case VK_HOME:
			if (pDoc->m_crlRect.top <= (cli.bottom - cli.top))
			{
				pDoc->m_crlRect.right += 15;
				pDoc->m_crlRect.bottom += 15;
				
			}break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy317pra1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy317pra1Doc* pDoc = GetDocument();
	pDoc->m_crlRect.left = 450; pDoc->m_crlRect.right = 900;
	pDoc->m_crlRect.top = 50; pDoc->m_crlRect.bottom = 500;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
