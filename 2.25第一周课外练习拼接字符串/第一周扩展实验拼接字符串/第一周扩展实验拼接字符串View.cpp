
// ��һ����չʵ��ƴ���ַ���View.cpp : C��һ����չʵ��ƴ���ַ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ����չʵ��ƴ���ַ���.h"
#endif

#include "��һ����չʵ��ƴ���ַ���Doc.h"
#include "��һ����չʵ��ƴ���ַ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��һ����չʵ��ƴ���ַ���View

IMPLEMENT_DYNCREATE(C��һ����չʵ��ƴ���ַ���View, CView)

BEGIN_MESSAGE_MAP(C��һ����չʵ��ƴ���ַ���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C��һ����չʵ��ƴ���ַ���View ����/����

C��һ����չʵ��ƴ���ַ���View::C��һ����չʵ��ƴ���ַ���View()
{
	// TODO: �ڴ˴���ӹ������
	b = "bbb";
}

C��һ����չʵ��ƴ���ַ���View::~C��һ����չʵ��ƴ���ַ���View()
{
}

BOOL C��һ����չʵ��ƴ���ַ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��һ����չʵ��ƴ���ַ���View ����

void C��һ����չʵ��ƴ���ַ���View::OnDraw(CDC* pDC)
{
	C��һ����չʵ��ƴ���ַ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��һ����չʵ��ƴ���ַ���View ��ӡ

BOOL C��һ����չʵ��ƴ���ַ���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��һ����չʵ��ƴ���ַ���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��һ����չʵ��ƴ���ַ���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��һ����չʵ��ƴ���ַ���View ���

#ifdef _DEBUG
void C��һ����չʵ��ƴ���ַ���View::AssertValid() const
{
	CView::AssertValid();
}

void C��һ����չʵ��ƴ���ַ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��һ����չʵ��ƴ���ַ���Doc* C��һ����չʵ��ƴ���ַ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��һ����չʵ��ƴ���ַ���Doc)));
	return (C��һ����չʵ��ƴ���ַ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C��һ����չʵ��ƴ���ַ���View ��Ϣ�������


void C��һ����չʵ��ƴ���ַ���View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��һ����չʵ��ƴ���ַ���Doc* pDoc = GetDocument();
	CString s = pDoc->a+b;
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
