
// 综合实验五View.cpp : C综合实验五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验五.h"
#endif

#include "综合实验五Set.h"
#include "综合实验五Doc.h"
#include "综合实验五View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验五View

IMPLEMENT_DYNCREATE(C综合实验五View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验五View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C综合实验五View 构造/析构

C综合实验五View::C综合实验五View()
	: CRecordView(IDD_MY_FORM)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验五View::~C综合实验五View()
{
}

void C综合实验五View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
}

BOOL C综合实验五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验五View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验五Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验五View 打印

BOOL C综合实验五View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C综合实验五View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C综合实验五View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C综合实验五View 诊断

#ifdef _DEBUG
void C综合实验五View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验五View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验五Doc* C综合实验五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验五Doc)));
	return (C综合实验五Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验五View 数据库支持
CRecordset* C综合实验五View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验五View 消息处理程序
