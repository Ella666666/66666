
// 420ʵ��Ի���ȷ����ɫView.cpp : CMy420ʵ��Ի���ȷ����ɫView ���ʵ��
//

#include "stdafx.h"
#include "�����ɫ.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "420ʵ��Ի���ȷ����ɫ.h"
#endif

#include "420ʵ��Ի���ȷ����ɫDoc.h"
#include "420ʵ��Ի���ȷ����ɫView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy420ʵ��Ի���ȷ����ɫView

IMPLEMENT_DYNCREATE(CMy420ʵ��Ի���ȷ����ɫView, CView)

BEGIN_MESSAGE_MAP(CMy420ʵ��Ի���ȷ����ɫView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_InputRGB, &CMy420ʵ��Ի���ȷ����ɫView::OnInputrgb)
END_MESSAGE_MAP()

// CMy420ʵ��Ի���ȷ����ɫView ����/����

CMy420ʵ��Ի���ȷ����ɫView::CMy420ʵ��Ի���ȷ����ɫView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy420ʵ��Ի���ȷ����ɫView::~CMy420ʵ��Ի���ȷ����ɫView()
{
}

BOOL CMy420ʵ��Ի���ȷ����ɫView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy420ʵ��Ի���ȷ����ɫView ����

void CMy420ʵ��Ի���ȷ����ɫView::OnDraw(CDC* /*pDC*/)
{
	CMy420ʵ��Ի���ȷ����ɫDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy420ʵ��Ի���ȷ����ɫView ��ӡ

BOOL CMy420ʵ��Ի���ȷ����ɫView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy420ʵ��Ի���ȷ����ɫView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy420ʵ��Ի���ȷ����ɫView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy420ʵ��Ի���ȷ����ɫView ���

#ifdef _DEBUG
void CMy420ʵ��Ի���ȷ����ɫView::AssertValid() const
{
	CView::AssertValid();
}

void CMy420ʵ��Ի���ȷ����ɫView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy420ʵ��Ի���ȷ����ɫDoc* CMy420ʵ��Ի���ȷ����ɫView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy420ʵ��Ի���ȷ����ɫDoc)));
	return (CMy420ʵ��Ի���ȷ����ɫDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy420ʵ��Ի���ȷ����ɫView ��Ϣ�������


void CMy420ʵ��Ի���ȷ����ɫView::OnInputrgb()
{
	�����ɫ rgb;
	CClientDC dc(this);
	dc.Ellipse(60, 60, 300, 160);
	int t = rgb.DoModal();
	if (t == IDOK)
	{	
	    CBrush *b = new CBrush(RGB(rgb.x, rgb.y, rgb.z));
	    dc.SelectObject(b);
		dc.Ellipse(60, 60, 300, 160);
	}
	// TODO: �ڴ���������������
}
