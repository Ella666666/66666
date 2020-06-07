// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "414ʵ��1.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_szPath(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &MyDlg::OnBnClickedOpenButton)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void MyDlg::OnBnClickedOpenButton()
{
	TCHAR szFilter[] = _T("ALL File|*.txt|�����ļ�(*.*)|*.*||");	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);	
	CString strFilePath; 	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   		
		strFilePath = fileDlg.GetPathName();		
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);	
	}
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
