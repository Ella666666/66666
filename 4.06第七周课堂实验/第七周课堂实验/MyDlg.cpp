// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ܿ���ʵ��.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

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


// MyDlg ��Ϣ�������


void MyDlg::OnTransaction()
{
	this->UpdateData(true);
	CString c;
	c = a;
	a = b;
	b = c;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
