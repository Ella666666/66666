// ErgodicDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验五.h"
#include "ErgodicDlg.h"
#include "afxdialogex.h"


// ErgodicDlg 对话框

IMPLEMENT_DYNAMIC(ErgodicDlg, CDialogEx)

ErgodicDlg::ErgodicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, er(_T(""))
{

}

ErgodicDlg::~ErgodicDlg()
{
}

void ErgodicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, er);
}


BEGIN_MESSAGE_MAP(ErgodicDlg, CDialogEx)
END_MESSAGE_MAP()


// ErgodicDlg 消息处理程序
