
// �ڶ���ʵ���ʵ��3Doc.cpp : C�ڶ���ʵ���ʵ��3Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ���ʵ��3.h"
#endif

#include "�ڶ���ʵ���ʵ��3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ڶ���ʵ���ʵ��3Doc

IMPLEMENT_DYNCREATE(C�ڶ���ʵ���ʵ��3Doc, CDocument)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ���ʵ��3Doc, CDocument)
END_MESSAGE_MAP()


// C�ڶ���ʵ���ʵ��3Doc ����/����

C�ڶ���ʵ���ʵ��3Doc::C�ڶ���ʵ���ʵ��3Doc()
{
	// TODO: �ڴ����һ���Թ������
	count = 0;
}

C�ڶ���ʵ���ʵ��3Doc::~C�ڶ���ʵ���ʵ��3Doc()
{
}

BOOL C�ڶ���ʵ���ʵ��3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ڶ���ʵ���ʵ��3Doc ���л�

void C�ڶ���ʵ���ʵ��3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C�ڶ���ʵ���ʵ��3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C�ڶ���ʵ���ʵ��3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ڶ���ʵ���ʵ��3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C�ڶ���ʵ���ʵ��3Doc ���

#ifdef _DEBUG
void C�ڶ���ʵ���ʵ��3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ڶ���ʵ���ʵ��3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ڶ���ʵ���ʵ��3Doc ����
