
// 420ʵ��Ի�����ԲDoc.cpp : CMy420ʵ��Ի�����ԲDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "420ʵ��Ի�����Բ.h"
#endif

#include "420ʵ��Ի�����ԲDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy420ʵ��Ի�����ԲDoc

IMPLEMENT_DYNCREATE(CMy420ʵ��Ի�����ԲDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy420ʵ��Ի�����ԲDoc, CDocument)
END_MESSAGE_MAP()


// CMy420ʵ��Ի�����ԲDoc ����/����

CMy420ʵ��Ի�����ԲDoc::CMy420ʵ��Ի�����ԲDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy420ʵ��Ի�����ԲDoc::~CMy420ʵ��Ի�����ԲDoc()
{
}

BOOL CMy420ʵ��Ի�����ԲDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy420ʵ��Ի�����ԲDoc ���л�

void CMy420ʵ��Ի�����ԲDoc::Serialize(CArchive& ar)
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
void CMy420ʵ��Ի�����ԲDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy420ʵ��Ի�����ԲDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy420ʵ��Ի�����ԲDoc::SetSearchContent(const CString& value)
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

// CMy420ʵ��Ի�����ԲDoc ���

#ifdef _DEBUG
void CMy420ʵ��Ի�����ԲDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy420ʵ��Ի�����ԲDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy420ʵ��Ի�����ԲDoc ����
