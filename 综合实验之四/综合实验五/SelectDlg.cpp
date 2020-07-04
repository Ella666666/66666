// SelectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验五.h"
#include "SelectDlg.h"
#include "afxdialogex.h"


// SelectDlg 对话框

IMPLEMENT_DYNAMIC(SelectDlg, CDialogEx)

SelectDlg::SelectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, sele(_T(""))
{

}

SelectDlg::~SelectDlg()
{
}

void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sele);
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialogEx)
END_MESSAGE_MAP()


// SelectDlg 消息处理程序
