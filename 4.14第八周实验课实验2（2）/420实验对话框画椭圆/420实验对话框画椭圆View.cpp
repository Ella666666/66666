
// 420ʵ��Ի�����ԲView.cpp : CMy420ʵ��Ի�����ԲView ���ʵ��
//

#include "stdafx.h"
#include "DrawEllipse.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "420ʵ��Ի�����Բ.h"
#endif

#include "420ʵ��Ի�����ԲDoc.h"
#include "420ʵ��Ի�����ԲView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy420ʵ��Ի�����ԲView

IMPLEMENT_DYNCREATE(CMy420ʵ��Ի�����ԲView, CView)

BEGIN_MESSAGE_MAP(CMy420ʵ��Ի�����ԲView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_InputPoint, &CMy420ʵ��Ի�����ԲView::OnInputpoint)
END_MESSAGE_MAP()

// CMy420ʵ��Ի�����ԲView ����/����

CMy420ʵ��Ի�����ԲView::CMy420ʵ��Ի�����ԲView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy420ʵ��Ի�����ԲView::~CMy420ʵ��Ի�����ԲView()
{
}

BOOL CMy420ʵ��Ի�����ԲView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy420ʵ��Ի�����ԲView ����

void CMy420ʵ��Ի�����ԲView::OnDraw(CDC* pDC)
{
	CMy420ʵ��Ի�����ԲDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy420ʵ��Ի�����ԲView ��ӡ

BOOL CMy420ʵ��Ի�����ԲView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy420ʵ��Ի�����ԲView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy420ʵ��Ի�����ԲView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy420ʵ��Ի�����ԲView ���

#ifdef _DEBUG
void CMy420ʵ��Ի�����ԲView::AssertValid() const
{
	CView::AssertValid();
}

void CMy420ʵ��Ի�����ԲView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy420ʵ��Ի�����ԲDoc* CMy420ʵ��Ի�����ԲView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy420ʵ��Ի�����ԲDoc)));
	return (CMy420ʵ��Ի�����ԲDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy420ʵ��Ի�����ԲView ��Ϣ�������


void CMy420ʵ��Ի�����ԲView::OnInputpoint()
{
	DrawEllipse point;
	int t = point.DoModal();
	if(t==IDOK)
	{
		CRect re(point.x1, point.y1, point.x2, point.y2);
	    GetDC()->Ellipse(re);
	}
	
	// TODO: �ڴ���������������
}
