
// 414ʵ��1View.cpp : CMy414ʵ��1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "414ʵ��1.h"
#endif

#include "414ʵ��1Doc.h"
#include "414ʵ��1View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy414ʵ��1View

IMPLEMENT_DYNCREATE(CMy414ʵ��1View, CView)

BEGIN_MESSAGE_MAP(CMy414ʵ��1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy414ʵ��1View ����/����

CMy414ʵ��1View::CMy414ʵ��1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy414ʵ��1View::~CMy414ʵ��1View()
{
}

BOOL CMy414ʵ��1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}



// CMy414ʵ��1View ����

void CMy414ʵ��1View::OnDraw(CDC* /*pDC*/)
{
	CMy414ʵ��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy414ʵ��1View ��ӡ

BOOL CMy414ʵ��1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy414ʵ��1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy414ʵ��1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy414ʵ��1View ���

#ifdef _DEBUG
void CMy414ʵ��1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy414ʵ��1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy414ʵ��1Doc* CMy414ʵ��1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy414ʵ��1Doc)));
	return (CMy414ʵ��1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy414ʵ��1View ��Ϣ�������


void CMy414ʵ��1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MyDlg md2;
	int r = md2.DoModal();
	if (r == IDOK)
	{
	
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CMy414ʵ��1View::OnBnClickedOpenButton()
{
	TCHAR szFilter[] = _T("ALL File(*.*)|*.*||");	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath; 	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   		
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
		CString s1 = strFilePath;
		GetDC()->TextOutW(200, 100, s1);
	}
}
