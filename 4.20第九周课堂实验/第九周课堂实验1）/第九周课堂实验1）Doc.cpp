
// �ھ��ܿ���ʵ��1��Doc.cpp : C�ھ��ܿ���ʵ��1��Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ��ܿ���ʵ��1��.h"
#endif

#include "�ھ��ܿ���ʵ��1��Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ھ��ܿ���ʵ��1��Doc

IMPLEMENT_DYNCREATE(C�ھ��ܿ���ʵ��1��Doc, CDocument)

BEGIN_MESSAGE_MAP(C�ھ��ܿ���ʵ��1��Doc, CDocument)
END_MESSAGE_MAP()


// C�ھ��ܿ���ʵ��1��Doc ����/����

C�ھ��ܿ���ʵ��1��Doc::C�ھ��ܿ���ʵ��1��Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C�ھ��ܿ���ʵ��1��Doc::~C�ھ��ܿ���ʵ��1��Doc()
{
}

BOOL C�ھ��ܿ���ʵ��1��Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ھ��ܿ���ʵ��1��Doc ���л�

void C�ھ��ܿ���ʵ��1��Doc::Serialize(CArchive& ar)
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
void C�ھ��ܿ���ʵ��1��Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C�ھ��ܿ���ʵ��1��Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ھ��ܿ���ʵ��1��Doc::SetSearchContent(const CString& value)
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

// C�ھ��ܿ���ʵ��1��Doc ���

#ifdef _DEBUG
void C�ھ��ܿ���ʵ��1��Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ھ��ܿ���ʵ��1��Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ھ��ܿ���ʵ��1��Doc ����
