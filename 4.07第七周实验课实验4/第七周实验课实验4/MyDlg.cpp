// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周实验课实验4.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, ss(_T(""))
	, x(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Text(pDX, IDC_EDIT3, ss);
	DDX_Text(pDX, IDC_EDIT2, x);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序





void MyDlg::OnBnClickedButton1()
{
	this->UpdateData(true);
	CClientDC dc(this);
	CString sss;
	sss.Format("%d", x);
	CString s1;
	ss = s + sss + ss;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
