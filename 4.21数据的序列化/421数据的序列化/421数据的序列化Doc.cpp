
// 421���ݵ����л�Doc.cpp : CMy421���ݵ����л�Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "421���ݵ����л�.h"
#endif

#include "421���ݵ����л�Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy421���ݵ����л�Doc

IMPLEMENT_DYNCREATE(CMy421���ݵ����л�Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy421���ݵ����л�Doc, CDocument)
END_MESSAGE_MAP()


// CMy421���ݵ����л�Doc ����/����

CMy421���ݵ����л�Doc::CMy421���ݵ����л�Doc()
{
	// TODO: �ڴ����һ���Թ������
	s = _T("�ð���abc");
	a = 123;
	int i = 224, j = -330;
	ca.Add(i);
	ca.Add(j);
	st.name = _T("����");
	st.age = 21;
}

CMy421���ݵ����л�Doc::~CMy421���ݵ����л�Doc()
{
}

BOOL CMy421���ݵ����л�Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy421���ݵ����л�Doc ���л�

void CMy421���ݵ����л�Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << a << s;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar >> a >> s;
	}
	ca.Serialize(ar);
	st.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy421���ݵ����л�Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy421���ݵ����л�Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy421���ݵ����л�Doc::SetSearchContent(const CString& value)
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

// CMy421���ݵ����л�Doc ���

#ifdef _DEBUG
void CMy421���ݵ����л�Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy421���ݵ����л�Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy421���ݵ����л�Doc ����
