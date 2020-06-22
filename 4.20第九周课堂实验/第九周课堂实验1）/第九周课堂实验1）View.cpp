
// �ھ��ܿ���ʵ��1��View.cpp : C�ھ��ܿ���ʵ��1��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ��ܿ���ʵ��1��.h"
#endif

#include "�ھ��ܿ���ʵ��1��Doc.h"
#include "�ھ��ܿ���ʵ��1��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <fstream>
#include <string>
#include <iostream>
#include "MyDlg.h"
using namespace std;

// C�ھ��ܿ���ʵ��1��View

IMPLEMENT_DYNCREATE(C�ھ��ܿ���ʵ��1��View, CView)

BEGIN_MESSAGE_MAP(C�ھ��ܿ���ʵ��1��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWDIALOG, &C�ھ��ܿ���ʵ��1��View::OnShowdialog)
	ON_COMMAND(ID_FILE_OPEN, &C�ھ��ܿ���ʵ��1��View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &C�ھ��ܿ���ʵ��1��View::OnFileSave)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ھ��ܿ���ʵ��1��View::OnShowPicture)
END_MESSAGE_MAP()

// C�ھ��ܿ���ʵ��1��View ����/����

C�ھ��ܿ���ʵ��1��View::C�ھ��ܿ���ʵ��1��View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ھ��ܿ���ʵ��1��View::~C�ھ��ܿ���ʵ��1��View()
{
}

BOOL C�ھ��ܿ���ʵ��1��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ��ܿ���ʵ��1��View ����

void C�ھ��ܿ���ʵ��1��View::OnDraw(CDC* /*pDC*/)
{
	C�ھ��ܿ���ʵ��1��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ��ܿ���ʵ��1��View ��ӡ

BOOL C�ھ��ܿ���ʵ��1��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ھ��ܿ���ʵ��1��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ھ��ܿ���ʵ��1��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ھ��ܿ���ʵ��1��View ���

#ifdef _DEBUG
void C�ھ��ܿ���ʵ��1��View::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ��ܿ���ʵ��1��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ��ܿ���ʵ��1��Doc* C�ھ��ܿ���ʵ��1��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ��ܿ���ʵ��1��Doc)));
	return (C�ھ��ܿ���ʵ��1��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ��ܿ���ʵ��1��View ��Ϣ�������


void C�ھ��ܿ���ʵ��1��View::OnShowdialog()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	filename = cfd.GetPathName();
	dc.TextOutW(0, 0, filename);
	if (r == IDOK)
	{
		ifstream ifs(filename);
		string s;
		ifs >> s;
		ofstream ofs(cfd.GetPathName());
		CString ss = cfd.GetPathName();
		ofs << CT2A(ss.GetString()) << endl;

	}
	
}


void C�ھ��ܿ���ʵ��1��View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		while (ifs >> s)
		{
			CString str;
			str = CString(s.c_str());
			CClientDC dc(this);
			dc.TextOutW(200, 200, CString(s.c_str()));

		}

	}
	// TODO: �ڴ���������������
}


void C�ھ��ܿ���ʵ��1��View::OnFileSave()
{
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(filename);
		CString s = filename;
		ofs << filename << endl;
		ofs << CT2A(s.GetString()) << endl;


	}
	// TODO: �ڴ���������������
}


void C�ھ��ܿ���ʵ��1��View::OnShowPicture()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		CString s;
		s.Format(_T("C:\\Users\\86187\\Desktop\\abc.txt"));
		ofstream ofs(s);
		ofs << CT2A(filename.GetString()) << endl;
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
