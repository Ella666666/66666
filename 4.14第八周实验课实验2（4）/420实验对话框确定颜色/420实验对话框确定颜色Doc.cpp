
// 420ʵ��Ի���ȷ����ɫDoc.cpp : CMy420ʵ��Ի���ȷ����ɫDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "420ʵ��Ի���ȷ����ɫ.h"
#endif

#include "420ʵ��Ի���ȷ����ɫDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy420ʵ��Ի���ȷ����ɫDoc

IMPLEMENT_DYNCREATE(CMy420ʵ��Ի���ȷ����ɫDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy420ʵ��Ի���ȷ����ɫDoc, CDocument)
END_MESSAGE_MAP()


// CMy420ʵ��Ի���ȷ����ɫDoc ����/����

CMy420ʵ��Ի���ȷ����ɫDoc::CMy420ʵ��Ի���ȷ����ɫDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy420ʵ��Ի���ȷ����ɫDoc::~CMy420ʵ��Ի���ȷ����ɫDoc()
{
}

BOOL CMy420ʵ��Ի���ȷ����ɫDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy420ʵ��Ի���ȷ����ɫDoc ���л�

void CMy420ʵ��Ի���ȷ����ɫDoc::Serialize(CArchive& ar)
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
void CMy420ʵ��Ի���ȷ����ɫDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy420ʵ��Ի���ȷ����ɫDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy420ʵ��Ի���ȷ����ɫDoc::SetSearchContent(const CString& value)
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

// CMy420ʵ��Ի���ȷ����ɫDoc ���

#ifdef _DEBUG
void CMy420ʵ��Ի���ȷ����ɫDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy420ʵ��Ի���ȷ����ɫDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy420ʵ��Ի���ȷ����ɫDoc ����
