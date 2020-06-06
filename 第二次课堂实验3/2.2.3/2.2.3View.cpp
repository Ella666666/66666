
// 2.2.3View.cpp : CMy223View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2.2.3.h"
#endif

#include "2.2.3Doc.h"
#include "2.2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy223View

IMPLEMENT_DYNCREATE(CMy223View, CView)

BEGIN_MESSAGE_MAP(CMy223View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy223View ����/����

CMy223View::CMy223View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy223View::~CMy223View()
{
}

BOOL CMy223View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy223View ����

void CMy223View::OnDraw(CDC* pDC)
{
	CMy223Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPaintDC dc(this);
	CRect cr;//���νṹ
	GetClientRect(&cr);//��ÿͻ�������
	int cx = cr.right;//��
	int cy = cr.bottom;//��
	pDC->SetMapMode(MM_ISOTROPIC);//X=Y
	pDC->SetWindowExt(1000, 1000);//�����߼����ڣ�Ĭ�ϴ���ԭ��Ϊ��0��0��
	pDC->SetViewportExt(cx, -cy);//��������ӿ�,X��Y��Ϊ��
	pDC->SetViewportOrg(cx / 2, cy / 2);//�����ӿ�ԭ��Ϊ�ͻ�������
	pDC->Ellipse(-500, 500, 500, -500);//������Բ��ͻ������е���Բ
}


// CMy223View ��ӡ

BOOL CMy223View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy223View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy223View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy223View ���

#ifdef _DEBUG
void CMy223View::AssertValid() const
{
	CView::AssertValid();
}

void CMy223View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy223Doc* CMy223View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy223Doc)));
	return (CMy223Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy223View ��Ϣ�������
