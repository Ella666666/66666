// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������ʵ���ʵ��4.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

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


// MyDlg ��Ϣ�������





void MyDlg::OnBnClickedButton1()
{
	this->UpdateData(true);
	CClientDC dc(this);
	CString sss;
	sss.Format("%d", x);
	CString s1;
	ss = s + sss + ss;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
