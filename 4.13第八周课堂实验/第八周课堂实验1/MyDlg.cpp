// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第八周课堂实验1.h"
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
	DDX_LBString(pDX, IDC_LIST1, b);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	TCHAR szFilter[] = _T("ALL File|*.txt|所有文件(*.*)|*.*||");	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath; 	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   		
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, strFilePath);
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strFilePath);
	}

	// TODO: 在此添加控件通知处理程序代码
}
