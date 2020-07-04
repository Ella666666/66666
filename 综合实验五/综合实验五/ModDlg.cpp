// ModDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验五.h"
#include "ModDlg.h"
#include "afxdialogex.h"


// ModDlg 对话框

IMPLEMENT_DYNAMIC(ModDlg, CDialogEx)

ModDlg::ModDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, name1(_T(""))
	, num1(_T(""))
	, specia1(_T(""))
	, sex1(_T(""))
	, birth1(0)
	, phone(_T(""))
	, address1(_T(""))
	, picpath1(_T(""))
{

}

ModDlg::~ModDlg()
{
}

void ModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, name1);
	DDX_Text(pDX, IDC_EDIT9, num1);
	DDX_Text(pDX, IDC_EDIT10, specia1);
	DDX_Text(pDX, IDC_EDIT11, sex1);
	DDX_Text(pDX, IDC_EDIT12, birth1);
	DDX_Text(pDX, IDC_EDIT13, phone);
	DDX_Text(pDX, IDC_EDIT14, address1);
	DDX_Text(pDX, IDC_EDIT15, picpath1);
}


BEGIN_MESSAGE_MAP(ModDlg, CDialogEx)
END_MESSAGE_MAP()


// ModDlg 消息处理程序
