
// ��һ��ʵ��2������ͳ���Ҽ������ʾView.cpp : C��һ��ʵ��2������ͳ���Ҽ������ʾView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ��ʵ��2������ͳ���Ҽ������ʾ.h"
#endif

#include "��һ��ʵ��2������ͳ���Ҽ������ʾDoc.h"
#include "��һ��ʵ��2������ͳ���Ҽ������ʾView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��һ��ʵ��2������ͳ���Ҽ������ʾView

IMPLEMENT_DYNCREATE(C��һ��ʵ��2������ͳ���Ҽ������ʾView, CView)

BEGIN_MESSAGE_MAP(C��һ��ʵ��2������ͳ���Ҽ������ʾView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C��һ��ʵ��2������ͳ���Ҽ������ʾView ����/����

C��һ��ʵ��2������ͳ���Ҽ������ʾView::C��һ��ʵ��2������ͳ���Ҽ������ʾView()
{
	// TODO: �ڴ˴���ӹ������

}

C��һ��ʵ��2������ͳ���Ҽ������ʾView::~C��һ��ʵ��2������ͳ���Ҽ������ʾView()
{
}

BOOL C��һ��ʵ��2������ͳ���Ҽ������ʾView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��һ��ʵ��2������ͳ���Ҽ������ʾView ����

void C��һ��ʵ��2������ͳ���Ҽ������ʾView::OnDraw(CDC* pDC)
{
	C��һ��ʵ��2������ͳ���Ҽ������ʾDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��һ��ʵ��2������ͳ���Ҽ������ʾView ��ӡ

BOOL C��һ��ʵ��2������ͳ���Ҽ������ʾView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��һ��ʵ��2������ͳ���Ҽ������ʾView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��һ��ʵ��2������ͳ���Ҽ������ʾView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��һ��ʵ��2������ͳ���Ҽ������ʾView ���

#ifdef _DEBUG
void C��һ��ʵ��2������ͳ���Ҽ������ʾView::AssertValid() const
{
	CView::AssertValid();
}

void C��һ��ʵ��2������ͳ���Ҽ������ʾView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��һ��ʵ��2������ͳ���Ҽ������ʾDoc* C��һ��ʵ��2������ͳ���Ҽ������ʾView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��һ��ʵ��2������ͳ���Ҽ������ʾDoc)));
	return (C��һ��ʵ��2������ͳ���Ҽ������ʾDoc*)m_pDocument;
}
#endif //_DEBUG


// C��һ��ʵ��2������ͳ���Ҽ������ʾView ��Ϣ�������


void C��һ��ʵ��2������ͳ���Ҽ������ʾView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��һ��ʵ��2������ͳ���Ҽ������ʾDoc* pDoc = GetDocument();
	pDoc->count += 1;


	CView::OnLButtonDown(nFlags, point);
}


void C��һ��ʵ��2������ͳ���Ҽ������ʾView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��һ��ʵ��2������ͳ���Ҽ������ʾDoc* pDoc = GetDocument();
	CClientDC dc(this);	
	CString s;
	s.Format("%d", pDoc->count);
	dc.TextOut(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
