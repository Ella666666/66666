// SortDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "SortDlg.h"
#include "afxdialogex.h"


// SortDlg �Ի���

IMPLEMENT_DYNAMIC(SortDlg, CDialogEx)

SortDlg::SortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, sort(_T(""))
{

}

SortDlg::~SortDlg()
{
}

void SortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sort);
}


BEGIN_MESSAGE_MAP(SortDlg, CDialogEx)
END_MESSAGE_MAP()


// SortDlg ��Ϣ�������
