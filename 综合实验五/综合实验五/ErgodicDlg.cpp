// ErgodicDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "ErgodicDlg.h"
#include "afxdialogex.h"


// ErgodicDlg �Ի���

IMPLEMENT_DYNAMIC(ErgodicDlg, CDialogEx)

ErgodicDlg::ErgodicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, er(_T(""))
{

}

ErgodicDlg::~ErgodicDlg()
{
}

void ErgodicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, er);
}


BEGIN_MESSAGE_MAP(ErgodicDlg, CDialogEx)
END_MESSAGE_MAP()


// ErgodicDlg ��Ϣ�������
