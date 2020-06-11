// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周课堂实验.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
	, b(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnTransaction)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnTransaction()
{
	this->UpdateData(true);
	CString c;
	c = a;
	a = b;
	b = c;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
