
// 第十一周课堂实验2Doc.cpp : C第十一周课堂实验2Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十一周课堂实验2.h"
#endif

#include "第十一周课堂实验2Set.h"
#include "第十一周课堂实验2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C第十一周课堂实验2Doc

IMPLEMENT_DYNCREATE(C第十一周课堂实验2Doc, CDocument)

BEGIN_MESSAGE_MAP(C第十一周课堂实验2Doc, CDocument)
END_MESSAGE_MAP()


// C第十一周课堂实验2Doc 构造/析构

C第十一周课堂实验2Doc::C第十一周课堂实验2Doc()
{
	// TODO: 在此添加一次性构造代码

}

C第十一周课堂实验2Doc::~C第十一周课堂实验2Doc()
{
}

BOOL C第十一周课堂实验2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}



#ifdef SHARED_HANDLERS

// 缩略图的支持
void C第十一周课堂实验2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void C第十一周课堂实验2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void C第十一周课堂实验2Doc::SetSearchContent(const CString& value)
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

// C第十一周课堂实验2Doc 诊断

#ifdef _DEBUG
void C第十一周课堂实验2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C第十一周课堂实验2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C第十一周课堂实验2Doc 命令
