
// ��һ����չʵ��ƴ���ַ���Doc.cpp : C��һ����չʵ��ƴ���ַ���Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ����չʵ��ƴ���ַ���.h"
#endif

#include "��һ����չʵ��ƴ���ַ���Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��һ����չʵ��ƴ���ַ���Doc

IMPLEMENT_DYNCREATE(C��һ����չʵ��ƴ���ַ���Doc, CDocument)

BEGIN_MESSAGE_MAP(C��һ����չʵ��ƴ���ַ���Doc, CDocument)
END_MESSAGE_MAP()


// C��һ����չʵ��ƴ���ַ���Doc ����/����

C��һ����չʵ��ƴ���ַ���Doc::C��һ����չʵ��ƴ���ַ���Doc()
{
	// TODO: �ڴ����һ���Թ������
	a = "aaa";
}

C��һ����չʵ��ƴ���ַ���Doc::~C��һ����չʵ��ƴ���ַ���Doc()
{
}

BOOL C��һ����չʵ��ƴ���ַ���Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��һ����չʵ��ƴ���ַ���Doc ���л�

void C��һ����չʵ��ƴ���ַ���Doc::Serialize(CArchive& ar)
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
void C��һ����չʵ��ƴ���ַ���Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C��һ����չʵ��ƴ���ַ���Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��һ����չʵ��ƴ���ַ���Doc::SetSearchContent(const CString& value)
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

// C��һ����չʵ��ƴ���ַ���Doc ���

#ifdef _DEBUG
void C��һ����չʵ��ƴ���ַ���Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��һ����չʵ��ƴ���ַ���Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��һ����չʵ��ƴ���ַ���Doc ����
