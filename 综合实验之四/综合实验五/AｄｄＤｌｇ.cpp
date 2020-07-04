// AｄｄＤｌｇ.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验五.h"
#include "AｄｄＤｌｇ.h"
#include "afxdialogex.h"


// AｄｄＤｌｇ 对话框

IMPLEMENT_DYNAMIC(AｄｄＤｌｇ, CDialogEx)

AｄｄＤｌｇ::AｄｄＤｌｇ(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, l(_T(""))
	, num2(_T(""))
	, name2(_T(""))
	, specia2(_T(""))
	, sex(_T(""))
	, birth2(0)
	, phone2(_T(""))
	, address(_T(""))
	, picpath2(_T(""))
{

}

AｄｄＤｌｇ::~AｄｄＤｌｇ()
{
}

void AｄｄＤｌｇ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, l);
	DDX_Text(pDX, IDC_EDIT3, num2);
	DDX_Text(pDX, IDC_EDIT10, name2);
	DDX_Text(pDX, IDC_EDIT2, specia2);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT7, birth2);
	DDX_Text(pDX, IDC_EDIT6, phone2);
	DDX_Text(pDX, IDC_EDIT8, address);
	DDX_Text(pDX, IDC_EDIT9, picpath2);
}


BEGIN_MESSAGE_MAP(AｄｄＤｌｇ, CDialogEx)
END_MESSAGE_MAP()


// AｄｄＤｌｇ 消息处理程序
