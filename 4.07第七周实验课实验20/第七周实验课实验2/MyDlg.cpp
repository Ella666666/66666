// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周实验课实验2.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, z);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyDlg::OnOk)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlg::OnEqual)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MyDlg::OnEqual()
{
	this->UpdateData(true);
	z = x + y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
