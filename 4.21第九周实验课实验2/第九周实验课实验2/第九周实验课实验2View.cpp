
// �ھ���ʵ���ʵ��2View.cpp : C�ھ���ʵ���ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ���ʵ���ʵ��2.h"
#endif

#include "�ھ���ʵ���ʵ��2Doc.h"
#include "�ھ���ʵ���ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"string"
#include"iostream"
#include"fstream"
using namespace std;

// C�ھ���ʵ���ʵ��2View

IMPLEMENT_DYNCREATE(C�ھ���ʵ���ʵ��2View, CView)

BEGIN_MESSAGE_MAP(C�ھ���ʵ���ʵ��2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_SAVE_AS, &C�ھ���ʵ���ʵ��2View::OnFileSaveAs)
	ON_COMMAND(ID_FILE_OPEN, &C�ھ���ʵ���ʵ��2View::OnFileOpen)
END_MESSAGE_MAP()

// C�ھ���ʵ���ʵ��2View ����/����

C�ھ���ʵ���ʵ��2View::C�ھ���ʵ���ʵ��2View()
{
	// TODO: �ڴ˴���ӹ������
	i = 0;

}

C�ھ���ʵ���ʵ��2View::~C�ھ���ʵ���ʵ��2View()
{
}

BOOL C�ھ���ʵ���ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ���ʵ���ʵ��2View ����

void C�ھ���ʵ���ʵ��2View::OnDraw(CDC* pDC)
{
	C�ھ���ʵ���ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ���ʵ���ʵ��2View ��ӡ

BOOL C�ھ���ʵ���ʵ��2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ھ���ʵ���ʵ��2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ھ���ʵ���ʵ��2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ھ���ʵ���ʵ��2View ���

#ifdef _DEBUG
void C�ھ���ʵ���ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ���ʵ���ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ���ʵ���ʵ��2Doc* C�ھ���ʵ���ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ���ʵ���ʵ��2Doc)));
	return (C�ھ���ʵ���ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ���ʵ���ʵ��2View ��Ϣ�������


void C�ھ���ʵ���ʵ��2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDC*pDC = GetDC();
	C�ھ���ʵ���ʵ��2Doc* pDoc = GetDocument();
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen *oldpen = (CPen*)pDC->SelectObject(&pen);
	    i += 1;
		pDC->Ellipse(pDoc->c[i]);
	CView::OnLButtonDown(nFlags, point);
}


void C�ھ���ʵ���ʵ��2View::OnFileSaveAs()
{
	Invalidate();
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());
		C�ھ���ʵ���ʵ��2Doc* pDoc = GetDocument();
		for (int i = 0; i < pDoc->c.GetSize(); i++)
		{
			CString s0, s1, s2, s3;
			s0.Format(_T("%d"), pDoc->c[i].top);
			s1.Format(_T("%d"), pDoc->c[i].left);
			s2.Format(_T("%d"), pDoc->c[i].right);
			s3.Format(_T("%d"), pDoc->c[i].bottom);
			ofs << CT2A(s0.GetString()) << " ";
			ofs << CT2A(s1.GetString()) << " ";
			ofs << CT2A(s2.GetString()) << " ";
			ofs << CT2A(s3.GetString()) << " ";
			ofs << endl;
		}


	}
	// TODO: �ڴ���������������
}


void C�ھ���ʵ���ʵ��2View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CDC* pDC = GetDC();
		C�ھ���ʵ���ʵ��2Doc* pDoc = GetDocument();
		for (int i = 0; i < pDoc->c.GetSize(); i++)
		{
			pDC->Ellipse(pDoc->c[i]);

		}
	}
	// TODO: �ڴ���������������
}
