// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ڰ��ܿ���ʵ��1.h"
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
	DDX_LBString(pDX, IDC_LIST1, b);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


void MyDlg::OnBnClickedButton1()
{
	TCHAR szFilter[] = _T("ALL File|*.txt|�����ļ�(*.*)|*.*||");	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath; 	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   		
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, strFilePath);
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strFilePath);
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
