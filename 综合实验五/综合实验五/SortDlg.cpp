// SortDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验五.h"
#include "SortDlg.h"
#include "afxdialogex.h"


// SortDlg 对话框

IMPLEMENT_DYNAMIC(SortDlg, CDialogEx)

SortDlg::SortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, sort(_T(""))
{

}

SortDlg::~SortDlg()
{
}

void SortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sort);
}


BEGIN_MESSAGE_MAP(SortDlg, CDialogEx)
END_MESSAGE_MAP()


// SortDlg 消息处理程序
