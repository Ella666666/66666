// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "413ʵ��.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, r(0)
	, a(_T(""))
	, b(0)
	, c(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDX_Text(pDX, IDC_EDIT3, y);
	DDX_Text(pDX, IDC_EDIT1, r);
	DDX_Text(pDX, IDC_EDIT6, a);
	DDX_Text(pDX, IDC_EDIT4, b);
	DDX_Text(pDX, IDC_EDIT5, c);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


void MyDlg::OnBnClickedButton1()
{
	this->UpdateData(true);
	r = x + y;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
